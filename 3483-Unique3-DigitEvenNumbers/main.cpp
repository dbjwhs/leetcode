#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int totalNumbers(const vector<int>& digits) {
        unordered_set<int> unique_digits;

        for (size_t i = 0; i < digits.size(); ++i) {
            // if 0 not a valid 3 digit number
            if (digits[i] == 0) {
                continue;
            }
            for (size_t j = 0; j < digits.size(); ++j) {
                if (j == i) {
                    continue;
                }
                for (size_t k = 0; k < digits.size(); ++k) {
                    if (k == i || k == j) {
                        continue;
                    }

                    // if even this is our next number
                    if (digits[k] % 2 == 0) {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        unique_digits.insert(num);
                    }
                }
            }
        }
        return unique_digits.size();
    }
};

void runTests() {
    Solution solution;
    {
        vector<int> digits = {1,2,3,4};
        int result = solution.totalNumbers(digits);
        assert(result == 12 && "Test 1 failed");
        cout << "Test 1 passed: " << endl;
    }
}

int main() {
    runTests();
    cout << "All Tests Passed" << endl;
    return 0;
}
