/*! @file winmain.cpp
 */
#include "StdAfx.h"

#include <tchar.h>
#include <Windows.h>
#include <clocale>

#include "CSpeedTest.h"

//! Main関数
int WINAPI _tWinMain(
	HINSTANCE	hInstance,		//!< handle to current instance
	HINSTANCE	hPrevInstance,	//!< handle to previous instance
	LPTSTR		lpCmdLine,		//!< pointer to command line
	int			nCmdShow		//!< show state of window
)
{
	// Cロケールを初期化する
	auto loc = ::_tsetlocale( LC_ALL, L"Japanese_Japan.932" );
	assert( loc ); //あり得ない

	// アプリクラスのインスタンスを生成
	CSpeedTest app( hInstance, lpCmdLine );

	// 初期化実施
	if ( !app.InitInstance() ) {
		return CSpeedTest::FAILED_TO_INIT;
	}

	// メイン処理実行
	return app.Run();
}
