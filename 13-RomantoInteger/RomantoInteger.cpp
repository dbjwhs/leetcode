#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        vector<int> romanValue{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romanString{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for (int rdx = 0; rdx < s.size(); rdx++) {
            string chrStr{s[rdx]};
            if (rdx + 1 < s.size()) {
                string chrStrPeek;
                string nextChrStr{s[rdx + 1]};
                chrStrPeek = chrStr + nextChrStr;
                if (auto romanIt = ranges::find(romanString, chrStrPeek); romanIt != romanString.end()) {
                    result += romanValue[distance(romanString.begin(), romanIt)];
                    rdx++;
                    continue;
                }
            }
            for (int ndx = 0; ndx < romanString.size(); ndx++) {
                if (chrStr == romanString[ndx]) {
                    result += romanValue[ndx];
                    break;
                }
            }
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        int result = solution.romanToInt("MCMXCIV");
        assert(result == 1994 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
