
#include"menu.h"
#include"player.h"
#include"player2.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include"score.h"


int pause_coin=10;
int pause_level=2;
int level=1;
int collissionpixcount=0;
int LastDigit=0;


void play(){

    Main_Menu :
	int total_coin=0;
	int menu_button = main_menu();


    if(menu_button==1 || menu_button==11){
		Mix_HaltMusic();
		
		if(menu_button==1) InputTaken();

		if(menu_button==11){
			total_coin=pause_coin;
			level= pause_level;
		} 
		else level=1;

	//////////////////////**************LEVEL11111111111****************////////////////
	//////////////////////**************LEVEL11111111111****************////////////////
	//////////////////////**************LEVEL11111111111****************////////////////

		LEVEL :
		
		//level= pause_level;
		
		if(level==1){
		
		puts("you pressed play button");
        load =IMG_Load("loading.jpg");
		load_tex = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex,NULL,NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(300);

		load =IMG_Load("loading.gif");
		load_tex1 = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_Rect load_position;
		load_position.x = 550;
		load_position.y = 600;
		load_position.w = 150;
		load_position.h = 150;
		//SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex1,NULL,&load_position);
		SDL_RenderPresent(renderer);
		SDL_Delay(500);


		Mix_PlayMusic( gMusic1, -1 );		// playing music

		door =IMG_Load("Door.png");
		door_tex = SDL_CreateTextureFromSurface(renderer,door);
		SDL_FreeSurface(door);
		
		SDL_Rect door_position;
		door_position.x = 1250;
		door_position.y = 930;
		door_position.w = 30;
		door_position.h = 30;


	




	//Special Coin
        bool SpecialcoinB = false;
        Specialcoin = IMG_Load("Specialcoin.png");
		Specialcoin_tex = SDL_CreateTextureFromSurface(renderer,Specialcoin);
		SDL_FreeSurface(Specialcoin);

        SDL_Rect Specialcoin_position;
		Specialcoin_position.x = 640+ 400 * (rand() % 2);
		Specialcoin_position.y = 20 + 900 * (rand() % 2);
		Specialcoin_position.w = 30;
		Specialcoin_position.h = 30;
		


	//Supercoin(sword)
		bool supercoinB = false;
        supercoin = IMG_Load("supercoin.png");
		supercoin_tex = SDL_CreateTextureFromSurface(renderer,supercoin);
		SDL_FreeSurface(supercoin);

        SDL_Rect supercoin_position;
		supercoin_position.x = 40+ 400 * (rand() % 2);
		supercoin_position.y = 40+ 888 * (rand() % 2);
		supercoin_position.w = 30;
		supercoin_position.h = 30;

	

	// NON-Special COIN
		ccoin =IMG_Load("coin.png");
		ccoin_tex = SDL_CreateTextureFromSurface(renderer,ccoin);
		SDL_FreeSurface(ccoin);

		SDL_Rect ccoin1_position;
		ccoin1_position.x = 950;
		ccoin1_position.y = 888 - 200 * (rand() % 3);
		ccoin1_position.w = 20;
		ccoin1_position.h = 20;

		SDL_Rect ccoin2_position;
		ccoin2_position.x = 0 + 240 * (rand() % 3) ;
		ccoin2_position.y = 250;
		ccoin2_position.w = 20;
		ccoin2_position.h = 20;

		SDL_Rect ccoin3_position;
		ccoin3_position.x = 0+ 380 * (rand() % 3);
		ccoin3_position.y = 900;
		ccoin3_position.w = 20;
		ccoin3_position.h = 20;

		SDL_Rect ccoin4_position;
		ccoin4_position.x = 1250;
		ccoin4_position.y = 30+ 320 * (rand() % 3) ;
		ccoin4_position.w = 20;
		ccoin4_position.h = 20;

		SDL_Rect ccoin5_position;
		ccoin5_position.x = 580 + 60 * (rand() % 2);
		ccoin5_position.y = 210;
		ccoin5_position.w = 20;
		ccoin5_position.h = 20;


		enemy =IMG_Load("enemy.png");
		enemy_tex = SDL_CreateTextureFromSurface(renderer,enemy);
		SDL_FreeSurface(enemy);
		SDL_Rect enemy1_position;
		enemy1_position.x = 555;
		enemy1_position.y = 455;
		enemy1_position.w = 30;
		enemy1_position.h = 30;


		SDL_Rect enemy2_position;
		enemy2_position.x = 170;
		enemy2_position.y = 350;
		enemy2_position.w = 30;
		enemy2_position.h = 30;

		SDL_Rect enemy3_position;
		enemy3_position.x = 630;
		enemy3_position.y = 0;
		enemy3_position.w = 30;
		enemy3_position.h = 30;

		SDL_Rect enemy4_position;
		enemy4_position.x = 630;
		enemy4_position.y = 750;
		enemy4_position.w = 30;
		enemy4_position.h = 30;

		SDL_Rect enemy5_position;
		enemy5_position.x = 120;
		enemy5_position.y = 490;
		enemy5_position.w = 30;
		enemy5_position.h = 30;

		float y_pos1 = 455;
 		int direction1 = 1;

		float x_pos2 = 170;
 		int direction2 = 1;

		float y_pos3 = 0;
 		int direction3 = 1;

		float x_pos4 = 630;
 		int direction4 = 1;

		float y_pos5 = 490;
 		int direction5 = 1;

		


		
		gPlayerTexture.loadFromFile( "pac.png" );
		
		
		
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Even-----------------------------t handler
		Player player;	//The dot that will be moving around on the screen
		
			//Set the wall
			SDL_Rect wall_1;
			wall_1.x = 0;
			wall_1.y = 150;
			wall_1.w = 270;
			wall_1.h = 70;

			
			SDL_Rect wall_2;
			wall_2.x = 0;
			wall_2.y = 710;
			wall_2.w = 400;
			wall_2.h = 80;

			
			SDL_Rect wall_3;
			wall_3.x = 350;
			wall_3.y = 0;
			wall_3.w = 50;
			wall_3.h = 350;

			
			SDL_Rect wall_4;
			wall_4.x = 550;
			wall_4.y = 750;
			wall_4.w = 80;
			wall_4.h = 210;

			
			SDL_Rect wall_5;
			wall_5.x = 550;
			wall_5.y = 0;
			wall_5.w = 30;
			wall_5.h = 450;



			
			SDL_Rect wall_6;
			wall_6.x = 580;
			wall_6.y = 0;
			wall_6.w = 50;
			wall_6.h = 200;

			
			SDL_Rect wall_7;
			wall_7.x = 580;
			wall_7.y = 250;
			wall_7.w = 50;
			wall_7.h = 200;

			
			SDL_Rect wall_8;
			wall_8.x = 850;
			wall_8.y = 840;
			wall_8.w = 80;
			wall_8.h = 60*2;

			
			SDL_Rect wall_9;
			wall_9.x = 1100;
			wall_9.y = 0;
			wall_9.w = 50;
			wall_9.h = 200;

			
			
			SDL_Rect wall_10;
			wall_10.x = 1100;
			wall_10.y = 650;
			wall_10.w = 50;
			wall_10.h = 310;


			SDL_Rect wall_11;
			wall_11.x = 120;
			wall_11.y = 220;
			wall_11.w = 50;
			wall_11.h = 270;

			SDL_Rect wall_12;
			wall_12.x = 750;
			wall_12.y = 800;
			wall_12.w = 300;
			wall_12.h = 50;

			SDL_Rect wall_13;
			wall_13.x = 680;
			wall_13.y = 0;
			wall_13.w = 50;
			wall_13.h = 460;

			SDL_Rect wall_14;
			wall_14.x = 920;
			wall_14.y = 200;
			wall_14.w = 325;
			wall_14.h = 50;

			SDL_Rect wall_15;
			wall_15.x = 830;
			wall_15.y = 300;
			wall_15.w = 60;
			wall_15.h = 250;

			SDL_Rect wall_16;
			wall_16.x = 830;
			wall_16.y = 550;
			wall_16.w = 500;
			wall_16.h = 50;

			SDL_Rect wall_17;
			wall_17.x = 0*7;
			wall_17.y = 0*4;
			wall_17.w = 0*1;
			wall_17.h = 0*3;

			SDL_Rect wall_18;
			wall_18.x = 0*8;
			wall_18.y = 0*8;
			wall_18.w = 0*1;
			wall_18.h = 0*1;

			SDL_Rect wall_19;
			wall_19.x = 0*9;
			wall_19.y = 0*1;
			wall_19.w = 0;
			wall_19.h = 0;

			SDL_Rect wall_20;
			wall_20.x = 0*9;
			wall_20.y = 0*6;
			wall_20.w = 0;
			wall_20.h = 0;

			SDL_Rect wall_21;
			wall_21.x = 0*10;
			wall_21.y = 0*2;
			wall_21.w = 0;
			wall_21.h = 0;

			SDL_Rect wall_22;
			wall_22.x = 0*10;
			wall_22.y = 0*8;
			wall_22.w = 0;
			wall_22.h = 0;

			SDL_Rect wall_23;
			wall_23.x = 0*11;
			wall_23.y = 0*3;
			wall_23.w = 0;
			wall_23.h = 0;

			SDL_Rect wall_24;
			wall_24.x = 0*11;
			wall_24.y = 0*5;
			wall_24.w = 0;
			wall_24.h = 0;

			SDL_Rect wall_25;
			wall_25.x = 0*11;
			wall_25.y = 0*7;
			wall_25.w = 0;
			wall_25.h = 0;

			SDL_Rect wall_26;
			wall_26.x = 0*11;
			wall_26.y = 0*9;
			wall_26.w = 0;
			wall_26.h = 0;

			SDL_Rect wall_27;
			wall_27.x = 91*12;
			wall_27.y = 96*0;
			wall_27.w = 0;
			wall_27.h = 0;

			SDL_Rect wall_28;
			wall_28.x = 0*12;
			wall_28.y = 0*2;
			wall_28.w = 0;
			wall_28.h = 0;

			SDL_Rect wall_29;
			wall_29.x = 0*13;
			wall_29.y = 0*5;
			wall_29.w = 0;
			wall_29.h = 0;

			SDL_Rect wall_30;
			wall_30.x = 0*13;
			wall_30.y = 0;
			wall_30.w = 0;
			wall_30.h = 0;

		int points=0; 
		int msc=0;

		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}
					// pause
					if(d.key.keysym.scancode==SDL_SCANCODE_P){
						pause_level=level;
						pause_coin=total_coin;
						Mix_PlayMusic( gMusic3, -1 );

						goto Main_Menu;
					} 

					//music control
					if(d.key.keysym.scancode==SDL_SCANCODE_M) Mix_HaltMusic();
					

					player.handleEvent( d );	//Handle input for the dot

					
				}
			//cout<<mPosX<<" "<<mPosY<<endl;if(mPosX>=0 && mPosX<=WINDOW_WIDTH) mPosX+=5;
			//moving enemy 
				enemy1_position.y= (int) y_pos1;
				enemy2_position.x= (int) x_pos2;
				enemy3_position.y= (int) y_pos3;
				enemy4_position.x= (int) x_pos4;
				enemy5_position.y= (int) y_pos5;
				
			//Move the dot and check collision
				player.move( wall_1,wall_2,wall_3,wall_4,wall_5,wall_6,wall_7,wall_8,wall_9,wall_10,wall_11,wall_12,wall_13,wall_14,wall_15,
				wall_16,wall_17,wall_18,wall_19,wall_20,wall_21,wall_22,wall_23,wall_24,wall_25,wall_26,wall_27,wall_28,wall_29,wall_30 );

				
			//collission with enemy
				if(  mPosX >= (enemy1_position.x-enemy1_position.w) && mPosX <= (enemy1_position.x+enemy1_position.w) && mPosY>=(enemy1_position.y - enemy1_position.h) && mPosY<=(enemy1_position.y + enemy1_position.h) && enemy1_position.w!=0 ) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy1_position.w=0;
						enemy1_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;	
				}


				if( enemy2_position.w!=0 && mPosY >= (enemy2_position.y-enemy2_position.h) && mPosY <=(enemy2_position.y + enemy2_position.h) 
				&& mPosX >=(enemy2_position.x - enemy2_position.w) && mPosX <=(enemy2_position.x + enemy2_position.w)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy2_position.w=0;
						enemy2_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy3_position.w!=0 &&  mPosX >= (enemy3_position.x-enemy3_position.w) && mPosX <= (enemy3_position.x+enemy3_position.w) 
				&& mPosY>=(enemy3_position.y - enemy3_position.h) && mPosY<=(enemy3_position.y + enemy3_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy3_position.w=0;
						enemy3_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy4_position.w!=0 &&  mPosX >= (enemy4_position.x-enemy4_position.w) && mPosX <= (enemy4_position.x+enemy4_position.w) 
				&& mPosY>=(enemy4_position.y - enemy4_position.h) && mPosY<=(enemy4_position.y + enemy4_position.h)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy4_position.w=0;
						enemy4_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  enemy5_position.w!=0 &&  mPosX >= (enemy5_position.x-enemy5_position.w) && mPosX <= (enemy5_position.x+enemy5_position.w) 
				&& mPosY>=(enemy5_position.y - enemy5_position.h) && mPosY<=(enemy5_position.y + enemy5_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy5_position.w=0;
						enemy5_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				
				//collide with Specialcoin

                if(  mPosX >= (Specialcoin_position.x-Specialcoin_position.w) && mPosX <= (Specialcoin_position.x+Specialcoin_position.w) 
				&& mPosY>=(Specialcoin_position.y - Specialcoin_position.h) && mPosY<=(Specialcoin_position.y + Specialcoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						Specialcoin_position.w=0;
						Specialcoin_position.h=0; 
						SpecialcoinB = true;

						gPlayerTexture.loadFromFile( "pac2.png" );

						collissionpixcount = 0;

				} 

				//collide with supercoin

                if(  mPosX >= (supercoin_position.x-supercoin_position.w) && mPosX <= (supercoin_position.x+supercoin_position.w) 
				&& mPosY>=(supercoin_position.y - supercoin_position.h) && mPosY<=(supercoin_position.y + supercoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						supercoin_position.x=0;
						supercoin_position.y=0; 
						supercoinB = true;			

						collissionpixcount = 0;

				} 


				//Collide with Coin

				if(  mPosX >= (ccoin1_position.x-ccoin1_position.w) && mPosX <= (ccoin1_position.x+ccoin1_position.w) 
				&& mPosY>=(ccoin1_position.y - ccoin1_position.h) && mPosY<=(ccoin1_position.y + ccoin1_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin1_position.w=0;ccoin1_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin2_position.x-ccoin2_position.w) && mPosX <= (ccoin2_position.x+ccoin2_position.w) 
				&& mPosY>=(ccoin2_position.y - ccoin2_position.h) && mPosY<=(ccoin2_position.y + ccoin2_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin2_position.w=0;ccoin2_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin3_position.x-ccoin3_position.w) && mPosX <= (ccoin3_position.x+ccoin3_position.w) 
				&& mPosY>=(ccoin3_position.y - ccoin3_position.h) && mPosY<=(ccoin3_position.y + ccoin3_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin3_position.w=0;ccoin3_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin4_position.x-ccoin4_position.w) && mPosX <= (ccoin4_position.x+ccoin4_position.w) 
				&& mPosY>=(ccoin4_position.y - ccoin4_position.h) && mPosY<=(ccoin4_position.y + ccoin4_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin4_position.w=0;ccoin4_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin5_position.x-ccoin5_position.w) && mPosX <= (ccoin5_position.x+ccoin5_position.w) 
				&& mPosY>=(ccoin5_position.y - ccoin5_position.h) && mPosY<=(ccoin5_position.y + ccoin5_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin5_position.w=0;ccoin5_position.h=0; ++points;cout<<points<<endl;
				}

				if((  mPosX >= (door_position.x-door_position.w) && mPosX <= (door_position.x+door_position.w) 
				&& mPosY>=(door_position.y - door_position.h) && mPosY<=(door_position.y + door_position.h)) && points == 5){
						Mix_PlayChannel( -1, levelup, 0 );puts("Level 1 Upgraded");++level;total_coin+=points;if(supercoinB) total_coin+=5; goto LEVEL;
				} 

			//points


			//Points Print in level											
				
				LastDigit = ((points+total_coin) % 10);

				switch( LastDigit )
        		{
        		case 0 : pointsP = IMG_Load("0.jpg"); break;									
        		case 1 : pointsP = IMG_Load("1.jpg"); break;									
        		case 2 : pointsP = IMG_Load("2.jpg"); break;
        		case 3 : pointsP = IMG_Load("3.jpg"); break;
        		case 4 : pointsP = IMG_Load("4.jpg"); break;
        		case 5 : pointsP = IMG_Load("5.jpg"); break;
        		case 6 : pointsP = IMG_Load("6.png"); break;
        		case 7 : pointsP = IMG_Load("7.jpg"); break;
        		case 8 : pointsP = IMG_Load("8.jpg"); break;
        		case 9 : pointsP = IMG_Load("9.jpg"); break;
        		}

				pointsP_tex = SDL_CreateTextureFromSurface(renderer,pointsP);
				SDL_FreeSurface(pointsP);

        		SDL_Rect pointsP_position;
				pointsP_position.x = 1250 ;
				pointsP_position.y = 0 ;
				pointsP_position.w = 30;
				pointsP_position.h = 30;

			//2nd digit
				
				switch( ((points+total_coin)/10) )
        		{
        		case 0 : pointsP2 = IMG_Load("0.jpg"); break;									
        		case 1 : pointsP2 = IMG_Load("1.jpg"); break;									
        		case 2 : pointsP2 = IMG_Load("2.jpg"); break;
        		case 3 : pointsP2 = IMG_Load("3.jpg"); break;
				case 4 : pointsP2 = IMG_Load("4.jpg"); break;
        		}

				pointsP2_tex = SDL_CreateTextureFromSurface(renderer,pointsP2);
				SDL_FreeSurface(pointsP2);

        		SDL_Rect pointsP2_position;
				pointsP2_position.x = 1220;
				pointsP2_position.y = 0;
				pointsP2_position.w = 30;
				pointsP2_position.h = 30;




				 


				//Clear screen
				SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
				SDL_RenderClear( renderer );


				//Render wall
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_1 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_2 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_3 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_4 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_5 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_6 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_7 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_8 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_9 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_10 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_11 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_12 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_13 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_14 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_15 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_16 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_17 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_18 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_19 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_20 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_21 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_22 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_23 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_24 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_25 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_26 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_27 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_28 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_29 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_30 );



				//Rendering objects
				player.render();
				//Rendering enemy
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy1_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy2_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy3_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy4_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy5_position);
				
				//Rendering pointsP
                SDL_RenderCopy(renderer,pointsP_tex,NULL,&pointsP_position);
				SDL_RenderCopy(renderer,pointsP2_tex,NULL,&pointsP2_position);


				//Rendering Specialcoin
                SDL_RenderCopy(renderer,Specialcoin_tex,NULL,&Specialcoin_position);

				//Rendering supercoin
                SDL_RenderCopy(renderer,supercoin_tex,NULL,&supercoin_position);


				//Rendering coin
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin1_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin2_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin3_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin4_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin5_position);

				//Rendering door
				SDL_RenderCopy(renderer,door_tex,NULL,&door_position);
				
				 
				//Update screen
				SDL_RenderPresent( renderer );
				

				y_pos1 += (float) direction1 * 5;	//printf("%f\n",y_pos1);
	 			if(y_pos1 == 455 || y_pos1 == 715) direction1 *= -1;

				x_pos2 += (float) direction2 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos2 == 170 || x_pos2 == 520) direction2 *= -1;

				y_pos3 += (float) direction3 * 5;	//printf("%f\n",x_pos2);
	 			if(y_pos3 == 0 || y_pos3 == 440) direction3 *= -1;

				x_pos4 += (float) direction4 * 5;	//printf("%f\n",x_pos4);
	 			if(x_pos4 == 630 || x_pos4 == 1070) direction4 *= -1;

				y_pos5 += (float) direction5 * 5;	//printf("%f\n",x_pos2);
	 			if(y_pos5 == 490 || y_pos5 == 680) direction5 *= -1;
				
		}	

		close();
	}




