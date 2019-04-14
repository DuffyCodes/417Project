#include <map>
#include <vector>
#include <iterator>
#include "parseTemps.h"

using namespace std;

map<int, vector<int>> convertToMap(vector<CoreTempReading> readings){

    map<int, vector<int>> easierReadings;
    vector<int> first, second, third, fourth;

    for(auto it = readings.begin(); it != readings.end(); it++){
        first.push_back(it->second[0]);
        second.push_back(it->second[1]);
        third.push_back(it->second[2]);
        fourth.push_back(it->second[3]);
    }
    easierReadings.insert(pair<int, vector<int>>(1, first));
    easierReadings.insert(pair<int, vector<int>>(2, second));
    easierReadings.insert(pair<int, vector<int>>(3, third));
    easierReadings.insert(pair<int, vector<int>>(4, fourth));

    return easierReadings;
}
