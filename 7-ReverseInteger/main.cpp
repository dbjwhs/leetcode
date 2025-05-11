#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }

        string str = to_string(x);
        unsigned int val = x;
        bool is_signed = false;
        if (val > numeric_limits<int>::max()) {
            is_signed = true;
            str.erase(0, 1);
        }

        unsigned int accum = 0;
        for (int ndx = 0; ndx < str.size(); ++ndx) {
            int next_factor = str[ndx] - '0';
            if (ndx == 9) {
                if (next_factor > 2) {
                    return 0;
                }
                if (next_factor == 2 && accum > 0x8CA6BFF) {
                    return 0;
                }
            }
            accum += pow(10, ndx) * next_factor;
        }

        // we can assign accum with not threat of overflow
        int result = accum;
        if (is_signed) {
            result = -result;
        }
        return result;
    }
};

// Test cases
void runTests() {
    Solution solution;

    {
        int result = solution.reverse(123);
        assert(result == 321 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }

    {
        int result = solution.reverse(1534236469);
        assert(result == 0 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }

    {
        int result = solution.reverse(-2147483648);
        assert(result == 0 && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }

    {
        int result = solution.reverse(-123);
        int expected = -321;
        assert(result == expected && "Test 4 failed");
        std::cout << "Test 4 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}