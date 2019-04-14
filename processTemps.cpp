#include <map>
#include <vector>
#include <iterator>
#include "parseTemps.h"
#include "processTemps.h"

using namespace std;

map<int, vector<float>> convertToMap(vector<CoreTempReading> readings){

    map<int, vector<float>> easierReadings;
    vector<float> first, second, third, fourth;

    for(auto it = readings.begin(); it != readings.end(); it++){
        first.push_back(it->second[0]);
        second.push_back(it->second[1]);
        third.push_back(it->second[2]);
        fourth.push_back(it->second[3]);
    }
    easierReadings.insert(pair<int, vector<float>>(1, first));
    easierReadings.insert(pair<int, vector<float>>(2, second));
    easierReadings.insert(pair<int, vector<float>>(3, third));
    easierReadings.insert(pair<int, vector<float>>(4, fourth));

    return easierReadings;
}

/*
 * Turn the data into a function.
 * y = y0 + (y1 - y0)/(x1 - x0) * x - (y1 - y0)/(x1 - x0) * x0
 */



float Function::calcM(float y0, float y1, float x0, float x1){
	return (y1 - y0)/(x1 - x0);
}
