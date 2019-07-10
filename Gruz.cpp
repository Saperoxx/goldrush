

#include "Gruz.h"

Gruz::Gruz():Objekt() {

    texture.loadFromFile("Gruz.png");
    this->sprite=new sf::Sprite(texture);
    sprite->setOrigin(texture.getSize().x/2.0,texture.getSize().y/2.0);
    sprite->setPosition(RandPoz());
    SetRozmiar();

}

Gruz::~Gruz() {

}

void Gruz::Rysuj(sf::RenderWindow &window) {

    window.draw(*sprite);

}

void Gruz::SetRozmiar() {
    int r=rand()%4+1;
    sprite->setScale(1.0/r,1.0/r);
}
