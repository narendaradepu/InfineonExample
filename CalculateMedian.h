#include <iostream>
#include <vector>

class CalculateMedian {
    public:
	   CalculateMedian(const std::string& filePath);
	   void calculateMedian();
       void showAscendingSortedList();
    private:
    std::vector<int> numvector;
};
