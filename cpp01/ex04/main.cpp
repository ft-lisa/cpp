#include "main.hpp"

int ft_replace(char* file, std::string str1, std::string str2)
{
        std::string name;
        std::string sline;
        std::string sbefore;
        const char* after;
        const char* before;
        int size;

        name = file;
        name = name + ".replace";
        std::ifstream file1(file);
        if (!file1) 
                return std::cerr << "Le fichier est inexistant" << std::endl, 1;
        std::ofstream file2(name.c_str());
        if (!file2) 
                return std::cerr << "Echec de la creation du fichier" << std::endl, 1;
        if (str1.empty() || str2.empty())
                return std::cerr << "Les champs ne peuvent pas etre vide" << std::endl, 1;
        while(std::getline(file1, sline))
        {
                before = sline.c_str();
                sbefore = sline;
                after = strchr(before, str1[0]);
                while (after) 
                {
                        size = after - before;
                        sbefore.resize(size);
                        file2 << sbefore;
                        
                        if (strncmp(str1.c_str(), after, str1.size()) == 0)
                        {
                                file2 << str2;
                                sline.erase(0, size + str1.size());
                        }
                        else
                        {
                                file2 << after[0];
                                sline.erase(0, size + 1);
                        }
                        before = sline.c_str();
                        sbefore = sline;
                        after = strchr(before, str1[0]);
                        std::cout << std::endl << std::endl;
                }
                file2 << sline << std::endl;
        }
        return (0) ;
}

int main(int argc, char** argv)
{
        if (argc != 4)
                return std::cerr << "./replace [fichier] [mot 1] [mot 2]" << std::endl,1 ;
        
        return ft_replace(argv[1], argv[2], argv[3]);
}