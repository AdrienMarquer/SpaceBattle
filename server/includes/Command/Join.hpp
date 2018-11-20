//
// Created by joa on 26/10/18.
//

#ifndef SERVER_JOIN_HPP
#define SERVER_JOIN_HPP

#include <string>
#include <vector>
#include <Error.h>

class Join {
public:
    Join(std::string&s);

    virtual ~Join();
    void parse();

    const std::vector<std::string> &getVec() const;
    int getId_game() const;
    bool isViewer() const;
private:
    std::vector<std::string> vec;
    int                         id_game;
    bool                        viewer;
};


#endif //SERVER_JOIN_HPP
