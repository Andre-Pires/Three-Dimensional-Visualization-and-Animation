#include "stdafx.h"
#include "Vector3D.h"
#include <math.h>

//default constructor
Vector3D::Vector3D()
{
}

Vector3D::Vector3D(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}
Vector3D::~Vector3D(){};

//calculate and return the magnitude of this vector
void Vector3D::set(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}

//calculate and return the magnitude of this vector
float Vector3D::GetMagnitude()
{
	return sqrtf(x * x + y * y + z * z);
}

//multiply this vector by a scalar
Vector3D Vector3D::operator*(float num) const
{
	return Vector3D(x * num, y * num, z * num);
}

//pass in a vector, pass in a scalar, return the product
Vector3D operator*(float num, Vector3D const &vec)
{
	return Vector3D(vec.x * num, vec.y * num, vec.z * num);
}

//add two vectors
Vector3D Vector3D::operator+(const Vector3D &vec) const
{
	return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

//subtract two vectors
Vector3D Vector3D::operator-(const Vector3D &vec) const
{
	return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

//normalize this vector
void Vector3D::normalizeVector3D()
{
	float magnitude = sqrtf(x * x + y * y + z * z);
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

//calculate and return dot product
float Vector3D::dotVector3D(const Vector3D &vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

//calculate and return cross product
Vector3D Vector3D::crossVector3D(const Vector3D &vec) const
{
	return Vector3D(y * vec.z - z * vec.y,
		z * vec.x - x * vec.z,
		x * vec.y - y * vec.x);
}

float Vector3D::getX(){
	return x;
}

float Vector3D::getY(){
	return y;
}

float Vector3D::getZ(){
	return z;
}
