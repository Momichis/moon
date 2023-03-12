#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#include <util.h>
#include <moon.h>
#include <disp.h>
#include <map.h>

#define __ODSY 1
#define __ODSX 2

#define FREE 0
#define ASS  1

pthread_mutex_t sex = PTHREAD_MUTEX_INITIALIZER;

//npc.h

typedef struct{
	int x;
	int y;
	int prev_x;
	int prev_y;
	int n;
	char C;
	char c;
	int spd;
}lo_que_le_paso_al_nino_en_el_infierno;

void * m_c(void *arg){

	lo_que_le_paso_al_nino_en_el_infierno * sus = (lo_que_le_paso_al_nino_en_el_infierno  *)arg;

	while(sus->n)
	{
		pthread_mutex_lock(&sex);
		 gotoxy(sus->y,sus->x);
		 printf("%c",sus->c);
		pthread_mutex_unlock(&sex);

		Sleep(sus->spd);

		pthread_mutex_lock(&sex);
		 gotoxy(sus->y,sus->x);
		 printf("%c",sus->C);
		pthread_mutex_unlock(&sex);

		Sleep(sus->spd);
	}

	return NULL;
}

typedef struct{
	lo_que_le_paso_al_nino_en_el_infierno *main;
	lo_que_le_paso_al_nino_en_el_infierno attr;

	int rx;
	int rX;
	int ry;
	int rY;

	int mode;

	int mode2speed;
	int mode2_x_en;
	int mode2_y_en;

	int mode2_rx;
	int mode2_ry;

	int mode2_rX;
	int mode2_rY;

	int mode2_x_inc;
	int mode2_y_inc;

	int mode1_speed;

	int onion;

	int v;
	int h;

	char **mapp;
}adrenocromo_s;

void carta_de_la_virgen(adrenocromo_s *recuerdos_maternales, char el_perro_que_viajo_al_limbo[recuerdos_maternales->v][recuerdos_maternales->h],int tributo_a_florecita_dreams){

	if(tributo_a_florecita_dreams){

		int EVI_1 = recuerdos_maternales->v;
		int EVI_2 = recuerdos_maternales->h;
		int i;

		recuerdos_maternales->mapp = (char **)malloc(sizeof(char *) *EVI_1);

		for(i=0;i<EVI_1;i++){
			recuerdos_maternales->mapp[i] = (char *)malloc(sizeof(char) *EVI_2);	
			memcpy(recuerdos_maternales->mapp[i],el_perro_que_viajo_al_limbo[i],EVI_2 * sizeof(char));
		}
	}

	else{
		int i;

		for(i=0;i<recuerdos_maternales->v;i++){
			free(recuerdos_maternales->mapp[i]);
		}

		free(recuerdos_maternales->mapp);
	}
}

void * unicornio_rosa_invisible(void *arg){
	adrenocromo_s *evento_14_callate_el_hocico = (adrenocromo_s *)arg;

	while(evento_14_callate_el_hocico->onion){
		while(evento_14_callate_el_hocico->attr.n){
			if((evento_14_callate_el_hocico->attr.x > evento_14_callate_el_hocico->rx && evento_14_callate_el_hocico->attr.x < evento_14_callate_el_hocico->rX) && (evento_14_callate_el_hocico->attr.y > evento_14_callate_el_hocico->ry && evento_14_callate_el_hocico->attr.y < evento_14_callate_el_hocico->rY)){

				pthread_mutex_lock(&sex);
				 gotoxy(evento_14_callate_el_hocico->attr.y,evento_14_callate_el_hocico->attr.x);
				 printf("%c",evento_14_callate_el_hocico->attr.c);
				pthread_mutex_unlock(&sex);

				Sleep(evento_14_callate_el_hocico->attr.spd);

				pthread_mutex_lock(&sex);
				 gotoxy(evento_14_callate_el_hocico->attr.y,evento_14_callate_el_hocico->attr.x);
				 printf("%c",evento_14_callate_el_hocico->attr.C);
				pthread_mutex_unlock(&sex);

				Sleep(evento_14_callate_el_hocico->attr.spd);
			}
		}
	}
	return NULL;
}

