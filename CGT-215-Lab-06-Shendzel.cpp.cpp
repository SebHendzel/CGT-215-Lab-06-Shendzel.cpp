

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
    } //I assume these just close the code if the images aren't there

    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();
    Image foregroundImage;
    foregroundImage = foregroundTex.copyToImage(); //I assume these convert the images to pixellated textures

    Vector2u sz = backgroundImage.getSize();
    Color corner = foregroundImage.getPixel(1, 1); //This grabs the corner and sets it as a color, being able to be used for color matching later.
    for (int y = 0; y < sz.y; y++) {
        for (int x = 0; x < sz.x; x++) {
            Color check = foregroundImage.getPixel(x, y);
            if (check.g == corner.g  && check.r == corner.r && check.b == corner.b) { //using the fixed point from earlier, knowing that's the green screen color, I matched and set the pixels alpha to zero

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
    window.draw(sprite2); //Putting the backgorund uses the same method as the foreground I put it first so it's behind, but I wonder if there is a way to make it less bulky code rather than copying what I did to put hte foreground in.
    window.draw(sprite1);
    window.display();
    while (true);
}


