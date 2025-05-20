// this was too easy, I did it in the leetcode web IDE
//https://leetcode.com/problems/regular-expression-matching/description/

class Solution {
public:
    bool isMatch(string s, string p) {
        regex pattern(p);
        return regex_match(s, pattern);
    }
};