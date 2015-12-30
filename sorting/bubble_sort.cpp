#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Bubble sort works by finding the highest element and shifting it to the end through a series of multiple swaps,
// then repeating it on the rest of the array.

template<typename T>
void BubbleSort( vector<T>& arr, const size_t& begin, const size_t& end )
{
	for ( size_t i = begin, k = 0; i < end - 1 ; i++ )
	{
		bool isSorted = true;
		// The last k elements are sorted already
		for ( size_t j = begin; j < end - 1 - k; j++ )
		{
			if ( arr[j] > arr[j + 1] )
			{
				swap( arr[j], arr[j + 1] );
				isSorted = false;
			}
		}
		if ( isSorted )
		{
			break;
		}
	}
}

int main()
{
	vector<int> arr = {5, 1, 4, 2, 3};
	BubbleSort( arr, 0, arr.size() );
	print(arr);
}
