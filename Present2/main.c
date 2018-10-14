#include <stdio.h>
#include <unistd.h>
#include <string.h>

char UserName[100];
char strangeMess[] = {
  218, 217, 183, 158, 143, 143, 134, 223, 189, 150, 141, 139, 151, 155, 158, 134, 223, 139, 144, 223, 134, 144, 138, 218, 211, 217, 183, 158, 143, 143, 134, 223, 189, 150, 141, 139, 151, 155, 158, 134, 223, 139, 144, 223, 134, 144, 138, 218, 211, 217, 183, 158, 143, 143, 134, 223, 189, 150, 141, 139, 151, 155, 158, 134, 211, 223, 155, 154, 158, 141, 223, 219, 218, 211, 217, 183, 158, 143, 143, 134, 223, 189, 150, 141, 139, 151, 155, 158, 134, 223, 139, 144, 223, 134, 144, 138, 222, 218, 217, 217, 217, 217, 131, 161, 131, 161, 131, 161, 172, 144, 223, 144, 145, 223, 139, 151, 150, 140, 223, 137, 154, 141, 134, 223, 140, 143, 154, 156, 150, 158, 147, 223, 155, 158, 134, 217, 182, 223, 136, 144, 138, 147, 155, 223, 147, 150, 148, 154, 223, 139, 144, 223, 140, 158, 134, 223, 139, 144, 223, 134, 144, 138, 217, 182, 223, 151, 144, 143, 154, 223, 134, 144, 138, 216, 147, 147, 223, 158, 147, 136, 158, 134, 140, 223, 153, 150, 145, 155, 223, 151, 158, 143, 143, 150, 145, 154, 140, 140, 217, 182, 145, 223, 136, 151, 158, 139, 154, 137, 154, 141, 223, 134, 144, 138, 223, 146, 158, 134, 223, 155, 144, 209, 217, 217, 218, 204, 187, 158, 145, 154, 147, 245
};

void removeTrailingNewline(char c[]){
  int n = strlen(c);
  if(c[n - 1] == '\n') c[n - 1] = '\0';
}

void LongPause(){
  int milliseconds = 1000 * 1000;
  usleep(milliseconds);
}

void ShortPause(){
  int milliseconds = 100 * 1000;
  usleep(milliseconds);
}

void eraseLastCharacter(){
  char *message = "\b \b";
  printMessage(message);
}

int printCharOrResolveCommand(char c){
  if(c == '%') LongPause();
  else
  if(c == '^') eraseLastCharacter();
  else
  if(c == '$') printMessage(UserName);
  else
  if(c == '&') putchar('\n');
  else
  if(c == '3') putchar('\t');
  else
    putchar(c);
  fflush(stdout);
  ShortPause();
}

void printMessage(char c[]){
  int i, n = strlen(c);
  for(i = 0; i < n; ++ i){
    printCharOrResolveCommand(c[i]);
  }
}

int decodeChar(char c){
  int ans;
  ans = c ^ 255;
  return ans;
}

void decodeString(char c[]){
  int i, n = strlen(c);
  for(i = 0; i < n; ++ i){
    c[i] = decodeChar(c[i]);
  }
}

void init(){
  printf("Please enter your name: ");
  fgets(UserName, 100, stdin);
  removeTrailingNewline(UserName);
  fflush(stdin);
  decodeString(strangeMess);
}

int main(){
  init();
  printMessage(strangeMess);
  return 0;
}
