#include "Matrix.h"
#include "Array.h"
using namespace std;

template
	< typename T >
void fillMatrix(Matrix <T> & m)
{
	int i, j;
	for (i = 0; i < m.numRows(); i++)
		m[i][0] = T();
	for (j = 0; j < m.numCols(); j++)
		m[0][j] = T();
	for (i = 1; i < m.numRows(); i++)
		for (j = 1; j < m.numCols(); j++)
		{
			m[i][j] = T(i * j);
		}
}
void test_int_matrix()
{
	Matrix < int > m(10, 5);
	fillMatrix(m);
	cout << m << endl;
}
void test_double_matrix()
{
	Matrix < double > M(8, 10);
	fillMatrix(M);
	cout << M << endl;
}
void generate_exception(Matrix < double > &m)
{
	for (int i = 0; i < m.numRows(); i++)
		m[i+1][0] = double();
}
void test_double_matrix_exceptions()
{
	cout << "Starting...\n";
	Matrix < double > M(8, 10);
	fillMatrix(M);
	cout << M;
	try
	{
		generate_exception(M);
	}
	catch (IndexOutOfBoundsException)
	{
		cout << "Error: Index out of bounds" << endl;
	}
	cout << "Done\n";
}
int main()
{
	for (int i = 0; i < 3; ++i)
	{
		test_int_matrix();
		test_double_matrix();
		test_double_matrix_exceptions();
	}
	return 0;
}
