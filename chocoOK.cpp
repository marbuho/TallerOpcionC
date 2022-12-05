//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1430
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, b, k, ans = 0;
		cin >> n >> b;
		while (b--)
		{
			cin >> k;
			int z = 1;
			while (k--)
			{
				int x;
				cin >> x;
				z *= x;
				z %= n;
			}
			ans += z;
			ans %= n;
		}
		cout << "->"<<ans << endl;
	}
}
