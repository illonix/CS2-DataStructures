// Bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        Bigint left(0);
        Bigint right(0);
        Bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(1);
      Bigint right(0);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(1);
      Bigint right(1);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(13);
      Bigint right(14);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 13);
      assert(right  == 14);
      assert(result == 27);
    }

      {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(134234);
      Bigint right(16234);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 134234);
      assert(right  == 16234);
      assert(result == 150468);
    }

     {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(9);
      Bigint right(12);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 12);
      assert(result == 21);
    }
      {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(9);
      Bigint right(1);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 1);
      assert(result == 10);
    }
      {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(23);
      Bigint right(47);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 23);
      assert(right  == 47);
      assert(result == 70);
    }
      {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(2);
      Bigint right(9);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 2);
      assert(right  == 9);
      assert(result == 11);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(24);
      Bigint right(26);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 24);
      assert(right  == 26);
      assert(result == 50);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      Bigint left(2000111);
      Bigint right(923426);
      Bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 2000111);
      assert(right  == 923426);
      assert(result == 2923537);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      Bigint left("987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
      Bigint right("123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789");
      Bigint result;
  
      // Test
      result = left + right;
  
      // Verify
      assert(left == "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
      assert(right == "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789");
      assert(result == "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110");
  }
  



    
    //Add test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

