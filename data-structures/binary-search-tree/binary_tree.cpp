#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

#include "bintree_pretty_print.h"

BinaryTreeNode* Insert( BinaryTreeNode* root, const int& key )
{
	if ( root == NULL )
	{
		root = new BinaryTreeNode( key );
	}
	else if ( key <= root->data )
	{
		root->left = Insert( root->left, key );
	}
	else
	{
		root->right = Insert( root->right, key );
	}

	return root;
}

BinaryTreeNode* Search( BinaryTreeNode* root, const int& key )
{
	if ( root == NULL || root->data == key )
	{
		return root;
	}
	else if ( key <= root->data )
	{
		return Search( root->left, key );
	}
	else
	{
		return Search( root->right, key );
	}
}

// Given a non-empty binary search tree,
// return the node with minimum key value found in that tree.
// Helper for Remove()
BinaryTreeNode* Lowest( BinaryTreeNode* root )
{
	// Loop down to find the leftmost leaf
	while ( root->left != NULL )
	{
		root = root->left;
	}

	return root;
}

BinaryTreeNode* Remove( BinaryTreeNode* root, const int& key )
{
	if ( root == NULL )
	{
		return root;
	}

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if ( key < root->data )
	{
		root->left = Remove( root->left, key );
	}

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if ( key > root->data )
	{
		root->right = Remove( root->right, key );
	}

	// If the key is same as root's key,
	// then this is the node to be deleted
	else
	{
		// Node with only one child or no child
		if ( root->left == NULL )
		{
			BinaryTreeNode* rightBak = root->right;
			delete root;
			return rightBak;
		}
		else if ( root->right == NULL )
		{
			BinaryTreeNode* leftBak = root->left;
			delete root;
			return leftBak;
		}

		// Node with two children
		// Get the inorder successor (smallest in the right subtree)
		BinaryTreeNode* inOrderSucc = Lowest( root->right );

		// Copy the inorder successor's content to this node
		root->data = inOrderSucc->data;

		// Delete the inorder successor
		root->right = Remove( root->right, inOrderSucc->data );
	}

	return root;
}

int main()
{
	BinaryTreeNode* root = NULL;

	root = Insert( root, 50 );
	root = Insert( root, 30 );
	root = Insert( root, 20 );
	root = Insert( root, 40 );
	root = Insert( root, 70 );
	root = Insert( root, 60 );
	root = Insert( root, 80 );
	printBinaryTreeNode( root, 1, 1, cout );

	printf( "\nDelete 20\n" );
	root = Remove( root, 20 );
	printBinaryTreeNode( root, 1, 1, cout );

	printf( "\nDelete 30\n" );
	root = Remove( root, 30 );
	printBinaryTreeNode( root, 1, 1, cout );

	printf( "\nDelete 50\n" );
	root = Remove( root, 50 );
	printBinaryTreeNode( root, 1, 1, cout );

}
