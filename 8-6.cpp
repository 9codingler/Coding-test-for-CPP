#include <iostream>
#include <vector>
using namespace std;

int dp[101];
int tmp[101];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> tmp[i];
    }

    dp[1] = tmp[1];
    dp[2] = max(tmp[1], tmp[2]); // 첫번째, 두번째를 선택할지 나눈다.
    
    for(int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2] + tmp[i], dp[i - 1]);
    }

    cout << dp[n] << '\n';
    return 0;
}
