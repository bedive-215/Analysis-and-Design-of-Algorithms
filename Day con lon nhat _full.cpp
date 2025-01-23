#include<iostream>
using namespace std;
void DP(int a[100], int n, int L[100], int T[100])
{
	int i, j, jmax;
	a[0] = INT_MIN; 
	a[n+1] = INT_MAX;
	L[n+1] = 1;//cs 
	for (int i = n; i >=0; i--)
	{
		jmax = n+1;
		for (j = i + 1; j <= n+1;j++)
		if ((a[j] > a[i]) && (L[j] > L[jmax]))
			jmax = j;
		L[i] = L[jmax] + 1;
		T[i] = jmax;
		 
	}
	
}
int main()
{
	int a[100], n, L[100], T[100];
	cout << "n= ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
	DP(a,n,L,T);
	cout << "Chieu dai: " << L[0] - 2<<endl;
	cout << "Day con tang dai nhat:" << endl;
	int i = T[0];
	while (i != n + 1)
	{
		cout <<"a["<<i<<"]= "<< a[i] << endl;
		i = T[i];
	}
	cout << endl;
	return 0;
}