class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        // dp[day][age] where age ∈ [1..forget]
        vector<vector<int>> dp(n + 1, vector<int>(forget + 1, 0));
        dp[1][1] = 1;

        for (int day = 2; day <= n; ++day) {
            // Aging: people grow older by 1 day (ages 2..forget)
            for (int age = 2; age <= forget; ++age) {
                dp[day][age] = dp[day - 1][age - 1];
            }

            // New learners (age = 1) are those who were sharers on previous day:
            // sharers on day 'day' correspond to dp[day-1][age] with age in [delay .. forget-1]
            long long newPeople = 0;
            for (int age = delay; age <= forget - 1; ++age) {
                newPeople += dp[day - 1][age];
                if (newPeople >= MOD) newPeople -= MOD;
            }
            dp[day][1] = (int)newPeople;
        }

        // Sum everyone who still remembers on day n: ages 1..forget (inclusive)
        long long ans = 0;
        for (int age = 1; age <= forget; ++age) {
            ans += dp[n][age];
            if (ans >= MOD) ans -= MOD;
        }
        return (int)ans;
    }
};
