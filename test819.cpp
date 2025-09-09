class Solution {
public:
    bool check_in(string a,vector<string>& banned ){
        for(int i = 0 ;i < banned.size();i++){
            if(a == banned[i]){
                return true;
            }
        }
        return false;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> maps;
        vector<string> words;

        int n = paragraph.size();
        bool flag = false;
        int first_p = 0;
        int max_count = 0;
        string max_s;
        for (int i = 0; i < n; i++)
        {
            if((paragraph[i] >= 'A' && paragraph[i] <= 'Z')){
                //转小写
                paragraph[i] = paragraph[i] - ('A' - 'a');
            }
            if((paragraph[i] >= 'a' && paragraph[i] <= 'z') ){
                if(!flag){
                    first_p = i;
                    flag = true;
                }
            }else{
                if(flag){
                    string new_string = paragraph.substr(first_p,(i - first_p));
                    if(!check_in(new_string, banned)){
                        words.push_back(new_string);
                    }
                    
                    flag = false;
                }

            }

        }
        for (int i = 0; i < words.size(); i++)
        {
            // cout << "words:" << words[i] << ":" << endl;
            for(unordered_map<string, int>::iterator it = maps.begin(); it != maps.end();it ++){
                cout << it->first << ":" << it->second << endl;
            }
            // cout <<"-----------------------------------------------" << endl;
            if(maps.find(words[i]) != maps.end()){
                maps[words[i]] = maps[words[i]] +1;
            }else{
                maps[words[i]] = 1;
            }

            // cout << words[i] << ":" << maps[words[i]] <<endl;

            if ( maps[words[i]] > max_count){
                // cout << "max words: " << words[i] << " : " <<maps[words[i]] << endl;
                max_count = maps[words[i]] ;
                max_s = words[i];
            }
        }
        return max_s;
        
    }
}; 
