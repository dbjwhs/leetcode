#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string inputToStr = this->bitsetToString(n);
        string resultStr = inputToStr;
        int ndx = inputToStr.length() - 1;
        for (char c : inputToStr) {
            resultStr[ndx] = c;
            --ndx;
        }
        return this->createFromBitset(resultStr);
    }

    uint32_t createFromBitset(string strVal) {
        bitset<32> bits(strVal);
        return static_cast<uint32_t>(bits.to_ulong());
    }

    string bitsetToString(uint32_t value) {
        bitset<32> bits(value);
        return bits.to_string();
    }
};

void runTests() {
    Solution solution;

    {
        uint32_t n = solution.createFromBitset("00000010100101000001111010011100");
        uint32_t result = solution.reverseBits(n);
        string resultStr = solution.bitsetToString(result);
        string expectedResultStr = solution.bitsetToString(964176192);
        assert(resultStr == expectedResultStr && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
