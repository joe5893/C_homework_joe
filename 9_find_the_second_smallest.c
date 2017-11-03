#include <stdio.h>
#include <stdlib.h>
//find the second smallest integer

int find(int *a,int len){
	if(a<2)
		return NULL;//???
		//未考虑全部相等情况 
	
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
//		if(min2!=i&&){       //此处逻辑。。。待改进！ 
//			min2=a[i];
//		}
	}
	
	return min2;
}
void d(){
	int n,i,j;
	scanf("%d",&n);
	
	
	int *b=(int *)malloc(sizeof(int)*n);//保存每组的结果 
	for (i=0;i<n;i++){
		int num;//每组有几个元素
		scanf("%d",&num);
		int *a=(int *)malloc(sizeof(int)*num);
		
		for(j=0;j<num;j++){
			scanf("%d",&a[j]);
		}
		
		b[i]=find(a,num);
		
		free(a);
	}
	
	for(i=0;i<n;i++){
		if(b[i]==NULL){//不能用NULL !!!!!!!!!!!!!!!! 
			printf("ERROR");  //未完善 
		}
		else{
			printf("%d\n",b[i]);
		}
	}
	free(b);
	
} 


//从头向尾遍历,将最小数(相对)沉入尾部(相对)
void BubbleSort(int *arr,int sz){
    int i = 0;
    int j = 0;
    
    for(i=0;i<sz-1;i++){
    	//每冒泡一轮，就将本轮最小数放到末尾
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
    	//冒泡一次：把最小的一个冒到最后 
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
        //显示每轮冒泡结果： 
        printArr(arr,sz);
        
        //如果min2找到，终止冒泡 
        if(arr[sz-i-1]>min){
        	min2 = arr[sz-i-1];      
			min2found = 1;  	
        	printf("min2=%d\n",min2);
        	break;
        }
    }
    
    //如果冒完了是这种: 9555555 或者95,则前面不可能找到min2，需要特殊处理： 
    if(sz>1 && min2found==0 && arr[0]>arr[1]){
    	min2 = arr[0];      
		min2found = 1;  	
        printf("min2=%d\n",min2);
    }
    
    printf("min2found=%d\n",min2found);
}


void testLi(){
	//先针对一般的情况写，调通后，再处理特殊情况 
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
	//作业要求的输入和输出： 
}
int main(){
	testLi();
	
	//homework();
	
	return 0;
}
