//
// Created by adrien on 11/12/18.
//

#ifndef SPACEBATTLE_CONNEXIONPAGE_H
#define SPACEBATTLE_CONNEXIONPAGE_H

#include <SFML/Graphics.hpp>
#include <string>

class ConnexionPage
        {
private:

    bool usernameSelected = false;
    bool ipSelected = false;
    bool portSelected = false;

    sf::Font font;
    sf::Event event;
    sf::Texture texture;

    sf::Text usernameTitle;
    sf::Text ipTitle;
    sf::Text portTitle;
    sf::Text validate;

    sf::Text usernameText;
    sf::String usernameInput;
    sf::Text ipText;
    sf::String ipInput;
    sf::Text portText;
    sf::String portInput;

public:
    ConnexionPage();
    ~ConnexionPage();
    void disp();

    void fontSettings();

    void textsUpdate(sf::Event event, sf::String *input, sf::Text *text);
};


#endif //SPACEBATTLE_CONNEXIONPAGE_H
