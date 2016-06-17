#ifndef SDL_HELLO_WORLD_TEXTURE_H
#define SDL_HELLO_WORLD_TEXTURE_H


#include <string>
#include <SDL_render.h>

class Texture {
public:
    Texture(SDL_Texture* texture, int width, int height);
    ~Texture();

    int getWidth();
    int getHeight();

    void draw(SDL_Renderer *renderer, SDL_Rect clip);
    void draw(SDL_Renderer *renderer, SDL_Rect clip, SDL_Rect size, bool preserveAspect = false);

private:
    //The actual hardware texture
    SDL_Texture *mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif //SDL_HELLO_WORLD_TEXTURE_H
