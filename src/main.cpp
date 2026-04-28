#include <iostream>
#include "weapons/G36.h"

int main()
{
  std::cout << "=== Fire Range ===\n\n";

  G36 g36;

  std::cout << g36.status() << '\n';

  g36.fire(12);
  std::cout << g36.status() << '\n';

  g36.fire(25);           // fire 18 shoots until jammed
  std::cout << g36.status() << '\n';

  g36.reload();
  std::cout << g36.status() << '\n';

  return 0;
}