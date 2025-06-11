#include "iter.hpp"

void incrementation(int &i)
{
        i++;
}

template <typename T>
void iter(T ptr, int length, T& fct)
{
        for (int i=0; i < length; i++)
        {
                fct(ptr[i]);
        }
}


int main()
{
        int i[10];

        iter(i, 10, incrementation);
}