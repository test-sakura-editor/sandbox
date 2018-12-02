
#include "StdAfx.h"
#include "cxx11_sample.h"


void useCDoNotCopySimple(void)
{
	// CDoNotCopySimple
	{
		// コンストラクタ呼出し
		CDoNotCopySimple obj1;

		// コピーコンストラクタ呼出し
		CDoNotCopySimple obj2(obj1);

		// コピー演算子呼出し
		CDoNotCopySimple obj3 = obj1;

		// ムーブ演算子呼出し
		CDoNotCopySimple obj4(std::move(obj1));

		// ムーブ演算子呼出し
		CDoNotCopySimple obj5 = std::move(obj1);

	} // ←ここで、デストラクタが呼ばれる
}
