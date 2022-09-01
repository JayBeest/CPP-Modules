#ifndef GRADE_TOO_HIGH_EXCEPTION_H
# define GRADE_TOO_HIGH_EXCEPTION_H

# include <exception>

class GradeTooHighException : public std::exception {

public:

    const char * what() const _NOEXCEPT;

};

#endif
