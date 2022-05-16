#include <vector>
#include <string>
#include <unordered_map>
#include <stdio.h>

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
	void getColVector(string name, int colIndex, vector<int>& colVector);
	void setColVector(string name, int colIndex, int coff);
	void matrixProducts(string matrixA, string matrixB);	
public:
	explicit MatrixArithemtic(){};
	void addMatrix(const vector<int>& matrix, int row, int col, string name);
	void getMatrixProducts(string matrixA, string matrixB);
	void showMatrix(string matrixName);
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

void MatrixArithemtic::getColVector(string name, int colIndex, vector<int>& colVector)
{
	matrixInfo m = matricesInfo[name];
	for (int rowIndex = 0; rowIndex < m.row; rowIndex++)
	{
		int elem = m.startIndex + rowIndex*(m.col)  + colIndex;	 
		colVector.push_back(matricsData[elem]);
		//printf("%d\n",matricsData[elem]);
	}
}

void MatrixArithemtic::setColVector(string name, int colIndex, int coff)
{
	matrixInfo m = matricesInfo[name];
	for (int rowIndex = 0; rowIndex < m.row; rowIndex++)
	{
		int elem = m.startIndex + rowIndex*(m.col)  + colIndex;	 
		matricsData[elem] *= coff;
	}
}

void MatrixArithemtic::matrixProducts(string matrixA, string matrixB)	
{
	// copy matrixA into matrix result
	vector<int> res;
	matrixInfo mia = matricesInfo[matrixA];
	for (int i = mia.startIndex; i < mia.startIndex+(mia.col*mia.row); i++)
		res.push_back(matricsData[i]);

	// add result matrix into matrices data and info
	string resName = matrixA+matrixB;
	matrixInfo mib = matricesInfo[matrixB];
	addMatrix(res, mia.row, mib.col, resName);

	// split matrixA into column space multiple the column space of matrixB  
	for (int i = 0; i < mib.col; i++)
	{
		vector<int> colVector;
		getColVector(matrixB, i, colVector);
		for (int j = 0; j < colVector.size(); j++)
			if (colVector[j])
				setColVector(resName, j, colVector[j]);
	}
}

void MatrixArithemtic::showMatrix(string matrixName)
{
	matrixInfo mi = matricesInfo[matrixName];
	for (int i = mi.startIndex; i < mi.startIndex+(mi.col*mi.row); i++)
	{
		if (!(i % mi.col)) printf("\n");
		printf("%d\t",matricsData[i]);
	}
	printf("\n");
}

void MatrixArithemtic::getMatrixProducts(string matrixA, string matrixB)
{
	matrixInfo mia = matricesInfo[matrixA];
	matrixInfo mib = matricesInfo[matrixB];
	if (mia.row != mib.col || mia.col != mib.row) 
	{
		printf("the matrix A and B can not get products\n");
		return;
	}
	matrixProducts(matrixA, matrixB);
	showMatrix(matrixA+matrixB);
}

int main()
{
	// 5x3 matrix
	vector<int> A{1,-1, 0,1};
	vector<int> B{3,2,0,-2};
	MatrixArithemtic ma;
	ma.addMatrix(A, 2, 2, "A");
	ma.addMatrix(B, 2, 2, "B");
	ma.getMatrixProducts("A","B");
	return 0;
}
