#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// A trie node CDT
class TrieNode
{
public:
	bool isEndOfWord;
	vector<TrieNode*> children;

	TrieNode()
	{
		children.resize( alphabetSize, nullptr );
		isEndOfWord = false;
	}

	bool IsLeaf() const
	{
		for ( const auto& child : children )
		{
			if ( child )
			{
				return false;
			}
		}
		return true;
	}

	TrieNode*& GetChild( const char& c )
	{
		return children[c - 'a'];
	}

private:
	const static size_t alphabetSize = 26;
};

ostream& operator<< ( ostream& out, const TrieNode* trieNode )
{
	if ( trieNode == nullptr )
	{
		out << "NULL";
	}
	else
	{
		out << "{";
		for ( size_t i = 0; i < trieNode->children.size(); i++ )
		{
			if ( trieNode->children[i] != nullptr )
			{
				out << char( 'a' + i );
			}
		}
		out << "," << trieNode->isEndOfWord << "}";
	}
	return out;
}


// Now the actual Trie class

class Trie
{
public:

	Trie( TrieNode* root = nullptr, const size_t& size = 0 )
	{
		root_ = root;
		size_ = size;
		if ( root_ == nullptr )
		{
			root_ = new TrieNode;
		}
	}

	size_t Size() const
	{
		return size_;
	}

	void Insert( const string& word )
	{
		size_t level = 0;
		TrieNode* it = root_;

		while ( level < word.size() )
		{
			TrieNode*& itChild = it->GetChild( word[level] );
			if ( itChild == nullptr )
			{
				itChild = new TrieNode;
			}
			it = itChild;
			level++;
		}

		if ( !( it->isEndOfWord ) )
		{
			size_ = Size() + 1;
			it->isEndOfWord = true;
		}
	}

	bool IsPresent( const string& word ) const
	{
		size_t level = 0;
		TrieNode* it = root_;

		while ( level < word.size() )
		{
			TrieNode* itChild = it->GetChild( word[level] );
			if ( itChild == nullptr )
			{
				break;
			}

			it = itChild;
			level++;
		}

		return ( level == word.size() ) && it->isEndOfWord;
	}

	// Returns if word was present in the trie or not
	bool Remove( const string& word )
	{
		return RemoveHelper( root_, word, 0 );
	}

private:

	TrieNode* root_;
	size_t size_;

	static void PrintTrie( const TrieNode* const root, const string& prefix , vector<string>& result )
	{
		if ( root == nullptr )
		{
			return;
		}
		if ( root->isEndOfWord )
		{
			result.push_back( prefix );
		}
		for ( size_t i = 0; i < root->children.size(); i++ )
		{
			PrintTrie( root->children[i], prefix + char( 'a' + i ), result );
		}
	}

	// Removes word from the trie.
	// Returns if word was present in the trie or not
	bool RemoveHelper( TrieNode* const root, const string& word, const size_t& level )
	{
		// Empty trie
		if ( root == nullptr )
		{
			return false;
		}

		if ( level == word.size() )
		{
			// word found !!
			if ( root->isEndOfWord )
			{
				root->isEndOfWord = false;
				return true;
			}

			// Else, word not present in the trie
			return false;
		}

		// Get a reference to the child of the current node in the path from root to the end of word
		TrieNode*& rootChild = root->GetChild( word[level] );
		// Call the function on the child
		const bool wordFound = RemoveHelper( rootChild, word, level + 1 );

		// If target has been found, and
		// child of current node is not end-of-word, and
		// child of current node is leaf
		// then delete child of current node
		// The second condition is to prevent of deletion of the whole branch on which the word was found;
		// we need to just delete all the nodes up the branch till another end-of-word is found
		if ( wordFound && !( rootChild->isEndOfWord ) && rootChild->IsLeaf() )
		{
			delete rootChild;
			// Initialize the dangling pointer to NULL
			rootChild = nullptr;
		}

		return wordFound;
	}

	friend ostream& operator<< ( ostream&, const Trie& );

};

ostream& operator<< ( ostream& out, const Trie& trie )
{
	vector<string> result;
	Trie::PrintTrie( trie.root_, "", result );
	out << result;
	return out;
}

int main()
{
	string s;
	Trie trie;

	s = "a";
	trie.Insert( s );
	if ( !trie.Remove( s ) )
	{
		cout << s << " not found!\n";
	}
	print( trie );

	trie.Insert( "anmol" );
	trie.Insert( "jaggi" );
	trie.Insert( "jag" );
	trie.Insert( "anm" );
	trie.Insert( "an" );
	print( trie );

	s = "";
	if ( !trie.Remove( s ) )
	{
		cout << "'" << s << "' not found!\n";
	}
	print( trie );

	s = "anmo";
	if ( !trie.Remove( s ) )
	{
		cout << "'" << s << "' not found!\n";
	}
	print( trie );

	s = "anmol";
	if ( !trie.Remove( s ) )
	{
		cout << s << " not found!\n";
	}
	print( trie );
}
