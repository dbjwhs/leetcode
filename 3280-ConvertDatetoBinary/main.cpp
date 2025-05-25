#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        string result;
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        result += binToStr(year);
        result += "-";
        result += binToStr(month);
        result += "-";
        result += binToStr(day);
        return result;
    }
    string binToStr(int n) {
        string result;

        while (n > 0) {
            result.push_back(n % 2 + '0');
            n /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


void runTests() {
    Solution solution;

    {
        string date = "2080-02-29";
        string expectedResult = "100000100000-10-11101";
        string result = solution.convertDateToBinary(date);
        assert(result == expectedResult && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
