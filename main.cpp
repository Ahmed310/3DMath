#include<iostream>

#include"Vector3.h"

int main()
{
	Vector3 a(1,1,1);
	Vector3 b (5,5,5);

	std::cout << (b - a).x << std::endl;
	std::cout << ZERO.x << std::endl;
	std::cout << UP.y << std::endl;

	return 0;
}