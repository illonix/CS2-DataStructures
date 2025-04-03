//
// Test case for string concatenation using +=
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

  { 
    //------------------------------------
    // Setup Fixture: Empty += Empty
    String str1, str2;
    str1 += str2;
    assert(str1 == "");
    assert(str2 == "");
  }

  {
    //------------------------------------
    // Setup Fixture: Empty += Single character
    String str1, str2('b');
    str1 += str2;
    assert(str1 == "b");
    assert(str2 == "b");
  }

  {
    //------------------------------------
    // Setup Fixture: Single char += Single char
    String str1('a');
    str1 += 'b';
    assert(str1 == "ab");
  }

  {
    //------------------------------------
    // Setup Fixture: String += String
    String str1("Hello"), str2(" World");
    str1 += str2;
    assert(str1 == "Hello World");
    assert(str2 == " World");
  }

  {
    //------------------------------------
    // Setup Fixture: String += Empty String
    String str1("Test"), str2("");
    str1 += str2;
    assert(str1 == "Test");
    assert(str2 == "");
  }

  {
    //------------------------------------
    // Setup Fixture: Empty String += String
    String str1(""), str2("Test");
    str1 += str2;
    assert(str1 == "Test");
    assert(str2 == "Test");
  }

  {
    //------------------------------------
    // Setup Fixture: String += Itself
    String str1("Repeat");
    str1 += str1;
    assert(str1 == "RepeatRepeat");
  }

  {
    //------------------------------------
    // Setup Fixture: Multiple += Operations
    String str1("A");
    str1 += "B";
    str1 += "C";
    assert(str1 == "ABC");
  }

  std::cout << "Done testing += operator" << std::endl;
}