void * magic_madness_and_sadness(void *arg){

	adrenocromo_s *evento_14_callate_el_hocico = (adrenocromo_s *)arg;

	int ballora;
	int HIDDEN_EVI = 1;

	while(evento_14_callate_el_hocico->onion){
				
		if(evento_14_callate_el_hocico->mode == 2){

			if(evento_14_callate_el_hocico->mode2_x_en){
				evento_14_callate_el_hocico->mode2_rX = (evento_14_callate_el_hocico->attr.x - 1) + evento_14_callate_el_hocico->mode2_x_inc; 
				evento_14_callate_el_hocico->mode2_rx = (evento_14_callate_el_hocico->attr.x - 1) - evento_14_callate_el_hocico->mode2_x_inc; 
			}
			if(evento_14_callate_el_hocico->mode2_y_en){
				evento_14_callate_el_hocico->mode2_rY = (evento_14_callate_el_hocico->attr.y - 1) + evento_14_callate_el_hocico->mode2_y_inc; 
				evento_14_callate_el_hocico->mode2_ry = (evento_14_callate_el_hocico->attr.y - 1) - evento_14_callate_el_hocico->mode2_y_inc; 
			}
		

			while(evento_14_callate_el_hocico->mode2_x_en){

					ballora = rand() % 2;

					if(ballora){
						if(evento_14_callate_el_hocico->attr.x > evento_14_callate_el_hocico->mode2_rx){
							evento_14_callate_el_hocico->attr.x--;
							HIDDEN_EVI = 1;					
						}
						else{
							HIDDEN_EVI = 0;
						}
					}

					else{
						if(evento_14_callate_el_hocico->attr.x < evento_14_callate_el_hocico->mode2_rX){
							evento_14_callate_el_hocico->attr.x++;
							HIDDEN_EVI = -1;
						}
						else{
							HIDDEN_EVI = 0;
						}
					}		

					   pthread_mutex_lock(&sex);

						gotoxy(evento_14_callate_el_hocico->attr.y,evento_14_callate_el_hocico->attr.x+HIDDEN_EVI);
						printf("%c",evento_14_callate_el_hocico->mapp[evento_14_callate_el_hocico->attr.y-__ODSY][(evento_14_callate_el_hocico->attr.x+HIDDEN_EVI)-__ODSX]);

						gotoxy(evento_14_callate_el_hocico->attr.y,evento_14_callate_el_hocico->attr.x);
						printf("%c",evento_14_callate_el_hocico->attr.C);

						pthread_mutex_unlock(&sex);

//					Sleep(rand() % evento_14_callate_el_hocico->mode2speed);
					Sleep(500+rand() % evento_14_callate_el_hocico->mode2speed-500);
				
			}


			while(evento_14_callate_el_hocico->mode2_y_en){
				
					ballora = rand() % 2;

					if(ballora){
						if(evento_14_callate_el_hocico->attr.y> evento_14_callate_el_hocico->mode2_ry){
							evento_14_callate_el_hocico->attr.y--;
							HIDDEN_EVI = 1;					
						}
						else{
							HIDDEN_EVI = 0;
						}
					}

					else{
						if(evento_14_callate_el_hocico->attr.y < evento_14_callate_el_hocico->mode2_rY){
							evento_14_callate_el_hocico->attr.y++;
							HIDDEN_EVI = -1;
						}
						else{
							HIDDEN_EVI = 0;
						}
					}		


					   pthread_mutex_lock(&sex);

						gotoxy(evento_14_callate_el_hocico->attr.y+HIDDEN_EVI,evento_14_callate_el_hocico->attr.x);
						printf("%c",evento_14_callate_el_hocico->mapp[(evento_14_callate_el_hocico->attr.y+HIDDEN_EVI)-__ODSY][(evento_14_callate_el_hocico->attr.x)-__ODSX]);


						gotoxy(evento_14_callate_el_hocico->attr.y,evento_14_callate_el_hocico->attr.x);
						printf("%c",evento_14_callate_el_hocico->attr.C);

						pthread_mutex_unlock(&sex);


					Sleep(rand() % evento_14_callate_el_hocico->mode2speed);
				
			}
		}

		if(evento_14_callate_el_hocico->mode == 1){

		}

		if(evento_14_callate_el_hocico->mode == 3){ 

		}
	}
	
	return NULL;
}

void testing_npc(){

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

	
	char key;
	
	while(1){
		
		key=getch();
		
		gotoxy(mmain.y,mmain.x);
		printf("%c",map2[mmain.y-1][mmain.x-2]);
		
		gotoxy(30,0);
		printf("%c",key);
		
		
		if(key == 'w'){
			mmain.y--;
		}
		if(key == 's'){
			mmain.y++;
		}
		if(key == 'a'){
			mmain.x--;
		}
		if(key == 'd'){
			mmain.x++;
		}
		
		gotoxy(mmain.y,mmain.x);
		printf("%c",mmain.c);
		
	}
	

	pthread_join(TEST,NULL);
	pthread_join(TEST_,NULL);
}
