#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& a, int left, int right) {
    int i, j, x;
    x = a[(left + right) / 2];
    i = left;
    j = right;
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    } while (i < j);
    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

void inkq(const vector<int>& tmp) {
    if (!tmp.empty()) {
        for(int i = 0; i < tmp.size(); i++){
        	cout << tmp[i] << " ";
		}
		cout << endl;
    } else {
        cout << "Khong co cau hinh nao thoa man." << endl;
    }
}

void Try(const vector<int>& a, int index, int target, vector<int>& tmp) {
    if (target == 0) {
        inkq(tmp);
        exit(0);
    }
    for (int i = index; i < a.size(); i++) {
        if (i > index && a[i] == a[i - 1]) {
            continue;
        }
        if (a[i] > target) {
            break;
        }
        tmp.push_back(a[i]);
        Try(a, i + 1, target - a[i], tmp);
        tmp.pop_back();
    }
}

int main() {
    vector<int> a = {200, 10, 20, 20, 50, 50, 50, 50, 100, 100};
    QuickSort(a, 0, a.size() - 1);
    vector<int> tmp;
    int target = 390;
    Try(a, 0, target, tmp);
    return 0;
}

