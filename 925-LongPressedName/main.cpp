#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isLongPressedName(const std::string& name, const std::string& typed) {
        int nameDex = 0;
        int typedDex = 0;

        while (nameDex < name.length() && typedDex < typed.length()) {
            if (name[nameDex] != typed[typedDex]) {
                return false;
            }

            char currentChar = name[nameDex];
            int nameCount = 0;
            int typedCount = 0;
            while (nameDex < name.length() && name[nameDex] == currentChar) {
                nameCount++;
                nameDex++;
            }

            while (typedDex < typed.length() && typed[typedDex] == currentChar) {
                typedCount++;
                typedDex++;
            }

            if (typedCount < nameCount) {
                return false;
            }
        }
        return nameDex == name.length() && typedDex == typed.length();
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
