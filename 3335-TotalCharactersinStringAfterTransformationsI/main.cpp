#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // prevent overflow
        int trim_mod = 1e9 + 7;
        // init main vector with initial string
        int alpahbet_size = 26;
        vector<long long> str_vec_accum(alpahbet_size, 0);
        for (auto ch : s) {
            int ch_idx = ch - 'a';
            str_vec_accum[ch_idx]++;
        }

        // iterate transformations
        while (t--) {
            vector<long long> str_vec_trans(alpahbet_size, 0);
            int alpahbet_ndx_z = alpahbet_size - 1;
            for (int ndx = 0; ndx < alpahbet_ndx_z; ndx++) {
                str_vec_trans[ndx + 1] = (str_vec_trans[ndx + 1] + str_vec_accum[ndx]) % trim_mod;
            }

            // handle 'z' case roll over to "ab"
            str_vec_trans[0] = (str_vec_trans[0] + str_vec_accum[alpahbet_ndx_z]) % trim_mod;
            str_vec_trans[1] = (str_vec_trans[1] + str_vec_accum[alpahbet_ndx_z]) % trim_mod;

            // init for new transformation
            str_vec_accum = str_vec_trans;
        }
        // generate count and return
        int cnt = 0;
        for (int i = 0; i < alpahbet_size; i++) {
            cnt = (cnt + str_vec_accum[i]) % trim_mod;
        }
        return cnt;
    }
};

void runTests() {
    Solution solution;

    {
        int result = solution.lengthAfterTransformations("abcyy", 2);
        assert(result == 7 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }

    {
        int result = solution.lengthAfterTransformations("azbk", 1);
        assert(result == 5 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }

    {
        int result = solution.lengthAfterTransformations("jqktcurgdvlibczdsvnsg", 7517);
        assert(result == 79033769 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
