#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;

/*********************************** Powmod begins ***********************************/

LL PowMod( LL base, LL exponent, const LL& mod )
{
	LL ans = 1;

	while ( exponent )
	{
		if ( exponent & 1 )
		{
			ans = MulMod( ans, base, mod );
		}

		base = MulMod( base, base, mod );
		base >>= 1;
	}

	return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********************************** Recursive Powmod begins ***********************************/

LL PowMod( const LL& base, const LL& exponent, const LL& mod )
{
	if ( exponent == 0 )
	{
		return 1;
	}

	if ( exponent & 1 )
	{
		LL temp = PowMod( base, exponent / 2 );
		return base * ( temp % mod * temp % mod ) % mod;
	}
	else
	{
		LL temp = PowMod( base, exponent / 2 );
		return ( ( temp % mod ) * ( temp % mod ) ) % mod;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********************************** Recursive PowMod begins ***********************************/

// This one works for -ve power too !!! :D
double MyPow( double base, int power )
{
	if ( power == 0 )
	{
		return 1.0;
	}
	if ( power == 1 )
	{
		return base;
	}
	if ( power == -1 )
	{
		return 1 / base;
	}
	if ( power % 2 == 0 )
	{
		return pow( base, power / 2 ) * pow( base, power / 2 );
	}
	return pow( base, power / 2 ) * pow( base, ( power / 2 ) + 1 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

}
