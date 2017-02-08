//Written by Anirudh Balachandran and David Alummoottil

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>   //see if we can delete at the end 
#include "mymalloc.h" 



void memory_Seperator(struct metablock *curr, int inputBytes){
 if(curr -> B_size == (inputBytes+sizeof(struct metablock))){
    curr -> isFree = 0;
  }
 else{ 
  struct metablock *new_Block = (void*)((void*)curr + inputBytes + sizeof(struct metablock));  
  new_Block -> B_size = curr -> B_size - inputBytes -sizeof(struct metablock);
  new_Block -> next = curr -> next; 
  new_Block -> isFree = 1;
  curr -> isFree = 0;
  curr -> B_size = inputBytes + sizeof(struct metablock); 
  curr -> next  = new_Block;
    }
}



void * myMalloc(int inputBytes, char *file, int line){
   void * finResult = (void *) NULL; 
   struct metablock *curr ;
 
   if(!(metaList->B_size)){   
     metaList -> B_size = 10000; 
     metaList -> isFree = 1;  
     metaList -> next = NULL;
   }
   curr = metaList; 
     while(curr -> next != NULL && ( curr->isFree == 0|| curr->B_size < (inputBytes + sizeof(struct metablock)))){ 
       curr = curr -> next; 
     }
     if(curr->B_size >= (inputBytes+sizeof(struct metablock))){// && curr-> B_size<=10000 && curr->isFree == 1){
        memory_Seperator(curr , inputBytes);
        finResult = (void*)(curr); 
     }
     else{
       finResult = NULL;
   }
  
  return finResult;
}


void myFree(void* freePtr, char *file, int line){
    struct metablock *curr;
    struct metablock *newMem = metaList;
   
    if(((void*)memory<=freePtr) && (freePtr<=(void*)(memory+10000))){
       while(newMem->next != NULL ){
           if(newMem == freePtr ){
            if(newMem->isFree == 0){
               newMem->isFree = 1;
               curr=metaList;
               while(curr->next!=NULL){ 
                 if((curr->isFree==1) && (curr->next->isFree==1)){
                   curr->B_size+=(curr->next->B_size);
                   curr->next=curr->next->next;
                 }
                 if(curr->next!=NULL){
                   curr=curr->next;
                 } 
                }
              break;  
           }         
          else{
           //ERROR_POINTER_FREE;
           return; 
          }  
        }
        newMem=newMem->next;
     }  
  return; 
  }
  else{
     // ERROR_NOT_ALLOCATED;  
      return;
   }
} 

