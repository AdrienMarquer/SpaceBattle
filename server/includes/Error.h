//
// Created by joa_b on 13/04/17.
//

#ifndef _ERROR_H
#define _ERROR_H

#include <exception>
#include <string>

class Error: public std::exception {
public:
    Error(std::string const& s="") throw():err(s) {

    }
     virtual const char* what() const throw() {
         return err.c_str();
     }

    virtual ~Error() throw()
    {}

private:
    std::string err;
};


#endif //TEST_PLAZZA_ERROR_H
