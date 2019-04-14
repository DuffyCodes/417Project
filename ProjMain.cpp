#include "parseTemps.h"
#include "processTemps.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

//------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    // Input validation
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file_name" << "\n";
        return 1;
    }

    ifstream input_temps(argv[1]);
    if (!input_temps) {
        cout << "ERROR: " << argv[1] << " could not be opened" << "\n";
        return 2;
    }
    // End Input Validation

    vector<CoreTempReading> readings = parse_raw_temps(input_temps);
    // Convert the readings to a map (easier for me to manipulate)
    map<int, vector<float>> easierReadings = convertToMap(readings);

    float slope = calcSlope(easierReadings, 1);
    float intercept = calcIntercept(easierReadings, slope, 1);
    cout << "intercept: "<<intercept<<endl;
    /*
    *
    *debugging stuffs
    *
    for(auto it = easierReadings.begin(); it != easierReadings.end(); it++){
        cout<<endl<<it->first<<endl;
        for(int i = 0; i < it->second.size(); i++){
            cout<<it->second[i]<<", ";
        }

    }
    */

    return 0;
}
