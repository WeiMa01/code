#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    bool check(string s, string word){
        int n = word.size();
        int m = s.size();
        cout << "chek::::::" << s <<"    " << word << endl;
        if (m < n) {
            return false;
        }
        if(n == 0){
            return false;
        }
        for(int i=0 ;i < n;i++){
            if(s[i] != word[i]){
                return false;
            }
        }
        return true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        queue<string> q;
        int n = wordDict.size(), m = 0;
        string words = s;
        for(int i = 0 ;i < n;i++){
            words = s;
            if(check(words,wordDict[i])){
                q.push(wordDict[i]);
                cout << "check true: " << words << endl;
                while(!q.empty()){

                    m = q.front().size();
                    q.pop();
                    words = words.substr(m,words.size()-m);
                    cout << "word:" << words << endl;
                    if(words.size() == 0){
                        return true;
                    }
                    for(int i = 0 ;i < n; i++){
                        
                        if(check(words, wordDict[i])){
                            if(words.size() == wordDict[i].size()){
                                return true;
                            }
                            q.push(wordDict[i]);
                        }
                    }
                }
            }
        }
        return false;
    }
};


int main()
{

    vector<string> wordList  = {"aaaa", "aa"};
    Solution solution;
    auto result = solution.wordBreak("aaaaaaa", wordList);
    std::cout << "result: " << result << std::endl;
    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << "   ";
    // }
    return 0;
}
