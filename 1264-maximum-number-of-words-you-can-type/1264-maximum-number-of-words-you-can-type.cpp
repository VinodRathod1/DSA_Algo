class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        string word;
        stringstream ss(text);
        
        while (ss >> word) {   // extract words
            bool canType = true;
            for (char c : word) {
                if (broken.count(c)) { // contains broken letter
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }
        return count;
    }
};
