/*! @file CSpeedTest.cpp
 */
#include "StdAfx.h"
#include "CSpeedTest.h"

#include <OleCtl.h>
#include <wincodec.h>
#pragma comment(lib, "windowscodecs.lib")
#include <wrl.h>

#pragma comment(lib, "msimg32.lib")

#include <exception>
#include <fstream>

//! コンストラクタ
CSpeedTest::CSpeedTest( HINSTANCE hInstance, LPCTSTR lpCmdLine ) noexcept
	: m_hInstance( hInstance )
	, m_lpCmdLine( lpCmdLine )
	, m_hrOleInit( E_FAIL )
{
}

//! デストラクタ
CSpeedTest::~CSpeedTest( void ) noexcept
{
	// OLE初期化が成功していたらシャットダウンする
	if ( SUCCEEDED( m_hrOleInit ) ) {
		::OleUninitialize();
	}
}

//! アプリインスタンスを初期化する
bool CSpeedTest::InitInstance( void ) noexcept
{
	// OLE(というかCOM)を初期化する
	m_hrOleInit = ::OleInitialize( NULL );
	if ( FAILED( m_hrOleInit ) ) {
		return false;
	}

	return true;
}

struct CStopWatch
{
	std::string title;
	LARGE_INTEGER frequency;
	LARGE_INTEGER startTime;

	CStopWatch( const std::string &szTitle )
		: title( szTitle )
		, frequency( qpc::queryPerformanceFrequency() )
		, startTime( qpc::queryPerformanceCounter() )
	{
	}
	virtual ~CStopWatch( void )
	{
		LARGE_INTEGER endTime;
		endTime = qpc::queryPerformanceCounter();

		LARGE_INTEGER elapsedTime;
		elapsedTime.QuadPart = endTime.QuadPart - startTime.QuadPart;
		//elapsedTime.QuadPart /= frequency.QuadPart;

		WCHAR buf[MAX_PATH];
		::swprintf_s( buf, L"%hs elapsed=%lld\n", title.c_str(), elapsedTime.QuadPart );
		::OutputDebugStringW( buf );
	}
};

static size_t MAX_COUNT = 5000;

void case1()
{
	HWND hWnd = ::GetDesktopWindow();
	HDC hDC = ::GetDC( hWnd );

	RECT rc;
	::GetWindowRect( hWnd, &rc );

	if ( true )
	{
		CStopWatch sw( __FUNCTION__ );
		for ( size_t n = 0; n < MAX_COUNT; n++ ) {
			HBRUSH brush = ::CreateSolidBrush( RGB( 0xff, 0xff, 0 ) );
			::FillRect( hDC, &rc, brush );
			::DeleteObject( brush );
		}
	}
	::ReleaseDC( hWnd, hDC );
}

void case2()
{
	HWND hWnd = ::GetDesktopWindow();
	HDC hDC = ::GetDC( hWnd );

	RECT rc;
	::GetWindowRect( hWnd, &rc );

	if ( true )
	{
		CStopWatch sw( __FUNCTION__ );
		for ( size_t n = 0; n < MAX_COUNT; n++ ) {
			COLORREF bkColor = RGB( 0xff, 0xff, 0 );
			COLORREF bkColorOld = ::SetBkColor( hDC, bkColor );
			::ExtTextOut( hDC, rc.left, rc.top, ETO_OPAQUE, &rc, _T( "" ), 0, NULL );
			::SetBkColor( hDC, bkColorOld );
		}
	}
	::ReleaseDC( hWnd, hDC );
}

void case3()
{
	HWND hWnd = ::GetDesktopWindow();
	HDC hDC = ::GetDC( hWnd );

	RECT rc;
	::GetWindowRect( hWnd, &rc );

	if ( true )
	{
		CStopWatch sw( __FUNCTION__ );
		for ( size_t n = 0; n < MAX_COUNT; n++ ) {
			HBRUSH brush = ::CreateSolidBrush( RGB( 0xff, 0xff, 0 ) );
			HGDIOBJ brushOld = ::SelectObject( hDC, brush );
			::PatBlt( hDC, rc.left, rc.top, rc.right, rc.bottom, PATCOPY );
			::SelectObject( hDC, brushOld );
			::DeleteObject( brush );
		}
	}
	::ReleaseDC( hWnd, hDC );
}

void case4()
{
	HWND hWnd = ::GetDesktopWindow();
	HDC hDC = ::GetDC( hWnd );

	RECT rc;
	::GetWindowRect( hWnd, &rc );

	HBRUSH brush = ::CreateSolidBrush( RGB( 0xff, 0xff, 0 ) );

	if ( true )
	{
		CStopWatch sw( __FUNCTION__ );
		for ( size_t n = 0; n < MAX_COUNT; n++ ) {
			::FillRect( hDC, &rc, brush );
		}
	}
	::DeleteObject( brush );
	::ReleaseDC( hWnd, hDC );
}

void case5()
{
	HWND hWnd = ::GetDesktopWindow();
	HDC hDC = ::GetDC( hWnd );

	RECT rc;
	::GetWindowRect( hWnd, &rc );

	COLORREF bkColor = RGB( 0xff, 0xff, 0 );
	COLORREF bkColorOld = ::SetBkColor( hDC, bkColor );

	if ( true )
	{
		CStopWatch sw( __FUNCTION__ );
		for ( size_t n = 0; n < MAX_COUNT; n++ ) {
			::ExtTextOut( hDC, rc.left, rc.top, ETO_OPAQUE, &rc, _T( "" ), 0, NULL );
		}
	}
	::SetBkColor( hDC, bkColorOld );
	::ReleaseDC( hWnd, hDC );
}

void case6()
{
	HWND hWnd = ::GetDesktopWindow();
	HDC hDC = ::GetDC( hWnd );

	RECT rc;
	::GetWindowRect( hWnd, &rc );

	HBRUSH brush = ::CreateSolidBrush( RGB( 0xff, 0xff, 0 ) );
	if ( true )
	{
		CStopWatch sw( __FUNCTION__ );
		for ( size_t n = 0; n < MAX_COUNT; n++ ) {
			HGDIOBJ brushOld = ::SelectObject( hDC, brush );
			::PatBlt( hDC, rc.left, rc.top, rc.right, rc.bottom, PATCOPY );
			::SelectObject( hDC, brushOld );
		}
	}
	::DeleteObject( brush );
	::ReleaseDC( hWnd, hDC );
}

//! メイン処理を実行する
int CSpeedTest::Run( void ) noexcept
{
	try
	{
		case1();
		case2();
		case3();
		case4();
		case5();
		case6();
		return 0;
	}
	catch ( std::exception& ) {
		return UNEXPECTED_ERROR;
	}
}
