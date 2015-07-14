#include "Vector3.h"
#include <math.h>






extern const Vector3 UP(0, 1, 0);
extern const Vector3 DOWN(0, -1, 0);
extern const Vector3 LEFT(-1, 0, 0);
extern const Vector3 RIGHT(1, 0, 0);
extern const Vector3 FORWARD(0, 0, 1);
extern const Vector3 BACK(0, 0, -1);
extern const Vector3 ONE(1, 1, 1);
extern const Vector3 ZERO(0, 0, 0);

Vector3::Vector3()
{
}



Vector3::Vector3(const Vector3 &a)
: x(a.x), y(a.y), z(a.z) {}



Vector3::Vector3(float nx, float ny, float nz)
: x(nx), y(ny), z(nz) {}

// Standard object maintenance
// Assignment. We adhere to C convention and
// return reference to the lvalue
Vector3& Vector3::operator=(const Vector3 &a)
{
	x = a.x; y = a.y; z = a.z;
	return *this;
}

bool Vector3::operator ==(const Vector3 &a) const
{
	return x == a.x && y == a.y && z == a.z;
}

bool Vector3::operator !=(const Vector3 &a) const
{
	return x != a.x || y != a.y || z != a.z;
}
// Vector operations
// Set the vector to zero

void Vector3::zero() { x = y = z = 0.0f; }
// Unary minus returns the negative of the vector
Vector3 Vector3::operator~(void)  { return Vector3(-x, -y, -z); }
// Binary + and – add and subtract vectors

Vector3 Vector3::operator +(const Vector3 &a) const
{
	return Vector3(x + a.x, y + a.y, z + a.z);
}

Vector3 Vector3::operator -(const Vector3 &a)const 
{
	return Vector3(x - a.x, y - a.y, z - a.z);
}

Vector3 Vector3::operator *(float a) const
{
	return Vector3(x*a, y*a, z*a);
}


Vector3 Vector3::operator /(float a) const
{
	float oneOverA = 1.0f / a; // NOTE: no check for divide by zero here
	return Vector3(x*oneOverA, y*oneOverA, z*oneOverA);
}


Vector3& Vector3::operator +=(const Vector3 &a)
{
	x += a.x; y += a.y; z += a.z;
	return *this;
}


Vector3& Vector3::operator -= (const Vector3 &a)
{
	x -= a.x; y -= a.y; z -= a.z;
	return *this;
}


Vector3& Vector3::operator *=(float a)
{
	x *= a; y *= a; z *= a;
	return *this;
}


Vector3& Vector3::operator /= (float a)
{
	float oneOverA = 1.0f / a;
	x *= oneOverA; y *= oneOverA; z *= oneOverA;
	return *this;
}



void Vector3::normalize()
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


float Vector3::operator *(const Vector3 &a) const
{
	return x*a.x + y*a.y + z*a.z;
}


/////////////////////////////////////////////////////////////////////////////
//
// Nonmember functions
//
/////////////////////////////////////////////////////////////////////////////
// Compute the magnitude of a vector
inline float vectorMag(const Vector3 &a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}
// Compute the cross product of two vectors

inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b) 
{
	return Vector3(
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x
		);
}
// Scalar on the left multiplication, for symmetry
inline Vector3 operator *(float k, const Vector3 &v) 
{
	return Vector3(k*v.x, k*v.y, k*v.z);
}
// Compute the distance between two points
inline float distance(const Vector3 &a, const Vector3 &b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}