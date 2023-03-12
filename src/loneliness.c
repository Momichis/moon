#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#include <util.h>
#include <string.h>
//spr.h

extern pthread_mutex_t mutex;

typedef struct{
	int x;
	int y;
	int n; /* 1:true 0:false */
	int speed;
	char C;
	char c;
}m_cstruct;

void *m_cfunction(void *arg){
	m_cstruct *obj = (m_cstruct *)arg;

	while(obj->n){
//		if(obj->n){
			pthread_mutex_lock(&mutex);
			gotoxy(obj->y,obj->x);
			printf("%c",obj->c);
			pthread_mutex_unlock(&mutex);
			
			Sleep(obj->speed);
			
			pthread_mutex_lock(&mutex);
			gotoxy(obj->y,obj->x);
			printf("%C",obj->C);
			pthread_mutex_unlock(&mutex);
			
			Sleep(obj->speed);
//        }
	}
	return 0;
}

typedef struct{
	int x;
	int y;
	int h;
	int v;
	char ***sprites;
	int sp_quant;
	int speed;
	int a_en;
}obj_sprite;


void *animate_object(void *arg){
	
	obj_sprite *npc = (obj_sprite *)arg;
	int i,j,sp_sw;
	
	npc->v+=npc->y;
	npc->h+=npc->x;

	while(npc->a_en){
//	while(1){

		for(sp_sw=0;sp_sw<(npc->sp_quant);sp_sw++){
			for(i=npc->y;i<npc->v;i++){
				for(j=npc->x;j<npc->h;j++){
				pthread_mutex_lock(&mutex);
					gotoxy(i,j);
					printf("%c",npc->sprites[sp_sw][i-npc->y][j-npc->x]);
				pthread_mutex_unlock(&mutex);
				}
			}
				Sleep(npc->speed);
		}
	}
	/*
	for(i=y;i<v;i++){
		for(j=x;j<h;i++){
			gotoxy(i,j);
			printf("%c",array[i][j]);
		}
	}
	*/
	return NULL;
}

void free_spr(int y, int x,char ***spr){
	int i,j;
	for(i=0;i<y;i++){
		for(j=0;j<x;j++){
			free(spr[i][j]);
		}
	}
	free(spr);
}


