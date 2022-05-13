/*
 * f:S->Z, set S is defined and set Z is integer set, f is function 
 */
#include <set>

static std::set<int> range;

int testFunc(int x)
{
	// test whether the function is one to one
}

bool isOneToOne(const std::set<int>& s)
{
	for (int x:s)
	{
		int y = testFunc(x);
		if (!range.count(y))
			range.insert(y);
		return false;
	}
	return true;

}

int main(int argc, char* argv[])
{
	std::set<int> S;
	for (int i = 0; i < argv[1]; i++) 
		s.insert(1+i);
	return 0;
}
