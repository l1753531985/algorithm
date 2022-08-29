#include "FixedCapacityStackOfStrings.h"

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings(int cap)
{
    index = 0;
    array = new string[cap];
}

FixedCapacityStackOfStrings::~FixedCapacityStackOfStrings()
{
    delete[] array;
}

void FixedCapacityStackOfStrings::push(string item)
{
    array[index] = item;
    index++;
}

string FixedCapacityStackOfStrings::pop()
{
    string value = array[index];
    index--;
    return value;
}

bool FixedCapacityStackOfStrings::isEmpty()
{
    return (index == 0);
}

int FixedCapacityStackOfStrings::size()
{
    return index;
}
