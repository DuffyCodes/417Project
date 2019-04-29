/*
 * LinearInterpolation.h
 *
 *  Created on: Apr 24, 2019
 *      Author: mduffy
 */

#ifndef LINEARINTERPOLATION_H_
#define LINEARINTERPOLATION_H_
#include <vector>
#include <map>

class LinearInterpolation{
public:
	LinearInterpolation(const std::map<int, std::vector<float>> m);

	float calcSlope(const std::map<int, std::vector<float>> m, int x, int core);
	float calcIntercept(std::map<int, std::vector<float>> m, float slope, int x, int core);

private:
	float slope;
	float intercept;
};



#endif /* LINEARINTERPOLATION_H_ */
