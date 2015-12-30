#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Complexity -> O( E + V )

typedef vector<vector<size_t> > AdjList;

void BFS ( const AdjList& adjList, const size_t& source, const size_t& target )
{
  // dist[i] -> Shortest distance of vertex i from source
  // dist[i] = -1 means that vertex i has not been discovered yet
  vector<int> dist ( adjList.size(), -1 );

  // parent[i] -> Predecessor of vertex i in the shortest path tree
  // Used just for printing the shortest path tree
  vector<size_t> parent ( adjList.size(), 0 );

  queue<size_t> bfsQueue;

  bfsQueue.push ( source );
  dist[source] = 0;

  while ( !bfsQueue.empty() )
  {
    if ( dist[target] != -1 )
    {
      break;
    }

    size_t u = bfsQueue.front();
    bfsQueue.pop();

    for ( size_t i = 0; i < adjList[u].size(); i++ )
    {
      size_t v = adjList[u][i];
      if ( dist[v] != -1 )
      {
        continue;
      }

      dist[v] = dist[u] + 1;
      parent[v] = u;
      bfsQueue.push ( v );
    }
  }

  print ( dist );
  print ( parent );

}


int main()
{
  AdjList adjList ( 5 );

  adjList[0].pb ( 1 );
  adjList[0].pb ( 2 );

  adjList[1].pb ( 2 );
  adjList[1].pb ( 4 );

  adjList[2].pb ( 1 );
  adjList[2].pb ( 3 );

  adjList[3].pb ( 4 );

  BFS ( adjList, 0, 3 );
}
