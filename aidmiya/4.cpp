#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<bool> prime(100, 1);
	// エラトステネスのふるい
	for ( int i = 2; i < prime.size(); i++ ) {
		for ( int j = 2; j < prime.size(); j++ ) {
			if ( ( i % j == 0 ) && ( i / j != 1 ) ) {
				prime.at(j) = 0;
			}
		}
	}
	for ( int i = 0; i < prime.size(); i++ ) {
		if ( prime.at(i)==1 )
			cout << i << endl;
	}
	return 0;
}

