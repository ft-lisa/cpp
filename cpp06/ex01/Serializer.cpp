#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
        return reinterpret_cast<uintptr_t>(ptr); //reintepret cast prochain dynamique
}
Data*  Serializer::deserialize(uintptr_t raw)
{
        return reinterpret_cast<Data*>(raw);
}
Serializer::Serializer()
{

}
Serializer::Serializer(const Serializer&)
{

}
Serializer& Serializer::operator=(const Serializer&)
{
        return(*this);        
}
Serializer::~Serializer()
{

}