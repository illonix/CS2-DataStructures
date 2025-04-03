//  String class test program
//
//  Tests: Char Constructor
//


#include <iostream>
#include <cassert>
#include "string.hpp"

int main() {

  {
    String str1('a');
    assert(str1 == "a");
    std::cout << "Test case 1 passed.\n";
  }

  {
    String str('z');
    assert(str == "z");
    std::cout << "Test case 2 passed.\n";
  }

  {
    String str("z");
    String str1("a");
    String result = str + str1;
    assert(str == "z");
    assert(str1 == "a");
    assert(result == "za");
    std::cout << "Test case 3 passed.\n";
  }

  {
    String str('!');
    assert(str == "!");
    std::cout << "Test case 4 passed.\n";
  }

  {
    String str('0');
    assert(str == "0");
    std::cout << "Test case 5 passed.\n";
  }

  {
    String str('#');
    assert(str == "#");
    std::cout << "Test case 6 passed.\n";
  }

  {
    String str('*');
    assert(str == "*");
    std::cout << "Test case 7 passed.\n";
  }

  {
    String str(' ');
    assert(str == " ");
    std::cout << "Test case 8 passed.\n";
  }

  {
    String str1('X');
    String str2('Y');
    String result = str1 + str2;
    assert(result == "XY");
    std::cout << "Test case 9 passed.\n";
  }

  {
    String str('9');
    assert(str == "9");
    std::cout << "Test case 10 passed.\n";
  }

  std::cout << "Done testing char constructor." << std::endl;
  return 0;
}
