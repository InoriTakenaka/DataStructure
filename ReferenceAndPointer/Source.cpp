#include<iostream>
#include"vector2d.h"

using std::cout;
using std::endl;

std::ostream& operator<<(std::ostream& os,const Vector2d& vec) {
	cout << "(" << vec.point_.getX() << "," << vec.point_.getY() << ")" << endl;
}

int main() {
	
}