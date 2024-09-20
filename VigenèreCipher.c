#include <stdio.h>
#include <string.h>

#define MAX_TERMS 20
#define MAX_STR 200
#define alph 26



int indexof(char a, const char str[]) {
    char temp2 = a;
    if (a >= 'A' && a <= 'Z') {
        temp2 = (char) (temp2 + 32);
    }
    int i = 0;
    for (; i < alph; i++)
        if (str[i] == temp2)
            break;

    return i;

}
void encode(char str[], char key[], char e[], char *terms[]) {

    char alphabetIndexes[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                              's',
                              't', 'u', 'v', 'w', 'x', 'y', 'z'};//the alphabet we go over them;
    int i = 0;// for the index of keys loop
    int l = 0;// go over the str and e and alphabt
    int t = 0;//for terms






    while (l < strlen(str) && l<MAX_STR) {

        // inorder to make cycle over key
        int keyIndex = indexof(key[i], alphabetIndexes);
        if (i == strlen(key)) { i = 0; }

        int charIndex = indexof(str[l], alphabetIndexes);//the index of letter from str array
        int encodeIndex = charIndex + keyIndex;
        if (encodeIndex >= alph)
            encodeIndex = encodeIndex - alph;
        if ((str[l] >= 'A' & str[l] <= 'Z') || (str[l] >= 'a' & str[l] <= 'z')) {
            e[l] = alphabetIndexes[encodeIndex];
            i++;
            l++;
        } else {
            e[l] = str[l];
            l++;
        }
    }
    e[l] = '\0';

    for (int g = 0; g < MAX_TERMS; g++)
        terms[g] = NULL;


    int bool = 1;
    l = 0;
    while (l < strlen(e) && l<MAX_STR && t < MAX_TERMS) {
        if (e[l] == ' ') {
            bool = 1;
        } else {
            if (bool == 1) {
                terms[t] = &e[l];
                t++;
                bool = 0;
            }
        }
        l++;
    }

}
void getIthElement(char e[], char *terms[], int i, char out[]) {
    int wordscount = 0;
    for (int k = 0; k < MAX_TERMS; k++) {
        if (terms[k] != NULL)
            wordscount++;
    }
    if (i >= wordscount) {
        strcpy(out, "");
        return;
    }
    int j = 0;
    while (terms[i] != NULL && terms[i][j] != ' ' && terms[i][j] != '\0') {
        if (j > MAX_TERMS)
            break;
        out[j] = terms[i][j];
        j++;
        // p++;
        out[j] = '\0';


    }

}
