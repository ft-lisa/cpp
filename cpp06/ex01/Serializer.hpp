#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <stdint.h>

struct Data 
{
        int i;
};

class Serializer
{
        public :
                static uintptr_t serialize(Data* ptr);
                static Data* deserialize(uintptr_t raw);

        private:
                Serializer();
                Serializer(const Serializer&);
                Serializer& operator=(const Serializer&);
                ~Serializer();


};

#endif