#include<iostream>
using std::cout;
using std::endl;
#include"vector2d.h"
namespace reference {
	/**
* 一、左值与右值的简单理解：
* lvalue: 有地址，有值，可以出现在等号的左边
* rvalue: 只有值，没有地址，多半都是临时值，只能出现在等号的右边*
* 例如，你可以写:
* int i = 10;
* i这个变量，他被保存在栈上，在内存中有一席之地，并且它的值是10。所以是左值。
* 而对于等号右边的这个数字10，它只有一个值，却没有地址。内存中没有他的位置。所以是右值。
* 所以从没见过人这样写代码：
* 10 = i
* 你可以将10赋值给一个变量，但是反过来不可以把变量赋值给10
* =>
*
*
* 二、引用
* C++中的引用，可以简单理解为给已经存在的 变量、对象 起一个别名。
*
* 引用与指针 本质上是同一个东西，只是一个为了让程序员更好
* 理解更容易去使用的一个语法糖。
*
* 语法为：
* (1) &   —— 左值引用
* (2) &&  —— 右值引用
*/

/*-------  reference use case ----------*/

    // 用于给变量起一个别名
	void Foo() {
		int i = 10;
		int& a = i;
		const int& b = i;
		cout << "i is : " << i << endl;
		cout << "b is : " << b << endl;
		a = 11;
		//b = 12; // b是一个右值，所以编译器会提示： expression must be a modifiable lvalue
		cout << "i is : " << i << endl;
		cout << "a is : " << a << endl;
	}

	// 进行引用的传递
	void SetValue(int&& Src,int& Dst) {
		Dst = Src;		
	}

	void SetValue(int Src, int Dst) {
		Src = Dst;
	}
}

using namespace reference;

int main() {
	int a = 10, b = 12;
	SetValue(a, b);
	cout << a << endl;
}