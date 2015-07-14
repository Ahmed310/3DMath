#ifndef _VECTOR3_H
#define _VECTOR3_H


class Vector3
{
public:
	Vector3();
	
	// Copy constructor
	Vector3(const Vector3 &a);
	// Construct given three values
	Vector3(float nx, float ny, float nz);

public:

	Vector3& operator =(const Vector3 &a);    // return reference to the lvalue
	Vector3  operator +(const Vector3 &a) const;    // Binary + and – add and subtract vectors
	Vector3  operator -(const Vector3 &a) const;
	Vector3  operator *(float a) const;    // Multiplication and division by scalar
	Vector3  operator /(float a) const;
	Vector3  operator ~(void);
	Vector3& operator +=(const Vector3& a);      // Combined assignment operators
	Vector3& operator -=( const Vector3& a );
	Vector3& operator *=(float a);
	Vector3& operator /=(float a);
	
	bool operator ==(const Vector3 &a) const;    // Check for equality
	bool operator !=(const Vector3 &a) const;
	float operator *(const Vector3 &a) const;    // Vector dot product

	void zero();    // Set the vector to zero
	void normalize();    // Normalize the vector

public:
	float x, y, z;
};



/////////////////////////////////////////////////////////////////////////////
//
// Global variables
//
/////////////////////////////////////////////////////////////////////////////

//  global constant vectors which are commonly used (forward declaration )

extern const Vector3 UP;
extern const Vector3 DOWN;
extern const Vector3 LEFT;
extern const Vector3 RIGHT;
extern const Vector3 FORWARD;
extern const Vector3 BACK;
extern const Vector3 ONE;
extern const Vector3 ZERO;

/////////////////////////////////////////////////////////////////////////////
//
// Nonmember functions
//
/////////////////////////////////////////////////////////////////////////////


inline float vectorMag(const Vector3 &a);    //  Compute the magnitude of a vector
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b); // Compute the cross product of two vectors
inline Vector3 operator *(float k, const Vector3 &v);    // Scalar on the left multiplication, for symmetry
inline float distance(const Vector3 &a, const Vector3 &b);    // Compute the distance between two points



#endif

