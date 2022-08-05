#include<bits/stdc++.h>
using namespace std;

// Memoization
// Time: O(n); Space: O(2n) ~ O(n)
int memFibo(int n, vector<int>& memo) {
    if(n <= 1) {
        return n;
    }
    else if(memo[n] != -1) {
        return memo[n];
    }
    return memo[n] = memFibo(n-1, memo) + memFibo(n-2, memo);
}

// Tabulation
// Time: O(n); Space: O(n)
int tabFibo(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space Optimization
// Time: O(n); Space: O(1)
int optFibo(int n) {
    if(n <= 1) {
        return n;
    }
    int prevToPrev = 0;
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
    cout << memFibo(n, memo) << endl;
    cout << tabFibo(n) << endl;
    cout << optFibo(n) << endl;
}