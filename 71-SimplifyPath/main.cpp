#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty() or (path.length() == 1 and path[0] == '/')) {
            return path;
        }

        vector<string> pathVec;
        string nextWord;
        for (int ndx = 0; ndx < path.length(); ndx++) {
            char nextToken = path[ndx];
            if (nextToken == '/' and ndx == 0) {
                pathVec.emplace_back("/");
                continue;
            }
            if (nextToken == '/') {
                if (!nextWord.empty()) {
                    pathVec.push_back(nextWord);
                    nextWord = "";
                }
                continue;
            }
            nextWord += nextToken;
        }
        if (!nextWord.empty()) {
            pathVec.push_back(nextWord);
        }
        path = buildPath(pathVec);
        return path;
    }

    string buildPath(vector<string> pathVec) {
        auto it = ranges::find(pathVec, ".");
        while (it != pathVec.end()) {
            pathVec.erase(it);
            it = ranges::find(pathVec, ".");
        }
        it = ranges::find(pathVec, "..");
        while (it != pathVec.end()) {
            pathVec.erase(it);
            if (it - 1 != pathVec.begin()) {
                pathVec.erase(it - 1);
            }
            it = ranges::find(pathVec, "..");
        }
        string result;
        for (int ndx = 0; ndx < pathVec.size(); ndx++) {
            result += pathVec[ndx];
            if (ndx != 0 and ndx != pathVec.size() - 1) {
                result += "/";
            }
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        string path = "/a/../../b/../c//.//";
        string expected = "/c";
        string result = solution.simplifyPath(path);
        assert(result == expected && "Test 0 failed");
        std::cout << "Test 0 passed: " << result << std::endl;
    }
    {
        string path = "/a/./b/../../c/";
        string expected = "/c";
        string result = solution.simplifyPath(path);
        assert(result == expected && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        string path = "/home/user/Documents/../Pictures";
        string expected = "/home/user/Pictures";
        string result = solution.simplifyPath(path);
        assert(result == expected && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
    {
        string path = "/home//foo/";
        string expected = "/home/foo";
        string result = solution.simplifyPath(path);
        assert(result == expected && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
    {
        string path = "/home/";
        string expected = "/home";
        string result = solution.simplifyPath(path);
        assert(result == expected && "Test 4 failed");
        std::cout << "Test 4 passed: " << result << std::endl;
    }
    {
        string path = "/../";
        string expected = "/";
        string result = solution.simplifyPath(path);
        assert(result == expected && "Test 5 failed");
        std::cout << "Test 5 passed: " << result << std::endl;
    }
    {
        string path = "/.../a/../b/c/../d/./";
        string expected = "/.../b/d";
        string result = solution.simplifyPath(path);
        assert(result == expected && "Test 6 failed");
        std::cout << "Test 6 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
