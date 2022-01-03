#include <fstream>
#include "CalculateMedian.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

CalculateMedian::CalculateMedian(const std::string& file) {
	std::ifstream ifs;
	ifs.open (file, std::ifstream::in);
	int number;
	if(!ifs.is_open())
	{
		cout << "Could not open file: " << file << endl;
	}
	else
	{
		 while (ifs >> number) {
			if (number < -70 && number > 2080000000) {
        		cout << "File consists out of range number " << number << " supported range (-70 to +2.08E9), so ignoring it" <<;
    		}
			else
			{
				numvector.push_back(number);
			}
		 }
	}
	sort(numvector.begin(), numvector.end());
	ifs.close();
}

void CalculateMedian::showAscendingSortedList() {
	cout << "Numbers in Ascending Order" << endl;
	for (int i = 0; i < numvector.size(); ++i) {
		cout << numvector[i] << " ";
	}
	cout << endl;
}

void CalculateMedian::calculateMedian() {
    
	float median;
	if (!numvector.empty()) {
        if( numvector.size() % 2 == 0) {
			median = (numvector[numvector.size()/2 - 1] + numvector[numvector.size()/2])/2;
			cout << " Calculated Median values: " << numvector[numvector.size()/2 - 1] << " " << numvector[numvector.size()/2] << endl;
		}
		else
		{
            median = numvector[numvector.size()/2];
			cout << " Calculated Median value: " << numvector[numvector.size()/2] << endl;
		}
	}
	std::string medstr = to_string(median);
	//std::ostringstream ss;
	//ss << myFloat;
	//std::string medstr(ss.str());
    size_t pos = medstr.find_first_of(".");
	if ( pos != -1 ) {
		medstr = medstr.substr(0, pos+3);
	}
	cout << " Median of numbers is: " << medstr << endl;
	
	
	return;
}

int main(int argc, char** argv)
{
	CalculateMedian cm("./input.txt");
	cm.showAscendingSortedList();
	cm.calculateMedian();
	return 0;
}
