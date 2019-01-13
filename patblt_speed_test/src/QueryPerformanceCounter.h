/*! @file GdiUtils.h
 */
#pragma once

#include <tchar.h>
#include <Windows.h>


namespace qpc {

	inline LARGE_INTEGER queryPerformanceFrequency( void ) {
		LARGE_INTEGER Frequency;
		::QueryPerformanceFrequency( &Frequency );
		return std::move( Frequency );
	}
	inline LARGE_INTEGER queryPerformanceCounter( void ) {
		LARGE_INTEGER StartingTime;
		::QueryPerformanceCounter( &StartingTime );
		return std::move( StartingTime );
	}
};
