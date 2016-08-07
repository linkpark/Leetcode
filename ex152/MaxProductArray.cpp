#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      if( nums.size() == 1 ) return nums[0];              

      vector<int> zero_position;
      int max_product = nums[0];

      for( size_t i = 0; i < nums.size(); ++i ) {
        if( nums[i] == 0 ) {
          zero_position.push_back(i);
          max_product = 0;
        }
      }
      
      if( zero_position.size() == 0 ) 
        return maxSubArrayProduct( nums, 0, nums.size() - 1 );
      
      int left_bound = 0;
      for( size_t i = 0; i < zero_position.size(); ++i ) {
        int max = max_product;
        if( zero_position[i] > 0 ) {
          max = maxSubArrayProduct( nums, left_bound, zero_position[i] - 1 );
          if( max > max_product ) max_product = max;
        }

        left_bound = zero_position[i] + 1;
      }

      int max = maxSubArrayProduct( nums, left_bound, nums.size() - 1 );
      if( max > max_product ) max_product = max;

      return max_product;
    }

    int maxSubArrayProduct( vector<int> &nums, int left_bound, int right_bound ) {
      if( left_bound >= (int)nums.size() || right_bound < 0 ) return INT_MIN;
      if( left_bound >= right_bound ) return nums[left_bound];

      int num_of_neg = 0;
      int result = 1;
      int first_neg = -1;
      int last_neg = -1;
      for( int i = left_bound; i <= right_bound; ++i ) {
        if( nums[i] < 0 )  {
          if( first_neg < 0 ) first_neg = i;

          last_neg = i;
          num_of_neg++;
        }
        result *= nums[i];
      }    

      if( num_of_neg % 2 == 0 ) 
        return result; 
      else { 
          int result_left = std::max( maxSubArrayProduct(nums, left_bound, first_neg-1 ), maxSubArrayProduct( nums, first_neg+1, right_bound ) ); 
          int result_right = std::max( maxSubArrayProduct(nums, left_bound, last_neg-1), maxSubArrayProduct( nums, last_neg+1, right_bound) );
          return std::max( result_left, result_right );
      }
    }
};

int main() {
  Solution s;
  //vector<int> nums = {2,3,-2,4};
  //vector<int> nums = {-2};
  //vector<int> nums = {0,2};
  //vector<int> nums = { -1,-2,-3,0 };
  vector<int> nums = { -4, -3, -2 };

  cout << s.maxProduct(nums) << endl;

  return 0; 
}
