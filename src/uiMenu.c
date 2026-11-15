/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS2600
*/
#include <stdio.h>

int main()
{
  printf("Welcome to the Banking Simulator\n");
  bool quit = false;
  printf("Select Option:\n");
  printf("1. Account\n");
  printf("2. Deposit\n");
  printf("3. Withdraw\n");
  printf("4. Quit\n");
  while(!quit){
    int x = 0;
    printf("Option: ");
    scanf("%d", &x);

    if(x == 1){
      printf("Account\n");
    } else if(x == 2){
      printf("Deposit\n");
    } else if(x == 3){
      printf("Withdraw\n");
    } else if(x == 4){
      printf("Quitting\n");
      quit = true;
    } else{
      printf("Not an option\n");
    }
  }
  return 0;
}
