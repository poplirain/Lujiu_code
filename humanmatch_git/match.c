//1.妆越浓->人越丑
//2.3分女化妆5美颜7自认9
//3.3女>6男
/*int age;
char gender[20];
int truegrade;
int facegrade;
int is_make;
int is_retouch;
int is_confident;
int judge_other_facegrade;*/

#include "human.h"//人类生成
#include "preference.h" //外貌水平构成
#include "judge.h"//判断机制
Human h[10000];

void printf_true_human(Human *h,int start,int end){
    for(int i=start;i<end;i++)
    {
        printf("姓名：%s, 年龄：%d, 性别：%s, 真实颜值分数：%d, 车辆数：%d, 房子数：%d, 薪资等级：%d, 是否化妆：%d, 是否美颜： %d, 是否自信：%d\n",h[i].name,h[i].age,h[i].gender,h[i].truegrade,h[i].pos->car,h[i].pos->house,h[i].pos->salarygrade,h[i].is_make,h[i].is_retouch,h[i].is_confident);
    }
}

void printf_self_human(Human *h){
        printf("姓名：%s, 年龄：%d, 性别：%s, 自己认为自己的颜值分数：%d, 车辆数：%d, 房子数：%d, 薪资等级：%d, 是否化妆：%d, 是否美颜： %d, 是否自信：%d\n",h->name,h->age,h->gender,h->facegrade,h->pos->car,h->pos->house,h->pos->salarygrade,h->is_make,h->is_retouch,h->is_confident);
}

