
#include "StdAfx.h"
#include "cxx11_sample.h"


void useCDoNotCopyMixedStyle(void)
{
	// CDoNotCopyMixedStyle
	{
		// コンストラクタ呼出し
		CDoNotCopyMixedStyle obj1;

		// コピーコンストラクタ呼出し
		CDoNotCopyMixedStyle obj2(obj1);

		// コピー演算子呼出し
		CDoNotCopyMixedStyle obj3 = obj1;

		// ムーブ演算子呼出し
		CDoNotCopyMixedStyle obj4(std::move(obj1));

		// ムーブ演算子呼出し
		CDoNotCopyMixedStyle obj5 = std::move(obj1);

	} // ←ここで、デストラクタが呼ばれる
}
