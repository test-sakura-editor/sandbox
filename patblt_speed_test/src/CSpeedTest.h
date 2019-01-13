/*! @file CSpeedTest.h
 */
#pragma once

#include <tchar.h>
#include <Windows.h>

#include <cstdint>
#include <memory>
#include <vector>
#include <iosfwd>

#include "QueryPerformanceCounter.h"

//! アプリケーションクラス
class CSpeedTest
{
	HINSTANCE m_hInstance;
	LPCTSTR m_lpCmdLine;
	HRESULT m_hrOleInit;

public:
	/*! エラーコードはテキトーに振る
	 */
	enum {
		BAD_COMMAND_LINE = INT_MIN,
		FAILED_TO_INIT,
		UNEXPECTED_ERROR,
	};

public:
	CSpeedTest( HINSTANCE hInstance, LPCTSTR lpCmdLine ) noexcept;
	virtual ~CSpeedTest( void ) noexcept;

public:
	bool InitInstance( void ) noexcept;
	int Run( void ) noexcept;
};
