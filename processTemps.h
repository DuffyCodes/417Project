#ifndef PROCESSTEMPS_H_INCLUDED
#define PROCESSTEMPS_H_INCLUDED

#include <map>
#include <vector>
#include "parseTemps.h"

std::map<int, std::vector<float>> convertToMap(std::vector<CoreTempReading> readings);
double calcSlope(std::map<int, std::vector<float>> m, int key);
double calcIntercept(std::map<int, std::vector<float>> m, double slope, int key);

#endif // PROCESSTEMPS_H_INCLUDED
