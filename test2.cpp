#include <iostream>
#include <vector>

int main()
{
    std::vector <std::vector <unsigned char>> Vec;
    Vec.resize(1);
    std::cout <<Vec.max_size() <<std::endl;
    std::cout <<Vec.at(0).max_size();
}