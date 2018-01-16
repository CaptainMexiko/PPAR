#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

int errprint;
int errscan;
int k;
int result = 0;

  if(argv[1] == NULL){
    errprint = printf("Rentrée un int pluise\n");
    scanf("%d", &k);
    if (k < 0){
      perror("L'input doit etre superieur ou egale a 0");
      exit(-1);
    }
  }
  else{
    k = atoi(argv[1]);
  }

  if(k < 0){
    perror("L'input doit etre superieur ou egale a 0");
    exit(-1);
  }

int pk = 1 << k;
int tab[pk];

  for (int i = 0; i < pk; i++) {
    tab[i] = i;
    result += tab[i];
  }

  printf("Le résultat vaut : %d\n", result);

  //La compléxité est de O(n) ou O(2^k)
  return 0;
}
