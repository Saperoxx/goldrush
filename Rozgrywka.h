#pragma once

#include "Gruz.h"
#include "Zloto.h"

class Rozgrywka {
public:
    Rozgrywka(sf::RenderWindow &window);
    ~Rozgrywka();

    void Utworz(sf::RenderWindow &window,float &delta);

    //Funckje haka
    void Obrot(float &delta);

    void RzutDwa(float &delta);




    bool isSpace() const;

    void setSpace(bool space);


    bool isKoniecGry() const;

    void setKoniecGry(bool KoniecGry);

private:
    bool isColStone() const;

    void setColStone(bool ColStone);

    int getI() const;

    void setI(int I);
    //funcje dla liny
    bool isLina() const;

    void setLina(bool lina);

    void ColEkran(sf::RenderWindow &window);

    void Czas(float &delta);

public:
    bool isRamka() const;

    void setRamka(bool ramka);


private:
    std::vector<Objekt*> kamienie;


    const int ile=15;// gruzu i zlota jest ile*2

    //Hak
    sf::Texture texture;
    sf::Sprite *hak;
    sf::Vector2f poz;

    float dt=0.0;
    float kat=0;
    float czasObrotu=0.05;
    bool kierunek= false;

    float V=3.0;//predkosc wciagania haku
    float dt2=0.0;

    bool space= false;
    //kolizja z skalamai zmienne
    bool ColStone=false;
    int I;//ktora skala

    //Lina
    sf::Texture texture1;
    sf::Sprite *rope;

    bool lina= false;
    float dt3=0.0;
    float ropeY=0.01;
    const float Vskali=0.01225;

    //Punkty
    sf::Texture texture2;
    sf::Sprite *chest;
    sf::Font font;
    sf::Text text;
    int punkty=0;
    std::string Pkt;
    //Czas
    sf::Texture texture3;
    sf::Sprite *bar;
    sf::Text text1;
    sf::Text text2;
    float czas=0.0;
    //Ekran
    bool ramka= false;
    float dt4=0.0;

    //Koniec Gry
    bool KoniecGry= false;
    sf::Texture texture4;
    sf::Sprite *koniec;

    //Dzwieki
    sf::Music pkt;
    sf::Music zahaczenie;
};


