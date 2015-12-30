#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long ULL;

double Pow( const double& base, ULL power )
{
	ULL result = 1;
	while ( power )
	{
		result *= base;
		power--;
	}
	return result;
}

double StringToDouble( string str )
{
	size_t i = 0;

	// sign of the final answer
	int sign = ( str[i] == '-' ) ? -1 : 1;

	if ( str[i] == '+' || str[i] == '-' )
	{
		i++;
	}

	//value before '.'/'e'
	double val = 0.0;

	double div10 = 1.0;
	ULL mul10 = 0;

	while ( 1 )
	{
		if ( str[i] == '.' )
		{
			++i;
			while ( i < str.size() )
			{
				val = val * 10 + ( str[i] - '0' );
				div10 *= 10;
				i++;
			}
		}

		if ( str[i] == 'e' )
		{
			++i;
			int sign2 = ( str[i] == '-' ) ? -1 : 1;
			if ( str[i] == '+' || str[i] == '-' )
			{
				i++;
			}
			while ( i < str.size() )
			{
				mul10 = mul10 * 10 + ( str[i] - '0' );
				i++;
			}
			mul10 *= sign2;
		}

		if ( i < str.size() )
		{
			return sign * val / div10 * Pow( 10.0, mul10 );
		}
		val = val * 10 + ( str[i] - '0' );
		i++;
	}

	return NAN;
}

int main()
{
	print( StringToDouble( "12" ) );
}
