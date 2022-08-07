#include <iostream>
#include <queue>

using namespace std;

int n;
int indegree[501];
vector<int> graph[501];
int timegraph[501];
vector<int> result;
int ans[501];

void topologySort() {
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]]--;
            if(indegree[graph[now][i]] == 0) {
                ans[graph[now][i]] += ans[now]; // 선수과목의 다음과목에 해당하는 수강시간은, 선수과목을 수행하기까지의 시간 + 자기자신의 수행시간(이거는 main에서 더해줬다.).
                q.push(graph[now][i]);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int time;
        cin >> time;
        timegraph[i] = time;
        while(1) {
            int sunsu;
            cin >> sunsu;
            if(sunsu == -1) {
                break;
            }
            graph[sunsu].push_back(i);
            indegree[i]++;
        }
    }

    for(int i = 1; i <= n; i++) { // 수업을 끝낼라면 기본적으로 자신의 수업번호에 해당하는 시간을 소요해야 하기 때문에.
        ans[i] += timegraph[i];
    }
    topologySort();

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
