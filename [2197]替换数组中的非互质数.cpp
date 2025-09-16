#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>

using namespace std;



class Solution {
public:
    // int GCD(int a, int b){
    //     //最大公约数
    //     int min_num =  a < b ? a :b;
    //     for (int i = min_num; i > 0; i--){
    //         if(a % i == 0 && b%i == 0){
    //             return i;
    //         }
    //     }
    //     return 1;
    // }
    // int LCM(int a, int b){
    //     //  最小公倍数
    //     int max_num = a > b ? a: b;
    //     int min_num = a< b ? a:b;
    //     for (int i = max_num; i / max_num <= min_num; i++) {
    //         if(i % a == 0 && i %b ==0){
    //             return i;
    //         }
    //     }
    //     return a*b;
    // }

int GCD(int a, int b){
        //最大公约数
        int min_num =  a < b ? a :b;
        int max_num =  a >= b ? a:b;
        int c = max_num % min_num;
        while(c!= 0){
            max_num = b;
            min_num = c;
            c = max_num % min_num;
        }
        return min_num;
    }
    int LCM(int a, int b){
        //  最小公倍数

        return a * (b / GCD(a,b));
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums;
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < n; i++){
            cout << result.back() << "  " << nums[i] << "  " << GCD(result.back(), nums[i]) << endl;
            if(GCD(result.back(), nums[i]) != 1){
                int tmp = result.back();
                result.pop_back();
                result.push_back(LCM(tmp, nums[i]));
                //处理result中新加入的数和老数之间不满足条件
                int n_size = result.size();
                for(int j = n_size -1; j>0;j--){
                    if(GCD(result[j], result[j-1]) != 1){
                        int a = result.back();
                        result.pop_back();
                        int b = result.back();
                        result.pop_back();
                        result.push_back(LCM(a,b));
                    }else{
                        break;
                    }
                }

            }else{
                cout << "result .push back " << nums[i] << endl;
                result.push_back(nums[i]);
            }
            cout << " result 中的元素" << endl;
            for(int k = 0 ; k < result.size(); k++){
                cout << result[i] << " ";
            }
            cout << endl;
        }
        return result; 
    }
};



int main()
{

    vector<int> test;
    for (int i = 0; i < 10; i++)
    {
        test.push_back(i) ;
    }
    test.pop_back();
    for(int i= 0 ; i< test.size() ;i++){
        cout << test[i] << " ";
    }

    

    // Solution solution;
    // vector<int> nums = {602,37963,37963,37963};

    // // cout << solution.GCD(37963, 37963) << "   " <<solution.LCM(37963, 37963)  << endl;


    // auto result = solution.replaceNonCoprimes(nums);
    // // // // cout << "result: " << result << std::endl;
    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << "   ";
    // }
    // for (int i = 0; i < result.size(); i++) {
    //     for (int j = 0; j < result[i].size(); j++)
    //     {
    //         cout << result[i][j] << "    ";
    //     }
    //     cout << endl;
        
    // }

    return 0;
}
//         (1 + 2) * (3 + 4)           (1 + 2) * 3 + 4                   //站里面 
//         1 2 + 3 4 + *                1  2 + 3 * 4 +                   1 2 + 3 *   
