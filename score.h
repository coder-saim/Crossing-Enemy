void InputTaken(){

			SDL_Surface *sam =IMG_Load("score.png");
	    	SDL_Texture *sam_tex = SDL_CreateTextureFromSurface(renderer,sam);
			SDL_FreeSurface(sam);


			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Set text color as black
			SDL_Color textColor = {0, 0, 128,0 };

			gPromptTextTexture.loadFromRenderedText( "Enter Your Name ", textColor);
			//The current input text.
			std::string inputText = " ";
			gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );

			//Enable text input
			SDL_StartTextInput();

			//While application is running
			while( !quit )
			{
				//The rerender text flag
				bool renderText = false;

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					//Special key input
					else if( e.type == SDL_KEYDOWN )
					{
						if((e.key.keysym.sym == SDLK_RETURN ) && inputText.length() > 0)
						{
							quit = true;
						}
						//Handle backspace
						if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
						{
							//lop off character
							inputText.pop_back();
							renderText = true;
						}
						//Handle copy
						else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
						{
							SDL_SetClipboardText( inputText.c_str() );
						}
						//Handle paste
						else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
						{
							inputText = SDL_GetClipboardText();
							renderText = true;
						}
					}
					//Special text input event
					else if( e.type == SDL_TEXTINPUT )
					{
						//Not copy or pasting
						if( !( SDL_GetModState() & KMOD_CTRL && ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' || e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) ) )
						{
							//Append character
							inputText += e.text.text;
							renderText = true;
						}
					}
				}

				//Rerender text if needed
				if( renderText )
				{
					//Text is not empty
					if( inputText != "" )
					{
						//Render new text
						gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );
					}
					//Text is empty
					else
					{
						//Render space texture
						gInputTextTexture.loadFromRenderedText( " ", textColor );
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( renderer, 47, 79, 79, 79 );
				SDL_RenderClear( renderer );
				SDL_RenderCopy(renderer,sam_tex,NULL,NULL);

				//Render text textures
				gPromptTextTexture.render( ( WINDOW_WIDTH - gPromptTextTexture.getWidth() ) / 2, 250 );
				gInputTextTexture.render( ( WINDOW_WIDTH - gInputTextTexture.getWidth() ) / 2, 320 );

				//Update screen
				SDL_RenderPresent( renderer );
			}
			/*int x=1;
			cout <<x<<" "<< inputText << endl;
			FILE *scoreFile = fopen("HighestScores.dat", "a");
			fprintf(scoreFile, "%d %s\n", x, inputText.c_str());
			fclose(scoreFile);*/
			
			//Disable text input
			SDL_StopTextInput();
		
	
}


//////////////////////////////// <<<<<<<<<<<<<<<<<<< SCORE>>>>>>>//////////////////////////////



void InputTaken(int x){
			SDL_Surface *sam =IMG_Load("score.png");
	    	SDL_Texture *sam_tex = SDL_CreateTextureFromSurface(renderer,sam);
			SDL_FreeSurface(sam);

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Set text color as black
			SDL_Color textColor = { 0, 0, 128, 0 };

			gPromptTextTexture.loadFromRenderedText( "Enter Your Name ", textColor);
			//The current input text.
			std::string inputText = " ";
			gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );

			char Text[299];sprintf(Text, "Your Score is : %2d", x);
			SDL_Surface* tmp = TTF_RenderText_Solid(font1, Text, {0, 0, 128});
			SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmp);
			SDL_Rect dest2 = {360, 270, 540, 80};

			//Enable text input
			SDL_StartTextInput();

			//While application is running
			while( !quit )
			{
				//The rerender text flag
				bool renderText = false;

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					//Special key input
					else if( e.type == SDL_KEYDOWN )
					{
						if((e.key.keysym.sym == SDLK_RETURN ) && inputText.length() > 0)
						{
							quit = true;
						}
						//Handle backspace
						if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
						{
							//lop off character
							inputText.pop_back();
							renderText = true;
						}
						//Handle copy
						else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
						{
							SDL_SetClipboardText( inputText.c_str() );
						}
						//Handle paste
						else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
						{
							inputText = SDL_GetClipboardText();
							renderText = true;
						}
					}
					//Special text input event
					else if( e.type == SDL_TEXTINPUT )
					{
						//Not copy or pasting
						if( !( SDL_GetModState() & KMOD_CTRL && ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' || e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) ) )
						{
							//Append character
							inputText += e.text.text;
							renderText = true;
						}
					}
				}

				//Rerender text if needed
				if( renderText )
				{
					//Text is not empty
					if( inputText != "" )
					{
						//Render new text
						gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );
					}
					//Text is empty
					else
					{
						//Render space texture
						gInputTextTexture.loadFromRenderedText( " ", textColor );
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( renderer, 47, 79, 79, 79 );
				SDL_RenderClear( renderer );
				SDL_RenderCopy(renderer,sam_tex,NULL,NULL);

				//Render text textures
				gPromptTextTexture.render( ( WINDOW_WIDTH - gPromptTextTexture.getWidth() ) / 2, 350 );
				gInputTextTexture.render( ( WINDOW_WIDTH - gInputTextTexture.getWidth() ) / 2, 420 );
				 SDL_RenderCopy(renderer, tex, NULL, &dest2);

				//Update screen
				SDL_RenderPresent( renderer );
			}
			
			cout <<x<<" "<< inputText << endl;
			if(x>=15){
				FILE *scoreFile = fopen("HighestScores.dat", "a");
				fprintf(scoreFile, "%d %s\n", x, inputText.c_str());
				fclose(scoreFile);
			}
			
			//Disable text input
			SDL_StopTextInput();
		
	
}



//////////////////////////////// <<<<<<<<<<<<<<<<<<<HIGH SCORE>>>>>>>>>>>>>>>>//////////////////////////////

bool compareScores(pair<int, string> x, pair<int, string> y){
	if(x.first > y.first) return true;
	else return false;
} 


void HighScore(){
	SDL_RenderCopy(renderer,help_tex,NULL,NULL);
	std::vector<std::pair<int, std::string>> highScores;
	highScores.clear();
	int Input;
	FILE* ScoreFile = fopen("HighestScores.dat", "r");
	int num;
	char playerName[100];
	while (fscanf(ScoreFile, "%d %s", &num, playerName) != EOF){
		pair<int, string> input;
		input.first = num;
		string thisName = playerName;
		input.second = thisName;

		highScores.push_back(input);
	}
	
	
	fclose(ScoreFile);


	while (highScores.size() < 7){
		highScores.push_back(make_pair(0, "N/A"));
	}

	std::sort(highScores.begin(), highScores.end(),compareScores);

	//for (int i = 0; i < 5; i++) std::cout << i + 1 << ".\t" << highScores[i].second << "\t" << highScores[i].first << endl;
	
	//SDL_RenderClear( renderer );
	SDL_Color textColor = { 0, 0, 128 };
	//Loading Texture
	int i,j,k=1;
	SDL_Texture *nametexture[5],*valuetexture[5],*serialtexture[5] ;

		char Text[30]="... Highest Scores ...";
		SDL_Surface* tmp = TTF_RenderText_Solid(font1, Text, {0, 0, 128});
		SDL_Texture* tex1 = SDL_CreateTextureFromSurface(renderer, tmp);
		SDL_Rect dest = {280, 150, 700, 80}; SDL_RenderCopy(renderer, tex1, NULL, &dest);



	for (i = 0,j=0; i < 5; i++,j+=100){

		string s = highScores[i].second;
		int value = highScores[i].first;
		char nameP[50],name[50];
		strcpy(nameP,s.c_str());
		sprintf(name, "%-7s", nameP);
		
		char text[50]; sprintf(text, "%3d", value);
		//printf("%s\n", text);

		SDL_Surface* tmp = TTF_RenderText_Solid(font1, name, textColor);
		nametexture[i] = SDL_CreateTextureFromSurface(renderer, tmp);
		SDL_Rect namepos = {510, 250+j, 200, 70}; SDL_RenderCopy(renderer, nametexture[i], NULL, &namepos);
		SDL_FreeSurface(tmp);

		tmp = TTF_RenderText_Solid(font1, text, textColor);
		valuetexture[i] = SDL_CreateTextureFromSurface(renderer, tmp);
		SDL_Rect valpos = {720, 250+j, 70, 70}; SDL_RenderCopy(renderer, valuetexture[i], NULL, &valpos);
		SDL_FreeSurface(tmp);

		char Text[100];sprintf(Text, "%d", k); Text[1]='.'; Text[2]='\0';
		tmp = TTF_RenderText_Solid(font1, Text, textColor);
		serialtexture[i] = SDL_CreateTextureFromSurface(renderer, tmp);
		SDL_Rect spos = {420, 250+j, 60, 70}; SDL_RenderCopy(renderer, serialtexture[i], NULL, &spos);
		SDL_FreeSurface(tmp);
		++k;
	}

	
	SDL_RenderPresent(renderer);

	
}





bool GameOver(int x){
	
	Mix_PlayChannel( -1, death, 0 );
	Mix_HaltMusic();
	puts("Collide with Enemy !");
	

		SDL_Event s;
		bool running = true;
 		while(running){
             while(SDL_PollEvent(&s)){
                 switch(s.type){
 					case SDL_QUIT:
 						running = false;
 						break;
					case SDL_MOUSEBUTTONDOWN:
						if(s.motion.x>=570 && s.motion.x<=710 && s.motion.y>=665 && s.motion.y<=700){
							return true;
							break;
						}
						if(s.motion.x>=565 && s.motion.x<=740 && s.motion.y>=720 && s.motion.y<=755){
							Mix_PlayMusic( gMusic3, -1 );		// playing music
							return false;
							break;
						}
 				}
             }

	//SDL_SetRenderDrawColor(renderer,240, 243, 244 ,255);
	//SDL_RenderClear(renderer);



	gameover =IMG_Load("gameover.png");
	gameover_tex = SDL_CreateTextureFromSurface(renderer,gameover);
	SDL_FreeSurface(gameover);
	SDL_RenderCopy(renderer,gameover_tex,NULL,NULL);
	

	char Text0[30];sprintf(Text0, "Your Score is : %2d", x);
	SDL_Surface* tmp = TTF_RenderText_Solid(font1, Text0, {0, 0, 255});
	SDL_Texture* tex0 = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_Rect dest0 = {430, 535, 450, 60};SDL_RenderCopy(renderer, tex0, NULL, &dest0);
	SDL_FreeSurface(tmp);


	/*char Text[30]="Wanna Play Again ?";
	tmp = TTF_RenderText_Solid(font1, Text, {0, 0, 255});
	SDL_Texture* tex2 = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_Rect dest3 = {380, 500, 500, 80}; SDL_RenderCopy(renderer, tex2, NULL, &dest3);
	SDL_FreeSurface(tmp);


	char Text1[10]="1. Yup !";
	tmp = TTF_RenderText_Solid(font1, Text1, {0, 0, 255});
	SDL_Texture* tex3 = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_Rect dest4 = {550, 600, 200, 50}; SDL_RenderCopy(renderer, tex3, NULL, &dest4);
	SDL_FreeSurface(tmp);


	char Text2[10]="2. Nope !";
	tmp = TTF_RenderText_Solid(font1, Text2, {0, 0, 255});
	SDL_Texture* tex4 = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_Rect dest5 = {550, 670, 200, 50}; SDL_RenderCopy(renderer, tex4, NULL, &dest5);
	SDL_FreeSurface(tmp);*/



	SDL_RenderPresent(renderer);
	}
	//SDL_Delay(5000);
	return true;
}