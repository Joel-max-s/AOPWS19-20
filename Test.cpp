#include <iostream>
#include <vector>

int main()
{
    std::vector <std::vector <int>>  Test;
    Test.resize(10);
    for (int i = 0; i < 10; i++)
    {
        Test.at(i).resize(10);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <10; j++)
        {
            Test.at(i).at(j) = 10*i + j;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            std::cout <<Test.at(i).at(j);
        }
        std::cout << std::endl;
    }
    std::vector <std::vector <int>> Test2;
    Test2 = Test;
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            std::cout <<Test2.at(i).at(j);
        }
        std::cout << std::endl;
    }
}