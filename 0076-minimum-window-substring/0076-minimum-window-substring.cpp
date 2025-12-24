class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        if(t.length()>n)return "";
        unordered_map<char,int>mppt;
        for(char ch:t){
            mppt[ch]++;
        }
        int left=0,right=0,windowsize=INT_MAX;
        int start=0;
        int requiredcnt=t.size();
        while(right<n){
            char ch=s[right];
            if(mppt[ch]>0)requiredcnt--;
            mppt[ch]--;
            right++;
            while(requiredcnt==0){
                if(right-left<windowsize){
                    windowsize=right-left;
                    start=left;
                }
              mppt[s[left]]++;
              if(mppt[s[left]]>0){
                requiredcnt++;
              }
              left++;
            }
        }
        return windowsize==INT_MAX?"":s.substr(start,windowsize);
    }
};