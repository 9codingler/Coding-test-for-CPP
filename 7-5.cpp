#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> input1;
vector<int> input2;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        input1.push_back(tmp);
    }

    sort(input1.begin(), input1.end());

    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        input2.push_back(tmp);
    }

    for(int i = 0; i < m; i++) {
        int start = 0;
        int end = input1.size() - 1;
        int target = input2[i];
        while(1) {
            int mid = (start + end) / 2;

            if(target == input1[mid]) {
                cout << "yes" << '\n';
                break;
            }

            if(start > end) {
                cout << "no" << '\n';
                break;
            }

            else if (target < input1[mid]) {
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }
        }
    }

    return 0;
}
