#include<bits/stdc++.h>
using namespace std;

// Memoization
// Time: O(n); Space: O(2n) ~ O(n)
int memMinClimb(int n, vector<int>& arr, vector<int>& memo, int index) {
    if(index < 0) {
        return 0;
    }
    else if(arr.size() == 1) {
        return arr[0];
    }
    else if(arr.size() == 2) {
        return min(arr[0], arr[1]);
    }
    else if(memo[index] != -1) {
        return memo[index];
    }
    return memo[index] = arr[index] + min(memMinClimb(n, arr, memo, index-1), memMinClimb(n, arr, memo, index-2)); 
}

// Tabulation
// Time: O(n); Space: O(n)
int tabMinClimb(int n, vector<int> arr) {
    if(arr.size() == 1) {
        return arr[0];
    }
    else if(arr.size() == 2) {
        return min(arr[0], arr[1]);
    }
    vector<int> dp(n+1, -1);
    dp[0] = arr[0];
    dp[1] = arr[1];
    for(int i=2; i<n; i++) {
        dp[i] = arr[i] + min(dp[i-1], dp[i-2]);
    }
    dp[n] = min(dp[n-1], dp[n-2]);
    return dp[n];
}

// Space Optimization
// Time: O(n); Space: O(1)
int optMinClimb(int n, vector<int> arr) {
    if(arr.size() == 1) {
        return arr[0];
    }
    else if(arr.size() == 2) {
        return min(arr[0], arr[1]);
    }
    int prevToPrev = arr[0];
    int prev = arr[1];
    int curr = 0;
    for(int i=2; i<n; i++) {
        curr = arr[i] + min(prev, prevToPrev);
        prevToPrev = prev;
        prev = curr;
    }
    curr = min(prev, prevToPrev);
    return curr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> memo(n, -1);
    cout << min(memMinClimb(n, arr, memo, n-1), memMinClimb(n, arr, memo, n-2)) << endl;
    cout << tabMinClimb(n, arr) << endl;
    cout << optMinClimb(n, arr) << endl;
}