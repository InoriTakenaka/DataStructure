#include"point.h"
#include<cmath>
#include<iostream>

class Vector2d {
private:
	Point point_;
public:
	Vector2d(int x,int y){
		point_ = Point(x,y);
	}
	//ʵ�������ӷ�����
	Vector2d operator+(const Vector2d& rvalue) {		
		int x = rvalue.point_.getX() + p.getX();
		int y = rvalue.point_.getY() + p.getY();
		return Vector2d(x, y);
	}
	//�����������н�֮�������ֵ
	float getIncludedAngle(const Vector2d& rvalue) {
		int product = this->getDotProduct(rvalue);
		float norm_this = sqrtf(point_.getX() * point_.getX() + point_.getX() * point_.getY());
		Point rPoint = rvalue.point_;
		float norm_rvalue = sqrtf(rPoint.getX() * rPoint.getX() + rPoint.getY() * rPoint.getY());
		return product / (norm_this * norm_rvalue);
	}

	//��������������
	int getDotProduct(const Vector2d& rvalue) {
		int newX = point_.getX() * rvalue.point_.getX();
		int newY = point_.getY() * rvalue.point_.getY();
		return newX + newY;
	}
	
	// ����ostream�������������
	friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec);
};