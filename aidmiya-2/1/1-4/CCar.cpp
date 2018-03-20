#include <iostream>
#include "CCar.h"
using namespace std;

CCar::CCar() : fuel(200) {
  cout << "新車の燃料は" << fuel << "あります" << endl;
}
CCar::CCar(int value) : fuel(value) {
  cout << "新車の燃料は" << fuel << "あります" << endl;
}
/*
CCar::CCar() {      // 型なし
  // int fuel = 200;
  fuel = 200;
  cout << "新車の燃料は" << fuel << "あります" << endl;
}
CCar::CCar(int value) {// 型なし
  // int fuel = value;
  fuel = value;
  cout << "新車の燃料は" << fuel << "あります" << endl;
}
*/
CCar::~CCar() {     // 型なし
  cout << "燃料が" << fuel << "残っていますが、廃車です。" << endl;
  cout << "廃車" << endl;
}

void CCar::run() {
  fuel -= 100;
  cout << "走ったので燃料が100減り、" << fuel << "になりましたよ" << endl;
}
int CCar::getFuel() {
  return fuel;
}
void CCar::setFuel(int value) {
  cout << "燃料を" << value << "に設定しました" << endl;
  fuel = value;
}

