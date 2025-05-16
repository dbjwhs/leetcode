#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getLongestSubsequence(const vector<string>& words, const vector<int>& groups) {
    // only one word, return it
    int wordSize = words.size();
    if (wordSize == 1) {
        return {words[0]};
    }

    // each possible index
    int maxLength = 0;
    vector<string> bestResult;
    for (int ndx = 0; ndx < wordSize; ++ndx) {
        vector<string> currentResult;
        currentResult.push_back(words[ndx]);
        int lastGroup = groups[ndx];

        // extend the subsequence
        for (int gdx = ndx + 1; gdx < wordSize; ++gdx) {
            if (groups[gdx] != lastGroup) {
                currentResult.push_back(words[gdx]);
                lastGroup = groups[gdx];
            }
        }

        // the best result if we found a longer subsequence
        if (currentResult.size() > maxLength) {
            maxLength = currentResult.size();
            bestResult = currentResult;
        }
    }
    return bestResult;
}

// Test the solution
void runTests() {
    // Test Case 1
    vector<string> words1 = {"e", "a", "b"};
    vector<int> groups1 = {0, 0, 1};
    vector<string> expected1a = {"e", "b"};
    vector<string> expected1b = {"a", "b"};
    auto result1 = getLongestSubsequence(words1, groups1);
    bool test1Success = (result1 == expected1a || result1 == expected1b) && result1.size() == 2;
    cout << "Test 1: " << (test1Success ? "PASSED" : "FAILED") << endl;
    cout << "  Got: ";
    for (const auto& s : result1) cout << s << " ";
    cout << endl;

    // Test Case 2
    vector<string> words2 = {"a", "b", "c", "d"};
    vector<int> groups2 = {1, 0, 1, 1};
    vector<string> expected2a = {"a", "b", "c"};
    vector<string> expected2b = {"a", "b", "d"};
    auto result2 = getLongestSubsequence(words2, groups2);
    bool test2Success = (result2 == expected2a || result2 == expected2b) && result2.size() == 3;
    cout << "Test 2: " << (test2Success ? "PASSED" : "FAILED") << endl;
    cout << "  Got: ";
    for (const auto& s : result2) cout << s << " ";
    cout << endl;

    // Test Case 3 - Edge case with single element
    vector<string> words3 = {"single"};
    std::vector<int> groups3 = {0};
    auto result3 = getLongestSubsequence(words3, groups3);
    bool test3Success = result3.size() == 1 && result3[0] == "single";

    // Test Case 4 - All same group
    std::vector<std::string> words4 = {"a", "b", "c", "d", "e"};
    vector<int> groups4 = {1, 1, 1, 1, 1};
    auto result4 = getLongestSubsequence(words4, groups4);
    bool test4Success = result4.size() == 1;
    cout << "Test 4: " << (test4Success ? "PASSED" : "FAILED") << endl;

    // Test Case 5 - Alternating groups
    vector<string> words5 = {"a", "b", "c", "d", "e"};
    vector<int> groups5 = {0, 1, 0, 1, 0};
    auto result5 = getLongestSubsequence(words5, groups5);
    bool test5Success = result5.size() == 5;
    cout << "Test 5: " << (test5Success ? "PASSED" : "FAILED") << endl;
}

int main() {
    runTests();
    return 0;
}