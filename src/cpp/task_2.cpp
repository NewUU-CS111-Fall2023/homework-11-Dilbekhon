/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

using namespace std;

bool canPartition(const vector<int>& nums) {
    int totalSum = 0;

    for (int num : nums) {
        totalSum += num;
    }

    if (totalSum % 2 != 0) {
        return false;
    }
    
    int targetSum = totalSum / 2;
    int n = nums.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {

            if (j - nums[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][targetSum];
}

int main() {

    vector<int> nums1 = {1, 5, 11, 5};
    vector<int> nums2 = {1, 2, 3, 5};

    bool result1 = canPartition(nums1);
    bool result2 = canPartition(nums2);

    cout << boolalpha;  // Print boolean values as true/false
    cout << result1 << endl;  // Should print "true"
    cout << result2 << endl;  // Should print "false"

    return 0;
}
