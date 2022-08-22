#include <iostream>

using namespace std;

int arr[1000000];

int main() {
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = n - 1;
    bool flag = false;
    int mididx;
    while(1) {
        int mid = (start + end) / 2;

        if(arr[mid] == x) {
            mididx = x;
            break;
        }

        if(start > end) { //x를 못찾고 while 끝내는 경우.
            flag = true;
            break;
        }

        if(arr[mid] > x) {
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    if(flag) {
        cout << -1 << '\n';
        return 0;
    }

    else {
        //이분탐색 통해 왼쪽, 오른쪽 끝 찾기.
        int leftstart = 0;
        int leftend = mididx - 1;
        int rightstart = mididx + 1;
        int rightend = n - 1;

        int leftans, rightans;
        while(1) {
            if(leftstart > leftend) {
                break;
            }

            int leftmid = (leftstart + leftend) / 2;

            if(arr[leftmid] < x) {
                leftstart = leftmid + 1;
            }

            else { //arr[leftmid] == x인 경우도 leftend를 왼쪽으로 땡긴다.
                leftend = leftmid - 1;
            }
        }
        
        if(arr[leftstart] == x) { // 밑의 if문까지 둘 다 만족할 경우, 밑의 if문의 답으로 최신화되도록 if문 순서조정.
            leftans = leftstart;
        }

        if(arr[leftend] == x) {
            leftans = leftend;
        }

        while(1) {
            if(rightstart > rightend) {
                break;
            }

            int rightmid = (rightstart + rightend) / 2;

            if(arr[rightmid] > x) { //left랑 반대로 rightend, rightstart 움직임.
                rightend = rightmid - 1;
            }

            else {
                rightstart = rightmid + 1;
            }
        }

        if(arr[rightend] == x) {
            rightans = rightend;
        }

        if(arr[rightstart] == x) {
            rightans = rightstart;
        }

        cout << rightans << ' ';
        cout << leftans << '\n';
        cout << rightans - leftans + 1 << '\n';
    }
    return 0;
}
