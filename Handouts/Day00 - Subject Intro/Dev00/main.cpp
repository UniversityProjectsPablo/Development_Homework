#include <stdio.h>
#include "Header.h"

int main()
{
	vec3<float>v1, v2;
	int option = 0;
	float x, y, z;
	for(int i=0;i<2;i++)
	{
		std::cout << "Choose values for vector " << i+1 << endl << "x: ";
		std::cin >> x;
		std::cout << "y: ";
		std::cin >> y;
		std::cout << "z: ";
		std::cin >> z;
		if(i==0)
			v1 = { x,y,z };
		else
			v2 = { x,y,z };
	}	
	
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
		if (v1.is_zero())
			cout << "V1 is zero" << endl;
		else
			cout << "V1 is not zero" << endl;
		
		if (v2.is_zero())
			cout << "V2 is zero" << endl;
		else
			cout << "V2 is not zero" << endl;
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
