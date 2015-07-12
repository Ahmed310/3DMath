#ifndef _VECTOR3_H
#define _VECTOR3_H

template<class type>
class Vector3
{
public:
	Vector3();
	~Vector3();
	
	// Copy constructor
	Vector3(const Vector3 &a);
	// Construct given three values
	Vector3(type nx, type ny, type nz);

	
	Vector3 &operator =(const Vector3 &a);    // return reference to the lvalue
	Vector3 operator +(const Vector3 &a) const;    // Binary + and – add and subtract vectors
	Vector3 operator –(const Vector3 &a) const;
	Vector3 operator *(type a) const;    // Multiplication and division by scalar
	Vector3 operator /(type a) const;

	Vector3& operator+=(const Vector3 &a); // Combined assignment operators
	Vector3& operator–= (const Vector3 &a);
	Vector3& operator *=(type a);
	Vector3& operator /=(type a);
	
	bool operator ==(const Vector3 &a) const;    // Check for equality
	bool operator !=(const Vector3 &a) const;
	type operator *(const Vector3 &a) const;    // Vector dot product

	void zero();    // Set the vector to zero
	void normalize();    // Normalize the vector

public:
	type x, y, z;
};



/////////////////////////////////////////////////////////////////////////////
//
// Global variables
//
/////////////////////////////////////////////////////////////////////////////
// We provide a global zero vector constant
template<typename type>
extern const Vector3 kZeroVector;


/////////////////////////////////////////////////////////////////////////////
//
// Nonmember functions
//
/////////////////////////////////////////////////////////////////////////////

template<typename type>
inline type vectorMag(const Vector3 &a);    //  Compute the magnitude of a vector

template<typename type>
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b); // Compute the cross product of two vectors

template<typename type>
inline Vector3 operator *(float k, const Vector3 &v);    // Scalar on the left multiplication, for symmetry

template<typename type>
inline type distance(const Vector3 &a, const Vector3 &b);    // Compute the distance between two points



#endif

