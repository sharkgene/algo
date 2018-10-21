#include <iostream>

int main(void)
{
    int n, m,i, f[20]={0};
    scanf("%d %d",&n,&m);
    for(i=2;i<=n;i++)
    {
        f[i]=(f[i-1]+m)%i;
        printf("%d个人报数，报到%d的出列，最后的胜者下标为%d\n", i,m,f[i]);
    }
    printf("The winner is %d\n", f[n]+1);
}
