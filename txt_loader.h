#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define ARRAYSIZE 1656
class Txtloader3D {
public:
	Txtloader3D();
	~Txtloader3D();

	void SetArray();
	void PrintArrayOfX();
	double get_point_array_x(int index);

	void PrintArrayOfY();
	double get_point_array_y(int index);
private:
	ifstream OpenFile_(char *file_name);
	double point_array_x_[ARRAYSIZE];
	void set_point_array_x_(int index, double input_xvalue);
	double point_array_y_[ARRAYSIZE];
	void set_point_array_y_(int index, double input_xvalue);
};