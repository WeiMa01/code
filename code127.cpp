class Solution {
public:
    bool check(string w1,string w2){
        //判断是否只有一个单词不一致
        if( w1.size() != w2.size()){
            return false;
        }
        int n = w1.size(), same = 0;
        // cout << " check n, same: " << n << "  " << same << endl;
        for(int i = 0;i < n; i++){
            if(w1[i] != w2[i]){
                same ++;
            }
            if(same >= 2) 
                break;
        }
        if (same == 1){
            return true;
        }else{
            return false;
        }

    }


    

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int> > edge(n+1);
        unordered_map<string, int > word_id(n+1);
        word_id[beginWord] = 0;
        node_num++;
        for(int i = 1 ;i <= n ;i++){
            if( word_id.find(wordList[i-1]) == word_id.end()){
                node_num++;
                word_id[wordList[i-1]] = i;
            } 
        }
        
        for (std::unordered_map<string, int>::iterator it = word_id.begin(); it != word_id.end(); it++)
        {
            for (std::unordered_map<string, int>::iterator itj = it;  itj != word_id.end(); itj++)
            {

                if(check(it->first, itj->first)){
                    edge[it->second].push_back(itj->second);
                    edge[itj->second].push_back(it->second);
                }
            }
        }

        if ( word_id.find(endWord) == word_id.end()){
            return 0;
        }
        int begin = word_id[beginWord], end = word_id[endWord];
        vector<int> dis(n+1, INT_MAX);
        dis[begin] = 0;
        queue<int> que;
        que.push(begin);
        while(!que.empty()){
            int x = que.front();
            que.pop();
            if(x == end){
                return dis[end] +1;
            }

            for(int i = 0 ;i < edge[x].size(); i++){
                if(dis[edge[x][i]] == INT_MAX ){
                    dis[edge[x][i]] = dis[x] + 1;
                    que.push(edge[x][i]);
                }
            }
        }
        return 0;
    }
};
