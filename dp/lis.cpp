#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Returns the length of the LIS
template<typename T>
size_t Lis( vector<T>& arr )
{
	// dp[i] -> Length of the LIS upto arr[i]
	vector<size_t> dp( arr.size(), 1 );

	// parent[i] => index of the predecessor of arr[i] in the resulting LIS
	// Used just for printing the LIS
	vector<size_t> parent( arr.size(), 0 );

	// Initialize parent[]
	for ( size_t i = 0; i < parent.size(); i++ )
	{
		parent[i] = i;
	}

	for ( size_t i = 0; i < arr.size(); i++ )
	{
		for ( size_t j = 0; j < i; j++ )
		{
			if ( arr[j] < arr[i] )
			{
				if ( dp[j] + 1 > dp[i] )
				{
					// Include arr[i] into the LIS just after arr[j]
					dp[i] = dp[j] + 1;
					parent[i] = j;
				}
			}
		}
	}

	// Main algo done !!
	// Now the printing part

	size_t endOfLis = max_element( dp.begin(), dp.end() ) - dp.begin();
	size_t lengthOfLis = dp[endOfLis];

	stack<size_t> LisIndices;
	while ( 1 )
	{
		LisIndices.push( endOfLis );
		if ( parent[endOfLis] == endOfLis )
		{
			break;
		}
		endOfLis = parent[endOfLis];
	}

	cout << "The LIS is -:\n";
	while ( !LisIndices.empty() )
	{
		size_t index = LisIndices.top();
		cout << arr[index] << "(" << index << ") ";
		LisIndices.pop();
	}
	cout << endl;

	return lengthOfLis;
}

int main()
{
	vector<int> arr = {1, 2, 3, 2, 5, 4, 5};
	print( Lis( arr ) );
}
