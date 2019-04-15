#include "parseTemps.h"
#include "processTemps.h"
#include <iostream>
#include <fstream>
#include <vector>
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
    //auto it = easierReadings.begin();

    for(int i = 0; i < easierReadings.size(); i++){
    	double slope = calcSlope(easierReadings, i+1);
    	double intercept = calcIntercept(easierReadings, slope, i+1);
    	ofstream core;
    	char c = '0'+i;
    	string coreNum = "core ";
    	coreNum+=c;
    	coreNum.append(".txt");
    	core.open(coreNum);
    	core << slope<<"x + "<<intercept<<endl;
    	core.close();
    	cout<<"core "<<i<<" finished. See .txt file"<<endl;
    }

    //cout << "line: "<<slope<<"x + "<<intercept<<endl;
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
