
#include "StdAfx.h"
#include "cxx11_sample.h"


void useCMovableTypeDoNotCopy(void)
{
	// CMovableTypeDoNotCopy
	{
		// コンストラクタ呼出し
		CMovableTypeDoNotCopy obj1;

		// コピーコンストラクタ呼出し
		CMovableTypeDoNotCopy obj2(obj1);

		// コピー演算子呼出し
		CMovableTypeDoNotCopy obj3 = obj1;

		// ムーブ演算子呼出し
		CMovableTypeDoNotCopy obj4(std::move(obj1));

		// ムーブ演算子呼出し
		CMovableTypeDoNotCopy obj5 = std::move(obj1);

	} // ←ここで、デストラクタが呼ばれる
}
