#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int minCostRecursion(vector<vector<int>>& C, int x, int y, int n) {
    if (x == C.size() - 1 && y == C[0].size() - 1) {
        return C[x][y];
    }
    if (n == 0) {
        return C[x][y];
    }
    int trenxuong = (x + 1 < C.size()) ? minCostRecursion(C, x + 1, y, n - 1) : INF;
    int phaiqua = (y + 1 < C[0].size()) ? minCostRecursion(C, x, y + 1, n - 1) : INF;
    int cheo = (x + 1 < C.size() && y + 1 < C[0].size()) ? minCostRecursion(C, x + 1, y + 1, n - 1) : INF;
    return min(min(trenxuong, phaiqua), cheo) + C[x][y];
}


int main() {
    vector<vector<int>> C = {
        {2, 3, 4},
        {5, 9, 3},
        {2, 6, 4}
    };

    int x = 0, y = 0;
    cout << "Chi phi duong di thap nhat den (" << x << ", " << y << ") la: " << minCostRecursion(C, x, y, C.size()) << endl;
    return 0;
}

