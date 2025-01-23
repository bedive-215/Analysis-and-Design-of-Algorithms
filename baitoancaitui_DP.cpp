#include <iostream>
#include <vector>

using namespace std;


void solution(int n, int s, int w[], int v[]) {
	
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][s] << endl;

    // Truy vet
    vector<int> picked_items;
    for (int i = n, j = s; i > 0 && j > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            picked_items.push_back(i);
            j -= w[i];
        }
    }

    // In ra ket qua truy vet
    cout << "Cac mon hang duoc chon: ";
    for (int i = picked_items.size() - 1; i >= 0; i--) {
        cout << picked_items[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;


    int s;
    cout << "Nhap vao khoi luong cai tui dung duoc: ";
    cin >> s;

    int w[n + 1], v[n + 1];

    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];

    solution(n, s, w, v);

    return 0;
}

