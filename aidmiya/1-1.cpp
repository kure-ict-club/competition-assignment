/* Q1 その1 aidmiya */

#include <iostream>
using namespace std;

void toFizzBuzz( int );

int main() {
	toFizzBuzz(2);
	toFizzBuzz(3);
	toFizzBuzz(5);
	toFizzBuzz(15);
	return 0;
}

void toFizzBuzz( int value ) {
	if ( ( value % 3 == 0 ) && ( value % 5 == 0 ) ) {
		cout << "FizzBuzz" << endl;
	}
	else if ( value % 3 == 0 ) {
		cout << "Fizz" << endl;
	}
	else if ( value % 5 == 0 ) {
		cout << "Buzz" << endl;
	}
	else {
		cout << value << endl;
	}
}

