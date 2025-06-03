#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// Given a string s, return the longest palindromic substring in s.
//
//
//
// Example 1:
//
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:
//
// Input: s = "cbbd"
// Output: "bb"
//



using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLen = start + 1;

        for (int ndx = 0; ndx < static_cast<int>(s.length()); ++ndx) {
            // check for odd-length palindromes (center at ndx)
            int len1 = expandAroundCenter(s, ndx, ndx);

            // check for even-length palindromes (center between ndx and ndx + 1)
            int len2 = expandAroundCenter(s, ndx, ndx + 1);

            if (const int currentMax = max(len1, len2); currentMax > maxLen) {
                maxLen = currentMax;
                start = ndx - (currentMax - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

    int expandAroundCenter(const string& s, int left, int right) {
        int sLen = s.length();
        while (left >= 0
            && right < sLen
            && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};

void runTests() {
    Solution solution;

    {
        string s = "babad";
        string result = solution.longestPalindrome(s);
        assert(result == "bab" || result == "aba" && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        string s = "cbbd";
        string result = solution.longestPalindrome(s);
        assert(result == "bb" && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
