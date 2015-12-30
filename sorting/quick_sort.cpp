#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;


/*
1). Qsort works by taking any element of the array as a reference and dividing the rest of the array in 2 partitions.
2). The left partition has all the values less than it and the right partition greater than it.
3). Then this process is repeated for these 2 partitions.
*/

template<typename T>
void QuickSortPartition( vector<T>& arr, const size_t& begin, const size_t& end, size_t& pivotPos )
{
	assert( end <= arr.size() );
	assert( pivotPos < end );
	assert( pivotPos >= begin );

	// Array size less than 2
	if ( end - begin < 2 || end < begin )
	{
		return;
	}

	// Bring the pivot element to the beginning to keep it safe ! :p
	swap( arr[begin], arr[pivotPos] );

	pivotPos = begin;

	// Shift all the elements lower than the pivot element to the front of the array
	for ( size_t i = begin + 1; i < end; i++ )
	{
		if ( arr[i] < arr[begin] )
		{
			swap( arr[i], arr[++pivotPos] );
		}
	}

	// Restore the pivot element
	swap( arr[begin], arr[pivotPos] );
}

template<typename T>
void QuickSort( vector<T>& arr, const size_t& begin, const size_t& end )
{
	assert( end <= arr.size() );

	// Array size less than 2
	if ( end - begin < 2 || end <= begin )
	{
		return;
	}

	size_t pivotPos = ( begin + end ) / 2;
	QuickSortPartition( arr, begin, end, pivotPos );
	if ( pivotPos )
	{
		// Sort the left partition.( This partition holds values LESS than the pivot element )
		QuickSort( arr, begin, pivotPos );
	}
	// Sort the right partition.( This partition holds values HIGHER than the pivot element )
	QuickSort( arr, pivotPos + 1, end );
}

int main()
{
	vector<int> arr = {5, 1, 4, 2, 3};
	QuickSort( arr, 0, arr.size() );
	print( arr );
}
