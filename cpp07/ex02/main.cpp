#include "Array.hpp"

int main()
{
        Array<char> one(5);
        char c = 't';
        one.fillArray(c);
        for(unsigned int i = 0; i < one.size(); i++)
        {
                std::cout << "one[" << i << "] = " << one[i] << std::endl;
        }
        // std::cout << one[5] << std::endl;   //erreur
        Array<char> two;
        two.fillArray(1);
        //std::cout << two[0] << std::endl; // erreur
        Array<char> three(one);
        for(unsigned int i = 0; i < three.size(); i++)
        {
                std::cout << "three[" << i << "] = " << three[i] << std::endl;
        }
        two = three;
        for(unsigned int i = 0; i < two.size(); i++)
        {
                std::cout << "two[" << i << "] = " << two[i] << std::endl;
        }
        Array<std::string> four(4);
        std::string str = "coucou";
        four.fillArray(str);
        for(unsigned int i = 0; i < four.size(); i++)
        {
                std::cout << "four[" << i << "] = " << four[i] << std::endl;
        }
}