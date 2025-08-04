#ifndef JUDGE_H
#define JUDGE_H
#include "human.h"
#include<string.h>
int woman_judge_perference(Human *she,Human *other){
    int reduce_score=0;
    if(!strcmp(other->gender,"man")){
        she->judge_other_facegrade=other->facegrade-1;
        reduce_score++;
        if(other->is_confident!=1){
            she->judge_other_facegrade-=1;
            reduce_score++;
        }
        if(other->is_make!=1){
            she->judge_other_facegrade-=1;
            reduce_score++;
        }
        if(other->is_retouch!=1&&reduce_score<3){
            she->judge_other_facegrade-=1;    
        }
        reduce_score=0;
    }
    else{
        if(other->is_confident!=1){
            she->judge_other_facegrade-=1;
            reduce_score++;
        }
        if(other->is_make!=1){
            she->judge_other_facegrade-=1;
            reduce_score++;
        }
        if(other->is_retouch!=1&&reduce_score<2){
            she->judge_other_facegrade-=1;
        }
        reduce_score=0;
    }
    if(she->judge_other_facegrade<0){
        she->judge_other_facegrade=1;
    }
    return she->judge_other_facegrade;
}
int man_judge_perference(Human *he,Human *other){
    int reduce_score=0;
   if(!strcmp(other->gender,"man")){
        he->judge_other_facegrade=other->facegrade-1;
        reduce_score++;
        if(other->is_confident!=1){
            he->judge_other_facegrade-=1;
            reduce_score++;
        }
        if(other->is_make==1){
            he->judge_other_facegrade-=1;
            reduce_score++;
        }

        if(other->is_retouch==1&&reduce_score<3){
            he->judge_other_facegrade-=1;

        }
        reduce_score=0;
    }
    
    else{
        if(other->is_confident!=1){
            he->judge_other_facegrade=other->facegrade-1;
        }
        if(other->is_retouch==1){
            he->judge_other_facegrade-=1;
        }
    }
     if(he->judge_other_facegrade<0){
        he->judge_other_facegrade=1;
    }
    return he->judge_other_facegrade;

}
float possession_generate(Human *h){
    h->judge_other_possession=h->pos->car+h->pos->house+h->pos->salarygrade*0.4;
    return h->judge_other_possession;
}
float woman_judge_possession(Human *she,Human *other){
     if(!strcmp(other->gender,"man")){
        she->judge_other_possession=possession_generate(other)-1;
        if(she->is_confident==1){
            she->judge_other_possession-=0.5;
        }
    }
    else{
         she->judge_other_possession=possession_generate(other)-0.5;
        if(she->is_confident==1){
            she->judge_other_possession-=0.5;
        }
    }
    if(she->judge_other_possession<0){
        she->judge_other_possession=0;
    }
    return she->judge_other_possession;
}
float man_judge_possession(Human *he,Human *other){
    if(!strcmp(other->gender,"man")){
        he->judge_other_possession=possession_generate(other)-0.5;
        if(he->is_confident==1){
            he->judge_other_possession-=0.5;
        }
    }
    else{
        if(he->is_confident==1){
            he->judge_other_possession=possession_generate(other)-0.5;
        }
    }
    if(he->judge_other_possession<0){
        he->judge_other_possession=0;
    }
    return he->judge_other_possession;
}
void final_judge(Human *h){
    h->finaljudge=h->judge_other_facegrade*0.9+h->judge_other_possession*1.1;
    printf("对你的最终评级是：%f\n对你的回答是：",h->finaljudge);
    if(!strcmp(h->gender,"man")){
        float his_finalgrade=((h->pos->car+h->pos->house+h->pos->salarygrade*0.4)*1.1+h->facegrade*0.9);
        if(h->finaljudge>=his_finalgrade)
        {
            printf("你很优秀，我很乐意。\n");
        }
        else{
            printf("不好意思我们不合适。\n");
        }
    }
    else{
        if(h->finaljudge>=h->facegrade)
        {
            printf("你配我勉勉强强吧。（自信）\n");
        }
        else{
            printf("你能不能拿镜子照照你自己，你配的上我吗？（鄙视）\n");
        }
    }
}

float calculate_matchrate(Human *h){
    return h->finaljudge/h->facegrade;
}
#endif
