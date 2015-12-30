#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

const int INF = INT_MAX;

// Complexity -> O(V^3)
void FloydWarshal( vector<vector<int> >& adjMatrix )
{

	/* Add all vertices one by one to the set of intermediate vertices.
	   Before start of a iteration, we have shortest distances between all
	   pairs of vertices such that the shortest distances consider only the
	   vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
	   After the end of a iteration, vertex no. k is added to the set of
	   intermediate vertices and the set becomes {0, 1, 2, .. k}
	*/
	for ( size_t k = 0; k < adjMatrix.size(); k++ )
	{
		// Pick all vertices as source one by one
		for ( size_t i = 0; i < adjMatrix.size(); i++ )
		{
			// Pick all vertices as destination for the above picked source
			for ( size_t j = 0; j < adjMatrix.size(); j++ )
			{
				int temp = INF;

				// If vertex k is on the shortest path from i to j,
				// then update the value of adjMatrix[i][j]
				if ( adjMatrix[i][k] != temp && adjMatrix[k][j] != temp )
				{
					temp = adjMatrix[i][k] + adjMatrix[k][j];
				}
				adjMatrix[i][j] = min( adjMatrix[i][j], temp );
			}
		}
	}

	// Checking for -ve weight cycles -:

	// Check if the diagonal elements are -ve
	for ( size_t i = 0; i < adjMatrix.size(); i++ )
	{
		if ( adjMatrix[i][i] < 0 )
		{
			cout << "The graph contains negative-weight cycles!\n";
			break;
		}
	}
}

int main()
{
	vector<vector<int> > adjMatrix;
	adjMatrix.pb( vector<int> {0, 5, INF, 10} );
	adjMatrix.pb( vector<int> {INF, 0, 3, INF} );
	adjMatrix.pb( vector<int> {INF, INF, 0, 1} );
	adjMatrix.pb( vector<int> {INF, INF, INF, 0} );

	FloydWarshal( adjMatrix );

	for ( size_t  i = 0; i < adjMatrix.size(); i++ )
	{
		for ( size_t j = 0; j < adjMatrix[i].size(); j++ )
		{
			if ( adjMatrix[i][j] == INF )
			{
				cout << "INF" << " ";
			}
			else
			{
				cout << adjMatrix[i][j] << " ";
			}
		}
		cout << "\n";
	}
}
