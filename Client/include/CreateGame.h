//
// Created by adrien on 11/20/18.
//

#ifndef CLIENT_CREATEGAME_H
#define CLIENT_CREATEGAME_H
#include <SFML/Window/Event.hpp>
#include <TGUI/TGUI.hpp>
#include "Client.h"

class CreateGame {
private:
    Client *client;
    std::string commandeCreate;

    sf::RenderWindow window{{400, 400}, "Create game"};
    //sf::RenderWindow *window;
    sf::Event event;
    tgui::Gui gui{window};

    tgui::EditBox::Ptr nameEditBox;
    tgui::CheckBox::Ptr viewerRadio;
    tgui::Label::Ptr label;
    tgui::Label::Ptr labelError;
    tgui::ListBox::Ptr list;
    tgui::Button::Ptr validateButton;


public:
    CreateGame(Client *_client,sf::RenderWindow *_window);
    ~CreateGame();
    void disp();
};


#endif //CLIENT_CREATEGAME_H
