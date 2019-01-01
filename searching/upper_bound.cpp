#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

/*
1. Finds the LAST index in arr where we could insert a new element of value "val" without violating the ascending order.
2. If there is an element in arr with value STRICTLY greater than "val", return the index of the first such element; otherwise, return n.
		In other words, return {min(i) | arr[i]>c}, or n if that set is empty.
*/

template<typename T>
size_t UpperBound( const vector<T>& arr, const size_t& begin, const size_t& end, const T& val )
{
	assert( arr.size() >= 0 );
	assert( begin < arr.size() );
	assert( end <= arr.size() );

	size_t low = begin ;
	size_t high = end ;

	while ( low < high )
	{
		const size_t mid = low + ( high - low ) / 2;
		if ( arr[mid] > val )
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return low;
}

int main()
{
	vector<int> arr = {0, 1, 2, 3, 4, 4, 4, 6, 7, 8, 9};
	print( UpperBound( arr, 0, arr.size(), 4 ) );
}
