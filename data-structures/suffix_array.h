#ifndef SUFFIX_ARRAY_H_INCLUDED
#define SUFFIX_ARRAY_H_INCLUDED

map<string, int> suffix_array( string s )
{
	s += '\0';
	map<string, int> arr;
	for ( int i = ( int )s.size() - 1; i >= 0; i-- )
	{
		arr[s.substr( i )] = i;
	}
	return arr;
}
int common_prefix_length( const string& a, const string& b )
{
	int i = 0;
	while ( i < ( int )a.size() && i < ( int )b.size() )
	{
		if ( a[i] != b[i] )
		{
			break;
		}
		i++;
	}
	return i;
}
vector<int> LCP( const map<string, int>& arr )
{
	vector<int> res( arr.size(), 0 );
	map<string, int>::const_iterator it1, it2;
	it1 = it2 = arr.begin();
	++it2;
	for ( int i = 1; i < ( int )res.size(); i++, ++it1, ++it2 )
	{
		res[i] = common_prefix_length( it1->first, it2->first );
	}
	return res;
}

#endif // SUFFIX_ARRAY_H_INCLUDED
