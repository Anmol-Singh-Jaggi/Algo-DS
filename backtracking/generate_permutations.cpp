#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef unsigned long long ULL;

// arr should be initialized with zeroes before calling this function
// Only arr[begin, end) will be used for the permutations
// The maximum value which an element will be able to take is "maxValue"
// The minimum value which an element will be able to take is "minValue"
// Total number of permutations = (maxValue - minValue + 1) ^ (end - begin)
void GeneratePermutations( vector<int>& arr, const size_t& begin, const size_t& end, const int& minValue, const int& maxValue, ULL& permutationCount )
{
	// Base case
	if ( begin == end )
	{
		permutationCount++;
		//cout << arr << endl;
		return;
	}

	for ( int value = minValue; value <= maxValue; value++ )
	{
		arr[begin] = value;
		GeneratePermutations( arr, begin + 1, end, minValue, maxValue, permutationCount );
	}
}

ULL Pow( const ULL& base, ULL power )
{
	ULL result = 1;
	while ( power )
	{
		result *= base;
		power--;
	}
	return result;
}

int main()
{
	vector<int> arr( 3, 0 );
	ULL permutationCount = 0;
	const int maxValue = 2;
	const int minValue = 0;

	GeneratePermutations( arr, 0, arr.size(), minValue, maxValue, permutationCount );
	print( permutationCount );

	assert( permutationCount == Pow( maxValue + 1, arr.size() ) );
}
