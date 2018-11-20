#ifndef SERVER_NEW_GAME_HPP
#define SERVER_NEW_GAME_HPP

#include <string>
#include <vector>

class New {
public:
    virtual ~New();
    New(std::string &str);
    void parse();
    void display_vec();

    const std::vector<std::string> &getVec() const;

    bool isViewer() const;

    std::string &getName();

    int getTime() const;

private:
    std::vector<std::string> vec;
    bool                    viewer;
    std::string             name;
    int                     time;
};


#endif //SERVER_NEW_GAME_HPP
