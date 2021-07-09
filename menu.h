int main_menu(){

	//Loading the Menu Image into memory using SDL Image Library Function
	menu = IMG_Load("menu1.png");
	if(menu == NULL){
		printf("Error Creating Menu\n");
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	//Loading the Menu Image Data Into the Graphics Hardware's Memory
	menu_tex = SDL_CreateTextureFromSurface(renderer,menu);
	SDL_FreeSurface(menu);
	if(menu_tex == NULL){
		printf("Error Creating Menu Texture: %s\n",SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	SDL_RenderCopy(renderer,menu_tex,NULL,NULL);
	int x=1;
	//Menu Text Type
	if(1){
		font  = TTF_OpenFont("roman.ttf",70);
		font1  = TTF_OpenFont("roman.ttf",70);	
		

	 
		SDL_RenderPresent(renderer);

		//Menu Event
		SDL_Event e;
		bool mrunning = true;
		while(mrunning){
			if(SDL_PollEvent(&e)){
				switch(e.type){
					case SDL_QUIT :
						mrunning =false;
						break;
					case SDL_MOUSEBUTTONDOWN:
					{
						if(e.motion.x>=370&&e.motion.x<=590&&e.motion.y>=330&&e.motion.y<370){
							Mix_PlayChannel( -1, click, 0 );return 11; 
							break;
						}

						if(e.motion.x>=365&&e.motion.x<=590&&e.motion.y>=450&&e.motion.y<485){
							Mix_PlayChannel( -1, click, 0 );return 1;
							break;
						}

						if(e.motion.x>=400&&e.motion.x<=550&&e.motion.y>=570&&e.motion.y<610){
							Mix_PlayChannel( -1, click, 0 );return 2;
							break;
						}
						if(e.motion.x>=420&&e.motion.x<=535&&e.motion.y>=690&&e.motion.y<730){
							Mix_PlayChannel( -1, click, 0 );return 3;
							break;
						}
						if(e.motion.x>=420&&e.motion.x<=535&&e.motion.y>=810&&e.motion.y<850){
							Mix_PlayChannel( -1, click, 0 );return 4;
							break;
						}

						if(e.motion.x>=800&&e.motion.x<=1110&&e.motion.y>=690&&e.motion.y<730){
							Mix_PlayChannel( -1, click, 0 );
							
							if(x) {
								Mix_HaltMusic(); --x;
							}
							else{
								++x; Mix_PlayMusic( gMusic3, -1 );
							} 
							
						}

						
						
					}
					default:
					break;
				}
			}
		} 
	}
    return 0;
}
