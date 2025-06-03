#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        unordered_set<int> hasKeys;         // keys we have
        unordered_set<int> hasBoxes;        // boxes we have (but may not be able to open)
        unordered_set<int> processedBoxes;  // boxes we've already processed
        queue<int> canOpen;                 // boxes we can currently open

        // Initialize with initial boxes
        for (int box : initialBoxes) {
            hasBoxes.insert(box);
            if (status[box] == 1) {  // Box is already open
                canOpen.push(box);
            }
        }

        int totalCandies = 0;

        // process all openable boxes
        while (!canOpen.empty()) {
            int currentBox = canOpen.front();
            canOpen.pop();

            // skip if already processed
            if (processedBoxes.contains(currentBox)) {
                continue;
            }

            // mark as processed and remove from hasBoxes
            processedBoxes.insert(currentBox);
            hasBoxes.erase(currentBox);

            // collect candies from the current box
            totalCandies += candies[currentBox];

            // collect keys from the current box
            for (int key : keys[currentBox]) {
                hasKeys.insert(key);
            }

            // collect contained boxes
            for (int box : containedBoxes[currentBox]) {
                hasBoxes.insert(box);
            }

            // check if any boxes we have can now be opened
            for (int box : hasBoxes) {
                if (!processedBoxes.contains(box) && (status[box] == 1 || hasKeys.contains(box))) {
                    canOpen.push(box);
                }
            }
        }
        return totalCandies;
    }
};


void runTests() {
    Solution solution;

    {
        vector<int> status = {1,0,1,0};
        vector<int> candies = {7,5,4,100};
        vector<vector<int>> keys = {{},{},{1},{}};
        vector<vector<int>> containedBoxes = {{1,2},{3},{},{}};
        vector<int> initialBoxes = {0};
        int result = solution.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
        assert(result == 16 && "Test 1 failed");
        cout << "Test 1 passed: " << result << endl;
    }
    {
        vector<int> status = {1,0,0,0,0,0};
        vector<int> candies = {1,1,1,1,1,1};
        vector<vector<int>> keys = {{1,2,3,4,5},{},{},{}, {}, {}};
        vector<vector<int>> containedBoxes = {{1,2,3,4,5},{3},{},{}, {}, {}, {}};
        vector<int> initialBoxes = {0};
        int result = solution.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
        assert(result == 6 && "Test 1 failed");
        cout << "Test 1 passed: " << result << endl;
    }
}

int main() {
    runTests();
    cout << "All Tests Passed" << endl;
    return 0;
}
