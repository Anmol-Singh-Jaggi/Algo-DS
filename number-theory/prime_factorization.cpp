#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;


/*********************************** Prime factorization begins ***********************************/

void primeFact( size_t num )
{
	// for ( size_t j = 0, i = 2; i * i <= num; i = primelist[++j] ) // sieve version
	for ( size_t i = 2; i * i <= num; i++ ) // Works faster with the help of sieve
	{
		while ( num % i == 0 )
		{
			cout << i;
			if ( i < num )
			{
				cout << "x";
			}
			num /= i;
		}
	}

	if ( num != 1 )
	{
		cout << num;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********************************** Prime factorization using map begins ***********************************/

// Primefact using std::map
typedef map<size_t, size_t> factorTable;

factorTable primeFact( size_t num )
{
	factorTable fTable;
	for ( size_t j = 0, i = 2; i * i <= num; i = primeList[++j] )
	{
		if ( num % i == 0 )
		{
			size_t temp = 0;
			while ( num % i == 0 )
			{
				num /= i;
				temp++;
			}
			fTable[i] = temp;
		}
	}

	if ( num != 1 )
	{
		fTable[num]++;
	}

	return fTable;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	PrimeFact( 100 );
}
