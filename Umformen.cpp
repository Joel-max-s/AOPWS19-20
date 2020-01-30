#include <array>
#include <vector>
#include <iostream>

int main()
{
    std::vector <int> test;
    std::vector <std::vector <int>> test2;
    /*test2.resize(10);
    for(int i = 0; i < 10; i++)
    {
        test2.at(i).resize(10);
        std::cout <<test2.at(i).size() <<std::endl;
    }*/
    for (int i = 0; i < 43008; i++)
    {
        test.push_back(i);
        std::cout <<test.at(i) <<std::endl;
    }
    for (int i = 0; i < 1792; i++)
    {
        test2.push_back({});
        for (int j = 0; j < 24; j++)
        {
            test2.at(i).push_back(test.at(24*i + j));
            std::cout <<test.at(24*i + j) <<std::endl;
        }
    }
    for (int i = 0; i < 1792; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            std::cout <<test2.at(i).at(j) <<" ";
        }
        std::cout <<std::endl;
    }

}