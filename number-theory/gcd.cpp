#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;

size_t GCD( size_t first, size_t second )
{
	if ( second == 0 )
	{
		return first;
	}

	return GCD( second, first % second );
}

int main()
{

}
