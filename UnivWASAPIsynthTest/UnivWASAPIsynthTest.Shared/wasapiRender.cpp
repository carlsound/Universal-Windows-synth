#include "pch.h"
#include "wasapiRender.h"


wasapiRender::wasapiRender()
{
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
			aCIDP = GetDefaultAudioRenderId(AudioDeviceRole::Default);
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
			hr4 = iAC2->Initialize(AUDCLNT_SHAREMODE_SHARED, (DWORD) 0,  (REFERENCE_TIME) 10000000, (REFERENCE_TIME) 0, waveFormat, NULL);
			//
			hr5 = iAC2->GetService(IID_IAudioRenderClient, (void**)&iARCP);
			//
			hr6 = iAC2->Start();
			//
			int i = 0;
#endif
		//aCID = Windows::Media::Devices::MediaDevice::GetDefaultAudioRenderId(Windows::Media::Devices::AudioDeviceRole::Default);
		//
		//hr1 = iAC->Initialize(AUDCLNT_SHAREMODE_SHARED, );
		//
		//hr2 = iAC->GetService(riid, ppv);
		//
}


wasapiRender::~wasapiRender()
{
}