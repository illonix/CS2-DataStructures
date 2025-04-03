//File:        string.hpp
//       
//Version:     1.1
//Date:        Spring 2025
//Author:      Jude Skrzat
//

#include "string.hpp"
#include <cassert>

String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = 0;
}

String::String(char ch) {
    if(ch == 0){
        stringSize = 1;
        str = new char[stringSize];
        str[0] = 0;
    } else {
        stringSize = 2;
        str = new char[stringSize];
        str[0] = ch;
        str[1] = 0;
    }
}

String::String(const char val[]) {
    int i = 0;
    while (val[i] != '\0') ++i;
        stringSize = i + 1;
        str = new char[stringSize];
    for (int j = 0; j < i; ++j) {
        str[j] = val[j];
    }
    str[i] = '\0';
}

String::String(const String& copy) {
    stringSize = copy.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < stringSize - 1; ++i) {
        str[i] = copy.str[i];
    }
    str[stringSize - 1] = '\0';
}

String::~String() {
    delete[] str;
}

void String::swap(String& rhs) {
    char *strTemp = str;
    str = rhs.str;
    rhs.str = strTemp;
    
    int sizeTemp = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = sizeTemp;
}

String& String::operator=(String rhs) {
    if (this != &rhs) {
        swap(rhs);
    }
    return *this;
}


int String::capacity() const { 
    return stringSize - 1; 
}

int String::length() const {
    int result = 0;
    while (str[result] != 0) ++result;
    return result;
}

char& String::operator[](int i) {
    assert(i >= 0);
    assert(i <= length());
    return str[i];
}

char String::operator[](int i) const {
    assert(i >= 0);
    assert(i <= length());
    return str[i];
}

String& String::operator+=(const String& rhs) {
    int oldLength = length();
    int newLength = oldLength + rhs.length();
    char* newStr = new char[newLength + 1];

    for (int i = 0; i < oldLength; ++i) {
        newStr[i] = str[i];
    }
    for (int j = 0; j < rhs.length(); ++j) {
        newStr[oldLength + j] = rhs.str[j];
    }

    newStr[newLength] = '\0';
    delete[] str;
    str = newStr;
    stringSize = newLength + 1;
    return *this;
}


bool String::operator==(const String& rhs) const {   //"hello world" != "hell0 world" 
    int i = 0;
    while (str[i] == rhs.str[i] && str[i] != '\0' && rhs.str[i] != '\0') {
        ++i;
    }
    return str[i] == rhs.str[i];
    }

bool String::operator<(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] < rhs.str[i];
}

String String::substr(int start, int end) const {
    String result;
    if (start < 0) start = 0;
    if (end >= length()) end = length() - 1;
    if (end < start) return result;

    for(int i = start; i <= end; ++i) {
        result += str[i];
    }
    return result;
}

int String::findch(int start, char ch) const {
    if (start < 0) start = 0;             // Prevent negative start index
    if (start >= length()) return -1;     // Out of bounds, return -1

    for (int i = start; str[i] != 0; ++i) {
        if (str[i] == ch) return i;       // Found character, return index
    }

    return -1; // Character not found
}


int String::findstr(int start, const String& subStr) const {
    if (start < 0 || start >= length()) {
        return -1;
    }

    int subLen = subStr.length();
    if (subLen == 0) return -1;

    for (int i = start; i <= length() - subLen; ++i) {
        int j = 0;
        while (j < subLen && str[i + j] == subStr[j]) {
            ++j;
        }
        if (j == subLen) {
            return i;
        }
    }

    return -1;
}

// Check if String is Empty
bool String::empty() const {
    return length() == 0;
}

std::vector<String> String::split(const char ch) const {
    int start = 0;
    int end = 0;

    std::vector<String> temp;
    while (end != -1) {
        end = findch(start, ch);

        if (start == end) {
            temp.push_back("");
        } else if (end != -1) {
            temp.push_back(substr(start, end - 1));
        }
        if (end == -1) {
            temp.push_back(substr(start, length()));
        }

        start = end + 1;
    }
    return temp;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    int i = 0;
    while (rhs.str[i] != 0) {
        out << rhs.str[i];
        ++i;
    }
    return out;
}

// Input Stream Operator
std::istream& operator>>(std::istream& in, String& rhs) {
    char buff[1000];  // assuming a large enough buffer
    in >> buff;
    rhs = String(buff);
    return in;
}


String operator+(String lhs, const String& rhs) {
    return lhs += rhs;
}

bool operator==(const char lhs[], const String& rhs) { return rhs == lhs; }
bool operator==(char lhs,         const String& rhs) { return rhs == lhs; }
bool operator<(const char lhs[],  const String& rhs) { return String(lhs) <  rhs; }
bool operator<(char lhs,          const String& rhs) { return String(lhs) <  rhs; }

bool operator<=(const String& lhs, const String& rhs) { return !(rhs < lhs); }
bool operator!=(const String& lhs, const String& rhs) { return !(rhs == lhs); }
bool operator>=(const String& lhs, const String& rhs) { return !(rhs > lhs); }
bool operator>(const String& lhs, const String& rhs) { return rhs < lhs; }

// Getline Function
std::istream& getline(std::istream& in, String& str) {
    char buffer[1024];
    if (in.getline(buffer, 1024)) {
        str = String(buffer);
    } else {
        str = String("");
    }
    return in;
}
int String::toInt() const {
    int result = 0;
    int i = 0;
    bool isNegative = false;

    if (str[0] == '-') { // Handle negative numbers
        isNegative = true;
        i = 1;
    }

    for (; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            return 0; // Invalid number, return 0
        }
    }

    return isNegative ? -result : result;
}
