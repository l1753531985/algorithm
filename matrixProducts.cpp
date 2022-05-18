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
	void setColVector(string src, string res, int colIndex, int coff);
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

void MatrixArithemtic::setColVector(string src, string res, int colIndex, int coff)
{
	matrixInfo s = matricesInfo[src];
	matrixInfo r = matricesInfo[res];
	for (int rowIndex = 0; rowIndex < r.row; rowIndex++)
	{
		int elemPostion = rowIndex*(s.col)  + colIndex;	 
		matricsData[r.startIndex+elemPostion] = matricsData[s.startIndex+elemPostion] * coff;
	}
}

void MatrixArithemtic::matrixProducts(string matrixA, string matrixB)	
{
	// add result matrix into matrices data and info
	string resName = matrixA+matrixB;
	matrixInfo mib = matricesInfo[matrixB];
	matrixInfo mia = matricesInfo[matrixA];
	vector<int> res(mia.row*mib.col);
	addMatrix(res, mia.row, mib.col, resName);

	// copy matrix A into matrix result
	for (int i = 0; i < mia.col*mia.row; i++)
		matricesData[] = matricsData[i];

	// split matrixA into column space multiple the column space of matrixB  
	for (int i = 0; i < mib.col; i++)
	{
		vector<int> colVector;
		getColVector(matrixB, i, colVector);
		for (int j = 0; j < colVector.size(); j++)
			if (colVector[j])
			{
				setColVector(matrixA, resName, i, colVector[j]);
			}
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
