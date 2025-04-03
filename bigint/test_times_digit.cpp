// Bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi1(3);
    
        // Test
        bi1 = bi1.timesDigit(1);
    
        // Verify
        assert(bi1 == 3); 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi2(0);
    
        // Test
        bi2 = bi2.timesDigit(5);
    
        // Verify
        assert(bi2 == 0); // Multiplying zero should remain zero
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi3(9);
    
        // Test
        bi3 = bi3.timesDigit(2);
    
        // Verify
        assert(bi3 == 18); // 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi4(47);
    
        // Test
        bi4 = bi4.timesDigit(3);
    
        // Verify
        assert(bi4 == 141); // 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi5(123);
    
        // Test
        bi5 = bi5.timesDigit(4);
    
        // Verify
        assert(bi5 == 492); // 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi6(789);
    
        // Test
        bi6 = bi6.timesDigit(9);
    
        // Verify
        assert(bi6 == 7101); // 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi7(9999);
    
        // Test
        bi7 = bi7.timesDigit(9);
    
        // Verify
        assert(bi7 == 89991); // 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi8(1000001);
    
        // Test
        bi8 = bi8.timesDigit(7);
    
        // Verify
        assert(bi8 == 7000007); // 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi9("987654321");
    
        // Test
        bi9 = bi9.timesDigit(8);
    
        // Verify
        assert(bi9 == "7901234568"); // 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture (100-digit number)
        Bigint bi10("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    
        // Test
        bi10 = bi10.timesDigit(5);
    
        // Verify
        assert(bi10 == "6172839450617283945061728394506172839450617283945061728394506172839450617283945061728394506172839450"); 
        
    }
    


    //Add test cases as needed.
    
    std::cout << "Done testing Bigint * digit" << std::endl;
    return 0;
}
