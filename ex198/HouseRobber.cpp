#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// dynamic programming

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    if (nums.size() == 2) return max(nums[0], nums[1]);

    if (nums.size() == 1) return nums[0];

    max_rob_value_.resize( nums.size() );
    for( size_t i = 0; i < nums.size(); ++i ) 
      max_rob_value_[i] = -1;

    max_rob_value_[nums.size() - 1] = nums[nums.size() - 1];
    max_rob_value_[nums.size() - 2] =
        max(nums[nums.size() - 1], nums[nums.size() - 2]);

    return max(nums[0] + rob_value(nums, 2), rob_value(nums, 1));
  }

  int rob_value(vector<int>& nums, int n) {
    if (max_rob_value_[n] != -1) return max_rob_value_[n];

    max_rob_value_[n] =
        max(rob_value(nums, n + 1), rob_value(nums, n + 2) + nums[n]);
    return max_rob_value_[n];
  }

  vector<int> max_rob_value_;
};

int main() {
  vector<int> nums = { 1,2,3,5,6,7,7,7,7,8,8,8,88,9,10,11,23,123123,111,2321 };
  Solution s;
  cout << s.rob( nums ) << endl;
}
