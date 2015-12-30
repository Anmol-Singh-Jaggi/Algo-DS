#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;


#define leftChild(i) ( ( i ) << 1 )
#define rightChild(i) ( ( ( i ) << 1 ) + 1 )
#define parent(i) ( ( i ) >> 1 )

// Rearranges root and its 2 children nodes according to the heap property.
// Note that it does not imply that the whole array is heapified.
// Only if the all the descendants of the 2 children of the root satisfy the heap property, then only is the end result a complete heap
// In the above mentioned case, it just moves the root to its correct position in the heap.
template<typename T>
void MaxHeapify( vector<T>& arr, const size_t& rootPos, const size_t& end ) // arr is 1-indexed
{
	// The index of the element with the greatest value among the root and its 2 children
	size_t greatestPos = rootPos;
	if ( leftChild( rootPos ) < end && arr[leftChild( rootPos )] > arr[greatestPos] )
	{
		greatestPos = leftChild( rootPos );
	}
	if ( rightChild( rootPos ) < end && arr[rightChild( rootPos )] > arr[greatestPos] )
	{
		greatestPos = rightChild( rootPos );
	}
	if ( greatestPos != rootPos ) // Otherwise will enter into an infinite recursion
	{
		swap( arr[greatestPos], arr[rootPos] );
		// "Trickle down" the heapiness
		MaxHeapify( arr, greatestPos, end );
	}
}

// Transforms the array to a heap. Complexity -> O(n) [ Derivation is a bit complex ]
// Note that the array does not get sorted in anyway.
// All the elements arr[i] satisfy the property { arr[i] > arr[i*2] and arr[i] > arr[i*2+1] }. Nothing more than that.
template<typename T>
void BuildHeap( vector<T>& arr, const size_t& begin, const size_t& end ) // Constructs a heap from arr
{
	// It would have been better if we would have initialized root with the middle element,
	// since the arr[n/2, n) contains leaves, which cannot be "heapified" further anyways.
	size_t root = parent( end - 1 ); // Start from the parent of the last element
	while ( root >= begin )
	{
		MaxHeapify( arr, root--, end );
	}
}

// Sorts the array
// Note that the first element of the array arr[0] can be garbage as it is not used at all.
template<typename T>
void HeapSort( vector<T>& arr, const size_t& begin, const size_t& end )
{
	// Currently unable to specify random starting limit as the calculation of left and right childs assumes the position of nodes to be absolute
	assert( begin == 1 );
	assert( end <= arr.size() );

	if ( end <= begin )
	{
		return;
	}

	BuildHeap( arr, begin, end );
	for ( size_t i = end - 1; i > begin; i-- )
	{
		// The first element contains the biggest element, so put it at the end
		swap( arr[begin], arr[i] );
		MaxHeapify( arr, begin, i );
	}
}

int main()
{
	vector<int> arr = {0, 5, 1, 4, 2, 3};
	HeapSort( arr, 1, arr.size() );
	print( arr );
}
