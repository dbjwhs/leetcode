#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// Given two binary strings a and b, return their sum as a binary string.
//
//
//
// Example 1:
//
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//
//
// Constraints:
//
// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result{};
        int strLen = stringPrep(a, b);
        bool carry = false;
        for (int ndx = 0; ndx < strLen; ndx++) {
            char nextCharA = ndx < a.size() ? a[ndx] : '0';
            char nextCharB = ndx < b.size() ? b[ndx] : '0';
            if (nextCharA == '1' && nextCharB == '1') {
                if (carry == true) {
                    result += "1";
                } else {
                    result += "0";
                    carry = true;
                }
            }
            else if (nextCharA == '1' || nextCharB == '1') {
                if (carry == true) {
                    result += "0";
                } else {
                    result += "1";
                }
            }
            else {
                if (carry == true) {
                    result += "1";
                } else {
                    result += "0";
                }
                carry = false;
            }
        }
        if (carry == true) {
            result += "1";
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int stringPrep(string& a, string& b) {
        int strLen = max(a.size(), b.size());
        if (a.size() < strLen) {
            a.insert(0, strLen - a.size(), '0');
        }
        if (b.size() < strLen) {
            b.insert(0, strLen - b.size(), '0');
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        return strLen;
    }
};

void runTests() {
    Solution solution;

    {
        string a{"11"};
        string b{"1"};
        string result = solution.addBinary(a, b);
        assert(result == "100" && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        string a{"1010"};
        string b{"1011"};
        string result = solution.addBinary(a, b);
        assert(result == "10101" && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
    {
        string a{"0"};
        string b{"0"};
        string result = solution.addBinary(a, b);
        assert(result == "0" && "Test 2 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
    {
        string a{"111"};
        string b{"1010"};
        string result = solution.addBinary(a, b);
        assert(result == "10001" && "Test 2 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}

// https://leetcode.com/problems/add-binary/description/