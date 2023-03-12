#include <pthread.h>
#include <stdlib.h>

#include <moon.h>
#include <util.h>
#include <msg.h>
#include <disp.h>
#include <npc.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void escucho_voces_quien_es();

int moon(void){

/*
	init_sdl_mixer();
	bg_sound("the_bends.ogg");

	Mix_Chunk *sound = Mix_LoadWAV("foo.wav");


    SDL_Event event;

	while(1){
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT){
			Mix_CloseAudio();
			Mix_Quit();
			SDL_Quit();
			exit(0);
		}
		Mix_PlayChannel(0, sound, 0);
		Sleep(200);
	}
*/

	init_sdl_mixer();
	
	escucho_voces_quien_es();
//	Intro();
  return 0;
}

void escucho_voces_quien_es(){
		
	system("clear");
	
	who_said florecita_dreams;
	who_said_init(&florecita_dreams);
	message_box crossdresser;
	
	florecita_dreams.v = 30;
	
	florecita_dreams.al = 2;
	
	florecita_dreams.y = 0;
	florecita_dreams.x = 1;
	
	florecita_dreams.Y = 7;

	florecita_dreams.tits_peed = 30; 
	florecita_dreams.text_speed = 10; 
	

	florecita_dreams.titspell_rd[0] = 100;
	florecita_dreams.titspell_rd[1] = 10;

	florecita_dreams.txtspell_rd[0] = 10;
	florecita_dreams.txtspell_rd[1] = 10;

	florecita_dreams.sq_speed = 10;
	florecita_dreams.tits_peed = 10;
	
	
	florecita_dreams.tit_sound = "foo.wav";
	florecita_dreams.txt_sound = "foo.wav";

	florecita_dreams.sqr_sound[0] = "msg.wav";
	florecita_dreams.sqr_sound[1] = "boom.wav";
	
	
	florecita_dreams.title = ">F6C@ A@C 56?EC@]";
	
	florecita_dreams.text = "En momentos de debilidad, a veces necesitamos a alguien que nos escuche.";
	
	ShowConsoleCursor(0);
	put_message_box(NULL,&crossdresser,florecita_dreams);
	ShowConsoleCursor(1);


	
	getch();

	florecita_dreams.tit_sound = NULL;

	florecita_dreams.titspell_rd[0] = 0;
	florecita_dreams.titspell_rd[1] = 0;

	florecita_dreams.sqr_sound[0] = NULL;
	florecita_dreams.sqr_sound[1] = NULL;

	florecita_dreams.sq_speed = 0;
	florecita_dreams.tits_peed = 0; 


	florecita_dreams.text = "Yo quiero taco bell";
	ShowConsoleCursor(0);
	put_message_box(NULL,&crossdresser,florecita_dreams);
	ShowConsoleCursor(1);

	getch();


	system("clear");

	florecita_dreams.text = "ya me crecio la verga la verga ya me creció";
	ShowConsoleCursor(0);
	put_message_box(NULL,&crossdresser,florecita_dreams);
	ShowConsoleCursor(1);

	
	free(florecita_dreams.t_buff);
	
	
}

