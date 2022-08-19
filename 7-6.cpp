#include <iostream>
#include <vector>
using namespace std;

int arr[1000001];
vector<int> targets;

int main() {
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp] = 1;
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }

    for(int i = 0; i < m; i++) {
        if(arr[targets[i]] == 1) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}
