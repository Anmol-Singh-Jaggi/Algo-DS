#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

pair<size_t, size_t> knapsack( const vector<size_t>& weights, const vector<size_t>& values, const size_t& weight )
{
	/*..........................................................
	..... weights[] and values[] should be 1-indexed !!!!! .....
	..........................................................*/

	// Stores the values
	// dpValues[i][j] = The maximum value that can be achieved from the first 'i' items and a bag of capacity 'j'

	vector<vector<size_t> > dpValues( 2, vector<size_t> ( weight + 1, 0 ) );
	// Stores the weights
	// dpWeights[i][j] = The weights of all the items in the optimal solution set upto that point
	// It is required to include the item with lesser weight in case two items have the same value,
	// so that the solution set has the minimum weight among all the solution sets with the maximum value
	vector<vector<size_t> > dpWeights = dpValues;

	// Required for calculating the indices of items in the solution set
	// keep[i][j] = true, if item 'i' is to be included in a bag of capacity 'j'
	// false, otherwise
	vector<vector<bool> > keep( weights.size(), vector<bool> ( weight + 1, false ) );

	// Iterate over all the items
	for ( size_t i = 1; i < weights.size(); i++ )
	{
		// Iterate over all the weight possibilities of the optimal solution set
		for ( size_t j = 0; j <= weight; j++ )
		{
			dpValues[i & 1][j] = dpValues[( i - 1 ) & 1][j];
			dpWeights[i & 1][j] = dpWeights[( i - 1 ) & 1][j];

			// If the current item is not larger than the bag itself
			if ( weights[i] <= j )
			{
				// If the solution set after including the current item has higher value than the one without it,
				// include the current item
				if ( dpValues[( i - 1 ) & 1][j - weights[i]] + values[i] > dpValues[( i - 1 ) & 1][j] )
				{
					dpValues[i & 1][j] = dpValues[( i - 1 ) & 1][j - weights[i]] + values[i];
					dpWeights[i & 1][j] = dpWeights[( i - 1 ) & 1][j - weights[i]] + weights[i];
					keep[i][j] = true;
				}
				else if ( dpValues[( i - 1 ) & 1][j - weights[i]] + values[i] == dpValues[( i - 1 ) & 1][j] )
				{
					if ( dpWeights[( i - 1 ) & 1][j - weights[i]] + weights[i] < dpWeights[( i - 1 ) & 1][j] )
					{
						dpWeights[i & 1][j] = dpWeights[( i - 1 ) & 1][j - weights[i]] + weights[i];
						keep[i][j] = true;
					}
				}
			}
		}

		dpValues[( i + 1 ) & 1] = dpValues[i & 1];
		dpWeights[( i + 1 ) & 1] = dpWeights[i & 1];
	}

	// Indices of items selected for the knapsack ( 1-indexed )
	vector<size_t> chosenOnes;

	// Calculating chosenOnes
	for ( size_t i = weights.size() - 1, j = weight; i >= 1; i-- )
	{
		if ( keep[i][j] )
		{
			chosenOnes.push_back( i );
			j = j - weights[i];
		}
	}

	print( chosenOnes );
	return mp( dpWeights[( weights.size() - 1 ) & 1][weight], dpValues[( weights.size() - 1 ) & 1][weight] );
}

int main()
{
	vector<size_t> weights = {0, 5, 4, 6, 3};
	vector<size_t> values = {0, 10, 40, 30, 50};
	print( knapsack( weights, values, 10 ) );
}
