#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "k_means.h"
#include "txt_loader.h"
using namespace std;

int main() {

	cout << "HelloWorld;" << endl;
	Txtloader3D txtloader;
	Kmeans kmeans;

	txtloader.SetArray();

	for (int i = 0; i < ARRAYSIZE; i++) {
		kmeans.set_point_x(i, txtloader.get_point_array_x(i));
		kmeans.set_point_y(i, txtloader.get_point_array_y(i));
	}
	kmeans.KmeansAlgorithm();

	for (int i = 0; i < NUMGROUP; i++)
	{
		kmeans.set_group_center_x(i);
		kmeans.set_group_center_y(i);
	}

	for (int i = 0; i < NUMGROUP; i++) {
		cout << "group_center_x[" << i << "]: " << kmeans.get_group_center_x(i) << " " 
			 << "group_center_y[" << i << "]: " << kmeans.get_group_center_y(i) <<endl;
	}
	system("pause");
	return 0;
}