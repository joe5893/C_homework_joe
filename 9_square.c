#include <stdio.h>
#include <stdlib.h>

int square(int n){
	if(n<0)
		return NULL;//������warning 
	if(n==0){
		return -1;//return 0���� 
	}
	int i,ans=100;
	//scanf("%d",&n);
	int temp=n*10000; //���ܱ�֤��������Ҳ���㣬��ʹ�ܱ�֤��Ч��Ҳ̫���� 
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
		b[j]=square(x);//����Ҫ���浽b[j]���棬ֱ�Ӵ�ӡ�������� 
	}
	
	for(j=0;j<num;j++){
		if(b[j]==NULL){
			printf("ERROR\n");
			continue; //����continue 
		}
		if(b[j]==-1){
			printf("0.00\n");
			continue;//����continue 
		}
		printf("%.2f\n",b[j]*1.0/100);
	}
	
	free(b);
	
	return 0;
}
