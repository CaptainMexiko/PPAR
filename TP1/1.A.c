#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

int errprint;
int errscan;
int k;
int result = 0;

  if(argv[1] == null){
    errprint = printf("Rentrée un int pluise\n");
    if(errprint != 0){
      perror("Erreur de printf :");
      exit(-2);
    }
    scanf("%d\n", &k);
    if (k < 0){
      perror("L'input doit etre superieur ou egale a 0")
      exit(-1);
    }
  }
  else{
    k = argv[1]
  }

  if(k < 0){
    perror("L'input doit etre superieur ou egale a 0")
    exit(-1);
  }

int pk = 1 << k
int tab[pk];

  for (int i = 0; i < pk; i++) {
    tab[i] = i;
  }

  return 0;
}
