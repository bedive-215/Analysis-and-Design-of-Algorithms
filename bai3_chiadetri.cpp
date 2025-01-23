#include <iostream>
#include <vector>
using namespace std;

int tim(int a[], int left, int right, vector<int> &b){
    int mid = (left+right) / 2;
	if(left < right){
	    tim(a,left,mid,b);
	    tim(a,mid+1,right,b);
	}
	else if (left == right){
	   if(a[left]==left){
	       b.push_back(left);
	       return 1;
	   }
	   return 0;
	}
}

int main(){
	vector<int> b;
    int a[8] = {0,3,3,5,4,5,3,3};
    tim(a,0,7,b);
    if(!b.empty()){
    	for(int i = 0; i!= b.size();i++){
    		cout << b[i] << " ";
		}
	}
    return 0;
}
