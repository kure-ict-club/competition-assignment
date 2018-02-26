
#include <iostream>
#include <string>

#include "DelegateAction.h"
#include "DelegateCreate.h"
#include "DelegateFuncCreate.h"
#include "DelegateEvent.h"

//ƒeƒXƒg—p‚ÌActionƒNƒ‰ƒX
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

//’ÊíŠÖ”‚É‚à‘Î‰
void H1(int a, int b, int c) {
	std::cout << a * b*c << "\n";
}
void H2(int a, float b, std::string c) {
	std::cout << c << a + b << "\n";
}



//ˆø”ƒŠƒXƒg‚ÌŒ^‚Æ”
#define TYPE1 int ,int ,int
#define TYPE2 int ,float ,std::string

int main() {

	//Action(”CˆÓ‚ÌƒNƒ‰ƒXA”CˆÓ‚Ìˆø”)
	MyClass my1;
	
	//Event
	DelegateEvent<TYPE1> event1;
	DelegateEvent<TYPE2> event2;


	//Event‚É“o˜^ (•ª‚¯‚Ä‘‚­Û‚Í“o˜^‚Émove‚·‚é‚±‚Æ) setEventŠÖ” ,+= , << ‚É‘Î‰
	event1.setEvent(DelegateCreate<MyClass, TYPE1>::create(&my1, &MyClass::F1));
	event1 += (DelegateCreate<MyClass, TYPE1>::create(&my1, &MyClass::G1));
	event1 << (DelegateFuncCreate<TYPE1>::create(&H1));//’ÊíŠÖ”—p

	event2.setEvent(DelegateCreate<MyClass, TYPE2>::create(&my1, &MyClass::F2));
	event2 += (DelegateCreate<MyClass, TYPE2>::create(&my1, &MyClass::G2));
	event2 << (DelegateFuncCreate<TYPE2>::create(&H2));//’ÊíŠÖ”—p


	//Event”­¶
	event1(1, 2, 3);
	event2(1, 2.43f, "string");

	//Event“o˜^‰ğœ
	event1.clear();
	event2.clear();

	//Event”­¶‚³‚¹‚Ä‚¿‚á‚ñ‚Æ“o˜^‰ğœ‚³‚ê‚Ä‚é‚©‚ğŠm”F
	event1(1, 2, 3);
	event2(1, 2.43f, "string");


	return 0;
}

