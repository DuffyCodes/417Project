/*
 * LinearInterpolation.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: mduffy
 */

#include "LinearInterpolation.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * Constructor to find Linear Interpolation between all points read in
 * @param m <b>The points to be parsed</b>
 */
LinearInterpolation::LinearInterpolation(map<int, vector<float>> m){

	for(int core = 0; core < 4; core++){
		fstream out;
		ostringstream os;
		os << "core_" << core << ".txt";
		string fileName = os.str();
		out.open(fileName, fstream::in | fstream::out | fstream::app);
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		out << "LINEAR INTERPOLATION\n";
		out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		int end = m.find(core)->second.size() - 1;
		for(int i = 0; i < end; i++){
			float slope = calcSlope(m, i, core);
			float b = calcIntercept(m, slope, i, core);
			out << i * 30 <<" < x < " << (i+1) * 30 << "; y = " << b;
			if(slope >= 0)
				out << " + " << slope <<"x; Linear Interpolation\n";
			else
				out << " - " << abs(slope) <<"x; Linear Interpolation\n";
		}
		out<<"\n\n";
		out.close();
	}
}

/**
 * Function to calculate the slope between two points (m in y=mx+b)
 * @param m <b>The container of all the readings</b>
 * @param x <b>The x value index</b>
 * @param core <b>The core being parsed</b>
 * @return float <b>The slope</b>
 */
float LinearInterpolation::calcSlope(const map<int, vector<float>> m, int x, int core){
	//auto it = m.begin();
	float yChange = m.find(core)->second[x+1] - m.find(core)->second[x];
	float xChange = ((x+1) * 30) - (x * 30);
//	cerr << "x0: "<< x * 30 << " x1: "<< (x+1) * 30 << " y0: " << m.find(core)->second[x] << " y1 "<<  m.find(core)->second[x+1] << "\n";
//	cerr<<"slope: "<<yChange/xChange<<endl;
	return yChange / xChange;
}


/**
 * Function to calculate the y-intercept (b in y=mx+b).
 * @param m <b>The container of all the readings</b>
 * @param slope <b>The slope of the line</b>
 * @param x <b>The x value index</b>
 * @param core <b>The core being parsed</b>
 * @return float <b>The y-Intercept</b>
 */
float LinearInterpolation::calcIntercept(map<int, vector<float>>m, float slope, int x, int core){
//	cerr<< "y0: "<<m.find(core)->second[x]<<" slope: "<<slope<<" x0: "<<x*30<<endl;
//	cerr<<"b: "<<m.find(core)->second[x] - (slope * x * 30)<<endl;
	return m.find(core)->second[x] - (slope * x * 30);
}
