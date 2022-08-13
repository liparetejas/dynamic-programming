#include<bits/stdc++.h>
using namespace std;

// Memoization
// Time: O(nk); Space: O(2n) ~ O(n)
int memFrogJump(int n, vector<int>& arr, vector<int>& memo, int index, int k) {
    if(index <= 0) {
        return 0;
    }
    else if(memo[index] != -1) {
        return memo[index];
    }
    int minSteps = INT_MAX;
    for(int i=1; i<=k; i++) {
        if(index-i>=0) {
            int jumps = memFrogJump(n, arr, memo, index-i, k) + abs(arr[index]-arr[index-i]);
            minSteps = min(minSteps, jumps);
        }
    }
    return memo[index] = minSteps;
}

// Tabulation
// Time: O(nk); Space: O(n)
int tabMinClimb(int n, vector<int> arr, int k) {
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                int jumps = dp[i-j] + abs(arr[i]-arr[i-j]);
                minSteps = min(minSteps, jumps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

// Space Optimization
int optMinClimb(int n, vector<int> arr) {
    // No further space optimization possible
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    // vector<int> memo(n, -1);
    // cout << memFrogJump(n, arr, memo, n-1, k) << endl;
    cout << tabMinClimb(n, arr, k) << endl;
    // cout << optMinClimb(n, arr, k) << endl;
}