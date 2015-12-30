#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;
/*********************************** Fastest Mulmod begins ***********************************/

// Works on magic
LL MulMod( const LL& first, const LL& second, const LL& mod )
{
	LL res = ( first * ( ( LD ) second / ( LD ) mod ) );
	res = first * second - res * mod;
	if ( res >= mod )
	{
		res -= mod;
	}
	if ( res < 0 )
	{
		res += mod;
	}
	return res;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********************************** Ethiopian Mulmod begins ***********************************/

LL EthiopianMul( LL first, LL second, const LL& mod )
{
	LL ans = 0;
	second %= mod;

	while ( first )
	{
		if ( first & 1 )
		{
			ans = ( ans + second ) % mod;
		}

		first >>= 1;
		second = ( second << 1 ) % mod;
	}

	return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********************************** Mulmod begins ***********************************/

// Calculate (first * second) % mod
LL MulMod( LL first, LL second, const LL& mod )
{
	LL ans = 0;
	first %= mod;

	while ( second )
	{
		if ( second & 1 )
		{
			ans = ( ans + first ) % mod;
		}

		first = ( first << 1 ) % mod;
		second >>= 1;
	}

	return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

}
