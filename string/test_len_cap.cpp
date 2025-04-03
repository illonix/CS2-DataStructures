//  String class test program
//
//  Tests: Length Capacity
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        String testOne = "abcd1234";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 8);
        assert(resultTwo == 8);
    }

    {
        String testOne;
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 0);
        assert(resultTwo == 0);
    }

    {
        String testOne = "abcd1423";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 8);
        assert(resultTwo == 8);
    }

    {
        String testOne = "ax";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 2);
        assert(resultTwo == 2);
    }

    {
        String testOne = "test string";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 11);
        assert(resultTwo >= 11); // Assuming capacity is >= length
    }

    {
        String testOne = " ";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 1);
        assert(resultTwo >= 1);
    }

    {
        String testOne = "special@chars!";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 14);
        assert(resultTwo >= 14);
    }

    {
        String testOne = "longer string example";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 21);
        assert(resultTwo >= 21);
    }

    {
        String testOne = "1234567890";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 10);
        assert(resultTwo >= 10);
    }

    {
        String testOne = "hello world!";
        int resultOne = testOne.length();
        int resultTwo = testOne.capacity();
        std::cout << "length: " << resultOne << std::endl;
        std::cout << "Capacity: " << resultTwo << std::endl;
        assert(resultOne == 12);
        assert(resultTwo >= 12);
    }

    std::cout << "Done testing length and capacity." << std::endl;
}
