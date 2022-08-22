#include <iostream>

using namespace std;

int arr[1000001];

int binarysearch(int start, int end) {
    if(start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if(arr[mid] == mid) {
        return mid;
    }

    if(arr[mid] > mid) {
        return binarysearch(start, mid - 1);
    }

    else {
        return binarysearch(mid + 1, end);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << binarysearch(0, n - 1) << '\n';
    return 0;
}
