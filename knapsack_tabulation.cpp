/*
No. of states:
1. Space in knapsack: w
2. No of items: n
Table Size = dp[n+1][w+1]
*/

#include<bits/stdc++.h>
#define M 1000000007
#define ll long long int
#define endl '\n'
using namespace std;

void printDpTable(vector<vector<ll>> dp) {
    for(vector<ll> subdp : dp) {
        for(ll n : subdp) {
            cout << n << " ";
        }
        cout << endl;
    }
}

ll solve(vector<vector<ll>>& dp, vector<ll> w, vector<ll> p, ll n, ll c) {
    for(ll i=0; i<=n; i++) {
        for(ll j=0; j<=c; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(w[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], p[i-1]+dp[i-1][j-w[i-1]]);
            }
        }
    }
    return dp[n][c];
}

int main()
{
    ll n; // number of items
    cin >> n;
    ll c;
    cin >> c; // capacity
	vector<ll> w(n); // weight vector
    vector<ll> p(n); // profit vector
    for(ll i=0; i<n; i++) {
        cin >> w[i];
    }
    for(ll i=0; i<n; i++) {
        cin >> p[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(c+1, 0));
    cout << solve(dp, w, p, n, c) << endl << endl; 
    printDpTable(dp);
	return 0;	
}

/*
Input:
3 4
1 2 3
2 3 5

Output:
Max profit: 7

DP Table:
0 0 0 0 0
0 2 2 2 2
0 2 3 5 5
0 2 3 5 7
*/