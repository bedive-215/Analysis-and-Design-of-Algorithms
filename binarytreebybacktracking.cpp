#include <iostream>

using namespace std;
char a[100];
int use[3]= {0};
int n; // do cao cua cay nhi phan
void inkq(){
	for(int i = 0; i < n;i++){
		cout << a[i];
	}
	cout << endl;
}

void Try(int i){
	char kitu[] = {'A','B','C'};
	if(i < n-1){
		for(int j = 0; j < 3; j++){
			if(use[j]==0){
				a[i] = kitu[j];
				use[j] = 1;
			}
			else{
				Try(i + 1);
			}
			use[j] = 0;
		}
	}
	else if(i == n-1){
		inkq();
	}
}

int main(){
	cin >> n;
	Try(0);
	return 0;
}
