// [1] その3 int型のvectorにランダムに0〜9の数を10個入れ、全て表示->要素を2つ追加、乱数を入れ、全て表示

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void putAll(int*, int);

int main() {
  // 準備
  srand((unsigned int) time(NULL));

  // 10個入れて表示
  vector<int> value(10);
  for ( int i = 0; i < value.size(); i++ )
    value[i] = rand() % 10;
  putAll(&value[0], value.size());
  cout << endl;

  // 2個追加して表示
  value.push_back(rand() % 10);
  value.push_back(rand() % 10);
  putAll(&value[0], value.size());
  cout << endl;
  return 0;
}

void putAll(int* first, int num) {
  for ( int i = 0; i < num; i++ )
    cout << *(first+i) << " ";
}

