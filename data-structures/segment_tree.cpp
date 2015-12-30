#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 * Almost all the variables which are declared as unsigned are indices
 * N = arr.size() - 1
 */

vector<int> arr( 10, rand() % 4 );
vector<int> tree( arr.size() * 2, 0 );

/**
 * Build and init tree
 * The tree node with the index "node" covers the elements within [start, end] in the original array.
 * Complexity - O(N)
 */
void build_tree( const unsigned node, const unsigned start, const unsigned end )
{
	assert( start <= end );

	if ( start == end ) // Leaf node
	{
		tree[node] = arr[start]; // Init value
		return;
	}

	const unsigned mid = ( start + end ) / 2;
	const unsigned leftChildNode = node * 2;
	const unsigned rightChildNode = leftChildNode + 1;

	build_tree( leftChildNode, start, mid ); // Init left child
	build_tree( rightChildNode, mid + 1, end ); // Init right child

	tree[node] = max( tree[leftChildNode], tree[rightChildNode] ); // Init root value
}

/**
 * Increment elements within range [updateStart, updateEnd] with "value"
 */
void update_tree( const unsigned node, const unsigned start, const unsigned end,
									const unsigned uStart, const unsigned uEnd,
									const unsigned value )
{
	assert( start <= end );
	assert( uStart <= uEnd );

	if ( start > uEnd || end < uStart ) // Current segment is not within range [uStart, uEnd]
	{
		return;
	}

	if ( start == end ) // Leaf node
	{
		tree[node] += value;
		return;
	}

	const unsigned mid = ( start + end ) / 2;
	const unsigned leftChildNode = node * 2;
	const unsigned rightChildNode = leftChildNode + 1;

	update_tree( leftChildNode, start, mid, uStart, uEnd, value ); // Updating left child
	update_tree( rightChildNode, mid + 1, end, uStart, uEnd, value ); // Updating right child

	tree[node] = max( tree[leftChildNode], tree[rightChildNode] ); // Updating root
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree( const unsigned node, const unsigned start, const unsigned end,
								const unsigned uStart, const unsigned uEnd )
{
	assert( start <= end );
	assert( uStart <= uEnd );

	if ( start > uEnd || end < uStart ) // Current segment is not within range [uStart, uEnd]
	{
		return -1000000000; // Out of range
	}

	if ( start >= uStart && end <= uEnd ) // Current segment is totally within range [uStart, uEnd]
	{
		return tree[node];
	}

	const unsigned mid = ( start + end ) / 2;
	const unsigned leftChildNode = node * 2;
	const unsigned rightChildNode = leftChildNode + 1;

	const int leftQuery = query_tree( leftChildNode, start, mid, uStart, uEnd ); // Query left child
	const int rightQuery = query_tree( rightChildNode, mid + 1, end, uStart, uEnd ); // Query right child

	const int query = max( leftQuery, rightQuery ); // Return final result
	return query;
}

int main()
{
	srand( time( NULL ) );
	for ( unsigned i = 0; i < arr.size(); i++ )
	{
		arr[i] = rand() % 5;
	}
	print( arr );
	build_tree( 1, 0, arr.size() - 1 );
	print( tree );

	update_tree( 1, 0, arr.size() - 1, 0, 6, 5 ); // Increment range [0, 6] by 5
	update_tree( 1, 0, arr.size() - 1, 7, 7, 12 ); // Incremenet range [7, 7] by 12
	update_tree( 1, 0, arr.size() - 1, 5, 9, 100 ); // Increment range [5, 9] by 100
	print( tree );

	print( query_tree( 1, 0, arr.size() - 1, 0, arr.size() - 1 ) ); // Get max element in range [0, N-1]
}
