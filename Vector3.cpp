#include "Vector3.h"
#include <math.h>




//template<typename type>
//const Vector3 Vector3::kZeroVector = Vector3(0f,0f,0f);


template <typename  type>
Vector3<type>::Vector3()
{
}

template <typename  type>
Vector3<type>::~Vector3()
{
}

template <typename  type>
Vector3<type>::Vector3(const Vector3 &a)
: x(a.x), y(a.y), z(a.z) {}


template <typename  type>
Vector3<type>::Vector3(type nx, type ny, type nz)
: x(nx), y(ny), z(nz) {}

// Standard object maintenance
// Assignment. We adhere to C convention and
// return reference to the lvalue
template <typename type>
Vector3& Vector3<type>::operator=(const Vector3 &a)
{
	x = a.x; y = a.y; z = a.z;
	return *this;
}

template <typename type>
bool Vector3<type>::operator ==(const Vector3 &a) const
{
	return x == a.x && y == a.y && z == a.z;
}

template <typename type>
bool Vector3<type>::operator !=(const Vector3 &a) const
{
	return x != a.x || y != a.y || z != a.z;
}
// Vector operations
// Set the vector to zero
template <typename type>
void Vector3<type>::zero() { x = y = z = 0.0f; }
// Unary minus returns the negative of the vector
template <typename type>
Vector3 Vector3<type>::operator –() const { return Vector3(–x, –y, –z); }
// Binary + and – add and subtract vectors
template <typename type>
Vector3 Vector3<type>::operator +(const Vector3 &a) const
{
	return Vector3<>(x + a.x, y + a.y, z + a.z);
}

template <typename type>
Vector3 Vector3<type>::operator –(const Vector3 &a) const
{
	return Vector3(x – a.x, y – a.y, z – a.z);
}

template <typename type>
Vector3 Vector3<type>::operator *(float a) const
{
	return Vector3(x*a, y*a, z*a);
}

template <typename type>
Vector3 Vector3<type>::operator /(float a) const
{
	float oneOverA = 1.0f / a; // NOTE: no check for divide by zero here
	return Vector3(x*oneOverA, y*oneOverA, z*oneOverA);
}

template <typename type>
Vector3& Vector3<type>::operator +=(const Vector3 &a)
{
	x += a.x; y += a.y; z += a.z;
	return *this;
}

template <typename type>
Vector3& Vector3<type>::operator – = (const Vector3 &a)
{
	x – = a.x; y – = a.y; z – = a.z;
	return *this;
}

template <typename type>
Vector3& Vector3<type>::operator *=(float a)
{
	x *= a; y *= a; z *= a;
	return *this;
}

template <typename type>
Vector3& Vector3<type>::operator /= (float a)
{
	float oneOverA = 1.0f / a;
	x *= oneOverA; y *= oneOverA; z *= oneOverA;
	return *this;
}


template <typename type>
void Vector3<type>::normalize()
{
	float magSq = x*x + y*y + z*z;
	
	if (magSq > 0.0f) 
	{ 
		// check for divide-by-zero
		float oneOverMag = 1.0f / sqrt(magSq);
		x *= oneOverMag;
		y *= oneOverMag;
		z *= oneOverMag;
	}
}

template<typename type>
type Vector3<type>::operator *(const Vector3 &a) const
{
	return x*a.x + y*a.y + z*a.z;
}










/////////////////////////////////////////////////////////////////////////////
//
// Nonmember functions
//
/////////////////////////////////////////////////////////////////////////////
// Compute the magnitude of a vector
template<typename type>
inline type vectorMag(const Vector3 &a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}
// Compute the cross product of two vectors

template<typename type>
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b) 
{
	return Vector3(
		a.y*b.z – a.z*b.y,
		a.z*b.x – a.x*b.z,
		a.x*b.y – a.y*b.x
		);
}
// Scalar on the left multiplication, for symmetry
template<typename type>
inline Vector3 operator *(float k, const Vector3 &v) 
{
	return Vector3(k*v.x, k*v.y, k*v.z);
}
// Compute the distance between two points
template<typename type>
inline type distance(const Vector3 &a, const Vector3 &b)
{
	float dx = a.x – b.x;
	float dy = a.y – b.y;
	float dz = a.z – b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}