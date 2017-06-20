#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void install();
void update();
void apps();
void about();
void aboutThisApp();

void main(){
	printf("Please initialize by typing in your password:");
	char command[50];
   	strcpy( command, "dir" );
	system(command);
	char input[7] ={0};

	aboutThisApp();
	while(1){
		printf("Input command [install/update/apps/about/exit]: ");
		scanf("%s", input);
		printf("Current input value \"%s\" ", input);

		if (!strcmp(input,"install")){
			printf("INSTALL\n");
		}
		else if (!strcmp(input,"update")){
			printf("UPDATE\n");
		}
		else if (!strcmp(input,"apps")){
			printf("APPS\n");
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

}
