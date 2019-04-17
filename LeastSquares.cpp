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

using namespace std;

LeastSquares::LeastSquares(map<int, vector<float>> m) {
	long long matrix[2][3];
	for(int core = 0; core < 4; core++){
		int numEntries = m.find(core+1)->second.size();
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 3; j++){
				matrix[i][j]=0;
			}
		}
		matrix[0][0] = numEntries;
		int interval = numEntries / 20;
		//std::cout<<interval<<std::endl;
		long long pi0pi0 = numEntries;
		long long pi0pi1 = 0;
		long long pi0f = 0;
		long long pi1pi1 = 0;
		long long pi1f = 0;
		for(int xVals = 0; xVals < numEntries; xVals++){
			pi0pi1 += xVals * 30;
			pi0f += m.find(core+1)->second[xVals];
			pi1pi1 += (m.find(core+1)->second[xVals]) * (m.find(core+1)->second[xVals]);
			pi1f += (m.find(core+1)->second[xVals]) * (xVals * 30);
			//std::cout<<".";
		}
		matrix [0][0] = pi0pi0;
		matrix[0][1] = pi0pi1;
		matrix [0][2] = pi0f;
		matrix [1][0] = pi0pi1;
		matrix [1][1] = pi1pi1;
		matrix [1][2] = pi1f;

		for(int i = 0; i < 2; i++){
			reduce(matrix, i);
		}

		vector<int> solution(2);
		//solution = gauss(matrix);
		cout<<solution[0]<<" "<<solution[1]<<"x"<<endl;
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			std::cout << matrix[i][j]<<"  ";
		}
		std::cout<<std::endl;


	}

}

void LeastSquares::reduce(long long m[2][3], int i){

}

vector<int> LeastSquares::gauss(vector<vector <long long> > m){
	int n = m.size();
    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(m[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(m[k][i]) > maxEl) {
                maxEl = abs(m[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = m[maxRow][k];
            m[maxRow][k] = m[i][k];
            m[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<2; k++) {
            double c = -m[k][i]/m[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    m[k][j] = 0;
                } else {
                    m[k][j] += c * m[i][j];
                }
            }
        }
    }
	    // Solve equation Ax=b for an upper triangular matrix A
    vector<int> x(n);
    for (int i=1; i>=0; i--) {
        x[i] = m[i][n]/m[i][i];
        for (int k=i-1;k>=0; k--) {
            m[k][n] -= m[k][i] * x[i];
        }
    }

    return x;
}

