//
// Created by joa on 26/10/18.
//

#ifndef SERVER_MSG_HPP
#define SERVER_MSG_HPP

#include <string>
#include <vector>
#include <Error.h>

class Msg {
public:
    Msg(std::string&s);
    virtual ~Msg();
    void parse();
    const std::vector<std::string> &getVec() const;

private:
    std::vector<std::string> vec;
};


#endif //SERVER_MSG_HPP
