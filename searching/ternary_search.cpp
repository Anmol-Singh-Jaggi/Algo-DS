#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

template<typename T>
size_t TernarySearch( const vector<T>& arr, const size_t& begin, const size_t& end, const T& val )
{
	assert( arr.size() >= 0 );
	assert( begin < arr.size() );
	assert( end <= arr.size() );

	size_t low = begin ;
	size_t high = end ;

	while ( low < high )
	{
		const size_t mid1 = low + ( high - low ) / 3;
		const size_t mid2 = low + 2 * ( high - low ) / 3;
		if ( val == arr[mid1] )
		{
			return mid1;
		}
		else if ( val == arr[mid2] )
		{
			return mid2;
		}
		if ( val > arr[mid2] )
		{
			low = mid2 + 1;
		}
		else if ( val < arr[mid1] )
		{
			high = mid1;
		}
		else
		{
			low = mid1 + 1;
			high = mid2;
		}
	}

	return end; // not found
}

int main()
{
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print( TernarySearch( arr, 0, arr.size(), 9 ) );
}
