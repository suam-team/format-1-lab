// gcc chall.c -m32 -s -o chall

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 200

void flag()
{
  FILE *fptr;
  char flag[BUFFER_SIZE];
  if ((fptr = fopen("flag.txt", "r")) == NULL)
  {
    puts("[ERROR] Cannot open the flag file!\n");
    exit(1);
  }
  fgets(flag, BUFFER_SIZE - 1, fptr);
  printf("You are authorized, here's the flag: %s\n", flag);
  fclose(fptr);
  exit(0);
}

void pass_check()
{
  // Password input buffer
  char password[BUFFER_SIZE];

  // Correct password storage
  char authorized_password[BUFFER_SIZE];
  FILE *fp;
  while (1)
  {
    if ((fp = fopen("password.txt", "r")) == NULL)
    {
      puts("[ERROR] Cannot open the password file!\n");
      exit(1);
    }

    fgets(authorized_password, BUFFER_SIZE - 1, fp);
    fclose(fp);

    puts("***** AUTHORIZED ACCESS ONLY *****\n");
    puts("Please enter your password: ");

    // Receive password input
    fgets(password, BUFFER_SIZE - 1, stdin);

    // Check if the password is correct
    if (strncmp(password, authorized_password, strlen(authorized_password)) != 0)
    {
      // Clear the authorized_password variable
      strcpy(authorized_password, "");

      puts("Your password is: ");
      printf(password);
      puts("The password is incorrect!\n");
    }
    else
    {
      flag();
    }
  }
}

int main()
{
  setvbuf(stdout, NULL, _IONBF, 0);
  pass_check();
  return 0;
}