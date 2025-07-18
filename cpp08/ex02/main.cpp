#include "MutantStack.hpp"

int main()
{
        MutantStack<int> mstack;
        if (mstack.empty())
                std::cout << "La stack est vide" << std::endl;
        mstack.push(5);
        if (mstack.empty())
                std::cout << "La stack est vide" << std::endl;
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int> m2(mstack);
        std::cout << "mstack :" << mstack.top() << std::endl;
        std::cout << "m2 :" << m2.top() << std::endl;
        MutantStack<int> m3;
        m3 = m2;
        std::cout << "mstack :" << mstack.top() << std::endl;
        std::cout << "m3 :" << m3.top() << std::endl;        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
                std::cout << *it << std::endl;
                ++it;
        }
        std::stack<int> s(mstack);
        return 0;
}