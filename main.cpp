#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdio.h>

sf::Sprite rotation(sf::Sprite kaannettava)
{

    using namespace sf;
    Time millisekunti = milliseconds(3.f);

    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        //kaannettava.setRotation(kaannettava.getRotation()+1.f);
        kaannettava.rotate(1.f);
        sleep(millisekunti);
    }

    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
       //kaannettava.setRotation(kaannettava.getRotation()-1.f);
       kaannettava.rotate(-1.f);
       sleep(millisekunti);
    }
    return kaannettava;
}


int main()
{

    using namespace sf;

    //MUUTTUJIA
    Vector2f sijainti;
    float rotaatio;

    //Luodaan ikkuna
    RenderWindow window(VideoMode(800, 600), "Pelitesti");


    Time millisekunti = milliseconds(3.f);

    //Tausta eli kentta, jolla liikutaan
    Texture tausta;
    tausta.loadFromFile("img/Pelitausta_tyhja.jpg");
    Sprite piirratausta;
    piirratausta.setTexture(tausta);

    //Ruskeat esteet laudalla
    Texture esteet;
    esteet.loadFromFile("img/Esteet.png");
    Sprite piirraesteet;
    piirraesteet.setTexture(esteet);

    //vihrea objekti, jota voi liikuttaa kentalla
    Sprite vihree;
    vihree.setTexture(tausta);
    vihree.setColor(Color(0, 255, 0));
    vihree.setScale(0.035, 0.05); //28x30, alkup. 800x600
    vihree.setOrigin(400,300);//eli onnistui



    while (window.isOpen())
    {
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        //vihree=rotation(vihree);
        //rotaatio=vihree.getRotation();
        if(Keyboard::isKeyPressed(Keyboard::Right)){vihree.move(1,1);}
        if(Keyboard::isKeyPressed(Keyboard::Left)){vihree.move(-1,0);}
        if(Keyboard::isKeyPressed(Keyboard::Up)){vihree.move(0,-1);}
        if(Keyboard::isKeyPressed(Keyboard::Down)){vihree.move(0,1);}
        if(Keyboard::isKeyPressed(Keyboard::Space)){vihree.setPosition(400,300);}
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(piirratausta);
        window.draw(piirraesteet);
        window.draw(vihree);
        window.display();
        sleep(millisekunti);
    }

    return 0;
}
