#include <stdio.h>
#include <vector>

#define MAXSIZE  64
#define FIRST_BIT 0x8000000000000000

#define AND(a,b) a&b
#define OR(a,b)  a|b
#define UNARY(a) ~a
#define MASK(a) maskBit&a

static unsigned long maskBit = 0xFFFFFFFFFFFFFFFF; 

unsigned long setBit(unsigned long bits, int flag) 
{
	__asm__("shr %[bits]"
			:[bits] "+r"(bits));
	if (flag)
		bits |= (bits|FIRST_BIT);
	return bits;
}

unsigned long complementOfBitString(unsigned long bitString)
{
	return MASK(UNARY(bitString));		
}

unsigned long unionOfBitString(unsigned long bitStringA, unsigned long bitStringB)
{
	return MASK(OR(bitStringA,bitStringB));		
}

unsigned long intersectionOfBitString(unsigned long bitStringA, unsigned long bitStringB)
{
	return MASK(AND(bitStringA,bitStringB));		
}

unsigned long differenceOfBitString(unsigned long bitStringA, unsigned long bitStringB)
{
	unsigned long complementOfB = UNARY(bitStringB);
	unsigned long AsubB = AND(complementOfB,bitStringA);
	return MASK(AsubB);		
}

unsigned long symmeticDifferenceOfBitString(unsigned long bitStringA, unsigned long bitStringB)
{
	unsigned long symDiff = unionOfBitString(bitStringA,bitStringB)-intersectionOfBitString(bitStringA,bitStringB);
	return MASK(symDiff); 
}

// The max size of elements of a set is 64
template<typename Object>
unsigned long getBitString(const std::vector<Object>& set, const std::vector<Object>& setUniversal)
{
	// init a bit string
	unsigned long bitString = 0xFFFFFFFFFFFFFFFF; 
	int setIndex= set.size()-1;

	// it means has this element, while the bit equals 1, therefore none
	for (int i = setUniversal.size()-1; i >= 0; i--)
	{
		int flag = (setUniversal[i] == set[setIndex]) ? 1 : 0;
		bitString = setBit(bitString, flag);
		setIndex -= flag;
	}
    return MASK(bitString);
}

template<typename Object>
void setOperation(std::vector<Object>& set, unsigned long bitString, std::vector<Object>& result)
{
	for (int i = 0; i < set.size(); i++)
	{
		unsigned long currentBit = bitString & FIRST_BIT;
		if (currentBit)
			result.push_back(set[i]);
		bitString <<= 0x1;
	}
}

int main()
{
	std::vector<int> setA{1,2};
	std::vector<int> setB{2,4};
	std::vector<int> setUniversal{1,2,3,4};

	maskBit <<= (MAXSIZE-setUniversal.size());

	// assume we have ordered all sets
	unsigned long bitStringA = getBitString(setA,setUniversal);
	unsigned long bitStringB = getBitString(setB,setUniversal);

	// bit string opertion
	unsigned long complementBitA = complementOfBitString(bitStringA);
	unsigned long unionAB = unionOfBitString(bitStringA,bitStringB);
	unsigned long intersectionAB = intersectionOfBitString(bitStringA,bitStringB);
	unsigned long differenceAB = differenceOfBitString(bitStringA,bitStringB);
	unsigned long symmeticDifferenceAB = symmeticDifferenceOfBitString(bitStringA,bitStringB);

	// set operation
	std::vector<int> result;
	setOperation(setUniversal,symmeticDifferenceAB,result); 
	
	if (result.size() > 0)
	{
		for (int x:result)
			printf("%d\t",x);
	}
	else
		printf("empty set");
	printf("\n");
	return 0;
}
