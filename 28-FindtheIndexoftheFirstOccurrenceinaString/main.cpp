#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        if (needle == haystack) {
            return 0;
        }
        int matched_index = -1;
        for (int hdx = 0; hdx < haystack.size(); ++hdx) {
            matched_index = hdx;
            for (int ndx = 0; ndx < needle.size(); ++ndx) {
                if (needle[ndx] != haystack[hdx + ndx]) {
                    matched_index = -1;
                    break;
                }
            }
            if (matched_index != -1) {
                break;
            }
        }
        return matched_index;
    }
};

void runTests() {
    Solution solution;

    {
        string haystack = "leetcode";
        string needle = "leeto";
        int result = solution.strStr(haystack, needle);
        assert(result == -1 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }

    {
        string haystack = "sadbutsad";
        string needle = "sad";
        int result = solution.strStr(haystack, needle);
        assert(result == 0 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }

    {
        string haystack = "hello";
        string needle = "ll";
        int result = solution.strStr(haystack, needle);
        assert(result == 2 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}

https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/