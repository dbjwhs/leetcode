#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> vec;

        int subCnt = 0, longestSubCnt = 0;
        for (auto c : s) {
            auto it = find(vec.begin(), vec.end(), c);
            if (it != vec.end()) {
                int vecDis = distance(vec.begin(), it);
                vec.erase(vec.begin(), vec.begin() + vecDis + 1);
                subCnt -= vecDis + 1;
            }
            vec.push_back(c);
            subCnt++;
            if (subCnt > longestSubCnt) {
                longestSubCnt = subCnt;
            }
        }
        return longestSubCnt;
    }
};

void runTests() {
    Solution solution;

    {
        int result = solution.lengthOfLongestSubstring("abcabcbb");
        assert(result == 3 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        int result = solution.lengthOfLongestSubstring("bbbbb");
        assert(result == 1 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
    {
        int result = solution.lengthOfLongestSubstring("pwwkew");
        assert(result == 3 && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
    {
        int result = solution.lengthOfLongestSubstring(" ");
        assert(result == 1 && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
    {
        int result = solution.lengthOfLongestSubstring("");
        assert(result == 0 && "Test 4 failed");
        std::cout << "Test 4 passed: " << result << std::endl;
    }
    {
        int result = solution.lengthOfLongestSubstring("abcdefghidxapl890px3");
        assert(result == 3 && "Test 5 failed");
        std::cout << "Test 5 passed: " << result << std::endl;
    }
    // {
    //     int result = solution.lengthOfLongestSubstring("dvdf");
    //     assert(result == 3 && "Test 5 failed");
    //     std::cout << "Test 5 passed: " << result << std::endl;
    // }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
