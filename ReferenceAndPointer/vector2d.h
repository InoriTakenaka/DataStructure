#include"point.h"
#include<cmath>

class Vector2d {
private:
	Point point_;
public:
	Vector2d(int x,int y){
		point_ = Point(x,y);
	}
	//ʵ�������ӷ�����
	Vector2d operator+(const Vector2d& rvalue) {		
		Point p = rvalue.point_;
		int x = point_.getX() + p.getX();
		int y = point_.getY() + p.getY();
		return Vector2d(x, y);
	}
	//�����������н�֮�������ֵ
	float getIncludedAngle(const Vector2d& rvalue) {

	}
	//��������������
	int getDotProduct(const Vector2d& rvalue) {

	}
};