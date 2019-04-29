#include "parseTemps.h"
#include "LeastSquares.h"
#include "LinearInterpolation.h"
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

    for(int i = 1; i < argc; i++){
    	ifstream input_temps(argv[i]);
    	if (!input_temps) {
    		cout << "ERROR: " << argv[i] << " could not be opened" << "\n";
    	    return 2;
    	}
    	// End Input Validation
        vector<CoreTempReading> readings = parse_raw_temps(input_temps);

        // Convert the readings to a map (easier for me to manipulate)
        map<int, vector<float>> easierReadings = convertToMap(readings);

        LeastSquares least(easierReadings, argv[i]);
        LinearInterpolation linInterp(easierReadings);
    }
    return 0;
}
