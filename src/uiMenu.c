#include <stdio.h>

int main()
{
  printf("Welcome to the Banking Simulator\nBy Ethan Caoile, Micah Kang, Ricky Paque, Aris Sarkisian, and Felix Zheng\n");
  int quit = 0; 
  printf("Select Option:\n");
  printf("1. Account\n");
  printf("2. Deposit\n");
  printf("3. Withdraw\n");
  printf("4. Quit\n");
  while(!quit){
    int x = 0;
    
    printf("Option: ");
    if(scanf("%d", &x) != 1){
      printf("Error, input integer value\n");
      while(getchar() != '\n');
      continue;
    }

    if(x == 1){
      printf("Select 1 to create account\nSelect 2 if already have one\nOption:");
      int z = 0;
      if(scanf("%d", &z) != 1){
	printf("Error, non int inputted, returning to main menu\n");
	while(getchar() != '\n');
	continue;
      }
      if(z ==1){
	printf("New Account\n");
      } else if(z == 2){
	printf("Old Account\n");
      } else {
	printf("Not an option, returning to main menu\n");
      }
    } else if(x == 2){
      printf("Deposit\n");
    } else if(x == 3){
      printf("Withdraw\n");
    } else if(x == 4){
      printf("Quitting\n");
      quit = 1;
    } else{
      printf("Not an option\n");
    }
  }
  return 0;
}
