#include<stdio.h>
#include<sys/ioctl.h>
#include<signal.h>
//fonction qui renvoit la taille du terminal
void term_size(void){
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  // 0 : est descripteur de fichier de l'entrée standard
  printf("Size is %d row %d cols\n", w.ws_row,w.ws_col);
}

//sighandler
//un pg redimentionné recoit sigwintch

void sig_handler(int sig){
  term_size();
}

int main(int argc, char **argv){
  
  signal(SIGWINCH, sig_handler);
  while(1){}
  return 0;
}
