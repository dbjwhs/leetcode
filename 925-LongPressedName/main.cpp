#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        bool result = true;
        int tdx = 0;
        for (int ndx = 0; ndx < name.length(); ++ndx) {
            if (name[ndx] != typed[tdx]) {
                result = false;
                break;
            }
            ++tdx;
            if (ndx < name.length() - 1 && name[ndx + 1] == typed[tdx]) {
                continue;
            }
            while (name[ndx] == typed[tdx]) {
                ++tdx;
            }
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        string name = "leelee";
        string typed = "lleeelee";
        bool result = solution.isLongPressedName(name, typed);
        assert(result == true && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        string name = "alex";
        string typed = "aaleex";
        bool result = solution.isLongPressedName(name, typed);
        assert(result == true && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
