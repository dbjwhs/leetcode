#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> romanTable{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}
            , {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };


        string result;
        while (num > 0) {
            if (num >= 1000) {
                result += romanTable[1000];
                num -= 1000;
            }
            else if (num >= 900) {
                result += romanTable[900];
                num -= 900;
            }
            else if (num >= 500) {
                result += romanTable[500];
                num -= 500;
            }
            else if (num >= 400) {
                result += romanTable[400];
                num -= 400;
            }
            else if (num >= 100) {
                result += romanTable[100];
                num -= 100;
            }
            else if (num >= 90) {
                result += romanTable[90];
                num -= 90;
            }
            else if (num >= 50) {
                result += romanTable[50];
                num -= 50;
            }
            else if (num >= 40) {
                result += romanTable[40];
                num -= 40;
            }
            else if (num >= 10) {
                result += romanTable[10];
                num -= 10;
            }
            else if (num >= 9) {
                result += romanTable[9];
                num -= 9;
            }
            else if (num >= 5) {
                result += romanTable[5];
                num -= 5;
            }
            else if (num >= 4) {
                result += romanTable[4];
                num -= 4;
            }
            else if (num >= 1) {
                result += romanTable[1];
                num -= 1;
            }
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        int num = 58;
        string result = solution.intToRoman(num);
        assert(result == "LVIII" && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }

    {
        int num = 3749;
        string result = solution.intToRoman(num);
        assert(result == "MMMDCCXLIX" && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }

    {
        int num = 1994;
        string result = solution.intToRoman(num);
        assert(result == "MCMXCIV" && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
