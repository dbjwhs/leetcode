#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, char> alienAplhaMap;
        this->setUpAlphabetMap(alienAplhaMap, order);
        for (auto& word : words) {
            for (auto& ch : word) {
                ch = alienAplhaMap[ch];
            }
        }
        return is_sorted(words.begin(), words.end());;
    }
    void setUpAlphabetMap(map<char, char>& alienAplhaMap, string order) {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (int ndx = 0; ndx < order.length(); ndx++) {
            alienAplhaMap[order[ndx]] = alphabet[ndx];
        }
    }
};
void runTests() {
    Solution solution;

    {
        vector<string> words = {"hello", "leetcode"};
        string order = "hlabcdefgijkmnopqrstuvwxyz";
        bool result = solution.isAlienSorted(words, order);
        assert(result == true && "Test 2 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
