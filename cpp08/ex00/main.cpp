#include "easyfind.hpp"

// template <typename T>
int main()
{

    //vector
    std::vector<int> list1;
    std::vector<int>::iterator i;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_back(40);

    i = easyfind(list1, 20);
    std::cout << *i++ << std::endl;
    std::cout << *i << std::endl;
    i = easyfind(list1, 50);
    std::cout << *i << std::endl << std::endl << std::endl;

    //list
    std::list<int> list2;
    list2.push_back(5);
    list2.push_back(10);
    list2.push_back(15);
    std::list<int>::iterator it;
    it = easyfind(list2, 10);

    std::cout << *it++ << std::endl;
    std::cout << *it << std::endl;
    it = easyfind(list2, 50);
    std::cout << *it << std::endl;

    return 0;
}
