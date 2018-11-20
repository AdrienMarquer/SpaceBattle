#include <iostream>
#include <fstream>
#include <boost/timer.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <thread>
#include "Client.h"
#include "ConnexionPage.h"
#include <TGUI/TGUI.hpp>
#include <MainMenu.h>


using boost::asio::ip::tcp;

int main(int argc, char **argv) {
    try
    {
        if (argc != 3)
        {
            std::cerr << "Usage: Client <host> <port>\n";
            return 1;
        }
        /*
        ConnexionPage connecPage;
        connecPage.disp();
        */
        boost::asio::io_service io_service;

        Client *client = new Client(io_service, "localhost", "4243");
        std::string str = "PSEUDO Adrien\n";
        client->getSocket_().write_some(boost::asio::buffer(str,str.size()));

        MainMenu main(client);
        main.disp();
        return 0;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}