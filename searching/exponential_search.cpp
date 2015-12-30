#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

template <typename T>
size_t ExponentialSearch( const vector<T>& arr, const size_t& begin, const size_t& end, const T& val )
{
	assert( arr.size() >= 0 );
	assert( begin < arr.size() );
	assert( end <= arr.size() );

	if ( val == arr[begin] )
	{
		return begin;
	}

	size_t upper_bound = begin + 2;

	while ( upper_bound < end && arr [upper_bound] <= val )
	{
		upper_bound <<= 1 ;
	}

	upper_bound = min( upper_bound, end );
	print( upper_bound );
	size_t result = BinarySearch( arr, upper_bound >> 1, min( upper_bound, end ), val );
	return ( result == upper_bound ) ? end : result;
}

int main()
{
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print( ExponentialSearch( arr, 0, arr.size(), 9 ) );
}
