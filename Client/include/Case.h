//
// Created by bjo on 14/11/18.
//

#ifndef CLIENT_CASE_H
#define CLIENT_CASE_H


class Case {
public:
    Case(int x, int y);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

private:
    int         x;
    int         y;
};


#endif //CLIENT_CASE_H
