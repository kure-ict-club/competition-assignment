
#include <iostream>
#include <string>

#include "DelegateAction.h"
#include "DelegateCreate.h"
#include "DelegateFuncCreate.h"
#include "DelegateEvent.h"

//テスト用のActionクラス
class MyClass
{
public:
	void F1(int a, int b, int c) {
		std::cout << a << " " << b << " " << c << "\n";
	}
	void F2(int a, float b, std::string c) {
		std::cout << a << " " << b << " " << c << "\n";
	}
	void G1(int a, int b, int c) {
		std::cout << a*a << " " << b*b << " " << c*c << "\n";
	}
	void G2(int a, float b, std::string c) {
		std::cout << a*a << " " << b*b << " " << c+c << "\n";
	}
};

//通常関数にも対応
void H1(int a, int b, int c) {
	std::cout << a * b*c << "\n";
}
void H2(int a, float b, std::string c) {
	std::cout << c << a + b << "\n";
}



//引数リストの型と数
#define TYPE1 int ,int ,int
#define TYPE2 int ,float ,std::string

int main() {

	//Action(任意のクラス、任意の引数)
	MyClass my1;
	
	//Event
	DelegateEvent<TYPE1> event1;
	DelegateEvent<TYPE2> event2;


	//Eventに登録 (分けて書く際は登録時にmoveすること) setEvent関数 ,+= , << に対応
	event1.setEvent(DelegateCreate<MyClass, TYPE1>::create(&my1, &MyClass::F1));
	event1 += (DelegateCreate<MyClass, TYPE1>::create(&my1, &MyClass::G1));
	event1 << (DelegateFuncCreate<TYPE1>::create(&H1));//通常関数用

	event2.setEvent(DelegateCreate<MyClass, TYPE2>::create(&my1, &MyClass::F2));
	event2 += (DelegateCreate<MyClass, TYPE2>::create(&my1, &MyClass::G2));
	event2 << (DelegateFuncCreate<TYPE2>::create(&H2));//通常関数用


	//Event発生
	event1(1, 2, 3);
	event2(1, 2.43f, "string");

	//Event登録解除
	event1.clear();
	event2.clear();

	//Event発生させてちゃんと登録解除されてるかを確認
	event1(1, 2, 3);
	event2(1, 2.43f, "string");


	return 0;
}

