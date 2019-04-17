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

	std::vector<int> gauss(std::vector<std::vector<long long> > m);
	void reduce(long long m[2][3], int i);
};

#endif /* LEASTSQUARES_H_ */
