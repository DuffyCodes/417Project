#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <utility>
#include <map>

#include "parseTemps.h"

//------------------------------------------------------------------------------
std::vector<CoreTempReading> parse_raw_temps(std::istream& original_temps,
                                             int step_size)
{
    std::vector<CoreTempReading> allTheReadings;

    // Input Parsing Variables
    int step = 0;
    std::string line;

    while (getline(original_temps, line)) {
        std::istringstream input(line);

        std::vector<double> next_temperature_set;
        std::transform(std::istream_iterator<std::string>(input),
                       std::istream_iterator<std::string>(),
                       std::back_inserter(next_temperature_set),
                       [](const std::string& raw_reading) -> double {
                           return stod(raw_reading);
                       });

        allTheReadings.emplace_back(step, next_temperature_set);
        step += step_size;
    }

    return allTheReadings;
}
std::map<int, std::vector<float>> convertToMap(std::vector<CoreTempReading> readings){

    std::map<int, std::vector<float>> easierReadings;
    std::vector<float> first, second, third, fourth;

    for(auto it = readings.begin(); it != readings.end(); it++){
        first.push_back(it->second[0]);
        second.push_back(it->second[1]);
        third.push_back(it->second[2]);
        fourth.push_back(it->second[3]);
    }
    easierReadings.insert(std::pair<int, std::vector<float>>(1, first));
    easierReadings.insert(std::pair<int, std::vector<float>>(2, second));
    easierReadings.insert(std::pair<int, std::vector<float>>(3, third));
    easierReadings.insert(std::pair<int, std::vector<float>>(4, fourth));

    return easierReadings;
}
