#include <stdio.h>
#include <string>
#include <vector>

#define MAXSIZE  64
#define AND(a,b) a&b
#define OR(a,b)  a|b
#define UNARY(a) ~a

uint64_t setBit(uint64_t bits, int flag) 
{
	if (flag)
	{
		__asm__("sar %[bits]"
				:[bits] "+r"(bits));
		bits |= 0x8FFFFFFFFFFFFFFF;
	}
	else
		__asm__("shr %[bits]"
				:[bits] "+r"(bits));
	return bits;
}

// The max size of elements of a set is 64
template<typename Object>
uint64_t getBitString(const std::vector<Object>& set, const std::vector<Object>& setUniversal)
{
	// init bit string
	uint64_t universal = 0xFFFFFFFFFFFFFFFF; 
	uint64_t bitString = 0xFFFFFFFFFFFFFFFF; 
	universal = universal << (MAXSIZE-setUniversal.size());
	int setIndex= set.size()-1;

	// it means a element, while bit flag equals 1, therefore none
	for (int i = setUniversal.size()-1; i >= 0; i--)
	{
		int flag = (setUniversal[i] == set[setIndex]) ? 1 : 0;
		bitString = setBit(bitString, flag);
		setIndex -= flag;
	}
	bitString &= universal;
    return bitString;
}

template<typename Object>
void complementOfSet(std::vector<Object>& set)
{
}

int main()
{
	std::vector<int> setA{1,2};
	std::vector<int> setB{2,3};
	std::vector<int> setUniversal{1,2,3,4};
	// assume we have ordered all sets
	uint64_t bitA = getBitString(setA,setUniversal);
	uint64_t bitB = getBitString(setB,setUniversal);
	printf("%x\n", bitA);
}
