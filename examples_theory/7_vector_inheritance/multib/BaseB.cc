#include "BaseB.h"
#include <iostream>
using namespace std;

BaseB::BaseB() {
}

BaseB::~BaseB() {
}

void BaseB::f() {
  cout << "BaseB::f " << this << endl;
}

void BaseB::g() {
  cout << "BaseB::g " << this << endl;
}

