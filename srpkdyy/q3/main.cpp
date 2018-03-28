#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

class Text {
private:
   std::vector<std::string> text;

public:
   Text(std::ifstream& readFile) {
      std::string buf;
      while (getline(readFile, buf)) text.push_back(buf);
   }

   int lineCount() const {
      return text.size();
   }

   std::string getLine(int line) const {
      return text[line];
   }

   char getChar(int line, int row) const {
      return text[line][row];
   }
};

class Rearranger {
private:
   bool isDescending;
   std::vector<int> sortData;

public:
   Rearranger(std::string data, char split) : isDescending(true) {
      std::stringstream ss { data };
      std::string buf;
      while(getline(ss, buf, split)) sortData.push_back(std::stoi(buf));
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

   void setDescending() {
      if (!isDescending) {
         std::reverse(sortData.begin(), sortData.end());
         isDescending = true;
      }
   }

   void setAscending() {
      if (isDescending) {
         std::reverse(sortData.begin(), sortData.end());
         isDescending = false;
      }
   }

   int size() const {
      return sortData.size();
   }

   std::vector<int> getSortedData() const {
      return sortData;
   }

};


int main() {
   std::ifstream ifs("input.txt");
   if (ifs.fail()) return -1;

   Text text(ifs);

   Rearranger data(text.getLine(2), ' ');


   switch (text.getChar(0, 2)) {
      case '0': data.bubbleSort(); break;
      case '1': data.selectSort(); break;
      default :                    break;

   }

   switch (text.getChar(0, 0)) {
      case '0': data.setAscending();  break;
      case '1': data.setDescending(); break;
      default :                       break;
      
   }
    
   
   std::ofstream ofs("output.txt");

   ofs << text.getLine(0);
   for (const auto& value : data.getSortedData()) ofs << ' ' << value;


	return 0;
}

