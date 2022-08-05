#include<bits/stdc++.h>
using namespace std;

// Memoization
// Time: O(n); Space: O(2n) ~ O(n)
int memClimb(int n, vector<int>& memo) {
    if(n == 0) {
        return 1;
    }
    else if(n == 1) {
        return 1;
    }
    else if(memo[n] != -1) {
        return memo[n];
    }
    return memo[n] = memClimb(n-1, memo) + memClimb(n-2, memo);
}

// Tabulation
// Time: O(n); Space: O(n)
int tabClimb(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space Optimization
// Time: O(n); Space: O(1)
int optClimb(int n) {
    int prevToPrev = 1;
    int prev = 1;
    int curr = 0;
    for(int i=2; i<=n; i++) {
        curr = prev + prevToPrev;
        prevToPrev = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;
    vector<int> memo(n+1, -1);
    cout << memClimb(n, memo) << endl;
    cout << tabClimb(n) << endl;
    cout << optClimb(n) << endl;
}