#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
	//��Ϊָ����wordcount202031100314 -c input.txt
	//argv[2]��ı����ļ��� 
    FILE *fp;
    int cnt = 0;
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");  //û�д��ļ� 
        return 0;
    }
    if (argv[1][1] == 'w')   //���㵥���� 
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
        printf("������=%d\n", cnt);
    }
    else if (argv[1][1] == 'c')   //�����ַ��� 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("�ַ���=%d", cnt);
    }
    fclose(fp);
    return 0;
}


