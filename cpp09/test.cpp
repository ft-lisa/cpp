#include <iostream>
#include <list>


void movePreviousBlockAfterIt(std::list<int> &lst, std::list<int>::iterator it, int n) {
    if (lst.empty() || n <= 0) return;
        while(n > 0)
        {
                
                n--;
        }
}

int main() {
    std::list<int> lst;
    for (int i = 1; i <= 9; ++i)
        lst.push_back(i);

    std::list<int>::iterator it = lst.begin();
    std::advance(it, 7); // it -> 4
    std::cout << "num : " << *it << std::endl;

    movePreviousBlockAfterIt(lst, it, 2);

    for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl; // 4 5 1 2 3 6 7 8 9
    // 1 2 3 4 5 6 7 8 9
}
