#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {
        //------------------------------------
        // Setup Fixture: Test `<` (less than)
        String str1("apple"), str2("banana");
        assert(str1 < str2);  
        assert(!(str2 < str1));
        assert(!(str1 < str1));
    }

    {
        //------------------------------------
        // Setup Fixture: Test `>` (greater than)
        String str1("orange"), str2("grape");
        assert(str1 > str2);  
        assert(!(str2 > str1));
        assert(!(str1 > str1));
    }

    {
        //------------------------------------
        // Setup Fixture: Test `<=` (less than or equal)
        String str1("cat"), str2("dog"), str3("cat");
        assert(str1 <= str2); 
        assert(str1 <= str3); 
        assert(!(str2 <= str1));
    }

    {
        //------------------------------------
        // Setup Fixture: Test `>=` (greater than or equal)
        String str1("zebra"), str2("aardvark"), str3("zebra");
        assert(str1 >= str2); 
        assert(str1 >= str3); 
        assert(!(str2 >= str1));
    }

    {
        //------------------------------------
        // Setup Fixture: Test `==` (equal)
        String str1("hello"), str2("hello"), str3("world");
        assert(str1 == str2); 
        assert(!(str1 == str3));
    }

    {
        //------------------------------------
        // Setup Fixture: Test `!=` (not equal)
        String str1("apple"), str2("orange"), str3("apple");
        assert(str1 != str2); 
        assert(!(str1 != str3));
    }

    std::cout << "Done testing comparison operators." << std::endl;
}
