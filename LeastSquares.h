/*
 * LeastSquares.h
 *
 *  Created on: Apr 17, 2019
 *      Author: mduffy
 */

#ifndef LEASTSQUARES_H_
#define LEASTSQUARES_H_
#include <vector>
#include <map>


class LeastSquares {
public:
	LeastSquares(std::map<int, std::vector<float>> m);

	void reduce(double m[2][3], int i);
	void eliminate(double m[2][3], int i);

	double getC0() const {
		return c0;
	}

	double getC1() const {
		return c1;
	}

private:
	double matrix[2][3];
	double c0 = matrix[0][2];
	double c1 = matrix[1][2];
};

#endif /* LEASTSQUARES_H_ */
