#ifndef PREFERENCE_H
#define PREFERENCE_H
#include "human.h"
void  Woman_perference_generator(Human *h){
    if(h->is_make==1){
        h->facegrade+=2;
    }
    if(h->is_retouch==1){
        h->facegrade+=2;
    }
    if(h->is_confident==1){
        h->facegrade+=2;
    }
}
void  Man_perference_generator(Human *h){
    if(h->is_make==1){
        h->facegrade+=1;
    }
    if(h->is_retouch==1){
        h->facegrade+=2;
    }
    if(h->is_confident==1){
        h->facegrade+=1;
    }
}

#endif