#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

#define isBitSet(num, pos) ((num) & ((unsigned long long)1 << (pos)))

// size  = Number of bits to show
// If size = 0, the number of bits shown would be equal to some default value
template<typename T>
string DecimalToBinary( const T& num, const size_t size = 0 )
{
	assert( size <= 64 );

	string result;

	for ( size_t i = 0; i < 64; i++ )
	{
		if ( isBitSet( num, i ) )
		{
			result += '1';
		}
		else
		{
			result += '0';
		}
	}

	if ( result.empty() )
	{
		result = '0';
	}

	if ( size )
	{
		result = result.substr( 0, size );
	}

	reverse( result.begin(), result.end() );

	return result;
}

// size  = Number of bits to show
// If size = 0, the number of bits shown would be equal to some default value
template<typename T>
string DecimalToBinaryBitset( const T& num, const size_t size = 0 )
{
	assert( size <= 64 );

	stringstream ss;
	ss << bitset<64> ( num );
	string result = ss.str();

	if ( size )
	{
		result = result.substr( result.size() - size );
	}

	return result;
}

int main()
{
	long long num = 10;
	cout << DecimalToBinary( num ) << endl;
	cout << DecimalToBinaryBitset( num ) << endl;
}
