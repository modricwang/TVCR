#include <vector>
using std::vector;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> twoSum;
    for (auto it = 0; it < nums.size(); it++) {
      for (auto it2 = it + 1; it2 < nums.size(); it2++) {
        if (nums[it] + nums[it2] == target) {
          twoSum.push_back(it);
          twoSum.push_back(it2);
        }
      }
    }
    return twoSum;
  }
};
