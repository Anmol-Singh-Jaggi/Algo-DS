#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Insertion Sort works by sorting first "i" elements as "i" goes from 1 -> size...
// It finds the correct position of arr[i] and shifts all the elements after the correct position before placing arr[i] in its correct slot.
// I have used int instead of size_t for the iterators because using size_t would cause a noticeable increase in the code complexity.

template<typename T>
void InsertionSort( vector<T>& arr, const int& begin, const int& end )
{
	assert( end <= ( int )arr.size() );
	assert( begin >= 0 );

	for ( int i = begin; i < end; i++ )
	{
		int j = i - 1;
		T bak = arr[i];
		// Right-shift all the elements before i which are greater than bak
		while ( j >= begin && arr[j] > bak )
		{
			arr[j + 1] = arr[j];
			j--;
		}
		// Insert n[i] into its correct position
		arr[j + 1] = bak;
	}
}
int main()
{
	vector<int> arr = {5, 1, 4, 2, 3};
	InsertionSort( arr, 0, arr.size() );
	print(arr);
}