///////////////////////////////////temporary////////////////////////////////////


	if(level==2){
		load =IMG_Load("loading.jpg");
		load_tex = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex,NULL,NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(300);

		load =IMG_Load("loading.gif");
		load_tex1 = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_Rect load_position;
		load_position.x = 550;
		load_position.y = 600;
		load_position.w = 150;
		load_position.h = 150;
		//SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex1,NULL,&load_position);
		SDL_RenderPresent(renderer);
		SDL_Delay(500);
		gPlayerTexture.loadFromFile( "pac.png" );
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Event handler
		Player2 player;	//The dot that will be moving around on the screen
		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}
					player.handleEvent( d );	//Handle input for the dot
					
					
				}
		//Move the dot and check collision
		player.move();
		if(total_coin>=1){
				++level; goto LEVEL;
			} 

		//Clear screen
		SDL_SetRenderDrawColor( renderer, 47, 79, 79, 79 );
		SDL_RenderClear( renderer );
		//Rendering objects
		player.render();
		//Update screen
		SDL_RenderPresent( renderer );
		}	
	close();
	}


///////////////////////////////////temporary////////////////////////////////////	






	//////////////////////**************LEVEL22222222222****************////////////////
	//////////////////////**************LEVEL22222222222****************////////////////
	//////////////////////**************LEVEL22222222222****************////////////////

	
	if(level==3){
		
		Mix_PlayMusic( gMusic1, -1 );		// playing music

		door =IMG_Load("Door.png");
		door_tex = SDL_CreateTextureFromSurface(renderer,door);
		SDL_FreeSurface(door);
		
		SDL_Rect door_position;
		door_position.x = 665;
		door_position.y = 450;
		door_position.w = 30;
		door_position.h = 30;



	//Special Coin
        bool SpecialcoinB = false;
        Specialcoin = IMG_Load("Specialcoin.png");
		Specialcoin_tex = SDL_CreateTextureFromSurface(renderer,Specialcoin);
		SDL_FreeSurface(Specialcoin);

        SDL_Rect Specialcoin_position;
		Specialcoin_position.x = 20 + 160 * (rand() % 2);
		Specialcoin_position.y = 820;
		Specialcoin_position.w = 30;
		Specialcoin_position.h = 30;


	//Supercoin(sword)
		bool supercoinB = false;
        supercoin = IMG_Load("supercoin.png");
		supercoin_tex = SDL_CreateTextureFromSurface(renderer,supercoin);
		SDL_FreeSurface(supercoin);

        SDL_Rect supercoin_position;
		supercoin_position.x = 40+ 400 * (rand() % 2);
		supercoin_position.y = 40+ 888 * (rand() % 2);
		supercoin_position.w = 30;
		supercoin_position.h = 30;


		

	// NON-Special COIN
		ccoin =IMG_Load("coin.png");
		ccoin_tex = SDL_CreateTextureFromSurface(renderer,ccoin);
		SDL_FreeSurface(ccoin);

		SDL_Rect ccoin1_position;
		ccoin1_position.x = 10 + 160 * (rand() % 2);
		ccoin1_position.y = 440;
		ccoin1_position.w = 20;
		ccoin1_position.h = 20;

		SDL_Rect ccoin2_position;
		ccoin2_position.x = 500 + 80 * (rand() % 3);
		ccoin2_position.y = 400;
		ccoin2_position.w = 20;
		ccoin2_position.h = 20;

		SDL_Rect ccoin3_position;
		ccoin3_position.x = 570 + 160 * (rand() % 3);
		ccoin3_position.y = 85;
		ccoin3_position.w = 20;
		ccoin3_position.h = 20;

		SDL_Rect ccoin4_position;
		ccoin4_position.x = 1050;
		ccoin4_position.y = 30 + 80 * (rand() % 2);
		ccoin4_position.w = 20;
		ccoin4_position.h = 20;

		SDL_Rect ccoin5_position;
		ccoin5_position.x = 650 - 3* 80 * (rand() % 2);
		ccoin5_position.y = 730;
		ccoin5_position.w = 20;
		ccoin5_position.h = 20;

		SDL_Rect ccoin6_position;
		ccoin6_position.x = 900 + 160 * (rand() % 2);
		ccoin6_position.y = 650+ 80 * (rand() % 2);
		ccoin6_position.w = 20;
		ccoin6_position.h = 20;

		SDL_Rect ccoin7_position;
		ccoin7_position.x = 1050 + 160 * (rand() % 2);
		ccoin7_position.y = 920 ;
		ccoin7_position.w = 20;
		ccoin7_position.h = 20;


		enemy =IMG_Load("enemy.png");
		enemy_tex = SDL_CreateTextureFromSurface(renderer,enemy);
		SDL_FreeSurface(enemy);
		SDL_Rect enemy1_position;
		enemy1_position.x = 0;
		enemy1_position.y = 365;
		enemy1_position.w = 30;
		enemy1_position.h = 30;


		SDL_Rect enemy2_position;
		enemy2_position.x = 565;
		enemy2_position.y = 85;
		enemy2_position.w = 30;
		enemy2_position.h = 30;

		SDL_Rect enemy3_position;
		enemy3_position.x = 565;
		enemy3_position.y = 150;
		enemy3_position.w = 30;
		enemy3_position.h = 30;

		SDL_Rect enemy4_position;
		enemy4_position.x = 880;
		enemy4_position.y = 700;
		enemy4_position.w = 30;
		enemy4_position.h = 30;

		SDL_Rect enemy5_position;
		enemy5_position.x = 320;
		enemy5_position.y = 400;
		enemy5_position.w = 30;
		enemy5_position.h = 30;

		float x_pos1 = 0;
 		int direction1 = 1;

		float x_pos2 = 565;
 		int direction2 = 1;

		float y_pos3 = 150;
 		int direction3 = 1;

		float x_pos4 = 880;
 		int direction4 = 1;

		float x_pos5 = 320;
 		int direction5 = 1;

		


		
		gPlayerTexture.loadFromFile( "pac.png" );
		
		
		
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Event handler
		Player player;	//The dot that will be moving around on the screen
		
			//Set the wall

			SDL_Rect wall_1;
			wall_1.x = 80*0;
			wall_1.y = 80*0;
			wall_1.w = 80*0;
			wall_1.h = 80*0;

			SDL_Rect wall_2;
			wall_2.x = 80*0;
			wall_2.y = 80*3;
			wall_2.w = 80*3;
			wall_2.h = 80*1;

			SDL_Rect wall_3;
			wall_3.x = 80*0;
			wall_3.y = 80*6;
			wall_3.w = 80*1;
			wall_3.h = 80*4;

			SDL_Rect wall_4;
			wall_4.x = 80*1;
			wall_4.y = 80*5;
			wall_4.w = 80*1;
			wall_4.h = 80*6;

			SDL_Rect wall_5;
			wall_5.x = 80*3;
			wall_5.y = 80*2;
			wall_5.w = 80*1;
			wall_5.h = 80*9;

			SDL_Rect wall_6;
			wall_6.x = 80*6;
			wall_6.y = 80*1;
			wall_6.w = 80*1;
			wall_6.h = 80*4;

			SDL_Rect wall_7;
			wall_7.x = 80*6;
			wall_7.y = 80*6;
			wall_7.w = 80*1;
			wall_7.h = 80*5;

			SDL_Rect wall_8;
			wall_8.x = 80*5;
			wall_8.y = 80*11;
			wall_8.w = 80*2;
			wall_8.h = 80*1;

			SDL_Rect wall_9;
			wall_9.x = 80*8;
			wall_9.y = 80*2;
			wall_9.w = 80*1;
			wall_9.h = 80*3;

			SDL_Rect wall_10;
			wall_10.x = 80*8;
			wall_10.y = 80*6;
			wall_10.w = 80*1;
			wall_10.h = 80*3;

			SDL_Rect wall_11;
			wall_11.x = 80*11;
			wall_11.y = 80*2;
			wall_11.w = 80*4;
			wall_11.h = 80*1;

			SDL_Rect wall_12;
			wall_12.x = 80*11;
			wall_12.y = 80*4;
			wall_12.w = 80*1;
			wall_12.h = 80*3;

			SDL_Rect wall_13;
			wall_13.x = 80*10;
			wall_13.y = 80*7;
			wall_13.w = 80*4;
			wall_13.h = 80*1;

			SDL_Rect wall_14;
			wall_14.x = 80*10;
			wall_14.y = 80*8;
			wall_14.w = 80*1;
			wall_14.h = 80*2;

			SDL_Rect wall_15;
			wall_15.x = 80*10;
			wall_15.y = 80*10;
			wall_15.w = 80*3;
			wall_15.h = 80*2;

			SDL_Rect wall_16;
			wall_16.x = 80*15;
			wall_16.y = 80*1;
			wall_16.w = 80*1;
			wall_16.h = 80*9;
 
            SDL_Rect wall_17;
         	wall_17.x = 80*2;
         	wall_17.y = 80*0;
         	wall_17.w = 80*1;
         	wall_17.h = 80*1;
 
         	SDL_Rect wall_18;
         	wall_18.x = 80*3;
         	wall_18.y = 80*0;
         	wall_18.w = 80*1;
         	wall_18.h = 80*1;
 
         	SDL_Rect wall_19;
         	wall_19.x = 80*4;
         	wall_19.y = 80*0;
         	wall_19.w = 80*1;
         	wall_19.h = 80*1;
 
         	SDL_Rect wall_20;
         	wall_20.x = 80*5;
         	wall_20.y = 80*0;
         	wall_20.w = 80*1;
         	wall_20.h = 80*1;
 
         	SDL_Rect wall_21;
         	wall_21.x = 80*6;
         	wall_21.y = 80*0;
         	wall_21.w = 80*1;
         	wall_21.h = 80*1;
 
         	SDL_Rect wall_22;
         	wall_22.x = 80*7;
         	wall_22.y = 80*0;
         	wall_22.w = 80*1;
         	wall_22.h = 80*1;
 
         	SDL_Rect wall_23;
         	wall_23.x = 80*8;
         	wall_23.y = 80*0;
         	wall_23.w = 80*1;
         	wall_23.h = 80*1;
 
         	SDL_Rect wall_24;
         	wall_24.x = 80*9;
         	wall_24.y = 80*0;
         	wall_24.w = 80*1;
         	wall_24.h = 80*1;
 
         	SDL_Rect wall_25;
         	wall_25.x = 80*10;
        	wall_25.y = 80*0;
         	wall_25.w = 80*1;
         	wall_25.h = 80*1;
 
         	SDL_Rect wall_26;
         	wall_26.x = 80*11;
         	wall_26.y = 80*0;
         	wall_26.w = 80*1;
         	wall_26.h = 80*1;
 
         	SDL_Rect wall_27;
         	wall_27.x = 80*12;
         	wall_27.y = 80*0;
         	wall_27.w = 80*1;
         	wall_27.h = 80*1;
 
         	SDL_Rect wall_28;
         	wall_28.x = 80*13;
         	wall_28.y = 80*0;
         	wall_28.w = 80*1;
         	wall_28.h = 80*0;

         	SDL_Rect wall_29;
         	wall_29.x = 80*14;
         	wall_29.y = 80*0;
         	wall_29.w = 80*1;
         	wall_29.h = 80*1;
 
         	SDL_Rect wall_30;
         	wall_30.x = 80*15;
         	wall_30.y = 80*0;
         	wall_30.w = 80*1;
         	wall_30.h = 80*1;

int points=0; 

		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}

					if(d.key.keysym.scancode==SDL_SCANCODE_P){
						pause_level=level;
						pause_coin=total_coin;
						Mix_PlayMusic( gMusic3, -1 );
						goto Main_Menu;
					} 

					if(d.key.keysym.scancode==SDL_SCANCODE_M) Mix_HaltMusic();

					player.handleEvent( d );	//Handle input for the dot
					
					
				}
				
				//moving enemy 
				enemy1_position.x= (int) x_pos1;
				enemy2_position.x= (int) x_pos2;
				enemy3_position.y= (int) y_pos3;
				enemy4_position.x= (int) x_pos4;
				enemy5_position.x= (int) x_pos5;
				

				//Move the dot and check collision
				player.move( wall_1,wall_2,wall_3,wall_4,wall_5,wall_6,wall_7,wall_8,wall_9,wall_10,wall_11,wall_12,wall_13,wall_14,wall_15,
				wall_16,wall_17,wall_18,wall_19,wall_20,wall_21,wall_22,wall_23,wall_24,wall_25,wall_26,wall_27,wall_28,wall_29,wall_30 );
				
				//collission with enemy
				if(  mPosX >= (enemy1_position.x-enemy1_position.w) && mPosX <= (enemy1_position.x+enemy1_position.w) && mPosY>=(enemy1_position.y - enemy1_position.h) && mPosY<=(enemy1_position.y + enemy1_position.h) && enemy1_position.w!=0 ) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy1_position.w=0;
						enemy1_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;	
				}

				if( enemy2_position.w!=0 && mPosY >= (enemy2_position.y-enemy2_position.h) && mPosY <=(enemy2_position.y + enemy2_position.h) 
				&& mPosX >=(enemy2_position.x - enemy2_position.w) && mPosX <=(enemy2_position.x + enemy2_position.w)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy2_position.w=0;
						enemy2_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy3_position.w!=0 &&  mPosX >= (enemy3_position.x-enemy3_position.w) && mPosX <= (enemy3_position.x+enemy3_position.w) 
				&& mPosY>=(enemy3_position.y - enemy3_position.h) && mPosY<=(enemy3_position.y + enemy3_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy3_position.w=0;
						enemy3_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy4_position.w!=0 &&  mPosX >= (enemy4_position.x-enemy4_position.w) && mPosX <= (enemy4_position.x+enemy4_position.w) 
				&& mPosY>=(enemy4_position.y - enemy4_position.h) && mPosY<=(enemy4_position.y + enemy4_position.h)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy4_position.w=0;
						enemy4_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  enemy5_position.w!=0 &&  mPosX >= (enemy5_position.x-enemy5_position.w) && mPosX <= (enemy5_position.x+enemy5_position.w) 
				&& mPosY>=(enemy5_position.y - enemy5_position.h) && mPosY<=(enemy5_position.y + enemy5_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy5_position.w=0;
						enemy5_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

			//collide with Specialcoin

                if(  mPosX >= (Specialcoin_position.x-Specialcoin_position.w) && mPosX <= (Specialcoin_position.x+Specialcoin_position.w) 
				&& mPosY>=(Specialcoin_position.y - Specialcoin_position.h) && mPosY<=(Specialcoin_position.y + Specialcoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						Specialcoin_position.w=0;
						Specialcoin_position.h=0; 
						SpecialcoinB = true;

						gPlayerTexture.loadFromFile( "pac2.png" );

						collissionpixcount = 0;

				} 

				
			//collide with supercoin

                if(  mPosX >= (supercoin_position.x-supercoin_position.w) && mPosX <= (supercoin_position.x+supercoin_position.w) 
				&& mPosY>=(supercoin_position.y - supercoin_position.h) && mPosY<=(supercoin_position.y + supercoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						supercoin_position.x=0;
						supercoin_position.y=0; 
						supercoinB = true;			

						collissionpixcount = 0;

				} 




			//Collide with Coin

				if(  mPosX >= (ccoin1_position.x-ccoin1_position.w) && mPosX <= (ccoin1_position.x+ccoin1_position.w) 
				&& mPosY>=(ccoin1_position.y - ccoin1_position.h) && mPosY<=(ccoin1_position.y + ccoin1_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin1_position.w=0;ccoin1_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin2_position.x-ccoin2_position.w) && mPosX <= (ccoin2_position.x+ccoin2_position.w) 
				&& mPosY>=(ccoin2_position.y - ccoin2_position.h) && mPosY<=(ccoin2_position.y + ccoin2_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin2_position.w=0;ccoin2_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin3_position.x-ccoin3_position.w) && mPosX <= (ccoin3_position.x+ccoin3_position.w) 
				&& mPosY>=(ccoin3_position.y - ccoin3_position.h) && mPosY<=(ccoin3_position.y + ccoin3_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin3_position.w=0;ccoin3_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin4_position.x-ccoin4_position.w) && mPosX <= (ccoin4_position.x+ccoin4_position.w) 
				&& mPosY>=(ccoin4_position.y - ccoin4_position.h) && mPosY<=(ccoin4_position.y + ccoin4_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin4_position.w=0;ccoin4_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin5_position.x-ccoin5_position.w) && mPosX <= (ccoin5_position.x+ccoin5_position.w) 
				&& mPosY>=(ccoin5_position.y - ccoin5_position.h) && mPosY<=(ccoin5_position.y + ccoin5_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin5_position.w=0;ccoin5_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin6_position.x-ccoin6_position.w) && mPosX <= (ccoin6_position.x+ccoin6_position.w) 
				&& mPosY>=(ccoin6_position.y - ccoin6_position.h) && mPosY<=(ccoin6_position.y + ccoin6_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin6_position.w=0;ccoin6_position.h=0; ++points;cout<<points<<endl;
				}

				if(  mPosX >= (ccoin7_position.x-ccoin7_position.w) && mPosX <= (ccoin7_position.x+ccoin7_position.w) 
				&& mPosY>=(ccoin7_position.y - ccoin7_position.h) && mPosY<=(ccoin7_position.y + ccoin7_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin7_position.w=0;ccoin7_position.h=0; ++points;cout<<points<<endl;
				}

				if((  mPosX >= (door_position.x-door_position.w) && mPosX <= (door_position.x+door_position.w) 
				&& mPosY>=(door_position.y - door_position.h) && mPosY<=(door_position.y + door_position.h)) && points == 7){
						Mix_PlayChannel( -1, levelup, 0 );puts("Level 2 Upgraded");++level;total_coin+=points;if(supercoinB) total_coin+=5; goto LEVEL;
				} 



					
			//Points Print in level											
				
				LastDigit = ((points+total_coin) % 10);

				switch( LastDigit )
        		{
        		case 0 : pointsP = IMG_Load("0.jpg"); break;									

        		case 1 : pointsP = IMG_Load("1.jpg"); break;									
					
        		case 2 : pointsP = IMG_Load("2.jpg"); break;

        		case 3 : pointsP = IMG_Load("3.jpg"); break;

        		case 4 : pointsP = IMG_Load("4.jpg"); break;

        		case 5 : pointsP = IMG_Load("5.jpg"); 
					pointsP2 = IMG_Load("1.jpg");break;

        		case 6 : pointsP = IMG_Load("6.png"); break;

        		case 7 : pointsP = IMG_Load("7.jpg"); break;

        		case 8 : pointsP = IMG_Load("8.jpg"); break;

        		case 9 : pointsP = IMG_Load("9.jpg"); break;

        		}

				pointsP_tex = SDL_CreateTextureFromSurface(renderer,pointsP);
				SDL_FreeSurface(pointsP);

        		SDL_Rect pointsP_position;
				pointsP_position.x = 1250 ;
				pointsP_position.y = 0 ;
				pointsP_position.w = 30;
				pointsP_position.h = 30;

			
				//2nd digit
				
				switch( ((points+total_coin)/10) )
        		{
        		case 0 : pointsP2 = IMG_Load("0.jpg"); break;									
        		case 1 : pointsP2 = IMG_Load("1.jpg"); break;									
        		case 2 : pointsP2 = IMG_Load("2.jpg"); break;
        		case 3 : pointsP2 = IMG_Load("3.jpg"); break;
				case 4 : pointsP2 = IMG_Load("4.jpg"); break;
        		}

				pointsP2_tex = SDL_CreateTextureFromSurface(renderer,pointsP2);
				SDL_FreeSurface(pointsP2);

        		SDL_Rect pointsP2_position;
				pointsP2_position.x = 1220;
				pointsP2_position.y = 0;
				pointsP2_position.w = 30;
				pointsP2_position.h = 30;






				//Clear screen
				SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
				SDL_RenderClear( renderer );


				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_1 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_2 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_3 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_4 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_5 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_6 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_7 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_8 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_9 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_10 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_11 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_12 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_13 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_14 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_15 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_16 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_17 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_18 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_19 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_20 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_21 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_22 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_23 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_24 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_25 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_26 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_27 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_28 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_29 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_30 );



				//Rendering objects
				player.render();
				//Rendering enemy
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy1_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy2_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy3_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy4_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy5_position);

				//Rendering pointsP
                SDL_RenderCopy(renderer,pointsP_tex,NULL,&pointsP_position);
				SDL_RenderCopy(renderer,pointsP2_tex,NULL,&pointsP2_position);
				
				//Rendering Specialcoin
                SDL_RenderCopy(renderer,Specialcoin_tex,NULL,&Specialcoin_position);

				//Rendering supercoin
                SDL_RenderCopy(renderer,supercoin_tex,NULL,&supercoin_position);

				//Rendering coin
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin1_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin2_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin3_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin4_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin5_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin6_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin7_position);

				//Rendering door
				SDL_RenderCopy(renderer,door_tex,NULL,&door_position);
				
				 
				//Update screen
				SDL_RenderPresent( renderer );
				

				x_pos1 += (float) direction1 * 5;	//printf("%f\n",y_pos1);
	 			if(x_pos1 == 0 || x_pos1 == 210) direction1 *= -1;

				x_pos2 += (float) direction2 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos2 == 565 || x_pos2 == 1100) direction2 *= -1;

				y_pos3 += (float) direction3 * 5;	//printf("%f\n",x_pos2);
	 			if(y_pos3 == 150 || y_pos3 == 750) direction3 *= -1;

				x_pos4 += (float) direction4 * 5;	//printf("%f\n",x_pos4);
	 			if(x_pos4 == 880 || x_pos4 == 1180) direction4 *= -1;

				x_pos5 += (float) direction5 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos5 == 320 || x_pos5 == 850) direction5 *= -1;
				
		}	

		close();
	}



