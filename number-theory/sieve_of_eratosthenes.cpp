#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;


/*********************************** Sieve of Eratosthenes begins ***********************************/

const size_t myMax = 100000;
vector<size_t> primeList;

void CreateSieve()
{
	vector<bool> primes( myMax + 1, true );

	for ( size_t p = 4; p <= myMax; p += 2 )
	{
		primes[p] = false;
	}

	size_t root = sqrt( myMax );

	for ( size_t p = 3; p <= root; p += 2 )
	{
		if ( primes[p] == true )
		{
			// Reason for i += 2*p instead of i += p -:
			// Since p and p*p, both are odd, (p*p + p) will be even,
			// which means that it would have already been marked before
			for ( size_t i = p * p; i <= myMax; i += 2 * p )
			{
				primes[i] = false;
			}
		}
	}
	
	for ( size_t i = 2; i <= myMax; i++ )
	{
		if ( primes[i] == true )
		{
			primeList.push_back( i );
		}
	}

	print( primeList.size() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********************************** Segmented Sieve of Eratosthenes begins ***********************************/

vector<size_t> primeList;

void CreateSieve( size_t lower, size_t upper )
{
	assert( upper >= lower );

	if ( lower < 2 )
	{
		lower = 2;
	}

	size_t root = sqrt( upper ), diff = upper - lower;
	vector<bool> primes( diff + 1, true );

	for ( size_t p = 2; p <= root; p++ )
	{
		size_t start = lower / p;
		start *= p;

		while ( start < lower )
		{
			start += p;
		}

		for ( size_t i = start; i <= upper; i += p )
		{
			if ( i != p )
			{
				primes[i - lower] = false;
			}
		}
	}

	for ( size_t i = 0; i <= diff; i++ )
	{
		if ( primes[i] == true )
		{
			primeList.push_back( lower + i );
		}
	}

	print( primeList.size() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********************************** Bit Sieve of Eratosthenes begins ***********************************/

#define isBitSet(x) ( flag[x >> 6] & ( 1 << ( (x >> 1) & 31 ) ) )
#define setBit(x) ( flag[x >> 6] |= ( 1 << ( (x >> 1) & 31 ) ) )

size_t myMax;
vector<int> flag;
vector<size_t> primeList;

void CreateSieve()
{
	flag.resize( ( myMax >> 6 ) + 1 );

	size_t root = sqrt( myMax );
	for ( size_t i = 3; i <= root; i += 2 )
	{
		if ( !isBitSet( i ) )
		{
			size_t k = i << 1;
			for ( size_t j = i * i; j < myMax; j += k )
			{
				setBit( j );
			}
		}
	}

	primeList.pb( 2 );
	for ( size_t i = 3; i < myMax; i += 2 )
	{
		if ( !isBitSet( i ) )
		{
			primeList.pb( i );
		}
	}

	print( primeList.size() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	CreateSieve();
}
