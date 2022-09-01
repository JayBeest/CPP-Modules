#ifndef GRADE_TOO_LOW_EXCEPTION_H
# define GRADE_TOO_LOW_EXCEPTION_H

# include <exception>

class GradeTooLowException : public std::exception {

public:
    const char * what() const throw ();
};

#endif
