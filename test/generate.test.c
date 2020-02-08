#include "unittest.h"
#include "generate.h"


int main() {
  unit_test(!is_strong("abcd", 4), "abcd is a weak password");
  unit_test(is_strong("abc^3Solenji", 12), "abc^3Solenji is a strong password");

  return report();
}
