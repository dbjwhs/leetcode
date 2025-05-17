#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> romanValue{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romanString{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result;
        for (int ndx = 0; ndx < romanValue.size(); ndx++) {
            while (num >= romanValue[ndx]) {
                result += romanString[ndx];
                num -= romanValue[ndx];
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
        assert(result == "MCMXCIV" && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
