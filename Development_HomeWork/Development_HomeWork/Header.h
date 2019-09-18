#ifndef _Header_H
#define _Header_H
using namespace std;

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
};

template<class T>
vec3<T>::vec3() {}

template<class T>
vec3<T>::~vec3() {}

template<class T>
vec3<T>::vec3(T tx, T ty, T tz) {}


#endif // !_Header
