#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int noiDay(vector <int> a){
	int chiphi = 0;
	sort(a.begin(), a.end());
	while(a.size() > 1){
		// chu y chi them doan noi 2 doan day khong pk la tong cua ca doan day noi tu dau den cuoi
		int cost = a[0] + a[1];
		chiphi += cost;
		a.erase(a.begin());
		a.erase(a.begin());
		a.push_back(cost);
		sort(a.begin(), a.end());
	}
	return chiphi;
}

int main(){
	vector<int> day = {4,3,2,6};
	cout << noiDay(day);
	return 0;
}
