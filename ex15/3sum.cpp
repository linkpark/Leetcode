#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      std::sort( nums.begin(), nums.end() );           
      vector<vector<int>> ret;     

      if( nums.size() < 3 ) return ret;

      for( size_t i = 0; i < nums.size(); ++i ) {
        if( i > 0 && ( nums[i-1] == nums[i]) ) continue; 
        
        vector< vector<int> > twoSum = TwoSum( nums, (0-nums[i]), i+1, nums.size()-1 );
        
        if( twoSum.size() != 0 ) {
          for( size_t j = 0 ;j < twoSum.size(); ++j ) {
            vector<int> threeSum;
            threeSum.push_back( nums[i] );
            threeSum.push_back( twoSum[j][0] );
            threeSum.push_back( twoSum[j][1] );

            ret.push_back( threeSum );
          }
        }
      }

      return ret;
    }

    vector< vector<int> > TwoSum( vector<int>& nums, int sum, int left_bound, int right_bound ) {
      vector< vector<int> > ret;

      int left = left_bound; int right = right_bound;
      while( right > left ) {
        while( right>left && left>left_bound && ( nums[left-1] == nums[left]) ) left++;
        while( right>left && (right < right_bound ) && ( nums[right+1] == nums[right]) )right--; 

        if( nums[left] + nums[right] > sum ) {
          right--; 
          continue;
        }
        else if( nums[left] + nums[right] < sum ) {
          left++; 
          continue;
        }
        else if(  ( nums[left] + nums[right] == sum ) && ( right > left ) ) {
          vector<int> one_pair;
          one_pair.push_back( nums[left] );
          one_pair.push_back( nums[right] );
          left++; right--;
          ret.push_back( one_pair );
        }
      }

      return ret;
    }
};

int main() {
  Solution s;
//  vector<int> test =  {-1, 0, 1, 2, -1, -4};
  //vector<int> test =  {1,1,-2};
  //vector<int> test = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
  //vector<int> test = { -2,0,0,2,2};
  vector<int> test = { 0,0,0};
  
  vector< vector<int> > ret = s.threeSum( test );

  for( size_t i = 0; i < ret.size(); ++ i ) {
    cout << ret[i][0] << " " << ret[i][1] << " " << ret[i][2] << endl;
  }

  return 0;
}

