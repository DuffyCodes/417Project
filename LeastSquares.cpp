/*
 * LeastSquares.cpp
 *
 *  Created on: Apr 17, 2019
 *      Author: mduffy
 */

#include "LeastSquares.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * <pre>
 * <b>LeastSquares</b>
 * This pseudo-class will parse and create the LeastSquares Approximations
 * </pre>
 */

/**
 * This constructor creates the LeastSquares calculations
 * @param m <b>Map of readings</b>
 * @param s <b>Files to be parsed</b>
 */
LeastSquares::LeastSquares(map<int, vector<float>> m, string s) {

	for(int core = 0; core < 4; core++){
		int numEntries = m.find(core)->second.size();
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 3; j++){
				matrix[i][j]=0;
			}
		}

		int pi0pi0 = numEntries;
		double pi0pi1 = 0;
		double pi0f = 0;
		double pi1pi1 = 0;
		double pi1f = 0;
		for(int xVals = 0; xVals < numEntries; xVals++){
			pi0pi1 += xVals * 30;
			pi0f += m.find(core)->second[xVals];
			pi1pi1 += (xVals * 30) * (xVals * 30);
			pi1f += (m.find(core)->second[xVals]) * (xVals * 30);
		}
		matrix [0][0] = pi0pi0;
		matrix[0][1] = pi0pi1;
		matrix [0][2] = pi0f;
		matrix [1][0] = pi0pi1;
		matrix [1][1] = pi1pi1;
		matrix [1][2] = pi1f;
		/*
		 * debugging output
		 */
//		cerr<<"Pre: \n";
//		for(int i = 0; i < 2; i++){
//			for(int j = 0; j < 3; j++){
//				cerr << matrix[i][j]<<"  ";
//			}
//			cerr<<std::endl;
//		}

		for(int i = 0; i < 2; i++){
			reduce(matrix, i);
			eliminate(matrix, i);
		}
		c0 = matrix[0][2];
		c1 = matrix[1][2];

		printOutput(c0, c1, s, numEntries, core);
//		cerr<<endl<<endl<<"After: \n";
//		for(int i = 0; i < 2; i++){
//			for(int j = 0; j < 3; j++){
//				cerr << matrix[i][j]<<"  ";
//			}
//			cerr<<std::endl;
//		}
//		cerr<<endl<<endl;
	}


}
/**
 * Matrix reduction function
 * @param m <b>Matrix to be reduced</b>
 * @param i <b>Column index</b>
 */
void LeastSquares::reduce(double m[2][3], int i){
//	cerr<<"before reduce "<<i<<endl;
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j < 3; j++){
//			cerr << m[i][j]<<"  ";
//		}
//		cerr<<endl;
//	}

	double factor = m[i][i];
	//cout << "factor: "<<factor<<endl;
	for(int index = i; index < 3; index++){
		float temp = m[i][index];
		//cout<< "temp: "<<temp<<endl;
		m[i][index] = temp / factor;
	}
//	cerr<<"after reduce "<<i<<endl;
//	for(int i = 0; i < 2; i++){
//			for(int j = 0; j < 3; j++){
//				cerr << m[i][j]<<"  ";
//			}
//			cerr << endl;
//		}
}

/**
 * Matrix elimination
 * @param m <b>Matrix to be altered</b>
 * @param i <b>Index of the entry to eliminate based on</b>
 */
void LeastSquares::eliminate(double m[2][3], int i){
//	cerr<< "before eliminate "<<i<<endl;
//	for(int i = 0; i < 2; i++){
//			for(int j = 0; j < 3; j++){
//				cerr << m[i][j]<<"  ";
//			}
//			cerr << :endl;
//		}
	if(i == 0){
		double factor = m[1][0];
		for(int index = 0; index < 3; index++){
			double temp = m[1][index];
			m[1][index] = temp - (factor * m[0][index]);
		}
	}
	if (i ==1){
		double factor = m[0][1];
		for(int index = 1; index < 3; index++){
			double temp = m[0][index];
			m[0][index] = temp - (factor * m[1][index]);
		}
	}
//	cerr<< "after eliminate "<<i<<endl;
//		for(int i = 0; i < 2; i++){
//				for(int j = 0; j < 3; j++){
//					cerr << m[i][j]<<"  ";
//				}
//				cerr << endl;
//			}
}

/**
 * Function to print output to a file
 * @param c0 <b>c0</b>
 * @param c1 <b>c1</b>
 * @param s <b>File being parsed</b>
 * @param numEntries <b>How many readings being parsed</b>
 * @param core <b>The core being parsed</b>
 */
void LeastSquares::printOutput(float c0, float c1, string s, int numEntries, int core){
	fstream out;
	ostringstream os;
	os << "core_" << core << ".txt";
	string fileName = os.str();
	out.open(fileName, fstream::in | fstream::out | fstream::app);
	out << "***********************************************************************\n";
	out << s;
	out << "\n***********************************************************************\n";
	out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	out << "LEAST SQUARES APPROXIMATION\n";
	out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	out << "0 < x < "<<numEntries*30<<"; y= "<<c0;
	if(c1 >= 0)
		out << " + "<<c1<<"x; Least Squares Approximation\n";
	else
		out << " - "<<abs(c1)<<"x; Least Squares Approximation\n";
	out.close();
}
