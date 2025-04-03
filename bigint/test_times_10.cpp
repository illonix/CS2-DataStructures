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
        bi1 = bi1.times10(1);
    
        // Verify
        assert(bi1 == 30); // Corrected: 3 * 10^1 = 30
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi2(5);
    
        // Test
        bi2 = bi2.times10(2);
    
        // Verify
        assert(bi2 == 500); // 5 * 10^2 = 500
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi3(123);
    
        // Test
        bi3 = bi3.times10(3);
    
        // Verify
        assert(bi3 == 123000); // 123 * 10^3 = 123000
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi4(9876);
    
        // Test
        bi4 = bi4.times10(4);
    
        // Verify
        assert(bi4 == 98760000); // 9876 * 10^4 = 98760000
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi5(0);
    
        // Test
        bi5 = bi5.times10(5);
    
        // Verify
        assert(bi5 == 0); // 0 * 10^5 should still be 0
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi6(1);
    
        // Test
        bi6 = bi6.times10(10);
    
        // Verify
        assert(bi6 == "10000000000"); // 1 * 10^10 = 10000000000
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi7(42);
    
        // Test
        bi7 = bi7.times10(0);
    
        // Verify
        assert(bi7 == 42); // Multiplying by 10^0 should return the same number
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi8(7001);
    
        // Test
        bi8 = bi8.times10(6);
    
        // Verify
        assert(bi8 == "7001000000"); // 7001 * 10^6 = 7001000000
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi9("999999");
    
        // Test
        bi9 = bi9.times10(8);
    
        // Verify
        assert(bi9 == "99999900000000"); // 999999 * 10^8 = 99999900000000
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi40("1234567890123456789012345678901234567890");
    
        // Test
        bi40 = bi40.times10(6);
    
        // Verify
        assert(bi40 == "1234567890123456789012345678901234567890000000"); 
        // 1234567890123456789012345678901234567890 * 10^6 = 1234567890123456789012345678901234567890000000
    }
    
    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

