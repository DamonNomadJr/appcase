#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void install();
void update();
void apps();
void about();
void aboutThisApp();

void main(){

	char command[50];
	char input[7] ={0};

	aboutThisApp();
	while(1){
		printf("<><><><><><><><><><><><><>\n");
		printf("Input command [install/update/apps/about/exit]: ");
		scanf("%s", input);

		if (!strcmp(input,"install")){
			printf("INSTALL\n");
		}
		else if (!strcmp(input,"update")){
			printf("UPDATE\n");
			update();
		}
		else if (!strcmp(input,"apps")){
			printf("APPS\n");
			apps();
		}
		else if (!strcmp(input,"about")){
			printf("ABOUT\n");
		}
		else if (!strcmp(input,"exit")){
			printf("EXIT\n");
			break;
		}
		else{
			printf("Command not fount\n");
		}
	}
}

void aboutThisApp(){
	FILE *file = fopen("about.txt", "r");
	int c;
	while ((c = getc(file)) != EOF)
		putchar(c);
	fclose(file);
}

void update(){
	printf("<><><><><><><><><><><><><>\n");
	system("sudo apt-get update");
	system("sudo apt-get upgrade");
}

void apps(){
	printf("<><><><><><><><><><><><><>\n");
	system("ls repository/ -1");
}
