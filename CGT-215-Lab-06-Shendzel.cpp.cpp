

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
    string background = "images1/backgrounds/winter.png";

    string foreground = "images1/characters/yoda.png";

    Texture backgroundTex;
    if (!backgroundTex.loadFromFile(background)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }
    Texture foregroundTex;
    if (!foregroundTex.loadFromFile(foreground)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }

    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();
    Image foregroundImage;
    foregroundImage = foregroundTex.copyToImage();

    Vector2u sz = backgroundImage.getSize();
    for (int y = 0; y < sz.y; y++) {
        for (int x = 0; x < sz.x; x++) {
            Color check = foregroundImage.getPixel(x, y);
            if (check.g > 180  && check.r < 80 && check.b < 80) {

                check.a = 0;
                foregroundImage.setPixel(x, y, check);
            }

        }
    }

    RenderWindow window(VideoMode(1024, 768), "Here's the output");
    Sprite sprite1;
    Texture tex1;
    Sprite sprite2;
    Texture tex2;
    tex2.loadFromImage(backgroundImage);
    tex1.loadFromImage(foregroundImage);
    sprite2.setTexture(tex2);
    sprite1.setTexture(tex1);
    window.clear();
    window.draw(sprite2);
    window.draw(sprite1);
    window.display();
    while (true);
}


