#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// This will crack any DES-encrypted password that is 8 characters or less.
// It will encrypt each word in the dictionary and check if it's the same as what the user supplies. If it isn't, we go through every ascii combo of 8 letters.
int main(int argc, char* argv[])
{
    char salt[2];
    strncpy(salt, argv[1], 2);
    printf("Salted\n");
    char dictWord[128];
    FILE *F;
    char encrypted[128];
    strncpy(encrypted, argv[1], sizeof(encrypted));
    printf("File made\n");
    F = fopen("/usr/share/dict/words", "r");
    printf("Dictionary opened.\n");
    while(fgets(dictWord, 128, F))
    {
        printf("Got word %s...\n", dictWord);
        if(!strcmp(dictWord, "A"))
            printf("dictWord compares to A.\n");
        if(strlen(dictWord) <=9)
        {
            printf("The string is less than 9 chars.\n");
            if(!(strcmp(crypt(dictWord,salt), encrypted)))
            {
            printf("%s is the password.", dictWord);
            return 0;
            }
               
        }
    }
    printf("Moving on to the brute force algorithm that tries all ascii combos.");
    for(dictWord[0]= 126; dictWord[0] >=32; dictWord[0]--)
    {
        for(dictWord[1]= 126; dictWord[1] >=32; dictWord[1]--)
        {
            for(dictWord[2]= 126; dictWord[2] >=32; dictWord[2]--)
            {
                for(dictWord[3]= 126; dictWord[3] >=32; dictWord[3]--)
                {
                    for(dictWord[4]= 126; dictWord[4] >=32; dictWord[4]--)
                    {
                        for(dictWord[5]= 126; dictWord[5] >=32; dictWord[5]--)
                        {
                            for(dictWord[6]= 126; dictWord[6] >=32; dictWord[6]--)
                            {
                                for(dictWord[7]= 126; dictWord[7] >=32; dictWord[7]--)
                                {
                                    printf("%s\n", dictWord);
                                    if(!(strcmp(crypt(dictWord,salt), encrypted)))
                                    {
                                        printf("%s is the password.", dictWord);
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

