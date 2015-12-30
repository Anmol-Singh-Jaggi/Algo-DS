#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

class MinHeap
{
	vector<int> heapArray;

public:

	// To get index of parent of node at index
	size_t Parent( const size_t& index ) const;

	// To get index of left child of node at index
	size_t LeftChild( const size_t& index ) const;

	// To get index of right child of node at index
	size_t RightChild( const size_t& index ) const;

	// Inserts a new key
	void InsertKey( const int& newEntry );

	// Deletes a key stored at index
	void DeleteKey( const size_t& index );

	// Decreases key value of key at index to new_val
	void DecreaseKey( const size_t& index, const int& newVal );

	// To extract the root
	int ExtractTop();

	// Returns the key at root
	int GetTop() const;

	// Used when we need to shift an element to its correct postition which is above its current height
	void HeapifyUp( size_t index );

	// A recursive method to heapify a subtree with root at given index
	// This method assumes that the subtrees of root are already heapified
	// Used when we need to shift an element to its correct postition which is below its current height
	void HeapifyDown( const size_t& rootIndex );
};


size_t MinHeap::Parent( const size_t& index ) const
{
	if ( index == 0 )
	{
		return index;
	}

	return ( index - 1 ) / 2;
}

size_t MinHeap::LeftChild( const size_t& index ) const
{
	return 2 * index + 1;
}

size_t MinHeap::RightChild( const size_t& index ) const
{
	return 2 * index + 2 ;
}

void MinHeap::InsertKey( const int& newEntry )
{
	// First insert the new key at the end
	heapArray.push_back( newEntry );
	// Fix the heap property
	HeapifyUp( heapArray.size() - 1 );
}

void MinHeap::DeleteKey( const size_t& index )
{
	// Make the key at index to be equal to INT_MIN so that it comes at the top of the heap
	DecreaseKey( index, INT_MIN );
	// Remove the top of the heap
	ExtractTop();
}

void MinHeap::DecreaseKey( const size_t& index, const int& newVal )
{
	// This is important!!
	assert( newVal <= heapArray[index] );

	heapArray[index] = newVal;
	// Fix the heap property
	HeapifyUp( index );
}

int MinHeap::ExtractTop()
{
	assert( !heapArray.empty() );

	// Store the minimum value, and remove it from heap
	int root = heapArray[0];
	// Copy the last element to the root index
	heapArray[0] = heapArray.back();
	// Decrease the heap size by 1
	heapArray.pop_back();
	// Fix the heap property
	HeapifyDown( 0 );

	return root;
}

int MinHeap::GetTop() const
{
	assert( !heapArray.empty() );

	return heapArray[0];
}

void MinHeap::HeapifyUp( size_t index )
{
	while ( index && heapArray[Parent( index )] > heapArray[index] )
	{
		swap( heapArray[index], heapArray[Parent( index )] );
		index = Parent( index );
	}
}

void MinHeap::HeapifyDown( const size_t& rootIndex )
{
	const size_t& leftChild = LeftChild( rootIndex );
	const size_t& rightChild = RightChild( rootIndex );

	size_t smallest = rootIndex;

	// Find the smallest among the 3 nodes (root, left-child and right-child)

	if ( leftChild < heapArray.size() && heapArray[leftChild] < heapArray[smallest] )
	{
		smallest = leftChild;
	}

	if ( rightChild < heapArray.size() && heapArray[rightChild] < heapArray[smallest] )
	{
		smallest = rightChild;
	}

	// There is no need to heapify if the root is already the smallest among the three
	if ( smallest != rootIndex )
	{
		// Bring the smallest element to the root
		swap( heapArray[rootIndex], heapArray[smallest] );
		// Fix the heap property
		HeapifyDown( smallest );
	}
}

// Driver program to test above functions
int main()
{
	MinHeap myHeap;

	myHeap.InsertKey( 3 );
	myHeap.InsertKey( 2 );
	myHeap.DeleteKey( 1 );
	myHeap.InsertKey( 15 );
	myHeap.InsertKey( 5 );
	myHeap.InsertKey( 4 );
	myHeap.InsertKey( 45 );

	cout << myHeap.ExtractTop() << " ";
	cout << myHeap.GetTop() << " ";
	myHeap.DecreaseKey( 2, 1 );
	cout << myHeap.GetTop();
}
