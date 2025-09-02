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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = nullptr,* tmp = nullptr;
        int k = lists.size();
        int m, minVal;
        vector<ListNode*>::iterator position;
        if(k == 0){
            return nullptr;
        }
        while(lists.size() > 0){
            m = lists.size();
            minVal = 10e4+1;
            for(vector<ListNode*>::iterator i = lists.begin(); i != lists.end() ; i++){
                if((*i) == nullptr){
                    lists.erase(i);
                }
                if( (*i) -> val < minVal){
                    position = i;
                    minVal = (*i)->val;
                }
                //遍历每个 list 的头结点，找最小的
            }
            // 
            if(root == nullptr){
                root = *position;
            }else{
                tmp ->next = *position;
            }
            tmp = *position;

            *position = (*position) ->next;
            //删除表头元素
            // if((*position) -> next != nullptr){
            //     *position = (*position) ->next;
            // }else{
            //     lists.erase(position);
            // }
            tmp->next = nullptr;  
        }
        return root;
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
