#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(const vector<int>& digits) {
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
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (digits[k] % 2 == 0 && unique_digits.find(num) == unique_digits.end()) {
                        unique_digits.insert(num);
                    }
                }
            }
        }
        std::vector<int> result(unique_digits.begin(), unique_digits.end());
        std::sort(result.begin(), result.end());
        return result;
    }
};


void runTests() {
    Solution solution;

    {
        vector<int> digits = {2,1,3,0};
        vector<int> expected = {102,120,130,132,210,230,302,310,312,320};
        vector<int> result = solution.findEvenNumbers(digits);
        assert(result == expected && "Test 1 failed");
        cout << "Test 1 passed: " << endl;
    }
}

int main() {
    runTests();
    cout << "All Tests Passed" << endl;
    return 0;
}
