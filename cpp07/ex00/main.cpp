#include "whatever.hpp"

// voir pour les const
template <typename T>
void swap(T& a, T& b)
{
        T c;

        c = b;
        b = a;
        *a = c;
}

template <typename T>
T min(T a, T b)
{
        if (a < b)
                return a;
        return b;
}

template <typename T>
T max(T a, T b)
{
        if (a > b)
                return a;
        return b;
}

int main()
{
        int a = 0;
        int b = 4;
        // long c = 30;

        const char d = 'c';
        const char e = 'e';

        std::cout << "min: " << min(a, b) << std::endl;
        // std::cout << "min: " << min(a, c) << std::endl;
        std::cout << "min: " << min(d, e) << std::endl;
        swap(a, b);
        std::cout << "swap: " << a << ", " << b << std::endl;

}