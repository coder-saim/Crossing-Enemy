#ifndef PLAYER2_H
#define PLAYER2_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <sstream>


//The X and Y offsets of the Player
int mPosX2, mPosY2;
//The velocity of the Player
int mVelX2, mVelY2;


#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960


class Player2
{
    public:
       
		//The dimensions of the Player
		static const int Player_WIDTH = 30;
		static const int Player_HEIGHT = 30;

		//Maximum axis velocity of the Player
		static const int Player_VEL2 = 7;

        TTF_Font *font1;
        void Media();
		//Initializes the variables
		Player2();

		//Takes key presses and adjusts the Player's velocity
		void handleEvent( SDL_Event& e );

		//Moves the Player and checks collision
		void move();
		//Shows the Player on the screen
		void render();

        void ScoreInput(int x);
        
        SDL_Texture* LoadText(TTF_Font *font, const char *Text, SDL_Color color);

        
	
       
};



Player2::Player2()
{
    //Initialize the offsets
    mPosX2 = 0;
    mPosY2 = 0;


    //Initialize the velocity
    mVelX2 = 0;
    mVelY2 = 0;
}

void Player2::handleEvent( SDL_Event& e ){
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 ){
        //Adjust the velocity
        switch( e.key.keysym.sym ){
            case SDLK_UP: mVelY2 -= Player_VEL2; break;
            case SDLK_DOWN: mVelY2 += Player_VEL2; break;
            case SDLK_LEFT: mVelX2 -= Player_VEL2; break;
            case SDLK_RIGHT: mVelX2 += Player_VEL2; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 ){
        //Adjust the velocity
        switch( e.key.keysym.sym ){
            case SDLK_UP: mVelY2 += Player_VEL2; break;
            case SDLK_DOWN: mVelY2 -= Player_VEL2; break;
            case SDLK_LEFT: mVelX2 += Player_VEL2; break;
            case SDLK_RIGHT: mVelX2 -= Player_VEL2; break;
        }
    }
}

void Player2::move(){
    //Move the Player left or right
    mPosX2 += mVelX2;
	

    //If the Player collided or went too far to the left or right
    if( ( mPosX2 < 0 ) || ( mPosX2 + Player_WIDTH > WINDOW_WIDTH ) ) mPosX2 -= mVelX2;

    //Move the Player up or down
    mPosY2 += mVelY2;
	

    //If the Player collided or went too far up or down
    if( ( mPosY2 < 0 ) || ( mPosY2 + Player_HEIGHT > WINDOW_HEIGHT ) ) mPosY2 -= mVelY2;
}



void Player2::render()
{
    //Show the Player
	gPlayerTexture2.render( mPosX2, mPosY2 );
}


#endif