//  String class test program
//
//  Tests: Equal
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("a");
        String strTwo("a");
        // TEST
        bool result = (str == strTwo);

        // VERIFY
        assert(str    == "a");
        std::cout << "strTwo: [" << strTwo << "]" << std::endl;
        assert(strTwo == "a");
        assert(result == true);
    }

  {
    String str1("a");
    String str2("abc");
    assert(!(str1 == str2));
    std::cout << str1 << " != " << str2 << std::endl;
  }

  {
    String str1("abc");
    String str2("abc");
    assert((str1 == str2));
    std::cout << str1 << " == " << str2 << std::endl;
  }

  {
    String str1("");
    String str2("");
    assert((str1 == str2));
    std::cout << "Empty strings: " << str1 << " == " << str2 << std::endl;
  }

  {
    String str1("abc123");
    String str2("abc123");
    assert((str1 == str2));
    std::cout << str1 << " == " << str2 << std::endl;
  }

  {
    String str1("123abc");
    String str2("123abc");
    assert((str1 == str2));
    std::cout << str1 << " == " << str2 << std::endl;
  }

  {
    String str1("Hello World");
    String str2("Hello World");
    assert((str1 == str2));
    std::cout << str1 << " == " << str2 << std::endl;
  }

  {
    String str1("Hello World");
    String str2("hello world");
    assert(!(str1 == str2));  // Case-sensitive comparison
    std::cout << str1 << " != " << str2 << std::endl;
  }

  {
    String str1("a longer string test");
    String str2("a longer string test");
    assert((str1 == str2));
    std::cout << str1 << " == " << str2 << std::endl;
  }

  {
    String str1("abcde");
    String str2("abcd");
    assert(!(str1 == str2));
    std::cout << str1 << " != " << str2 << std::endl;
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE: Testing `!=` with different lengths
    String str1("a");
    String str2("abc");
    assert(!(str1 == str2)); // Should not be equal
    assert(str1 != str2);    // Should be different
    std::cout << str1 << " != " << str2 << std::endl;
}

{
  //------------------------------------------------------
  // SETUP FIXTURE: One string is a substring of another
  String str1("abcde");
  String str2("abcd");
  assert(!(str1 == str2)); // Should not be equal
  assert(str1 != str2);    // Should be different
  std::cout << str1 << " != " << str2 << std::endl;
}

  std::cout << "Done testing operator== " << std::endl;
}
