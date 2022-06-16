#include"point.h"
#include<cmath>

class Vector2d {
private:
	Point point_;
public:
	Vector2d(int x,int y){
		point_ = Point(x,y);
	}
	//实现向量加法运算
	Vector2d operator+(const Vector2d& rvalue) {		
		Point p = rvalue.point_;
		int x = point_.getX() + p.getX();
		int y = point_.getY() + p.getY();
		return Vector2d(x, y);
	}
	//求两个向量夹角之间的余弦值
	float getIncludedAngle(const Vector2d& rvalue) {

	}
	//求向量的数量积
	int getDotProduct(const Vector2d& rvalue) {

	}
};