#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; ++num) {
            std::string numStr = std::to_string(num);
            int length = numStr.length();
            if (length % 2 == 0) {
                int halfLength = length / 2;
                int firstHalfSum = 0;
                int secondHalfSum = 0;
                for (int ndx = 0; ndx < halfLength; ++ndx) {
                    firstHalfSum += (numStr[ndx] - '0');
                }
                for (int ndx = halfLength; ndx < length; ++ndx) {
                    secondHalfSum += (numStr[ndx] - '0');
                }
                if (firstHalfSum == secondHalfSum) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    std::cout << std::format("{}", solution.countSymmetricIntegers(1, 100)) << std::endl;
    std::cout << std::format("{}", solution.countSymmetricIntegers(1200, 1230)) << std::endl;
    return 0;
}