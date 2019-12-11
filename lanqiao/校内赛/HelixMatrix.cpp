#include <iostream>
using namespace std;

int getnum(int n, int m, int x, int y) 
{
	int lev = min(min(x, n - 1 - x), min(y, m - 1 - y));
	int d = x + y - lev * 2;
	int st = 2 * lev * (n + m - 2 * lev) + 1;
	if(x == lev || y == m - 1 - lev || (m < n && lev * 2 + 1 == m))
		return st + d;
	int nt = st + (n + m - 4 * lev - 2) * 2;
	return nt - d;
}

int main() 
{
	int n, m,x,y;
	cin >> n >> m>>x>>y; 
	cout<<getnum(n,m,x-1,y-1)<<endl;
	return 0;
}
