#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

void CountSort( vector<size_t>& arr, const size_t& begin, const size_t& end )
{
	if ( arr.empty() )
	{
		return;
	}

	vector<size_t> freq( *max_element( arr.begin() + begin, arr.begin() + end ) + 1 );

	// Calculate the frequencies of each element
	for ( size_t i = begin; i < end; i++ )
	{
		freq[arr[i]]++;
	}

	// Calculate the cumulative frequencies
	for ( size_t i = 1; i < freq.size(); i++ )
	{
		freq[i] += freq[i - 1] ;
	}

	// Temporary array to store the sorted array
	vector<int> sortedArr( end - begin );

	// Calculate the sorted array
	for ( int i = end - 1; i >= ( int )begin; i-- )
	{
		size_t& sortedArrIndex = freq[arr[i]];
		sortedArr[--sortedArrIndex] = arr[i];
	}

	// Copy the sorted array back into the input array
	for ( size_t i = begin, j = 0; i < end; i++, j++ )
	{
		arr[i] = sortedArr[j];
	}

}

int main()
{
	vector<size_t> arr = {5, 1, 4, 2, 3, 1, 5, 4, 3, 2};
	CountSort( arr, 0, arr.size() );
	print( arr );
}
