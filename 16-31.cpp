#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[21][21];
int dp[21][21];

int main() {
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n, m;
        cin >> n >> m;
    
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> map[i][j];
                dp[i][j] = map[i][j];
            }
        }
        
        for(int j = 2; j <= m; j++) { //1열은 굳이 dp배열 갱신해줄 필요 없다.
            for(int i = 1; i <= n; i++) {
                int leftup, left, leftdown; // 어디서 오는것인지.
                if(i == 1) {
                    leftup = 0; //각각의 1행은 왼쪽 위에서 올 수 없다.
                }
                else {
                    leftup = dp[i - 1][j - 1];
                }
                left = dp[i][j - 1];
                if(i == n) {
                    leftdown = 0;
                }
                else {
                    leftdown = dp[i + 1][j - 1];
                }
                dp[i][j] = dp[i][j] + max(leftup, max(leftdown, left));
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; i++) {
            ans = max(ans, dp[i][m]);
        }
        cout << ans << '\n';
    }
}
