#include "whatever.hpp"

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
        std::cout << "max: " << max(d, e) << std::endl;


}

// int main( void ) {
// int a = 2;
// int b = 3;
// ::swap( a, b );
// std::cout << "a = " << a << ", b = " << b << std::endl;
// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// std::string c = "chaine1";
// std::string d = "chaine2";
// ::swap(c, d);
// std::cout << "c = " << c << ", d = " << d << std::endl;
// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// return 0;
// }