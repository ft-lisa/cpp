#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate(void)
{
        std::srand(static_cast<unsigned int>(std::time(0)));

        int r = std::rand() % 3;

        switch (r)
        {
                case 0:
                        return new A();
                case 1:
                        return new B();
                default:
                        return new C();
        }
}
void Base::identify(Base* p)
{
        //std::cout << "1" << std::endl;
        if (dynamic_cast<A*>(p))
                std::cout << "Class A" << std::endl;
        else if (dynamic_cast<B*>(p))
                std::cout << "Class B" << std::endl;
        else if (dynamic_cast<C*>(p))
                std::cout << "Class C" << std::endl;
        else 
                std::cout << "Type unknown" << std::endl;
}
void Base::identify(Base& p)
{
        //std::cout << "2" << std::endl;

        try
        {
                (void)dynamic_cast<A&>(p);
                std::cout << "Class A" << std::endl;
                return ;
        }
        catch(...)
        {

        }
        try
        {
                (void)dynamic_cast<B&>(p);
                std::cout << "Class B" << std::endl;
                return ;
        }
        catch(...)
        {

        }
        try
        {
                (void)dynamic_cast<C&>(p);
                std::cout << "Class C" << std::endl;
                return ;
        }
        catch(...)
        {

        }
        std::cout << "Type unknown" << std::endl;
}

Base::~Base()
{

}
