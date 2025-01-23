#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDiff(vector<int>& arr, int left, int right) {
    if (left == right) {
        return 0;
    }
    int mid = (left+right) / 2;
    int maxDiffLeft = maxDiff(arr, left, mid);
    int maxDiffRight = maxDiff(arr, mid + 1, right);
    
    int tmp = arr[mid + 1] - arr[mid];
    int minLeft = arr[left];
    int maxRight = arr[right];
    
    for (int i = mid + 1; i <= right; i++) {
        tmp = max(tmp, arr[i] - minLeft);
        minLeft = min(minLeft, arr[i]);
    }
    
    for (int i = mid; i >= left; i--) {
        tmp = max(tmp, maxRight - arr[i]);
        maxRight = max(maxRight, arr[i]);
    }
    return max(maxDiffLeft, max(maxDiffRight, tmp));
}

int findMaxDiff(vector<int>& arr) {
    if (arr.size() < 2) {
        return 0;
    }
    
    return maxDiff(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {4, 2, 5, 8, 1, 7};
    int maxDiff = findMaxDiff(arr);
    cout << "Do lech lon nhat: " << maxDiff << endl;
    
    return 0;
}
