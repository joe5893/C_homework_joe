#include <stdio.h>
#include <stdlib.h>
//find the second smallest integer

int find(int *a,int len){
	if(a<2)
		return NULL;//???
		//δ����ȫ�������� 
	
	int i,min=a[0],flag=1;// 
	for(i=1;i<len;i++){
		if(min>a[i]){
			min=a[i];			
		}
		if(a[i-1]!=a[i])
			flag=0;
	}
	if(flag){
		return NULL;//???
	}

	int min2=a[0];
	i=0;
	while(min2==min){
		i++;
		min2=a[i];
		
	}
	for(i=1;i<len;i++){
		if(a[i]>min&&min2>a[i]){
			min2=a[i];
		}
//		if(min2!=i&&){       //�˴��߼����������Ľ��� 
//			min2=a[i];
//		}
	}
	
	return min2;
}
void d(){
	int n,i,j;
	scanf("%d",&n);
	
	
	int *b=(int *)malloc(sizeof(int)*n);//����ÿ��Ľ�� 
	for (i=0;i<n;i++){
		int num;//ÿ���м���Ԫ��
		scanf("%d",&num);
		int *a=(int *)malloc(sizeof(int)*num);
		
		for(j=0;j<num;j++){
			scanf("%d",&a[j]);
		}
		
		b[i]=find(a,num);
		
		free(a);
	}
	
	for(i=0;i<n;i++){
		if(b[i]==NULL){//������NULL !!!!!!!!!!!!!!!! 
			printf("ERROR");  //δ���� 
		}
		else{
			printf("%d\n",b[i]);
		}
	}
	free(b);
	
} 


//��ͷ��β����,����С��(���)����β��(���)
void BubbleSort(int *arr,int sz){
    int i = 0;
    int j = 0;
    
    for(i=0;i<sz-1;i++){
    	//ÿð��һ�֣��ͽ�������С���ŵ�ĩβ
        for(j=0;j<sz-i-1;j++){
            if(arr[j]<arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
void printArr(int *arr,int sz){
	int k;
	for(k=0;k<sz;k++)
    {
    	printf("%d ",arr[k]);
    }
    printf("\n");
}
void li(int *arr,int sz){
	printArr(arr,sz);
    int i = 0;
    int j = 0; 
       
    int min,min2,k,min2found=0;
	
    for(i=0;i<sz-1;i++){
    	//ð��һ�Σ�����С��һ��ð����� 
        for(j=0;j<sz-i-1;j++){
            if(arr[j]<arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        
        if(i==0) {
        	min = arr[sz-1];
        }
        //��ʾÿ��ð�ݽ���� 
        printArr(arr,sz);
        
        //���min2�ҵ�����ֹð�� 
        if(arr[sz-i-1]>min){
        	min2 = arr[sz-i-1];      
			min2found = 1;  	
        	printf("min2=%d\n",min2);
        	break;
        }
    }
    
    //���ð����������: 9555555 ����95,��ǰ�治�����ҵ�min2����Ҫ���⴦�� 
    if(sz>1 && min2found==0 && arr[0]>arr[1]){
    	min2 = arr[0];      
		min2found = 1;  	
        printf("min2=%d\n",min2);
    }
    
    printf("min2found=%d\n",min2found);
}


void testLi(){
	//�����һ������д����ͨ���ٴ���������� 
	int b[]={6,5,10,8,5,13};	
	li(b,6);
	printf("\n");
	
	int dd[]={2,2,3,3,3};
	li(dd,5);
	printf("\n");
	
	int a[]={5,10,8,9,13};			
	li(a,5);
	printf("\n");
	
	int c[]={5,5,5,5,5};		
	li(c,5);
	printf("\n");
	
	int d[]={9,5,5,5,5};	
	li(d,5);
	printf("\n");
	
	int e[]={9,5};	
	li(e,2);
	printf("\n");

	int f[]={9};	
	li(f,1);
	printf("\n");
}
void homework(){
	//��ҵҪ������������� 
}
int main(){
	testLi();
	
	//homework();
	
	return 0;
}
