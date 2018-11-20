#include <iostream>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <Client.h>

#include "Client.h"

Client::Client(boost::asio::io_service &io_service_, const char *add, const char *port):
        io_service_(io_service_),
        socket_(io_service_)
{
    tcp::resolver resolver(io_service_);
    tcp::resolver::query query(tcp::v4(), add, port);
    tcp::resolver::iterator iterator = resolver.resolve(query);
    boost::asio::connect(socket_, iterator);
    this->game = std::make_shared<Game>();
    this->status = UNDEFINED;
    std::cout << "[TCP] Client connection Ok" << std::endl;
}

Client::~Client() {

}

int Client::read_data() {
    io_service_.poll();
    char data[1024];
    size_t read;
    int flag = -1;
    boost::system::error_code error;

    size_t availBytes = socket_.available();
    if (availBytes == 0) {
        return -1;
    }
    read = socket_.read_some(boost::asio::buffer(data, 1024), error);
    if (error == boost::asio::error::eof)
        throw boost::system::system_error(error);
    else if (error)
        throw boost::system::system_error(error);
    if (data != 0) {
        data[read] = '\0';
        this->stream += data;
        bzero(data, 1024);
        if (get_command())
            flag = 1;
    }
    return flag;
}

bool Client::get_command() {
    std::istringstream iss(this->stream);
    bool flag = false;

    std::string line;
    while (std::getline(iss, line)) {
        parse_command(line);
        this->stream = this->stream.substr(stream.find_first_of('\n')+1);
        flag = true;
    }
    return flag;
}

void Client::parse_command(std::string&cmd) {
    std::vector<std::string> param;

    std::istringstream s ( cmd);
    param.insert(param.end(),
                 std::istream_iterator<std::string>(s),
                 std::istream_iterator<std::string>());
    if (param.size() == 0)
        return ;
    treatCommand(param, cmd);
}

const Client::HandleCommand Client::handleCommandsTab[] =
        {
                { "ID", &Client::Id },
                { "INFO", &Client::Info },
                { "SHOOT", &Client::Shoot },
                { "SHIP", &Client::Ship },
                { "HIT", &Client::Hit },
                { "TIME", &Client::Time },
                { "READY", &Client::Ready },
                { "TURN", &Client::Turn },
                { "WINNER", &Client::Winner },
                { "PSEUDO", &Client::Pseudo },
                { "MSG", &Client::Msg },
                { "OK", &Client::Ok },
                { "KO", &Client::Ko },
                { "VIEWER", &Client::Viewer },
                { "COUNT", &Client::Count },
                { "GAME", &Client::nGame },
                { "STATUS", &Client::Status },
                { "UNKNOWN_INSTRUCTION", NULL },
        };

void	Client::treatCommand(std::vector<std::string> &param, std::string &cmd) {
    int i;

    for (i = 0; handleCommandsTab[i].instruction != "UNKNOWN_INSTRUCTION"; ++i) {
        if (handleCommandsTab[i].instruction == param.at(0)) {
            ((this)->*handleCommandsTab[i].handler)(param, cmd);
            return ;
        }
    }
    std::cerr << "Unknown command" << std::endl;
}

void Client::Id(std::vector<std::string> &param, std::string &cmd) {
    if (param.size() != 2) {
        std::cerr << "Bad command ID" << std::endl;
        return ;
    }
    try {
        this->game->setMy_id(std::stoi(param.at(1)));
    }catch (std::exception &e) {
        std::cerr << "Exception ID: " << e.what() << std::endl;
        return ;
    }
    std::cout << "ID: " << this->game->getMy_id() << std::endl;
}

void Client::Info(std::vector<std::string> &param, std::string &cmd) {
    this->game->clear_vec_info_game();
    this->parse_Info(cmd);

std::cout << "Info" << std::endl;
}

void Client::Shoot(std::vector<std::string> &param, std::string &cmd) {
    if (param.size() != 4) {
        std::cerr << "Bad command SHOOT" << std::endl;
        return ;
    }
    try {
        int id = std::stoi(param.at(1));
        int x = std::stoi(param.at(2));
        int y = std::stoi(param.at(3));

        if (id == this->game->getMy_id()) {
            this->game->add_my_shoot(x,y);
        } else {
            this->game->add_o_shoot(x,y);
        }
    } catch (std::exception &e) {
        std::cerr << "Exception SHOOT: " << e.what() << std::endl;
        return ;
    }
    std::cout << "Shoot" << std::endl;
}

