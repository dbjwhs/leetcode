#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> powerVector;

        // first try to find the power of 3 as a native value and build a vector of powers of 3 that are less that our
        // our passed in value
        int val = 0;
        while (true) {
            int nextPow = pow(3, val++);
            if (nextPow == n) {
                return true;
            }
            if (nextPow < n) {
                powerVector.push_back(nextPow);
            } else {
                break;
            }
        }

        // we did not find him off the bat, so we will not barbarically recurse through all possible values
        vector<int> allPossibleValues = generateSubsetSumsRecursive(powerVector);
        return find(allPossibleValues.begin(), allPossibleValues.end(), n) != powerVector.end();
    }

    void generateRecursiveHelper(vector<int>& powerMap, int index, int currentSum, vector<int>& subsetSums) {
        if (index == powerMap.size()) {
            subsetSums.push_back(currentSum);
            return;
        }

        // Exclude current element
        generateRecursiveHelper(powerMap, index + 1, currentSum, subsetSums);

        // Include current element
        generateRecursiveHelper(powerMap, index + 1, currentSum + powerMap[index], subsetSums);
    }

    vector<int> generateSubsetSumsRecursive(vector<int>& powerMap) {
        vector<int> subsetSums;
        generateRecursiveHelper(powerMap, 0, 0, subsetSums);
        sort(subsetSums.begin(), subsetSums.end());
        return subsetSums;
    }
};

void runTests() {
    Solution solution;

    {
        int n = 91;
        bool result = solution.checkPowersOfThree(n);
        assert(result == true && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        int n = 21;
        bool result = solution.checkPowersOfThree(n);
        assert(result == false && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