///////////////////////////////////temporary////////////////////////////////////


	if(level==4){
		load =IMG_Load("loading.jpg");
		load_tex = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex,NULL,NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(300);

		load =IMG_Load("loading.gif");
		load_tex1 = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_Rect load_position;
		load_position.x = 550;
		load_position.y = 600;
		load_position.w = 150;
		load_position.h = 150;
		//SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex1,NULL,&load_position);
		SDL_RenderPresent(renderer);
		SDL_Delay(500);
		gPlayerTexture.loadFromFile( "pac.png" );
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Event handler
		Player2 player;	//The dot that will be moving around on the screen
		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}
					player.handleEvent( d );	//Handle input for the dot
					
					
				}
		//Move the dot and check collision
		player.move();
		if(total_coin>=1){
				++level; goto LEVEL;
			} 

		//Clear screen
		SDL_SetRenderDrawColor( renderer, 47, 79, 79, 79 );
		SDL_RenderClear( renderer );
		//Rendering objects
		player.render();
		//Update screen
		SDL_RenderPresent( renderer );
		}	
	close();
	}


///////////////////////////////////temporary////////////////////////////////////	







		//////////////////////**************LEVEL33333333333****************////////////////
		//////////////////////**************LEVEL33333333333****************////////////////
		//////////////////////**************LEVEL33333333333****************////////////////  

		if(level==5){
		
		Mix_PlayMusic( gMusic1, -1 );		// playing music

		door =IMG_Load("Door.png");
		door_tex = SDL_CreateTextureFromSurface(renderer,door);
		SDL_FreeSurface(door);
		
		SDL_Rect door_position;
		door_position.x = 1250;
		door_position.y = 930;
		door_position.w = 30;
		door_position.h = 30;

	//Special Coin
        bool SpecialcoinB = false;
        Specialcoin = IMG_Load("Specialcoin.png");
		Specialcoin_tex = SDL_CreateTextureFromSurface(renderer,Specialcoin);
		SDL_FreeSurface(Specialcoin);

        SDL_Rect Specialcoin_position;
		Specialcoin_position.x = 30 + 180 * (rand() % 2);
		Specialcoin_position.y = 820- 270 * (rand() % 2);
		Specialcoin_position.w = 30;
		Specialcoin_position.h = 30;

	//Supercoin(sword)
		bool supercoinB = false;
        supercoin = IMG_Load("supercoin.png");
		supercoin_tex = SDL_CreateTextureFromSurface(renderer,supercoin);
		SDL_FreeSurface(supercoin);

        SDL_Rect supercoin_position;
		supercoin_position.x = 480 + 190 * (rand() % 2);
		supercoin_position.y = 230 + 190 * (rand() % 2);
		supercoin_position.w = 30;
		supercoin_position.h = 30;
		

	// NON-Special COIN
		ccoin =IMG_Load("coin.png");
		ccoin_tex = SDL_CreateTextureFromSurface(renderer,ccoin);
		SDL_FreeSurface(ccoin);

		SDL_Rect ccoin1_position;
		ccoin1_position.x = 10;
		ccoin1_position.y = 420 - 95 * (rand() % 2);
		ccoin1_position.w = 20;
		ccoin1_position.h = 20;

		SDL_Rect ccoin2_position;
		ccoin2_position.x = 420  - 95 * (rand() % 2);
		ccoin2_position.y = 780;
		ccoin2_position.w = 20;
		ccoin2_position.h = 20;

		SDL_Rect ccoin3_position;
		ccoin3_position.x = 570;
		ccoin3_position.y = 100 + 95 * (rand() % 2);
		ccoin3_position.w = 20;
		ccoin3_position.h = 20;

		SDL_Rect ccoin4_position;
		ccoin4_position.x = 400;
		ccoin4_position.y = 100 + 95 * (rand() % 2);
		ccoin4_position.w = 20;
		ccoin4_position.h = 20;

		SDL_Rect ccoin5_position;
		ccoin5_position.x = 550;
		ccoin5_position.y = 580 - 120 * (rand() % 2);
		ccoin5_position.w = 20;
		ccoin5_position.h = 20;

		SDL_Rect ccoin6_position;
		ccoin6_position.x = 850 + 100 * (rand() % 2);
		ccoin6_position.y = 600;
		ccoin6_position.w = 20;
		ccoin6_position.h = 20;

		SDL_Rect ccoin7_position;
		ccoin7_position.x = 1250;
		ccoin7_position.y = 600 - 200 * (rand() % 2);
		ccoin7_position.w = 20;
		ccoin7_position.h = 20;


		enemy =IMG_Load("enemy.png");
		enemy_tex = SDL_CreateTextureFromSurface(renderer,enemy);
		SDL_FreeSurface(enemy);
		SDL_Rect enemy1_position;
		enemy1_position.x = 0;
		enemy1_position.y = 500;
		enemy1_position.w = 30;
		enemy1_position.h = 30;


		SDL_Rect enemy2_position;
		enemy2_position.x = 0;
		enemy2_position.y = 770;
		enemy2_position.w = 30;
		enemy2_position.h = 30;

		SDL_Rect enemy3_position;
		enemy3_position.x = 365;
		enemy3_position.y = 195;
		enemy3_position.w = 30;
		enemy3_position.h = 30;

		SDL_Rect enemy4_position;
		enemy4_position.x = 580;
		enemy4_position.y = 385;
		enemy4_position.w = 30;
		enemy4_position.h = 30;

		SDL_Rect enemy5_position;
		enemy5_position.x = 915;
		enemy5_position.y = 485;
		enemy5_position.w = 30;
		enemy5_position.h = 30;

		float x_pos1 = 0;
 		int direction1 = 1;

		float x_pos2 = 0;
 		int direction2 = 1;

		float x_pos3 = 365;
 		int direction3 = 1;

		float y_pos4 = 385;
 		int direction4 = 1;

		float y_pos5 = 485;
 		int direction5 = 1;

		


		
		gPlayerTexture.loadFromFile( "pac.png" );
		
		
		
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Event handler
		Player player;	//The dot that will be moving around on the screen
		
			

			//Set the wall_map3

			SDL_Rect wall_1;
			wall_1.x = 91*0;
			wall_1.y = 96*2;
			wall_1.w = 91*1;
			wall_1.h = 96*1;

			SDL_Rect wall_2;
			wall_2.x = 91*0;
			wall_2.y = 96*9;
			wall_2.w = 91*4;
			wall_2.h = 96*1;

			SDL_Rect wall_3;
			wall_3.x = 91*1;
			wall_3.y = 96*0;
			wall_3.w = 91*7;
			wall_3.h = 96*1;

			SDL_Rect wall_4;
			wall_4.x = 91*1;
			wall_4.y = 96*2;
			wall_4.w = 91*1;
			wall_4.h = 96*3;

			SDL_Rect wall_5;
			wall_5.x = 91*1;
			wall_5.y = 96*6;
			wall_5.w = 91*1;
			wall_5.h = 96*2;

			SDL_Rect wall_6;
			wall_6.x = 91*3;
			wall_6.y = 96*1;
			wall_6.w = 91*1;
			wall_6.h = 96*6;

			SDL_Rect wall_7;
			wall_7.x = 91*3;
			wall_7.y = 96*7;
			wall_7.w = 91*3;
			wall_7.h = 96*1;

			SDL_Rect wall_8;
			wall_8.x = 91*5;
			wall_8.y = 96*1;
			wall_8.w = 91;
			wall_8.h = 96*1;

			SDL_Rect wall_9;
			wall_9.x = 91*5;
			wall_9.y = 96*5;
			wall_9.w = 91*1;
			wall_9.h = 96*1;

			SDL_Rect wall_10;
			wall_10.x = 91*5;
			wall_10.y = 96*8;
			wall_10.w = 91*3;
			wall_10.h = 96*1;

			SDL_Rect wall_11;
			wall_11.x = 91*7;
			wall_11.y = 96*1;
			wall_11.w = 91*1;
			wall_11.h = 96*1;

			SDL_Rect wall_12;
			wall_12.x = 91*7;
			wall_12.y = 96*6;
			wall_12.w = 91*2;
			wall_12.h = 96*1;

			SDL_Rect wall_13;
			wall_13.x = 91*8;
			wall_13.y = 96*5;
			wall_13.w = 91*2;
			wall_13.h = 96*1;

			SDL_Rect wall_14;
			wall_14.x = 91*4;
			wall_14.y = 96*3;
			wall_14.w = 91*5;
			wall_14.h = 96*1;

			SDL_Rect wall_15;
			wall_15.x = 91*9;
			wall_15.y = 96*7;
			wall_15.w = 91*1;
			wall_15.h = 96*3;

			SDL_Rect wall_16;
			wall_16.x = 91*10;
			wall_16.y = 96*1;
			wall_16.w = 91;
			wall_16.h = 96;

			SDL_Rect wall_17;
			wall_17.x = 91*11;
			wall_17.y = 96*3;
			wall_17.w = 91*2;
			wall_17.h = 96*1;

			SDL_Rect wall_18;
			wall_18.x = 91*11;
			wall_18.y = 96*6;
			wall_18.w = 91*1;
			wall_18.h = 96*1;

			SDL_Rect wall_19;
			wall_19.x = 91*11;
			wall_19.y = 96*8;
			wall_19.w = 91;
			wall_19.h = 96;

			SDL_Rect wall_20;
			wall_20.x = 91*12;
			wall_20.y = 0;
			wall_20.w = 91;
			wall_20.h = 96;

			SDL_Rect wall_21;
			wall_21.x = 91*13;
			wall_21.y = 96*5;
			wall_21.w = 91+6;
			wall_21.h = 96;

			SDL_Rect wall_22;
			wall_22.x = 91*10;
			wall_22.y = 96*2;
			wall_22.w = 91;
			wall_22.h = 96;

			SDL_Rect wall_23;
			wall_23.x = 91*10;
			wall_23.y = 96*3;
			wall_23.w = 91;
			wall_23.h = 96;

			SDL_Rect wall_24;
			wall_24.x = 91*10;
			wall_24.y = 96*4;
			wall_24.w = 91;
			wall_24.h = 96;

			SDL_Rect wall_25;
			wall_25.x = 91*13;
			wall_25.y = 0;
			wall_25.w = 91+6;
			wall_25.h = 96;

			SDL_Rect wall_26;
			wall_26.x = 91*12;
			wall_26.y = 96*1;
			wall_26.w = 91;
			wall_26.h = 96;

			SDL_Rect wall_27;
			wall_27.x = 91*13;
			wall_27.y = 96*1;
			wall_27.w = 91+6;
			wall_27.h = 96;

			SDL_Rect wall_28;
			wall_28.x = 91*12;
			wall_28.y = 96*8;
			wall_28.w = 91;
			wall_28.h = 96;

			SDL_Rect wall_29;
			wall_29.x = 91*13;
			wall_29.y = 96*7;
			wall_29.w = 91+6;
			wall_29.h = 96;

			SDL_Rect wall_30;
			wall_30.x = 91*13;
			wall_30.y = 96*8;
			wall_30.w = 91+6;
			wall_30.h = 96;


int points=0; 

		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}

					if(d.key.keysym.scancode==SDL_SCANCODE_P){
						pause_level=level;
						pause_coin=total_coin;
						Mix_PlayMusic( gMusic3, -1 );
						goto Main_Menu;
					}
					if(d.key.keysym.scancode==SDL_SCANCODE_M) Mix_HaltMusic();

					player.handleEvent( d );	//Handle input for the dot
					
					
				}
				//moving enemy 
				enemy1_position.x= (int) x_pos1;
				enemy2_position.x= (int) x_pos2;
				enemy3_position.x= (int) x_pos3;
				enemy4_position.y= (int) y_pos4;
				enemy5_position.y= (int) y_pos5;
				

				//Move the dot and check collision
				player.move( wall_1,wall_2,wall_3,wall_4,wall_5,wall_6,wall_7,wall_8,wall_9,wall_10,wall_11,wall_12,wall_13,wall_14,wall_15,
				wall_16,wall_17,wall_18,wall_19,wall_20,wall_21,wall_22,wall_23,wall_24,wall_25,wall_26,wall_27,wall_28,wall_29,wall_30 );
				
				//collission with enemy
				if(  mPosX >= (enemy1_position.x-enemy1_position.w) && mPosX <= (enemy1_position.x+enemy1_position.w) && mPosY>=(enemy1_position.y - enemy1_position.h) && mPosY<=(enemy1_position.y + enemy1_position.h) && enemy1_position.w!=0 ) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy1_position.w=0;
						enemy1_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;	
				}

				if( enemy2_position.w!=0 && mPosY >= (enemy2_position.y-enemy2_position.h) && mPosY <=(enemy2_position.y + enemy2_position.h) 
				&& mPosX >=(enemy2_position.x - enemy2_position.w) && mPosX <=(enemy2_position.x + enemy2_position.w)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy2_position.w=0;
						enemy2_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy3_position.w!=0 &&  mPosX >= (enemy3_position.x-enemy3_position.w) && mPosX <= (enemy3_position.x+enemy3_position.w) 
				&& mPosY>=(enemy3_position.y - enemy3_position.h) && mPosY<=(enemy3_position.y + enemy3_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy3_position.w=0;
						enemy3_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy4_position.w!=0 &&  mPosX >= (enemy4_position.x-enemy4_position.w) && mPosX <= (enemy4_position.x+enemy4_position.w) 
				&& mPosY>=(enemy4_position.y - enemy4_position.h) && mPosY<=(enemy4_position.y + enemy4_position.h)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy4_position.w=0;
						enemy4_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  enemy5_position.w!=0 &&  mPosX >= (enemy5_position.x-enemy5_position.w) && mPosX <= (enemy5_position.x+enemy5_position.w) 
				&& mPosY>=(enemy5_position.y - enemy5_position.h) && mPosY<=(enemy5_position.y + enemy5_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy5_position.w=0;
						enemy5_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}
			//collide with Specialcoin

                if(  mPosX >= (Specialcoin_position.x-Specialcoin_position.w) && mPosX <= (Specialcoin_position.x+Specialcoin_position.w) 
				&& mPosY>=(Specialcoin_position.y - Specialcoin_position.h) && mPosY<=(Specialcoin_position.y + Specialcoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						Specialcoin_position.w=0;
						Specialcoin_position.h=0; 
						SpecialcoinB = true;

						gPlayerTexture.loadFromFile( "pac2.png" );

						collissionpixcount = 0;

				} 
			
			//collide with supercoin

                if(  mPosX >= (supercoin_position.x-supercoin_position.w) && mPosX <= (supercoin_position.x+supercoin_position.w) 
				&& mPosY>=(supercoin_position.y - supercoin_position.h) && mPosY<=(supercoin_position.y + supercoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						supercoin_position.x=0;
						supercoin_position.y=0; 
						supercoinB = true;			

						collissionpixcount = 0;

				} 				


			//Collide with Coin

				if(  mPosX >= (ccoin1_position.x-ccoin1_position.w) && mPosX <= (ccoin1_position.x+ccoin1_position.w) 
				&& mPosY>=(ccoin1_position.y - ccoin1_position.h) && mPosY<=(ccoin1_position.y + ccoin1_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin1_position.w=0;ccoin1_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin2_position.x-ccoin2_position.w) && mPosX <= (ccoin2_position.x+ccoin2_position.w) 
				&& mPosY>=(ccoin2_position.y - ccoin2_position.h) && mPosY<=(ccoin2_position.y + ccoin2_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin2_position.w=0;ccoin2_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin3_position.x-ccoin3_position.w) && mPosX <= (ccoin3_position.x+ccoin3_position.w) 
				&& mPosY>=(ccoin3_position.y - ccoin3_position.h) && mPosY<=(ccoin3_position.y + ccoin3_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin3_position.w=0;ccoin3_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin4_position.x-ccoin4_position.w) && mPosX <= (ccoin4_position.x+ccoin4_position.w) 
				&& mPosY>=(ccoin4_position.y - ccoin4_position.h) && mPosY<=(ccoin4_position.y + ccoin4_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin4_position.w=0;ccoin4_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin5_position.x-ccoin5_position.w) && mPosX <= (ccoin5_position.x+ccoin5_position.w) 
				&& mPosY>=(ccoin5_position.y - ccoin5_position.h) && mPosY<=(ccoin5_position.y + ccoin5_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin5_position.w=0;ccoin5_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin6_position.x-ccoin6_position.w) && mPosX <= (ccoin6_position.x+ccoin6_position.w) 
				&& mPosY>=(ccoin6_position.y - ccoin6_position.h) && mPosY<=(ccoin6_position.y + ccoin6_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin6_position.w=0;ccoin6_position.h=0; ++points;cout<<points<<endl;
				}

				if(  mPosX >= (ccoin7_position.x-ccoin7_position.w) && mPosX <= (ccoin7_position.x+ccoin7_position.w) 
				&& mPosY>=(ccoin7_position.y - ccoin7_position.h) && mPosY<=(ccoin7_position.y + ccoin7_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin7_position.w=0;ccoin7_position.h=0; ++points;cout<<points<<endl;
				}

				if((  mPosX >= (door_position.x-door_position.w) && mPosX <= (door_position.x+door_position.w) 
				&& mPosY>=(door_position.y - door_position.h) && mPosY<=(door_position.y + door_position.h)) && points == 7){
						Mix_PlayChannel( -1, levelup, 0 );puts("Level 3 Upgraded");++level;total_coin+=points;if(supercoinB) total_coin+=5; goto LEVEL;
				} 


					
			//Points Print in level											
				
				LastDigit = ((points+total_coin) % 10);

				switch( LastDigit )
        		{
        		case 0 : pointsP = IMG_Load("0.jpg"); break;									

        		case 1 : pointsP = IMG_Load("1.jpg"); break;									
					
        		case 2 : pointsP = IMG_Load("2.jpg"); break;

        		case 3 : pointsP = IMG_Load("3.jpg"); break;

        		case 4 : pointsP = IMG_Load("4.jpg"); break;

        		case 5 : pointsP = IMG_Load("5.jpg"); 
					break;

        		case 6 : pointsP = IMG_Load("6.png"); break;

        		case 7 : pointsP = IMG_Load("7.jpg"); break;

        		case 8 : pointsP = IMG_Load("8.jpg"); break;

        		case 9 : pointsP = IMG_Load("9.jpg"); break;

        		}
				pointsP_tex = SDL_CreateTextureFromSurface(renderer,pointsP);
				SDL_FreeSurface(pointsP);

        		SDL_Rect pointsP_position;
				pointsP_position.x = 1250 ;
				pointsP_position.y = 0 ;
				pointsP_position.w = 30;
				pointsP_position.h = 30;
				
				
				//2nd digit
				
				switch( ((points+total_coin)/10) )
        		{
        		case 0 : pointsP2 = IMG_Load("0.jpg"); break;									
        		case 1 : pointsP2 = IMG_Load("1.jpg"); break;									
        		case 2 : pointsP2 = IMG_Load("2.jpg"); break;
        		case 3 : pointsP2 = IMG_Load("3.jpg"); break;
				case 4 : pointsP2 = IMG_Load("4.jpg"); break;
        		}

				pointsP2_tex = SDL_CreateTextureFromSurface(renderer,pointsP2);
				SDL_FreeSurface(pointsP2);

        		SDL_Rect pointsP2_position;
				pointsP2_position.x = 1220;
				pointsP2_position.y = 0;
				pointsP2_position.w = 30;
				pointsP2_position.h = 30;



				//Clear screen
				SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
				SDL_RenderClear( renderer );


				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_1 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_2 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_3 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_4 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_5 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_6 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_7 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_8 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_9 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_10 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_11 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_12 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_13 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_14 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_15 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_16 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_17 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_18 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_19 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_20 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_21 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_22 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_23 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_24 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_25 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_26 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_27 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_28 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_29 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_30 );



				//Rendering objects
				player.render();
				//Rendering enemy
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy1_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy2_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy3_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy4_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy5_position);

				//Rendering pointsP
                SDL_RenderCopy(renderer,pointsP_tex,NULL,&pointsP_position);
				SDL_RenderCopy(renderer,pointsP2_tex,NULL,&pointsP2_position);

				//Rendering Specialcoin
                SDL_RenderCopy(renderer,Specialcoin_tex,NULL,&Specialcoin_position);

				//Rendering supercoin
                SDL_RenderCopy(renderer,supercoin_tex,NULL,&supercoin_position);
				

				//Rendering coin
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin1_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin2_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin3_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin4_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin5_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin6_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin7_position);

				//Rendering door
				SDL_RenderCopy(renderer,door_tex,NULL,&door_position);
				
				 
				//Update screen
				SDL_RenderPresent( renderer );
				

				x_pos1 += (float) direction1 * 5;	//printf("%f\n",y_pos1);
	 			if(x_pos1 == 0 || x_pos1 == 250) direction1 *= -1;

				x_pos2 += (float) direction2 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos2 == 0 || x_pos2 == 430) direction2 *= -1;

				x_pos3 += (float) direction3 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos3 == 365 || x_pos3 == 830) direction3 *= -1;

				y_pos4 += (float) direction4 * 5;	//printf("%f\n",x_pos4);
	 			if(y_pos4 == 385 || y_pos4 == 730) direction4 *= -1;

				y_pos5 += (float) direction5 * 5;	//printf("%f\n",x_pos2);
	 			if(y_pos5 == 485 || y_pos5 == 930) direction5 *= -1;
				
		}	

		close();
	}


