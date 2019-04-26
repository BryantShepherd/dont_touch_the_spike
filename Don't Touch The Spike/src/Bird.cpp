// #include "Bird.h"
 #include "MainControl.h"

using namespace std;

Bird::Bird()
{
    x = 0;
    y = SCREEN_HEIGHT/2.0;
    dx = 0;
    dy = 0;
    ddx = 0;
    ddy = 0;
    width = 0;
    height = 0;
    bird_texture = NULL;
}
Bird::~Bird()
{
    free();
}
void Bird::loadFromFile(string path, SDL_Renderer* renderer)
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

        new_texture = SDL_CreateTextureFromSurface( renderer, loaded_surface );
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

    bird_texture = new_texture;

}
void Bird::free()
{
    if( bird_texture != NULL )
    {
        SDL_DestroyTexture( bird_texture );
        bird_texture = NULL;
        width = 0;
        height = 0;
    }
}

void Bird::render( int x, int y, int w, int h, SDL_Renderer* renderer, int status)
{
    SDL_Rect renderQuad = { x, y, w, h };
    if( status == 0)
    {
        SDL_RenderCopy( renderer, bird_texture, NULL, &renderQuad );
    }
    else
    {
        SDL_RenderCopyEx( renderer, bird_texture, NULL, &renderQuad, 0, NULL, SDL_FLIP_HORIZONTAL );
    }
}
void Bird::update(int &status, bool &hit, int &score)
{
    hit = false; //dx, day la gi, de lam gi?
    if(status == GOING_RIGHT)
    {
        dx += 0.05;
        dy += 0.3;
    }
    else //status == GOING_LEFT
    {
        dx -= 0.05;
        dy += 0.3;
    }
    x = x + dx;
    y = y + dy;
    if(x > SCREEN_WIDTH-34)
    {
        x = SCREEN_WIDTH-34;
        dx = -1.75;
        dy = -4.5;
        status = 1;
        hit = true;
        score++;
    }
    if(x < 0)
    {
        x = 0;
        dx = 1.75;
        dy = -4.5;
        status = 0;
        hit = true;
        score++;
    }
    if(y > SCREEN_HEIGHT-24)
    {
        y = SCREEN_HEIGHT-24;
    }
    if(y < 0)
    {
        y = 0;
    }

}
void Bird::handleEvent(SDL_Event &event, int status)
{
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_KEYDOWN:
    {
        if(event.key.keysym.sym == SDLK_SPACE)
        {
            if(status == 0)
            {
                dx = 2;
                dy = -7.5;
            }
            else
            {
                dx = -2;
                dy = -7.5 ;
            }
        }
        break;
    }
    }
}

int Bird::getWidth()
{
    return width;
}

int Bird::getHeight()
{
    return height;
}
float Bird::getX()
{
    return x;
}
float Bird::getY()
{
    return y;
}
