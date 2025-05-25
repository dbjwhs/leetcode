#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;

        for (int ndx = 0; ndx <= n; ++ndx) {
            result.push_back(numBits(ndx));
        }
        return result;
    }

    int numBits(int val) {
        int result  = 0;

        while (val != 0) {
            val = val &= val - 1;
            ++result;
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        vector<int> expectedResult{0,1,1};
        vector<int> result = solution.countBits(2);
        assert(result == expectedResult && "Test 1 failed");
        std::cout << "Test 1 passed" << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
