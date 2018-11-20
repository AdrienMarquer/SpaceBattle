//
// Created by adrien on 11/20/18.
//

#include "CreateGame.h"


#include <iostream>
#include <boost/asio/buffer.hpp>
#include <Client.h>
#include <TGUI/TGUI.hpp>
#include <MainMenu.h>


CreateGame::CreateGame(Client *_client, sf::RenderWindow *_window)
{
    client = _client;
}

CreateGame::~CreateGame()
{

}

void	CreateGame::disp()
{
    tgui::Theme theme{"../res/themes/Black.txt"};

    nameEditBox = tgui::EditBox::create();
    nameEditBox->setSize(200, 40);
    nameEditBox->setPosition(100, 50);
    nameEditBox->setDefaultText("Name of the game");
    gui.add(nameEditBox);

    label = tgui::Label::create();
    label->setRenderer(theme.getRenderer("Label"));
    label->setText("Activate viewers ? :");
    label->setPosition(70, 130);
    label->setTextSize(18);
    gui.add(label);

    labelError = tgui::Label::create();
    labelError->setRenderer(theme.getRenderer("Label"));
    labelError->setText("Missing parameters");
    labelError->setPosition(90, 310);
    labelError->setTextSize(18);

    viewerRadio = tgui::CheckBox::create();
    viewerRadio->setRenderer(theme.getRenderer("CheckBox"));
    viewerRadio->setPosition(270, 130);
    viewerRadio->setSize(25, 25);
    gui.add(viewerRadio);

    list= tgui::ListBox::create();
    list->setRenderer(theme.getRenderer("ListBox"));
    list->setSize(250, 120);
    list->setItemHeight(24);
    list->setPosition(70, 170);
    list->addItem("15 minutes");
    list->addItem("30 minutes");
    list->addItem("40 minutes");
    list->addItem("No limit");
    gui.add(list);

    validateButton = tgui::Button::create();
    validateButton->setRenderer(theme.getRenderer("Button"));
    validateButton->setPosition(100, 330);
    validateButton->setText("Create");
    validateButton->setSize(200, 50);
    validateButton->setTextSize(22);
    validateButton->connect("pressed", [=]()
    {
        if(list->getSelectedItemIndex() < 0 || nameEditBox->getText().getSize() <= 0){
            gui.add(labelError);
        }else{
            std::string time;
            switch(list->getSelectedItemIndex()) {
                case 0  :
                    time = "15";
                    break;
                case 1 :
                    time = "30";
                    break;
                case 2 :
                    time = "45";
                    break;
                case 3 :
                    time = "0";
                    break;
            }

            if(viewerRadio->isChecked())
                commandeCreate = "NEW 1 " + time + " " + nameEditBox->getText() +"\n";
            else
                commandeCreate = "NEW 0 " + time + " " + nameEditBox->getText() +"\n";

            client->getSocket_().write_some(boost::asio::buffer(commandeCreate,commandeCreate.size()));
            window.close();
        }
    });
    gui.add(validateButton);

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event); // Pass the event to the widgets
        }

        window.clear();
        gui.draw(); // Draw all widgets
        window.display();

    }
}
