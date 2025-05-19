#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort by length; this allows us to use the first word as max we need to check
        sortByLength(strs);
        int maxLen = strs[0].length();

        string result;
        int strDex = 0;
        for (int ldx = 0; ldx < maxLen; ++ldx) {
            int ndx;
            for (ndx = 0; ndx < strs.size() - 1; ndx++) {
                if (strs[ndx][strDex] != strs[ndx + 1][strDex]) {
                    goto end_of_loops;
                }
            }
            result += strs[ndx][strDex++];
        }
        end_of_loops:
        return result;
    }

    void sortByLength(std::vector<std::string>& strings) {
        std::sort(strings.begin(), strings.end(),
            [](string& a, string& b) {
                return a.length() < b.length();
            });}

};

void runTests() {
    Solution solution;

    {
        vector<string> strs{"flower", "flow", "flight"};
        string result = solution.longestCommonPrefix(strs);
        assert(result == "fl" && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
