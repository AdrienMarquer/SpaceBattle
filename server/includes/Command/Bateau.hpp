//
// Created by joa on 02/11/18.
//

#ifndef SERVER_BATEAU_HPP
#define SERVER_BATEAU_HPP

#include <string>
#include <vector>

class Bateau {
public:
    virtual ~Bateau();
    Bateau(std::string &str);
    Bateau(int x, int y);
    void parse();
    const std::vector<std::string> &getVec() const;

    int getX() const;

    void setX(int x0);

    int getY() const;

    void setY(int y0);


private:
    std::vector<std::string> vec;
    int x;
    int y;
};

#endif //SERVER_BATEAU_HPP
