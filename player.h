#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <vector>
#include<math.h>
#include"texture.h"



#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

//The X and Y offsets of the Player
int mPosX, mPosY;
//The velocity of the Player
int mVelX, mVelY;
//Player's collision box
SDL_Rect mCollider;


bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

class Player
{
    public:
		//The dimensions of the Player
		static const int Player_WIDTH = 30;
		static const int Player_HEIGHT = 30;

		//Maximum axis velocity of the Player
		static const int Player_VEL = 7;

		//Initializes the variables
		Player();

		//Takes key presses and adjusts the Player's velocity
		void handleEvent( SDL_Event& e );

		//Moves the Player and checks collision
		void move( SDL_Rect& wall_1 ,SDL_Rect& wall_2,SDL_Rect& wall_3 ,SDL_Rect& wall_4 ,SDL_Rect& wall_5,SDL_Rect& wall_6 , SDL_Rect& wall_7 ,
	SDL_Rect& wall_8,SDL_Rect& wall_9 ,SDL_Rect& wall_10,SDL_Rect& wall_11 ,SDL_Rect& wall_12,SDL_Rect& wall_13 ,SDL_Rect& wall_14 ,SDL_Rect& wall_15,
	SDL_Rect& wall_16 , SDL_Rect& wall_17 ,SDL_Rect& wall_18,SDL_Rect& wall_19 ,SDL_Rect& wall_20,SDL_Rect& wall_21 ,SDL_Rect& wall_22,SDL_Rect& wall_23 ,
	SDL_Rect& wall_24 ,SDL_Rect& wall_25,SDL_Rect& wall_26 , SDL_Rect& wall_27 ,SDL_Rect& wall_28,SDL_Rect& wall_29 ,SDL_Rect& wall_30 );

		//Shows the Player on the screen
		void render();

        

 
       
};



Player::Player()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Set collision box dimension
	mCollider.w = Player_WIDTH;
	mCollider.h = Player_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Player::handleEvent( SDL_Event& e ){
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 ){
        //Adjust the velocity
        switch( e.key.keysym.sym ){
            case SDLK_UP: mVelY -= Player_VEL;gPlayerTexture.loadFromFile( "pacup.png" ); break;
            case SDLK_DOWN: mVelY += Player_VEL;gPlayerTexture.loadFromFile( "pacdown.png" ); break;
            case SDLK_LEFT: mVelX -= Player_VEL;gPlayerTexture.loadFromFile( "pacleft.png" ); break;
            case SDLK_RIGHT: mVelX += Player_VEL;gPlayerTexture.loadFromFile( "pac.png" ); break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 ){
        //Adjust the velocity
        switch( e.key.keysym.sym ){
            case SDLK_UP: mVelY += Player_VEL; break;
            case SDLK_DOWN: mVelY -= Player_VEL; break;
            case SDLK_LEFT: mVelX += Player_VEL; break;
            case SDLK_RIGHT: mVelX -= Player_VEL; break;
        }
    }
}

