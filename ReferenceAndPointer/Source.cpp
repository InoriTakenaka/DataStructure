#include<iostream>
using std::cout;
using std::endl;
#include"vector2d.h"
namespace reference {
	/**
* һ����ֵ����ֵ�ļ���⣺
* lvalue: �е�ַ����ֵ�����Գ����ڵȺŵ����
* rvalue: ֻ��ֵ��û�е�ַ����붼����ʱֵ��ֻ�ܳ����ڵȺŵ��ұ�*
* ���磬�����д:
* int i = 10;
* i�������������������ջ�ϣ����ڴ�����һϯ֮�أ���������ֵ��10����������ֵ��
* �����ڵȺ��ұߵ��������10����ֻ��һ��ֵ��ȴû�е�ַ���ڴ���û������λ�á���������ֵ��
* ���Դ�û����������д���룺
* 10 = i
* ����Խ�10��ֵ��һ�����������Ƿ����������԰ѱ�����ֵ��10
* =>
*
*
* ��������
* C++�е����ã����Լ����Ϊ���Ѿ����ڵ� ���������� ��һ��������
*
* ������ָ�� ��������ͬһ��������ֻ��һ��Ϊ���ó���Ա����
* ��������ȥʹ�õ�һ���﷨�ǡ�
*
* �﷨Ϊ��
* (1) &   ���� ��ֵ����
* (2) &&  ���� ��ֵ����
*/

/*-------  reference use case ----------*/

    // ���ڸ�������һ������
	void Foo() {
		int i = 10;
		int& a = i;
		const int& b = i;
		cout << "i is : " << i << endl;
		cout << "b is : " << b << endl;
		a = 11;
		//b = 12; // b��һ����ֵ�����Ա���������ʾ�� expression must be a modifiable lvalue
		cout << "i is : " << i << endl;
		cout << "a is : " << a << endl;
	}

	// �������õĴ���
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