//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
//
#include "wasapiCapture.h"
#include "wasapiRender.h"

namespace UnivWASAPIsynthTest
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		void tglBtnChecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void tglBtnUnchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		//
		std::shared_ptr<wasapiCapture> wc;
		std::shared_ptr<wasapiRender> wr;
	};
}
