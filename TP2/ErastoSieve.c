#include <stdbool.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_THREAD 2

int crible(bool *e, int n){

  double end = sqrt(n);
  #pragma omp parallel for schedule(dynamic)
    for (int i = 2; i < (int) end; i++) {
      for (int j = 2; j * i < n; j++) {
          e[j * i] = false;
      }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
  omp_set_num_threads(NUM_THREAD);

  int n = atoi(argv[1]);
  bool tabBool[n];

  for (int i = 0; i < n; i++) {
    tabBool[i] = true;
  }

  crible(tabBool, n);

  /*for (int i = 2; i < n; i++) {
    if(tabBool[i] == true){
      printf("%d ", i);
    }
  }*/

  return 0;
}
