#pragma once


#include "Objekt.h"

class Zloto:public Objekt {
public:
    Zloto();
    ~Zloto();

    void Rysuj(sf::RenderWindow &window);
    void SetWartosc();
    void SetRozmiar();

private:
    int r;
};



