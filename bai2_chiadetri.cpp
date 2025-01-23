#include <iostream>
using namespace std;

int find_peak(int arr[], int low, int high)
{
    int mid = (low + high) / 2;

    if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        return arr[mid];
    
    if (arr[mid] < arr[mid + 1])
        return find_peak(arr, mid + 1, high);
    
    return find_peak(arr, low, mid - 1);
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peak = find_peak(arr, 0, n - 1);

    cout << "Phan tu dau tien giam va lon nhat la: " << peak << endl;

    return 0;
}