void Player::move( SDL_Rect& wall_1 ,SDL_Rect& wall_2,SDL_Rect& wall_3 ,SDL_Rect& wall_4 ,SDL_Rect& wall_5,SDL_Rect& wall_6 , SDL_Rect& wall_7 ,
	SDL_Rect& wall_8,SDL_Rect& wall_9 ,SDL_Rect& wall_10,SDL_Rect& wall_11 ,SDL_Rect& wall_12,SDL_Rect& wall_13 ,SDL_Rect& wall_14 ,SDL_Rect& wall_15,
	SDL_Rect& wall_16 , SDL_Rect& wall_17 ,SDL_Rect& wall_18,SDL_Rect& wall_19 ,SDL_Rect& wall_20,SDL_Rect& wall_21 ,SDL_Rect& wall_22,SDL_Rect& wall_23 ,
	SDL_Rect& wall_24 ,SDL_Rect& wall_25,SDL_Rect& wall_26 , SDL_Rect& wall_27 ,SDL_Rect& wall_28,SDL_Rect& wall_29 ,SDL_Rect& wall_30 )
{
    //Move the Player left or right
    mPosX += mVelX;
	mCollider.x = mPosX;

    //If the Player collided or went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + Player_WIDTH > WINDOW_WIDTH ) || checkCollision( mCollider, wall_1 ) 
	|| checkCollision( mCollider, wall_2 )|| checkCollision( mCollider, wall_3 ) || checkCollision( mCollider, wall_4 )
	|| checkCollision( mCollider, wall_5 ) || checkCollision( mCollider, wall_6 ) || checkCollision( mCollider, wall_7 )
	|| checkCollision( mCollider, wall_8 ) || checkCollision( mCollider, wall_9 )|| checkCollision( mCollider, wall_10 ) 
	|| checkCollision( mCollider, wall_11 ) || checkCollision( mCollider, wall_12 )|| checkCollision( mCollider, wall_13 ) 
	|| checkCollision( mCollider, wall_14 ) || checkCollision( mCollider, wall_15 ) || checkCollision( mCollider, wall_16 ) 
	|| checkCollision( mCollider, wall_17 )|| checkCollision( mCollider, wall_18 ) || checkCollision( mCollider, wall_19 )
	|| checkCollision( mCollider, wall_20 ) || checkCollision( mCollider, wall_21 ) || checkCollision( mCollider, wall_22 )
	|| checkCollision( mCollider, wall_23 ) || checkCollision( mCollider, wall_24 )|| checkCollision( mCollider, wall_25 ) 
	|| checkCollision( mCollider, wall_26 ) || checkCollision( mCollider, wall_27 )|| checkCollision( mCollider, wall_28 ) 
	|| checkCollision( mCollider, wall_29 )|| checkCollision( mCollider, wall_30 ))
    {
        //Move back
        mPosX -= mVelX;
		mCollider.x = mPosX;
    }

    //Move the Player up or down
    mPosY += mVelY;
	mCollider.y = mPosY;

    //If the Player collided or went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + Player_HEIGHT > WINDOW_HEIGHT ) || checkCollision( mCollider, wall_1 ) 
	|| checkCollision( mCollider, wall_2 )|| checkCollision( mCollider, wall_3 ) || checkCollision( mCollider, wall_4 )
	|| checkCollision( mCollider, wall_5 ) || checkCollision( mCollider, wall_6 ) || checkCollision( mCollider, wall_7 )
	|| checkCollision( mCollider, wall_8 ) || checkCollision( mCollider, wall_9 )|| checkCollision( mCollider, wall_10 ) 
	|| checkCollision( mCollider, wall_11 ) || checkCollision( mCollider, wall_12 )|| checkCollision( mCollider, wall_13 ) 
	|| checkCollision( mCollider, wall_14 ) || checkCollision( mCollider, wall_15 ) || checkCollision( mCollider, wall_16 ) 
	|| checkCollision( mCollider, wall_17 )|| checkCollision( mCollider, wall_18 ) || checkCollision( mCollider, wall_19 )
	|| checkCollision( mCollider, wall_20 ) || checkCollision( mCollider, wall_21 ) || checkCollision( mCollider, wall_22 )
	|| checkCollision( mCollider, wall_23 ) || checkCollision( mCollider, wall_24 )|| checkCollision( mCollider, wall_25 ) 
	|| checkCollision( mCollider, wall_26 ) || checkCollision( mCollider, wall_27 )|| checkCollision( mCollider, wall_28 ) 
	|| checkCollision( mCollider, wall_29 )|| checkCollision( mCollider, wall_30 ))
    {
        //Move back
        mPosY -= mVelY;
		mCollider.y = mPosY;
    }
}



void Player::render()
{
    //Show the Player
	gPlayerTexture.render( mPosX, mPosY );
}



#endif