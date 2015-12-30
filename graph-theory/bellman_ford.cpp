#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Complexity -> O(E*V)
// Does not work on undirected graphs ( duh! )

// vertex_weight.first = index of some vertex
// vertex_weight.second = weight/sum of weights of edge(s) ( exact meaning depends on the context in which it is being used)
typedef pair<size_t, int> vertex_weight;

// AdjList[i] -> vector of pair(v, weight of edge(i, v)); where v = neighbour of i
typedef vector<vector<vertex_weight> > AdjList;

vector<long long> BellmanFord( const AdjList& adjList, const size_t& source )
{
	// dist[i] -> Shortest distance of vertex i from source
	vector<long long> dist( adjList.size(), INT_MAX );

	// parent[i] -> Predecessor of vertex i in the shortest path tree
	// Used just for printing the shortest path tree
	vector<size_t> parent( adjList.size(), 0 );

	dist[source] = 0;

	// Iterating over all vertices
	for ( size_t k = 0; k < adjList.size() - 1; k++ )
	{
		// Iterating over all edges
		for ( size_t u = 0; u < adjList.size(); u++ )
		{
			for ( size_t i = 0; i < adjList[u].size(); i++ )
			{
				size_t v = adjList[u][i].first;

				// weight = weight of the edge(u, v)
				int weight = adjList[u][i].second;

				// "Relax" dist[v]
				if ( dist[u] + weight < dist[v] )
				{
					dist[v] = dist[u] + weight;
					parent[v] = u;
				}
			}
		}
	}

	// Detecting -ve weight cycle -:

	// Iterating over all edges
	for ( size_t u = 0; u < adjList.size(); u++ )
	{
		for ( size_t i = 0; i < adjList[u].size(); i++ )
		{
			size_t v = adjList[u][i].first;

			// weight = weight of the edge(u, v)
			int weight = adjList[u][i].second;

			// "Relax" dist[v]
			if ( dist[u] + weight < dist[v] )
			{
				cout << "The graph contains negative-weight cycle!!\n";
				u = adjList.size();
				break;
			}
		}
	}

	print( parent );

	return dist;
}

int main()
{
	AdjList adjList( 5 );

	adjList[0].pb( mp( 1, -1 ) );
	adjList[0].pb( mp( 2, 4 ) );
	adjList[1].pb( mp( 2, 3 ) );
	adjList[1].pb( mp( 3, 2 ) );
	adjList[1].pb( mp( 4, 2 ) );
	adjList[3].pb( mp( 2, 5 ) );
	adjList[3].pb( mp( 1, 1 ) );
	adjList[4].pb( mp( 3, -3 ) );

	print( BellmanFord( adjList, 0 ) );
}

