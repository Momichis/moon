#include <stdio.h>
#include "../include/map.h"


int main(void){
	
	for(int i=0;i<mega2map_V;i++){
		for(int j=0;j<mega2map_H;j++){
			printf("%c",mega2map[i][j]);
		}	printf("\n");
	}

  return 0;
}
