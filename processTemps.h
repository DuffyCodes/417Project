#ifndef PROCESSTEMPS_H_INCLUDED
#define PROCESSTEMPS_H_INCLUDED

#include <map>
#include <vector>
#include "parseTemps.h"


// y = y0 + (y1 - y0)/(x1 - x0) * x - (y1 - y0)/(x1 - x0) * x0
class Function{
private:
	float y0;
	float y1;
	float x1;
	float x0;
	float m;

public:
	float getM() const {
		return m;
	}

	float getX0() const {
		return x0;
	}

	void setX0(float x0) {
		this->x0 = x0;
	}

	float getX1() const {
		return x1;
	}

	void setX1(float x1) {
		this->x1 = x1;
	}

	float getY0() const {
		return y0;
	}

	void setY0(float y0) {
		this->y0 = y0;
	}

	float getY1() const {
		return y1;
	}

	void setY1(float y1) {
		this->y1 = y1;
	}

	float calcM(float y0, float y1, float x0, float x1);
};

std::map<int, std::vector<float>> convertToMap(std::vector<CoreTempReading> readings);



#endif // PROCESSTEMPS_H_INCLUDED
