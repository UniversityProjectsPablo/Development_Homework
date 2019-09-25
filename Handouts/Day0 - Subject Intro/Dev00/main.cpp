#include <stdio.h>
#include "Header.h"

int main()
{
	vec3<float>v1, v2;
	int option = 0;

	v1 = { 1,2,3 };
	v2 = { 2,58,2 };
	std::cout << "Vector 1 = {" << v1.x << ", " << v1.y << ", " << v1.z << "}" << endl << 
		"Vector 2 = {" << v2.x << ", " << v2.y << ", " << v2.z << "}" << endl << "----------" << endl;
	std::cout << "What do you want to do? " << endl <<
		"1. Normalize vector" << endl <<
		"2. Is zero?" << endl <<
		"3. Distance to" << endl << endl <<
		"My decision is: ";
	std::cin >> option;

	switch(option)
	{
	case 1:
		v1.normalize();
		v2.normalize();
		std::cout << "Vector 1 = {" << v1.x << ", " << v1.y << ", " << v1.z << "}" << endl <<
			"Vector 2 = {" << v2.x << ", " << v2.y << ", " << v2.z << "}" << endl << "----------" << endl;
		break;
	case 2:

		break;
	case 3:
		std::cout << "Distance from v1 to v2: " << v1.distance_to(v2) << std::endl;
		break;
	default:

		break;
	}
	

	system("pause");
	return 0;
}
