#include <iostream>
#include <vector>

#include "sequence_table.hpp"


using std::vector;

template<typename T>
extern std::ostream& operator<<(std::ostream& os, const SequenceTable<T>& t);

int main()
{
    vector<int> vec;

    SequenceTable<int> sq;
    sq.unshift(1);
    sq.unshift(2);
    sq.push_back(3);
    sq.push_back(4);
   
    for (int i = 0; i < sq.get_size(); i++) {
        std::cout << i << ": " << sq[i] << std::endl;
    }

    std::cout << "element count: " << sq.get_size() << std::endl;
    std::cout << sq.get_capacity() << std::endl;
    //std::cout << "Hello World!\n";
}
