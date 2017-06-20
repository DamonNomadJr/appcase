#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void install();
void update();
void apps();
void about();
void aboutThisApp();

char osArc[6] = {'a','m','d','6','4'};
void main(){

	char command[50];
	char input[7] ={0};

	aboutThisApp();
	update();
	while(1){
		printf("<><><><><><><><><><><><><>\n");
		printf("Input command [install/update/apps/about/exit]: ");
		scanf("%s", input);

		if (!strcmp(input,"install")){
			printf("INSTALL\n");
			install();
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
	system("sudo apt-get -qq update");
	system("sudo apt-get -qq upgrade");
	system("mkdir ~/Programs/");
}

void apps(){
	printf("<><><><><><><><><><><><><>\n");
	system("ls repository/ -1");
}

void install(){
	printf("<><><><><><><><><><><><><>\n");
	char input[10];
	printf("Please state the application name [***|apps]: ");
	scanf("%s", input);
	char cmd[60];
	if (!strcmp(input,"apps")){
		printf("APPS\n");
		apps();
	}
	else{
		sprintf(cmd,"mkdir ~/Programs/%s", input);
		system(cmd);
		sprintf(cmd,"sudo dpkg -iG repository/%s/install%s.deb --instdir=<~/Programs/%s/>", input, osArc, input);
		printf("Requested to install %s\n", input);
		printf("command %s\n", cmd);
		system(cmd);

	}
}
