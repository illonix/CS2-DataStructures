// File:  bigint.hpp
//
// Programmer:  Jude Skrzat
// Description: Definition for Bigint ADT.
//              
//

#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP

#include <iostream>

const int CAPACITY = 300;

class Bigint{
    public:

        Bigint ();
        Bigint (int);
        Bigint (const char[]);

        void debugPrint (std::ostream&) const;
        bool operator== (const Bigint&) const;
        bool operator== (const char[] ) const;
        bool operator== (int          ) const;

        friend std::ostream& operator<< (std::ostream&, const Bigint&);
        friend std::istream& operator>> (std::istream&,       Bigint&);
         
        Bigint operator+  (const Bigint&) const;
        int    operator[] (int i)         const { return array[i]; }
        Bigint timesDigit (int  )         const;
        Bigint times10    (int  )         const;
        Bigint operator*  (const Bigint&) const;

        

    private:
        int array[CAPACITY];
        
};

bool operator== (      int,  const Bigint&);
bool operator== (const char, const Bigint&);

#endif