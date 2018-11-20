//
// Created by adrien on 11/19/18.
//

#include "MainMenu.h"
#include <iostream>
#include <boost/asio/buffer.hpp>
#include <Client.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/Gui.hpp>
#include <TGUI/TGUI.hpp>
#include <CreateGame.h>
#include "MainMenu.h"


MainMenu::MainMenu(Client *_client)
{
    client = _client;
}

MainMenu::~MainMenu()
{

}

void	MainMenu::disp()
{

    tgui::Theme theme{"../res/themes/Black.txt"};

    picture = tgui::Picture::create("../res/images/background.jpg");
    picture->setSize({"100%", "100%"});
    gui.add(picture);

    chatbox = tgui::ChatBox::create();
    chatbox->setRenderer(theme.getRenderer("ChatBox"));
    chatbox->setSize(400, 220);
    chatbox->setTextSize(18);
    chatbox->setPosition(1100, 600);
    chatbox->setLinesStartFromTop();
    gui.add(chatbox);

    chatEditBox = tgui::EditBox::create();
    chatEditBox->setSize(300, 40);
    chatEditBox->setPosition(1100, 850);
    chatEditBox->setDefaultText("Message");
    gui.add(chatEditBox);

    buttonChat = tgui::Button::create();
    buttonChat->setRenderer(theme.getRenderer("Button"));
    buttonChat->setPosition(1400, 850);
    buttonChat->setText("Send");
    buttonChat->setSize(100, 40);
    buttonChat->setTextSize(20);
    buttonChat->connect("pressed", [=]()
    {
        if(chatEditBox->getText().getSize() > 0){
            std::string commandeChat("MSG " + chatEditBox->getText() + "\n");
            client->getSocket_().write_some(boost::asio::buffer(commandeChat,commandeChat.size()));
        }else{
            std::cout << "Nothing selected" << std::endl;
        }
    });
    gui.add(buttonChat);

    listBox = tgui::ListBox::create();
    listBox->setRenderer(theme.getRenderer("ListBox"));
    listBox->setSize(300, 250);
    listBox->setItemHeight(30);
    listBox->setPosition(560, 250);
    gui.add(listBox);

    buttonJoin = tgui::Button::create();
    buttonJoin->setRenderer(theme.getRenderer("Button"));
    buttonJoin->setPosition(600, 550);
    buttonJoin->setText("Join selected game");
    buttonJoin->setSize(230, 50);
    buttonJoin->setTextSize(22);
    buttonJoin->connect("pressed", [=]()
    {
        if(listBox->getSelectedItemIndex() >= 0){
            std::cout << listBox->getSelectedItemIndex() << std::endl;
            //QUAND JOIN, SUPPR TOUS LES MESSAGES
        }else{
            std::cout << "Nothing selected" << std::endl;
        }
    });

    gui.add(buttonJoin);

    buttonView = tgui::Button::create();
    buttonView->setRenderer(theme.getRenderer("Button"));
    buttonView->setPosition(580, 620);
    buttonView->setText("Watch selected game");
    buttonView->setSize(270, 50);
    buttonView->setTextSize(22);
    buttonView->connect("pressed", [=]()
    {
        std::cout << "viewer" << std::endl;
    });
    gui.add(buttonView);


    buttonCreate = tgui::Button::create();
    buttonCreate->setRenderer(theme.getRenderer("Button"));
    buttonCreate->setPosition(615, 700);
    buttonCreate->setText("Create game");
    buttonCreate->setSize(200, 50);
    buttonCreate->setTextSize(22);
    buttonCreate->connect("pressed", [=]()
    {
        CreateGame create(client,&window);
        create.disp();
    });
    gui.add(buttonCreate);

    labelCo = tgui::Label::create();
    labelCo->setRenderer(theme.getRenderer("Label"));
    labelCo->setText("Players connected : ");
    labelCo->setPosition(1200, 30);
    labelCo->setTextSize(15);
    gui.add(labelCo);

    labelNum = tgui::Label::create();
    labelNum->setRenderer(theme.getRenderer("Label"));
    labelNum->setText("0");
    labelNum->setPosition(1365, 30);
    labelNum->setTextSize(15);
    gui.add(labelNum);

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event); // Pass the event to the widgets
        }

        flag = client->read_data();
        if(flag == 1){
            listBox->removeAllItems();
            for(auto it : client->getGame()->getVec_game()){
                listBox->addItem((*it).getName());
            }
            labelNum->setText(std::to_string(client->getGame()->getNb_player_connected()));
            chatbox->removeAllLines();
            for(auto it : client->getGame()->getMessage()){
                chatbox->addLine(it, sf::Color::Yellow);
            }
        }else if(flag == 0){
            //deco
        }else{
            //nothing
        }

        window.clear();
        gui.draw(); // Draw all widgets
        window.display();

    }
}