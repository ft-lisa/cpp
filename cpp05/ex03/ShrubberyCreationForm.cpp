#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other){}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&)
{
        std::cerr << "Assignment operator is disabled due to const members." << std::endl;
        return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
        std::string name = _name + "_shrubbery";
        if (_signed == false)
            throw NotSigneException() ;
        if (executor.getGrade() > _grade_for_exec)
            throw GradeTooLowException();

        std::ofstream file2(name.c_str());
        if (!file2) 
                throw NotCreatFile();
        file2 << "                                                         .\n";
        file2 << "                                              .         ;\n";
        file2 << "                 .              .              ;%     ;;\n";
        file2 << "                   ,           ,                :;%  %;\n";
        file2 << "                    :         ;                   :;%;'     .,\n";
        file2 << "           ,.        %;     %;            ;        %;'    ,;\n";
        file2 << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
        file2 << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
        file2 << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
        file2 << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
        file2 << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
        file2 << "                    `:%;.  :;bd%;          %;@%;'\n";
        file2 << "                      `@%:.  :;%.         ;@@%;'\n";
        file2 << "                        `@%.  `;@%.      ;@@%;\n";
        file2 << "                          `@%%. `@%%    ;@@%;\n";
        file2 << "                            ;@%. :@%%  %@@%;\n";
        file2 << "                              %@bd%%%bd%%:;\n";
        file2 << "                                #@%%%%%:;;\n";
        file2 << "                                %@@%%%::;\n";
        file2 << "                                %@@@%(o);  . '\n";
        file2 << "                                %@@@o%;:(.,'\n";
        file2 << "                            `.. %@@@o%::;\n";
        file2 << "                               `)@@@o%::;\n";
        file2 << "                                %@@(o)::;\n";
        file2 << "                               .%@@@@%::;\n";
        file2 << "                               ;%@@@@%::;.\n";
        file2 << "                              ;%@@@@%%:;;;.\n";
        file2 << "                          ...;%@@@@@%%:;;;;,..\n";

        
}