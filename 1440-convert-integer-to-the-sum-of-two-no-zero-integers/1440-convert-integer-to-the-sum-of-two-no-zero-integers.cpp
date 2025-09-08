#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasZero(int x) {
        string s = to_string(x);
        return s.find('0') != string::npos;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};
            }
        }
        return {}; 
    }
};
