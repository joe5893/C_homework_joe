#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int f1(int n)
{
    int nt = n;
    int cnt = 0;
    int i;
    printf("n=%d, ",n);
    for(i = 2; i <= nt;i++)
        if( nt%i == 0){
        	printf("%d",i);
        	if(nt!=i) printf("*");
            cnt++;
            nt = nt/i;
            i = 1;
        }
    return cnt;
}


int f(int n)
{
    int i,nt = n;
    int cnt = 0;
    for(i = 2; i <= nt;i++)
        if(!(nt%i)){
            cnt++;
            nt = nt/i;
            i = 1;
        }
    return cnt;
}

void homework(){
	//作业要求的输入和输出： 
}
int main(int argc, char *argv[]) {
	 
    f(262) ;
    printf("\n");
    
    f(4950);
    printf("\n");
    
    f(13);
    printf("\n");
    
    //homework();
    
    return 0;
}
