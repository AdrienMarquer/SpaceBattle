//
// Created by joa on 26/10/18.
//

#ifndef SERVER_PSEUDON_HPP
#define SERVER_PSEUDON_HPP


#include <string>
#include <vector>
#include <Error.h>

class Pseudon {
public:
    Pseudon(std::string&s);
    virtual ~Pseudon();
    void parse();
    const std::vector<std::string> &getVec() const;

    const std::string &getPseudo() const;

private:
    std::vector<std::string> vec;
    std::string              pseudo;

};


#endif //SERVER_PSEUDON_HPP
