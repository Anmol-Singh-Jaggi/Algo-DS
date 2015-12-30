#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// 1. Find the highest index k such that str[k] < str[k+1]. If no such index exists, the permutation is the last permutation.
// 2. Find the highest index l > k such that str[l] > str[k]. Such an 'l' must exist, since k+1 is such an index.
// 3. Swap str[k] with str[l].
// 4. Reverse the order of all of the elements after index k
bool NextPermutation( string& str )
{
	bool nextPermutationExists = false;

	size_t k = 0;
	for ( size_t i = 0; i < str.size() - 1; i++ )
	{
		if ( str[i] < str[i + 1] )
		{
			k = i;
			nextPermutationExists = true;
		}
	}

	if ( !nextPermutationExists )
	{
		return false;
	}

	size_t l = 0;
	for ( size_t i = k + 1; i < str.size(); i++ )
	{
		if ( str[i] > str[k] )
		{
			l = i;
		}
	}

	swap( str[k], str[l] );
	reverse( str.begin() + k + 1, str.end() );

	return true;
}

int main()
{
	string s = "adbc";
	sort( s.begin(), s.end() );

	print( s );
	while ( NextPermutation( s ) )
	{
		print( s );
	}
}
