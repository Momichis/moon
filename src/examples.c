#include <moon.h>
#include <map.h>
#include <msg.h>
#include <spr.h>
#include <npc.h>
#include <util.h>
#include <disp.h>
#include <pthread.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void sprite_example(){
	
	obj_sprite SrMomichi;
			
	SrMomichi.x = 3;
	SrMomichi.y = 1;
	
	SrMomichi.v = 3;
	SrMomichi.h = 7;
	
	SrMomichi.sp_quant = 3;
	SrMomichi.speed = 180;
	SrMomichi.a_en = 1;

	SrMomichi.sprites = srmomichi_d();
	
	
	char key;
	system("clear");
	
	pthread_t SRMOMICHI;
	pthread_create(&SRMOMICHI,NULL,animate_object,&SrMomichi);
	
	while(1){
		key = getch();
		if(key == 'x'){
			SrMomichi.a_en = 0;
			pthread_join(SRMOMICHI,NULL);
			printf("exit\n");
			break;
		}
	}
}

void maping(){
	
	init_sdl_mixer();


	who_said nppc1;


	who_said_init(&nppc1);
	message_box crossdresser;
	
	nppc1.y = 15;
	nppc1.x = 2;
	nppc1.h = 65;
	
	nppc1.Y = 21;
	
	nppc1.al = 2;
	

	nppc1.tits_peed = 30; 
	nppc1.text_speed = 10; 
	

	nppc1.titspell_rd[0] = 100;
	nppc1.titspell_rd[1] = 10;

	nppc1.txtspell_rd[0] = 10;
	nppc1.txtspell_rd[1] = 10;

	nppc1.sq_speed = 10;
	nppc1.tits_peed = 10;
	
	
	nppc1.tit_sound = "foo.wav";
	nppc1.txt_sound = "foo.wav";

	nppc1.title = "lol";
	nppc1.who = "npc --__-- no se";
	
	nppc1.text = "La existencia es eterna";
	
	
	int scr_x;
	int scr_y;
	
	int loc_x = 1;
	int loc_y = 1;
	
	#define map2Y 20
	#define map2X 64
	
	#define DSY 1
	#define DSX 2
	
	int SY = 20;
	int	SX = 60;
	
	#define ODSY 0
	#define ODSX 1
			
	pthread_t ME;
	m_cstruct me;

	me.n = 1;
	me.C = 'o';
	me.c = 'O';
	me.speed = 400;

	me.x = 2;
	me.y = 2;
		
	scr_x = me.x;
	scr_y = me.y;
	
	
	srand(time(NULL));
	
	//pthread_create(&ME,NULL,m_cfunction,&me);
	
	char key;

	system("clear");
	FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
	ShowConsoleCursor(0);



	
	obj_sprite SrMomichi;
	
	

	SrMomichi.x = 3;
	SrMomichi.y = 23;
	
	SrMomichi.v = 3;
	SrMomichi.h = 7;
	
	SrMomichi.sp_quant = 3;
	SrMomichi.speed = 180;
	SrMomichi.a_en = 1;

	SrMomichi.sprites = srmomichi_d();

	obj_sprite SrMomichi1 = SrMomichi;
	obj_sprite SrMomichi2 = SrMomichi;
	obj_sprite SrMomichi3 = SrMomichi;
	obj_sprite SrMomichi4 = SrMomichi;
	obj_sprite SrMomichi5 = SrMomichi;
	obj_sprite SrMomichi6 = SrMomichi;
	obj_sprite SrMomichi7 = SrMomichi;
	
	
	pthread_t SRMOMICHI;
	pthread_t SRMOMICHI2;
	pthread_t SRMOMICHI3;
	pthread_t SRMOMICHI4;
	pthread_t SRMOMICHI5;
	pthread_t SRMOMICHI6;
	pthread_t SRMOMICHI7;
	
	SrMomichi1.x += 8;
	SrMomichi2.x += 16;
	SrMomichi3.x += 24;
	SrMomichi4.x += 32;
	SrMomichi5.x += 40;
	SrMomichi6.x += 48;
	SrMomichi7.x += 56;


	SrMomichi1.speed += 8;
	SrMomichi2.speed += 16;
	SrMomichi3.speed += 24;
	SrMomichi4.speed += 32;
	SrMomichi5.speed += 40;
	SrMomichi6.speed += 48;
	SrMomichi7.speed += 56;
	
	pthread_create(&SRMOMICHI,NULL,animate_object,&SrMomichi);
	pthread_create(&SRMOMICHI2,NULL,animate_object,&SrMomichi1);
	pthread_create(&SRMOMICHI3,NULL,animate_object,&SrMomichi2);

	pthread_create(&SRMOMICHI4,NULL,animate_object,&SrMomichi3);
	pthread_create(&SRMOMICHI5,NULL,animate_object,&SrMomichi4);
	pthread_create(&SRMOMICHI6,NULL,animate_object,&SrMomichi5);
	pthread_create(&SRMOMICHI7,NULL,animate_object,&SrMomichi6);
	
	

	adrenocromo_s test;
	test.attr.x = 30;
	test.attr.y = 12;

	test.rx = 0;
	test.ry = 0;

	test.rX = 99;
	test.rY = 99;

	test.attr.n = 1;
	test.attr.c = 'c';
	test.attr.C = 'C';
	test.attr.spd = 500;

	test.v = map2_V;
	test.h = map2_H;

	test.mode2speed = 4000;

	test.onion = 1;

	test.mode = 2;
	
	test.mode2_y_inc = 1;

	test.mode2_x_inc = 2;
	

	test.mode2_y_en = 0;

	test.mode2_x_en = 1;


	ShowConsoleCursor(0);

	system("clear");


	carta_de_la_virgen(&test,map2,ASS);	

	pprint(map2_V,map2_H,map2);

	getch();

	pthread_t TEST;
	pthread_t TEST_;


	lo_que_le_paso_al_nino_en_el_infierno mmain;
	pthread_t MMAIN;

	mmain.x = 3;
	mmain.y = 3;
	mmain.n = 1;
	mmain.spd = 600;
	mmain.c = 'o';
	mmain.C = 'O';

	
	pthread_create(&TEST,NULL,unicornio_rosa_invisible,&test);
	pthread_create(&TEST_,NULL,magic_madness_and_sadness,&test);
	pthread_create(&MMAIN,NULL,m_c,&mmain);

	



	DrawSquare(21,1,28,67,0,0);

	Mix_Chunk *sound = Mix_LoadWAV("foots.wav");

	while(mmain.n){

		key=getch();
		if(key == 'x'){
			mmain.n = 0;
		}
		if(key == 'o'){
			mmain.n = 1;
		}
			
		if(mmain.n == 1){
		gotoxy(mmain.y,mmain.x);
//		gotoxy(scr_y,scr_x);


//		printf("%c",map2[me.y-ODSY][me.x-ODSX]);
		printf("%c",map2[scr_y-ODSY][scr_x-ODSX]);
				
		if(key == 'w'){ 
			mmain.y --; 
			scr_y--;
			Mix_PlayChannel(0, sound, 0);
		}
		if(key == 'a'){
			mmain.x--;
			scr_x--;
			Mix_PlayChannel(0, sound, 0);
		} 
		if(key == 's'){
			mmain.y++;
			scr_y++;
			Mix_PlayChannel(0, sound, 0);
		}
		if(key == 'd'){ 
			mmain.x++; 
			scr_x++;
			Mix_PlayChannel(0, sound, 0);
		}
		if(key == 'x'){
			mmain.n = 0;
		}
		
		if(key == '+'){
			SX++;
			SY++;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
		}
		if(key == '-'){
			SX--;
			SY--;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
		}			

		if(key == ']'){
			SX++;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
		}
		if(key == '['){
			SX--;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
		}			

		if(key == '>'){
			SY++;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
		}
		if(key == '<'){
			SY--;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
		}			

		if(key == ' '){
			if(mmain.x == test.attr.x -1 || mmain.x == test.attr.x + 1 || mmain.y == test.attr.y - 1 || mmain.y == test.attr.y + 1){
				test.mode2_x_en = 0;
				put_message_box(NULL,&crossdresser,nppc1);			
				getch();
				test.mode2_x_en = 1;			
				pprint(map2_V,map2_H,map2);
			}
		}			
			

		if(mmain.x == (SX+DSX*2)-2){
			loc_x ++;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
			me.x--;
		}
			
		if(mmain.x == ODSX){
			loc_x --;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
			me.x++;
		}
			
		if(mmain.y == (SY+DSY*2)-1){
			loc_y ++;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
			me.y--;
		}
			
		if(mmain.y == ODSY){
			loc_y --;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map2);
			me.y++;
		}
			
		gotoxy(mmain.y,mmain.x);
//		gotoxy(scr_y,scr_x);
		printf("%c",mmain.c);


		if(scr_x == 37 && scr_y == 3){
			test.onion = 0;
			test.attr.n = 0;
			FocusInsideSquarexy(map2Y,map2X,DSY,DSX,SY,SX,loc_y,loc_x,map1);			
		}

		}
	}
	
	pthread_join(TEST,NULL);
	pthread_join(TEST_,NULL);
//	pthread_join(ME,NULL);
	ShowConsoleCursor(1);
}
