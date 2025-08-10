#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), target("default target")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &tmp) : Form(tmp.getName(), tmp.getSignGrade(), tmp.getExecGrade()), target(tmp.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &tmp)
{
    target = tmp.target;
    return (*this);
}

void                    ShrubberyCreationForm::execute(const Bureaucrat &B) const
{
    if (B.getGrade() > getExecGrade())
    {   
        std::cout << "can't execute, ";
        throw   GradeTooLowException();
    }
    if (!getSigned())
    {
        std::cout << "can't execute, ";
        throw   FormIsNotSigned();
    }
    std::ofstream   out;
    out.open(target + "_shrubbery");
    if (!out.is_open())
        throw FileIsNotOpen();
    out << "                -!;                     " << std::endl;					
	out << "               ~ :,,.                   " << std::endl;					
	out << "             ~!!!~,,.                   " << std::endl;					
	out << "           .;*;,;.:::~ ;,               " << std::endl;					
	out << "            ;!:~.:;:!;*!:*              " << std::endl;						
	out << "            ~*;;:!!==!.=*!              " << std::endl;					
	out << "             -!:!*;!;*;$*$!,            " << std::endl;					
	out << "            . *$~***=*;;*;=             " << std::endl;					
	out << "           -.;~~-=;*-=--*!--.           " << std::endl;				
	out << "           ;:*,~ ~! ~=.$#$*=*!          " << std::endl;				
	out << "           ;     =*:~-=~:*=:#-          " << std::endl;			
	out << "                 .- ~ =;==~~            " << std::endl;		
	out << "                   ;   -, .--           " << std::endl;			
	out << "           .;!   .    ~     .           " << std::endl;				
	out << "          !-*!;  ,; =*!                 " << std::endl;			
	out << "         !=!:~!!- !$~$!$:               " << std::endl;			
	out << "         =.;=;!*- ~;-:$!*               " << std::endl;		
	out << "          .   $$: ~. ;;=~               " << std::endl;	
	out << "               :  *  :  .               " << std::endl;
	out << "                   ~ ~                  " << std::endl;				
	out << "                   :.                   " << std::endl;			
	out << "                    :                   " << std::endl;			
	out << "                    ~                   " << std::endl;			
	out << "                    -                   " << std::endl;		
	out << "                    ~                   " << std::endl;			
	out << "                    ~                   " << std::endl;			
	out << "                    :                   " << std::endl;	
	out << "                    ,                   " << std::endl;
    out << "                    ,                   " << std::endl;
    out << "                    -                   " << std::endl;
    out << "                    ~                   " << std::endl;
    out << "                    ~                   " << std::endl;
    out << "                    !                   " << std::endl;
    out << "                    ;                   " << std::endl;
    out << "                    !                   " << std::endl;
    out.close();
    std::cout << "successfully created " << target << "_shrubbery" << std::endl;
}

const char*     ShrubberyCreationForm::FileIsNotOpen::what(void) const throw()
{
    return ("file is not open");
}