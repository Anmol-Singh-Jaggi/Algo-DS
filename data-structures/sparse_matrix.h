#ifndef SPARSE_MATRIX_H_INCLUDED
#define SPARSE_MATRIX_H_INCLUDED


struct tuple
{
	int row, col, value;
};
class sparse
{
	tuple *table;
public:
	sparse( const int&, const int&, const int& );
	sparse( const sparse& );
	~sparse();
	void get_data();
	void read_data() const;
	void show_sparse() const;
	void transpose();
	friend sparse sparse_multiply( const sparse& one, sparse two );
	friend sparse add_sparse( const sparse& one, const sparse& two );
};
// Default Constructor..
sparse::sparse( const int& rows, const int& cols, const int& non_zero_elements )
{
	// non_zero_elements = number of non-zero elements in the matrix...
	table = new tuple[non_zero_elements + 1];
	table[0].row = rows;
	table[0].col = cols;
	table[0].value = 0;
}
// Copy Constructor..
sparse::sparse( const sparse& other )
{
	table = new tuple[other.table[0].value + 1];
	int i;
	for ( i = 0; i <= other.table[0].value; i++ )
	{
		table[i] = other.table[i];
	}
}

// Destructor..
sparse::~sparse()
{
	delete[] table;
}
// Input the matrix and store it in sparse {row_number,col_number,value} form..
void sparse::get_data()
{
	int i, j, k = 1, elem;
	for ( i = 0; i < table[0].row; i++ )
	{
		for ( j = 0; j < table[0].col; j++ )
		{
			scanf( "%d", &elem );
			if ( elem )
			{
				table[k].row = i;
				table[k].col = j;
				table[k++].value = elem;
			}
		}
	}
	table[0].value = k - 1;
}
// Read the sparse table and display it in its matrix form..
void sparse::read_data() const
{
	int i, j, k = 1;
	for ( i = 0; i < table[0].row; i++ )
	{
		for ( j = 0; j < table[0].col; j++ )
		{
			/* If the last non-zero element hasn't been displayed already and
			   the position (i,j) has a non-zero element...  */
			if ( k <= table[0].value && ( i == table[k].row && j == table[k].col ) )
			{
				printf( "%d ", table[k++].value );
			}
			else
			{
				printf( "0 " );
			}
		}
		printf( "\n" );
	}
}
// Add two matrices given in sparse tabular form...
sparse add_sparse( const sparse& one, const sparse& two )
{
	// Return if the two matrices are of different dimensions...
	if ( ( one.table[0].row != two.table[0].row ) || ( one.table[0].col != two.table[0].col ) )
	{
		printf( "Matrices incompatible for addition!! " );
		return sparse( 0, 0, 0 ); // Indicates error...
	}
	int no_of_rows = one.table[0].row;
	int no_of_columns = one.table[0].col;
	// A sparse table used for storing the resultant of the addition..
	sparse result( no_of_rows, no_of_columns, one.table[0].value + two.table[0].value );
	// "k" is used for iterating "one"
	// "l" is used for iterating "two"
	// "m" is used for iterating "result"
	int i, j, k = 1, l = 1, m = 1;
	for ( i = 0; i < no_of_rows; i++ )
	{
		for ( j = 0; j < no_of_columns; j++ )
		{
			// If the position (i,j) has a non-zero element in both the matrices..
			if ( ( i == one.table[k].row ) && ( j == one.table[k].col ) && ( i == two.table[l].row ) && ( j == two.table[l].col ) )
			{
				result.table[m].row = i;
				result.table[m].col = j;
				result.table[m++].value = one.table[k++].value + two.table[l++].value;
			}
			// If the position (i,j) has a non-zero element in "one" only..
			else if ( i == one.table[k].row && j == two.table[k].col )
			{
				result.table[m].row = i;
				result.table[m].col = j;
				result.table[m++].value = one.table[k++].value;
			}
			// If the position (i,j) has a non-zero element in "two" only...
			else if ( i == two.table[l].row && j == two.table[l].col )
			{
				result.table[m].row = i;
				result.table[m].col = j;
				result.table[m++].value = two.table[l++].value;
			}
		}
	}
	result.table[0].value = m - 1;
	return result;
}
// Show the sparse table itself...
void sparse::show_sparse() const
{
	int i;
	for ( i = 0; i <= table[0].value; i++ )
	{
		printf( "%d %d %d\n", table[i].row, table[i].col, table[i].value );
	}
}
// Fast transpose the matrix..
void sparse::transpose()
{
	int i;
	// A temporary sparse table for storing the result..
	tuple* temp = new tuple[table[0].value + 1];
	temp[0].row = table[0].col;
	temp[0].col = table[0].row;
	temp[0].value = table[0].value;
	// An array for storing the frequency of non-zero elements in all the columns..
	// col_elem_frequency[i] = number of non-zero elements in column "i"..
	int *col_elem_frequency = new int[table[0].col + 1];
	// An array for storing the position of the first appearance of a particular column in the final (transposed) sparse table...
	// col_start_pos[i] = the index of "temp" at which the first non-zero element of column "i" appears..
	int *col_start_pos = new int[table[0].col + 1];
	// Updating the col_elem_frequency[] array..
	for ( i = 1; i <= table[0].value; i++ )
	{
		col_elem_frequency[table[i].col]++;
	}
	col_start_pos[0] = 1; // Because the 0'th index is for the header of the table...
	// Updating the col_start_pos[] array..
	/* Index of appearance of first non-zero element of column "i" = Index of appearance of first non-zero element of column "i-1"..
	 .. + number of non-zero elements in column "i-1"  */
	for ( i = 1; i <= table[0].col; i++ )
	{
		col_start_pos[i] = col_start_pos[i - 1] + col_elem_frequency[i - 1];
	}
	for ( i = 1; i <= table[0].value; i++ )
	{
		// A REFERENCE to the index (in temp) of first non-zero elem of column "table[i].col"..
		int &pos = col_start_pos[table[i].col];
		temp[pos].row = table[i].col;
		temp[pos].col = table[i].row;
		temp[pos].value = table[i].value;
		// Note that this increment reflects the data in col_start_pos[] as it is a reference variable!!...
		pos++;
	}
	// Overwrite the original table with the transposed table...
	for ( i = 0; i <= table[0].value; i++ )
	{
		table[i] = temp[i];
	}
	delete[] temp;
	delete[] col_elem_frequency;
	delete[] col_start_pos;
}
sparse sparse_multiply( const sparse& one, sparse two )
{
	if ( one.table[0].col != two.table[0].row )
	{
		printf( "Matrices incompatible for multiplication!!" );
		return sparse( 0, 0, 0 );
	}
	// The sparse matrix of the product matrix...
	sparse result( one.table[0].row, two.table[0].col, one.table[0].row * two.table[0].col );
	two.transpose();  // Taking transpose of the second matrix so that we can iterate both the matrices in row-major order..
	int i, j, k, l = 1, m = 1, n = 1, elem1, elem2, newelem;
	// An array used to record the index of the occurence of the first element of each row of the matrix in the sparse table...
	int *row_start_pos_one = new int[one.table[0].row + 1];
	int *row_start_pos_two = new int[two.table[0].row + 1];
	// Initializing to 1,because the 0'th index is occupied by the table header..
	memset( row_start_pos_one, 1, one.table[0].row + 1 );
	memset( row_start_pos_two, 1, two.table[0].row + 1 );
	for ( i = one.table[0].value; i >= 1; i-- )
	{
		row_start_pos_one[one.table[i].row] = i;
	}
	for ( i = two.table[0].value; i >= 1; i-- )
	{
		row_start_pos_two[two.table[i].row] = i;
	}
	for ( i = 0; i < one.table[0].row; i++ )
	{
		for ( j = 0; j < two.table[0].row; j++ )
		{
			newelem = 0;
			l = row_start_pos_one[i];
			m = row_start_pos_two[j];
			for ( k = 0; k < two.table[0].col; k++ )
			{
				elem1 = elem2 = 0;
				if ( l <= one.table[0].value && one.table[l].row == i && one.table[l].col == k )
				{
					elem1 = one.table[l++].value;
				}
				if ( m <= two.table[0].value && two.table[m].row == j && two.table[m].col == k )
				{
					elem2 = two.table[m++].value;
				}
				newelem += elem1 * elem2;
			}
			if ( newelem ) // If it's a non-zero element, add it to the resultant matrix..
			{
				tuple temp;
				temp.row = i;
				temp.col = j;
				temp.value = newelem;
				result.table[n++] = temp;
			}

		}
	}
	delete[] row_start_pos_one;
	delete[] row_start_pos_two;
	result.table[0].value = n - 1;
	return result;
}


#endif // SPARSE_MATRIX_H_INCLUDED
