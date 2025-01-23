#include <iostream>

using namespace std;

double Middle(int k[], int n){
	int mid = (n-1)/2;
	if(n%2==0){
		return (float)(k[mid]+k[mid+1])/2.0;
	}
	return k[mid];
}

void merge(int a[],int b[],int c[], int n){
	int i = 0, j = 0 , k = 0;
	while(i < n && j < n){
		if(a[i]<=b[j]){
			c[k++] = a[i++];
		}
		else{
			c[k++] = b[j++];
		}
	}
	while(i<n){
		c[k++] = a[i++];
	}
	while(j<n){
		c[k++] = b [j++];
	}
	
}

int main(){
	int n = 5;
	int a[n] = {1, 4, 5, 6, 10};
	int b[n] = {2, 3, 4, 5, 7};
	int c[n*2];
	merge(a,b,c,n);
	cout << Middle(c,n*2);
	return 0;
}
