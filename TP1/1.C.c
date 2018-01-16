#include <stdio.h>
#include <stdlib.h>

int sumPara(int i, int pk, int *tab) {

  int j = i;
  int d = 1;

  for (int c = 2; c < pk; c++) {
    if (j % 2 == 0) {
      if (i + a < pk) {
        tab[i] += tab[i + d];
      }
      d *= 2;
      j /= 2;
    }
  }
}

int main(int argc, char const *argv[]) {

  int errprint;
  int errscan;
  int k;
  int result = 0;

  if (argv[1] == NULL) {
    errprint = printf("Rentrée un int pluise\n");
    scanf("%d", &k);
    if (k < 0) {
      perror("L'input doit etre superieur ou egale a 0");
      exit(-1);
    }
  } else {
    k = atoi(argv[1]);
  }

  if (k < 0) {
    perror("L'input doit etre superieur ou egale a 0");
    exit(-1);
  }

  int pk = 1 << k;
  int tab[pk];

  for (int i = 0; i < pk; i++) {
    tab[i] = i;
  }

  //for processor in parallel do sumPara(i, pk, tab);
  result = tab[0];
  printf("Le résultat vaut : %d\n", result);

  // La compléxité est de O(n) ou O(2^k)
  return 0;
}
