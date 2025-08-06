#ifndef HUMAN_H
#define HUMAN_H

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
typedef struct{
char name[20];
int age;
char gender[20];
int truegrade;
int facegrade;
int is_make;
int is_retouch;
int is_confident;
int judge_other_facegrade;
float judge_other_possession;
float finaljudge;
struct possession *pos;
}Human;
 struct possession{
    int salarygrade;
    int car;
    int house;
};

#endif