///////////////////////////////////temporary////////////////////////////////////


	if(level==6){
		load =IMG_Load("loading.jpg");
		load_tex = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex,NULL,NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(300);

		load =IMG_Load("loading.gif");
		load_tex1 = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_Rect load_position;
		load_position.x = 550;
		load_position.y = 600;
		load_position.w = 150;
		load_position.h = 150;
		//SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex1,NULL,&load_position);
		SDL_RenderPresent(renderer);
		SDL_Delay(500);
		gPlayerTexture.loadFromFile( "pac.png" );
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Event handler
		Player2 player;	//The dot that will be moving around on the screen
		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}
					player.handleEvent( d );	//Handle input for the dot
					
					
				}
		//Move the dot and check collision
		player.move();
		if(total_coin>=1){
				++level; goto LEVEL;
			} 

		//Clear screen
		SDL_SetRenderDrawColor( renderer, 47, 79, 79, 79 );
		SDL_RenderClear( renderer );
		//Rendering objects
		player.render();
		//Update screen
		SDL_RenderPresent( renderer );
		}	
	close();
	}


///////////////////////////////////temporary////////////////////////////////////	


		
			
		//////////////////////**************LEVEL44444444444****************////////////////
		//////////////////////**************LEVEL44444444444****************////////////////
		//////////////////////**************LEVEL44444444444****************////////////////  

		if(level==7){
		

		Mix_PlayMusic( gMusic2, -1 );		// playing music

		door =IMG_Load("Door.png");
		door_tex = SDL_CreateTextureFromSurface(renderer,door);
		SDL_FreeSurface(door);
		
		SDL_Rect door_position;
		door_position.x = 1250;
		door_position.y = 930;
		door_position.w = 30;
		door_position.h = 30;

	//Special Coin
        bool SpecialcoinB = false;
        Specialcoin = IMG_Load("Specialcoin.png");
		Specialcoin_tex = SDL_CreateTextureFromSurface(renderer,Specialcoin);
		SDL_FreeSurface(Specialcoin);

        SDL_Rect Specialcoin_position;
		Specialcoin_position.x = 940;
		Specialcoin_position.y = 900;
		Specialcoin_position.w = 30;
		Specialcoin_position.h = 30;

	//Supercoin(sword)
		bool supercoinB = false;
        supercoin = IMG_Load("supercoin.png");
		supercoin_tex = SDL_CreateTextureFromSurface(renderer,supercoin);
		SDL_FreeSurface(supercoin);

        SDL_Rect supercoin_position;
		supercoin_position.x = 30;
		supercoin_position.y = 920;
		supercoin_position.w = 30;
		supercoin_position.h = 30;
		

	// NON-Special COIN
		ccoin =IMG_Load("gems.png");
		ccoin_tex = SDL_CreateTextureFromSurface(renderer,ccoin);
		SDL_FreeSurface(ccoin);

		SDL_Rect ccoin1_position;
		ccoin1_position.x = 10;
		ccoin1_position.y = 200;
		ccoin1_position.w = 20;
		ccoin1_position.h = 20;

		SDL_Rect ccoin2_position;
		ccoin2_position.x = 420;
		ccoin2_position.y = 300;
		ccoin2_position.w = 20;
		ccoin2_position.h = 20;

		SDL_Rect ccoin3_position;
		ccoin3_position.x = 480;
		ccoin3_position.y = 220;
		ccoin3_position.w = 20;
		ccoin3_position.h = 20;

		SDL_Rect ccoin4_position;
		ccoin4_position.x = 400;
		ccoin4_position.y = 50;
		ccoin4_position.w = 20;
		ccoin4_position.h = 20;

		SDL_Rect ccoin5_position;
		ccoin5_position.x = 510;
		ccoin5_position.y = 400;
		ccoin5_position.w = 20;
		ccoin5_position.h = 20;

		SDL_Rect ccoin6_position;
		ccoin6_position.x = 850;
		ccoin6_position.y = 780;
		ccoin6_position.w = 20;
		ccoin6_position.h = 20;

		SDL_Rect ccoin7_position;
		ccoin7_position.x = 1250;
		ccoin7_position.y = 600;
		ccoin7_position.w = 20;
		ccoin7_position.h = 20;

		SDL_Rect ccoin8_position;
		ccoin8_position.x = 925;
		ccoin8_position.y = 720;
		ccoin8_position.w = 20;
		ccoin8_position.h = 20;

		SDL_Rect ccoin9_position;
		ccoin9_position.x = 230;
		ccoin9_position.y = 780;
		ccoin9_position.w = 20;
		ccoin9_position.h = 20;

		SDL_Rect ccoin10_position;
		ccoin10_position.x = 1240;
		ccoin10_position.y = 100;
		ccoin10_position.w = 20;
		ccoin10_position.h = 20;


		enemy =IMG_Load("enemy.png");
		enemy_tex = SDL_CreateTextureFromSurface(renderer,enemy);
		SDL_FreeSurface(enemy);
		SDL_Rect enemy1_position;
		enemy1_position.x = 0;
		enemy1_position.y = 300;
		enemy1_position.w = 30;
		enemy1_position.h = 30;


		SDL_Rect enemy2_position;
		enemy2_position.x = 15;
		enemy2_position.y = 485;
		enemy2_position.w = 30;
		enemy2_position.h = 30;

		SDL_Rect enemy3_position;
		enemy3_position.x = 365;
		enemy3_position.y = 130;
		enemy3_position.w = 30;
		enemy3_position.h = 30;

		SDL_Rect enemy4_position;
		enemy4_position.x = 550;
		enemy4_position.y = 385;
		enemy4_position.w = 30;
		enemy4_position.h = 30;

		SDL_Rect enemy5_position;
		enemy5_position.x = 640;
		enemy5_position.y = 200;
		enemy5_position.w = 30;
		enemy5_position.h = 30;

		SDL_Rect enemy6_position;
		enemy6_position.x = 915;
		enemy6_position.y = 130;
		enemy6_position.w = 30;
		enemy6_position.h = 30;

		SDL_Rect enemy7_position;
		enemy7_position.x = 1130;
		enemy7_position.y = 385;
		enemy7_position.w = 30;
		enemy7_position.h = 30;

		float x_pos1 = 0;
 		int direction1 = 1;

		float y_pos2 = 485;
 		int direction2 = 1;

		float x_pos3 = 365;
 		int direction3 = 1;

		float y_pos4 = 385;
 		int direction4 = 1;

		float x_pos5 = 640;
 		int direction5 = 1;

		float x_pos6 = 915;
 		int direction6 = 1;

		float y_pos7 = 385;
 		int direction7 = 1;

		


		
		gPlayerTexture.loadFromFile( "pac.png" );
		
		
		
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Event handler
		Player player;	//The dot that will be moving around on the screen
		
			

			

			//Set the wall_map4

			SDL_Rect wall_1;
			wall_1.x = 91*0;
			wall_1.y = 96*1;
			wall_1.w = 91*2;
			wall_1.h = 96*1;

			SDL_Rect wall_2;
			wall_2.x = 91*0;
			wall_2.y = 96*4;
			wall_2.w = 91*1;
			wall_2.h = 96*1;

			SDL_Rect wall_3;
			wall_3.x = 91*1;
			wall_3.y = 96*2;
			wall_3.w = 91*1;
			wall_3.h = 96*1;

			SDL_Rect wall_4;
			wall_4.x = 91*1;
			wall_4.y = 96*6;
			wall_4.w = 91*1;
			wall_4.h = 96*2;

			SDL_Rect wall_5;
			wall_5.x = 91*1;
			wall_5.y = 96*9;
			wall_5.w = 91*1;
			wall_5.h = 96*1;

			SDL_Rect wall_6;
			wall_6.x = 91*2;
			wall_6.y = 96*4;
			wall_6.w = 91*3;
			wall_6.h = 96*1;

			SDL_Rect wall_7;
			wall_7.x = 91*2;
			wall_7.y = 96*7;
			wall_7.w = 91*1;
			wall_7.h = 96*1;

			SDL_Rect wall_8;
			wall_8.x = 91*3;
			wall_8.y = 0;
			wall_8.w = 91*1;
			wall_8.h = 96*3;

			SDL_Rect wall_9;
			wall_9.x = 91*3;
			wall_9.y = 96*6;
			wall_9.w = 91*1;
			wall_9.h = 96*3;

			SDL_Rect wall_10;
			wall_10.x = 91*4;
			wall_10.y = 96*2;
			wall_10.w = 91*1;
			wall_10.h = 96*1;

			SDL_Rect wall_11;
			wall_11.x = 91*4;
			wall_11.y = 96*5;
			wall_11.w = 91*2;
			wall_11.h = 96*1;

			SDL_Rect wall_12;
			wall_12.x = 91*5;
			wall_12.y = 96*0;
			wall_12.w = 91*1;
			wall_12.h = 96*1;

			SDL_Rect wall_13;
			wall_13.x = 91*5;
			wall_13.y = 96*3;
			wall_13.w = 91*4;
			wall_13.h = 96*1;

			SDL_Rect wall_14;
			wall_14.x = 91*5;
			wall_14.y = 96*7;
			wall_14.w = 91*1;
			wall_14.h = 96*3;

			SDL_Rect wall_15;
			wall_15.x = 91*6;
			wall_15.y = 96*2;
			wall_15.w = 91*1;
			wall_15.h = 96*1;

			SDL_Rect wall_16;
			wall_16.x = 91*7;
			wall_16.y = 96*1;
			wall_16.w = 91;
			wall_16.h = 96;

			SDL_Rect wall_17;
			wall_17.x = 91*7;
			wall_17.y = 96*4;
			wall_17.w = 91*1;
			wall_17.h = 96*3;

			SDL_Rect wall_18;
			wall_18.x = 91*8;
			wall_18.y = 96*8;
			wall_18.w = 91*1;
			wall_18.h = 96*1;

			SDL_Rect wall_19;
			wall_19.x = 91*9;
			wall_19.y = 96*1;
			wall_19.w = 91;
			wall_19.h = 96;

			SDL_Rect wall_20;
			wall_20.x = 91*9;
			wall_20.y = 96*6;
			wall_20.w = 91;
			wall_20.h = 96*2;

			SDL_Rect wall_21;
			wall_21.x = 91*10;
			wall_21.y = 96*2;
			wall_21.w = 91;
			wall_21.h = 96*4;

			SDL_Rect wall_22;
			wall_22.x = 91*10;
			wall_22.y = 96*8;
			wall_22.w = 91;
			wall_22.h = 96;

			SDL_Rect wall_23;
			wall_23.x = 91*11;
			wall_23.y = 96*3;
			wall_23.w = 91*2;
			wall_23.h = 96;

			SDL_Rect wall_24;
			wall_24.x = 91*11;
			wall_24.y = 96*5;
			wall_24.w = 91;
			wall_24.h = 96;

			SDL_Rect wall_25;
			wall_25.x = 91*11;
			wall_25.y = 96*7;
			wall_25.w = 91;
			wall_25.h = 96;

			SDL_Rect wall_26;
			wall_26.x = 91*11;
			wall_26.y = 96*9;
			wall_26.w = 91;
			wall_26.h = 96;

			SDL_Rect wall_27;
			wall_27.x = 91*12;
			wall_27.y = 96*0;
			wall_27.w = 91;
			wall_27.h = 96;

			SDL_Rect wall_28;
			wall_28.x = 91*12;
			wall_28.y = 96*2;
			wall_28.w = 91;
			wall_28.h = 96;

			SDL_Rect wall_29;
			wall_29.x = 91*13;
			wall_29.y = 96*5;
			wall_29.w = 91+6;
			wall_29.h = 96;

			SDL_Rect wall_30;
			wall_30.x = 91*13;
			wall_30.y = 96*7;
			wall_30.w = 91+6;
			wall_30.h = 96*2;



int points=0; 

		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}

					if(d.key.keysym.scancode==SDL_SCANCODE_P){
						pause_level=level;
						pause_coin=total_coin;
						Mix_PlayMusic( gMusic3, -1 );
						goto Main_Menu;
					}

					if(d.key.keysym.scancode==SDL_SCANCODE_M) Mix_HaltMusic();

					player.handleEvent( d );	//Handle input for the dot
					
					
				}
				//moving enemy 
				enemy1_position.x= (int) x_pos1;
				enemy2_position.y= (int) y_pos2;
				enemy3_position.x= (int) x_pos3;
				enemy4_position.y= (int) y_pos4;
				enemy5_position.x= (int) x_pos5;
				enemy6_position.x= (int) x_pos6;
				enemy7_position.y= (int) y_pos7;
				

				//Move the dot and check collision
				player.move( wall_1,wall_2,wall_3,wall_4,wall_5,wall_6,wall_7,wall_8,wall_9,wall_10,wall_11,wall_12,wall_13,wall_14,wall_15,
				wall_16,wall_17,wall_18,wall_19,wall_20,wall_21,wall_22,wall_23,wall_24,wall_25,wall_26,wall_27,wall_28,wall_29,wall_30 );
				
				//collission with enemy
				if(  mPosX >= (enemy1_position.x-enemy1_position.w) && mPosX <= (enemy1_position.x+enemy1_position.w) && mPosY>=(enemy1_position.y - enemy1_position.h) && mPosY<=(enemy1_position.y + enemy1_position.h) && enemy1_position.w!=0 ) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy1_position.w=0;
						enemy1_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;	
				}

				if( enemy2_position.w!=0 && mPosY >= (enemy2_position.y-enemy2_position.h) && mPosY <=(enemy2_position.y + enemy2_position.h) 
				&& mPosX >=(enemy2_position.x - enemy2_position.w) && mPosX <=(enemy2_position.x + enemy2_position.w)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy2_position.w=0;
						enemy2_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy3_position.w!=0 &&  mPosX >= (enemy3_position.x-enemy3_position.w) && mPosX <= (enemy3_position.x+enemy3_position.w) 
				&& mPosY>=(enemy3_position.y - enemy3_position.h) && mPosY<=(enemy3_position.y + enemy3_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy3_position.w=0;
						enemy3_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

if(  enemy4_position.w!=0 &&  mPosX >= (enemy4_position.x-enemy4_position.w) && mPosX <= (enemy4_position.x+enemy4_position.w) 
				&& mPosY>=(enemy4_position.y - enemy4_position.h) && mPosY<=(enemy4_position.y + enemy4_position.h)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy4_position.w=0;
						enemy4_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  enemy5_position.w!=0 &&  mPosX >= (enemy5_position.x-enemy5_position.w) && mPosX <= (enemy5_position.x+enemy5_position.w) 
				&& mPosY>=(enemy5_position.y - enemy5_position.h) && mPosY<=(enemy5_position.y + enemy5_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy5_position.w=0;
						enemy5_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  mPosX >= (enemy6_position.x-enemy6_position.w) && mPosX <= (enemy6_position.x+enemy6_position.w) 
				&& mPosY>=(enemy6_position.y - enemy6_position.h) && mPosY<=(enemy6_position.y + enemy6_position.h)) {
					if(SpecialcoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  enemy7_position.w!=0 &&  mPosX >= (enemy7_position.x-enemy7_position.w) && mPosX <= (enemy7_position.x+enemy7_position.w) 
				&& mPosY>=(enemy7_position.y - enemy7_position.h) && mPosY<=(enemy7_position.y + enemy7_position.h)) {
					if(SpecialcoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

			//collide with Specialcoin

                if(  mPosX >= (Specialcoin_position.x-Specialcoin_position.w) && mPosX <= (Specialcoin_position.x+Specialcoin_position.w) 
				&& mPosY>=(Specialcoin_position.y - Specialcoin_position.h) && mPosY<=(Specialcoin_position.y + Specialcoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						Specialcoin_position.w=0;
						Specialcoin_position.h=0; 
						SpecialcoinB = true;

						gPlayerTexture.loadFromFile( "pac2.png" );

						collissionpixcount = 0;

				} 
				
			//collide with supercoin

                if(  mPosX >= (supercoin_position.x-supercoin_position.w) && mPosX <= (supercoin_position.x+supercoin_position.w) 
				&& mPosY>=(supercoin_position.y - supercoin_position.h) && mPosY<=(supercoin_position.y + supercoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						supercoin_position.x=0;
						supercoin_position.y=0; 
						supercoinB = true;			

						collissionpixcount = 0;

				} 


			//Collide with Coin

				if(  mPosX >= (ccoin1_position.x-ccoin1_position.w) && mPosX <= (ccoin1_position.x+ccoin1_position.w) 
				&& mPosY>=(ccoin1_position.y - ccoin1_position.h) && mPosY<=(ccoin1_position.y + ccoin1_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin1_position.w=0;ccoin1_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin2_position.x-ccoin2_position.w) && mPosX <= (ccoin2_position.x+ccoin2_position.w) 
				&& mPosY>=(ccoin2_position.y - ccoin2_position.h) && mPosY<=(ccoin2_position.y + ccoin2_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin2_position.w=0;ccoin2_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin3_position.x-ccoin3_position.w) && mPosX <= (ccoin3_position.x+ccoin3_position.w) 
				&& mPosY>=(ccoin3_position.y - ccoin3_position.h) && mPosY<=(ccoin3_position.y + ccoin3_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin3_position.w=0;ccoin3_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin4_position.x-ccoin4_position.w) && mPosX <= (ccoin4_position.x+ccoin4_position.w) 
				&& mPosY>=(ccoin4_position.y - ccoin4_position.h) && mPosY<=(ccoin4_position.y + ccoin4_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin4_position.w=0;ccoin4_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin5_position.x-ccoin5_position.w) && mPosX <= (ccoin5_position.x+ccoin5_position.w) 
				&& mPosY>=(ccoin5_position.y - ccoin5_position.h) && mPosY<=(ccoin5_position.y + ccoin5_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin5_position.w=0;ccoin5_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin6_position.x-ccoin6_position.w) && mPosX <= (ccoin6_position.x+ccoin6_position.w) 
				&& mPosY>=(ccoin6_position.y - ccoin6_position.h) && mPosY<=(ccoin6_position.y + ccoin6_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin6_position.w=0;ccoin6_position.h=0; ++points;cout<<points<<endl;
				}

				if(  mPosX >= (ccoin7_position.x-ccoin7_position.w) && mPosX <= (ccoin7_position.x+ccoin7_position.w) 
				&& mPosY>=(ccoin7_position.y - ccoin7_position.h) && mPosY<=(ccoin7_position.y + ccoin7_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin7_position.w=0;ccoin7_position.h=0; ++points;cout<<points<<endl;
				}

				if(  mPosX >= (ccoin8_position.x-ccoin8_position.w) && mPosX <= (ccoin8_position.x+ccoin8_position.w) 
				&& mPosY>=(ccoin8_position.y - ccoin8_position.h) && mPosY<=(ccoin8_position.y + ccoin8_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin8_position.w=0;ccoin8_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin9_position.x-ccoin9_position.w) && mPosX <= (ccoin9_position.x+ccoin9_position.w) 
				&& mPosY>=(ccoin9_position.y - ccoin9_position.h) && mPosY<=(ccoin9_position.y + ccoin9_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin9_position.w=0;ccoin9_position.h=0; ++points;cout<<points<<endl;
				}

				if(  mPosX >= (ccoin10_position.x-ccoin10_position.w) && mPosX <= (ccoin10_position.x+ccoin10_position.w) 
				&& mPosY>=(ccoin10_position.y - ccoin10_position.h) && mPosY<=(ccoin10_position.y + ccoin10_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin10_position.w=0;ccoin10_position.h=0; ++points;cout<<points<<endl;
				}




				if((  mPosX >= (door_position.x-door_position.w) && mPosX <= (door_position.x+door_position.w) 
				&& mPosY>=(door_position.y - door_position.h) && mPosY<=(door_position.y + door_position.h)) && points == 10){
						Mix_PlayChannel( -1, levelup, 0 );puts("Level 4 Upgraded");++level;total_coin+=points;if(supercoinB) total_coin+=5;goto LEVEL;
				} 


				
					
			//Points Print in level											
				
				LastDigit = ((points+total_coin) % 10);

				switch( LastDigit )
        		{
        		case 0 : pointsP = IMG_Load("0.jpg"); break;									

        		case 1 : pointsP = IMG_Load("1.jpg"); break;									
					
        		case 2 : pointsP = IMG_Load("2.jpg"); break;

        		case 3 : pointsP = IMG_Load("3.jpg"); break;

        		case 4 : pointsP = IMG_Load("4.jpg"); break;

        		case 5 : pointsP = IMG_Load("5.jpg"); break;

        		case 6 : pointsP = IMG_Load("6.png"); break;

        		case 7 : pointsP = IMG_Load("7.jpg"); break;

        		case 8 : pointsP = IMG_Load("8.jpg"); break;

        		case 9 : pointsP = IMG_Load("9.jpg"); break;

        		}
				pointsP_tex = SDL_CreateTextureFromSurface(renderer,pointsP);
				SDL_FreeSurface(pointsP);

        		SDL_Rect pointsP_position;
				pointsP_position.x = 1250 ;
				pointsP_position.y = 0 ;
				pointsP_position.w = 30;
				pointsP_position.h = 30;

				//2nd digit
				
				switch( ((points+total_coin)/10) )
        		{
        		case 0 : pointsP2 = IMG_Load("0.jpg"); break;									
        		case 1 : pointsP2 = IMG_Load("1.jpg"); break;									
        		case 2 : pointsP2 = IMG_Load("2.jpg"); break;
        		case 3 : pointsP2 = IMG_Load("3.jpg"); break;
				case 4 : pointsP2 = IMG_Load("4.jpg"); break;
        		}

				pointsP2_tex = SDL_CreateTextureFromSurface(renderer,pointsP2);
				SDL_FreeSurface(pointsP2);

        		SDL_Rect pointsP2_position;
				pointsP2_position.x = 1220;
				pointsP2_position.y = 0;
				pointsP2_position.w = 30;
				pointsP2_position.h = 30;

				

				//Clear screen
				SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
				SDL_RenderClear( renderer );


				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_1 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_2 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_3 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_4 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_5 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_6 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_7 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_8 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_9 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_10 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_11 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_12 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_13 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_14 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_15 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_16 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_17 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_18 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_19 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_20 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_21 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_22 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_23 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_24 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_25 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_26 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_27 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_28 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_29 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_30 );



				//Rendering objects
				player.render();
				//Rendering enemy
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy1_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy2_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy3_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy4_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy5_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy6_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy7_position);

				//Rendering pointsP
                SDL_RenderCopy(renderer,pointsP_tex,NULL,&pointsP_position);
				SDL_RenderCopy(renderer,pointsP2_tex,NULL,&pointsP2_position);

				//Rendering Specialcoin
                SDL_RenderCopy(renderer,Specialcoin_tex,NULL,&Specialcoin_position);

				//Rendering supercoin
                SDL_RenderCopy(renderer,supercoin_tex,NULL,&supercoin_position);
				

				//Rendering coin
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin1_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin2_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin3_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin4_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin5_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin6_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin7_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin8_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin9_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin10_position);

				//Rendering door
				SDL_RenderCopy(renderer,door_tex,NULL,&door_position);
				
				 
				//Update screen
				SDL_RenderPresent( renderer );
				

				x_pos1 += (float) direction1 * 5;	//printf("%f\n",y_pos1);
	 			if(x_pos1 == 0 || x_pos1 == 430) direction1 *= -1;

				y_pos2 += (float) direction2 * 5;	//printf("%f\n",x_pos2);
	 			if(y_pos2 == 485 || y_pos2 == 930) direction2 *= -1;

				x_pos3 += (float) direction3 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos3 == 365 || x_pos3 == 610) direction3 *= -1;

				y_pos4 += (float) direction4 * 5;	//printf("%f\n",x_pos4);
	 			if(y_pos4 == 385 || y_pos4 == 700) direction4 *= -1;

				x_pos5 += (float) direction5 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos5 == 640 || x_pos5 == 870) direction5 *= -1;

				x_pos6 += (float) direction6 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos6 == 915 || x_pos6 == 1250) direction6 *= -1;

				y_pos7 += (float) direction7 * 5;	//printf("%f\n",x_pos4);
	 			if(y_pos7 == 385 || y_pos7 == 930) direction7 *= -1;
				
		}	

		close();
	}
		

///////////////////////////////////temporary////////////////////////////////////


	if(level==8){
		load =IMG_Load("loading.jpg");
		load_tex = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex,NULL,NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(300);

		load =IMG_Load("loading.gif");
		load_tex1 = SDL_CreateTextureFromSurface(renderer,load);
		SDL_FreeSurface(load);
		SDL_Rect load_position;
		load_position.x = 550;
		load_position.y = 600;
		load_position.w = 150;
		load_position.h = 150;
		//SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,load_tex1,NULL,&load_position);
		SDL_RenderPresent(renderer);
		SDL_Delay(500);
		gPlayerTexture.loadFromFile( "pac.png" );
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Event handler
		Player2 player;	//The dot that will be moving around on the screen
		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}
					player.handleEvent( d );	//Handle input for the dot
					
					
				}
		//Move the dot and check collision
		player.move();
		if(total_coin>=1){
				++level; goto LEVEL;
			} 

		//Clear screen
		SDL_SetRenderDrawColor( renderer, 47, 79, 79, 79 );
		SDL_RenderClear( renderer );
		//Rendering objects
		player.render();
		//Update screen
		SDL_RenderPresent( renderer );
		}	
	close();
	}


///////////////////////////////////temporary////////////////////////////////////	









		//////////////////////**************LEVEL55555555555****************////////////////
		//////////////////////**************LEVEL55555555555****************////////////////
		//////////////////////**************LEVEL55555555555****************////////////////  

		if(level==9){
		

		Mix_PlayMusic( gMusic2, -1 );		// playing music

		door =IMG_Load("gemss.png");
		door_tex = SDL_CreateTextureFromSurface(renderer,door);
		SDL_FreeSurface(door);
		
		SDL_Rect door_position;
		door_position.x = 950;			
		door_position.y = 250;
		door_position.w = 30;
		door_position.h = 30;


	//Special Coin
        bool SpecialcoinB = false;
        Specialcoin = IMG_Load("Specialcoin.png");
		Specialcoin_tex = SDL_CreateTextureFromSurface(renderer,Specialcoin);
		SDL_FreeSurface(Specialcoin);

        SDL_Rect Specialcoin_position;
		Specialcoin_position.x = 500;
		Specialcoin_position.y = 740;
		Specialcoin_position.w = 30;
		Specialcoin_position.h = 30;

	//Supercoin(sword)
		bool supercoinB = false;
        supercoin = IMG_Load("supercoin.png");
		supercoin_tex = SDL_CreateTextureFromSurface(renderer,supercoin);
		SDL_FreeSurface(supercoin);

        SDL_Rect supercoin_position;
		supercoin_position.x = 420;
		supercoin_position.y = 260;
		supercoin_position.w = 30;
		supercoin_position.h = 30;
		

	// NON-Special COIN
		ccoin =IMG_Load("gems.png");
		ccoin_tex = SDL_CreateTextureFromSurface(renderer,ccoin);
		SDL_FreeSurface(ccoin);

		SDL_Rect ccoin1_position;
		ccoin1_position.x = 10;
		ccoin1_position.y = 700;
		ccoin1_position.w = 20;
		ccoin1_position.h = 20;

		SDL_Rect ccoin2_position;
		ccoin2_position.x = 320;
		ccoin2_position.y = 170;
		ccoin2_position.w = 20;
		ccoin2_position.h = 20;

		SDL_Rect ccoin3_position;
		ccoin3_position.x = 520;
		ccoin3_position.y = 600;
		ccoin3_position.w = 20;
		ccoin3_position.h = 20;

		SDL_Rect ccoin4_position;
		ccoin4_position.x = 570;
		ccoin4_position.y = 500;
		ccoin4_position.w = 20;
		ccoin4_position.h = 20;

		SDL_Rect ccoin5_position;
		ccoin5_position.x = 570;
		ccoin5_position.y = 340;
		ccoin5_position.w = 20;
		ccoin5_position.h = 20;

		SDL_Rect ccoin6_position;
		ccoin6_position.x = 250;
		ccoin6_position.y = 600;
		ccoin6_position.w = 20;
		ccoin6_position.h = 20;

		SDL_Rect ccoin7_position;
		ccoin7_position.x = 800;
		ccoin7_position.y = 340;
		ccoin7_position.w = 20;
		ccoin7_position.h = 20;

		SDL_Rect ccoin8_position;
		ccoin8_position.x = 1145;
		ccoin8_position.y = 450;
		ccoin8_position.w = 20;
		ccoin8_position.h = 20;

		SDL_Rect ccoin9_position;
		ccoin9_position.x = 1240;
		ccoin9_position.y = 280;
		ccoin9_position.w = 20;
		ccoin9_position.h = 20;

		SDL_Rect ccoin10_position;
		ccoin10_position.x = 900;
		ccoin10_position.y = 5;
		ccoin10_position.w = 20;
		ccoin10_position.h = 20;


		enemy =IMG_Load("enemy.png");
		enemy_tex = SDL_CreateTextureFromSurface(renderer,enemy);
		SDL_FreeSurface(enemy);
		SDL_Rect enemy1_position;
		enemy1_position.x = 720;
		enemy1_position.y = 285;
		enemy1_position.w = 30;
		enemy1_position.h = 30;


		SDL_Rect enemy2_position;
		enemy2_position.x = 15;
		enemy2_position.y = 500;
		enemy2_position.w = 30;
		enemy2_position.h = 30;

		SDL_Rect enemy3_position;
		enemy3_position.x = 250;
		enemy3_position.y = 600;
		enemy3_position.w = 30;
		enemy3_position.h = 30;

		SDL_Rect enemy4_position;
		enemy4_position.x = 960;
		enemy4_position.y = 0;
		enemy4_position.w = 30;
		enemy4_position.h = 30;

		SDL_Rect enemy5_position;
		enemy5_position.x = 240;
		enemy5_position.y = 320;
		enemy5_position.w = 30;
		enemy5_position.h = 30;

		SDL_Rect enemy6_position;
		enemy6_position.x = 915;
		enemy6_position.y = 0;
		enemy6_position.w = 30;
		enemy6_position.h = 30;

		SDL_Rect enemy7_position;
		enemy7_position.x = 640;
		enemy7_position.y = 400;
		enemy7_position.w = 30;
		enemy7_position.h = 30;

		SDL_Rect enemy8_position={950,450,30,30};

		float x_pos1 = 720;
 		int direction1 = 1;

		float y_pos2 = 500;
 		int direction2 = 1;

		float x_pos3 = 250;
 		int direction3 = 1;

		float y_pos4 = 0;
 		int direction4 = 1;

		float x_pos5 = 240;
 		int direction5 = 1;

		float x_pos6 = 915;
 		int direction6 = 1;

		float y_pos7 = 400;
 		int direction7 = 1;

		float x_pos8 = 950;
 		int direction8 = 1;

		


		
		gPlayerTexture.loadFromFile( "pac.png" );
		
		
		
		double ang=0;
		bool quit = false; 	//Main loop flag
		SDL_Event d;		//Event handler
		Player player;	//The dot that will be moving around on the screen
		
			

			

			//Set the wall_map5

			SDL_Rect wall_1;
            wall_1.x = 80*1;
            wall_1.y = 80*1;
            wall_1.w = 80*1;
            wall_1.h = 80*1;
 
            SDL_Rect wall_2;
            wall_2.x = 80*2;
            wall_2.y = 80*1;
            wall_2.w = 80*1;
            wall_2.h = 80*5;
 
            SDL_Rect wall_3;
            wall_3.x = 80*1;
            wall_3.y = 80*4;
            wall_3.w = 80*1;
            wall_3.h = 80*1;
 
            SDL_Rect wall_4;
            wall_4.x = 80*1;
            wall_4.y = 80*7;
            wall_4.w = 80*1;
            wall_4.h = 80*1;
 
            SDL_Rect wall_5;
            wall_5.x = 80*1;
            wall_5.y = 80*10;
            wall_5.w = 80*1;
            wall_5.h = 80*1;
 
            SDL_Rect wall_6;
            wall_6.x = 80*2;
            wall_6.y = 80*7;
            wall_6.w = 80*1;
            wall_6.h = 80*4;
 
            SDL_Rect wall_7;
            wall_7.x = 80*3;
            wall_7.y = 80*5;
            wall_7.w = 80*1;
            wall_7.h = 80*1;
 
            SDL_Rect wall_8;
            wall_8.x = 80*4;
            wall_8.y = 80*3;
            wall_8.w = 80*1;
            wall_8.h = 80*1;
 
            SDL_Rect wall_9;
            wall_9.x = 80*3;
            wall_9.y = 80*1;
            wall_9.w = 80*3;
            wall_9.h = 80*1;
 
            SDL_Rect wall_10;
            wall_10.x = 80*5;
            wall_10.y = 80*2;
            wall_10.w = 80*3;
            wall_10.h = 80*1;
 
            SDL_Rect wall_11;
            wall_11.x = 80*6;
            wall_11.y = 80*4;
            wall_11.w = 80*1;
            wall_11.h = 80*3;
 
            SDL_Rect wall_12;
            wall_12.x = 80*5;
            wall_12.y = 80*6;
            wall_12.w = 80*1;
            wall_12.h = 80*1;
 
            SDL_Rect wall_13;
            wall_13.x = 80*7;
            wall_13.y = 80*5;
            wall_13.w = 80*1;
            wall_13.h = 80*1;
 
            SDL_Rect wall_14;
            wall_14.x = 80*4;
            wall_14.y = 80*8;
            wall_14.w = 80*1;
            wall_14.h = 80*3;
 
            SDL_Rect wall_15;
            wall_15.x = 80*5;
            wall_15.y = 80*8;
            wall_15.w = 80*2;
            wall_15.h = 80*1;
 
            SDL_Rect wall_16;
            wall_16.x = 80*6;
            wall_16.y = 80*10;
            wall_16.w = 80*1;
            wall_16.h = 80*1;
 
            SDL_Rect wall_17;
         	wall_17.x = 80*7;
         	wall_17.y = 80*7;
         	wall_17.w = 80*1;
         	wall_17.h = 80*3;
 
         	SDL_Rect wall_18;
         	wall_18.x = 80*8;
         	wall_18.y = 80*3;
         	wall_18.w = 80*1;
         	wall_18.h = 80*2;
 
         	SDL_Rect wall_19;
         	wall_19.x = 80*9;
         	wall_19.y = 80*4;
         	wall_19.w = 80*1;
         	wall_19.h = 80*1;
 
         	SDL_Rect wall_20;
         	wall_20.x = 80*10;
         	wall_20.y = 80*5;
         	wall_20.w = 80*1;
         	wall_20.h = 80*2;
 
         	SDL_Rect wall_21;
         	wall_21.x = 80*11;
         	wall_21.y = 80*1;
         	wall_21.w = 80*1;
         	wall_21.h = 80*2;
 
         	SDL_Rect wall_22;
         	wall_22.x = 80*9;
         	wall_22.y = 80*0;
         	wall_22.w = 80*2;
         	wall_22.h = 80*1;
 
         	SDL_Rect wall_23;
         	wall_23.x = 80*9;
         	wall_23.y = 80*7;
         	wall_23.w = 80*4;
         	wall_23.h = 80*1;
 
         	SDL_Rect wall_24;
         	wall_24.x = 80*10;
         	wall_24.y = 80*9;
         	wall_24.w = 80*1;
         	wall_24.h = 80*3;
 
         	SDL_Rect wall_25;
         	wall_25.x = 80*9;
        	wall_25.y = 80*11;
         	wall_25.w = 80*1;
         	wall_25.h = 80*1;
 
         	SDL_Rect wall_26;
         	wall_26.x = 80*11;
         	wall_26.y = 80*9;
         	wall_26.w = 80*1;
         	wall_26.h = 80*1;
 
         	SDL_Rect wall_27;
         	wall_27.x = 80*13;
         	wall_27.y = 80*8;
         	wall_27.w = 80*1;
         	wall_27.h = 80*3;
 
         	SDL_Rect wall_28;
         	wall_28.x = 80*11;
         	wall_28.y = 80*4;
         	wall_28.w = 80*5;
         	wall_28.h = 80*1;

         	SDL_Rect wall_29;
         	wall_29.x = 80*13;
         	wall_29.y = 80*1;
         	wall_29.w = 80*1;
         	wall_29.h = 80*3;
 
         	SDL_Rect wall_30;
         	wall_30.x = 80*14;
         	wall_30.y = 80*6;
         	wall_30.w = 80*1;
         	wall_30.h = 80*1;


int points=0; 

		while(!quit){
			while( SDL_PollEvent( &d ) != 0 ){
					if( d.type == SDL_QUIT ){
						quit = true;
					}

					if(d.key.keysym.scancode==SDL_SCANCODE_P){
						pause_level=level;
						pause_coin=total_coin;
						Mix_PlayMusic( gMusic3, -1 );
						goto Main_Menu;
					}

					if(d.key.keysym.scancode==SDL_SCANCODE_M) Mix_HaltMusic();

					player.handleEvent( d );	//Handle input for the dot
					
					
				}
				//moving enemy 
				enemy1_position.x= (int) x_pos1;
				enemy2_position.y= (int) y_pos2;
				enemy3_position.x= (int) x_pos3;
				enemy4_position.y= (int) y_pos4;
				enemy5_position.x= (int) x_pos5;
				enemy6_position.x= (int) x_pos6;
				enemy7_position.y= (int) y_pos7;
				enemy8_position.x= (int) x_pos8;
				

				//Move the dot and check collision
				player.move( wall_1,wall_2,wall_3,wall_4,wall_5,wall_6,wall_7,wall_8,wall_9,wall_10,wall_11,wall_12,wall_13,wall_14,wall_15,
				wall_16,wall_17,wall_18,wall_19,wall_20,wall_21,wall_22,wall_23,wall_24,wall_25,wall_26,wall_27,wall_28,wall_29,wall_30 );
				
				//collission with enemy
				if(  mPosX >= (enemy1_position.x-enemy1_position.w) && mPosX <= (enemy1_position.x+enemy1_position.w) && mPosY>=(enemy1_position.y - enemy1_position.h) && mPosY<=(enemy1_position.y + enemy1_position.h) && enemy1_position.w!=0 ) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy1_position.w=0;
						enemy1_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;	
				}

				if( enemy2_position.w!=0 && mPosY >= (enemy2_position.y-enemy2_position.h) && mPosY <=(enemy2_position.y + enemy2_position.h) 
				&& mPosX >=(enemy2_position.x - enemy2_position.w) && mPosX <=(enemy2_position.x + enemy2_position.w)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy2_position.w=0;
						enemy2_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy3_position.w!=0 &&  mPosX >= (enemy3_position.x-enemy3_position.w) && mPosX <= (enemy3_position.x+enemy3_position.w) 
				&& mPosY>=(enemy3_position.y - enemy3_position.h) && mPosY<=(enemy3_position.y + enemy3_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy3_position.w=0;
						enemy3_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;

					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if(  enemy4_position.w!=0 &&  mPosX >= (enemy4_position.x-enemy4_position.w) && mPosX <= (enemy4_position.x+enemy4_position.w) 
				&& mPosY>=(enemy4_position.y - enemy4_position.h) && mPosY<=(enemy4_position.y + enemy4_position.h)) {

					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy4_position.w=0;
						enemy4_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  enemy5_position.w!=0 &&  mPosX >= (enemy5_position.x-enemy5_position.w) && mPosX <= (enemy5_position.x+enemy5_position.w) 
				&& mPosY>=(enemy5_position.y - enemy5_position.h) && mPosY<=(enemy5_position.y + enemy5_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy5_position.w=0;
						enemy5_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}


				if( mPosX >= (enemy6_position.x-enemy6_position.w) && mPosX <= (enemy6_position.x+enemy6_position.w) 
				&& mPosY>=(enemy6_position.y - enemy6_position.h) && mPosY<=(enemy6_position.y + enemy6_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy5_position.w=0;
						enemy5_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  enemy7_position.w!=0 &&  mPosX >= (enemy7_position.x-enemy7_position.w) && mPosX <= (enemy7_position.x+enemy7_position.w) 
				&& mPosY>=(enemy7_position.y - enemy7_position.h) && mPosY<=(enemy7_position.y + enemy7_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy5_position.w=0;
						enemy5_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				if(  enemy8_position.w!=0 &&  mPosX >= (enemy8_position.x-enemy8_position.w) && mPosX <= (enemy8_position.x+enemy8_position.w) 
				&& mPosY>=(enemy8_position.y - enemy8_position.h) && mPosY<=(enemy8_position.y + enemy8_position.h)) {
					if(SpecialcoinB == false && supercoinB == false){
						total_coin+=points; points = 0;
						bool opt = GameOver(total_coin);
						if(opt){
							level = 1 ;total_coin = 0;goto LEVEL;
						}
						else InputTaken(total_coin);
						goto Main_Menu;
					}
					else if(supercoinB == true){
						enemy5_position.w=0;
						enemy5_position.h=0;
						supercoinB = false;
						supercoin_position.h = 0;
						supercoin_position.w = 0;
					}
					else if(collissionpixcount < 14){
							collissionpixcount++;
							if(collissionpixcount > 3) gPlayerTexture.loadFromFile( "pac.png" );
					}
					else if(collissionpixcount > 13) SpecialcoinB = false;
				}

				//collide with Specialcoin

                if(  mPosX >= (Specialcoin_position.x-Specialcoin_position.w) && mPosX <= (Specialcoin_position.x+Specialcoin_position.w) 
				&& mPosY>=(Specialcoin_position.y - Specialcoin_position.h) && mPosY<=(Specialcoin_position.y + Specialcoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						Specialcoin_position.w=0;
						Specialcoin_position.h=0; 
						SpecialcoinB = true;

						gPlayerTexture.loadFromFile( "pac2.png" );

						collissionpixcount = 0;

				} 
				
				//collide with supercoin

                if(  mPosX >= (supercoin_position.x-supercoin_position.w) && mPosX <= (supercoin_position.x+supercoin_position.w) 
				&& mPosY>=(supercoin_position.y - supercoin_position.h) && mPosY<=(supercoin_position.y + supercoin_position.h)){
						Mix_PlayChannel( -1, coin, 0 );
						supercoin_position.x=0;
						supercoin_position.y=0; 
						supercoinB = true;			

						collissionpixcount = 0;

				} 



				//Collide with Coin

				if(  mPosX >= (ccoin1_position.x-ccoin1_position.w) && mPosX <= (ccoin1_position.x+ccoin1_position.w) 
				&& mPosY>=(ccoin1_position.y - ccoin1_position.h) && mPosY<=(ccoin1_position.y + ccoin1_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin1_position.w=0;ccoin1_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin2_position.x-ccoin2_position.w) && mPosX <= (ccoin2_position.x+ccoin2_position.w) 
				&& mPosY>=(ccoin2_position.y - ccoin2_position.h) && mPosY<=(ccoin2_position.y + ccoin2_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin2_position.w=0;ccoin2_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin3_position.x-ccoin3_position.w) && mPosX <= (ccoin3_position.x+ccoin3_position.w) 
				&& mPosY>=(ccoin3_position.y - ccoin3_position.h) && mPosY<=(ccoin3_position.y + ccoin3_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin3_position.w=0;ccoin3_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin4_position.x-ccoin4_position.w) && mPosX <= (ccoin4_position.x+ccoin4_position.w) 
				&& mPosY>=(ccoin4_position.y - ccoin4_position.h) && mPosY<=(ccoin4_position.y + ccoin4_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin4_position.w=0;ccoin4_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin5_position.x-ccoin5_position.w) && mPosX <= (ccoin5_position.x+ccoin5_position.w) 
				&& mPosY>=(ccoin5_position.y - ccoin5_position.h) && mPosY<=(ccoin5_position.y + ccoin5_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin5_position.w=0;ccoin5_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin6_position.x-ccoin6_position.w) && mPosX <= (ccoin6_position.x+ccoin6_position.w) 
				&& mPosY>=(ccoin6_position.y - ccoin6_position.h) && mPosY<=(ccoin6_position.y + ccoin6_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin6_position.w=0;ccoin6_position.h=0; ++points;cout<<points<<endl;
				}

				if(  mPosX >= (ccoin7_position.x-ccoin7_position.w) && mPosX <= (ccoin7_position.x+ccoin7_position.w) 
				&& mPosY>=(ccoin7_position.y - ccoin7_position.h) && mPosY<=(ccoin7_position.y + ccoin7_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin7_position.w=0;ccoin7_position.h=0; ++points;cout<<points<<endl;
				}

				if(  mPosX >= (ccoin8_position.x-ccoin8_position.w) && mPosX <= (ccoin8_position.x+ccoin8_position.w) 
				&& mPosY>=(ccoin8_position.y - ccoin8_position.h) && mPosY<=(ccoin8_position.y + ccoin8_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin8_position.w=0;ccoin8_position.h=0; ++points;cout<<points<<endl;
				} 

				if(  mPosX >= (ccoin9_position.x-ccoin9_position.w) && mPosX <= (ccoin9_position.x+ccoin9_position.w) 
				&& mPosY>=(ccoin9_position.y - ccoin9_position.h) && mPosY<=(ccoin9_position.y + ccoin9_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin9_position.w=0;ccoin9_position.h=0; ++points;cout<<points<<endl;
				}

				if(  mPosX >= (ccoin10_position.x-ccoin10_position.w) && mPosX <= (ccoin10_position.x+ccoin10_position.w) 
				&& mPosY>=(ccoin10_position.y - ccoin10_position.h) && mPosY<=(ccoin10_position.y + ccoin10_position.h)){
						Mix_PlayChannel( -1, coin, 0 );ccoin10_position.w=0;ccoin10_position.h=0; ++points;cout<<points<<endl;
				}




				if((  mPosX >= (door_position.x-door_position.w) && mPosX <= (door_position.x+door_position.w) 
				&& mPosY>=(door_position.y - door_position.h) && mPosY<=(door_position.y + door_position.h)) && points == 10){
						total_coin+=points; if(supercoinB) total_coin+=10;
						Mix_PlayChannel( -1, victory, 0 );
						puts("You Win");
						SDL_SetRenderDrawColor(renderer,240, 243, 244 ,255);
						SDL_RenderClear(renderer);
						win =IMG_Load("win.png");
						win_tex = SDL_CreateTextureFromSurface(renderer,win);
						SDL_FreeSurface(win);
						SDL_Rect gmo = {150, 80, 1000, 800};
						SDL_RenderCopy(renderer,win_tex,NULL,&gmo);
						SDL_RenderPresent(renderer);
						SDL_Delay(3000);
						InputTaken(total_coin);
						Mix_PlayMusic( gMusic3, -1 );		// playing music
						goto Main_Menu;
				} 


				
					
			//Points Print in level											
				
				LastDigit = ((points+total_coin) % 10);

				switch( LastDigit )
        		{
        		case 0 : pointsP = IMG_Load("0.jpg"); break;									

        		case 1 : pointsP = IMG_Load("1.jpg"); break;									
					
        		case 2 : pointsP = IMG_Load("2.jpg"); break;

        		case 3 : pointsP = IMG_Load("3.jpg"); break;

        		case 4 : pointsP = IMG_Load("4.jpg"); break;

        		case 5 : pointsP = IMG_Load("5.jpg"); 
					

        		case 6 : pointsP = IMG_Load("6.png"); break;

        		case 7 : pointsP = IMG_Load("7.jpg"); break;

        		case 8 : pointsP = IMG_Load("8.jpg"); break;

        		case 9 : pointsP = IMG_Load("9.jpg"); break;

        		}
				pointsP_tex = SDL_CreateTextureFromSurface(renderer,pointsP);
				SDL_FreeSurface(pointsP);

        		SDL_Rect pointsP_position;
				pointsP_position.x = 1250 ;
				pointsP_position.y = 0 ;
				pointsP_position.w = 30;
				pointsP_position.h = 30;

				//2nd digit
				
				switch( ((points+total_coin)/10) )
        		{
        		case 0 : pointsP2 = IMG_Load("0.jpg"); break;									
        		case 1 : pointsP2 = IMG_Load("1.jpg"); break;									
        		case 2 : pointsP2 = IMG_Load("2.jpg"); break;
        		case 3 : pointsP2 = IMG_Load("3.jpg"); break;
				case 4 : pointsP2 = IMG_Load("4.jpg"); break;
        		}

				pointsP2_tex = SDL_CreateTextureFromSurface(renderer,pointsP2);
				SDL_FreeSurface(pointsP2);

        		SDL_Rect pointsP2_position;
				pointsP2_position.x = 1220;
				pointsP2_position.y = 0;
				pointsP2_position.w = 30;
				pointsP2_position.h = 30;



				//Clear screen
				SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
				SDL_RenderClear( renderer );


				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_1 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_2 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_3 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_4 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_5 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_6 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_7 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_8 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_9 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_10 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_11 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_12 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_13 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_14 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_15 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_16 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_17 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_18 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_19 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_20 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );		//SDL_RenderFillRect -> to fill rectangle with solid color 			
				SDL_RenderFillRect( renderer, &wall_21 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	//SDL_RenderDarwRect -> to draw rectangle with color
				SDL_RenderFillRect( renderer, &wall_22 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_23 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_24 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_25 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_26 );
				
				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_27 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_28 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_29 );

				SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );	
				SDL_RenderFillRect( renderer, &wall_30 );



				//Rendering objects
				player.render();
				//Rendering enemy
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy1_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy2_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy3_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy4_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy5_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy6_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy7_position);
				SDL_RenderCopy(renderer,enemy_tex,NULL,&enemy8_position);

				//Rendering pointsP
                SDL_RenderCopy(renderer,pointsP_tex,NULL,&pointsP_position);
				SDL_RenderCopy(renderer,pointsP2_tex,NULL,&pointsP2_position);

				//Rendering Specialcoin
                SDL_RenderCopy(renderer,Specialcoin_tex,NULL,&Specialcoin_position);

				//Rendering supercoin
                SDL_RenderCopy(renderer,supercoin_tex,NULL,&supercoin_position);
				

				//Rendering coin
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin1_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin2_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin3_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin4_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin5_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin6_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin7_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin8_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin9_position);
				SDL_RenderCopy(renderer,ccoin_tex,NULL,&ccoin10_position);

				//Rendering door
				SDL_RenderCopy(renderer,door_tex,NULL,&door_position);
				
				 
				//Update screen
				SDL_RenderPresent( renderer );
				

				x_pos1 += (float) direction1 * 5;	//printf("%f\n",y_pos1);
	 			if(x_pos1 == 720 || x_pos1 == 1000) direction1 *= -1;

				y_pos2 += (float) direction2 * 5;	//printf("%f\n",x_pos2);
	 			if(y_pos2 == 500 || y_pos2 == 850) direction2 *= -1;

				x_pos3 += (float) direction3 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos3 == 250 || x_pos3 == 520) direction3 *= -1;

				y_pos4 += (float) direction4 * 5;	//printf("%f\n",x_pos4);
	 			if(y_pos4 == 0 || y_pos4 == 280) direction4 *= -1;

				x_pos5 += (float) direction5 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos5 == 240 || x_pos5 == 450) direction5 *= -1;

				x_pos6 += (float) direction6 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos6 == 915 || x_pos6 == 1250) direction6 *= -1;

				y_pos7 += (float) direction7 * 5;	//printf("%f\n",x_pos4);
	 			if(y_pos7 == 400 || y_pos7 == 900) direction7 *= -1;

				x_pos8 += (float) direction8 * 5;	//printf("%f\n",x_pos2);
	 			if(x_pos8 == 950 || x_pos8 == 1250) direction8 *= -1;
				
		}	

		close();
		}
}
			








    else if(menu_button==2){
        puts("You Pressed SCORE Button");
		
		help =IMG_Load("score.png");
	    help_tex = SDL_CreateTextureFromSurface(renderer,help);
		SDL_FreeSurface(help);
		
        SDL_Event h;
		bool running = true;
 		while(running){
             while(SDL_PollEvent(&h)){
                if(h.key.keysym.scancode==SDL_SCANCODE_BACKSPACE) goto Main_Menu;
 				
 				switch(h.type){
 					case SDL_QUIT:
 						running = false;
 						break;
 				}
             }
			SDL_RenderClear( renderer );
			HighScore();
		
		
        }

}


	else if(menu_button==3){
		puts("You Pressed HELP Button");
		score =IMG_Load("help.png");
	    score_tex = SDL_CreateTextureFromSurface(renderer,score);
		SDL_FreeSurface(score);

		SDL_Event c;
		bool running = true;
 		while(running){
             while(SDL_PollEvent(&c)){
                if(c.key.keysym.scancode==SDL_SCANCODE_BACKSPACE) goto Main_Menu;
 				
 				switch(c.type){
 					case SDL_QUIT:
 						running = false;
 						break;
 				}
             }

		
		
		SDL_RenderCopy(renderer,score_tex,NULL,NULL);
		SDL_RenderPresent(renderer);
        }
		
        
}



	else if(menu_button==4){
		puts("You Pressed QUIT Button");
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		
    }

	


}

void end(){
    //Free loaded images
	Mix_HaltMusic();
	SDL_DestroyTexture(help_tex);
	SDL_DestroyTexture(help_tex1);
	SDL_DestroyTexture(menu_tex);
	SDL_DestroyTexture(score_tex);
	SDL_DestroyTexture(score_tex1);
	SDL_DestroyTexture(pre_menu_tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}