void judge_specific_human(Human *h,Human *o){
    if(!strcmp(h->gender,"man"))
            {
                Man_perference_generator(h);
                h->judge_other_facegrade=man_judge_perference(h,o);
                h->judge_other_possession=man_judge_possession(h,o);
                h->finaljudge=h->judge_other_facegrade*0.9+h->judge_other_possession*1.1;
                printf("他的基本信息如下\n");
                printf_self_human(h);
            }
            else
            {
                Woman_perference_generator(h);
                h->judge_other_facegrade=woman_judge_perference(h,o);
                h->judge_other_possession=woman_judge_possession(h,o);
                h->finaljudge=h->judge_other_facegrade*0.9+h->judge_other_possession*1.1;
                printf("她的基本信息如下\n");
                printf_self_human(h);
            }
            printf("对你的评价是：");
            final_judge(h);
}
int main()
{
    Human *human;
    human=h;
    human[0].pos = malloc(sizeof(struct possession));
    if(!human[0].pos) 
    {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }
    int hnumber; 
    int totalnumber=1;
    bool is_first=true;
    bool is_same=false; 
    int choose_language;
    char translate[20];
    printf("欢迎游玩！\n");
    printf("ようこそ遊びに来てください\n");
    printf("回车下一步--->\n");
    getchar();
    printf("えっ、本当に？また告白するの？じゃあ、まずは自分の情報を教えてね。\n");
    printf("欸，不是吧，你又来表白了？那先说下个人信息吧\n");
    printf("回车下一步--->\n");
    getchar();
    printf("あなたの情報を入力してください。名前、年齢、性別、実際の顔の評価（0-10）を含めてください。\n");
    printf("请输入你的信息,包括姓名，年龄，性别(man/woman)，真实颜值分数（0-10）\n");
    scanf("%s %d %s %d",&human[0].name,&human[0].age,&human[0].gender,&human[0].truegrade);
    getchar();
    printf("あなたが何台の車を持っているのか、何軒の家を持っているのか、給与レベルが（0-10）のどれに当たるのかを知る必要があります。\n");
    printf("我还需要知道你有几辆车，几套房，薪资等级是（0-10）\n");
    scanf("%d %d %d",&human[0].pos->car,&human[0].pos->house,&human[0].pos->salarygrade);
    getchar();
    printf("メイクをしましたか（0/1）、この写真は美顔加工されていますか（0/1）、自分に対して十分自信がありますか（0/1）\n");
    printf("你化妆了吗（0/1），你这个照片美颜了吗（0/1）,你觉得自己足够自信吗(0/1)\n");
    scanf("%d %d %d",&human[0].is_make,&human[0].is_retouch,&human[0].is_confident);
    getchar();
    human[0].facegrade=human[0].truegrade;
    human[0].finaljudge=possession_generate(&human[0])*1.1+human[0].facegrade*0.9;
    printf("你的最终评级为：%f",human[0].finaljudge);
    while(1)
    {
        if(is_first==true){
            is_first== false;
            goto First;
        }
        char choose[20];
        printf("新しい目標を追加する必要がありますか？");
        printf("\n");
        printf("你需要添加新的目标吗？（Yes/No）:");
        printf("\n");
        scanf("%s,&choose");
        getchar();
        if(!strcmp(choose,"yes"))
        {
            printf("あなたは新しいものを好み、古いものを嫌う人です（嫌悪）。\n");
            printf("你这个喜新厌旧的人（厌恶）\n");
            printf("回车下一步--->\n");
            getchar();
First:
            printf("今回は何人に告白するつもりですか？：");
            printf("\n");
            printf("这回你要表白几个人：");
            printf("\n");
            scanf("%d",&hnumber);
            getchar();
            if(hnumber>1){
                char gender[20];
                if(!strcmp(h[0].gender,"man")){
                    strcpy(gender,"男");
                }
                else{
                    strcpy(gender,"女");
                }
                printf("お前、まったくクズだな。今はお前が本当に気持ち悪いと思ってるよ。\n");
                printf("你这家伙，简直就是个渣%s，我现在都觉得你很恶心欸。\n",gender);
                printf("回车下一步--->\n");
                getchar();
            }
            char other_gender[20];
            if(!strcmp(human[0].gender,"man")){
                strcpy(other_gender,"她");
            }
            else{
                strcpy(other_gender,"他");
            }
            if(!strcmp(other_gender,"他"))
            {
                printf("彼らの情報を早く教えてください。名前、年齢、性別、実際の容姿スコア（0-10）、車の台数、家の数、給与レベル（0-10）は？彼らはそれぞれメイクをしていますか？美容加工をしていますか？自信がありますか？\n");
            }
            else{
                printf("彼女たちの情報を早く教えてください。名前、年齢、性別、実際の美しさのスコア（0-10）、車の台数、家の数、給与レベル（0-10）は？彼女たちはそれぞれメイクをしていますか？美顔していますか？自信がありますか？\n");
            }
            printf("快点把%s们的信息告诉我,姓名，年龄，性别，真实颜值分数（0-10）,有几辆车，几套房，薪资等级是（0-10）?他们分别化妆吗，美颜了吗，自信吗？\n",other_gender);

            for(int i=totalnumber;i<(totalnumber+hnumber);i++)
            {
                human[i].pos = malloc(sizeof(struct possession));
                if(!human[i].pos)
                {
                    perror("内存分配失败");
                    (EXIT_FAILURE);
                }  
            scanf("%s %d %s %d %d %d %d %d %d %d",&human[i].name,&human[i].age,&human[i].gender,&human[i].truegrade,&human[i].pos->car,&human[i].pos->house,&human[i].pos->salarygrade,&human[i].is_make,&human[i].is_retouch,&human[i].is_confident);
            getchar();
            if(strcmp(human[i].gender,human[0].gender)==0){
                is_same=true;
            }
            human[i].facegrade=human[i].truegrade;
            }
            totalnumber+=hnumber;
        }
        if(is_same==true){
            printf("お前まだ同性が好きなのかよ、マジで最悪だな！！！プログラムの設定じゃなかったら、お前なんて無視してるところだよ！\n");
            printf("你居然还喜欢同性吗，你这家伙真的是糟糕到极点！！！要不是程序设定，我都不想理你这家伙口牙！！！！\n");
            printf("回车下一步--->\n");
            getchar();
        }
        printf("では、あなたが今告白しようとしている相手の一覧は以下の通りです：\n");
        printf("那么，你现在要表白的人员表如下：\n");
        printf_true_human(human,1,totalnumber);
        for(int i=1;i<totalnumber;i++)
        {
            if(!strcmp(human[i].gender,"man"))
            {
                Man_perference_generator(&human[i]);
                human[i].judge_other_facegrade=man_judge_perference(&human[i],&human[0]);
                human[i].judge_other_possession=man_judge_possession(&human[i],&human[0]);
                human[i].finaljudge=human[i].judge_other_facegrade*0.6+human[i].judge_other_possession*0.4;
                printf("第%d位| 他的基本信息如下\n",i);
                printf_self_human(&human[i]);
            }
            else
            {
                Woman_perference_generator(&human[i]);
                human[i].judge_other_facegrade=woman_judge_perference(&human[i],&human[0]);
                human[i].judge_other_possession=woman_judge_possession(&human[i],&human[0]);
                human[i].finaljudge=human[i].judge_other_facegrade*0.6+human[i].judge_other_possession*0.4;
                printf("第%d位| 她的基本信息如下\n",i);
                printf_self_human(&human[i]);
            }
            char gender_call[20];
            if(!strcmp(human[i].gender,"man")){
                strcpy(gender_call,"他");
            }
            else{
                strcpy(gender_call,"她");
            }
            printf("%s对你的外貌评级是%d的，对你的财产评级是%f\n",gender_call,human[i].judge_other_facegrade,human[i].judge_other_possession);
            final_judge(&human[i]);
            float matchrate=calculate_matchrate(&human[i])*100;
            printf("她和你的匹配度为%.2f%%,其中超出100%%部分为你超过%s预期部分，不足100%%部分为你距离%s预期部分，你可以通过改变条件来完成best match",matchrate,gender_call,gender_call);
        }
        char  endgoon[20];
        printf("まだ新しい人を探したいですか、それとも再度告白したいですか？(はい/いいえ)");
        printf("\n");
        printf("你还想继续物色新人吗/再次表白吗？(yes/no)");
        printf("\n");
        scanf("%s",&endgoon);
        getchar();
        if(!strcmp(endgoon,"no"))
        {
            break;
        }
        char is_change[20];
        printf("雑魚、お前の条件は変わったのか？（軽蔑）(はい/いいえ)");
        printf("\n");
        printf("杂鱼，你的条件有所变化吗？（鄙夷）(yes/no)");
        printf("\n");
        scanf("%s",&is_change);
        getchar();
        if(!strcmp(is_change,"yes"))
        {
            printf("今、何台車があって、何軒家があって、給料ランクは（0-10）どのくらい？\n");
            printf("你现在有几辆车，几套房，薪资等级是（0-10）\n");
            scanf("%d %d %d",&human[0].pos->car,&human[0].pos->house,&human[0].pos->salarygrade);
            getchar();
            printf("今、メイクした？この写真、加工した？自分に自信あると思う？\n");
            printf("现在，你化妆了吗（0/1），你这个照片美颜了吗（0/1）,你觉得自己足够自信吗(0/1)\n");
            scanf("%d %d %d",&human[0].is_make,&human[0].is_retouch,&human[0].is_confident);
            getchar();
            printf("まあまあの向上はあったので、まあいいでしょう、あなたを一目置くことはありませんでした。\n");
            printf("还算有所提升，也就还可以吧，才没有对你高看一眼\n");
            printf("回车下一步--->\n");
            getchar();
        }
        else{
            printf("あなたは本当に完全な木材の無駄遣いで、成長も進取の気性もまったくありません、少し(目を丸くします)\n");
            printf("你真的是一个彻头彻尾的废柴欸，一点长进和进取心都没有，略（翻白眼）\n");
            printf("回车下一步--->\n");
            getchar();
        }
    }
    printf("回车下一步--->\n");
    getchar();
    printf("雑魚、次回また告白に来てね！^_^\n");
    printf("杂鱼，下次再来表白哦！^_^\n");
    for(int i = 0; i < totalnumber; i++) {
        free(human[i].pos);
        human[i].pos = NULL; // 避免悬空指针
    }
    return 0;
}
