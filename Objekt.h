#pragma once


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>

//Biblioteki SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//stale
#define PI 3.14159265
#define CzasGry 60

class Objekt {
public:
    Objekt();
    ~Objekt();

    virtual void Rysuj(sf::RenderWindow &window)=0;
    virtual void SetWartosc();
    virtual void SetRozmiar()=0;


     void Pokaz();
     void Ukryj();
     sf::Sprite *getSprite() const;

     sf::Vector2f RandPoz();

     bool Kolizja(sf::Sprite *one);

     void Ruch(float kat,float z);

    int getWartosc() const;

protected:
    bool pokaz;
    sf::Vector2f pozycja;
    sf::Texture texture;
    sf::Sprite *sprite;

    int wartosc=0;
};

