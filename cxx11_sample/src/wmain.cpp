
#include "StdAfx.h"
#include "cxx11_sample.h"

void useCSimple();
void useCDoNotCopyOldStyle();
void useCDoNotCopySimple();
void useCDoNotCopy();
void useCDoNotCopyMixedStyle();
void useCMovableTypeDoNotCopy();


int wmain(int argc, WCHAR* argv[])
{
	useCSimple();
	useCDoNotCopyOldStyle();
	useCDoNotCopySimple();
	useCDoNotCopy();
	useCDoNotCopyMixedStyle();
	useCMovableTypeDoNotCopy();

	return 0;
}

