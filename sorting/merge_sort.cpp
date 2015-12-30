#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;


template<typename T>
void MergeSortMerge( vector<T>& arr, const size_t& begin, const size_t& mid, const size_t& end )
{
	// Less than 2 elements in the array
	if ( end - begin < 2 || end < begin )
	{
		return;
	}
	assert( mid >= begin );
	assert( mid < end );

	vector<T> arrTemp( end - begin );
	size_t leftIt = begin, rightIt = mid;
	size_t  arrTempIt = 0;

	// Merge arr[begin, mid) and arr[mid, end) and store that result in arrTemp
	while ( leftIt < mid && rightIt < end )
	{
		if ( arr[leftIt] < arr[rightIt] )
		{
			arrTemp[arrTempIt++] = arr[leftIt++];
		}
		else
		{
			arrTemp[arrTempIt++] = arr[rightIt++];
		}
	}

	// Copy any leftover elements in arr[left, mid)
	while ( leftIt < mid )
	{
		arrTemp[arrTempIt++] = arr[leftIt++];
	}

	// Copy any leftover elements in arr[mid, right)
	while ( rightIt < end )
	{
		arrTemp[arrTempIt++] = arr[rightIt++];
	}

	// Copy arrTemp back into arr[begin, end)
	for ( size_t i = begin, j = 0; i < end; i++, j++ )
	{
		arr[i] = arrTemp[j];
	}
}

template<typename T>
void MergeSort( vector<T>& arr, const size_t& begin, const size_t& end )
{
	// Less than 2 elements in the array
	if ( end - begin < 2 || end < begin )
	{
		return;
	}
	size_t mid = ( begin + end ) / 2;

	// Sort the left half [begin, mid)
	MergeSort( arr, begin, mid );
	// Sort the right half [mid, end)
	MergeSort( arr, mid, end );
	// Merge the two sorted halves into one
	MergeSortMerge( arr, begin, mid, end );
}

int main()
{
	vector<int> arr = {5, 1, 4, 2, 3};
	MergeSort( arr, 0, arr.size() );
	print( arr );
}
