#include <iostream>

using namespace std;
int n = 8;
int b[8][8] = {{0}};


void inkq(int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int issafe(int row, int col, int b[][8]){
    for(int i = 0; i < row ; i++){
        if(b[i][col]==1){
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (b[i][j] == 1) {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (b[i][j] == 1) {
            return 0;
        }
    }
    return 1;
}

void Try(int i, int n, int b[][8]) {
    for (int j = 0; j < n; j++) {
       
        if(i == n ){
            inkq(n);
        }
        if(issafe(i,j,b)){
            b[i][j] = 1;
            Try(i + 1 , n , b);
            b[i][j] = 0;
        }
    }
}

int main(){
    Try(0,n,b);
    return 0;
}
