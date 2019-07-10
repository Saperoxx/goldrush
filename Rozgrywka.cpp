
#include "Rozgrywka.h"

Rozgrywka::Rozgrywka(sf::RenderWindow &window) {
    czas=CzasGry;
    for (int i = 0; i <ile; ++i) {

            kamienie.push_back(new Gruz());

            kamienie.push_back(new Zloto());
    }
    //Hak

    texture.loadFromFile("hak2.png");
    this->hak=new sf::Sprite(texture);
    hak->setOrigin(texture.getSize().x/2.0,0.0);
    hak->setPosition(window.getSize().x/2.,window.getSize().y-500);
    poz=hak->getPosition();
    //Lina

    texture1.loadFromFile("Rope.png");
    this->rope=new sf::Sprite(texture1);
    rope->setOrigin(texture1.getSize().x/2.0,0.0);
    rope->setPosition(window.getSize().x/2.-3,window.getSize().y-500);
    //Skrzynia

    texture2.loadFromFile("chest.png");
    this->chest=new sf::Sprite(texture2);
    chest->setOrigin(texture2.getSize().x/2.0,texture2.getSize().y/2.0);
    chest->setPosition(window.getSize().x/2.+125,window.getSize().y-550);
    //Bar

    texture3.loadFromFile("Bar.png");
    this->bar=new sf::Sprite(texture3);
    bar->setOrigin(texture3.getSize().x/2.0,texture3.getSize().y/2.0);
    bar->setPosition(window.getSize().x/2.0,100);

    texture4.loadFromFile("koniec.png");
    this->koniec=new sf::Sprite(texture4);
    koniec->setOrigin(texture4.getSize().x/2.0,texture4.getSize().y/2.0);
    koniec->setPosition(window.getSize().x/2.0,window.getSize().y/2.0);
    //Tekst

    font.loadFromFile("Bevan.ttf");
    text.setFont(font);

    text.setCharacterSize(30);
    text.setOrigin((text.getGlobalBounds().width/2.0),(text.getGlobalBounds().height/2.0));
    text.setPosition(window.getSize().x/2.+110,window.getSize().y-545);
    Pkt=std::to_string(punkty);
    text.setString(Pkt);

    text1.setFont(font);
    text1.setCharacterSize(30);
    text1.setOrigin((text1.getGlobalBounds().width/2.0),(text1.getGlobalBounds().height/2.0));
    text1.setPosition(window.getSize().x/2.0-30,65);

    text2.setFont(font);
    text2.setCharacterSize(30);
    text2.setOrigin((text1.getGlobalBounds().width/2.0),(text1.getGlobalBounds().height/2.0));
    text2.setPosition(window.getSize().x/2.0-30,90);
}

Rozgrywka::~Rozgrywka() {

    delete this->hak;
    delete this->rope;
    delete this->chest;
    delete this->bar;
    delete this->koniec;
}

