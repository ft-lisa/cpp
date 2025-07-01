#include "iter.hpp"

class Awesome {
public:
    Awesome() : _n(42) {}
    int get() const { return _n; }
    void multiplyBy(int factor) { _n *= factor; }

private:
    int _n;
};

std::ostream& operator<<(std::ostream& os, const Awesome& a) {
    os << a.get();
    return os;
}

void increment(int &i)
{
        i++;
}

template<typename T>
void print(const T & x)
{
    std::cout << x << std::endl;
}

int main()
{
        int i[10];
        char c[10];
        const std::string s[] = {"hello", "world", "42"};
        Awesome tabAwesome[3];
        iter(tabAwesome, 3, print<Awesome>);


        for (int j = 0; j < 10; ++j)
        {
                i[j] = j;
        }
        for (int j = 0; j < 10; ++j)
        {
                c[j] = j + 97;
        }
        for (int j = 0; j < 10; ++j)
        {
                std::cout << "i[" << j << "] = " << i[j] << std::endl;
        }
        iter(i, 10, increment);
        iter(s, 3, print<std::string>);
        for (int j = 0; j < 10; ++j)
        {
                std::cout << "i[" << j << "] = " << i[j] << std::endl;
        }
        iter(c, 10, print<char>);
}
    