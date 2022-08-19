#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

vector<int> v;

int main() {
    int n, target;
    cin >> n >> target;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = v[v.size() - 1];
    int ans;

    while(1) {
        if(start > end) {
            break;
        }

        int mid = (start + end) / 2;
        long long int sum = 0;

        for(int i = 0; i < n; i++) {
            if(v[i] > mid) {
                sum += v[i] - mid;
            }
        }

        // 다 짤랐는데 target보다 작으면-> mid를 줄여서 각각 짤리는 떡을 길게한다.
        if(sum < target) {
            end = mid - 1;
        }
        
        else {
            ans = mid;
            start = mid + 1;
        }
    }   

    cout << ans << '\n';
}
