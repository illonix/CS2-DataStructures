//  String class test program
//
//  Tests: Subscript
//


#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main() {
    {
        char X[5] = {'h', 'e', 'l', 'l', 'o'};
        String str(X);

        char result = str[0];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(str == String(X));
        assert(result == 'h');
    }

    {
        char X[5] = {'h', 'e', 'l', 'l', 'o'};
        String str(X);

        char result = str[4];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(result == 'o');
    }

    {
        String str("he1lo");
        char result = str[2];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(str == "he1lo");
        assert(result == '1');
    }

    {
        String str("hello");
        char result = str[1];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(str == "hello");
        assert(result != 'h');
    }

    {
        String str("OpenAI");
        char result = str[3];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(result == 'n');
    }

    {
        String str("Test123");
        char result = str[5];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(result == '2');
    }

    {
        String str("Boundary");
        char result = str[0];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(result == 'B');
    }

    {
        String str("Special Characters!@#");
        char result = str[15];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(result == 'e');
    }

    {
        String str("CaseSensitive");
        char result = str[10];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(result == 'i');
    }

    {
        String str("Longer String Test");
        char result = str[4];
        std::cout << "Subscript Result: " << result << std::endl;
        assert(result == 'e');
    }

    std::cout << "Done testing Subscript." << std::endl;
}
