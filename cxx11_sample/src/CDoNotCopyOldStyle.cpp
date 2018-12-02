
#include "StdAfx.h"
#include "cxx11_sample.h"


void useCDoNotCopyOldStyle(void)
{
	//CDoNotCopyOldStyle
	{
		// コンストラクタ呼出し
		CDoNotCopyOldStyle obj1;

		// コピーコンストラクタ呼出し
		CDoNotCopyOldStyle obj2(obj1);

		// コピー演算子呼出し
		CDoNotCopyOldStyle obj3 = obj1;

		// ムーブ演算子呼出し
		CDoNotCopyOldStyle obj4(std::move(obj1));

		// ムーブ演算子呼出し
		CDoNotCopyOldStyle obj5 = std::move(obj1);

	} // ←ここで、デストラクタが呼ばれる
}
