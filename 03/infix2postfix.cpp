#include <iostream>
#include "FixConvert.h" 

using namespace std;

int main()
{
	// FixConvert fc{"a + b * c + ( d * e + f ) * g"};
	FixConvert fc{" a - b - c"};
	string res = fc.getPostFixExpression();
	cout << res << endl;
	return 0;
}
