#include <stdio.h> 
#include <stdlib.h>
#include "mymalloc.c" 
#include <time.h> 



int main(int argc, char **argv){

//Memgrind Workload A 

  struct timeval startA, endA;
  gettimeofday(&startA, NULL); 
  int a0, a1, k;
  void *arr[3000];
  for (k=0;k<100;k++){
   for (a0=0;a0<3000;a0++){
      arr[a0]= malloc(1); 
    }
   for(a1=0;a1<3000;a1++){
      free(arr[a1]); 
    }
  }
  gettimeofday(&endA, NULL); 
  printf("Avg time for Workload A: %ld microseconds\n", ((endA.tv_sec * 1000000 + endA.tv_usec)
        - (startA.tv_sec * 1000000 + startA.tv_usec)) / 100);



//Memgrind Workload B 

   int b, k2; 
   struct timeval startB, endB;
   gettimeofday(&startB, NULL); 
   for(k2=0;k2<100;k2++){
      for(b=0;b<3000;b++){
        free((void*)malloc(1));
     }
   }

   gettimeofday(&endB, NULL); 
   printf("Avg time for Workload B: %ld microseconds\n", ((endB.tv_sec * 1000000 + endB.tv_usec)
        - (startB.tv_sec * 1000000 + startB.tv_usec)) / 100);


//Memgrind Workload C. 
 

  struct timeval startC, endC;
  gettimeofday(&startC, NULL); 

  void *arrC[3000]; 
  time_t t;
  int randomC, C, k3;
  int D = 0;
  int mallocCount=0;
  int freeCount=0;
  srand((unsigned) time(&t));
  int counter = 0; 

  for(k3=0;k3<100;k3++){
    for( C = 0 ; ; C++ ){
      char *testB;
      randomC = rand() % 2;
      if(randomC == 0 && mallocCount <3000 ){  //perform malloc
         mallocCount++;
         arrC[C] = malloc(1); 
      }
      else if(randomC == 1 && mallocCount > freeCount){
         freeCount++;
         free(arrC[D]);
         D++;
         C--;
      }
      else if( (mallocCount+ freeCount) < 6000){   
      C--;      
      }
      else {
         break; 
      }
   }
 }
    gettimeofday(&endC, NULL); 

    printf("Avg time for Workload C: %ld microseconds\n", ((endC.tv_sec * 1000000 + endC.tv_usec)
        - (startC.tv_sec * 1000000 + startC.tv_usec)) / 100 );



//Memgrind Workload D 

 void *arrC1[3000]; 
 time_t t1;
 int totalSize = 5000;
 int randomC1, randomSize, C1, k4;
 int D1 = 0;
 int mallocCount1=0;
 int freeCount1=0;
 srand((unsigned) time(&t1));
 int counter1 = 0; 

 struct timeval startD, endD;
 gettimeofday(&startD, NULL);

 for(k4=0;k4<100;k4++){
  for( C1 = 0 ; ; C1++ ) 
    {
      randomC1 = rand() % 2;
      if(randomC1 == 0 && mallocCount1 <5){  //perform malloc
         randomSize = rand() % 200; //290
         totalSize = totalSize - randomSize - sizeof(struct metablock);
         if (totalSize > (randomSize + sizeof(struct metablock)) ) {
            mallocCount1++;
            arrC1[C1] = malloc(randomSize); 
         } 
         else{
            mallocCount1++;
          }
         }
      else if(randomC1 == 1 && mallocCount1 > freeCount1){
         freeCount1++;
         free(arrC1[D1]);
         D1++;
         C1--;
      }
      else if( (mallocCount1+ freeCount1) < 10 ){   
          C1--;      
      }
      else{
         break; 
      }
   }
}

 gettimeofday(&endD, NULL); 

  printf("Avg time for Workload D: %ld microseconds\n", ((endD.tv_sec * 1000000 + endD.tv_usec)
        - (startD.tv_sec * 1000000 + startD.tv_usec)) );


// Memgrind Workload E

  struct timeval startE, endE;
  gettimeofday(&startE, NULL);
  int p,q,r;
  void *array[500];
  for(r=0;r<100;r++){
    for(p=1;p<=300;p++){
      array[p] = malloc(p);
  }
    for(q=300;q>0;q--){
      free(array[q]);
    }
  }
  gettimeofday(&endE, NULL); 

  printf("Avg time for Workload E: %ld microseconds\n", ((endE.tv_sec * 1000000 + endE.tv_usec)
        - (startE.tv_sec * 1000000 + startE.tv_usec)) / 100);




//Memgrind Workload F

  struct timeval startF, endF;
  gettimeofday(&startF, NULL);

  int x,y,m;

  void *arrayF[500];

  for(m=0;m<100;m++){
   int z = 300; 
   for(x = 1; x<=300; x=x+2){
      arrayF[x] = malloc(z); 
      z--; 
    }
   for(y = 0; y<300; y=y+2){
     free(arrayF[y]);
    }
 }

gettimeofday(&endF, NULL); 

printf("Avg time for Workload F: %ld microseconds\n", ((endF.tv_sec * 1000000 + endF.tv_usec)
        - (startF.tv_sec * 1000000 + startF.tv_usec)) / 100);


  return 0; 
}

