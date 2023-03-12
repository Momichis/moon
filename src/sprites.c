#include <stdlib.h>

char ***srmomichi_d(void){
	char ***srmomichi = (char ***)malloc(sizeof(char **) * 3);
	int i,j;
	for(i=0;i<3;i++){
		srmomichi[i] = (char **)malloc(sizeof(char *) * 3);
		for(j=0;j<3;j++){
			srmomichi[i][j] = (char *)malloc(sizeof(char) * 7);
		}
	}

	srmomichi[0][0] = " /|_/| ";
	srmomichi[0][1] = "( >.< )";
	srmomichi[0][2] = " > ^ < ";
	
	srmomichi[1][0] = " /|_/| ";
	srmomichi[1][1] = "( o.O )";
	srmomichi[1][2] = " > ^ < ";
	
	srmomichi[2][0] = " /\\_/\\ ";
	srmomichi[2][1] = "( O.o )";
	srmomichi[2][2] = " > ^ < ";

  return srmomichi;
}


char ***mooni_d(void){
	char ***mooni = (char ***)malloc(sizeof(char **) * 4);
	int i,j;
	for(i=0;i<4;i++){
		mooni[i] = (char **)malloc(sizeof(char *) * 10);
		for(j=0;j<10;j++){
			mooni[i][j] = (char *)malloc(sizeof(char) * 16);
		}
	}

	mooni[0][0] = "      ,_____    ";
	mooni[0][1] = "    ./ ><  _\\_. ";
	mooni[0][2] = "   /   ___/.-'``";
	mooni[0][3] = "  '   / _ /     ";
	mooni[0][4] = " /   /  ^{      ";
	mooni[0][5] = " |   |   _\\     ";
	mooni[0][6] = " j   |  _\\      ";
	mooni[0][7] = " \\   \\   \\      ";
	mooni[0][8] = " |    |._ '.__. ";
	mooni[0][9] = "/_'_'_\\ '-----' ";

	mooni[1][0] = "      ,_____    ";
	mooni[1][1] = "    ./ ><  _\\_. ";
	mooni[1][2] = "   /   ___/.-'``";
	mooni[1][3] = "  '   / _ /     ";
	mooni[1][4] = " /   /  -{      ";
	mooni[1][5] = " |   |   _\\     ";
	mooni[1][6] = " j   |  _\\      ";
	mooni[1][7] = " \\   \\   \\      ";
	mooni[1][8] = " |    |._ '.__. ";
	mooni[1][9] = "/_'_'_\\ '-----' ";

	mooni[2][0] = "      ,_____    ";
	mooni[2][1] = "    ./ ><  _\\_. ";
	mooni[2][2] = "   /   ___/.-'``";
	mooni[2][3] = "  '   / _ /     ";
	mooni[2][4] = " /   /  >{      ";
	mooni[2][5] = " |   |   _\\     ";
	mooni[2][6] = " j   |  (_\\     ";
	mooni[2][7] = " \\   \\   \\      ";
	mooni[2][8] = " |    |._ '.__. ";
	mooni[2][9] = "/_'_'_\\ '-----' ";

	mooni[3][0] = "      ,_____    ";
	mooni[3][1] = "    ./ ><  _\\_. ";
	mooni[3][2] = "   /   ___/.-'``";
	mooni[3][3] = "  '   / _ /     ";
	mooni[3][4] = " /   /  <{      ";
	mooni[3][5] = " |   |   _\\     ";
	mooni[3][6] = " j   |  )_\\     ";
	mooni[3][7] = " \\   \\   \\      ";
	mooni[3][8] = " |    |._ '.__. ";
	mooni[3][9] = "/_'_'_\\ '-----' ";


  return mooni;
}

