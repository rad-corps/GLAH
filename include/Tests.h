#pragma once

#include "Matrix.h"
#include <iostream>

using namespace std;

//Test a vector position multiplied by a translate vector
int TestMatrix()
{
	Matrix4x4 matrix;

	matrix.matrix[0][0] = 1;
	matrix.matrix[0][1] = 0;
	matrix.matrix[0][2] = 0;
	matrix.matrix[0][3] = 0;

	matrix.matrix[1][0] = 0;
	matrix.matrix[1][1] = 1;
	matrix.matrix[1][2] = 0;
	matrix.matrix[1][3] = 0;

	matrix.matrix[2][0] = 0;
	matrix.matrix[2][1] = 0;
	matrix.matrix[2][2] = 1;
	matrix.matrix[2][3] = 0;

	matrix.matrix[3][0] = 2;
	matrix.matrix[3][1] = 3;
	matrix.matrix[3][2] = 0;
	matrix.matrix[3][3] = 1;

	Vector4 vec(2.f, 4.f, 0.f, 1.f);

	Vector4 translatedVec = matrix * vec;

	cout << "TESTMATRIX\n-------------------" << endl;
	cout << vec.ToString() << endl;
	cout << matrix.ToString() << endl;
	cout << translatedVec.ToString() << endl;
	return 0;
}

int TestMatrix2()
{
	Matrix4x4 matrixTrans;
	Matrix4x4 matrixScale;

	matrixTrans.matrix[0][0] = 1;
	matrixTrans.matrix[0][1] = 0;
	matrixTrans.matrix[0][2] = 0;
	matrixTrans.matrix[0][3] = 0;

	matrixTrans.matrix[1][0] = 0;
	matrixTrans.matrix[1][1] = 1;
	matrixTrans.matrix[1][2] = 0;
	matrixTrans.matrix[1][3] = 0;

	matrixTrans.matrix[2][0] = 0;
	matrixTrans.matrix[2][1] = 0;
	matrixTrans.matrix[2][2] = 1;
	matrixTrans.matrix[2][3] = 0;

	matrixTrans.matrix[3][0] = 3;
	matrixTrans.matrix[3][1] = 2;
	matrixTrans.matrix[3][2] = 0;
	matrixTrans.matrix[3][3] = 1;

	
	matrixScale.matrix[0][0] = 2;
	matrixScale.matrix[0][1] = 0;
	matrixScale.matrix[0][2] = 0;
	matrixScale.matrix[0][3] = 0;

	matrixScale.matrix[1][0] = 0;
	matrixScale.matrix[1][1] = 2;
	matrixScale.matrix[1][2] = 0;
	matrixScale.matrix[1][3] = 0;

	matrixScale.matrix[2][0] = 0;
	matrixScale.matrix[2][1] = 0;
	matrixScale.matrix[2][2] = 2;
	matrixScale.matrix[2][3] = 0;

	matrixScale.matrix[3][0] = 0;
	matrixScale.matrix[3][1] = 0;
	matrixScale.matrix[3][2] = 0;
	matrixScale.matrix[3][3] = 1;

	Matrix4x4 result = matrixTrans * matrixScale;

	cout << "\n\nTESTMATRIX2\n-------------------" << endl;
	cout << "Translation Matrix" << endl;
	cout << matrixTrans.ToString() << endl;
	cout << "Scale Matrix Matrix" << endl;
	cout << matrixScale.ToString() << endl;	
	cout << "trans * scale" << endl;
	cout << result.ToString() << endl;
	
	return 0;
}

int TestMatrix3()
{
	Matrix4x4 matrixTrans;
	Matrix4x4 matrixScale;

	matrixTrans.matrix[0][0] = 3;
	matrixTrans.matrix[0][1] = 4;
	matrixTrans.matrix[0][2] = 7;
	matrixTrans.matrix[0][3] = 0;

	matrixTrans.matrix[1][0] = 4;
	matrixTrans.matrix[1][1] = 2;
	matrixTrans.matrix[1][2] = 2;
	matrixTrans.matrix[1][3] = 0;

	matrixTrans.matrix[2][0] = 2;
	matrixTrans.matrix[2][1] = 3;
	matrixTrans.matrix[2][2] = 4;
	matrixTrans.matrix[2][3] = 0;

	matrixTrans.matrix[3][0] = 0;
	matrixTrans.matrix[3][1] = 0;
	matrixTrans.matrix[3][2] = 0;
	matrixTrans.matrix[3][3] = 0;

	
	matrixScale.matrix[0][0] = 6;
	matrixScale.matrix[0][1] = 9;
	matrixScale.matrix[0][2] = 1;
	matrixScale.matrix[0][3] = 0;

	matrixScale.matrix[1][0] = 2;
	matrixScale.matrix[1][1] = 5;
	matrixScale.matrix[1][2] = 8;
	matrixScale.matrix[1][3] = 0;

	matrixScale.matrix[2][0] = 3;
	matrixScale.matrix[2][1] = 6;
	matrixScale.matrix[2][2] = 9;
	matrixScale.matrix[2][3] = 0;

	matrixScale.matrix[3][0] = 0;
	matrixScale.matrix[3][1] = 0;
	matrixScale.matrix[3][2] = 0;
	matrixScale.matrix[3][3] = 0;

	Matrix4x4 result = matrixTrans * matrixScale;

	cout << "\n\nTESTMATRIX3\n-------------------" << endl;
	cout << "Original Matrix 1" << endl;
	cout << matrixTrans.ToString() << endl;
	cout << "Original Matrix 2" << endl;
	cout << matrixScale.ToString() << endl;	
	cout << "Result" << endl;
	cout << result.ToString() << endl;
	
	return 0;
}

void RunTests()
{
	TestMatrix();
	TestMatrix2();
	TestMatrix3();
	system("pause");
}