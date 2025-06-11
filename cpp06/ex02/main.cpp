#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main ()
{
        Base base;
        Base* test;
        A a;

        test = base.generate();
        base.identify(test);
        base.identify(test);
        base.identify(base);
        base.identify(a);
        return(0);
}