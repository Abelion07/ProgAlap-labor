#include <stdio.h>
int osztokszama(int n){
    int darab = 0;
    for (int i = 1; i <= n; i++){
        if (n%i==0){
            darab+=1;
        }    
    }
    return darab;
}

int hanybetu(int n){
    int ossz = 0;
    int karakterek[10] = { 5, 3, 5, 5, 4, 2, 3, 3, 5, 6};
    while (n > 0){
        ossz += karakterek[n%10];
        n /= 10;
    }
    return ossz;
}

int main()
{
    for (int i = 1000; i< 9999; i++){
        if (osztokszama(i) == 14 && hanybetu(i) == 14){
            printf("%d\n", i);
        }
    }
}
