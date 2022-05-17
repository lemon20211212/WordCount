#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
	//因为指令是wordcount202031100314 -c input.txt
	//argv[2]存的便是文件名 
    FILE *fp;
    int cnt = 0;
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");  //没有此文件 
        return 0;
    }
    if (argv[1][1] == 'w')   //计算单词数 
    {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF)
        {
            cnt ++;
            int i=1;
            for (i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("单词数=%d\n", cnt);
    }
    else if (argv[1][1] == 'c')   //计算字符数 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("字符数=%d", cnt);
    }
    fclose(fp);
    return 0;
}


