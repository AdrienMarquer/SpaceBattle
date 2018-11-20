//
// Created by bjo on 14/11/18.
//

#include "info_game.h"

info_game::info_game(int id, const std::string &name, bool viewer, int time, e_state state) : id(id), name(name),
                                                                                              viewer(viewer),
                                                                                              time(time),
                                                                                              state(state) {}

int info_game::getId() const {
    return id;
}

void info_game::setId(int id) {
    info_game::id = id;
}

const std::string &info_game::getName() const {
    return name;
}

void info_game::setName(const std::string &name) {
    info_game::name = name;
}

bool info_game::isViewer() const {
    return viewer;
}

void info_game::setViewer(bool viewer) {
    info_game::viewer = viewer;
}

int info_game::getTime() const {
    return time;
}

void info_game::setTime(int time) {
    info_game::time = time;
}

e_state info_game::getState() const {
    return state;
}

void info_game::setState(e_state state) {
    info_game::state = state;
}
