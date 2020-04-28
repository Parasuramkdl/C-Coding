#pragma once

class Polar
{
	float m_angle;
	int m_radius;
public:
	static int count;
	
public:
	Polar();
	Polar(float a,int r);
	~Polar();
	static void PrintPolarCount();
};

