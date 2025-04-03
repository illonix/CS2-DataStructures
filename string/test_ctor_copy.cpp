//  String class test program
//
//  Tests: Copy Constructor
//

#include "string.hpp"
#include <iostream>
#include <cassert>

int main() {
    // Test case 1: Default constructor
    String str1;
    assert(str1.length() == 0);
    assert(str1.capacity() == 0);
    std::cout << "Test case 1 passed: Default constructor\n";

    // Test case 2: Constructor with a character
    String str2('a');
    assert(str2.length() == 1);
    assert(str2.capacity() == 1);
    assert(str2[0] == 'a');
    std::cout << "Test case 2 passed: Constructor with a character\n";

    // Test case 3: Constructor with a string literal
    String str3("Hello");
    assert(str3.length() == 5);
    assert(str3.capacity() == 5);
    assert(str3[0] == 'H');
    assert(str3[4] == 'o');
    std::cout << "Test case 3 passed: Constructor with a string literal\n";

    // Test case 4: Copy constructor
    String str4(str3);  // Use the copy constructor
    assert(str4.length() == str3.length());
    assert(str4.capacity() == str3.capacity());
    assert(str4 == str3);  // Ensure that they are equal
    std::cout << "Test case 4 passed: Copy constructor\n";

    // Test case 5: Modify the original string and check if the copy is unaffected
    str3[0] = 'h';  // Change first character of str3
    assert(str3[0] == 'h');   // Original string should change
    assert(str4[0] == 'H');   // Copy should remain unchanged
    std::cout << "Test case 5 passed: Modifying original string, copy unaffected\n";

    // Test case 6: Copy an empty string
    String str5;
    String str6(str5);  // Copy the empty string
    assert(str6.length() == 0);
    assert(str6.capacity() == 0);
    std::cout << "Test case 6 passed: Copying an empty string\n";

    // Test case 7: Constructor with a longer string literal
    String str7("This is a test");
    assert(str7.length() == 14);
    assert(str7.capacity() == 14);
    assert(str7[0] == 'T');
    assert(str7[13] == 't');
    std::cout << "Test case 7 passed: Constructor with a longer string\n";

    // Test case 8: Copy constructor with a longer string
    String str8(str7);  // Copy longer string
    assert(str8.length() == str7.length());
    assert(str8.capacity() == str7.capacity());
    assert(str8 == str7);
    std::cout << "Test case 8 passed: Copy constructor with longer string\n";

    // Test case 9: Constructor with a single space character
    String str9(' ');
    assert(str9.length() == 1);
    assert(str9.capacity() == 1);
    assert(str9[0] == ' ');
    std::cout << "Test case 9 passed: Constructor with a space character\n";

    // Test case 10: Copy constructor for a string with special characters
    String str10("!@#$%");
    String str11(str10);  // Copy string with special characters
    assert(str11.length() == 5);
    assert(str11.capacity() == 5);
    assert(str11 == str10);
    std::cout << "Test case 10 passed: Copy constructor for string with special characters\n";

    std::cout << "All tests passed for test_ctor_copy." << std::endl;
    return 0;
}
