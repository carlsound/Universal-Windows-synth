#pragma once
//
#include <Audioclient.h>
#include <mmdeviceapi.h>
#include <phoneaudioclient.h>
#include <Windows.h>
//
class wasapiRender
{
	public:
		wasapiRender();
		~wasapiRender();
	//
	private:
		HRESULT hr1, hr2, hr3, hr4, hr5, hr6;
		//
		IAudioClient2 *iAC2;
		IAudioRenderClient *iARCP;
		//
		const IID IID_IAudioClient = __uuidof(IAudioClient2);
		const IID IID_IAudioRenderClient = __uuidof(IAudioRenderClient);
		//
		LPCWSTR aCIDP;
		Platform::String^ aCID;
		//REFIID riid = IID_IAudioRenderClient;
		//void **ppv;
		//
		WAVEFORMATEX* waveFormat;
};

