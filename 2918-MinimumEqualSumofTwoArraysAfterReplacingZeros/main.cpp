#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

class Solution {
public:
    long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
        long long sumNum1 = 0, sumNum2 = 0;
        int sumZero1 = 0, sumZero2 = 0;

        // sums and number of zeros in each array
        numZerosNumSum(nums1, sumNum1, sumZero1);
        numZerosNumSum(nums2, sumNum2, sumZero2);

        // check if sums already be equal
        if (sumZero1 == 0 && sumZero2 == 0) {
            return (sumNum1 == sumNum2) ? sumNum1 : -1;
        }

        // nums1 has no zeros
        if (sumZero1 == 0) {
            return (sumNum1 >= sumNum2 + sumZero2) ? sumNum1 : -1;
        }

        // nums2 has no zeros
        if (sumZero2 == 0) {
            return (sumNum2 >= sumNum1 + sumZero1) ? sumNum2 : -1;
        }

        // both arrays have zeros
        return std::max(sumNum1 + sumZero1, sumNum2 + sumZero2);
    }

    void numZerosNumSum(const std::vector<int>& nums, long long& sum, int& zeros) {
        for (const int num : nums) {
            sum += num;
            zeros += (num == 0);
        }
    }
};

// Test cases
void runTests() {
    Solution solution;

    {
        std::vector<int> nums1 = {3, 2, 0, 1, 0};
        std::vector<int> nums2 = {6, 5, 0};
        long long expected = 12;
        long long result = solution.minSum(nums1, nums2);
        assert(result == expected && "Example 1 failed");
        std::cout << "Example 1 passed: " << result << std::endl;
    }

    {
        std::vector<int> nums1 = {2, 0, 2, 0};
        std::vector<int> nums2 = {1, 4};
        long long expected = -1;
        long long result = solution.minSum(nums1, nums2);
        assert(result == expected && "Example 2 failed");
        std::cout << "Example 2 passed: " << result << std::endl;
    }

    // both arrays with just zeros
    {
        std::vector<int> nums1 = {0};
        std::vector<int> nums2 = {0};
        long long expected = 1; // Both arrays would have sum 1
        long long result = solution.minSum(nums1, nums2);
        assert(result == expected && "Both arrays with just zeros test failed");
        std::cout << "Both zeros test passed: " << result << std::endl;
    }

    {
        std::vector<int> nums1 = {1, 0};
        std::vector<int> nums2 = {2};
        long long expected = 2; // Can make sums equal (1 + 1 = 2)
        long long result = solution.minSum(nums1, nums2);
        assert(result == expected && "Can make equal with zeros test failed");
        std::cout << "Can make equal test passed: " << result << std::endl;
    }

    // increase
    {
        std::vector<int> nums1 = {2};
        std::vector<int> nums2 = {1, 0};
        long long expected = 2; // Can increase sum2 to match sum1
        long long result = solution.minSum(nums1, nums2);
        assert(result == expected && "Can increase to match test failed");
        std::cout << "Can increase test passed: " << result << std::endl;
    }

    // equal sums with no zeros
    {
        std::vector<int> nums1 = {5, 5};
        std::vector<int> nums2 = {10};
        long long expected = 10; // Already equal
        long long result = solution.minSum(nums1, nums2);
        assert(result == expected && "Equal sums with no zeros test failed");
        std::cout << "Equal sums test passed: " << result << std::endl;
    }

    // impossible due to sum mismatch
    {
        std::vector<int> nums1 = {3, 0};
        std::vector<int> nums2 = {2};
        long long expected = -1; // Cannot make equal (3+1 > 2)
        long long result = solution.minSum(nums1, nums2);
        assert(result == expected && "Impossible due to sum mismatch test failed");
        std::cout << "Impossible test passed: " << result << std::endl;
    }

    // try large numbers
    {
        std::vector<int> nums1 = {9999999, 0, 0};
        std::vector<int> nums2 = {999991, 0};
        long long expected = 10000001;
        long long result = solution.minSum(nums1, nums2);
        assert(result == expected && "Large numbers test failed");
        std::cout << "Large numbers test passed: " << result << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}