#include <string>

#ifndef __FIXEDCAPACITYSTACKOFSTRING_H
using namespace std;

class FixedCapacityStackOfStrings {
public:
    FixedCapacityStackOfStrings(int cap);
    ~FixedCapacityStackOfStrings();
    void push(string item);
    string pop();
    bool isEmpty();
    int size();
private:
    int index;
    string* array;
};
#endif
