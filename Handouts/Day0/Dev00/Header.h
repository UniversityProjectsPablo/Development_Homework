#ifndef _Header_H
#define _Header_H
using namespace std;
#include <math.h>
#include <string.h>
#include <iostream>

template <class T>
class vec3 {
private:
	T x;
	T y;
	T z;

public:
	vec3();
	vec3(T, T, T);
	~vec3();
	void normalize();
	void zero();
	bool is_zero();
	float distance_to(vec3);
};

template<class T>
vec3<T>::vec3() {}

template<class T>
vec3<T>::~vec3() {}



template<class T>
vec3<T>::vec3(T tx, T ty, T tz) {}

template<class T>
bool vec3<T>::is_zero() 
{
	if (x == 0 && y == 0 && z == 0)
		return true;
	else
		return false;
}

template<class T>
float vec3<T>::distance_to(vec3) 
{
	float distance;

	distance = sqrt(pow(x - vec3, 2) + pow(y - vec3, 2) + pow(z - vec3, 2));

	return distance;
}

#endif // !_Header
