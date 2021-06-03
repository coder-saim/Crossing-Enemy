int main_menu(){

	//Loading the Menu Image into memory using SDL Image Library Function
	menu = IMG_Load("menu.jpg");
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

	//Menu Text Type
	if(1){
		font  = TTF_OpenFont("Avara.ttf",70);
		font1  = TTF_OpenFont("Avara.ttf",70);	
		SDL_Texture *text[5];
		SDL_Color text_color = { 222, 49, 99,0};
		
		menu_surface = TTF_RenderText_Solid(font,"PLAY",text_color);
		text[0] = SDL_CreateTextureFromSurface(renderer,menu_surface);
		menu_surface = TTF_RenderText_Solid(font,"SCORE",text_color);
		text[1] = SDL_CreateTextureFromSurface(renderer,menu_surface);
		menu_surface = TTF_RenderText_Solid(font,"HELP",text_color);
		text[2] = SDL_CreateTextureFromSurface(renderer,menu_surface);
		menu_surface = TTF_RenderText_Solid(font,"QUIT",text_color);
		text[3] = SDL_CreateTextureFromSurface(renderer,menu_surface);
        
        SDL_Rect text_position;
		int i,j;
		for(i=0,j=0;i<4;i++,j+=150){
			text_position.x = 250;
			text_position.y = 300+j;
			text_position.w = 200;
			text_position.h = 80;
			SDL_RenderCopy(renderer,text[i],NULL,&text_position);
		}
		char Text[100]="... Crossing Enemy ...";
		SDL_Surface* tmp = TTF_RenderText_Solid(font1, Text, {222, 49, 99});
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmp);
		SDL_Rect dest2 = {280, 100, 800, 100}; SDL_RenderCopy(renderer, tex, NULL, &dest2);


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
						if(e.motion.x>=250&&e.motion.x<=450&&e.motion.y>=300&&e.motion.y<380){
							return 1;
							break;
						}
						if(e.motion.x>=250&&e.motion.x<=450&&e.motion.y>=380&&e.motion.y<530){
							return 2;
							break;
						}
						if(e.motion.x>=250&&e.motion.x<=450&&e.motion.y>=530&&e.motion.y<680){
							return 3;
							break;
						}
						if(e.motion.x>=250&&e.motion.x<=450&&e.motion.y>=680&&e.motion.y<830){
							return 4;
							break;
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
