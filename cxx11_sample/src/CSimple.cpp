
#include "StdAfx.h"
#include "cxx11_sample.h"


void useCSimple(void)
{
	//CSimple
	{
		// コンストラクタ呼出し
		CSimple obj1;

		// コピーコンストラクタ呼出し
		CSimple obj2(obj1);

		// コピー演算子呼出し
		CSimple obj3 = obj1;

		// ムーブ演算子呼出し
		CSimple obj4(std::move(obj1));

		// ムーブ演算子呼出し
		CSimple obj5 = std::move(obj1);

	} // ←ここで、デストラクタが呼ばれる
}
