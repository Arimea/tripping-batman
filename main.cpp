#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdio.h>

int main()
{
    using namespace sf;
    //printf(2)
    //Luodaan ikkuna
    RenderWindow window(VideoMode(800, 600), "Pelitesti");



    Time millisekunti = milliseconds(3.f);

    //Tausta eli kentta, jolla liikutaan
    Texture tausta;
    tausta.loadFromFile("img/Pelitausta.jpg");
    Sprite piirratausta;
    piirratausta.setTexture(tausta);

    //vihrea objekti, jota voi liikuttaa kentalla
    Sprite vihree;
    vihree.setTexture(tausta);
    vihree.setColor(Color(0, 255, 0));
    vihree.setScale(0.035, 0.05);



    while (window.isOpen())
    {
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Right)){vihree.move(1,0);}
        if(Keyboard::isKeyPressed(Keyboard::Left)){vihree.move(-1,0);}
        if(Keyboard::isKeyPressed(Keyboard::Up)){vihree.move(0,-1);}
        if(Keyboard::isKeyPressed(Keyboard::Down)){vihree.move(0,1);}

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(piirratausta);
        window.draw(vihree);
        window.display();
        sleep(millisekunti);
    }

    return 0;
}