void Client::Hit(std::vector<std::string> &param, std::string &cmd) {
    if (param.size() != 4) {
        std::cerr << "Bad command HIT" << std::endl;
        return ;
    }
    try {
        int id = std::stoi(param.at(1));
        int x = std::stoi(param.at(2));
        int y = std::stoi(param.at(3));

        if (id == this->game->getMy_id()) {
            this->game->add_my_hit(x,y);
        } else {
            this->game->add_o_hit(x,y);
        }
    } catch (std::exception &e) {
        std::cerr << "Exception HIT: " << e.what() << std::endl;
        return ;
    }
    std::cout << "Hit" << std::endl;
}

void Client::Time(std::vector<std::string> &param, std::string &cmd) {
    if (param.size() != 2) {
        std::cerr << "Bad command TIME" << std::endl;
    }
    this->game->setTime_(param.at(1));
    std::cout << "Time" << std::endl;
}

void Client::Ready(std::vector<std::string> &param, std::string &cmd) {
    if (param.size() != 1) {
        std::cerr << "Bad command READY" << std::endl;
    }
    this->game->setReady(true);
    this->game->setState(IN_PROGRESS);
    std::cout << "Ready" << std::endl;
}

void Client::Turn(std::vector<std::string> &param, std::string &cmd) {
if (param.size() != 1) {
        std::cerr << "Bad command TURN" << std::endl;
    }
    this->game->setTurn(true);
    std::cout << "Turn" << std::endl;
}

void Client::Winner(std::vector<std::string> &param, std::string &cmd) {
 if (param.size() != 2) {
        std::cerr << "Bad command WINNER" << std::endl;
        return ;
    }
    try {
        this->game->setId_winner(std::stoi(param.at(1)));
        this->game->setState(FINISH);
    }catch (std::exception &e) {
        std::cerr << "Exception WINNER: " << e.what() << std::endl;
        return ;
    }
    std::cout << "WINNER: " << this->game->getId_winner() << std::endl;
}

void Client::Pseudo(std::vector<std::string> &param, std::string &cmd) {
    if (param.size() < 3) {
        std::cerr << "Bad command PSEUDO" << std::endl;
        return ;
    }
    try {
        param.erase(param.begin());
        int id = std::stoi(param.at(0));
        param.erase(param.begin());
        auto it = param.begin();
        std::string pseudo;

        while (it != param.end()) {
            pseudo += (*it);
            pseudo += " ";
            it++;
        }
        if (id == this->game->getMy_id()) {
            this->game->setMy_pseudo(pseudo);
        } else {
            this->game->setO_pseudo(pseudo);
        }
        std::cout << "Pseudo: " << pseudo << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception PSEUDO: " << e.what() << std::endl;
        return ;
    }
}

void Client::Msg(std::vector<std::string> &param, std::string &cmd) {
if (param.size() < 2) {
        std::cerr << "Bad command MSG" << std::endl;
        return ;
    }
    try {
        param.erase(param.begin());
        auto it = param.begin();
        std::string msg;

        while (it != param.end()) {
            msg += (*it);
            msg += " ";
            it++;
        }
        this->game->add_message(msg);
        std::cout << "Message: " << msg << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception MSG: " << e.what() << std::endl;
        return ;
    }
}

void Client::parse_Info(std::string &cmd) {
    std::istringstream ss(cmd);
    std::string token;

    std::vector<std::string> token_vec;
    while(std::getline(ss, token, ';')) {
        token_vec.push_back(token);
    }

    auto it = token_vec.begin();
    while (it != token_vec.end()) {
        std::istringstream s (*it);
        std::vector<std::string> vec;
        vec.insert(vec.end(),
                   std::istream_iterator<std::string>(s),
                   std::istream_iterator<std::string>());
        check_info_param(vec);
        it++;
    }
}

