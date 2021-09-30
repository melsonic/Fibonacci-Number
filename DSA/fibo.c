#include <stdio.h>
#include <string.h>
#define N 5000

void Assign(char b[], char a[])
{
    for (int i = N - 1; i >= 0; i--)
    {
        b[i] = a[i];
    }
}

void AddNs(char a[], char b[], char c[])
{
    int x = 0;
    for (int i = N - 1; i > -1; i--)
    {
        int j = (a[i] - '0') + (b[i] - '0') + x;
        c[i] = (j % 10) + '0';
        x = j / 10;
    }
}

void printIt(char a[]){
    printf("\n");
    for(int i=0; i<N;i++){
        if(a[i] == '0'){
            continue;
        }
        else if(a[i] != '0'){
            printf("%c",a[i]);
        }
    }
    printf("\n");
}

void calc(int n)
{
    int i;
    char f[N];
    char base[N];
    char baseOne[N];
    for(i=0; i<N;i++){
        f[i] = '0';
        base[i] = '0';
        baseOne[i] = '0';
    }
    baseOne[N-1] = '1';
    for (i = 1; i < n; i++)
    {
        AddNs(base, baseOne, f);
        Assign(base, baseOne);
        Assign(baseOne, f);
    }

    printIt(f);
    
}

int main()
{
    int n, i;
    printf("Enter n : ");
    scanf("%d", &n);
    calc(n);
    return 0;
}
