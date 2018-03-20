// [1] その1 FizzBuzz問題を関数に分割
// FizzBuzz…%3==0ならFizz、%5==0ならBuzz、どちらもならFizzBuzzと出力
#include <iostream>
using namespace std;
void toFizzBuzz(int value);

int main() {
  toFizzBuzz(2);
  toFizzBuzz(3);
  toFizzBuzz(5);
  toFizzBuzz(15);
}

void toFizzBuzz(int value) {
  if ( value % (3*5) == 0 )       // 3でも5でも
    cout << "FizzBuzz" << endl;
  else if ( value % 3 == 0 )      // 3で
    cout << "Fizz" << endl;
  else if ( value % 5 == 0 )      // 5で
    cout << "Buzz" << endl;
  else                            // そのほか
    cout << value << endl;
}

