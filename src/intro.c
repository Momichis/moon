#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#include <util.h>
#include <disp.h>

#include <map.h>

typedef struct{
	char key;
	int enable;
	pthread_t *intro_thread;
}k_struct;

void *k_f(void *arg){
	k_struct *kb = (k_struct *)arg;
	while(1){
		while(kb->enable){
				if(kb->key == 'x' || kb->key == 'X'){
					pthread_cancel(*kb->intro_thread);
				}
			kb->key = getch();
		}
	}
}

void *pintro(void *arg){

	char init[29][84];
		Fill(29,84,init,' ');
	
	ShowConsoleCursor(0);		
clear();
	puttext(29,84,init,29/2-2,21,"(c) 2 0 2 1   M A S E C A   C O .   L T D");
	puttext(29,84,init,29/2-1,42-33,"T M   A N D   (c) 2 0 2 1   M A S E C A   M . X     . ,   I N C .");
	puttext(29,84,init,29/2,42-11,"L I C E N S E D   B Y");
	puttext(29,84,init,29/2+1,42-49/2,"P O R O N G A S   O F   A M E R I C A .   I N C.");
	
	PrintInsideSquare(29,84,init);
	
	Sleep(4050);

	clear();
	
	FocusInsideSquare(270,110,   29,84,   240,0,mega2map);
		Sleep(300);

	clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-37/2,"I N   T H E   Y E A R  O F   2 0 0 X");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-53/2,"A  S U P E R   R O B O T   N A M E D   M E G A M A N");
	FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
	
	gotoxy(31,1);
	printf("  [Presiona X para saltar...]");
			
	Sleep(4400);
	
clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-55/2,"                                                      ");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-55/2,"                                                      ");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(500);
				
clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-12,"W A S   C R E A T E D .");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-25,"D R .   L I G H T   C R E A T E D   M E G A M A N");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(4400);

clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-55/2,"                                                      ");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-55/2,"                                                      ");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(500);

clear();

	puttext(mega2map_V,mega2map_H,mega2map,263,42-25,"T H E   S T O P   T H E   E V I L   D E S I R E S");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-25/2,"O F   D R .   W I L L Y.");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(4400);

clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-55/2,"                                                      ");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-55/2,"                                                      ");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(500);

clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-25,"H O W E V E R ,   A F T E R   H I S   D E A T H ,");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-46/2,"D R .   W I L L Y   C R E A T E D   E I G H T");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(4400);

clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-55/2,"                                                      ");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-55/2,"                                                      ");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(1000);
clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-17,"O F   H I S   O W N   R O B O T S");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-36/2,"T O   C O U N T E R   M E G A M A N");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(4400);

clear();
	puttext(mega2map_V,mega2map_H,mega2map,263,42-55/2,"                                                      ");
	puttext(mega2map_V,mega2map_H,mega2map,265,42-55/2,"                                                      ");
			FocusInsideSquare(mega2map_V,mega2map_H,   29,84,   240,0,mega2map);
				Sleep(400);
		

	int i;
	for(i=239;i>=0;i--){

		clear();
			FocusInsideSquare(mega2map_V,mega2map_H,29,84,i,0,mega2map);
		Sleep(50);
	}
		Sleep(1500);

	int o=2;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"              ___           ___           ___     ,     ___    .                               "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,".       .    /__/\\         /  /\\     .   /  /\\         /__/\\                .              "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"    ,       |  |::\\       /  /::\\ .     /  /::\\        \\  \\:\\                            "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"            |  |:|:\\     /  /:/\\:\\     /  /:/\\:\\        \\  \\:\\  ,      .         .     "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"          __|__|:|\\:\\   /  /:/  \\:\\   /  /:/  \\:\\   _____\\__\\:\\                       "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"         /__/::::| \\:\\ /__/:/ \\__\\:\\ /__/:/ \\__\\:\\ /__/::::::::\\      ,    .          "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"    .    \\  \\:\\~~\\__\\/ \\  \\:\\ /  /:/ \\  \\:\\ /  /:/ \\  \\:\\~~\\~~\\/               "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"          \\  \\:\\        \\  \\:\\  /:/   \\  \\:\\  /:/   \\  \\:\\  ~~~     *           ,  "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"           \\  \\:\\    .   \\  \\:\\/:/  .  \\  \\:\\/:/     \\  \\:\\               ,        "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"   ,    .   \\  \\:\\        \\  \\::/       \\  \\::/       \\  \\:\\   .     .               "); ++o;
	puttext(mega2map_V,mega2map_H,mega2map,o,0,"             \\__\\/  .  ,   \\__\\/     .   \\__\\/         \\__\\/                  .        "); ++o;
	clear();		
		char buff[30][84];
		CopyLocation(mega2map_V,mega2map_H,30,84,0,0,mega2map,buff);
		PrintInsideSquare(30,84,buff);
	ShowConsoleCursor(1);

	return NULL;
}

void Intro(void){
	
	pthread_t KEYBOARD;
	pthread_t INTRO;
	
	k_struct kb;
	kb.enable = 1;
	kb.intro_thread = &INTRO;
	
	pthread_create(&KEYBOARD,NULL,k_f,&kb);
	pthread_create(&INTRO,NULL,pintro,NULL);

	pthread_join(INTRO,NULL);
	
	pthread_cancel(KEYBOARD);

	ShowConsoleCursor(1);
}
