//
// Created by joa on 26/10/18.
//

#ifndef SERVER_SHOOT_HPP
#define SERVER_SHOOT_HPP

#include <string>
#include <vector>

class Tir {
public:
    virtual ~Tir();
    Tir(std::string &str);
    Tir(int x, int y);
    void parse();
    void display_vec();

    const std::vector<std::string> &getVec() const;

    int getX() const;

    int getY() const;

private:
    std::vector<std::string> vec;
    int x;
    int y;
};


#endif //SERVER_SHOOT_HPP
