#include <stdio.h>
#include <string.h>

int verifica(int mT[], int mB[]) {
	int i;
    for (i=0; i<58; i++) if ((mT[i] > 0) && (mB[i] < mT[i])) return 0;
    return 1;
}

void minWindow(char * s, char * t) {
	int i;
    int tS = strlen(s);
    int tT = strlen(t);
    
    int mT[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (i=0; i<tT; i++) mT[t[i]-65]++;
    int mB[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int ini = 0;
    int fim = 0;
    int len = 0;
    char res[tS+1];
    strcpy(res, "");
    res[1] = '\0';
    do {
        mB[s[fim++]-65]++;

        if (verifica(mT, mB) == 1) {
            do mB[s[ini++]-65]--; while(verifica(mT, mB) == 1);
            if ((len == 0) || ((fim+1-ini) < len)) {
                len = fim+1-ini;
                strncpy(res, &s[ini-1], len);
                res[len] = '\0';
            }
        }
    } while (fim < tS);
    
    printf("%s\n", res);
}

int main() {
    minWindow("ADOBECODEBANC", "ABC");
    return 0;
}
