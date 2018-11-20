//
// Created by adrien on 11/19/18.
//

#ifndef CLIENT_MAINMENU_H
#define CLIENT_MAINMENU_H


#include <SFML/Window/Event.hpp>
#include <TGUI/TGUI.hpp>
#include "Client.h"

class MainMenu {
private:
    sf::RenderWindow window{{1500, 900}, "SpaceBattle"};
    tgui::Gui gui{window}; // Create the gui and attach it to the window
    Client *client;
    int flag;

    sf::Event event;

    tgui::Picture::Ptr picture;
    tgui::ChatBox::Ptr chatbox;
    tgui::ListBox::Ptr listBox;
    tgui::Button::Ptr buttonJoin;
    tgui::Button::Ptr buttonView;
    tgui::Button::Ptr buttonCreate;
    tgui::Label::Ptr labelCo;
    tgui::Label::Ptr labelNum;
    tgui::EditBox::Ptr chatEditBox;
    tgui::Button::Ptr buttonChat;


public:
    MainMenu(Client *_client);
    ~MainMenu();
    void disp();
};


#endif //CLIENT_MAINMENU_H
