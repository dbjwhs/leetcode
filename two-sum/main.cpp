#include <iostream>
#include <vector>
#include <format>

std::string vec_to_string(const std::vector<int>& vec) {
    std::string result = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        result += std::to_string(vec[i]);
        if (i < vec.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int size = nums.size();
        for (int ndx = 0; ndx < size - 1; ++ndx) {
            for (int xdx = ndx + 1; xdx < size; ++xdx) {
                if (nums[ndx] + nums[xdx] == target) {
                    return {ndx, xdx};
                }
            }
        }
        return {0, 0};
    }
};

int main() {
    Solution solution;
    std::vector vec1{2,7,11,15};
    std::vector vec2{3,2,4};
    std::vector vec3{3,3};
    std::vector vec4{3,2,3};

    std::cout << std::format("{}", vec_to_string(solution.twoSum(vec1, 9))) << std::endl;
    std::cout << std::format("{}", vec_to_string(solution.twoSum(vec2, 6))) << std::endl;
    std::cout << std::format("{}", vec_to_string(solution.twoSum(vec3, 6))) << std::endl;
    std::cout << std::format("{}", vec_to_string(solution.twoSum(vec4, 6))) << std::endl;
    return 0;
}