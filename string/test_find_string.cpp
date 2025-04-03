//  String class test program
//
//  Tests: Find String
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
  
    {
        String string = "yothere";
        String find = "there";
        int result = string.findstr(0, find);
        std::cout << "Test case 1: " << result << std::endl;
        assert(result == 2);
    }

    {
        String string = "hello world";
        String find = "world";
        int result = string.findstr(0, find);
        std::cout << "Test case 2: " << result << std::endl;
        assert(result == 6);
    }

    {
        String string = "example string";
        String find = "ex";
        int result = string.findstr(0, find);
        std::cout << "Test case 3: " << result << std::endl;
        assert(result == 0);
    }

    {
        String string = "example string";
        String find = "string";
        int result = string.findstr(0, find);
        std::cout << "Test case 4: " << result << std::endl;
        assert(result == 8);
    }

    {
        String string = "searching for a substring";
        String find = "substring";
        int result = string.findstr(0, find);
        std::cout << "Test case 5: " << result << std::endl;
        assert(result == 16);
    }

    {
        String string = "find the needle in the haystack";
        String find = "needle";
        int result = string.findstr(0, find);
        std::cout << "Test case 6: " << result << std::endl;
        assert(result == 9);
    }

    {
        String string = "aaaaa";
        String find = "a";
        int result = string.findstr(0, find);
        std::cout << "Test case 7: " << result << std::endl;
        assert(result == 0);
    }

    {
        String string = "abcdef";
        String find = "g";
        int result = string.findstr(0, find);
        std::cout << "Test case 8: " << result << std::endl;
        assert(result == -1); // Not found
    }

    {
        String string = "";
        String find = "test";
        int result = string.findstr(0, find);
        std::cout << "Test case 9: " << result << std::endl;
        assert(result == -1); // Not found in empty string
    }

    {
        String string = "substring at start";
        String find = "substring";
        int result = string.findstr(0, find);
        std::cout << "Test case 10: " << result << std::endl;
        assert(result == 0);
    }

    std::cout << "Done testing findstr()." << std::endl;
}
