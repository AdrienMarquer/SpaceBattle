//
// Created by adrien on 11/12/18.
//

#include <iostream>
#include <boost/asio/buffer.hpp>
#include <Client.h>
#include "ConnexionPage.h"
#include "MainMenu.h"


ConnexionPage::ConnexionPage()
{
}

ConnexionPage::~ConnexionPage()
{

}

void	ConnexionPage::disp()
{
    sf::RenderWindow	window(sf::VideoMode(500, 500), "Space Battle");

    sf::RectangleShape rectangleUsername(sf::Vector2f(250, 40));
    sf::RectangleShape rectangleIp(sf::Vector2f(250, 40));
    sf::RectangleShape rectanglePort(sf::Vector2f(250, 40));

    if(!font.loadFromFile("../res/fonts/coolvetica.ttf")){
        std::cout << "Error loading font" << std::endl;
    }
    if(!texture.loadFromFile("../res/images/background_connexion.jpg")){
        std::cout << "Error loading background" << std::endl;
    }
    sf::Sprite background(texture);

    fontSettings();

    usernameText.setPosition(160,100);
    rectangleUsername.setPosition(160,100);
    ipText.setPosition(160,200);
    rectangleIp.setPosition(160,200);
    portText.setPosition(160,300);
    rectanglePort.setPosition(160,300);
    usernameTitle.setPosition(60,105);
    ipTitle.setPosition(60,205);
    portTitle.setPosition(60,305);
    validate.setPosition(200,400);

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            switch (event.type){
                case sf::Event::Closed :

                    window.close();

                case sf::Event::MouseButtonReleased:
                    if (event.key.code==sf::Mouse::Left  && sf::Mouse::getPosition(window).x >= rectangleUsername.getPosition().x && sf::Mouse::getPosition(window).x <= rectangleUsername.getPosition().x + rectangleUsername.getSize().x
                        && sf::Mouse::getPosition(window).y >= rectangleUsername.getPosition().y && sf::Mouse::getPosition(window).y <= rectangleUsername.getPosition().y + rectangleUsername.getSize().y) {
                        usernameSelected = true;
                        ipSelected = false;
                        portSelected = false;
                    }else if(event.key.code==sf::Mouse::Left  && sf::Mouse::getPosition(window).x >= rectangleIp.getPosition().x && sf::Mouse::getPosition(window).x <= rectangleIp.getPosition().x + rectangleIp.getSize().x
                             && sf::Mouse::getPosition(window).y >= rectangleIp.getPosition().y && sf::Mouse::getPosition(window).y <= rectangleIp.getPosition().y + rectangleIp.getSize().y) {
                        ipSelected = true;
                        usernameSelected = false;
                        portSelected = false;
                    }else if(event.key.code==sf::Mouse::Left  && sf::Mouse::getPosition(window).x >= rectanglePort.getPosition().x && sf::Mouse::getPosition(window).x <= rectanglePort.getPosition().x + rectanglePort.getSize().x
                             && sf::Mouse::getPosition(window).y >= rectanglePort.getPosition().y && sf::Mouse::getPosition(window).y <= rectanglePort.getPosition().y + rectanglePort.getSize().y){
                        portSelected = true;
                        usernameSelected = false;
                        ipSelected = false;
                    }else if(event.key.code==sf::Mouse::Left  && sf::Mouse::getPosition(window).x >= validate.getPosition().x - 20 && sf::Mouse::getPosition(window).x <= validate.getPosition().x + 100
                             && sf::Mouse::getPosition(window).y >= validate.getPosition().y && sf::Mouse::getPosition(window).y - 20<= validate.getPosition().y + 40){
                        try {
                            boost::asio::io_service io_service;
                            std::string ipString(ipInput);
                            std::string portString(portInput);
                            std::string commandePseudo("PSEUDO " + usernameInput + "\n");
                            Client *client = new Client(io_service, ipString.c_str(), portString.c_str());
                            client->getSocket_().write_some(boost::asio::buffer(commandePseudo,commandePseudo.size()));

                            MainMenu main(client);
                            window.close();
                            main.disp();
                            //MENU PRINCIPAL
                        }catch (std::exception &e){
                            std::cerr << "Error connecting " << e.what() << std::endl;
                            window.close();
                        }
                        std::cerr << "Working" << std::endl;

                    }
                    else {
                        usernameSelected = false;
                        ipSelected = false;
                        portSelected = false;
                    }
                case sf::Event::TextEntered:
                    if ( usernameSelected && event.text.unicode < 0x80 &&  event.text.unicode != 0 )
                    {
                        textsUpdate(event,&usernameInput,&usernameText);
                    }
                    else if ( ipSelected && event.text.unicode < 0x80 &&  event.text.unicode != 0 )
                    {
                        textsUpdate(event,&ipInput,&ipText);
                    }
                    else if ( portSelected && event.text.unicode < 0x80 &&  event.text.unicode != 0 )
                    {
                        textsUpdate(event,&portInput,&portText);
                    }
            }

        }

        window.clear();
        window.draw(background);
        window.draw(rectangleUsername);
        window.draw(usernameText);
        window.draw(rectangleIp);
        window.draw(ipText);
        window.draw(rectanglePort);
        window.draw(portText);
        window.draw(usernameTitle);
        window.draw(ipTitle);
        window.draw(portTitle);
        window.draw(validate);
        window.display();
    }

}

void ConnexionPage::fontSettings() {
    usernameText.setFont(font);
    ipText.setFont(font);
    portText.setFont(font);
    usernameText.setFillColor(sf::Color::Black);
    ipText.setFillColor(sf::Color::Black);
    portText.setFillColor(sf::Color::Black);

    usernameTitle.setFont(font);
    ipTitle.setFont(font);
    portTitle.setFont(font);
    validate.setFont(font);
    usernameTitle.setString("Username");
    ipTitle.setString("IP");
    portTitle.setString("Port");
    validate.setString("Valider");
    usernameTitle.setCharacterSize(20);
    ipTitle.setCharacterSize(20);
    portTitle.setCharacterSize(20);
}

void ConnexionPage::textsUpdate(sf::Event event, sf::String *input, sf::Text *text) {
    if(event.text.unicode == 8){
        *input = input->substring(0,input->getSize()-1);
        text->setString(*input);
    }else if(input->getSize() <= 12){
        *input += event.text.unicode;
        text->setString(*input);
    }
}
