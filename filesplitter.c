/*
コマンドライン引数1つ目はファイル名。
分割を行う。
但し、2つ目の引数が存在する場合は、合成を行う。
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc, char *argv[])
{
    FILE *fp;
    FILE *fp2;
    if(argc==1 || argc>3)//エラー
    {
        int i;
        printf("error:The count of command line args should be 2 or 3 (include program's name).\n Type any words to close.");
        scanf("%d",i);
        return;
    }
    if(argc==2)//コマンドライン引数が1個→分割
    {
        fp= fopen(argv[1],"rb");
        if(fp==NULL)
        {
            int i;
            printf("error:");
            printf(argv[1]);
            printf("couldn't be found.\n Type any words to close.");
            scanf("%d",i);
            return;
        }
        int ch;
        for(int i=0;i<9999999;i++)//ほぼずっと(iは※との兼ね合いで、10進表示で15桁以下とする)
        //(filename)_(i).(拡張子)
        {
            char sfn[1000];//分割されたファイルの名前
            char myStr[15];//分割されたファイルの名前
            char fn[1000];//メモ書きファイルの名前
            if(strlen(argv[1]) < 1000-15-1)//※
            {
                strcpy(sfn,argv[1]);
                strcpy(fn,argv[1]);
            }
            else
            {
                printf("error:The filename is too long.\n Type any words to close.");
                scanf("%d",i);
                return;
            }
            strcat(sfn,"_");
            snprintf(myStr, 15, "%d", i);//※
            strcat(sfn,myStr);
            fp2= fopen(sfn,"wb");//分割出力されるファイルのポインタ。
            for(int cnt=0; cnt<(100000000);cnt++)//100MBずつ
            {
                ch = fgetc(fp);
                //chにはファイルの最初から最後まで1バイトずつ順番に格納される
                if(ch==EOF)//ファイルが終わったら
                {
                    strcat(fn,".17ec084");
                    fp2=fopen(fn,"wb");
                    fprintf(fp2,"This is a 17ec084 file used by fileSplitter.\n");
                    fprintf(fp2,"%d\n",cnt);
                    fprintf(fp2,"%d",i);
                    //合成時のためのメモ書きファイルを出力し、
                    return;//プログラムも終わり。
                }
                fprintf(fp2,"%c",ch);
                
            }
        }
               
        
    }
    if(argc==3)//コマンドライン引数が2個→合成
    {
        char fn[1000];//分割ファイル名
        char myStr[15];//分割ファイルの通し番号(文字列)
        char fn17ec084[1000];//メモ書きファイル名
        char maxc[15];//メモ書きファイルの3行目(分割ファイルの通し番号の最大値(文字列))
        strcpy(fn17ec084,argv[1]);
        strcat(fn17ec084,".17ec084");
        fp=fopen(fn17ec084,"r");//メモ書きファイルを開く
        if(fp==NULL)
        {
            printf("error:Such file doesn't exist, or 17ec084 file has been broken.\n Type any words to close.");
            int i;
            scanf("%d",i);
            return;
        }
        fgets(maxc, 100, fp);
        fgets(maxc, 100, fp);
        fgets(maxc, 100, fp);
        long max = strtol(maxc, NULL, 10);//分割ファイルの通し番号の最大値(long型)

        int ch;

        fp2=fopen(argv[1],"wb");

        for(int i=0; i<=max; i++)
        {
            strcpy(fn,argv[1]);
            strcat(fn,"_");
            snprintf(myStr, 15, "%d", i);
            strcat(fn,myStr);

            fp=fopen(fn,"rb");
            while ((ch = fgetc(fp)) != EOF )
            {
                fprintf(fp2,"%c",ch);
            }

            strcpy(fn,argv[1]);
            //remove(fn);
        }
        //remove(fn17ec084);
        return;
    }    

}
