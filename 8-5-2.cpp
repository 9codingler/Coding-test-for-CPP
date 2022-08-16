#include <iostream>

using namespace std;

int dp[30001];

int main() {
    int x;
    cin >> x;
    
    for(int i = 2; i <= x; i++) {
        //현재의 수에서 1을 빼는 경우.
        dp[i] = dp[i - 1] + 1; //d[1] = 0, d[2] = 1.
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if(i % 5 == 0) {
            dp[i] = min(dp[i], dp[i / 5] + 1);
        }
    }
    cout << dp[x] << '\n';
    for(int i = 1; i <= x; i++) {
        cout << dp[i] << ' ';
    }
    return 0;
}