void Client::check_info_param(std::vector<std::string> & vec) {
    if (vec.size() < 6) {
        std::cerr << "Bad command INFO" << std::endl;
    }
    vec.erase(vec.begin());
    try {
        int id_game = std::stoi(vec.at(0));
        vec.erase(vec.begin());

        e_state state = get_state(vec.at(0));
        vec.erase(vec.begin());

        int time = std::stoi(vec.at(0));
        vec.erase(vec.begin());

        bool viewer;
        viewer = !(vec.at(0) == "0");
        vec.erase(vec.begin());

        std::string game_name;
        auto it = vec.begin();
        while (it!= vec.end()) {
            game_name += *it;
            game_name += " ";
            it++;
        }
        this->game->add_info_game(id_game, game_name,viewer,time,state);

    } catch (std::exception &e) {
        std::cerr << "Exception INFO: " << e.what() << std::endl;
        return ;
    }
}

e_state Client::get_state(std::string &s) const {

    if (s == "NEW")
        return NEW;
    else if (s == "WAITING_PLAYER")
        return WAITING_PLAYER;
    else if (s == "WAITING_LAUNCH")
        return WAINTING_LAUNCH;
    else if (s == "IN_PROGRESS")
        return IN_PROGRESS;
    else
        return FINISH;
}

tcp::socket &Client::getSocket_() {
    return socket_;
}

void Client::Ok(std::vector<std::string> &param, std::string &cmd) {
std::cout << "Command OK" << std::endl;
}

void Client::Ko(std::vector<std::string> &param, std::string &cmd) {
    std::cerr << "Command KO" << std::endl;
}

void Client::Viewer(std::vector<std::string> &param, std::string &cmd) {
    std::istringstream ss(cmd);
    std::string token;
    cmd = cmd.substr(cmd.find_first_of(" \t")+1);

    while(std::getline(ss, token, ';')) {
        this->game->add_viewer(token);
    }
}

void Client::Count(std::vector<std::string> &param, std::string &cmd) {
 if (param.size() != 2) {
        std::cerr << "Bad command COUNT" << std::endl;
        return ;
    }
    try {
        this->game->setNb_player_connected(std::stoi(param.at(1)));
    }catch (std::exception &e) {
        std::cerr << "Exception COUNT: " << e.what() << std::endl;
        return ;
    }
    std::cout << "nb player connected: " << this->game->getNb_player_connected() << std::endl;
}

void Client::Ship(std::vector<std::string> &param, std::string &cmd) {
if (param.size() != 4) {
        std::cerr << "Bad command Ship" << std::endl;
        return ;
    }
    try {
        int id = std::stoi(param.at(1));
        int x = std::stoi(param.at(2));
        int y = std::stoi(param.at(3));

        if (id == this->game->getMy_id()) {
            this->game->add_my_ship(x,y);
        } else {
            this->game->add_o_ship(x,y);
        }
    } catch (std::exception &e) {
        std::cerr << "Exception SHIP: " << e.what() << std::endl;
        return ;
    }
    std::cout << "Ship" << std::endl;
}

void Client::nGame(std::vector<std::string> &param, std::string &cmd) {
    if (param.size() < 2) {
        std::cerr << "Bad command GAME" << std::endl;
        return ;
    }
    try {
        param.erase(param.begin());
        auto it = param.begin();
        std::string game;

        while (it != param.end()) {
            game += (*it);
            game += " ";
            it++;
        }
        this->game->setGame_name(game);
        std::cout << "Game: " << game << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception GAME: " << e.what() << std::endl;
        return ;
    }
}

void Client::Status(std::vector<std::string> &param, std::string &cmd) {
    if (param.size() != 2) {
        std::cerr << "Bad command STATUS" << std::endl;
        return ;
    }
    try {
        if (param.at(1) == "UNDEFINED") {
            std::cout << "STATUS: " << param.at(1) << std::endl;
            this->status = UNDEFINED;
        }
        else if (param.at(1) == "PLAYER_IN_GAME") {
            std::cout << "STATUS: " << param.at(1) << std::endl;
            this->status = PLAYER_IN_GAME;
        }
        else if (param.at(1) == "VIEWER_IN_GAME") {
            std::cout << "STATUS: " << param.at(1) << std::endl;
            this->status = VIEWER_IN_GAME;
        }

    }catch (std::exception &e) {
        std::cerr << "Exception STATUS: " << e.what() << std::endl;
        return ;
    }
}

const std::shared_ptr<Game> &Client::getGame() const {
    return game;
}

