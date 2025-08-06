#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a, const void *b) {
return (*(int*)a - *(int*)b);
}
int singleNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    int number=1;
    int result=nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i]==result){
            number++;
        }
        else{
            result=nums[i];
            number=1;
        }
        if(number>(numsSize/2)){
            break;
        }
    }
    return result;
}
int main(){
    int result=0;
    int numsSize=0;
    int *nums=(int *)malloc(numsSize);
    scanf("%d\n",&numsSize);
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    result=singleNumber(nums,numsSize);
    printf("%d\n",result);
    free(nums);
    return 0;
}