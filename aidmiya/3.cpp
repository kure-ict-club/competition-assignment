#include <iostream>
#include <vector>
using namespace std;

void bubble();
void selection();
void swap( int, int );
void t_swap( int, int );

vector<int> data = { 1, 7, 3, 5 };
int swaptest[2] = {3, 5};

int main() {
	cout << swaptest[0] << swaptest[1] << endl;
	t_swap( 0, 1 );
	cout << swaptest[0] << swaptest[1] << endl;
	return 0;
}

void bubble() {
	if ( data[0] < data[1] ) {
		swap( 0, 1 );
	}
}

void selection() {
}

void swap( int num1, int num2 ) {
	int* p = NULL;
	p = &data[num2];
	int tmp = data[num2];
	*p = data[num1];
	p = &data[num1];
	*p = tmp;
}

void t_swap( int num1, int num2 ) {
	int* p = NULL;
	p = &swaptest[num2];
	int tmp = swaptest[num2];
	*p = swaptest[num1];
	p = &swaptest[num1];
	*p = tmp;
}


