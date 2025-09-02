#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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
