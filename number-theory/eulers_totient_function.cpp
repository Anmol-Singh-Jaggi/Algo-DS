#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;

// Complexity = O(sqrt(num))

size_t ETF( size_t num )
{
	size_t ans = num;

	for ( size_t i = 2; i * i <= num; i++ )
	{
		if ( num % i == 0 )
		{
			ans -= ans / i;
		}
		while ( num % i == 0 )
		{
			num /= i;
		}
	}

	if ( num > 1 )
	{
		ans -= ans / num;
	}

	return ans;
}

int main()
{

}
