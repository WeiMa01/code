struct Voew{
    char val;
    int index;
};

class Solution {
public:
    string sortVowels(string s) {
        int n = s.size(),m;
        vector<Voew> v;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                v.push_back({s[i], i});
            }
        }
        // for(vector<Voew>::iterator iter = v.begin(); iter != v.end();iter++){
        //     cout << (iter->val) << ":" << (iter->index) << " ";
        // }
        // cout << endl;

        m = v.size();
        // 选择排序
        // for (int i = 0; i < m; i++){
        //     for (int j = i+1; j < m; j++){
        //         if(v[i].val  > v[j].val){
        //             char c = v[i].val;
        //             v[i].val = v[j].val;
        //             v[j].val =c;
        //         }
        //     }
        // }
        // 插入排序
        Voew tmp;
        for (int i = 1; i < m; i++){
            tmp.val = v[i].val;
            tmp.index = v[i].index;
            bool flag = false;
            for(int j = i-1; j>=0; j--){
                if(v[j].val  > tmp.val){
                    //向后移位
                    v[j+1].val = v[j].val;
                    // v[j+1].index = v[j].index;
                }else{
                    v[j+1].val = tmp.val;
                    // v[j].index = tmp.index;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                v[0].val = tmp.val;
            }
        }

        // for(vector<Voew>::iterator iter = v.begin(); iter != v.end();iter++){
        //     cout << (iter->val) << ":" << (iter->index) << " ";
        // }
        // cout << endl;

        for (int i = 0; i < m; i++){
            s[v[i].index] = v[i].val;
        }
        return s;
    }
};
