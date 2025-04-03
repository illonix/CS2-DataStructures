#include "string.hpp"
#include <cassert>
#include <iostream>
#include <vector>

int main() {
    // Test case 1: Basic split with spaces
    String s1("abc ef gh");
    std::vector<String> result1 = s1.split(' ');
    assert(result1.size() == 3);
    assert(result1[0] == "abc");
    assert(result1[1] == "ef");
    assert(result1[2] == "gh");

    // Test case 2: Split with '-' resulting in empty strings
    String s2("-a--b-");
    std::vector<String> result2 = s2.split('-');
    assert(result2.size() == 5);
    assert(result2[0] == "");
    assert(result2[1] == "a");
    assert(result2[2] == "");
    assert(result2[3] == "b");
    assert(result2[4] == "");

    // Test case 3: Split an empty string
    String s3("");
    std::vector<String> result3 = s3.split(' ');
    assert(result3.size() == 1);
    assert(result3[0] == ""); // Splitting an empty string should give one empty string

    // Test case 4: Single character split by itself
    String s4("a");
    std::vector<String> result4 = s4.split('a');
    assert(result4.size() == 2);
    assert(result4[0] == ""); // The character matches, so the result is two empty strings
    assert(result4[1] == "");

    // Test case 5: No delimiters present in the string
    String s5("abc");
    std::vector<String> result5 = s5.split(' ');
    assert(result5.size() == 1);
    assert(result5[0] == "abc"); // No spaces, so the whole string should be returned

    // Test case 6: String with only delimiters
    String s6("-----");
    std::vector<String> result6 = s6.split('-');
    assert(result6.size() == 6);
    for (const auto& str : result6) {
        assert(str == ""); // All parts should be empty since the string is only delimiters
    }

    // Additional Test case 7: String with multiple different characters and a delimiter in between
    String s7("word1,word2,word3");
    std::vector<String> result7 = s7.split(',');
    assert(result7.size() == 3);
    assert(result7[0] == "word1");
    assert(result7[1] == "word2");
    assert(result7[2] == "word3");


    // Additional Test case 9: String where delimiter is not present at all
    String s9("nodelimitershere");
    std::vector<String> result9 = s9.split(',');
    assert(result9.size() == 1);
    assert(result9[0] == "nodelimitershere");

    // Additional Test case 10: String with repeated characters and splitting on that character
    String s10("xxxx");
    std::vector<String> result10 = s10.split('x');
    assert(result10.size() == 5);
    assert(result10[0] == "");
    assert(result10[1] == "");
    assert(result10[2] == "");
    assert(result10[3] == "");
    assert(result10[4] == "");

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
