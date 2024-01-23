/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

using namespace std;

int findWaysToEvaluateToTarget(const vector<int>& nums, int target) {
    int n = nums.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(2 * target + 1, 0));

    dp[0][target] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 2 * target; ++j) {
            if (j - nums[i - 1] >= 0) {
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
            if (j + nums[i - 1] <= 2 * target) {
                dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    int result = findWaysToEvaluateToTarget(nums, target);
    cout << result << endl;

    return 0;
}
