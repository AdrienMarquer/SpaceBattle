#ifndef SERVER_GAME_HPP
#define SERVER_GAME_HPP

#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
#include "Client.hpp"

typedef enum e_game_state{
    NEW,
    WAITING_PLAYER,
    WAITING_LAUNCH,
    IN_PROGRESS,
    FINISH
}g_state;

class Game {
public:
    Game(boost::asio::io_service& io,int id, Client *player1, bool viewer, std::string &n, int time);
    virtual ~Game();

    int getId() const;

    g_state getState() const;

    Client *getPlayer1() const;

    Client *getPlayer2() const;

    bool isViewer() const;

    std::list<Client *> &getList_viewer();

    void setPlayer2(Client *player2);

    void add_viewer(Client*c);

    void start();

    int getTime() const;

    void setTime(int time);

    bool is_player_ready();

    void change_turn(Client *c);

    const std::string &getName() const;

    int is_winner();

    void send_time();

    void handle_timer(boost::system::error_code const & ec );

   void end_game();

   void send_to_game(std::string &cmd);

private:
    boost::asio::deadline_timer timer_;
    int                         id;
    g_state                     state;
    Client                      *player1;
    Client                      *player2;

    bool                        viewer;
    std::string                 name;
    int                         time_;
    std::list<Client*>          list_viewer;
};


#endif //SERVER_GAME_HPP
