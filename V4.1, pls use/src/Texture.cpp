#include "Texture.h"

using namespace std;

void Texture::logSDLError(ostream& os, const string &msg, bool fatal)
{
    os << msg << " Error: " << IMG_GetError() << endl;
    if (fatal)
    {
        IMG_Quit();
        SDL_Quit();
        exit(1);
    }
}

void Texture::free(SDL_Texture* texture)
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}

void Texture::loadFromFile(string path, SDL_Renderer* renderer)
{
    SDL_Texture* new_texture = NULL;
    SDL_Surface* loaded_surface = IMG_Load( path.c_str() );

    if( loaded_surface == NULL )
    {
        logSDLError(cout, "IMG_load", true);
    }
    else
    {
        SDL_SetColorKey( loaded_surface, SDL_TRUE, SDL_MapRGB( loaded_surface->format, 0x00, 0xFF, 0xFF ) );
        new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
        if( new_texture == NULL )
        {
            logSDLError(cout, "SDL_CreateTextureFromSurface", true);
        }
        else
        {
            width.push_back(loaded_surface->w);
            height.push_back(loaded_surface->h);
        }

        SDL_FreeSurface(loaded_surface);
    }

     texture.push_back(new_texture);
     new_texture = NULL;
}

void Texture::render(int i, int x, int y, int width, int height, SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = {x, y, width, height};
    SDL_RenderCopyEx(renderer, texture.at(i), NULL, &renderQuad, angle, center, flip);
}

float Texture::getX(int i)
{
    return x.at(i);
}

float Texture::getY(int i)
{
    return y.at(i);
}

int Texture::getWidth(int i)
{
    return width.at(i);
}

int Texture::getHeight(int i)
{
    return height.at(i);
}

int Texture::getTextureSize()
{
    return texture.size();
}
