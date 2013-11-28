#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdio.h>

sf::Sprite rotation(sf::Sprite kaannettava)
{

    using namespace sf;
    Time millisekunti = milliseconds(3.f);
    Time skaalasekunti = milliseconds(20.f);

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
    //float rotaatio;
    int palloSkaala=0;

    //Temp-olento
    Sprite temp;
    Sprite tempvarjo;

    //Luodaan ikkuna
    RenderWindow window(VideoMode(800, 600), "Pelitesti");

    Time skaalasekunti = milliseconds(100.f);
    Time millisekunti = milliseconds(3.f);

    //Tausta eli kentta, jolla liikutaan
    Texture tausta;
    tausta.loadFromFile("img/Pelitaustatyhjahitech.jpg");
    Sprite piirratausta;
    piirratausta.setTexture(tausta);

    //Ruskeat esteet laudalla
    Texture esteet;
    esteet.loadFromFile("img/esteethitech.png");
    Sprite piirraesteet;
    piirraesteet.setTexture(esteet);

    //Pelaajaobjekti, jota voi liikuttaa kentalla
    Texture pallo;
    pallo.loadFromFile("img/pelaajahitech.png");
    Sprite piirrapallo;
    piirrapallo.setTexture(pallo);
    //piirrapallo.setColor(Color(0, 255, 0));
    piirrapallo.setScale(0.6, 0.6); //28x30, alkup. 800x600
    piirrapallo.setOrigin(50,50);//eli onnistui

    //Pelaajaobjektin "stealth"-sprite
    Texture varjopallo;
    varjopallo.loadFromFile("img/pelaajahitechstealth.png");
    Sprite piirravarjopallo;
    piirravarjopallo.setTexture(varjopallo);
    piirravarjopallo.setScale(0.6,0.6);
    piirravarjopallo.setOrigin(50,50);




    while (window.isOpen())
    {
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

    //LIIKE
        //vihree=rotation(vihree);
        //rotaatio=vihree.getRotation();
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {piirrapallo.move(0.5,0);piirrapallo.setRotation(90);}
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {piirrapallo.move(-0.5,0);piirrapallo.setRotation(270);}
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {piirrapallo.move(0,-0.5);piirrapallo.setRotation(0);}
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {piirrapallo.move(0,0.5);piirrapallo.setRotation(180);}
        if(Keyboard::isKeyPressed(Keyboard::Space)) //Pallon skaalaus valilyonnista
            {
                if(palloSkaala==0)
                {
                    piirrapallo.setTexture(varjopallo);
                    palloSkaala++;
                    sleep(skaalasekunti);

                }
                else
                {
                    piirrapallo.setTexture(pallo);
                    palloSkaala--;
                    sleep(skaalasekunti);
                }

                //{piirrapallo.setScale(0.8,0.8);
                //palloSkaala++;
                //sleep(skaalasekunti);}
                //else
                //{piirrapallo.setScale(0.6,0.6);
                //palloSkaala--;
                //sleep(skaalasekunti);}
            }

        if((Keyboard::isKeyPressed(Keyboard::Right)) && (Keyboard::isKeyPressed(Keyboard::Up)))
            {piirrapallo.move(-0.15,0.15);
            piirrapallo.setRotation(45);}
        if((Keyboard::isKeyPressed(Keyboard::Right)) && (Keyboard::isKeyPressed(Keyboard::Down)))
            {piirrapallo.move(-0.15,-0.15);
            piirrapallo.setRotation(135);}
        if((Keyboard::isKeyPressed(Keyboard::Left)) && (Keyboard::isKeyPressed(Keyboard::Up)))
            {piirrapallo.move(0.15,0.15);
            piirrapallo.setRotation(315);}
        if((Keyboard::isKeyPressed(Keyboard::Left)) && (Keyboard::isKeyPressed(Keyboard::Down)))
            {piirrapallo.move(0.15,-0.15);
            piirrapallo.setRotation(225);}


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //render
        window.clear();
        window.draw(piirratausta);
        window.draw(piirraesteet);
        window.draw(piirrapallo);
        window.display();
        sleep(millisekunti);
    }
    return 0;
}

