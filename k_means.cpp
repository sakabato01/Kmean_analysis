#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <random>
#include <time.h>
#include"k_means.h"

using namespace std;
#ifndef TRUE
#define TRUE 1
#endif 
#ifndef FALSE
#define FALSE 0
#endif 

Kmeans::Kmeans() {
	for (int i = 0; i < ARRAYSIZE; i++) {
		point_x_[i] = 0;
		point_y_[i] = 0;
		group_kmeans[i] = -1;
		flag_visted_[i] = FALSE;
	}
	for (int i = 0; i < NUMGROUP; i++) {
		center_x_[i] = 0;
		center_y_[i] = 0;
		group_center_x[i] = 0;
		group_center_y[i] = 0;
		num_group_center_x[i] = 0;
		num_group_center_y[i] = 0;
	}
}
Kmeans::~Kmeans() {

}
void Kmeans::set_parameter_(int input_num_group, double input_theda) {
	num_group_ = input_num_group;
	threshold_theda_ = input_theda;
}

void Kmeans::set_point_x(int index, double input_xvalue) {
	point_x_[index] = input_xvalue;
}

void Kmeans::set_point_y(int index, double input_yvalue) {
	point_y_[index] = input_yvalue;
}

void Kmeans::set_center_x_(int index, double input_xvalue) {
	center_x_[index] = input_xvalue;
}

void Kmeans::set_center_y_(int index, double input_yvalue) {
	center_y_[index] = input_yvalue;
}

double Kmeans::get_point_x(int index) {
	return point_x_[index];
}

double Kmeans::get_point_y(int index) {
	return point_y_[index];
}

double Kmeans::CalculateDistance_(double A_point_x, double A_point_y, double B_point_x, double B_point_y) {
	return sqrt(pow(fabs(A_point_x - B_point_x), 2) + pow(fabs(A_point_y - B_point_y), 2));
}

int Kmeans::ClassifyPoint_(int point_index) {
	double distance_min = CalculateDistance_(point_x_[point_index], point_y_[point_index], center_x_[0], center_y_[0]);
	int center_index = 0;
	for (int i = 1; i < num_group_; i++) {
		double distance_temp = CalculateDistance_(point_x_[point_index], point_y_[point_index], center_x_[i], center_y_[i]);
		if (distance_temp <= distance_min) {
			distance_min = distance_temp;
			center_index = i;
		}
	}
	return center_index;
}

int Kmeans::SelectCenter_() {
	
	int point_index = (int)(rand() * 314159 % ARRAYSIZE);
	while (point_index < 0) {
		point_index = (int)(rand() * 314159 % ARRAYSIZE);
	}
	return point_index;
}

void Kmeans::SelectCenterLoop_() {
	srand(time(NULL));
	for (int i = 0; i < num_group_;) {
		int index_center = SelectCenter_();
		if (flag_visted_[index_center] == FALSE) {
			cout << "index_center=" << index_center << endl;
			flag_visted_[index_center] = TRUE;
			group_kmeans[index_center] = i;
			center_x_[i] = point_x_[index_center];
			center_y_[i] = point_y_[index_center];
			i++;
		}
	}
}

void Kmeans::KmeansAlgorithm() {
	//Initial parameters
	set_parameter_(NUMGROUP, THEDA);
	int num_points = ARRAYSIZE - num_group_;
	//Randomly choose points as centers
	SelectCenterLoop_();
	for (int i = 0; i < num_points;) {
	//Randomly choose a point which has not been visited
		int point_index_ = (int)(rand() * 314159 % ARRAYSIZE);
		while (point_index_ < 0) {
			point_index_ = (int)(rand() * 314159 % ARRAYSIZE);
		}
		
		int group_point = 0;
		if (flag_visted_[point_index_] == FALSE) {
			flag_visted_[point_index_] = TRUE;
			//Classify this point as the same group as the center point which is nearest
			group_point = ClassifyPoint_(point_index_);
			group_kmeans[point_index_] = group_point;
			//Update center point`s (x, y)
			center_x_[group_point] = (center_x_[group_point] + point_x_[point_index_]) / 2;
			center_y_[group_point] = (center_y_[group_point] + point_y_[point_index_]) / 2;
			i++;
		}
	}
	//recursivly choose another point until all the points are visited
}

void Kmeans::set_group_center_x(int index) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		if (group_kmeans[i] == index) {
			group_center_x[group_kmeans[i]] += point_x_[i];
			num_group_center_x[group_kmeans[i]]++;
		}
	}
}
void Kmeans::set_group_center_y(int index) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		if (group_kmeans[i] == index) {
			group_center_y[group_kmeans[i]] += point_y_[i];
			num_group_center_y[group_kmeans[i]]++;
		}
	}
}

double Kmeans::get_group_center_x(int index) {
	return group_center_x[index] / num_group_center_x[index];
}

double Kmeans::get_group_center_y(int index) {
	return group_center_y[index] / num_group_center_y[index];
}