#pragma once

#include "Vector.h"

void DotProductTest1()
{
	cout << "DotProductTest1: > 90 deg or > 1/2*PI " << endl;
	//> 90 deg or > 1/2*PI 
	Vector2 vec1(1.0f, 2.0f);
	Vector2 vec2(1.0f, -1.0f);
	float dotRes = vec1.Dot(vec2);
	float angle = vec1.AngleBetweenVectors(vec2);
	cout << "vec1: " << vec1 << endl << "vec2: " << vec2 << endl << "dot result: " << dotRes << endl << "angle: " << angle << endl << endl;
}

void DotProductTest2()
{
	cout << "DotProductTest2: < 90 deg or < 1/2*PI" << endl;
	Vector2 vec1(1.0f, 2.0f);
	Vector2 vec2(3.0f, 1.0f);
	float dotRes = vec1.Dot(vec2);
	float angle = vec1.AngleBetweenVectors(vec2);
	cout << "vec1: " << vec1 << endl << "vec2: " << vec2 << endl << "dot result: " << dotRes << endl << "angle: " << angle << endl << endl;
}

void DotProductTest3()
{
	cout << "DotProductTest3: AIE Slides Example " << endl;	 
	Vector2 vec1(5.0f, 2.0f);
	Vector2 vec2(-10.f, 4.0f);
	float dotRes = vec1.Dot(vec2);
	float angle = vec1.AngleBetweenVectors(vec2);
	cout << "vec1: " << vec1 << endl << "vec2: " << vec2 << endl << "dot result: " << dotRes << endl << "angle: " << angle << endl << endl;
}

void DotProductTest4()
{
	cout << "DotProductTest4 - 180 deg angle" << endl;
	//180 deg angle
	Vector2 vec1(-10.f, 0.f);
	Vector2 vec2(3.f, 0.f);
	float dotRes = vec1.Dot(vec2);
	float angle = vec1.AngleBetweenVectors(vec2);
	cout << "vec1: " << vec1 << endl << "vec2: " << vec2 << endl << "dot result: " << dotRes << endl << "angle: " << angle << endl << endl;
}

void DotProductTest5()
{
	cout << "DotProductTest5 - 180 deg angle (backwards)" << endl;
	//180 deg angle
	Vector2 vec2(-10.f, 0.f);
	Vector2 vec1(3.f, 0.f);
	float dotRes = vec1.Dot(vec2);
	float angle = vec1.AngleBetweenVectors(vec2);
	cout << "vec1: " << vec1 << endl << "vec2: " << vec2 << endl << "dot result: " << dotRes << endl << "angle: " << angle << endl << endl;
}

void RunVectorAngleTests()
{
	DotProductTest1();
	DotProductTest2();
	DotProductTest3();
	DotProductTest4();
	DotProductTest5();

	system("pause");
}