//
// Created by bjo on 14/11/18.
//

#ifndef CLIENT_INFO_GAME_H
#define CLIENT_INFO_GAME_H

#include <string>

typedef enum enum_state{
    NEW,
    WAITING_PLAYER,
    WAINTING_LAUNCH,
    IN_PROGRESS,
    FINISH
}e_state;

class info_game {
public:

    info_game(int id, const std::string &name, bool viewer, int time, e_state state);

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    bool isViewer() const;

    void setViewer(bool viewer);

    int getTime() const;

    void setTime(int time);

    e_state getState() const;

    void setState(e_state state);

private:
    int             id;
    std::string     name;
    bool            viewer;
    int             time;
    e_state         state;
};


#endif //CLIENT_INFO_GAME_H
