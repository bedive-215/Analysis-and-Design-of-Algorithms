#include <iostream>
#include <vector>

using namespace std;
int a[] = {200,10,20,20,50,50,50,50,100,100};
int b[100] = {0};
vector<int> v;

void inkq(int n) {
    cout << "(";
    for (int i = 0; i < n - 1; i++) {
        cout << v[i] << ",";
    }
    cout << v[n - 1] << ")" << endl;
}

void Try(int i, int sum, int M, int n) {
    if (sum < M) {
        for (int j = i; j < n; j++) {
            v.push_back(a[j]);
            Try(j + 1, sum+a[j], M, n);
            v.pop_back();
        }
    } else if (sum == M) {
        inkq(v.size());
        return;
    }
}

int main() {
    Try(0, 0, 390, 10);
    return 0;
}
