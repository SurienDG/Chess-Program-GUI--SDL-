// main.cpp is the main class in The Chess Program Project File
//Program created by Farzam Karimi, Surien Das-Giwojno, Claudio Gonzalez
// This class of The Chess Program Project File used to call the other classes so that the user can play one player or two player chess
//(c) Surien Das-Giwojno, Farzam, Claudio

// import libraries and classes
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <climits>
#include "PrintChess.h"
#include "moves.h"
#include "LegalMoves.h"
#include "ValidMoves.h"
#include "Conversion.h"
#include "ArtificialIintelligence.h"
#include "GameFunctions.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>




// state that namespace std is being used
using namespace std;





//Screen dimension constants
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;



class Sprite
{
public:
    //Initializes variables
    Sprite();

    //Deallocates memory
    ~Sprite();

    //Loads image at specified path
    bool loadFromFile( std::string path, int height, int width );

    //Deallocates sprite
    void free();

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );


private:
    //The actual hardware texture
    SDL_Texture* mSprite;


    //Image dimensions
    int mWidth;
    int mHeight;
};



class tiles
{
public:

    void handleEvent( SDL_Event& e );

    string boxes (void);

private:
    int x;
    int y;
    int oldx=0;
    int oldy=0;


};




class Ball
{
public:


    //Initializes the variables
    Ball();
    ~Ball();

    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );

    //Moves the dot
    void move();

    //Shows the dot on the screen
    void render();

    bool isHit(int x, int y);

private:
    //Sprite for the ball
    Sprite sprite;

    //The X and Y offsets of the dot
    int x, y;

    //The velocity of the dot
    int vx, vy;

};



Ball::Ball()
{

    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    vx = 0;
    vy = 0;

    //Load dot texture
    if( !sprite.loadFromFile( "ball.bmp",10, 12 ) )
    {
        printf( "Failed to load dot texture!\n" );
    }
}

Ball::~Ball()
{
    sprite.free();
}

void board (string PrintRow [8][8])
{
    Sprite sprite;
    int x=152;
    int y=162;
    string path="";
    for (int row=7; row>=0; row--)
    {
        for (int col=7; col>=0; col--)
        {
            if (PrintRow [row][col]==" p ")
                path="bp.jpg";
            else if (PrintRow [row][col]==" r ")
                path="br.jpg";
            else if (PrintRow [row][col]==" q ")
                path="bq.jpg";
            else if (PrintRow [row][col]==" b ")
                path="bb.jpg";
            else if (PrintRow [row][col]==" n ")
                path="bn.jpg";
            else if (PrintRow [row][col]==" k ")
                path="bk.jpg";
            else if (PrintRow [row][col]==" P ")
                path="wp.jpg";
            else if (PrintRow [row][col]==" R ")
                path="wr.jpg";
            else if (PrintRow [row][col]==" Q ")
                path="wq.jpg";
            else if (PrintRow [row][col]==" B ")
                path="wb.jpg";
            else if (PrintRow [row][col]==" N ")
                path="wn.jpg";
            else if (PrintRow [row][col]==" K ")
                path="wk.jpg";
            else
                path="";

            if (path!="")
            {

                if( !sprite.loadFromFile(path.c_str(),43 , 40) )
                {
                    printf( "Failed to load blue tile texture!\n" );
                }
                sprite.render(x,y);
            }
            x+=56;

        }
        x=152;
        y+=55;
    }
}

string tiles::boxes (void)
{
    Sprite sprite;


    //Load dot texture
    if( !sprite.loadFromFile( "Blue.jpg",50 , 50 ) )
    {
        printf( "Failed to load blue tile texture!\n" );
    }
//highlight A8 when clicked
    if (x>=143 and x<=197 and y>=158 and y<=209)
    {
        sprite.render(146, 158);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "A8";
        }
    }
//highlight B8 when clicked
    else if (x>=198 and x<=254 and y>=158 and y<=209)
    {
        sprite.render(202, 158);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "B8";
        }
    }
//highlight C8 when clicked
    else if (x>=255 and x<=310 and y>=158 and y<=209)
    {
        sprite.render(259, 158);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "C8";
        }
    }
//highlight D8 when clicked
    else if (x>=311 and x<=366 and y>=158 and y<=209)
    {
        sprite.render(315, 158);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "D8";
        }
    }
//highlight E8 when clicked
    else if (x>=367 and x<=422 and y>=158 and y<=209)
    {
        sprite.render(371, 158);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "E8";
        }
    }
//highlight F8 when clicked
    else if (x>=423 and x<=478 and y>=158 and y<=209)
    {
        sprite.render(427, 158);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "F8";
        }
    }
//highlight G8 when clicked
    else if (x>=479 and x<=535 and y>=158 and y<=209)
    {
        sprite.render(483, 158);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "G8";
        }
    }
//highlight H8 when clicked
    else if (x>=536 and x<=591 and y>=158 and y<=209)
    {
        sprite.render(539, 158);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "H8";
        }
    }
//highlight A7 when clicked
    else if (x>=143 and x<=197 and y>=210 and y<=264)
    {
        sprite.render(146, 212);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "A7";
        }
    }
//highlight B7 when clicked
    else if (x>=198 and x<=254 and y>=210 and y<=264)
    {
        sprite.render(202, 212);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "B7";
        }
    }
//highlight C7 when clicked
    else if (x>=255 and x<=310 and y>=210 and y<=264)
    {
        sprite.render(259, 212);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "C7";
        }
    }
