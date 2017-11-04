#include <stdio.h>
#include <stdlib.h>

int square(int n){
	if(n<0)
		return NULL;//编译有warning 
	if(n==0){
		return -1;//return 0即可 
	}
	int i,ans=100;
	//scanf("%d",&n);
	int temp=n*10000; //不能保证最大的整数也能算，即使能保证，效率也太差了 
	for(i=101;i<temp;i++){
		if((temp-ans*ans)>(temp-i*i)&&(temp-i*i)>0){
			ans=i;
		}
		else{
			break;
		}
	}
	
	return ans;
}

int main(){
	int num;
	scanf("%d",&num);
	int j,*b=(int*)malloc(sizeof(int)*num);
	for(j=0;j<num;j++){
		int x;
		scanf("%d",&x);
		b[j]=square(x);//不需要保存到b[j]里面，直接打印出来即可 
	}
	
	for(j=0;j<num;j++){
		if(b[j]==NULL){
			printf("ERROR\n");
			continue; //不用continue 
		}
		if(b[j]==-1){
			printf("0.00\n");
			continue;//不用continue 
		}
		printf("%.2f\n",b[j]*1.0/100);
	}
	
	free(b);
	
	return 0;
}
