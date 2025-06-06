// 2410. Maximum Matching of Players With Trainers
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
//
// The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
//
// Return the maximum number of matchings between players and trainers that satisfy these conditions.
//
//
//
// Example 1:
//
// Input: players = [4,7,9], trainers = [8,2,5,8]
// Output: 2
// Explanation:
// One of the ways we can form two matchings is as follows:
// - players[0] can be matched with trainers[0] since 4 <= 8.
// - players[1] can be matched with trainers[3] since 7 <= 8.
// It can be proven that 2 is the maximum number of matchings that can be formed.
// Example 2:
//
// Input: players = [1,1,1], trainers = [10]
// Output: 1
// Explanation:
// The trainer can be matched with any of the 3 players.
// Each player can only be matched with one trainer, so the maximum answer is 1.
//

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int> players, std::vector<int> trainers) {
        // sort both arrays to enable greedy matching
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());

        int matchings = 0;
        int trainerIndex = 0;

        // for each player (starting with lowest skill)
        for (int player : players) {
            // find the first available trainer who can handle this player
            while (trainerIndex < trainers.size() && trainers[trainerIndex] < player) {
                trainerIndex++;
            }

            // if we found a suitable trainer, make the match
            if (trainerIndex < trainers.size()) {
                matchings++;

                // this trainer is now used
                trainerIndex++;
            }
        }
        return matchings;
    }
};

void runTests() {
    Solution solution;

    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};
    {

        int result = solution.matchPlayersAndTrainers(players, trainers);
        assert(result == 2 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
