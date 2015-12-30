#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

/*

// The ratio in which the current search space is divided.
size_t ratio = ( ( val - arr[low] ) / arr[high] - arr[low] );

// This is not the middle element as the name suggests, but the element at which the search subspace has been divided, ie. the "pivot"
const size_t mid = low + ratio * ( high - low );

	OR

You can assume the distribution of values to be similar to a straight line, i.e y = m*x + c
where y = i
      x = arr[i]
Then, our job becomes to find "i" for a given arr[i], i.e to find "y" for a given "x".
	=> y = m * (x - x1) + c
	=> y = y1 + ((y2 - y1) / (x2 - x1)) * (x - x1)
	=> mid = low + ((high - low) / (arr[high] - arr[low])) * (val - arr[low])

Therefore, the more the distribution is similiar to a straight line (Arithmetic progression), the better the algorithm will perform.

*/
template<typename T>
size_t InterpolationSearch( const vector<T>& arr, const size_t& begin, const size_t& end, const T& val )
{
	assert( arr.size() >= 0 );

	size_t low = begin ;
	size_t high = end - 1 ;

	while ( arr [high] != arr [low] && val >= arr [low] && val <= arr [high] )
	{
		const size_t mid = low + ( ( val - arr [low] ) * ( high - low ) ) / ( arr [high] - arr [low] ) ;
		print( mid );

		if ( val > arr [mid] )
		{
			low = mid + 1 ;
		}
		else if ( val < arr [mid] )
		{
			high = mid - 1 ;
		}
		else
		{
			return mid ;  // val == arr[mid]
		}
	}

	if ( val == arr [low] )
	{
		return low ;
	}

	return arr.size() ; // val not found !!
}

int main()
{
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print( InterpolationSearch( arr, 0, arr.size(), 9 ) );
}
