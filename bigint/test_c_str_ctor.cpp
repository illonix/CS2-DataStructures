//  Bigint Test Program
//
//  Tests:  C-string constructor and operator<<, uses ==
//
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {

    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test 
        Bigint bi("0");

        // Verify
        assert(bi == 0);        
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        Bigint bi("1");

        // Verify
        assert(bi == 1);
    }

    {
        //------------------------------------------------------
        // Test: Construct with two-digit value
        // Setup fixture

        // Test 
        Bigint bi("27");

        // Verify
        assert(bi == 27);
    }

    {
        //------------------------------------------------------
        // Test: Construct with six-digit value
        // Setup fixture

        // Test 
        Bigint bi("456789");

        // Verify
        assert(bi == 456789);
    }
    

    {
        //------------------------------------------------------
        // Test: Construct with value that greater than an int will hold
        // Setup fixture
        // Larger than max int so need to check manually.

        // Test 
        Bigint bi("6234567890");
    
        // Verify
        assert(bi == "6234567890");
        std::cout << "6234567890 == ";
        std::cout << bi;           
        std::cout << std::endl;

        bi = Bigint("62345");   //Check re-assignment.
        assert(bi == "62345");
        std::cout << "62345 == ";
        std::cout << bi;
        std::cout << std::endl;


    }

    {
        //------------------------------------------------------
        // Test: Output
        // Setup fixture
        // Larger than max int so need to check manually.

        // Test
        Bigint bi("12345678901234567890123456789012345678901234567890123456789012345678901234567890");

        // Verify
        assert(bi == "12345678901234567890123456789012345678901234567890123456789012345678901234567890");

        std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890"<< std::endl;
        std::cout << "1234567890" << std::endl;
        std::cout << "==" << std::endl;
        std::cout << bi;
        std::cout << std::endl;

    }

    {
        //------------------------------------------------------
        // Test: Construct with multiple declarations.
        // Setup fixture

        // Test
        Bigint a("0");
        Bigint b("11");
        Bigint c("222");
        Bigint d("3333");
        Bigint e("44444");
        Bigint f("555555");
        Bigint g("6666666");
        Bigint h("77777777");
        Bigint i("888888888");


        // Verify
        assert(a == 0);
        assert(b == 11);
        assert(c == 222);
        assert(d == 3333);
        assert(e == 44444);
        assert(f == 555555);
        assert(g == 6666666);
        assert(h == 77777777);
        assert(i == 888888888);
   }


    std::cout << "Done testing constructor Bigint(const char[])." << std::endl;
    return 0;
}

