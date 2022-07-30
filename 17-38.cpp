// 성적 낮은 학생이 성적 높은학생을 가리키는 방향 그래프 표현 가능. -> 최단경로 문제.
// 다익스트라? 플로이드? -> '모든 노드'에 대하여 다른 노드와 도달 가능성을 따지는 것이므로, 다익스트라 x, 플로이드 o.
// 시간제한이 5초이므로, n = 500 => O(n^3)에 해당하는 플로이드 사용 가능.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int graph[501][501];
int arr[501];

int main() {
    int n, m, ans = 0;
    cin >> n >> m;

    fill(&graph[0][0], &graph[500][501], INF); //항상 row에 해당하는건 최대크기 -1로 해줘야함. 아니면 다른 배열에 쓰레기값이 차더라.

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                graph[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    //여기까지 기본적인 플로이드.

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                continue;
            }

            if(graph[i][j] != INF || graph[j][i] != INF) { //해당 노드보다 큰게 있다면 || 해당 노드보다 작은게 있다면 -> 해당노드와 크기 비교가 가능하므로 해당 노드의 비교수 추가.
                arr[i]++;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(arr[i] == n - 1) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
