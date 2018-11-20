//
// Created by bjo on 14/11/18.
//

#ifndef CLIENT_GAME_H
#define CLIENT_GAME_H


#include <vector>
#include <boost/shared_ptr.hpp>
#include "info_game.h"
#include "Case.h"

class Game {
public:
    Game();

    virtual ~Game();

    void add_info_game(int id, std::string &name, bool viewer, int time, e_state );
    void add_my_shoot(int x, int y);
    void add_my_ship(int x, int y);
    void add_o_shoot(int x, int y);
    void add_o_ship(int x, int y);
    void add_my_hit(int x, int y);
    void add_o_hit(int x, int y);
    void add_viewer(std::string &pseudo);

    int getMy_id() const;

    void setMy_id(int my_id);

    const std::string &getTime_() const;

    void setTime_(const std::string &time_);

    bool isReady() const;

    void setReady(bool ready);

    bool isTurn() const;

    void setTurn(bool turn);

    const std::vector<std::shared_ptr<info_game>> &getVec_game() const;

    const std::vector<std::shared_ptr<Case>> &getMy_shoot() const;

    const std::vector<std::shared_ptr<Case>> &getMy_hit() const;

    const std::vector<std::shared_ptr<Case>> &getO_shoot() const;

    const std::vector<std::shared_ptr<Case>> &getO_hit() const;

    int getId_winner() const;

    void setId_winner(int id_winner);

    e_state getState() const;

    void setState(e_state state);

    const std::string &getMy_pseudo() const;

    void setMy_pseudo(const std::string &my_pseudo);

    void clear_vec_info_game();

    const std::vector<std::string> &getMessage() const;

    void add_message(std::string&s);

    void clear_message_vec();

    int getNb_player_connected() const;

    void setNb_player_connected(int nb_player_connected);

    const std::vector<std::string> &getVec_viewer() const;

    const std::vector<std::shared_ptr<Case>> &getMy_ship() const;

    const std::vector<std::shared_ptr<Case>> &getO_ship() const;

    const std::string &getO_pseudo() const;

    void setO_pseudo(const std::string &o_pseudo);

    const std::string &getGame_name() const;

    void setGame_name(const std::string &game_name);

private:
    int                                           nb_player_connected; // on server
    std::vector<std::shared_ptr<info_game> >      vec_game;   // game list
    std::vector<std::string>                      vec_viewer; // pseudo viewer
    std::string                                   game_name;

    e_state                                       state;    // game state

    int                                           my_id;
    std::string                                   my_pseudo; // my pseudo
    std::vector<std::shared_ptr<Case> >           my_ship;
    std::vector<std::shared_ptr<Case> >           my_shoot;
    std::vector<std::shared_ptr<Case> >           my_hit;



    std::string                                   o_pseudo;  // pseudo opponnent
    std::vector<std::shared_ptr<Case> >           o_ship;
    std::vector<std::shared_ptr<Case> >           o_shoot;
    std::vector<std::shared_ptr<Case> >           o_hit;


    std::string                                   time_;
    bool                                          ready;
    bool                                          turn; // pass to false when you send shoot to server
    int                                           id_winner; // -1 if egal

    std::vector<std::string>                      message; //clear_message_vec when join game
};


#endif //CLIENT_GAME_H
