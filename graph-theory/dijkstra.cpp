#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Complexity -> O(( E+V)*logV )
// Does not work on graphs with negative edges

// vertex_weight.first = index of some vertex
// vertex_weight.second = weight/sum of weights of edge(s) ( exact meaning depends on the context in which it is being used)
typedef pair<size_t, int> vertex_weight;

// AdjList[i] -> vector of pair(v, weight of edge(i, v)); where v = neighbour of i
typedef vector<vector<vertex_weight> > AdjList;

const int INF = INT_MAX;

// Made just for comparison
class prioritize
{
public:

	bool operator()( const vertex_weight& p1, const vertex_weight& p2 )
	{
		// Here vertex_weight refers to pair(v, shortest distance of v from source)
		return p1.second > p2.second;
	}
};

int Dijkstra( const AdjList& adjList, const size_t& source, const size_t& target = INF )
{
	// dist[i] -> Shortest distance of vertex i from source
	vector<long long> dist( adjList.size(), INF );

	// visited[i] -> Has vertex i been visited already ?
	vector<bool> visited( adjList.size(), false );

	// parent[i] -> Predecessor of vertex i in the shortest path tree
	// Used just for printing the shortest path tree
	vector<size_t> parent( adjList.size(), 0 );

	// A min priority-queue used to retrieve the vertex whose distance from the source is shortest among the ones not visited
	priority_queue<vertex_weight, vector<vertex_weight>, prioritize > pq;

	dist[source] = 0;
	pq.push( mp( source, dist[source] ) );

	while ( !pq.empty() )
	{
		if ( target < visited.size() && visited[target] )
		{
			break;
		}

		size_t u = pq.top().first;
		pq.pop();

		if ( visited[u] )
		{
			continue;
		}

		for ( size_t i = 0; i < adjList[u].size(); i++ )
		{
			size_t v = adjList[u][i].first;
			if ( visited[v] )
			{
				continue;
			}

			// weight = weight of the edge(u, v)
			int weight = adjList[u][i].second;

			// "Relax" dist[v]
			if ( dist[u] + weight < dist[v] )
			{
				dist[v] = dist[u] + weight;
				pq.push( mp( v, dist[v] ) );
				parent[v] = u;
			}
		}

		visited[u] = true;
	}

	print( dist );
	print( parent );

	if ( target < visited.size() )
	{
		return dist[target];
	}
	else
	{
		return -1;
	}
}


int main()
{
	AdjList adjList( 5 );

	adjList[0].pb( mp( 1, 4 ) );
	adjList[0].pb( mp( 2, 1 ) );

	adjList[1].pb( mp( 2, 2 ) );
	adjList[1].pb( mp( 4, 3 ) );

	adjList[2].pb( mp( 1, 2 ) );
	adjList[2].pb( mp( 3, 2 ) );

	adjList[3].pb( mp( 4, 3 ) );

	Dijkstra( adjList, 0 );
}
