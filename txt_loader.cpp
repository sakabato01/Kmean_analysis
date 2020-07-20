#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "txt_loader.h"

using namespace std;
Txtloader3D::Txtloader3D(){
	for (int i = 0; i < ARRAYSIZE; i++) {
		point_array_x_[i] = 0;
		point_array_y_[i] = 0;
	}
}
Txtloader3D::~Txtloader3D(){

}

ifstream Txtloader3D::OpenFile_(char *file_name) {
	ifstream ptr_file;
	ptr_file.open(file_name);
	if (ptr_file.is_open()) {
		cout << "Open Successed!!" << endl;
		return ptr_file;
	}
	else {
		cout << "Open Failed!!" << endl;
		return ptr_file;
	}
}

void Txtloader3D::SetArray() {
	ifstream ptr_file_x = OpenFile_("decay_xyz_x.txt");
	ifstream ptr_file_y = OpenFile_("decay_xyz_y.txt");
	for (int i = 0; i < ARRAYSIZE; i++) {
		double temp_x=0;
		double temp_y = 0;
		ptr_file_x >> temp_x;
		ptr_file_y >> temp_y;
		set_point_array_x_(i, temp_x);
		set_point_array_y_(i, temp_y);
	}
	ptr_file_x.close();
	ptr_file_y.close();
}

void Txtloader3D::set_point_array_x_(int index, double input_xvalue) {
	point_array_x_[index] = input_xvalue;
}

void Txtloader3D::PrintArrayOfX() {
	for (int i = 0; i < ARRAYSIZE; i++) {
		cout << point_array_x_[i] << endl;
	}
}

double Txtloader3D::get_point_array_x(int index) {
	if (index > ARRAYSIZE) {
		cout << "Out of range!" << endl;
		return 0;
	}
	else {
		return point_array_x_[index];
	}
}

void Txtloader3D::set_point_array_y_(int index, double input_yvalue) {
	point_array_y_[index] = input_yvalue;
}

void Txtloader3D::PrintArrayOfY() {
	for (int i = 0; i < ARRAYSIZE; i++) {
		cout << point_array_y_[i] << endl;
	}
}

double Txtloader3D::get_point_array_y(int index) {
	if (index > ARRAYSIZE) {
		cout << "Out of range!" << endl;
		return 0;
	}
	else {
		return point_array_y_[index];
	}
}
