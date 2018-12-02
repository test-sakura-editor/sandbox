
#include "StdAfx.h"
#include "cxx11_sample.h"


void useCDoNotCopy(void)
{
	// CDoNotCopy
	{
		// コンストラクタ呼出し
		CDoNotCopy obj1;

		// コピーコンストラクタ呼出し
		CDoNotCopy obj2(obj1);

		// コピー演算子呼出し
		CDoNotCopy obj3 = obj1;

		// ムーブ演算子呼出し
		CDoNotCopy obj4(std::move(obj1));

		// ムーブ演算子呼出し
		CDoNotCopy obj5 = std::move(obj1);

	} // ←ここで、デストラクタが呼ばれる
}