void Rozgrywka::Obrot(float &delta) {
    if(!isSpace()&&!isColStone()) {
        dt += delta;
        //std::cout<<dtHak <<std::endl;
        if (dt >= czasObrotu) {
            dt = 0.0;
            //std::cout<<dtHak <<std::endl;
            if (!kierunek) {
                kat += 3;
                if (kat == 90) {
                    kierunek = true;
                }
            }
            if (kierunek) {
                kat -= 3;
                if (hak->getRotation() ==270) {
                    kierunek = false;
                }
            }
            hak->setRotation(kat);
        }
    }

}
void Rozgrywka::RzutDwa(float &delta) {

    if(isSpace()) {
        dt2 += delta;
        dt3 += delta;
        if (dt2 >= 0.05) {
            dt2=0.0;
            float x=0.0,y=0.0;
            //Lina
                setLina(true);
                rope->setRotation(hak->getRotation());
                rope->setScale(0.5, ropeY);
                ropeY +=Vskali;
            //Hak
            //std::cout<<hak->getRotation() <<std::endl;
            if(kat>=0)
            {
                y=V*cos((hak->getRotation()*PI/180));
                x=V*sin((hak->getRotation()*PI/180))*(-1);
            }
            if(kat<0)
            {
                y=V*cos((hak->getRotation()*PI/180));
                x=V*sin((hak->getRotation()*PI/180))*(-1);
            }
            hak->setOrigin(texture.getSize().x/2.0,texture.getSize().y/2.0);
            hak->move(x,y);
            for (int i = 0; i <kamienie.size() ; ++i) {
                if(kamienie[i]->Kolizja(hak))
                {
                    zahaczenie.openFromFile("zahaczenie.ogg");
                    zahaczenie.play();
                    std::cout<<"KOLIZJA"<<i <<std::endl;
                    setSpace(false);
                    setColStone(true);
                    setI(i);
                }
            }
            hak->setOrigin(texture.getSize().x/2.0,0.0);
        }
    }
    if(isColStone())
    {
        dt2 += delta;
        if (dt2 >= 0.05) {
            dt2 = 0.0;
            float x = 0.0, y = 0.0;
            //Lina
            rope->setScale(0.5, ropeY);
            ropeY -= Vskali;
            //Hak
            //std::cout<<hak->getRotation() <<std::endl;
            if (kat >= 0) {
                y = V * cos((hak->getRotation() * PI / 180));
                x = V * sin((hak->getRotation() * PI / 180)) * (-1);
            }
            if (kat < 0) {
                y = V * cos((hak->getRotation() * PI / 180));
                x = V * sin((hak->getRotation() * PI / 180)) * (-1);
            }
            hak->setOrigin(texture.getSize().x / 2.0, texture.getSize().y / 2.0);
            hak->move(-x, -y);
            if (isColStone()) {
            kamienie[getI()]->Ruch(hak->getRotation(), V);
            if (hak->getPosition().x == poz.x) {
                pkt.openFromFile("punkty.ogg");
                pkt.play();
                setColStone(false);
                setLina(false);
                //Punkty
                //std::cout<<kamienie[getI()]->getWartosc()<<std::endl;
                punkty += kamienie[getI()]->getWartosc();
                Pkt = std::to_string(punkty);
                text.setString(Pkt);

                kamienie.erase(kamienie.begin() + getI());
            }
        }
            hak->setOrigin(texture.getSize().x/2.0,0.0);
            std::cout <<punkty<< std::endl;
        }
    }
    if(isRamka())
    {
        setKoniecGry(true);
    }
}
void Rozgrywka::Czas(float &delta) {
    std::string one="Czas";
    czas-=delta;
    std::string two=std::to_string(czas);
    for (int i = 0; i < two.size()-2; ++i) {
        two.pop_back();
    }
    text1.setString(one);
    text2.setString(two);
    if(czas<=0)
    {
        setKoniecGry(true);
    }

}
void Rozgrywka::ColEkran(sf::RenderWindow &window) {

    if(hak->getPosition().x<=0)
    {
        if(!isRamka())
        {
            setRamka(true);
        }
    }
    if(hak->getPosition().x>=window.getSize().x)
    {
        if(!isRamka())
        {
            setRamka(true);
        }
    }
    if(hak->getPosition().y>=window.getSize().y)
    {
        if(!isRamka())
        {
            setRamka(true);
        }
    }
}
void Rozgrywka::Utworz(sf::RenderWindow &window,float &delta) {

    if(!isKoniecGry()) {
    for (int i = 0; i <kamienie.size() ; ++i) {
        kamienie[i]->Rysuj(window);
    }
    Obrot(delta);
    RzutDwa(delta);
    window.draw(*hak);
    if(isLina())
    {
        window.draw(*rope);
    }
    ColEkran(window);
    //Napisy
        Czas(delta);
        window.draw(*chest);
        window.draw(*bar);
        window.draw(text);
        window.draw(text1);
        window.draw(text2);
    }
    if(isKoniecGry())
    {
        text.setPosition(window.getSize().x/2.0-50,window.getSize().y/2.0);
        text.setCharacterSize(70);
        window.draw(*koniec);
        window.draw(text);
    }
}


bool Rozgrywka::isSpace() const {
    return space;
}

void Rozgrywka::setSpace(bool space) {
    Rozgrywka::space = space;
}

bool Rozgrywka::isColStone() const {
    return ColStone;
}

void Rozgrywka::setColStone(bool ColStone) {
    Rozgrywka::ColStone = ColStone;
}

int Rozgrywka::getI() const {
    return I;
}

void Rozgrywka::setI(int I) {
    Rozgrywka::I = I;
}
bool Rozgrywka::isLina() const {
    return lina;
}

void Rozgrywka::setLina(bool lina) {
    Rozgrywka::lina = lina;
}


bool Rozgrywka::isKoniecGry() const {
    return KoniecGry;
}

void Rozgrywka::setKoniecGry(bool KoniecGry) {
    Rozgrywka::KoniecGry = KoniecGry;
}

bool Rozgrywka::isRamka() const {
    return ramka;
}

void Rozgrywka::setRamka(bool ramka) {
    Rozgrywka::ramka = ramka;
}







