//  String class test program
//
//  Tests: Const char[] Constructor
//



#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

  {
    String str("a");
    assert(str[0] == 'a');
    assert(str[1] == '\0');
    std::cout << "Test case 1 passed.\n";
  }

  {
    String str("abc");
    assert(str[0] == 'a');
    assert(str[1] == 'b');
    assert(str[2] == 'c');
    assert(str[3] == '\0');
    std::cout << "Test case 2 passed.\n";
  }

  {
    String str("");
    assert(str[0] == '\0');
    std::cout << "Test case 3 passed.\n";
  }

  {
    String str("hello");
    assert(str[0] == 'h');
    assert(str[4] == 'o');
    assert(str[5] == '\0');
    std::cout << "Test case 4 passed.\n";
  }

  {
    String str("123456789");
    assert(str[0] == '1');
    assert(str[8] == '9');
    assert(str[9] == '\0');
    std::cout << "Test case 5 passed.\n";
  }

  {
    String str("!");
    assert(str[0] == '!');
    assert(str[1] == '\0');
    std::cout << "Test case 6 passed.\n";
  }

  {
    String str("C++");
    assert(str[0] == 'C');
    assert(str[2] == '+');
    assert(str[3] == '\0');
    std::cout << "Test case 7 passed.\n";
  }

  {
    String str("spaces in string");
    assert(str[6] == ' ');
    assert(str[7] == 'i');
    std::cout << "Test case 8 passed.\n";
  }

  {
    String str("mixedCASE");
    assert(str[0] == 'm');
    assert(str[5] == 'C');
    assert(str[9] == '\0');
    std::cout << "Test case 9 passed.\n";
  }

    {
    String str("a");
    assert(str[0] == 'a');
    assert(str[1] == '\0');
  }

  {
    String str("abc");
    assert(str[0] == 'a');
    assert(str[1] == 'b');
    assert(str[2] == 'c');
    assert(str[3] == '\0');
  }

  std::cout << "Done testing char array constructor." << std::endl;
}
