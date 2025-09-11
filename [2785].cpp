class Solution {
public:
    string sortVowels(string s) {
        int n = s.size(),m;
        vector<int> index;
        unordered_map<char, int> voew_num;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'a'){
                index.push_back(i);
                if(voew_num.find('a') != voew_num.end()){
                    voew_num['a'] = voew_num['a']+1;
                }else{
                    voew_num.insert({'a', 1});
                }
            }else if( s[i] == 'e'){
                index.push_back(i);
                if(voew_num.find('e') != voew_num.end()){
                    voew_num['e'] = voew_num['e']+1;
                }else{
                    voew_num.insert({'e', 1});
                }
            }else if( s[i] == 'i'){
                index.push_back(i);
                if(voew_num.find('i') != voew_num.end()){
                    voew_num['i'] = voew_num['i']+1;
                }else{
                    voew_num.insert({'i', 1});
                }
            }else if( s[i] == 'o'){
                index.push_back(i);
                if(voew_num.find('o') != voew_num.end()){
                    voew_num['o'] = voew_num['o']+1;
                }else{
                    voew_num.insert({'o', 1});
                }
            }else if( s[i] == 'u'){
                index.push_back(i);
                if(voew_num.find('u') != voew_num.end()){
                    voew_num['u'] = voew_num['u']+1;
                }else{
                    voew_num.insert({'u', 1});
                }
            }else if( s[i] == 'A'){
                index.push_back(i);
                if(voew_num.find('A') != voew_num.end()){
                    voew_num['A'] = voew_num['A']+1;
                }else{
                    voew_num.insert({'A', 1});
                }
            }else if( s[i] == 'E'){
                index.push_back(i);
                if(voew_num.find('E') != voew_num.end()){
                    voew_num['E'] = voew_num['E']+1;
                }else{
                    voew_num.insert({'E', 1});
                }
            }else if( s[i] == 'I'){
                index.push_back(i);
                if(voew_num.find('I') != voew_num.end()){
                    voew_num['I'] = voew_num['I']+1;
                }else{
                    voew_num.insert({'I', 1});
                }
            }else if (s[i] == 'O'){
                index.push_back(i);
                if(voew_num.find('O') != voew_num.end()){
                    voew_num['O'] = voew_num['O']+1;
                }else{
                    voew_num.insert({'O', 1});
                }
            }else if( s[i] == 'U'){
                index.push_back(i);
                if(voew_num.find('U') != voew_num.end()){
                    voew_num['U'] = voew_num['U']+1;
                }else{
                    voew_num.insert({'U', 1});
                }
            }
        }
        int index_s = 0;
        while(voew_num.find('A') != voew_num.end() && voew_num['A'] > 0){
            s[index[index_s++]] = 'A';
            voew_num['A']--;
        }
        while(voew_num.find('E') != voew_num.end() && voew_num['E'] > 0){
            s[index[index_s++]] = 'E';
            voew_num['E']--;
        }
        while(voew_num.find('I') != voew_num.end() && voew_num['I'] > 0){
            s[index[index_s++]] = 'I';
            voew_num['I']--;
        }
        while(voew_num.find('O') != voew_num.end() && voew_num['O'] > 0){
            s[index[index_s++]] = 'O';
            voew_num['O']--;
        }
        while(voew_num.find('U') != voew_num.end() && voew_num['U'] > 0){
            s[index[index_s++]] = 'U';
            voew_num['U']--;
        }

        while(voew_num.find('a') != voew_num.end() && voew_num['a'] > 0){
            s[index[index_s++]] = 'a';
            voew_num['a']--;
        }
        while(voew_num.find('e') != voew_num.end() && voew_num['e'] > 0){
            s[index[index_s++]] = 'e';
            voew_num['e']--;
        }
        while(voew_num.find('i') != voew_num.end() && voew_num['i'] > 0){
            s[index[index_s++]] = 'i';
            voew_num['i']--;
        }
        while(voew_num.find('o') != voew_num.end() && voew_num['o'] > 0){
            s[index[index_s++]] = 'o';
            voew_num['o']--;
        }
        while(voew_num.find('u') != voew_num.end() && voew_num['u'] > 0){
            s[index[index_s++]] = 'u';
            voew_num['u']--;
        }

        return s;
    }
};
