#include <iostream>
using namespace std;
void hoanvi(int &x, int &y)
{
    int t=x;x=y;y=t;
}
void sapxep(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
    if(a[i]>a[j])
    hoanvi(a[i],a[j]);
}
int max(int x, int y)
{
    return x>y?x:y;
}
void thamlam(int a[], int n, int k, int &ketqua)
{
    sapxep(a,n);
	int m = n%k; //lan van chuyen thu nhât la n%k
	ketqua = max(0, a[m] - 1);
    for (int i=m+k; i<=n; i+=k)       
		ketqua = ketqua + a[i] - 1;
	ketqua = ketqua * 2;
}
int main() 
{
	int a[100], n, k, ketqua;
    cout<<"k= "; cin>>k;
    cout<<"n= "; cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }
	thamlam(a, n, k, ketqua);
	cout << "ket qua la: " << ketqua;
	cout << endl;
    return 0;
}