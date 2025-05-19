#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> balanceStack;
        for (const auto& nextBracket : s) {
            if (nextBracket=='(' || nextBracket=='{' || nextBracket=='[') {
                balanceStack.push(nextBracket);
            } else {
                if (balanceStack.empty()
                    || (balanceStack.top() == '(' && nextBracket != ')')
                    || (balanceStack.top() == '{' && nextBracket != '}')
                    || (balanceStack.top() == '[' && nextBracket != ']')) {
                    return false;
                }
                balanceStack.pop();
            }
        }
        return balanceStack.empty();
    }
};

void runTests() {
    Solution solution;

    {
        string test = "()";
        bool result = solution.isValid(test);
        assert(result && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        string test = "()[]{}";
        bool result = solution.isValid(test);
        assert(result && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
    {
        string test = "(]";
        bool result = solution.isValid(test);
        assert(result == false && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
    {
        string test = "([])";
        bool result = solution.isValid(test);
        assert(result && "Test 4 failed");
        std::cout << "Test 4 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
