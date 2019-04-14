#ifndef PROCESSTEMPS_H_INCLUDED
#define PROCESSTEMPS_H_INCLUDED

#include <map>
#include <vector>
#include "parseTemps.h"

std::map<int, std::vector<float>> convertToMap(std::vector<CoreTempReading> readings);
float calcSlope(std::map<int, std::vector<float>> m, int key);
float calcIntercept(std::map<int, std::vector<float>> m, float slope, int key);

#endif // PROCESSTEMPS_H_INCLUDED
