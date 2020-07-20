#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
#define ARRAYSIZE 1656
#define NUMGROUP 5
#define THEDA 3.1415
class Kmeans {
public:
	Kmeans();
	~Kmeans();
	void set_parameter_(int input_num_group, double input_theda);
	void set_point_x(int index, double input_xvalue);
	void set_point_y(int index, double input_xvalue);
	double get_point_x(int index);
	double get_point_y(int index);
	void KmeansAlgorithm();
	double CalculateDistance_(double A_point_x, double A_point_y, double B_point_x, double B_point_y);
	int ClassifyPoint_(int point_index);
	int SelectCenter_();
	void SelectCenterLoop_();
	void set_center_x_(int index, double input_xvalue);
	void set_center_y_(int index, double input_xvalue);
	double get_group_center_x(int index);
	double get_group_center_y(int index);
	void set_group_center_x(int index);
	void set_group_center_y(int index);
private:
	int num_group_;
	double threshold_theda_;
	double point_x_[ARRAYSIZE];
	double point_y_[ARRAYSIZE];
	int group_kmeans[ARRAYSIZE];
	bool flag_visted_[ARRAYSIZE];
	double center_x_[NUMGROUP];
	double center_y_[NUMGROUP];
	double group_center_x[NUMGROUP];
	double group_center_y[NUMGROUP];
	double num_group_center_x[NUMGROUP];
	double num_group_center_y[NUMGROUP];
};