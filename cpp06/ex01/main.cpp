#include "Serializer.hpp"

int main()
{
        Data* data_p;
        Data data;
        data.i = 42;

        uintptr_t test;
        
        std::cout << "pointer: " << &data << ", chiffre: " << data.i << std::endl;
        test = Serializer::serialize(&data);
        data_p = Serializer::deserialize(test);
        std::cout << "pointer: " << data_p << ", chiffre: " << data_p->i << std::endl;

}