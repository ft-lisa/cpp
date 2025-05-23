#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

class Brain
{
        public:
                Brain();
                ~Brain();
                Brain(const Brain&);
                Brain& operator=(const Brain&);
                void setIdeas(std::string str, int i);
                std::string getIdeas(int i);
        protected:

        private:
                std::string ideas[100];
};

#endif