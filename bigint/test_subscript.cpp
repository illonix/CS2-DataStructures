// Bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        Bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }
    {
        // Setup
        Bigint bi(542);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 542);
        assert(digit == 4);
    }
    {
        // Setup
        Bigint bi(9042);

        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 9042);
        assert(digit == 9);
    }
    {
        // Setup
        Bigint bi(50);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 50);
        assert(digit == 5);
    }
    {
        // Setup
        Bigint bi(54345);

        // Test 
        int digit = bi[4];

        // Verify
        assert(bi    == 54345);
        assert(digit == 5);
    }
    {
        // Setup
        Bigint bi(234253342);

        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 234253342);
        assert(digit == 3);
    }
    {
        // Setup
        Bigint bi(1988);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 1988);
        assert(digit == 8);
    }
    {
        // Setup
        Bigint bi(3214000);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 3214000);
        assert(digit == 0);
    }
    {
        // Setup
        Bigint bi(12542);

        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 12542);
        assert(digit == 2);
    }
    {
        // Setup
        Bigint bi(4321);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 4321);
        assert(digit == 3);
    }
    {
        // Setup
        Bigint bi(1234);

        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 1234);  
        assert(digit == 1);
    }
    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

