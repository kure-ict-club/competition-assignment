
#include <iostream>
#include <string>

#include "DelegateAction.h"
#include "DelegateCreate.h"
#include "DelegateFuncCreate.h"
#include "DelegateEvent.h"

//�e�X�g�p��Action�N���X
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

//�ʏ�֐��ɂ��Ή�
void H1(int a, int b, int c) {
	std::cout << a * b*c << "\n";
}
void H2(int a, float b, std::string c) {
	std::cout << c << a + b << "\n";
}



//�������X�g�̌^�Ɛ�
#define TYPE1 int ,int ,int
#define TYPE2 int ,float ,std::string

int main() {

	//Action(�C�ӂ̃N���X�A�C�ӂ̈���)
	MyClass my1;
	
	//Event
	DelegateEvent<TYPE1> event1;
	DelegateEvent<TYPE2> event2;


	//Event�ɓo�^ (�����ď����ۂ͓o�^����move���邱��) setEvent�֐� ,+= , << �ɑΉ�
	event1.setEvent(DelegateCreate<MyClass, TYPE1>::create(&my1, &MyClass::F1));
	event1 += (DelegateCreate<MyClass, TYPE1>::create(&my1, &MyClass::G1));
	event1 << (DelegateFuncCreate<TYPE1>::create(&H1));//�ʏ�֐��p

	event2.setEvent(DelegateCreate<MyClass, TYPE2>::create(&my1, &MyClass::F2));
	event2 += (DelegateCreate<MyClass, TYPE2>::create(&my1, &MyClass::G2));
	event2 << (DelegateFuncCreate<TYPE2>::create(&H2));//�ʏ�֐��p


	//Event����
	event1(1, 2, 3);
	event2(1, 2.43f, "string");

	//Event�o�^����
	event1.clear();
	event2.clear();

	//Event���������Ă����Ɠo�^��������Ă邩���m�F
	event1(1, 2, 3);
	event2(1, 2.43f, "string");


	return 0;
}

