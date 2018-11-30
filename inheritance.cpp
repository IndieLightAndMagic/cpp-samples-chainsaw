

#include <iostream>
#include "foo.h"

void A::anotherfoo()
{
	/* do */
	std::cout << "anotherfoo\n";
}


void B::foo()
{
	std::cout << "B" << std::endl;
}

float Circle::area() const 	{
	return Shape::area();
	//return 3.14159216 * m_radius;
}
float Triangle::area() const {

	return m_base * m_height * 0.5;
}
float Shape::area() const {

	return 0.0f;
}
void x(Shape* pShape)
{

	Circle* pCircle = dynamic_cast<Circle*>(pShape); //pCircle == nullptr;
	if (pCircle == nullptr){
		Triangle* pTriangle = dynamic_cast<Triangle*>(pShape);
	}
	else {
		Shape* pAnotherShape = static_cast<Shape*>(pCircle);	
	}
	 
}
int main()
{
	A a;
	B b;
	
	a.foo();
	b.foo(); //error de compilador
	Shape* pShape = new Triangle();
	x(pShape);
	Line l;
	float area_rara = l.area();
	std::cout << area_rara << std::endl;
	return 0;
}
