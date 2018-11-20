#pragma once

#include "IServerSocket.hpp"
#include "Client.hpp"

#include <memory>
#include <list>
#include <boost/filesystem.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/map.hpp>
#include <Command/ICommand.hpp>
#include <Command/Bateau.hpp>
#include "Game.hpp"

class BattleSpaceServer : public IServerSocket::OnSocketEvent, public Client::OnClientEvent, private boost::noncopyable
{
public:
    BattleSpaceServer();
    virtual ~BattleSpaceServer();
    BattleSpaceServer(const BattleSpaceServer &) = delete;
    const BattleSpaceServer & operator = (const BattleSpaceServer &) = delete;
    void startServer();

public:
    static const unsigned int DEFAUT_LISTEN_PORT = 4243;
    static const unsigned int DEFAUT_QUEUE_SIZE = 128;

    void deleteClientMain(Client *cl);

public:
    void onNewConnection(IServerSocket *socket);
    void onCloseConnection(Client* client);
    void New_game(Client* client, std::string& cmd, ICommand::Instruction instruction);
    void Join_game(Client* client, std::string& cmd, ICommand::Instruction instruction);
    void Shoot(Client* client, std::string& cmd, ICommand::Instruction instruction);
    void Message(Client* client, std::string& cmd, ICommand::Instruction instruction);
    void Time(Client* client, std::string& cmd, ICommand::Instruction instruction);
    void Pseudo(Client* client, std::string& cmd, ICommand::Instruction instruction);
    void Ship(Client* client, std::string& cmd, ICommand::Instruction instruction);
    void Unknow(Client* client, std::string& cmd, ICommand::Instruction instruction);
    void send_to_all( std::string &cmd);
    void send_to_game(Client* callerClient, std::string &cmd);
    Game* find_game(Client* callerClient);
    bool is_in_game(Client*callerClient, Game *game);
    bool is_viewer(Client *callerClient,Game *g);
    void add_case(Client *callerClient, Bateau const &);
    void add_shoot(Client *callerClient, Tir const &);
    std::string& get_request_game(std::string &);
    void send_update_game();
    void send_list_game(Client *c);
    void send_id(Client *c, int id);
    void end_game(Client *c);
    void send_list_viewer(Client *client);
    void send_count_connection();
    void send_pseudo_opponent(Client*client);
    void send_name_game(Client *client);
    void send_data_viewer(Client *client);
    void send_viewer(Game*g, std::string &s);
    void send_ship_viewer(Client *client);
    void send_shoot_viewer(Client *client);
    void send_hit_viewer(Client *client);
    void send_data_viewer_join(Client *client);
private:
    std::shared_ptr<IServerSocket>     mServerSocket;
    std::list<Client*>                 mClients;
    std::vector<Game*>                   mGame;
};
