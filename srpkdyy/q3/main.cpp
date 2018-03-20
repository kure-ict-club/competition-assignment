#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Text {
private:
   int lineNum;
   std::vector<std::string> text;

public:
   Text() : lineNum(0) {}
   void readFromFile(std::ifstream& readFile) {
      std::string tmp;
      while (getline(readFile, tmp)) {
         text.push_back(tmp);
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


int main() {
   std::ifstream ifs("inputdata.txt");
   if (ifs.fail()) return -1;

   Text readData;
   readData.readFromFile(ifs);

   for (int i=0; i<readData.lineCount(); ++i) {
      std::cout << readData.getStr(i) << std::endl;
   }

   std::cout << readData.getChar(0, 1) << std::endl;

	return 0;
}

