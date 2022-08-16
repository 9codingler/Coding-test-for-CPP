#include <iostream>

using namespace std;

int dp[30001];

int solve(int x) {

    if(x == 1) {
        return 0;
    }

    if(dp[x] != 0) { // memoization.
        return dp[x];
    }

    dp[x] = solve(x - 1) + 1;

    if(x % 5 == 0) {
        dp[x] = min(dp[x], solve(x / 5) + 1);
    }

    if(x % 3 == 0) {
        dp[x] = min(dp[x], solve(x / 3) + 1);
    }

    if(x % 2 == 0) {
        dp[x] = min(dp[x], solve(x / 2) + 1);
    }
    
    return dp[x];
}

int main() {
    int x;
    cin >> x;
    cout << solve(x) << '\n';
    return 0;
}
