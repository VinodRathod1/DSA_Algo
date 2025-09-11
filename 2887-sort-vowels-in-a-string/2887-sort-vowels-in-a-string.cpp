class Solution {
public:
    string sortVowels(string s) {
        string vowels="aeiouAEIOU";
        unordered_set<char>st(vowels.begin(),vowels.end());
        vector<char>vec;
        for(char it:s){
            if(st.count(it))vec.push_back(it);
        }
        sort(vec.begin(),vec.end());
        string ans=s;
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                ans[i]=vec[idx++];
            }
        }
        return ans;
    }
};