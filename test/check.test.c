#include "unittest.h"

int main() {
  int solenj = 0;

  unit_test(solenj==0, "Solenj is 0");
  unit_test(solenj==1, "Solenj is 1 (press F if this fails)");

  return report();
}
