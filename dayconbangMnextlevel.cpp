#include <iostream>
#include <vector>
using namespace std;

void Try(vector<int> &a, int index, int target, vector<int> &tmp, vector<vector<int>> &res){
	if(target == 0){
		res.push_back(tmp);
		return;
	}
	for(int i = index; i < a.size();i++){
//		if(i > index && a[i] == a[i-1]){
//			continue;
//		}
		if(target - a[i] >= 0){
			tmp.push_back(a[i]);
			Try(a,i+1,target - a[i],tmp,res);
			tmp.pop_back();
		}
	}
}

void inkq(vector<vector<int>> res){
	for (const vector<int>& subsequence : res) {
    	cout << "(";
    	for (int i = 0; i < subsequence.size() - 1; i++) {
        	cout << subsequence[i] << ", ";
    	}
    	cout << subsequence.back() << ")" << endl;
	}
}
int main(){
	vector<int> a = {7, 1, 4, 3, 5, 6};
	vector<int> tmp;
	vector<vector<int>> res;
	int target = 11;
	Try(a,0,target,tmp,res);
	inkq(res);
	return 0;
}
