// File:  bigint.cpp
//
// Programmer:  Jude Skrzat
// Description: Definition for Bigint ADT.
//              
//

#include "bigint.hpp"
#include <iostream>

Bigint::Bigint() {
    for(int i = 0; i < CAPACITY; ++i){
        array[i] = 0;
    }
}

Bigint::Bigint(int val) : Bigint() {
    for(int i = 0; i < CAPACITY; ++i){
        array[i] = val % 10;
        val /= 10;
    }
}

Bigint::Bigint(const char val[]) : Bigint() {
    int strSize = 0;
    while(val[strSize] != 0) {
        ++strSize;
    }

    int strIndex = strSize - 1;
    
    for(int i = 0; i < strSize; ++i) {
        array[i] = val[strIndex] - '0';
        --strIndex;
    }
}


void Bigint::debugPrint(std::ostream& out) const {
     for (int i = CAPACITY - 1; i >= 0; --i) { 
        out << array[i] << "|";
    }
}



bool Bigint::operator==(const Bigint& rhs) const {
    for(int i = 0; i < CAPACITY; ++i){
        if(array[i] != rhs.array[i])
        return false;
    }
    return true;
}

bool operator==(int lhs, const Bigint& rhs) {
    return Bigint(lhs) == rhs;
}

bool operator==(const char lhs[], const Bigint& rhs) {
    return Bigint(lhs) == rhs;
}

std::ostream& operator<<(std::ostream& out, const Bigint& rhs) {
    bool leadingZero = true;
    int count = 0;
    for (int i = CAPACITY - 1; i >= 0; --i) {  // Print from most significant digit to least
        if (rhs.array[i] != 0 || !leadingZero || i == 0) {
            out << rhs.array[i];
            ++count;
            leadingZero = false;  // Stop skipping leading zeros once we print a nonzero digit
        }
    }
        if(count == 100) {
        out << std::endl;
        count = 0;
        }


    return out;
}

std::istream& operator>>(std::istream& in, Bigint& rhs) {
    char ch;
    int index = CAPACITY - 1;  // Start from the least significant position

    // Reset the array to 0s
    for (int i = 0; i < CAPACITY; ++i) {
        rhs.array[i] = 0;
    }

    // Read characters one by one until ';' is encountered
    while (in.get(ch) && ch != ';') {
        // Ensure the character is a digit
        if (ch >= '0' && ch <= '9') {
            for(int i = index; i >= 0; --i){
            rhs.array[i] = rhs.array[i - 1]; 
            }
            rhs.array[0] = ch - '0';
        }
    }

    return in;
}

Bigint Bigint::operator+(const Bigint& rhs) const {
    Bigint result;  // New Bigint to store the sum
    int carry = 0;

    for (int i = 0; i < CAPACITY; ++i) {
        int sum = array[i] + rhs.array[i] + carry;
        result.array[i] = sum % 10;  // Store the digit
        carry = sum / 10;  // Update the carry
    }

    return result;
}

Bigint Bigint::timesDigit(int val) const {
    Bigint result;
    int carry = 0;

    for (int i = 0; i < CAPACITY; ++i) {
        int product = (array[i] * val) + carry;
        result.array[i] = product % 10;
        carry = product / 10;
    }
    return result;
}

Bigint Bigint::times10(int val) const {
    Bigint temp;
    for(int i = 0; i < CAPACITY; ++i) {
        temp.array[i + val] = array[i];
    }
    for(int i = 0; i < val; ++i) {
        temp.array[i] = 0;
    }
    return temp;
}

Bigint Bigint::operator*(const Bigint& rhs) const {
    Bigint product = 0;
    for(int i = 0; i < CAPACITY; ++i) {
        if(rhs.array[i] == 0) {
            continue;
        }
        Bigint temp = this->timesDigit(rhs.array[i]);
        temp = temp.times10(i);
        product = product + temp;
    }
    return product;
}


