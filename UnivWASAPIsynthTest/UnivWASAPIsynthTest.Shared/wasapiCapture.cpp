#include "pch.h"
#include "wasapiCapture.h"

wasapiCapture::wasapiCapture(Windows::UI::Xaml::Controls::TextBox ^txtBox)
{
	t = txtBox;
	//
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
	phoneInitialize();
#endif
}

wasapiCapture::wasapiCapture()
{
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
	phoneInitialize();
#endif
}


wasapiCapture::~wasapiCapture()
{
}

void wasapiCapture::phoneInitialize()
{
	aCIDP = GetDefaultAudioCaptureId(AudioDeviceRole::Default);
	hr1 = ActivateAudioInterface(aCIDP, IID_IAudioClient, (void**)&iAC2);
	//
	hr2 = iAC2->GetMixFormat(&waveFormat);
	//
	AudioClientProperties properties = {};
	properties.cbSize = sizeof AudioClientProperties;
	properties.eCategory = AudioCategory_Other;
	//
	hr3 = iAC2->SetClientProperties(&properties);
	//
	hr4 = iAC2->Initialize(AUDCLNT_SHAREMODE_SHARED, 0x88000000, (REFERENCE_TIME)10000000, (REFERENCE_TIME)0, waveFormat, NULL);
	//
	hr5 = iAC2->GetBufferSize(&bufferFrameCount);
	//
	hr6 = iAC2->GetService(__uuidof(IAudioCaptureClient), (void**)&iACCP);
	//
	//hr7 = iAC2->Start();
	//
	packetLength = 0;
	pData = nullptr;
}

void wasapiCapture::start()
{
	hr7 = iAC2->Start();
	//
	while (packetLength <= 0) // wait until some data has been captured
	{
		hr8 = iACCP->GetNextPacketSize(&packetLength);
	}
	//
	hr9 = iACCP->GetBuffer(&pData, &numFramesAvailable, &flags, NULL, NULL);
	//
	//printf((char*)pData);
	//
	int i = 0;
	//
	/*if (t != nullptr)
	{
		t->Text = (Platform::String^)&pData;
	}*/
	//
	//
	//
	//
	//
	//
	//
	//
	// Each loop fills about half of the shared buffer.
	while (bDone == FALSE)
	{
		// Sleep for half the buffer duration.
		Sleep(hnsActualDuration / REFTIMES_PER_MILLISEC / 2);

		hr = pCaptureClient->GetNextPacketSize(&packetLength);
		EXIT_ON_ERROR(hr)

			while (packetLength != 0)
			{
				// Get the available data in the shared buffer.
				hr = pCaptureClient->GetBuffer(
					&pData,
					&numFramesAvailable,
					&flags, NULL, NULL);
				EXIT_ON_ERROR(hr)

					if (flags & AUDCLNT_BUFFERFLAGS_SILENT)
					{
						pData = NULL;  // Tell CopyData to write silence.
					}

				// Copy the available capture data to the audio sink.
				hr = pMySink->CopyData(
					pData, numFramesAvailable, &bDone);
				EXIT_ON_ERROR(hr)

					hr = pCaptureClient->ReleaseBuffer(numFramesAvailable);
				EXIT_ON_ERROR(hr)

					hr = pCaptureClient->GetNextPacketSize(&packetLength);
				EXIT_ON_ERROR(hr)
			}
		}
}

void wasapiCapture::stop()
{
	hr7 = iAC2->Stop();
}