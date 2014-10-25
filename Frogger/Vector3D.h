#pragma once
class Vector3D
{

	float x, y, z;

public:
	float GetMagnitude();
	Vector3D operator*(float num) const;
	friend Vector3D operator*(float num, Vector3D const &vec);
	Vector3D operator+(const Vector3D &vec) const;
	Vector3D operator-(const Vector3D &vec) const;
	void normalizeVector3D();
	float dotVector3D(const Vector3D &vec) const;
	Vector3D crossVector3D(const Vector3D &vec) const;
	void set(float X, float Y, float Z);
	float getX();
	float getY();
	float getZ();

	Vector3D(float X, float Y, float Z);
	Vector3D();
	~Vector3D();
};

