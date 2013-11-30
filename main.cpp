#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <cctype>

sf::Sprite rotation(sf::Sprite kaannettava)
{
    using namespace sf;
    Time millisekunti = milliseconds(3.f);
    //Time skaalasekunti = milliseconds(20.f);

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


    //Luodaan ikkuna
    RenderWindow window(VideoMode(800, 600), "Pelitesti");

    Time skaalasekunti = milliseconds(100.f);
    Time millisekunti = milliseconds(2.f);

    //Tausta eli kentta, jolla liikutaan
    Texture taustaText;
    taustaText.loadFromFile("img/Pelitaustatyhjahitech.jpg");
    Sprite tausta;
    tausta.setTexture(taustaText);

    //Ruskeat esteet laudalla
    Texture esteetText;
    esteetText.loadFromFile("img/esteethitech.png");
    Sprite esteet;
    esteet.setTexture(esteetText);

    //Pelaajaobjekti, jota voi liikuttaa kentalla
    Texture pelaajaText;
    pelaajaText.loadFromFile("img/pelaajahitech.png");
    Sprite pelaaja;
    pelaaja.setTexture(pelaajaText);
    pelaaja.setScale(0.6, 0.6); //28x30, alkup. 800x600
    pelaaja.setOrigin(50,50);//eli onnistui

    //Pelaajaobjektin "stealth"-sprite
    Texture pelaajaStealthText;
    pelaajaStealthText.loadFromFile("img/pelaajahitechstealth.png");
    Sprite pelaajaStealth;
    pelaajaStealth.setTexture(pelaajaStealthText);
    pelaajaStealth.setScale(0.6,0.6);
    pelaajaStealth.setOrigin(50,50);

    //Luodaan testaamiseen toinen pelaaja
    Texture pelaaja2Text;
    pelaaja2Text.loadFromFile("img/pallo.png");
    Sprite pelaaja2;
    pelaaja2.setTexture(pelaaja2Text);
    pelaaja2.setScale(0.6, 0.6); //28x30, alkup. 800x600
    pelaaja2.setOrigin(50,50);//eli onnistui
    pelaaja2.setPosition(400,300);




    while (window.isOpen())
    {
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        if (pelaaja.getGlobalBounds().intersects(pelaaja2.getGlobalBounds()))
        {
            pelaaja.setScale(1.0,1.0);
        }
        else
        {
            pelaaja.setScale(0.6,0.6);
        }


    //LIIKE
        //vihree=rotation(vihree);
        //rotaatio=vihree.getRotation();
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {pelaaja.move(2,0);pelaaja.setRotation(90);}
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {pelaaja.move(-2,0);pelaaja.setRotation(270);}
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {pelaaja.move(0,-2);pelaaja.setRotation(0);}
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {pelaaja.move(0,2);pelaaja.setRotation(180);}
        if(Keyboard::isKeyPressed(Keyboard::Space)) //Pallon skaalaus valilyonnista
            {
                if(palloSkaala==0)
                {
                    pelaaja.setTexture(pelaajaStealthText);
                    palloSkaala++;
                    sleep(skaalasekunti);

                }
                else
                {
                    pelaaja.setTexture(pelaajaText);
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
            {pelaaja.move(-0.3,0.3);
            pelaaja.setRotation(45);}
        if((Keyboard::isKeyPressed(Keyboard::Right)) && (Keyboard::isKeyPressed(Keyboard::Down)))
            {pelaaja.move(-0.3,-0.3);
            pelaaja.setRotation(135);}
        if((Keyboard::isKeyPressed(Keyboard::Left)) && (Keyboard::isKeyPressed(Keyboard::Up)))
            {pelaaja.move(0.3,0.3);
            pelaaja.setRotation(315);}
        if((Keyboard::isKeyPressed(Keyboard::Left)) && (Keyboard::isKeyPressed(Keyboard::Down)))
            {pelaaja.move(0.3,-0.3);
            pelaaja.setRotation(225);}


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //render
        window.clear();
        window.draw(tausta);
        window.draw(esteet);
        window.draw(pelaaja2);
        window.draw(pelaaja);
        window.display();
        sleep(millisekunti);
    }
    return 0;
}

