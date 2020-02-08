#include "unittest.h"


int main() {
  unit_test(1==0, "1==0 returns true");
  return report();
}
