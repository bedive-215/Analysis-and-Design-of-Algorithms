#include<bits/stdc++.h>
using namespace std;
int w[100], v[100];
int k = 1, t = 1;
int n, M;
int F[100][100];
void doc_file(fstream &f)
{
	f.open("d://caitui.txt", ios::in);
	f >> n;
	f >> M;
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

void DP()
{
	memset(F, 0, sizeof F);
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= M; j++)
	{
		F[i][j] = F[i - 1][j];//Khong chon vat thu i thi cap nhat lai truoc do
		if ((j >= w[i]) && (F[i - 1][j - w[i]] + v[i]))//chon vat i loi hon thi dat lai
			F[i][j] = F[i - 1][j - w[i]] + v[i];
	}
}
int main()
{
	fstream f;
	doc_file(f);
	DP();
	cout << F[n][M] << endl;
	while (n != 0)
	{
		if (F[n][M] != F[n - 1][M])
		{
			cout << n << " ";
			M = M - w[n];
		}
		n--;
	}
	cout << endl;
	return 0;
}
