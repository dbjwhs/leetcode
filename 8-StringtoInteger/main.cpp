#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <optional>
#include <limits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // remove spaces
        string cleanString = trim_leading(s);

        // determine sign-ness (-,+ valid)
        bool isNegative = false;
        if (cleanString[0] == '-' or cleanString[0] == '+') {
            cleanString[0] == '-' ? isNegative = true : isNegative = false;
            cleanString.erase(cleanString.begin());
        }

        // read till none digit char
        for (int ndx = 0; ndx < cleanString.size(); ndx++) {
            if (cleanString[ndx] < '0' or cleanString[ndx] > '9') {
                cleanString.erase(cleanString.begin() + ndx, cleanString.end());
                break;
            }
        }

        // process clean pure string
        int result = 0;
        for (int ndx = 0; ndx < cleanString.size(); ndx++) {
            // check for overflow before performing the multiplication
            if (result > INT_MAX / 10) {
                result = isNegative ? INT_MIN : INT_MAX;
                break;
            }

            // multiply safely since we've verified it won't overflow
            result = result * 10;

            // Check for overflow before performing the addition
            int digit = cleanString[ndx] - '0';
            if (result > INT_MAX - digit) {
                result = isNegative ? INT_MIN : INT_MAX;
                break;
            }

            // Add safely since we've verified it won't overflow
            result = result + digit;
        }

        if (isNegative and result != INT_MIN) {
            result = -result;
        }

        return result;
    }

    string trim_leading(std::string s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        return s;
    }
};
//https://leetcode.com/problems/string-to-integer-atoi/description/

void runTests() {
    Solution solution;

    {
        int result = solution.myAtoi("  -42w2");
        assert(result == -42 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }

    {
        int result = solution.myAtoi("-91283472332");
        assert(result == INT_MIN && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
