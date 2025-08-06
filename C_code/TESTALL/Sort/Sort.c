#include<stdio.h>
#include<stdlib.h>
void InsertionSort(int arr[], int n) {
    int i, j, key;
    
    // 首先找出最小值放在arr[0]作为哨兵
    int min = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    if (min != 0) {
        int temp = arr[0];
        arr[0] = arr[min];
        arr[min] = temp;
    }
    
    // 现在arr[0]是最小值，可以作为哨兵
    for (i = 2; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key) {  // 不需要检查j>=0因为arr[0]是最小的
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void BubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void SelectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  // 只需遍历到 n-1
        int min = i;  // 记录最小值的索引，初始化为当前i
        for (int j = i + 1; j < n; j++) {  // 从 i+1 开始找最小值
            if (arr[j] < arr[min]) {
                min = j;  // 更新最小值索引
            }
        }
        // 交换 arr[i] 和 arr[min]
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main(){
    int choose;
    while(1)
    {
        printf("请输入你想要排序的数字个数\n");
        int num;
        scanf("%d",&num); 
        getchar();
        printf("请输入你想要排序的数字个数的数字\n");
        int *arr=malloc(num*sizeof(int));
        for(int i=0;i<num;i++){
            scanf("%d",&arr[i]);
        }
        printf("choose one Sorttype(1.InsertionSort/2.BubbleSort/3.SelectSort)\n");
        scanf("%d",&choose); 
        getchar();
        switch (choose)
        {
        case 1:
            printf("you choose InsertionSort\n");
            InsertionSort(arr,num);
            break;
        case 2:
            printf("you choose BubbleSort\n");
            BubbleSort(arr,num);
            break;
        case 3:
            printf("you choose SelectSort\n");
            SelectSort(arr,num);
            break;
        default:
            break;
        }
        printf("从小到大:\n");
        for(int i=0;i<num;i++)
        {
            printf("%d",arr[i]);
            if(i!=(num-1))
            {
                printf("--->");
            }
        }
        printf("\n");
        free(arr);
        printf("是否退出？(Y/N):");
        char choose;
        scanf("%c",&choose);
        getchar();
        if(choose=='Y'||choose=='y'){
            break;
        }
    }
    return 0;
}