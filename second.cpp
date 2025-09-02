#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i =0;i < n;i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        int left,right;
        vector<vector<int>>  result;
        for(int i=0;i<n-2 && nums[i] <= 0; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            left = i+1;
            right = n-1;
            while(left < right){
                cout << " i left right: " << i << "   " << left << "  " << right << endl;
                cout << " i left right: " << nums[i] << "   " << nums[left] << "  " << nums[right] << endl;
                cout << "----------------" << endl;
                if(nums[i] + nums[left] + nums[right] == 0){
                    cout << " 满足条件: " << i << "   " << left << "  " << right << endl;
                    cout << " 满足条件: " << nums[i] << "   " << nums[left] << "  " << nums[right] << endl;
                    result.push_back({nums[i],nums[left],nums[right]});
                    while(left < n-1 && nums[left] == nums[left+1]){
                        left++;
                    }
                    left++;
                    while(right > left && nums[right] == nums[right-1]){
                        right--;
                    }
                    right--;
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    right--;
                }
            }
            
        }
        return result;
    }
};


int main()
{

    vector<int> nums = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    Solution solution;
    solution.threeSum(nums);
    // cout << "result: " << result << endl;
    // for (int i = 0; i < result; i++) {
    //     cout << nums[i] << "   ";
    // }
    return 0;
}
