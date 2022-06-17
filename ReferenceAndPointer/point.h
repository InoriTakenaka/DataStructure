#include<cmath>
/// <summary>
/// ��ʾ��άƽ���е�һ����
/// </summary>
struct Point {
private:
	/// <summary>
	/// ��ĺ�����
	/// </summary>
	int x_;
	/// <summary>
	/// ���������
	/// </summary>
	int y_;
public:
	Point(int x, int y) :x_(x), y_(y) {	}
	Point() :x_(0), y_(0) {}
	/// <summary>
	/// ���X����
	/// </summary>
	/// <returns></returns>
	int getX() const {
		return x_;
	}
	/// <summary>
	/// ����X����
	/// </summary>
	/// <param name="val"></param>
	void setX(int val) {
		x_ = val;
	}
	/// <summary>
	/// ���Y����
	/// </summary>
	/// <returns></returns>
	int getY() const {
		return y_;
	}
	/// <summary>
	/// ����Y����
	/// </summary>
	/// <param name="val"></param>
	void setY(int val) {
		y_ = val;
	}
	/// <summary>
	/// ����㵽����ԭ��(0,0)�ľ���
	/// </summary>
	/// <returns></returns>
	float distance() {
		return sqrtf(x_ * x_ + y_ * y_);
	}
};