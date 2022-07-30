#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;

int n, m, start;
vector<pair<int, int>> graph[30001]; //인덱스는 노드를 가리킴. (거리 , 연결노드) pair 들어감.
int d[30001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    while(!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist) { //갱신 안되면
            continue;
        }
        for(int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;

            if (cost < d[graph[now][i].first]) { //갱신 되면.
                d[graph[now][i].first] = cost;
                pq.push(make_pair(cost, graph[now][i].first));
            }
        }
    }
}

int main() {
    cin >> n >> m >> start;
    
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
    }

    fill(d, d + 30001, INF);
    dijkstra(start);

    int count = 0;
    int maxdistance = 0;
    for(int i = 1; i <= n; i++) {
        if(d[i] != INF) {
            count++;
            maxdistance = max(maxdistance, d[i]);
        }
    }

    count--; //위의 for문에서 시작노드까지 count에 포함되므로 마지막에 count--.
    cout << count << ' ' << maxdistance << '\n';
    return 0;
}
