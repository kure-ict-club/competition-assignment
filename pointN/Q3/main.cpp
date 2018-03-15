#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

enum sortMethod{
	bubble,
	select
};

enum sortOrder {
	up,
	down
};

struct howToSort {
	sortOrder so;
	sortMethod sm;
};

enum textformat {
	sortStyle,
	emptyString,
	sortData
};

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

std::vector<int> split(const std::string& input, const char delimiter) {
	std::istringstream stream(input);

	std::string field;
	std::vector<int> result;
	while (std::getline(stream, field, delimiter)) {
		result.push_back(std::stoi(field));
	}
	return result;
}

howToSort makeCondition(std::string str) {
	howToSort hts;
	std::vector<int> result = split(str, ':');
	switch (result[0]) {
	case up:
		hts.so = up;
		break;
	case down:
	default:
		hts.so = down;
		break;
	}
	switch (result[1]) {
	case bubble:
		hts.sm = bubble;
		break;
	case select:
	default:
		hts.sm = select;
		break;
	}
	return hts;
}

std::vector<int>& bubbleSort(std::vector<int>& nums, const sortOrder so) {
	int iLoop, iComp;
	int numsSize = nums.size();
	switch (so) {
	case up:
		for (iLoop = 0; iLoop < numsSize - 1; iLoop++) {
			for (iComp = 0; iComp < numsSize - 1 - iLoop; iComp++) {
				if (nums[iComp] > nums[iComp + 1]) {
					swap(nums[iComp], nums[iComp + 1]);
				}
			}
		}
		break;
	case down:
	default:
		for (iLoop = 0; iLoop < numsSize - 1; iLoop++) {
			for (iComp = 0; iComp < numsSize - 1 - iLoop; iComp++) {
				if (nums[iComp] < nums[iComp + 1]) {
					swap(nums[iComp], nums[iComp + 1]);
				}
			}
		}
		break;
	}
	return nums;
}

std::vector<int>& selectSort(std::vector<int>& nums, const sortOrder so) {
	int iLoop, iSearch, iMin, iMax;
	int numsSize = nums.size();
	switch (so) {
	case up:
		for (iLoop = 0; iLoop < numsSize - 1; iLoop++) {
			iMin = iLoop;
			for (iSearch = iLoop + 1; iSearch < numsSize; iSearch++) {
				if (nums[iSearch] < nums[iMin]) {
					iMin = iSearch;
				}
			}
			swap(nums[iMin], nums[iLoop]);
		}
		break;
	case down:
	default:
		for (iLoop = 0; iLoop < numsSize - 1; iLoop++) {
			iMax = iLoop;
			for (iSearch = iLoop + 1; iSearch < numsSize; iSearch++) {
				if (nums[iSearch] > nums[iMax]) {
					iMax = iSearch;
				}
			}
			swap(nums[iMax], nums[iLoop]);
		}
		break;
	}
	return nums;
}

void sort(std::vector<int>& inputNums, std::vector<int>& outputNums, const howToSort hts) {
	switch (hts.sm) {
	case bubble:
		outputNums = bubbleSort(inputNums, hts.so);
		break;
	case select:
	default:
		outputNums = selectSort(inputNums, hts.so);
		break;
	}
}

int main() {
	std::fstream ifs("inputNumbers.txt");
	howToSort howsort;
	std::vector<int> inputNumbers;
	std::vector<int> outputNumbers;
	std::vector<std::string> inputTexts;
	std::string outputText;
	std::string line;
	
	if (ifs.fail()) {
		std::cout << "failed" << std::endl;
		return -1;
	}
	while (std::getline(ifs, line)) {
		inputTexts.push_back(line);
	}
	howsort = makeCondition(inputTexts[sortStyle]);
	inputNumbers = split(inputTexts[sortData], ' ');
	sort(inputNumbers, outputNumbers, howsort);
	outputText = std::to_string(howsort.so) +":";
	for (unsigned int i = 0; i < outputNumbers.size(); i++) {
		if (i != 0) {
			outputText += " ";
		}
		outputText += std::to_string(outputNumbers[i]);
	}
	std::cout << outputText << std::endl;
	std::ofstream outputFile("outputNumbers.txt");
	outputFile << outputText;
	outputFile.close();
	return 0;
}