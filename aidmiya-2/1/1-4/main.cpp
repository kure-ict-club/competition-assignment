#include <iostream>
#include "CCar.h"
using namespace std;

int main() {
  // 生成と消去を明記せず、静的にインスタンス化
  CCar car1;
  cout << "car1の燃料: " << car1.getFuel() << endl;
  car1.run();
  cout << "car1の燃料: " << car1.getFuel() << endl;

  // 生成=newと消去=deleteを明記して、動的にインスタンス化
  //CCar* car2;
  CCar* car2 = new CCar;
  car2->run();
  cout << "car2の燃料: " << car2->getFuel() << endl;
  delete car2;

  // ゲッターとセッターを使う
  CCar car3(500);
  cout << "car3の燃料: " << car3.getFuel() << endl;
  car3.run();
  cout << "car3の燃料: " << car3.getFuel() << endl;
  car3.setFuel(car3.getFuel() + 300);
  cout << "car3の燃料: " << car3.getFuel() << endl;
  return 0;
}

