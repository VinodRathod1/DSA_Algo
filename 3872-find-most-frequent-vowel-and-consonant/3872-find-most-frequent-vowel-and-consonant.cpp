class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char,int> vo;
        unordered_map<char,int> co;

        for(int i=0; i<s.size(); i++) {
            if(vowel.find(s[i]) != vowel.end()) {
                vo[s[i]]++;
            } else {
                co[s[i]]++;
            }
        }

        int maxivo = 0, maxico = 0;
        for(auto &it : vo) {
            maxivo = max(maxivo, it.second);
        }
        for(auto &it : co) {
            maxico = max(maxico, it.second);
        }

        return maxivo + maxico;
    }
};
