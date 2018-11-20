#pragma once

#include "IClientSocket.hpp"
#include "IServerSocket.hpp"


#include <vector>
#include <list>
#include <utility>
#include <algorithm>

#include <boost/filesystem.hpp>
#include <boost/serialization/list.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <Command/ICommand.hpp>
#include "Command/Bateau.hpp"
#include "Command/Tir.hpp"

typedef enum e_client_state {
    UNDEFINED,
    PLAYER,
    VIEWER
} e_state;

class Client : public IClientSocket::OnSocketEvent {

    // interface for client callback
    public:
	    class OnClientEvent{
	    public:
		    virtual ~OnClientEvent() {}
            virtual void onCloseConnection(Client* client) = 0;
            virtual void New_game(Client* client, std::string& cmd, ICommand::Instruction instruction) = 0;
            virtual void Join_game(Client* client, std::string& cmd, ICommand::Instruction instruction) = 0;
            virtual void Shoot(Client* client, std::string& cmd, ICommand::Instruction instruction) = 0;
            virtual void Message(Client* client, std::string& cmd, ICommand::Instruction instruction) = 0;
            virtual void Time(Client* client, std::string& cmd, ICommand::Instruction instruction) = 0;
            virtual void Pseudo(Client* client, std::string& cmd, ICommand::Instruction instruction) = 0;
            virtual void Ship(Client* client, std::string& cmd, ICommand::Instruction instruction) = 0;
            virtual void Unknow(Client* client, std::string& cmd, ICommand::Instruction instruction) = 0;
        };

    // ctors dtors
    public:
        Client(IClientSocket* clientSocket, Client::OnClientEvent* listenerClient, int i);
        virtual ~Client();
        const Client & operator = (const Client &other);
        Client(const Client &) = delete;

    // handle commands
    private:
        struct HandleCommand {
            std::string             str;
            ICommand::Instruction   instruction;
            void				  (Client::OnClientEvent::*handler)(Client*, std::string &cmd, ICommand::Instruction instruction);
        };
        static const Client::HandleCommand	handleCommandsTab[];
    public:
        void treatCommand(ICommand::Instruction instruction, std::string &cmd);
        void onBytesWritten(IClientSocket *, unsigned int);
	    void onSocketReadable(IClientSocket *socket, std::string &cmd);
	    void onSocketClosed(IClientSocket *socket);
        void disconnect(void);
        void connect(void);
        void setConnected(bool state);
	    bool						  isConnect(void) const;
        ICommand::Instruction getInstruction(std::string &cmd);

    int getId() const;

	e_state getState() const;

	void setState(e_state state);

	bool add_bateau(Bateau *b);

	void add_shoot(Tir *t);

    void add_hit(Tir *t);

    const std::string &getPseudo() const;

    void setPseudo(const std::string &pseudo);

    bool isIsPseudo() const;

    void setIsPseudo(bool isPseudo);

    bool isIsturn() const;

    void setIsturn(bool isturn);

    bool isHit(int x, int y);

    const std::list<Bateau *> &getCase_() const;

    const std::list<Tir *> &getHit_() const;

    const std::list<Tir *> &getTir_() const;

public:
    IClientSocket* Socket;
    Client::OnClientEvent*  Listener;

private:
    int                         id;
    bool                        isConnected;
    bool                        isReady;
    bool                        isPseudo;
    bool                        isturn;
public:
    bool isIsReady() const;

    void setIsReady(bool isReady);

private:
    e_state                     state;

    std::list<Bateau*>        case_;
    std::list<Tir*>           tir_;
    std::list<Tir*>           hit_;
    std::string               pseudo;
};
