#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Number of permutations = factorial(str.length())
void Permute( string& str, const size_t& begin, const size_t& end, size_t& permutationCount )
{
	if ( begin == end )
	{
		permutationCount++;
		cout << str << "\n";
	}
	else
	{
		for ( size_t i = begin; i < end; i++ )
		{
			swap( str[i], str[begin] );
			Permute( str, begin + 1, end, permutationCount );
			swap( str[begin], str[i] );
		}
	}
}

size_t Factorial( const size_t num )
{
	size_t i = 1, result = 1;
	while ( i <= num )
	{
		result *= i;
		i++;
	}
	return result;
}

int main()
{
	string str = "anmol";
	size_t permCount = 0;
	Permute( str, 0, str.size(), permCount );
	print( permCount );
	print( Factorial( str.size() ) );
	assert( permCount == Factorial( str.size() ) );
}
