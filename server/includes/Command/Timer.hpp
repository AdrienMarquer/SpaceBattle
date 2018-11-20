//
// Created by joa on 26/10/18.
//

#ifndef SERVER_TIMER_HPP
#define SERVER_TIMER_HPP

#include <string>
#include <vector>
#include <Error.h>


class Timer {
public:
    Timer(std::string&s);

    virtual ~Timer();
    void parse();

    const std::vector<std::string> &getVec() const;

    int getTime() const;

private:
    std::vector<std::string> vec;
    int                      time;
};


#endif //SERVER_TIMER_HPP
