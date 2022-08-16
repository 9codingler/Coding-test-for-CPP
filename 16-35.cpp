#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001]; // 못생긴 수를 담기 위한 테이블 (1차원 DP 테이블)

int main() {
    cin >> n;

    // 2배, 3배, 5배를 위한 인덱스
    int i2 = 1, i3 = 1, i5 = 1;
    // 처음에 곱셈 값을 초기화
    int next2 = 2, next3 = 3, next5 = 5;

    dp[1] = 1; // 첫 번째 못생긴 수는 1
    // 1부터 n까지의 못생긴 수들을 찾기
    for (int i = 2; i <= n; i++) {
        // 가능한 곱셈 결과 중에서 가장 작은 수를 선택
        dp[i] = min({next2, next3, next5});
        // 인덱스에 따라서 곱셈 결과를 증가
        if (dp[i] == next2) {
            i2++;
            next2 = dp[i2] * 2;
        }
        if (dp[i] == next3) {
            i3++;
            next3 = dp[i3] * 3;
        }
        if (dp[i] == next5) {
            i5++;
            next5 = dp[i5] * 5;
        }
    }

    // n번째 못생긴 수를 출력
    cout << dp[n] << '\n';
}
