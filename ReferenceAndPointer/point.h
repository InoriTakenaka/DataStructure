#include<cmath>
/// <summary>
/// 表示二维平面中的一个点
/// </summary>
struct Point {
private:
	/// <summary>
	/// 点的横坐标
	/// </summary>
	int x_;
	/// <summary>
	/// 点的纵坐标
	/// </summary>
	int y_;
public:
	Point(int x, int y) :x_(x), y_(y) {	}
	Point() :x_(0), y_(0) {}
	/// <summary>
	/// 获得X坐标
	/// </summary>
	/// <returns></returns>
	int getX() const {
		return x_;
	}
	/// <summary>
	/// 设置X坐标
	/// </summary>
	/// <param name="val"></param>
	void setX(int val) {
		x_ = val;
	}
	/// <summary>
	/// 获得Y坐标
	/// </summary>
	/// <returns></returns>
	int getY() const {
		return y_;
	}
	/// <summary>
	/// 设置Y坐标
	/// </summary>
	/// <param name="val"></param>
	void setY(int val) {
		y_ = val;
	}
	/// <summary>
	/// 计算点到坐标原点(0,0)的距离
	/// </summary>
	/// <returns></returns>
	float distance() {
		return sqrtf(x_ * x_ + y_ * y_);
	}
};