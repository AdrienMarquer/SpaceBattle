//
// Created by bjo on 14/11/18.
//

#include <Game.h>

#include "Game.h"

void Game::add_info_game(int id, std::string &name, bool viewer, int time, e_state s) {
    std::shared_ptr<info_game> sharedptr(new info_game(id, name, viewer, time, NEW));
    this->vec_game.push_back(std::move(sharedptr));
}

void Game::add_my_shoot(int x, int y) {
std::shared_ptr<Case> sharedptr(new Case(x, y));
this->my_shoot.push_back(std::move(sharedptr));
}

void Game::add_o_shoot(int x, int y) {
std::shared_ptr<Case> sharedptr(new Case(x, y));
this->o_shoot.push_back(std::move(sharedptr));
}

void Game::add_my_ship(int x, int y) {
std::shared_ptr<Case> sharedptr(new Case(x, y));
this->my_shoot.push_back(std::move(sharedptr));
}

void Game::add_o_ship(int x, int y) {
std::shared_ptr<Case> sharedptr(new Case(x, y));
this->o_shoot.push_back(std::move(sharedptr));
}

void Game::add_my_hit(int x, int y) {
std::shared_ptr<Case> sharedptr(new Case(x, y));
this->my_hit.push_back(std::move(sharedptr));

}

void Game::add_o_hit(int x, int y) {
std::shared_ptr<Case> sharedptr(new Case(x, y));
this->o_hit.push_back(std::move(sharedptr));
}

void Game::add_viewer(std::string &pseudo) {
    this->vec_viewer.push_back(pseudo);
}

Game::Game() {
    this->ready = false;
    this->turn = false;
    this->nb_player_connected = 0;
}

Game::~Game() {
    this->vec_game.clear();
    this->my_shoot.clear();
    this->my_hit.clear();
    this->my_shoot.clear();
    this->my_hit.clear();
    this->message.clear();
    this->vec_viewer.clear();
    this->my_ship.clear();
    this->o_ship.clear();
}

int Game::getMy_id() const {
    return my_id;
}

void Game::setMy_id(int my_id) {
    Game::my_id = my_id;
}

const std::string &Game::getTime_() const {
    return time_;
}

void Game::setTime_(const std::string &time_) {
    Game::time_ = time_;
}

bool Game::isReady() const {
    return ready;
}

void Game::setReady(bool ready) {
    Game::ready = ready;
}

bool Game::isTurn() const {
    return turn;
}

void Game::setTurn(bool turn) {
    Game::turn = turn;
}

const std::vector<std::shared_ptr<info_game>> &Game::getVec_game() const {
    return vec_game;
}

const std::vector<std::shared_ptr<Case>> &Game::getMy_shoot() const {
    return my_shoot;
}

const std::vector<std::shared_ptr<Case>> &Game::getMy_hit() const {
    return my_hit;
}

const std::vector<std::shared_ptr<Case>> &Game::getO_shoot() const {
    return o_shoot;
}

const std::vector<std::shared_ptr<Case>> &Game::getO_hit() const {
    return o_hit;
}

int Game::getId_winner() const {
    return id_winner;
}

void Game::setId_winner(int id_winner) {
    Game::id_winner = id_winner;
}

e_state Game::getState() const {
    return state;
}

void Game::setState(e_state state) {
    Game::state = state;
}

const std::string &Game::getMy_pseudo() const {
    return my_pseudo;
}

void Game::setMy_pseudo(const std::string &my_pseudo) {
    Game::my_pseudo = my_pseudo;
}

const std::string &Game::getO_pseudo() const {
    return o_pseudo;
}

void Game::setO_pseudo(const std::string &o_pseudo) {
    Game::o_pseudo = o_pseudo;
}

void Game::clear_vec_info_game() {
    this->vec_game.clear();
}

const std::vector<std::string> &Game::getMessage() const {
    return message;
}

void Game::add_message(std::string &s) {
this->message.push_back(s);
}

void Game::clear_message_vec() {
    this->message.clear();
}

int Game::getNb_player_connected() const {
    return nb_player_connected;
}

void Game::setNb_player_connected(int nb_player_connected) {
    Game::nb_player_connected = nb_player_connected;
}

const std::vector<std::string> &Game::getVec_viewer() const {
    return vec_viewer;
}

const std::vector<std::shared_ptr<Case>> &Game::getMy_ship() const {
    return my_ship;
}

const std::vector<std::shared_ptr<Case>> &Game::getO_ship() const {
    return o_ship;
}

const std::string &Game::getGame_name() const {
    return game_name;
}

void Game::setGame_name(const std::string &game_name) {
    Game::game_name = game_name;
}


