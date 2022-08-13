#include<bits/stdc++.h>
using namespace std;

// Memoization
// Time: O(n); Space: O(2n) ~ O(n)
int memRobber(int index, vector<int>& memo, vector<int>& arr) {
    if(index < 0)
        return 0;
    else if(memo[index] != -1)
        return memo[index];
    memo[index] = max(arr[index]+memRobber(index-2, memo, arr), memRobber(index-1, memo, arr));
    return memo[index];
}

// Tabulation
// Time: O(n); Space: O(n)
int tabRobber(int n, vector<int>& arr) {
    if(n == 1) {
        return arr[0];
    }
    else if(n == 2) {
        return max(arr[0], arr[1]);
    }
    vector<int> dp(n, -1);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i=2; i<n; i++) {
        dp[i] = max(arr[i]+dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}

// Space Optimization
// Time: O(n); Space: O(1)
int optRobber(int n, vector<int>& arr) {
    if(n == 1) {
        return arr[0];
    }
    else if(n == 2) {
        return max(arr[0], arr[1]);
    }
    int prevToPrev = arr[0];
    int prev = max(arr[0], arr[1]);
    int curr = 0;
    for(int i=2; i<n; i++) {
        curr = max(arr[i]+prevToPrev, prev);
        prevToPrev = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> memo(n+1, -1);
    cout << memRobber(n-1, memo, arr) << endl;
    cout << tabRobber(n, arr) << endl;
    cout << optRobber(n, arr) << endl;
}