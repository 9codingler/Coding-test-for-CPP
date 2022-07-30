//특정위치에서 특정위치까지의 최소거리를 물어봤고, 각 노드에서의 비용이 각각 다르기 때문에 다익스트라 채택.
#include <iostream>
#include <queue>
#include <cstring>
#define INF 1e9
using namespace std;

int dx[] = {0, 1, 0, -1}; // 동 남 서 북
int dy[] = {1, 0, -1, 0};

int graph[125][125];
int d[125][125];

int n;

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(d[0][0], make_pair(0, 0)));
    
    while(!pq.empty()) {
        int dist = pq.top().first;
        int nowx = pq.top().second.first;
        int nowy = pq.top().second.second;
        pq.pop();

        if(d[nowx][nowy] < dist) {
            continue;
        }
        for(int i = 0; i < 4; i++) {
            int nx = nowx + dx[i];
            int ny = nowy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }

            int cost = dist + graph[nx][ny];

            if(cost < d[nx][ny]) {
                d[nx][ny] = cost;
                pq.push(make_pair(cost, make_pair(nx, ny)));
            }
        }
        
    }
}
int main() {
    int t;
    cin >> t;
    for(int k = 0; k < t; k++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        fill(&d[0][0], &d[124][125], INF);
        d[0][0] = graph[0][0];
        dijkstra();
        cout << d[n - 1][n - 1] << '\n';
        for(int i = 0; i <= n; i++) {
            memset(graph[i], 0, sizeof(int) * n);
        }
    }




    return 0;

}
