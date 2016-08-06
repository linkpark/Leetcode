#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
      int abs_value = INT_MAX;
      int result = 0;
      if( nums.size() < 3 ) return 0; 

      std::sort( nums.begin(), nums.end() );

      for( size_t i = 0; i < nums.size(); ++i ) {
        size_t k = nums.size() - 1;
        for( size_t j = i + 1; j < k ; ++j ) {
          int sum = nums[i] + nums[j] + nums[k];
          int distance= ::abs( (sum - target ) );
          if( distance <= abs_value ) {
            abs_value = distance;
            result = sum;
          } 

          if( sum > target ) { k--; j--;} 
        }
      }
            
      return result;
    }
};

int main() {
  Solution s;
  //vector<int> nums = {-1,2,1,-4};
  //vector<int> nums = {1,1,-1,-1,3};
  vector<int> nums = {1,2,4,8,16,32,64,128 };
  int target = 82;

  cout << s.threeSumClosest( nums, target ) << endl;
}
