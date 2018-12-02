#pragma once


/*!
 * 標準クラス
 */
class CSimple {

	typedef CSimple _Myt;

public:
	// 定義できる6種類すべてを default に指定。
	// 生成されるコードは「省略」した場合と同じ。
	CSimple(void) noexcept = default;
	virtual ~CSimple(void) noexcept = default;
	CSimple(const _Myt &other) noexcept = default;
	_Myt& operator = (const _Myt &rhs) noexcept = default;
	CSimple(_Myt &&other) noexcept = default;
	_Myt& operator = (_Myt &&rhs) noexcept = default;
};


/*!
 * コピー禁止クラス(旧式)
 *
 * コンストラクタ/演算子にアクセスできない、というエラーになる。
 */
class CDoNotCopyOldStyle {

	// メンバにリソースを含むクラスはコピー禁止とするのが普通。
	HFONT hFont;

	typedef CDoNotCopyOldStyle _Myt;

public:
	// コピー禁止クラスは普通、独自コンストラクタを定義する
	CDoNotCopyOldStyle(void)
		: hFont(NULL)
	{
		// 普通は定義する、というだけで言語仕様ではない。
	}
	// コピー禁止クラスは普通、独自デストラクタを定義する
	virtual ~CDoNotCopyOldStyle(void)
	{
		// 普通は定義する、というだけで言語仕様ではない。
		if (hFont) {
			::DeleteObject(hFont);
			hFont = NULL;
		}
	}

private:
	// 宣言だけして実装しない
	CDoNotCopyOldStyle(const _Myt &other);
	_Myt& operator = (const _Myt &rhs);
};


/*!
 * コピー禁止クラス(省略形)
 * 
 * ムーブしようとしたときのエラーが分かりづらいのでお勧めしない。
 */
class CDoNotCopySimple {

	// メンバにリソースを含むクラスはコピー禁止とするのが普通。
	HFONT hFont;

	typedef CDoNotCopySimple _Myt;

public:
	// コピー禁止クラスは普通、独自コンストラクタを定義する
	CDoNotCopySimple(void) noexcept
		: hFont(NULL)
	{
		// 普通は定義する、というだけで言語仕様ではない。
	}
	// コピー禁止クラスは普通、独自デストラクタを定義する
	virtual ~CDoNotCopySimple(void) noexcept
	{
		// 普通は定義する、というだけで言語仕様ではない。
		if (hFont) {
			::DeleteObject(hFont);
			hFont = NULL;
		}
	}

	// コピーコンストラクタを削除して自動生成されないようにする
	CDoNotCopySimple(const _Myt &other) = delete;
	// コピー代入演算子を削除して自動生成されないようにする
	_Myt& operator = (const _Myt &rhs) = delete;
	// ムーブのデフォルト実装はコピーなので、defaultにしてもコピー不可だが、該当行にエラー表示が出ないので分かりづらい
	CDoNotCopySimple(_Myt &&other) = default;
	// ムーブのデフォルト実装はコピーなので、defaultにしてもコピー不可だが、該当行にエラー表示が出ないので分かりづらい
	_Myt& operator = (_Myt &&rhs) = default;
};


/*!
 * コピー禁止クラス
 *
 * これが推奨実装。
 */
class CDoNotCopy {

	// メンバにリソースを含むクラスはコピー禁止とするのが普通。
	HFONT hFont;

	typedef CDoNotCopy _Myt;

public:
	// コピー禁止クラスは普通、独自コンストラクタを定義する
	CDoNotCopy(void) noexcept
		: hFont(NULL)
	{
		// 普通は定義する、というだけで言語仕様ではない。
	}
	// コピー禁止クラスは普通、独自デストラクタを定義する
	virtual ~CDoNotCopy(void) noexcept
	{
		// 普通は定義する、というだけで言語仕様ではない。
		if (hFont) {
			::DeleteObject(hFont);
			hFont = NULL;
		}
	}

	// コピーコンストラクタを削除して自動生成されないようにする
	CDoNotCopy(const _Myt &other) = delete;
	// コピー代入演算子を削除して自動生成されないようにする
	_Myt& operator = (const _Myt &rhs) = delete;
	// ムーブコンストラクタを削除して自動生成されないようにする
	CDoNotCopy(_Myt &&other) = delete;
	// ムーブ代入演算子を削除して自動生成されないようにする
	_Myt& operator = (_Myt &&rhs) = delete;
};


/*!
 * コピー禁止クラス(新旧複合)
 * 
 * コンストラクタ/演算子にアクセスできない、というエラーになるのでお勧めしない。
 */
class CDoNotCopyMixedStyle {

	// メンバにリソースを含むクラスはコピー禁止とするのが普通。
	HFONT hFont;

	typedef CDoNotCopyMixedStyle _Myt;

public:
	// コピー禁止クラスは普通、独自コンストラクタを定義する
	CDoNotCopyMixedStyle(void) noexcept
		: hFont(NULL)
	{
		// 普通は定義する、というだけで言語仕様ではない。
	}
	// コピー禁止クラスは普通、独自デストラクタを定義する
	virtual ~CDoNotCopyMixedStyle(void) noexcept
	{
		// 普通は定義する、というだけで言語仕様ではない。
		if (hFont) {
			::DeleteObject(hFont);
			hFont = NULL;
		}
	}

private:
	// コピーコンストラクタを削除して自動生成されないようにする
	CDoNotCopyMixedStyle(const _Myt &other) = delete;
	// コピー代入演算子を削除して自動生成されないようにする
	_Myt& operator = (const _Myt &rhs) = delete;
	// ムーブコンストラクタを削除して自動生成されないようにする
	CDoNotCopyMixedStyle(_Myt &&other) = delete;
	// ムーブ代入演算子を削除して自動生成されないようにする
	_Myt& operator = (_Myt &&rhs) = delete;
};


/*!
 * ムーブ可能コピー禁止クラス
 */
class CMovableTypeDoNotCopy {

	// メンバにリソースを含むクラスはコピー禁止とするのが普通。
	// しかし、リソースなので所有権移動によるムーブができたほうが便利。
	HFONT hFont;

	typedef CMovableTypeDoNotCopy _Myt;

public:
	// コピー禁止クラスは普通、独自コンストラクタを定義する
	CMovableTypeDoNotCopy(void) noexcept
		: hFont(NULL)
	{
		// 普通は定義する、というだけで言語仕様ではない。
	}
	// コピー禁止クラスは普通、独自デストラクタを定義する
	virtual ~CMovableTypeDoNotCopy(void) noexcept
	{
		// 普通は定義する、というだけで言語仕様ではない。
		if (hFont) {
			::DeleteObject(hFont);
			hFont = NULL;
		}
	}

	// コピーコンストラクタを削除して自動生成されないようにする
	CMovableTypeDoNotCopy(const _Myt &other) = delete;
	// コピー代入演算子を削除して自動生成されないようにする
	_Myt& operator = (const _Myt &rhs) = delete;
	// ムーブコンストラクタ
	CMovableTypeDoNotCopy(_Myt &&other) noexcept
		: hFont(NULL)
	{
		// 実処理はムーブ演算子に移譲する
		*this = std::forward<_Myt>(other);
	}
	// ムーブ代入演算子
	_Myt& operator = (_Myt &&rhs) noexcept
	{
		// メンバデータを入れ替える
		std::swap(hFont, rhs.hFont);
	}
};
