#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>


int main()
{
    int i,key,n,m=1;
    char text[100],c[100];

    while(m==1){
        printf("\t1 for Encrypt \n\t2 for Decrypt\nEnter your choice: ");
        scanf("%d",&n);
        fflush(stdin);
        //getchar();
        printf("Enter text: ");
        gets(text);
        printf("Enter key: ");
        scanf("%d",&key);



        if(n == 1){
            for(i = 0; i < strlen(text); i++){
                if(isalpha(text[i])){
                    if(islower(text[i]))
                        c[i] =(text[i] + key - 'a') % 26 + 'a';
                    else
                        c[i] = (text[i] + key - 'A') % 26 + 'A';
                }
                else if(isdigit(text[i]))
                    c[i] = (text[i] + key - '0') % 10 + '0';

                else if(text[i] == ' ') {
                    c[i] = ' ';
                }

            }
            c[i]='\0';
            printf("After Encryption the text is: %s\n\n",c);

        }
        else{
            for(i = 0; i < strlen(text); i++){
                if(isalpha(text[i])){
                    if(islower(text[i]))
                        c[i] = (text[i] - key - 'z') % 26 + 'z';
                    else
                        c[i] = (text[i] - key - 'Z') % 26 + 'Z';
                }
                else if(isdigit(text[i])) {
                    c[i] = (text[i] - key - '9') % 10 + '9';
                }
                else if(text[i] == ' ') {
                    c[i] = ' ';
                }

            }
            c[i]='\0';
            printf("After Decryption the text is: %s\n\n",c);
        }


        printf("  - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    }

    return 0;
}