//highlight D7 when clicked
    else if (x>=311 and x<=366 and y>=210 and y<=264)
    {
        sprite.render(315, 212);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "D7";
        }
    }
//highlight E7 when clicked
    else if (x>=367 and x<=422 and y>=210 and y<=264)
    {
        sprite.render(371, 212);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "E7";
        }
    }
//highlight F7 when clicked
    else if (x>=423 and x<=478 and y>=210 and y<=264)
    {
        sprite.render(427, 212);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "F7";
        }
    }
//highlight G7 when clicked
    else if (x>=479 and x<=535 and y>=210 and y<=264)
    {
        sprite.render(483, 212);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "G7";
        }
    }
    //highlight H7 when clicked
    else if (x>=536 and x<=591 and y>=210 and y<=264)
    {
        sprite.render(539, 212);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "H7";
        }
    }
    //highlight A6 when clicked
    else if (x>=143 and x<=197 and y>=265 and y<=317)
    {
        sprite.render(146, 268);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "A6";
        }
    }
    //highlight B6 when clicked
    else if (x>=198 and x<=254 and y>=265 and y<=317)
    {
        sprite.render(202, 268);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "B6";
        }
    }
    //highlight C6 when clicked
    else if (x>=255 and x<=310 and y>=265 and y<=317)
    {
        sprite.render(259, 268);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "C6";
        }
    }
    //highlight D6 when clicked
    else if (x>=311 and x<=366 and y>=265 and y<=317)
    {
        sprite.render(315, 268);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "D6";
        }
    }
    //highlight E6 when clicked
    else if (x>=367 and x<=422 and y>=265 and y<=317)
    {
        sprite.render(371, 268);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "E6";
        }
    }
    //highlight F6 when clicked
    else if (x>=423 and x<=478 and y>=265 and y<=317)
    {
        sprite.render(427, 268);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "F6";
        }
    }
    //highlight G6 when clicked
    else if (x>=479 and x<=535 and y>=265 and y<=317)
    {
        sprite.render(483, 268);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "G6";
        }
    }
    //highlight H6 when clicked
    else if (x>=536 and x<=591 and y>=265 and y<=317)
    {
        sprite.render(539, 268);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "H6";
        }
    }
    //highlight A5 when clicked
    else if (x>=143 and x<=197 and y>=318 and y<=372)
    {
        sprite.render(146, 321);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "A5";
        }
    }
    //highlight B5 when clicked
    else if (x>=198 and x<=254 and y>=318 and y<=372)
    {
        sprite.render(202, 321);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "B5";
        }
    }
    //highlight C5 when clicked
    else if (x>=255 and x<=310 and y>=318 and y<=372)
    {
        sprite.render(259, 321);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "C5";
        }
    }
    //highlight D5 when clicked
    else if (x>=311 and x<=366 and y>=318 and y<=372)
    {
        sprite.render(315, 321);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "D5";
        }
    }
    //highlight E5 when clicked
    else if (x>=367 and x<=422 and y>=318 and y<=372)
    {
        sprite.render(371, 321);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "E5";
        }
    }
    //highlight F5 when clicked
    else if (x>=423 and x<=478 and y>=318 and y<=372)
    {
        sprite.render(427, 321);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "F5";
        }
    }
    //highlight G5 when clicked
    else if (x>=479 and x<=535 and y>=318 and y<=372)
    {
        sprite.render(483, 321);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "G5";
        }
    }
    //highlight H5 when clicked
    else if (x>=536 and x<=591 and y>=318 and y<=372)
    {
        sprite.render(539, 321);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "H5";
        }
    }
    //highlight A4 when clicked
    else if (x>=143 and x<=197 and y>=373 and y<=427)
    {
        sprite.render(146, 376);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "A4";
        }
    }
    //highlight B4 when clicked
    else if (x>=198 and x<=254 and y>=373 and y<=427)
    {
        sprite.render(202, 376);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "B4";
        };
    }
    //highlight C4 when clicked
    else if (x>=255 and x<=310 and y>=373 and y<=427)
    {
        sprite.render(259, 376);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "C4";
        }
    }
    //highlight D4 when clicked
    else if (x>=311 and x<=366 and y>=373 and y<=427)
    {
        sprite.render(315, 376);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "D4";
        }

    }
    //highlight E4 when clicked
    else if (x>=367 and x<=422 and y>=373 and y<=427)
    {
        sprite.render(371, 376);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "E4";
        }
    }
    //highlight F4 when clicked
    else if (x>=423 and x<=478 and y>=373 and y<=427)
    {
        sprite.render(427, 376);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "F4";
        }
    }
    //highlight G4 when clicked
    else if (x>=479 and x<=535 and y>=373 and y<=427)
    {
        sprite.render(483, 376);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "G4";
        }
    }
    //highlight H4 when clicked
    else if (x>=536 and x<=591 and y>=373 and y<=427)
    {
        sprite.render(539, 376);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "H4";
        }
    }
    //highlight A3 when clicked
    else if (x>=143 and x<=197 and y>=428 and y<=482)
    {
        sprite.render(146, 431);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "A3";
        }
    }
    //highlight B3 when clicked
    else if (x>=198 and x<=254 and y>=428 and y<=482)
    {
        sprite.render(202, 431);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "B3";
        }
    }
    //highlight C3 when clicked
    else if (x>=255 and x<=310 and y>=428 and y<=482)
    {
        sprite.render(259, 431);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "C3";
        }
    }
    //highlight D3 when clicked
    else if (x>=311 and x<=366 and y>=428 and y<=482)
    {
        sprite.render(315, 431);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "D3";
        }
    }
    //highlight E3 when clicked
    else if (x>=367 and x<=422 and y>=428 and y<=482)
    {
        sprite.render(371, 431);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "E3";
        }
    }
    //highlight F3 when clicked
    else if (x>=423 and x<=478 and y>=428 and y<=482)
    {
        sprite.render(427, 431);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "F3";
        }
    }
    //highlight G3 when clicked
    else if (x>=479 and x<=535 and y>=428 and y<=482)
    {
        sprite.render(483, 431);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "G3";
        }
    }
    //highlight H3 when clicked
    else if (x>=536 and x<=591 and y>=428 and y<=482)
    {
        sprite.render(539, 431);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "H3";
        }
    }
    //highlight A2 when clicked
    else if (x>=143 and x<=197 and y>=483 and y<=537)
    {
        sprite.render(146, 486);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "A2";
        }
    }
    //highlight B2 when clicked
    else if (x>=198 and x<=254 and y>=483 and y<=537)
    {
        sprite.render(202, 486);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "B2";
        }
    }
    //highlight C2 when clicked
    else if (x>=255 and x<=310 and y>=483 and y<=537)
    {
        sprite.render(259, 486);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "C2";
        }
    }
    //highlight D2 when clicked
    else if (x>=311 and x<=366 and y>=483 and y<=537)
    {
        sprite.render(315, 486);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "D2";
        }
    }
    //highlight E2 when clicked
    else if (x>=367 and x<=422 and y>=483 and y<=537)
    {
        sprite.render(371, 486);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "E2";
        }
    }
    //highlight F2 when clicked
    else if (x>=423 and x<=478 and y>=483 and y<=537)
    {
        sprite.render(427, 486);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "F2";
        }
    }
    //highlight G2 when clicked
    else if (x>=479 and x<=535 and y>=483 and y<=537)
    {
        sprite.render(483, 486);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "G2";
        }
    }
    //highlight H2 when clicked
    else if (x>=536 and x<=591 and y>=483 and y<=537)
    {
        sprite.render(539, 486);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "H2";
        }
    }
    //highlight A1 when clicked
    else if (x>=143 and x<=197 and y>=538 and y<=592)
    {
        sprite.render(146, 541);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "A1";
        }
    }
    //highlight B1 when clicked
    else if (x>=198 and x<=254 and y>=538 and y<=592)
    {
        sprite.render(202, 541);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "B1";
        }
    }
    //highlight C1 when clicked
    else if (x>=255 and x<=310 and y>=538 and y<=592)
    {
        sprite.render(259, 541);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "C1";
        }
    }
    //highlight D1 when clicked
    else if (x>=311 and x<=366 and y>=538 and y<=592)
    {
        sprite.render(315, 541);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "D1";
        }
    }
    //highlight E1 when clicked
    else if (x>=367 and x<=422 and y>=538 and y<=592)
    {
        sprite.render(371, 541);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "E1";
        }
    }
    //highlight F1 when clicked
    else if (x>=423 and x<=478 and y>=538 and y<=592)
    {
        sprite.render(427, 541);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "F1";
        }
    }
    //highlight G1 when clicked
    else if (x>=479 and x<=535 and y>=538 and y<=592)
    {
        sprite.render(483, 541);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "G1";
        }
    }
    //highlight H1 when clicked
    else if (x>=536 and x<=591 and y>=538 and y<=592)
    {
        sprite.render(539, 541);
        if (oldx!=x and oldy!=y)
        {
            oldx=x;
            oldy=y;
            return "H1";
        }
    }

    return "";



}
void tiles::handleEvent( SDL_Event& e )
{

    //If a key was pressed
    if( e.type == SDL_KEYDOWN /*&& e.key.repeat == 0*/ )
    {
        //        //Adjust the velocity
        //        switch( e.key.keysym.sym )
        //        {
        //        case SDLK_UP:
        //            vy -= 1;
        //            break;
        //        case SDLK_DOWN:
        //            vy += 1;
        //            break;
        //        case SDLK_LEFT:
        //            vx -= 1;
        //            break;
        //        case SDLK_RIGHT:
        //            vx += 1;
        //            break;
        //        }
    }
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        x=e.button.x;
        y=e.button.y;
        std::cout<<"x="<<x<<"y="<<y<<" ";

    }

}




