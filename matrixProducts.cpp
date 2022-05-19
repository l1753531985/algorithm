#include <vector>
#include <string>
#include <unordered_map>
#include <stdio.h>

#define COLSUFF "colSpace"
#define ROWSUFF "rowSpace"
#define SUFFSIZE 7 

using namespace std;

class MatrixArithemtic {
private:
	struct matrixInfo {
		int startIndex;
		int row;
		int col;
	};
	unordered_map<string,matrixInfo> matricesInfo;
	vector<int> matricsData;
	void getColumnSpace(string matrixName);
	void matrixProduct(string matrixNameA, string matrixNameB);
public:
	explicit MatrixArithemtic(const vector<int>& matrix, int row, int col, string name)
	{ addMatrix(matrix, row, col, name); }
	void addMatrix(const vector<int>& matrix, int row, int col, string name);
	void getColumnVector(string matrixName, vector<int>& colVector, int colIndex);
	void getRowVector(string matrixName, vector<int>& rowVector, int rowIndex);
	void showMatrix(string matrixName, int isTranspose);
	void getMatrixProduct(string matrixNameA, string matrixNameB, vector<int>& res); 
	~MatrixArithemtic(){};
};

void MatrixArithemtic::addMatrix(const vector<int>& matrix, int row, int col, string name)
{
	// detect the size of elements
	if (matrix.size() != row*col)
	{
		printf("The matrix %s size differ with row and col!\n", name);
		return;
	}

	// add the table for switching name into index
	// need to exception operation for same name
	if (matricesInfo.find(name) != matricesInfo.end())
	{
		printf("The name has existed!\n");
		return;
	}

	// add the matrix info
	matrixInfo m;
	m.startIndex = matricsData.size();
	m.row = row;
	m.col = col;
	matricesInfo[name] = m;

	// add the matrix into store space
	for (int elem : matrix)
		matricsData.push_back(elem);
}

// transpose matrix get column space and find column vector easily
void MatrixArithemtic::getColumnSpace(string matrixName)
{
	vector<int> colSpace;
	// It must be exists in matrices data, if the transpose matrix can be found.
	if (matricesInfo.find(matrixName) != matricesInfo.end())
	{
		matrixInfo mi = matricesInfo[matrixName];
		for (int i = 0; i < mi.col; i++)
		{
			for (int j = 0; j < mi.row; j++)
			{
				int elemPos = mi.startIndex + j*mi.col + i;
				colSpace.push_back(matricsData[elemPos]);
			}
		}
		// add colSpace into matrices data for find it next
		string name = (matrixName.find(COLSUFF) == -1) ? COLSUFF+matrixName : matrixName.substr(matrixName.find(COLSUFF)+SUFFSIZE+1,(matrixName.length()-matrixName.find(COLSUFF)-SUFFSIZE));
		addMatrix(colSpace, mi.col, mi.row, name);
	}
}

void MatrixArithemtic::getColumnVector(string matrixName, vector<int>& colVector, int colIndex)
{
	getColumnSpace(matrixName);
	string colSpaceName = COLSUFF + matrixName;
	getRowVector(colSpaceName, colVector, colIndex);
}

void MatrixArithemtic::getRowVector(string matrixName, vector<int>& rowVector, int rowIndex)
{
	matrixInfo mi = matricesInfo[matrixName];
	int index = mi.startIndex + (rowIndex-1)*mi.col;
	for (int i = index; i < index+mi.col; i++)
		rowVector.push_back(matricsData[i]);
}

void MatrixArithemtic::matrixProduct(string matrixNameA, string matrixNameB)
{
	// pre process for get column space  
	vector<int> product;
	matrixInfo mia = matricesInfo[COLSUFF+matrixNameA];
	matrixInfo mib = matricesInfo[COLSUFF+matrixNameB];
	for (int i = 0; i < mib.col; i++)
	{
		vector<int> colVectorB;
		getColumnVector(matrixNameB, colVectorB, i);
		for (int elem : colVectorB)
			if (elem)
			{
			}
	}

	// add transpose matrix of matrix products into matrix data for find it next
	string colName = COLSUFF+matrixNameA+matrixNameB;
	addMatrix(product, mia.row, mib.col, colName); 
	// add matrix products into matrix data for find it next
	getColumnSpace(colName);
}

void MatrixArithemtic::getMatrixProduct(string matrixNameA, string matrixNameB, vector<int>& res) 
{
	matrixProduct(matrixNameA, matrixNameB);
	matrixInfo imab = matricesInfo[matrixNameA+matrixNameB];
	for (int i = imab.startIndex; i < imab.startIndex+imab.row*imab.col; i++)
		res.push_back(matricsData[i]);
}

// isTranspose for find the column space 
void MatrixArithemtic::showMatrix(string matrixName, int isTranspose = 0)
{
	if (isTranspose) matrixName = COLSUFF + matrixName;
	// if it has a record about the matrix, matrices data will return the record.
	// if not found the key, it will occur a error
	if (matricesInfo.find(matrixName) == matricesInfo.end()) 
	{
		printf("It is no such matrix!");
		return;
	}
	matrixInfo mi = matricesInfo[matrixName];
	for (int i = mi.startIndex; i < mi.startIndex+mi.row*mi.col; i++)
	{
		if (!(i % mi.row)) printf("\n");
		printf("%d\t",matricsData[i]);
	}
	printf("\n");
}


int main()
{
	// 5x3 matrix
	vector<int> A{4,0,3,-1,1,-2};
	vector<int> B{3,2,-1,9,0,-2};
	MatrixArithemtic ma{A,2,3,"A"};
	ma.addMatrix(B,3,2,"B");
	vector<int> test;
	ma.getMatrixProduct("A","B",test);
	for (int elem:test)
		printf("%d\t",elem);
	printf("\n");
	return 0;
}
