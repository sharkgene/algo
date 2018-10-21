#include <iostream>

int main(void)  
{  
    int n, m,i, s=0;  
    scanf("%d %d",&n,&m);  
    for(i=2;i<=n;i++)  
    {  
        s=(s+m)%i;  
    }  
    printf("The winner is %d\n", s + 1);  
}  
