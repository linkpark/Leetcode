#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      if( nums.size() == 1 ) return nums[0];

      int currentSum = nums[0];
      int maxSum = nums[0];      

      for( size_t i = 1; i < nums.size(); ++i ) {
        if( currentSum > 0 ) {
          currentSum += nums[i];
        } else {
          currentSum = nums[i];
        }

        if( currentSum > maxSum ) {
          maxSum = currentSum;
        }
      }

      return maxSum;
    }
};

int main() {
  Solution s;
  //vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
  vector<int> nums = { -1};
  
  cout << s.maxSubArray( nums ) << endl;

  return 0;
}
