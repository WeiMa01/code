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
    queue<char> unique_sign;
    vector<string> split_string(string str){
        vector<string> strs;
        int start =0;
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            if(str[i] == '*' || str[i] == '.'){
                strs.push_back(str.substr(start,i-start));
                start = i+1;
                unique_sign.push(str[i]);
            }
        }
        strs.push_back(str.substr(start, n-start));
        return strs;
    }
    int find_position(string s, string p, int start = 0){
        // -1, -1 代表没找到
        for (int i = start; i < s.size() - p.size()+1 ; i++)
        {
            //i 是s的起始位置
            bool f = true;
            for (int j = 0; j < p.size(); j++)
            {
                if(s[i+j] != p[j]){
                    f = false;
                    break;
                }
            }
            if(f){
                //匹配上了 
                return i;
            }
        }
        return -1;
    }
    bool isMatch(string s, string p) {
        //扩展 *  和 s一样长
        int ns = s.size();
        int ps = p.size();
        vector<string> psplit = split_string(p);
        vector<int> index;
        for (auto &word : psplit)
        {
            cout << word << " ";
        }
        cout << endl;

        //以 * 将p切分为多个子段 判断每一段在s中的下标位置。
        int position = -1;
        for (int i = 0; i < psplit.size(); i++)
        {
            position = find_position(s,psplit[i], position+1);
            if( position == -1) return false;
            index.push_back(position);
        }
        vector<char> new_p(ns, '#');
        for (int i = 0; i < index.size(); i++)
        {
            for(int j =0;j < psplit[i].size();j++){
                new_p[index[i] + j] = psplit[i][j];
            }
        }
        for (int i = 0; i < new_p.size(); i++)
        {
            if(new_p[i] == '#'){
                //需要扩展
                char unique = unique_sign.front();
                unique_sign.pop();
                if(unique == '.'){
                    new_p[i] = s[i];
                }else{
                    new_p[i] = new_p[i-1];
                }
            }
        }
        for (int i = 0; i < ns; i++)
        {
            if(s[i] != new_p[i]){
                return false;
            }
        }
        return true;
        //将 p扩展为和s一样长，判断。
    }
};

int main()
{   

    Solution solution;

    auto result = solution.isMatch("mabcdefggghi","ma.cdefg*hi");
    cout << "result: " << result << std::endl;
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
