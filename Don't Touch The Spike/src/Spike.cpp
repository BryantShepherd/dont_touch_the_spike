#include "Spike.h"

using namespace std;



Spike::Spike()
{
    srand((int) time(0));
    quality = 0; //dua vao so diem ma hien so gai tuong ung
    x = new float[quality];
    y = new float[quality];
    for( int i = 0; i<quality; i++) //neu trung thi sao
    {
        x[i] = SCREEN_WIDTH-30;
        y[i] = (0 + rand() % (60 + 1 - 0))*10;
    }
    spike_texture = NULL;
}

Spike::~Spike()
{
    delete[] x;
    delete[] y;
    free();
}

void Spike::loadFromFile(string path, SDL_Renderer* renderer)
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
        SDL_SetColorKey( loaded_surface, SDL_TRUE, SDL_MapRGB( loaded_surface->format, 0xFF, 0xFF, 0xFF ) );
        new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
        if( new_texture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            width = loaded_surface->w;
            height = loaded_surface->h;
        }

        SDL_FreeSurface( loaded_surface );
    }

    spike_texture = new_texture;

}

void Spike::free()
{
    if(spike_texture != NULL)
    {
        SDL_DestroyTexture(spike_texture);
        spike_texture = NULL;
    }
}

void Spike::setSpikesNumber(int &score)
{
    if (score <= 1) quality = 2;
    else if(score <= 4) quality = 3;
    else if (score <= 10) quality = 4;
    else if (score <= 15) quality = 5;
    else if (score <= 25) quality = 6;
    else if(score <= 40) quality = 7;
    else quality = 8;
}
void Spike::render( int x, int y, int w, int h, SDL_Renderer* renderer, int status)
{
    SDL_Rect renderQuad = { x, y, w, h };
    if(status == 0)
    {
        SDL_RenderCopyEx(renderer, spike_texture, NULL, &renderQuad, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
    else
    {
        SDL_RenderCopy( renderer, spike_texture, NULL, &renderQuad );
    }
}

void Spike::update(int status, bool hit, int &score)
{
    srand((int) time(0));
    if(hit == true)
    {
        setSpikesNumber(score);
        if(status == 0)
        {
            for(int i = 0; i < quality; i++)
            {
                x[i] = SCREEN_WIDTH-width;
                y[i] = (0 + rand() % (60 + 1 - 0))*height;
            }
        }
        else
        {
            for(int i = 0; i < quality; i++)
            {
                x[i] = 0;
                y[i] = (0 + rand() % (60 + 1 - 0))*height;
            }
        }
    }
}

float Spike::getX(int i)
{
    return x[i];
}

float Spike::getY(int i)
{
    return y[i];
}

int Spike::getWidth()
{
    return width;
}

int Spike::getHeight()
{
    return height;
}

int Spike::getQuality()
{
    return quality;
}
