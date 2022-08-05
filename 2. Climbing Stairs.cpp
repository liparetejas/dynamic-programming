#include<bits/stdc++.h>
using namespace std;

// Memoization
// Time: O(n); Space: O(2n) ~ O(n)
int memFibo(int n, vector<int>& memo) {
    return 0;
}

// Tabulation
// Time: O(n); Space: O(n)
int tabFibo(int n) {
    return 0;
}

// Space Optimization
// Time: O(n); Space: O(1)
int optFibo(int n) {
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> memo(n+1, -1);
    cout << memFibo(n, memo) << endl;
    cout << tabFibo(n) << endl;
    cout << optFibo(n) << endl;
}