void Ball::render()
{
    sprite.render(x,y);
}

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;


Sprite::Sprite()
{
    //Initialize
    mSprite = NULL;
    mWidth = 0;
    mHeight = 0;
}

Sprite::~Sprite()
{
    //Deallocate
    free();
}

bool Sprite::loadFromFile( std::string path, int height, int width )
{

    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = IMG_LoadTexture(gRenderer,path.c_str());




    if( newTexture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error:%s\n", path.c_str(), SDL_GetError() );
    }
    else
    {
        //Get image dimensions
        mWidth = width;
        mHeight = height;
    }



    //Return success
    mSprite = newTexture;
    return mSprite != NULL;
}

void Sprite::free()
{
    //Free texture if it exists
    if( mSprite != NULL )
    {
        SDL_DestroyTexture( mSprite );
        mSprite = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}
void Sprite::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx( gRenderer, mSprite, clip, &renderQuad, angle, center, flip );
}



bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error:%s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning:Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "Best Chess AI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error:%s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
        }
    }
    return success;
}
class buttons
{
public :
    void DisplayComButtons (void);
    bool PlayComB (SDL_Event& e);
    bool PlayComW (SDL_Event& e);


private:


};

void buttons ::DisplayComButtons (void)
{
    Sprite sprite;

    //Load dot texture
    if( !sprite.loadFromFile( "PlayComB.jpg",60 , 200 ) )
    {
        printf( "Failed to load aiButtonW tile texture!\n" );
    }

    sprite.render(10,20);
    //Load dot texture
    if( !sprite.loadFromFile( "PlayComW.jpg",60 , 200 ) )
    {
        printf( "Failed to load aiButtonW tile texture!\n" );
    }
    sprite.render(200,20);


}
bool buttons ::PlayComB (SDL_Event& e)
{
    int x=0;
    int y=0;
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        x=e.button.x;
        y=e.button.y;
    }

    if (x>=13 and x<=199 and y>=24 and y<=75)
        return true;
    else
        return false;


}
bool buttons ::PlayComW (SDL_Event& e)
{
    int x=0;
    int y=0;
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        x=e.button.x;
        y=e.button.y;
    }
    if (x>=200 and x<=396 and y>=24 and y<=75)

        return true;
    else
        return false;

}
void close()
{
    //Free loaded images

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
int main( int argc, char* args[] )
{
    // create class objects to so functions from other classes can be used
    PrintChess BoardPrint;
    moves MovesClass;
    LegalMoves legal;
    ValidMove valid;
    Conversion convert;
    ArtificialIntelligence ComputerPlayer;
    GameFunctions game;

    string othertemp;
    // set priority to high priority
    if(!SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS))
    {
        return 0;
    }
    //  declare variables
    // variable to store which player is playing
    string player;
    // variable to count the number of turns in the game
    int  turns=2;
    // variables to check whether certain pieces have moved so that information can be used to determine
    // if a player is able to castle
    bool KingUpper=true;
    bool KingLower=true;
    bool RookUpperRight=true;
    bool RookUpperLeft=true;
    bool RookLowerRight=true;
    bool RookLowerLeft=true;
    // variable to store which player can do en passant
    string EnPassant="No";
    // variable to store whether a pawn was moved
    bool pawn=false;
    // variables temperily used to store the position pieces needed to be moved to for en passant to work
    int temp1=0;
    int temp2=0;
    char temp3=' ';
    // variable to store all the boolean variables for castling so that they can be saved to a text file or
    // easily imported into another function
    string bools;
    // variable to store the hightest
    int best =INT_MAX;
    // variable to store the value a move scores
    int val;
    // variable to store all the boolean variables for castling so that they can be saved to a text file or
    // easily imported into another function
    string temps;
    bool InvalidMove=false;
    bool GameLogging=true;
    string type="no";
    bool beginning=true;
    bool AI=false;
    // variable used to store copy of the board when the ai makes and unmakes moves
    string CopyBoard [8][8];
    // string to hold valid moves
    string ValidMove;
    // variables for counters for making different moves
    register int t=0;
    register int q=1;
    register int z=2;
    register int r=3;

    // string the hold values taken from text file (mostly used to hold the boolean values of the above variables)
    string InputValues;

    // string to hold the value of the last move
    string LastMove="";

    // declare streams
    ofstream outputFile;
    ifstream InputFile;

    //variable to store the set up of the board at the beginning so it can be used to start a new game
    string OriginalSetup[8][8];
    // declare array variables to hold values the chess board
    string PrintRow [8][8] {{" R "," N "," B "," K "," Q "," B "," N "," R "},
        {" P "," P "," P "," P "," P "," P "," P "," P " },{"   ","   ","   ","   ","   ","   ","   ","   "},
        {"   ","   ","   ","   ","   ","   ","   ","   "},{"   ","   ","   ","   ","   ","   ","   ","   "},
        {"   ","   ","   ","   ","   ","   ","   ","   "},{" p "," p "," p "," p "," p "," p "," p "," p ",},
        {" r "," n "," b "," k "," q "," b "," n "," r "}
    };
    // string to store the moves the user enters
    string moves="";


    // puts the starting values of the board in the array that stores the original setup
    game.BoardSetup(PrintRow, OriginalSetup);

    //deletes old log file so new one can be created
    remove ("GameLogging.txt");
    // variables to store boolean values
    bools=string(1,((char)(KingUpper+48))) +string(1,((char)(KingLower+48)))+string(1,((char)(RookUpperRight+48)))+
          string(1,((char)(RookUpperLeft+48)))+string(1,((char)(RookLowerRight+48)))+ string(1,((char)(RookLowerLeft+48)));

    // checks whether it is the beginning of the game or not and checks whether logging is on
    if (GameLogging==true and beginning==true)
    {
        // stores all the castling bools in one string
        bools=string(1,((char)(KingUpper+48))) +string(1,((char)(KingLower+48)))+string(1,((char)(RookUpperRight+48)))+
              string(1,((char)(RookUpperLeft+48)))+string(1,((char)(RookLowerRight+48)))+ string(1,((char)(RookLowerLeft+48)));
        // stores all the enpassant temporary variables in one string
        temps=string(1,(char)(temp1+48))+string(1,(char)(temp2+48))+string(1,temp3);
        // writes everything to a file inucluding the board state to a text file entitled GameLogging.txt
        game.LoggingGames(PrintRow, "GameLogging.txt", true, bools, turns-1,  temps, EnPassant, LastMove );
    }
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        //The ball that will be moving around on the screen
        Ball ball;
        Sprite sprite;
        tiles Tiles;
        buttons ButtonsClass;

        // loop to keep the programing running
        while (true and !quit)
        {


            // variables to store boolean values
            bools=string(1,((char)(KingUpper+48))) +string(1,((char)(KingLower+48)))+string(1,((char)(RookUpperRight+48)))+
                  string(1,((char)(RookUpperLeft+48)))+string(1,((char)(RookLowerRight+48)))+ string(1,((char)(RookLowerLeft+48)));

            // sets the colour of the background of the console
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15 );
            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );
            SDL_RenderClear( gRenderer );

            // checks to see if Enpassent was triggered
            if (EnPassant=="P" and InvalidMove==false)
            {
                //stores the value of the position the pawn was in if it was to have moved one space
                temp1=convert.CharToInt(moves[3])-1;
                temp2=convert.CharToInt(moves[3]);
                temp3=moves[0];
                // moves the pawn to the place the user intended for it to be
                MovesClass.Moves(moves[0],convert.CharToInt(moves[3])-1,moves[0],convert.CharToInt(moves[3]), PrintRow, false, player);
            }
            else if (EnPassant=="p" and InvalidMove==false)
            {
                //stores the value of the position the pawn was in if it was to have moved one space
                temp1=convert.CharToInt(moves[3])+1;
                temp2=convert.CharToInt(moves[3]);
                temp3=moves[0];
                // moves the pawn to the place the user intended for it to be
                MovesClass.Moves(moves[0],convert.CharToInt(moves[3])+1,moves[0],convert.CharToInt(moves[3]), PrintRow,false, player);
            }

            do
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    Tiles.handleEvent( e );
                    if (ButtonsClass.PlayComB(e))
                    {
                        type="lower";
                        AI=true;
                    }
                    else if (ButtonsClass.PlayComW(e))
                    {
                        type="upper";
                        AI=true;
                    }

                }
                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );
                SDL_RenderClear( gRenderer );


                //Load dot texture
                if( !sprite.loadFromFile( "Chess.jpg",500, 500 ) )
                {
                    printf( "Failed to load dot texture!\n" );
                }

                sprite.render (100,100);


                ButtonsClass.DisplayComButtons();




                // assigns which player's turn it is depending on the value of turns
                if (turns%2!=0) player="lower";
                else player="upper";

                // clears the screen
                system("cls");
                // prints out the chess board
                // prints the orientation of of the board with a different header depending on who is playing
                if (player=="lower")
                {
                    // States that the player playing the lowercase letters will now be playing
                    cout<<"Player playing the LowerCase Letters Turn"<<endl<<endl;
                    // outputs the board with a certain orientation
                    BoardPrint.PrintChess1(PrintRow);
                    cout<<"The last move made was: "<<LastMove<<endl;


                }
                else
                {
                    // States that the player playing the uppercase letters will now be playing
                    cout<<" Player playing the UpperCase Letters Turn"<<endl<<endl;
                    // outputs the board with the opposite orientation of PrintChess1
                    BoardPrint.PrintChess2(PrintRow);
                    cout<<"The last move made was: "<<LastMove<<endl;

                }


                // checks to see if it is the ai's turn and whether the user wanted the ai to play or not
                if (player==type and AI==true)
                {

                board(PrintRow);



                //Update screen
                SDL_RenderPresent( gRenderer );

                    // calls the openings function to read a text file with all the openings to see if
                    //an opening can be used it and if it can it returns true and the stores the opening in a temp file
                    if (ComputerPlayer.openings (PrintRow,KingUpper,KingLower,RookUpperRight,
                                                 RookUpperLeft,RookLowerRight, RookLowerLeft, temp1, temp2,temp3,
                                                 EnPassant, player)==true)
                    {

                        // sets the next board state

                        // opens a text file by the name of temp.txt
                        InputFile.open("temp.txt");
                        // gets a line from the text file and stores it in InputValues
                        getline(InputFile,InputValues);
                        // assigns the value of InputValues to be nothing
                        InputValues="";
                        // reads the next line in the text file
                        getline(InputFile,InputValues);
                        // assigns the bool values to the following variables
                        KingUpper=convert.CharToBool(InputValues[0]);
                        KingLower=convert.CharToBool(InputValues[1]);
                        RookUpperRight=convert.CharToBool(InputValues[2]);
                        RookUpperLeft=convert.CharToBool(InputValues[3]);
                        RookLowerRight=convert.CharToBool(InputValues[4]);
                        RookLowerLeft=convert.CharToBool(InputValues[5]);
                        // gets the next line in the text file
                        getline(InputFile,InputValues);
                        // gets the next line in the text file
                        getline(InputFile,InputValues);
                        temp1=convert.CharToInt(InputValues[0]);
                        temp2=convert.CharToInt(InputValues[1]);
                        temp3=InputValues[2];
                        // gets the next line in the text file
                        getline(InputFile,InputValues);
                        // assigns Enpassant the value of InputValues
                        EnPassant=InputValues;
                        // gets the next line in the text file
                        getline(InputFile,InputValues);
                        // assigns LastMove the value of InputValues
                        LastMove=InputValues;
                        // closes the input file
                        InputFile.close();
                        // deletes the temp file
                        remove("temp.txt");
                        // logs the board state in a text file
                        if (GameLogging==true)
                        {
                            // stores all the boolean values for castling rights
                            bools=string(1,((char)(KingUpper+48))) +string(1,((char)(KingLower+48)))+string(1,((char)(RookUpperRight+48)))+
                                  string(1,((char)(RookUpperLeft+48)))+string(1,((char)(RookLowerRight+48)))+ string(1,((char)(RookLowerLeft+48)));
                            // stores all the temp variables for en passent
                            temps=string(1,(char)(temp1+48))+string(1,(char)(temp2+48))+string(1,temp3);
                            // calls function to log the game
                            game.LoggingGames(PrintRow, "GameLogging.txt", true, bools, turns,  temps, EnPassant, LastMove );
                        }
                        // goes to the next turn
                        turns++;
                        // the value of moves back to null
                        moves="";
                        // continues in the loop
                        continue;
                    }

                    // resets the value of valid moves to null string
                    ValidMove="";

                    // calls function to get valid moves
                    ValidMove=valid.ValidMoves(PrintRow, player, bools);

                    // checks to see if ValidMove equals to a null string
                    if (ValidMove=="")
                    {
                        // If the ai is in checkmate tells the player that they won and what command they can type in
                        if (legal.ischeck(PrintRow,player)==type)
                            cout<<"You win. Type quit to quit type new game to restart"<<endl;
                        else
                            // If the ai is in stalemate tells the player that they won and what command they can type in
                            cout<<"It was a stalemate. Type quit to quit type new game to restart"<<endl;
                    }
                    else
                    {
                        // calls function to get the top five best moves at depth one
                        ValidMove=ComputerPlayer.BestMoves(PrintRow,player,1, bools);



                        // resets values of the counters to the starting values for getting moves from the string
                        t=0;
                        q=1;
                        z=2;
                        r=3;


                        //sets the value of best to INT_MAX
                        best =INT_MAX;

                        // loop until end of string will be when r is equal to ValidMove.length()
                        while (r<ValidMove.length())
                        {

                     //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

                }
                            // calls function to make a copy of the current board state
                            game.BoardSetup(PrintRow,CopyBoard);
                            // calls function to render castling move and checks to see if the move was a castling move
                            if (MovesClass.castling(string (1,ValidMove[t])+string (1,ValidMove[q])+string (1,ValidMove[z])+string (1,ValidMove[r]),
                                                    PrintRow,player)==false)
                            {
                                // if the move wasn't a castling move makes the move here
                                MovesClass.MovesWithoutLegal(ValidMove[t],convert.CharToInt(ValidMove[q]),ValidMove[z],convert.CharToInt(ValidMove[r]),PrintRow);
                            }
                            // gets the value of making that move by calling the function AlphaBeta to check moves up to depth 5
                            val = ComputerPlayer.AlphaBeta(4, INT_MIN, INT_MAX,PrintRow, player, turns+1, bools);
                            // unmakes the move
                            game.BoardSetup(CopyBoard,PrintRow);

                            // checks to see if the value of the move is less than best if it is adds it to moves and changes the value of best
                            if (val<=best )
                            {
                                //changes the value of best to val
                                best=val;
                                // makes moves equal to a null string
                                moves="";
                                // puts the move that was made into the variable moves
                                moves+=ValidMove[t];
                                moves+=ValidMove[q];
                                moves+=ValidMove[z];
                                moves+=ValidMove[r];
                            }

                            // increases the counters by one so that next move can be made
                            t+=4;
                            q+=4;
                            z+=4;
                            r+=4;

                        }

                        // once the best move has been found breaks out and renders the move
                        break;
                    }
                }
                // checks whether a player is in check
                if (legal.ischeck(PrintRow,player)=="upper" or legal.ischeck(PrintRow,player)=="lower")
                {
                    // if CheckForMate returns true then outputs the word checkmate
                    if (valid.ValidMoves(PrintRow, player, bools)=="")cout<< "checkmate"<<endl;
                    // just in check outputs the word check
                    else cout<< "check"<<endl;
                }

                // outputs whether there is a stalemate or not based on returned value of ischeck function and whether ValidMoves found any moves
                if (legal.ischeck(PrintRow, player)=="No Check" and valid.ValidMoves(PrintRow,player, bools)=="")
                {
                    // outputs statement "stalemate"
                    cout<<"stalemate"<<endl;
                }

                // uncomment this line if you want to evaluation values of move scores
                //cout<< ComputerPlayer.evaluation(PrintRow,player, bools);

                // gets move from the user
                cout<<"Please enter your move"<<endl;
                //getline(cin,moves);

                if (moves.length()==4)
                {
                    string tempmoves="";
                    for (int i=2; i<4; i++)
                    {
                        tempmoves+=othertemp[i];
                    }
                    moves=tempmoves;
                }
                else
                {
                    moves+=Tiles.boxes();
                }

                othertemp=moves;

                board(PrintRow);



                //Update screen
                SDL_RenderPresent( gRenderer );


                // if the user enters save then saves the game to a text file
                if(moves=="save")
                {
                    // gets all the boolean values for castling stored in a single string
                    bools=string(1,((char)(KingUpper+48))) +string(1,((char)(KingLower+48)))+string(1,((char)(RookUpperRight+48)))+
                          string(1,((char)(RookUpperLeft+48)))+string(1,((char)(RookLowerRight+48)))+ string(1,((char)(RookLowerLeft+48)));
                    // stores all the temp files for en passant in a single string
                    temps=string(1,(char)(temp1+48))+string(1,(char)(temp2+48))+string(1,temp3);
                    // calls function LoggingGames to log the game
                    game.LoggingGames(PrintRow, "SaveFile.txt", false, bools, turns,  temps, EnPassant, LastMove );
                }
                // if the user enters resume
                else if(moves=="resume")
                {
                    // calls the function resume game and uses it assign values from a text file to the board array
                    game.ResumeGame(PrintRow, "SaveFile.txt");
                    // opens a text file by the name of SaveFile.txt
                    InputFile.open("SaveFile.txt");
                    // gets a line from the text file and stores it in InputValues
                    getline(InputFile,InputValues);
                    // assigns the value of InputValues to be nothing
                    InputValues="";
                    // reads the next line in the text file
                    getline(InputFile,InputValues);
                    // assigns the bool values to the following variables
                    KingUpper=convert.CharToBool(InputValues[0]);
                    KingLower=convert.CharToBool(InputValues[1]);
                    RookUpperRight=convert.CharToBool(InputValues[2]);
                    RookUpperLeft=convert.CharToBool(InputValues[3]);
                    RookLowerRight=convert.CharToBool(InputValues[4]);
                    RookLowerLeft=convert.CharToBool(InputValues[5]);
                    // gets the next line in the text file
                    getline(InputFile,InputValues);
                    // converts the line of the text file to an integer and assigns it to the variable turns
                    turns=convert.StringToInt(InputValues);
                    // gets the next line in the text file
                    getline(InputFile,InputValues);
                    temp1=convert.CharToInt(InputValues[0]);
                    temp2=convert.CharToInt(InputValues[1]);
                    temp3=InputValues[2];
                    // gets the next line in the text file
                    getline(InputFile,InputValues);
                    EnPassant=InputValues;
                    // gets the next line in the text file
                    getline(InputFile,InputValues);
                    LastMove=InputValues;
                    // closes the input file
                    InputFile.close();

                }
                // if moves equals to new game then starts a new game
                else if(moves=="new game")
                {
                    //removes logging file so it can start fresh
                    remove ("GameLogging.txt");
                    // resets values so the ai is not playing anymore
                    AI=false;
                    type="No";
                    // resets the value
                    LastMove="";
                    // resets bool so it the program knows
                    beginning=true;
                    // resets the value of turns to 2
                    turns=2;
                    // calls the function to reset the board
                    game.BoardSetup(OriginalSetup,PrintRow);
                    // resets the boolean values back to true
                    KingUpper=true;
                    KingLower=true;
                    RookUpperRight=true;
                    RookUpperLeft=true;
                    RookLowerRight=true;
                    RookLowerLeft=true;
                    // resets value of EnPAssant back to "No"
                    EnPassant="No";
                    pawn=false;
                    temp1=0;
                    temp2=0;
                    temp3=' ';
                    //  checks whether logging is on
                    if (GameLogging==true)
                    {
                        // stores all the castling bools in one string
                        bools=string(1,((char)(KingUpper+48))) +string(1,((char)(KingLower+48)))+string(1,((char)(RookUpperRight+48)))+
                              string(1,((char)(RookUpperLeft+48)))+string(1,((char)(RookLowerRight+48)))+ string(1,((char)(RookLowerLeft+48)));
                        // stores all the enpassant temporary variables in one string
                        temps=string(1,(char)(temp1+48))+string(1,(char)(temp2+48))+string(1,temp3);
                        // writes everything to a file inucluding the board state to a text file entitled GameLogging.txt
                        game.LoggingGames(PrintRow, "GameLogging.txt", true, bools, turns-1,  temps, EnPassant, LastMove );
                    }

                }
                // this allows the user to skip a turn it was just used for testing if it is needed uncomment it
                /*else if(moves=="skip")
                {
                turns++;
                InvalidMove=false;
                if (turns<=10)
                turns-=2;
                }*/
                // if moves equals quit, quits the game
                else if(moves=="quit")
                {
                    //Free resources and close SDL
                    close();
                    return 0;
                }
                // if the user types in in ailower it tells the ai playing the lower pieces that it can start playing when it is its turn
                else if(moves=="ailower" and AI!=true)
                {
                    type="lower";
                    AI=true;
                }
                // if the user types in in ailower it tells the ai playing the upper pieces that it can start playing when it is its turn
                else if(moves=="aiupper" and AI!=true)
                {
                    type="upper";
                    AI=true;
                }
                // changes the letter the user enters so that all the letters are in the same case
                if (moves [0]>=97 and moves [0]<=122)
                {
                    moves[0]-=32;
                }
                if (moves [2]>=97 and moves [2]<=122)
                {
                    moves[2]-=32;
                }
                if (quit)
                {
                    close ();
                    return 0;

                }

            }
            // makes sure the user enters in valid move data
            while (!((moves [0]>=65 and moves [0]<=72) and (moves [0]>=65 and moves [0]<=72)
                     and (moves.length()==4) and (convert.CharToInt(moves[1])>0 and convert.CharToInt(moves[3])>0)
                     and (convert.CharToInt(moves[1])<=8 and convert.CharToInt(moves[3])<=8)) );


            // checks to see if it is ai's turn if it is doesn't convert the moves
            if (player!=type)
            {
                // converts the letters so that they work properly with proper board labeling which we implemented at the end
                moves[0]=convert.ConvertingLetters(moves[0]);
                moves[2]=convert.ConvertingLetters(moves[2]);
            }


            // checks whether a pawn was moved
            if (PrintRow[convert.CharToInt(moves[1])-1][(int)moves[0]-65]==" P " or PrintRow[convert.CharToInt(moves[1])-1][(int)moves[0]-65]==" p ")pawn=true;
            else pawn=false;

            // checks whether user is trying to do enpassant when it is valid
            if (pawn==true and convert.CharToInt(moves[3])==temp1 and moves[2]==temp3  and ((int)moves[2]==(int)moves[0]+1 or (int)moves[2]==(int)moves[0]-1)
                    and (convert.CharToInt(moves[3])==convert.CharToInt(moves[1])+1 or convert.CharToInt(moves[3])==convert.CharToInt(moves[1])-1 ) )
            {
                // if the user is trying to do en passant then checks whether en passant is possible and if it is moves pawn to the place
                // so it can be taken by the player
                if (EnPassant=="P" or EnPassant=="p")
                {
                    MovesClass.MovesWithoutLegal(temp3,temp2,temp3,temp1, PrintRow);
                }

            }



            // checks to see if it legal for a move to be made normally, castling is not included as a normal move
            if (MovesClass.Moves(moves[0],convert.CharToInt(moves[1]),moves[2],convert.CharToInt(moves[3]),PrintRow, false, player)==false)
            {
                // if it couldn't be made noramlly checks to see if castling is legal
                if (legal.CastlingCheck (moves, PrintRow,player,KingUpper,KingLower, RookUpperRight, RookUpperLeft,
                                         RookLowerRight, RookLowerLeft, false))
                {
                    // if castling is legal calls function to render castling move
                    MovesClass.castling (moves,PrintRow, player);
                }
                else
                {
                    // if both types of moves fails outputs that the move is invalid
                    cout<<endl<<"Invalid move";
                    Sleep(1000);
                    // sets invalid move to be true
                    InvalidMove=true;
                    // and goes back through the loop and gets the move from the user again
                    continue;
                }

            }
            LastMove=moves;

            // converts the letters so that show up as the move the user made or ai made on the new board labeling
            LastMove[0]=convert.ConvertingLetters( LastMove[0]);
            LastMove[2]=convert.ConvertingLetters(LastMove[2]);


            // sets invalid move to be false
            InvalidMove=false;

            //checks to see if a pawn was moved, if the pawn was moved checks to see if pawn was moved but was moved back due to en passant
            if ((pawn==true and ((convert.CharToInt(moves[3])-1==convert.CharToInt(moves[1])+1)
                                 or convert.CharToInt(moves[3])-1==convert.CharToInt(moves[1])-3 ))
                    and (PrintRow[convert.CharToInt(moves[3])-1][(int)moves[2]-65]!=" P "
                         and PrintRow[convert.CharToInt(moves[3])-1][(int)moves[2]-65]!=" p "))
            {
                //checks to see if en passant is true by seeing if the pawn was moved one move back because of the moves function which moves a pawn
                //back one to alert the program that en passant is possible
                if (PrintRow[convert.CharToInt(moves[3])-2][(int)moves[2]-65]==" P ")
                    EnPassant="P";
                if (PrintRow[convert.CharToInt(moves[3])][(int)moves[2]-65]==" p ")
                    EnPassant="p";
            }
            // if en passant is not possible sets value of EnPassant to false
            else EnPassant="No";


            // checks to see whether a king or rook was moved and records it with a boolean variable for the purpose of checking for to see if a
            // castle was is legal on other turns
            if (PrintRow[convert.CharToInt(moves[3])-1][(int)moves[2]-65]==" K " )
            {
                KingUpper=false;
            }
            else if (PrintRow[convert.CharToInt(moves[3])-1][(int)moves[2]-65]==" k " )
            {
                KingLower=false;
            }
            else if ((int)moves[0]-64==1 and convert.CharToInt(moves[1])==1 and PrintRow[convert.CharToInt(moves[3])-1][(int)moves[2]-65]==" R ")
            {
                RookUpperLeft=false;
            }
            else if ((int)moves[0]-64==8 and convert.CharToInt(moves[1])==1 and PrintRow[convert.CharToInt(moves[3])-1][(int)moves[2]-65]==" R ")
            {
                RookUpperRight=false;
            }
            else if ((int)moves[0]-64==1 and convert.CharToInt(moves[1])==8 and PrintRow[convert.CharToInt(moves[3])-1][(int)moves[2]-65]==" r ")
            {
                RookLowerLeft=false;
            }
            else if ((int)moves[0]-64==8 and convert.CharToInt(moves[1])==8 and PrintRow[convert.CharToInt(moves[3])-1][(int)moves[2]-65]==" r ")
            {
                RookLowerRight=false;
            }

            // increases the value of turns so it can move to the next turn
            turns++;

            // checks whether logging is on
            if (GameLogging==true)
            {
                // stores all the castling bools in one string
                bools=string(1,((char)(KingUpper+48))) +string(1,((char)(KingLower+48)))+string(1,((char)(RookUpperRight+48)))+
                      string(1,((char)(RookUpperLeft+48)))+string(1,((char)(RookLowerRight+48)))+ string(1,((char)(RookLowerLeft+48)));
                // stores all the enpassant temporary variables in one string
                temps=string(1,(char)(temp1+48))+string(1,(char)(temp2+48))+string(1,temp3);
                // writes everything to a file inucluding the board state to a text file entitled GameLogging.txt
                game.LoggingGames(PrintRow, "GameLogging.txt", true, bools, turns-1,  temps, EnPassant, LastMove );
            }





        }
    }
    //Free resources and close SDL
    close();
    //returns a value of 0
    return 0;
}
