#include<stdio.h>
#include <iostream>
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<SDL2/SDL_timer.h>
#include<SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <fstream>
#include <vector>
using namespace std;

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* menu_surface = NULL;
TTF_Font *font1 = NULL,*font =NULL;
SDL_Surface* background = NULL;
SDL_Texture* background_tex = NULL;
SDL_Surface* load = NULL;
SDL_Texture* load_tex = NULL;
SDL_Texture* load_tex1 = NULL;
SDL_Surface* menu = NULL;
SDL_Texture* menu_tex = NULL;
SDL_Surface* score = NULL;
SDL_Surface* score1 = NULL;
SDL_Texture* score_tex1 = NULL;
SDL_Texture* score_tex = NULL;
SDL_Surface* win = NULL;
SDL_Texture* win_tex = NULL;
SDL_Surface* help = NULL;
SDL_Texture* help_tex = NULL;
SDL_Texture* help_tex1 = NULL;
SDL_Surface* pre_menu = NULL;
SDL_Texture* pre_menu_tex = NULL;
SDL_Surface* gameover = NULL;
SDL_Texture* gameover_tex = NULL;
SDL_Surface* highscore_img = NULL;
SDL_Texture* highscore_tex = NULL;
SDL_Surface* enemy = NULL;
SDL_Texture* enemy_tex = NULL;
SDL_Surface* ccoin = NULL;
SDL_Texture* ccoin_tex = NULL;
SDL_Surface* Specialcoin = NULL;
SDL_Texture* Specialcoin_tex = NULL;
SDL_Surface* supercoin = NULL;
SDL_Texture* supercoin_tex = NULL;
SDL_Surface* pointsP = NULL;
SDL_Texture* pointsP_tex = NULL;
SDL_Surface* pointsP2 = NULL;
SDL_Texture* pointsP2_tex = NULL;
SDL_Surface* door = NULL;
SDL_Texture* door_tex = NULL;
SDL_Surface* tmp = NULL;

Mix_Music *gMusic1 = NULL,*gMusic2 = NULL,*gMusic3 = NULL;
Mix_Chunk *click = NULL,*death = NULL,*coin = NULL,*victory = NULL,*levelup = NULL;


bool init(){
	
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO)>0){
		printf("video and timer: %s\n",SDL_GetError());
	}

    printf("Initialization Complete\n");

    window = SDL_CreateWindow("Crossing Enemy",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (!window){
 		printf("window: %s\n",SDL_GetError());
 		SDL_Quit();
		return 1;
 	}

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
 	renderer = SDL_CreateRenderer(window, -1, render_flags);

 	if (!renderer){
 		printf("renderer: %s\n",SDL_GetError());
 		SDL_DestroyWindow(window);
 		SDL_Quit();
		return 1;
 	}

	SDL_Surface* surface = IMG_Load("front.jpg");
 	if (!surface){
 		printf("Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(renderer);
 		SDL_DestroyWindow(window);
 		SDL_Quit();
		return 1;
 	}

 
 	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
 	SDL_FreeSurface(surface);
 	if(!tex){
 		printf("Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(renderer);
 		SDL_DestroyWindow(window);
 		SDL_Quit();
		return 1;
 	}



    if(TTF_Init()==-1){
    	printf("Error Initializing TTF: %s\n", TTF_GetError());
    	SDL_DestroyRenderer(renderer);
 		SDL_DestroyWindow(window);
 		SDL_Quit();
        return 1;
	}
	
	//Initialize SDL_mixer
	
	Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
	gMusic1 = Mix_LoadMUS( "Super Mario 3 Stage1.mp3" );
	gMusic2 = Mix_LoadMUS( "Castle Pac.mp3" );
	gMusic3 = Mix_LoadMUS( "intro.mp3" );

	death = Mix_LoadWAV( "death.wav" );
	coin = Mix_LoadWAV( "coin.mp3" );
	victory = Mix_LoadWAV( "Victory.mp3" );
	levelup = Mix_LoadWAV( "Victory.mp3" );
	click = Mix_LoadWAV( "Click.mp3" );




	Mix_PlayMusic( gMusic3, -1 );		// playing music


    SDL_RenderClear(renderer);
 	SDL_RenderCopy(renderer, tex, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);

    return true;
}
