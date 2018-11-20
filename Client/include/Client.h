#ifndef TEST_CLIENT_H
#define TEST_CLIENT_H

#include <boost/timer.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "info_game.h"
#include "Case.h"
#include "Game.h"

using boost::asio::ip::tcp;

typedef enum status {
    UNDEFINED,
    PLAYER_IN_GAME,
    VIEWER_IN_GAME
}e_status;

class Client {
public:
    Client(boost::asio::io_context &io_context_, const char *add, const char *port);
    virtual ~Client();

    tcp::socket &getSocket_();

    int read_data();
    bool get_command();
    void parse_command(std::string&cmd);
    void treatCommand(std::vector<std::string> &param, std::string &cmd);
    void Id(std::vector<std::string>& param, std::string &cmd);
    void Info(std::vector<std::string>& param, std::string &cmd);
    void Shoot(std::vector<std::string>& param, std::string &cmd);
    void Hit(std::vector<std::string>& param, std::string &cmd);
    void Time(std::vector<std::string>& param, std::string &cmd);
    void Ready(std::vector<std::string>& param, std::string &cmd);
    void Turn(std::vector<std::string>& param, std::string &cmd);
    void Winner(std::vector<std::string>& param, std::string &cmd);
    void Pseudo(std::vector<std::string>& param, std::string &cmd);
    void Msg(std::vector<std::string>& param, std::string &cmd);
    void Ok(std::vector<std::string>& param, std::string &cmd);
    void Ko(std::vector<std::string>& param, std::string &cmd);
    void Viewer(std::vector<std::string>& param, std::string &cmd);
    void Count(std::vector<std::string>& param, std::string &cmd);
    void Ship(std::vector<std::string>& param, std::string &cmd);
    void nGame(std::vector<std::string> &param, std::string &cmd);
    void Status(std::vector<std::string> &param, std::string &cmd);


    void parse_Info(std::string &cmd);
    void check_info_param(std::vector<std::string> &vec);
    e_state get_state(std::string &s) const;
private:
    boost::asio::io_service&    io_service_;
    tcp::socket                 socket_;
    std::string                 stream;
    struct HandleCommand {
            std::string            instruction;
            void				  (Client::*handler)(std::vector<std::string> &param, std::string &cmd);
        };
    static const Client::HandleCommand handleCommandsTab[];

    /* GAME INFORMATION */
    std::shared_ptr<Game>           game;
public:
    const std::shared_ptr<Game> &getGame() const;

private:
    e_status                        status;
};



#endif //TEST_CLIENT_H
