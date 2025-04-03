//  String class test program
//
//  Tests: Find Char
//

#include "string.hpp"
#include <cassert>
#include <iostream>


int main() {

    {
        // Test case 1: Basic find of a character
        String one = "abcde";
        char two = 'd';
        int result = one.findch(0, two);
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == 3);
    }

    {
        // Test case 2: Finding the same character from a different starting point
        String one = "abcde";
        char two = 'd';
        int result = one.findch(3, two);
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == 3);
    }

    {
        // Test case 3: Finding a different character
        String one = "abcde";
        char two = 'c';
        int result = one.findch(0, two);
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == 2);
    }

    {
        // Test case 4: Finding a character in a string with digits
        String one = "abcde1234";
        char two = '3';
        int result = one.findch(0, two);
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == 7);
    }

    {
        // Test case 5: Finding a character not in the string
        String one = "bcde1234";
        int result = one.findch(0, 'a');
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == -1);
    }


    {
        // Test case 7: Finding a non-existing character in a long string
        String one = "we rtyuiop012345674gregdfhdhr5456sfsetsesestsdfdsfsdfsdfsdfsdf";
        int result = one.findch(0, 'a');
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == -1);
    }

    {
        // Test case 8: Finding a space character in a string
        String one = "look for space";
        int result = one.findch(0, ' ');
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == 4);
    }

    {
        // Test case 9: Finding a character from a non-zero starting position
        String one = "abcdefg";
        int result = one.findch(4, 'g');
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == 6);
    }

    {
        // Test case 10: Finding a character in a string with special characters
        String one = "special@char&find";
        int result = one.findch(0, '@');
        std::cout << "FindChar Result: " << result << std::endl;
        assert(result == 7);
    }

    std::cout << "Done Testing FindChar" << std::endl;
}
