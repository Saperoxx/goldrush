
#include "Objekt.h"

Objekt::Objekt()
{
    pokaz= true;
    SetWartosc();
}

Objekt::~Objekt() {
    delete this->sprite;
}

sf::Sprite *Objekt::getSprite() const {
    return sprite;
}

void Objekt::Pokaz() {
    pokaz= true;

}

void Objekt::Ukryj() {
    pokaz= false;
}

sf::Vector2f Objekt::RandPoz(){

    sf::Vector2f poz;
    poz.x=rand()%1260;

    poz.y = rand() % 768 + 280;

    return poz;
}

void Objekt::SetWartosc() {

    wartosc=-5;
}

bool Objekt::Kolizja(sf::Sprite *one) {
    sf::Vector2f poz1=one->getPosition();
    sf::Vector2f poz2=sprite->getPosition();

    //kolizja osi x
    bool kolizjaX = poz1.x + one->getTexture()->getSize().x >= poz2.x &&
                      poz2.x + sprite->getTexture()->getSize().x >= poz1.x;
    //kolizja osi y
    bool kolizjaY = poz1.y + one->getTexture()->getSize().y >= poz2.y &&
                      poz2.y + sprite->getTexture()->getSize().y >= poz1.y;

    //obydwie true mamy kolizje obiketow (kwadratow)
    return kolizjaX && kolizjaY;
}

void Objekt::Ruch(float kat,float z) {
    float x=0.0;
    float y=0.0;
    if(kat>=0)
    {
        y=z*cos((kat*PI/180))*(-1);
        x=z*sin((kat*PI/180));
    }
    if(kat<0)
    {
        y=z*cos((kat*PI/180))*(-1);
        x=z*sin((kat*PI/180));
    }
    sprite->move(x,y);
}

int Objekt::getWartosc() const {
    return wartosc;
}


