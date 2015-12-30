// Given "n", generate all the possible 2^n subsets of an array of size "n"

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

vector<size_t> GeneratePowerSet( const size_t& n )
{
	vector<size_t> powerset;

	const size_t size = 1 << n;
	for ( size_t i = 0; i < size; i++ )
	{
		powerset.push_back( i );
	}

	return powerset;
}

// Extracts the subset indices from the bitmask
vector<size_t> DecodeMask( size_t bitMask )
{
	vector<size_t> positions;

	size_t i = 0;

	while ( bitMask )
	{
		if ( bitMask & 1 )
		{
			positions.push_back( i );
		}

		bitMask >>= 1;
		i++;
	}

	return positions;
}

int main()
{
	size_t n = 5;

	auto vec = GeneratePowerSet( n );
	print( vec.size() );

	for ( size_t i = 0; i < vec.size(); i++ )
	{
		auto decode = DecodeMask( vec[i] );
		print( decode );
	}
}
