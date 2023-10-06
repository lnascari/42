#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation form", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &p) : AForm(p)
{
	*this = p;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &p)
{
	if(this == &p)
		return *this;
	target = p.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char *ShrubberyCreationForm::execute(Bureaucrat &executor)
{
	try {
		if (!getSigned())
			throw FormNotSignedException();
		if (executor.getGrade() > getExecute())
			throw GradeTooLowException();
		std::ofstream file((target + std::string("_shrubbery")).c_str());
		file << "                                              .\n                                   .         ;\n      .              .              ;%     ;;\n        ,           ,                :;%  %;\n         :         ;                   :;%;'     .,\n,.        %;     %;            ;        %;'    ,;\n  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n    ;%;      %;        ;%;        % ;%;  ,%;'\n     `%;.     ;%;     %;'         `;%%;.%;'\n      `:;%.    ;%%. %@;        %; ;@%;%'\n         `:%;.  :;bd%;          %;@%;'\n           `@%:.  :;%.         ;@@%;'\n             `@%.  `;@%.      ;@@%;\n               `@%%. `@%%    ;@@%;\n                 ;@%. :@%%  %@@%;\n                   %@bd%%%bd%%:;\n                     #@%%%%%:;;\n                     %@@%%%::;\n                     %@@@%(o);  . '\n                     %@@@o%;:(.,' \n                 `.. %@@@o%::;\n                    `)@@@o%::;\n                     %@@(o)::;\n                    .%@@@@%::;\n                    ;%@@@@%::;.\n                   ;%@@@@%%:;;;.\n               ...;%@@@@@%%:;;;;,..";
		file.close();
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		return e.what();
	}
	return 0;
}