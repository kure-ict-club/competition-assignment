/* Q1 その2 aidmiya */

#include <iostream>
using namespace std;

void swap( int*, int* );
void show( int, int );

int main() {
	int a = 10;
	int b = 20;
	show( a, b );
	swap( &a, &b );
	show( a, b );
	return 0;
}

void swap( int* v1, int* v2 ) {
	int tmp = *v2;	// (int) = (*(int*)=>int)
	*v2 = *v1;	// (*(int*)) = (*(int*))
	*v1 = tmp;	// (*(int*)) = (int)
}

void show( int a, int b ) {
	cout << a << "\t" << b << endl;
}

