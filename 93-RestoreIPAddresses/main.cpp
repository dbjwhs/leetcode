#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// A valid IP address consists of exactly four integers separated by single dots. Each integer is
// between 0 and 255 (inclusive) and cannot have leading zeros.
//
// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312"
// and "192.168@1.1" are invalid IP addresses.
//
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by
// inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid
// IP addresses in any order.
//
//
//
// Example 1:
//
// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:
//
// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:
//
// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int strLen = s.length();

        if (strLen < 4 || strLen > 12) {
            return result;
        }

        for (int ndx = 0; ndx < strLen; ndx++) {
            for (int ndx2 = ndx + 1; ndx2 < strLen; ndx2++) {
                for (int ndx3 = ndx2 + 1; ndx3 < strLen; ndx3++) {
                    string nextOctA = s.substr(0, ndx);
                    if (isStringValid(nextOctA) == false) {
                        continue;
                    }
                    string nextOctB = s.substr(ndx, ndx2 - ndx);
                    if (isStringValid(nextOctB) == false) {
                        continue;
                    }
                    string nextOctC = s.substr(ndx2, ndx3 - ndx2);
                    if (isStringValid(nextOctC) == false) {
                        continue;
                    }
                    string nextOctD = s.substr(ndx3);
                    if (isStringValid(nextOctD) == false) {
                        continue;
                    }
                    result.push_back(nextOctA + "." + nextOctB + "." + nextOctC + "." + nextOctD);
                }
            }
        }

        //
        // for (auto nextCandiate : result) {
        //      cout << nextCandiate << endl;
        // }

        return result;
    }

    bool isStringValid(string s) {
        // each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
        if (s.empty() or s.length() > 3 or (s.length() != 1 and s[0] == '0') or stoi(s) > 255) {
            return false;
        }
        return true;
    }
};

void runTests() {
    Solution solution;

    {
        string s = "101023";
        vector<string> resultExpected = {"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"};
        vector<string> result = solution.restoreIpAddresses(s);
        assert(result == resultExpected && "Test 1 failed");
        std::cout << "Test 1 passed: " << std::endl;
    }

    {
        string s = "25525511135";
        vector<string> resultExpected = {"255.255.11.135", "255.255.111.35"};
        vector<string> result = solution.restoreIpAddresses(s);
        assert(result == resultExpected && "Test 2 failed");
        std::cout << "Test 2 passed: " << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
