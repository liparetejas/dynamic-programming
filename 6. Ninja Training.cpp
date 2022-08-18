#include<bits/stdc++.h>
using namespace std;

// Memoization
// Time: O(n*4*3); Space: O(5n) ~ O(n)
int memNinja(int n, int l, vector<vector<int>>& v, vector<vector<int>>& memo) {
    if(n == 0) {
        int maxPoints = 0;
        for(int i=0; i<3; i++) {
            if(i != l) {
                maxPoints = max(maxPoints, v[0][i]);
            }
        }
        return maxPoints;
    }
    else if(memo[n][l] != -1) {
        return memo[n][l];
    }
    int maxPoints = 0, localPoints = 0;
    for(int i=0; i<3; i++) {
        if(i != l) {
            localPoints = v[n][i] + memNinja(n-1, i, v, memo);
            maxPoints = max(maxPoints, localPoints);
        }
    }
    return memo[n][l] = maxPoints;
}

// Tabulation
// Time: O(n*4*3); Space: O(4n)
int tabNinja(int n, vector<vector<int>>& v) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);
    dp[0][3] = max(v[0][0], max(v[0][1], v[0][2]));
    for(int day = 1; day<n; day++) {
        for(int last = 0; last<4; last++) {
            for(int task=0; task<3; task++) {
                if(task != last) {
                    int localPoints = v[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], localPoints);
                }
            }
        }
    }
    return dp[n-1][3];
}

// Space Optimization
// Time: O(n*4*3); Space: O(4)
int optNinja(int n, vector<vector<int>>& v) {
    vector<int> prev(4, -1);
    prev[0] = max(v[0][1], v[0][2]);
    prev[1] = max(v[0][0], v[0][2]);
    prev[2] = max(v[0][0], v[0][1]);
    prev[3] = max(v[0][0], max(v[0][1], v[0][2]));
    for(int day = 1; day<n; day++) {
        vector<int> curr(4, -1);
        for(int last = 0; last<4; last++) {
            for(int task=0; task<3; task++) {
                if(task != last) {
                    int localPoints = v[day][task] + prev[task];
                    curr[last] = max(curr[last], localPoints);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> memo(n, vector<int>(4, -1));
    cout << memNinja(n-1, 3, v, memo) << endl;
    cout << tabNinja(n, v) << endl;
    cout << optNinja(n, v) << endl;
    return 0;
}