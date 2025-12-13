#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<string> validateCoupons(
        vector<string>& code,
        vector<string>& businessLine,
        vector<bool>& isActive
    ) {
        // Ordered mapping for business categories
        unordered_map<string, int> priority {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<string,string>> validCoupons; // (businessLine, code)

        // Helper lambda to check if code string is valid
        auto isValidCode = [&](const string &s) {
            if (s.empty()) return false;
            for (char ch : s) {
                // Only letters, digits, or underscore allowed
                if (!(isalnum(ch) || ch == '_'))
                    return false;
            }
            return true;
        };

        // Loop over all coupons
        int n = code.size();
        for (int i = 0; i < n; ++i) {
            if (!isActive[i]) continue; // Must be active
            if (!isValidCode(code[i])) continue; // Must have valid characters
            if (!priority.count(businessLine[i])) continue; // Must be valid category

            // Add to valid list
            validCoupons.push_back({businessLine[i], code[i]});
        }

        // Sort by business priority, then by code lexicographically
        sort(validCoupons.begin(), validCoupons.end(),
             [&](auto &a, auto &b) {
                 int pa = priority[a.first];
                 int pb = priority[b.first];
                 if (pa != pb) return pa < pb; // first compare category
                 return a.second < b.second;  // then compare codes
             });

        // Just return the sorted list of codes
        vector<string> result;
        for (auto &p : validCoupons) {
            result.push_back(p.second);
        }
        return result;
    }
};
