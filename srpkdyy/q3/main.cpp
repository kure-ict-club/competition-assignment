#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

class Text {
private:
   int lineNum;
   std::vector<std::string> text;

public:
   Text(std::ifstream& readFile) : lineNum(0) {
      std::string buf;
      while (getline(readFile, buf)) {
         text.push_back(buf);
         lineNum++;
      }
   }

   int lineCount() const {
      return lineNum;
   }

   std::string getStr(int line) {
      return text[line];
   }

   char getChar(int line, int row) {
      return text[line][row];
   }
};

class Rearranger {
public:
   std::vector<int> sortData;

public:
   Rearranger(std::string data, char split) {
      std::stringstream ss { data };
      std::string buf;
      while(getline(ss, buf, split)) sortData.push_back(std::stoi(buf));
   }

   int size() const {
      return sortData.size();
   }

   void bubbleSort() {
      for (int i=0; i<size()-1; ++i) {
         bool hasSorted = false;

         for (int j=0; j<size()-1-i; ++j) {
            if (sortData[j] > sortData[j+1]) {
               std::swap(sortData[j], sortData[j+1]);
               hasSorted = true;
            }
         }

         if (hasSorted == false) return;
      }
   }

   void selectSort() {
      for (int i=0; i<size()-1; ++i) {
         int minIndex = i;
         for (int j=i+1; j<size(); ++j) {
            if (sortData[minIndex] < sortData[j]) {
               minIndex = j;
            } 
         }
         std::swap(sortData[i], sortData[minIndex]);
      } 
   }

   std::vector<int> getDescenging() const {
      return sortData;
   }

   std::vector<int> getAscending() const {
      auto data = sortData;
      std::reverse(data.begin(), data.end());
      return data;
   }
};


int main() {
   std::ifstream ifs("inputdata.txt");
   if (ifs.fail()) return -1;

   Text text(ifs);

   Rearranger data(text.getStr(2), ' ');

   data.bubbleSort();
   //data.selectSort();

   for (auto value : data.getAscending()) {
      std::cout << value << std::endl;
   }

	return 0;
}

