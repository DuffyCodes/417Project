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
 * b = y0 - mx0
 */

float calcSlope(map<int,vector<float>> m, int key){
	auto it = m.begin();
	float yChange = m.find(key)->second[it->second.size()-1] - m.find(key)->second[0];
	float xChange = (it->second.size()-1);
	cout <<"slope: "<<yChange<<"/"<<xChange<<" = "<< yChange/xChange<<endl;
	return 0;
}

float calcIntercept(map<int, vector<float>>m, float slope, int key){
	float mx0 = slope * 30;
	return m.find(key)->second[0] - mx0;
}
