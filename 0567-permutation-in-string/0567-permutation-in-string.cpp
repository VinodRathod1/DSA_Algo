class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m)return false;
        vector<char>freqs1(26,0);
        vector<char>freqs2(26,0);
        for(int i=0;i<n;i++){
            freqs1[s1[i]-'a']++;
        }
        int i=0;
        for(int j=0;j<m;j++){
            freqs2[s2[j]-'a']++;
            if(j-i+1>n){
                freqs2[s2[i]-'a']--;
                i++;
            }
            if(freqs1==freqs2)return true;
        }
        
        return false;
    }
};