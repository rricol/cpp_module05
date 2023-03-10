#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat Lambda"), _grade(150)
{
   std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat overload constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &rhs ): _name(rhs.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs )
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName( void ) const
{
	return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void Bureaucrat::upGrade( int amount )
{
	if (this->_grade == this->maxGrade || (this->_grade - amount) < this->maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= amount;
}

void Bureaucrat::downGrade( int amount )
{
	if (this->_grade == this->minGrade || (this->_grade + amount) > this->minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += amount;
}

std::ostream &operator<<( std::ostream &o, Bureaucrat const &rhs )
{
	o << rhs.getName() << ", son grade est " << rhs.getGrade() << "." << std::endl;
	return o;
}