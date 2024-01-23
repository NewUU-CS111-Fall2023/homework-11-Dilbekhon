/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.length();

    vector<bool> dp(n + 1, false);

    dp[0] = true;

    for (int i = 1; i <= n; ++i) {

        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {

    string s1 = "newuzbekistan";
    vector<string> wordDict1 = {"new", "uzbekistan"};

    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};

    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};

    bool result1 = wordBreak(s1, wordDict1);
    bool result2 = wordBreak(s2, wordDict2);
    bool result3 = wordBreak(s3, wordDict3);

    cout << boolalpha; 
    cout << result1 << endl;  
    cout << result2 << endl;  
    cout << result3 << endl;  

    return 0;
}
