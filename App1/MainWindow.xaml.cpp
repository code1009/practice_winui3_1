#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App1::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
		myListBox().Items().Append(box_value(L"Clicked"));

        myButton().Content(box_value(L"Clicked"));
    }
}

/*

.vcxprj file:

  <PropertyGroup Label="Globals">

	<WindowsPackageType>None</WindowsPackageType>
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	<CppWinRTOptimized>true</CppWinRTOptimized>
	<CppWinRTRootNamespaceAutoMerge>true</CppWinRTRootNamespaceAutoMerge>
	<MinimalCoreWin>true</MinimalCoreWin>
	<ProjectGuid>{109b62cf-24c6-4d22-be3f-925617ff8924}</ProjectGuid>
	<ProjectName>App1</ProjectName>
	<RootNamespace>App1</RootNamespace>
	<!--
	  $(TargetName) should be same as $(RootNamespace) so that the produced binaries (.exe/.pri/etc.)
	  have a name that matches the .winmd
	-->
	<TargetName>$(RootNamespace)</TargetName>
	<DefaultLanguage>ko-KR</DefaultLanguage>
	<MinimumVisualStudioVersion>16.0</MinimumVisualStudioVersion>
	<AppContainerApplication>false</AppContainerApplication>

	<AppxPackage>false</AppxPackage>
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	<ApplicationType>Windows Store</ApplicationType>
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	<ApplicationTypeRevision>10.0</ApplicationTypeRevision>
	<WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>
	<WindowsTargetPlatformMinVersion>10.0.17763.0</WindowsTargetPlatformMinVersion>
	<UseWinUI>true</UseWinUI>
	<EnableMsixTooling>true</EnableMsixTooling>
  </PropertyGroup>

https://github.com/microsoft/WindowsAppSDK/issues/2212
https://learn.microsoft.com/en-us/windows/apps/winui/winui3/create-your-first-winui3-app

*/