#include <stdio.h>
#include "Header.h"

int main()
{
	vec3<float>v1, v2;

	v1 = { 1,1,1 };
	v2 = { 2,2,2 };

	std::cout << "Distance from v1 to v2: " << v1.distance_to(v2) << std::endl;

	system("pause");
	return 0;
}
