#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m;
int map[101][101];

int main() {
    cin >> n >> m;

    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            map[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                map[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        int nd1, nd2;
        cin >> nd1 >> nd2;
        map[nd1][nd2] = 1;
        map[nd2][nd1] = 1;
    }

    int x, k;
    cin >> x >> k;

    for(int l = 1; l <= n; l++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                map[i][j] = min(map[i][j], map[i][l] + map[l][j]);
            }
        }
    }

    int ans = map[1][k] + map[k][x];

    if(ans >= INF) {
        cout << -1 << '\n';
        return 0;
    }

    else {
        cout << ans << '\n';
        return 0;
    }
}
