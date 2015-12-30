// Given "n" and "r", generate all the possible nCr subsets of an array of size "n"

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef unsigned long long ULL;

// Generate the lowest number bigger than "num" having exactly "r" set bits
// Algorithm (From Cracking The Coding Interview, 5th Edition) -:
// 	1.	Find the position of the rightmost "non-trailing" zero (such that there is atleast one '1' on its right).
//			Let this position be 'p'
//			If there does not exist such a zero, the input is already the largest number possible.
// 	2.	Flip the bit at 'p' to 1 from 0.
//	3.	Count the number of zeroes and ones to the right of 'p'.
//			Let that number be c0 and c1 respectively.
//	4.	Set all the bits to the right of 'p' to 0.
//	5.	Set the first (c1-1) bits (starting from the right) to 1.
ULL NextBigger( ULL num )
{
	ULL numBak = num;

	// Compute c0 and c1
	// c0 = Number of zeroes to the right of the rightmost non-trailing zero
	size_t c0 = 0;
	// c1 = Number of ones to the right of the rightmost non-trailing zero
	size_t c1 = 0;
	while ( numBak && ( ( numBak & 1 ) == 0 ) )
	{
		c0++;
		numBak >>= 1;
	}
	while ( ( numBak & 1 ) == 1 )
	{
		c1++;
		numBak >>= 1;
	}

	// If the input is either 0,
	// or of the form "1111..00000",
	// then there is no bigger number possible
	// Note that for this to work, num should be unsigned
	if ( c0 + c1 == 0 || c0 + c1 == ( sizeof( num ) * 8 ) )
	{
		return 0;
	}

	// Position of the rightmost non-trailing zero ( starting from the right )
	const size_t p = c0 + c1;

	// Flip the rightmost non-trailing zero
	num |= 1 << p;
	// Clear all bits to the right of p
	num &= ~( ( 1 << p ) - 1 );
	// Insert (c1-1) ones on the right of p
	num |= ( 1 << ( c1 - 1 ) ) - 1;

	return num;
}

vector<ULL> GenerateSubsets( const size_t& n, const size_t& r )
{
	assert( n > 0 );
	assert( r > 0 );
	assert( n >= r );

	vector<ULL> subsets;

	// The smallest number having exactly "r" bits set
	ULL lowest = ( 1ULL << r ) - 1;
	// The biggest number having exactly "r" bits set
	ULL highest = lowest << ( n - r );

	// The set bits in the binary of "bitMask" denote the positions of the set included in the subset
	// This loop should run exactly nCr times
	for ( ULL bitMask = lowest; bitMask <= highest; bitMask = NextBigger( bitMask ) )
	{
		subsets.push_back( bitMask );
	}

	return subsets;
}

// Extracts the subset indices from the bitmask
vector<size_t> DecodeMask( ULL bitMask )
{
	vector<size_t> positions;

	size_t i = 0;

	while ( bitMask )
	{
		if ( bitMask & 1 )
		{
			positions.push_back( i );
		}
		bitMask >>= 1;
		i++;
	}

	return positions;
}

int main()
{
	size_t n = 5;
	size_t r = 2;

	auto vec = GenerateSubsets( n, r );
	print( vec.size() );
	system( "pause" );

	for ( size_t i = 0; i < vec.size(); i++ )
	{
		auto decode = DecodeMask( vec[i] );
		print( decode );
	}
}
