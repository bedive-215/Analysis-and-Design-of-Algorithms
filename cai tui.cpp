#include<iostream>
#include<fstream>
using namespace std;
int w[100], v[100];
int k = 1, t = 1;
int n, m;
int F[100][100];
void doc_file(fstream &f)
{
	f.open("d://caitui1.txt", ios::in);
	f >> n;
	f >> m;
	while (!f.eof())
	{
		f >> w[k];
		f >> v[t];
		k++; t++;
	}
	f.close();
	/*cout << "n= " << n << endl;
	cout << "m= " << m << endl;
	for (int i = 1; i <= n; i++)
		cout << w[i] << " " << v[i] << endl;*/
}
int max2s(int a, int b)
{
	return a > b ? a : b;
}
void DP()
{
	for (int i = 1; i <= n;i++)
	for (int j = 1; j <= m;j++)
		
	if (w[i] < j)
		F[i][j] = max2s(F[i - 1][j], F[i - 1][j - w[i]] + v[i]);
	else
		F[i][j] = F[i - 1][j];
}
int main()
{
	fstream f;
	doc_file(f);
	DP();
	cout << F[n][m]<<endl;
	while (n != 0)
	{
		if (F[n][m] != F[n - 1][m])
		{
			cout << n << " ";
			m = m - w[n];
		}
		n--;
	}
	cout << endl;
	return 0;
}
