#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Selection Sort works by finding the lowest element and inserting it into the front of the array,
// then finding the second lowest element and inserting it into the 2nd position, and so on

template<typename T>
void SelectionSort( vector<T>& arr, const size_t& begin, const size_t& end )
{
	for ( size_t i = begin; i < end; i++ )
	{
		std::swap( *min_element( arr.begin() + i, arr.end() ), arr[i] );
	}
}

int main()
{
	vector<int> arr = {5, 1, 4, 2, 3};
	SelectionSort( arr, 0, arr.size() );
	print(arr);
}
