#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CongViec {
    char ten; // ten cong viec
    int d; // thoi han
    int p; // loi nhuan
    
    // Hàm khoi tao
    CongViec(char ten, int d, int p) : ten(ten), d(d), p(p) {}
};

bool compare(CongViec a, CongViec b) {
    return a.p > b.p;
}

void Thamlam(int n, vector<CongViec> &t, vector<int> &TruyVet) {
    sort(t.begin(), t.end(), compare);
    vector<bool> slot(n, false); 
    for (int i = 0; i < n; i++) {
        for (int j = min(n, t[i].d) - 1; j >= 0; j--) {
            if (!slot[j]) {
                TruyVet.push_back(i);
                slot[j] = true;
                break;
            }
        }
    }
}

int main() {
    vector<CongViec> t = {
        CongViec('A', 2, 100),
        CongViec('B', 1, 19),
        CongViec('C', 2, 27),
        CongViec('D', 1, 25),
        CongViec('E', 3, 15)
    };
    
    int n = t.size(); // so luong cong viec
    int tongLoiNhuan = 0;
    vector<int> TruyVet;
    Thamlam(n, t, TruyVet);
    
    if (!TruyVet.empty()) {
        for (int i = 0; i < TruyVet.size(); i++) {
            tongLoiNhuan += t[TruyVet[i]].p;
            cout << "Cong Viec " << t[TruyVet[i]].ten << " (Thoi han: " << t[TruyVet[i]].d << ", Loi nhuan: " << t[TruyVet[i]].p << ")" << endl;
        }
        cout << endl;
    }
    cout << "Tong loi nhuan cao nhat la: " << tongLoiNhuan << endl;
    
    return 0;
}

