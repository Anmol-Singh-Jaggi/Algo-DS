#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

template<typename T>
size_t BinarySearch( const vector<T>& arr, const size_t& begin, const size_t& end, const T& val )
{
	assert( arr.size() >= 0 );
	assert( begin < arr.size() );
	assert( end <= arr.size() );

	size_t low = begin ;
	size_t high = end ;

	while ( low < high )
	{
		const size_t mid = low + ( high - low ) / 2;
		if ( val > arr[mid] )
		{
			low = mid + 1;
		}
		else if ( val < arr[mid] )
		{
			high = mid;
		}
		else
		{
			return mid;
		}
	}

	return end; // not found
}

int main()
{
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print( BinarySearch( arr, 0, arr.size(), 9 ) );
}
