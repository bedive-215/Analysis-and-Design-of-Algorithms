#include<iostream>
using namespace std;

int dem(int a[], int left, int right, int x){
    if(left==right){
        if(a[left]==x) return 1;
        else return 0;
    }
    int mid = (left+right)/2;
    return dem(a,left,mid,x) + dem(a,mid+1,right,x);
}

int main(){
    int a[8] = {1,3,3,5,4,7,3,3};
    cout << dem(a,0,7,3);
    return 0;
}

