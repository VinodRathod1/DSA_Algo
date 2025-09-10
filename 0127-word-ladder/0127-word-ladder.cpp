class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int ans=q.front().second;
            q.pop();
            if(word==endWord)return ans;
            for(int i=0;i<word.size();i++){
                char ori=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,ans+1});
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
};