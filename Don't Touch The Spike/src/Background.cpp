#include "Background.h"

using namespace std;

Background::Background()
{
    background_texture = NULL;
}

Background::~Background()
{
    free();
}

void Background::loadFromFile(string path, SDL_Renderer* renderer)
{
    free();

    SDL_Texture* new_texture = NULL;

    SDL_Surface* loaded_surface = IMG_Load( path.c_str() );
    if( loaded_surface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
        if( new_texture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        SDL_FreeSurface( loaded_surface );
    }

    background_texture = new_texture;

}

void Background::free()
{
    if(background_texture != NULL)
    {
        SDL_DestroyTexture(background_texture);
        background_texture = NULL;
    }
}

void Background::render( int x, int y, int w, int h, SDL_Renderer* renderer)
{

    SDL_Rect renderQuad = { x, y, w, h };
    SDL_RenderCopy( renderer, background_texture, NULL, &renderQuad );
}
