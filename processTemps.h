#ifndef PROCESSTEMPS_H_INCLUDED
#define PROCESSTEMPS_H_INCLUDED

#include <map>
#include <vector>
#include "parseTemps.h"

std::map<int, std::vector<int>> convertToMap(std::vector<CoreTempReading> readings);



#endif // PROCESSTEMPS_H_INCLUDED
