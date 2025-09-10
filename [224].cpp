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
    int calculate(string s) {
        // 转数组
        vector<string> mid_s;
        int n = s.size();
        string mid_val;
        for(int i =0;i < n; i++){
            if(s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                mid_s.push_back(mid_val);
                mid_val.clear();
                string tmp(1, s[i]);
                mid_s.push_back(tmp);

            }else{
                mid_val.push_back(s[i]);
            }
        }
        mid_s.push_back(mid_val);
        for(int i= 0 ;i < mid_s.size();i++){
            cout << mid_s[i] << " " ;
        }
        cout << endl;

        // 中缀表达式转后缀表达式
        stack<string> sign;
        vector<string> after_s;
        for(int i= 0 ;i < mid_s.size();i++){
            if(mid_s[i] == "("){
                sign.push(mid_s[i]);
            }else if(mid_s[i] == ")"){
                while(sign.top() != "("){
                    after_s.push_back(sign.top());
                    sign.pop();
                }
                sign.pop();// 弹出左括号
            }else if(mid_s[i] == "+"){
                while( ! sign.empty()){
                    if( sign.top() == "("){
                        break;
                    }
                    after_s.push_back(sign.top());
                    sign.pop();
                }
                sign.push("+");

            }else if(mid_s[i] == "-"){
                while( ! sign.empty()){
                    if( sign.top() == "("){
                        break;
                    }
                    after_s.push_back(sign.top());
                    sign.pop();
                }
                sign.push("-");
            }else if(mid_s[i] == "*"){
                while( ! sign.empty()){
                    if(sign.top() == "+" || sign.top() == "-" || sign.top() == "("){
                        break;
                    }
                    after_s.push_back(sign.top());
                    sign.pop();
                }
                sign.push("*");
            }else if(mid_s[i] == "/"){
                while( ! sign.empty()){
                    if(sign.top() == "+" || sign.top() == "-" || sign.top() == "("){
                        break;
                    }
                    after_s.push_back(sign.top());
                    sign.pop();
                }
                sign.push("/");
            }else{
                after_s.push_back(mid_s[i]); // 数字直接接到后面
            }
        }
        while(!sign.empty()){
            after_s.push_back(sign.top());
            sign.pop();
        }
        cout << "后缀表达式" << endl;
        for(int i = 0 ;i < after_s.size();i++){
            cout <<after_s[i] << " ";    
        }
        cout << endl;
        // 计算结果
        stack<int> s_num;
        int result = 0;
        for(int i = 0; i< after_s.size();i++){
            if(after_s[i] == "+"){
                int right = s_num.top();
                s_num.pop();
                int left = s_num.top();
                s_num.pop();
                s_num.push(left + right);
            }else if(after_s[i] == "-"){
                int right = s_num.top();
                s_num.pop();
                int left = s_num.top();
                s_num.pop();
                s_num.push(left - right);
            }else if(after_s[i] == "*"){
                int right = s_num.top();
                s_num.pop();
                int left = s_num.top();
                s_num.pop();
                s_num.push(left * right);
            }else if(after_s[i] == "/"){
                int right = s_num.top();
                s_num.pop();
                int left = s_num.top();
                s_num.pop();
                s_num.push(left / right);
            }else{
                cout << after_s[i] << endl;
                s_num.push(stoi(after_s[i]));
            }
        }
        return s_num.top();
    }
};

int main()
{
    vector<string> tokens = {"2","1","+","3","*"};
    Solution solution;
    auto result = solution.calculate("(1+(4+5+2)-3)+(6+8)");
    std::cout << "result: " << result << std::endl;
    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << "   ";
    // }
    return 0;
}
//         (1 + 2) * (3 + 4)           (1 + 2) * 3 + 4                   //站里面 
//         1 2 + 3 4 + *                1  2 + 3 * 4 +                   1 2 + 3 *   
