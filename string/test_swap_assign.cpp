//  String class test program
//
//  Tests: Swap
//

#include "string.hpp"
#include <iostream>
#include <cassert>

int main() {
    String str1("Hello");
    String str2("World");
    str1.swap(str2);
    assert(str1 == String("World") && str2 == String("Hello"));
    std::cout << "Test case 1 passed: swap('Hello', 'World') => ('World', 'Hello')\n";

    String str3; // Empty string
    String str4("Test");
    str3.swap(str4);
    assert(str3 == String("Test") && str4 == String(""));
    std::cout << "Test case 2 passed: swap('', 'Test') => ('Test', '')\n";

    String str5;
    String str6;
    str5.swap(str6);
    assert(str5 == String("") && str6 == String(""));
    std::cout << "Test case 3 passed: swap('', '') => ('', '')\n";

    String str7("Same");
    str7.swap(str7);
    assert(str7 == String("Same"));
    std::cout << "Test case 4 passed: swap('Same', 'Same') => ('Same', 'Same')\n";

    String str8("C++");
    String str9("Rocks!");
    str8.swap(str9);
    assert(str8 == String("Rocks!") && str9 == String("C++"));
    std::cout << "Test case 5 passed: swap('C++', 'Rocks!') => ('Rocks!', 'C++')\n";

    String str10("A");
    String str11("B");
    str10.swap(str11);
    assert(str10 == String("B") && str11 == String("A"));
    std::cout << "Test case 6 passed: swap('A', 'B') => ('B', 'A')\n";

    String str12("   ");
    String str13("Spaces");
    str12.swap(str13);
    assert(str12 == String("Spaces") && str13 == String("   "));
    std::cout << "Test case 7 passed: swap('   ', 'Spaces') => ('Spaces', '   ')\n";

    String str14("123");
    String str15("456");
    str14.swap(str15);
    assert(str14 == String("456") && str15 == String("123"));
    std::cout << "Test case 8 passed: swap('123', '456') => ('456', '123')\n";

    String str16("This is a very long string that we will use to test swapping!");
    String str17("Another long string for testing purposes!");
    str16.swap(str17);
    assert(str16 == String("Another long string for testing purposes!") && 
           str17 == String("This is a very long string that we will use to test swapping!"));
    std::cout << "Test case 9 passed: swap(long string, long string) => (long string, long string)\n";

    String str18("Upper");
    String str19("lower");
    str18.swap(str19);
    assert(str18 == String("lower") && str19 == String("Upper"));
    std::cout << "Test case 10 passed: swap('Upper', 'lower') => ('lower', 'Upper')\n";

    std::cout << "All test cases passed!\n";
    return 0;
}
