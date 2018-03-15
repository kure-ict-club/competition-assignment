#include <iostream>
#include "Delegate.h"
#include "DoorBell.h"

class Dog {
public:
	void dogFunc(int value) {
		std::cout << "one" << std::endl;
	}
};
class Cat {
public:
	void catFunc(int value) {
		std::cout << "meow" << std::endl;
	}
};

int main() {
	Dog dog;
	Cat cat;
	DelegateBase* dogFunc_DG = Delegate<Dog>::createDelegator(&dog, &Dog::dogFunc);
	DelegateBase* catFunc_DG = Delegate<Cat>::createDelegator(&cat, &Cat::catFunc);
	DoorBell doorBell;
	doorBell.setOnOpenDoorHandler(dogFunc_DG);
	doorBell.setOnOpenDoorHandler(catFunc_DG);
	doorBell.onOpenDoor();
}