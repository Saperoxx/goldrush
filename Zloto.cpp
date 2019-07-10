
#include "Zloto.h"

Zloto::Zloto():Objekt() {

    texture.loadFromFile("Zloto.png");
    this->sprite=new sf::Sprite(texture);
    sprite->setOrigin(texture.getSize().x/2.0,texture.getSize().y/2.0);
    sprite->setPosition(RandPoz());
    SetWartosc();
    SetRozmiar();

}

Zloto::~Zloto() {
    delete this->sprite;

}

void Zloto::Rysuj(sf::RenderWindow &window) {

    if (pokaz) {
    window.draw(*sprite);
    }
}

void Zloto::SetWartosc() {
    Objekt::SetWartosc();
    r=rand()%4+1;
    if(r==1)wartosc=100;
    if (r==2)wartosc=75;
    if (r==3)wartosc=75;
    if (r==4)wartosc=25;
}

void Zloto::SetRozmiar() {
    sprite->setScale(1.0/r,1.0/r);
}
