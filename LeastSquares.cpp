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

LeastSquares::LeastSquares(map<int, vector<float>> m) {

	for(int core = 0; core < 4; core++){
		int numEntries = m.find(core+1)->second.size();
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 3; j++){
				matrix[i][j]=0;
			}
		}
		//std::cout<<interval<<std::endl;
		int pi0pi0 = numEntries;
		double pi0pi1 = 0;
		double pi0f = 0;
		double pi1pi1 = 0;
		double pi1f = 0;
		for(int xVals = 0; xVals < numEntries; xVals++){
			pi0pi1 += xVals * 30;
			pi0f += m.find(core+1)->second[xVals];
			pi1pi1 += (xVals * 30) * (xVals * 30);
			pi1f += (m.find(core+1)->second[xVals]) * (xVals * 30);
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
//		fstream out;
//		ostringstream os;
//		os << "core_" << core << ".txt";
//		string fileName = os.str();
//		out.open(fileName, fstream::in | fstream::out | fstream::app);
//		out << "0 < x < "<<numEntries*30<<"; y= "<<c0<<" + "<<c1<<"x; Least Squares Approximation\n";
//		out.close();
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
