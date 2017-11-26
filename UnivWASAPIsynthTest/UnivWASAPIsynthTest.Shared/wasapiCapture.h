#pragma once
//
#include <Audioclient.h>
#include <mmdeviceapi.h>
#include <phoneaudioclient.h>
#include <Windows.h>
//
class wasapiCapture
{
public:
	wasapiCapture();
	wasapiCapture(Windows::UI::Xaml::Controls::TextBox^ txtBox);
	~wasapiCapture();
	void start();
	void stop();
	//
private:
	void phoneInitialize();
	//
	HRESULT hr1, hr2, hr3, hr4, hr5, hr6, hr7, hr8, hr9;
	//
	IAudioClient2 *iAC2;
	IAudioCaptureClient *iACCP;
	//
	const IID IID_IAudioClient = __uuidof(IAudioClient2);
	const IID IID_IAudioCaptureClient = __uuidof(IAudioCaptureClient);
	//
	LPCWSTR aCIDP;
	Platform::String^ aCID;
	//REFIID riid = IID_IAudioRenderClient;
	//void **ppv;
	//
	WAVEFORMATEX* waveFormat;
	//
	UINT32 bufferFrameCount;
	UINT32 packetLength;
	UINT32 numFramesAvailable;
	BYTE *pData;
	DWORD flags;
	//
	Windows::UI::Xaml::Controls::TextBox^ t;
};

