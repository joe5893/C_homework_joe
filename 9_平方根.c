#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ţ�ٵ�������ƽ���� 
void newton(){
	float a;   
    float x;      //xΪ������  
    int i=100;    //����ѭ���Ĵ���a  
    printf("������Ҫ��������:");  
    scanf("%f",&a);  
    x=a/2;  
    while(i--)  
    {  
        x=(x+a/x)/2;
		printf("%.2f  ",x)  ;
    }  
    printf("�����Ľ��Ϊ:%f\n",x);  
	
	//return ans;
}
//ţ�ٵ�������ƽ����
double Sqrt(double a,double p)//a�Ǳ���ƽ��������p�����󾫶�
{ 
    double x=1.0;double cheak; 
    do  
   { 
        x = (a / x + x) / 2.0; 
        cheak = x * x - a; 
    } while((cheak >= 0 ? cheak : -cheak) > p); 
     
    return x; 
}
void testSqrt(){
	printf("%.4f\n",Sqrt(2.0,0.0001));
    printf("%.4f\n",Sqrt(0.09,0.0001));
}

//�ö��ֱƽ���,�������5��ƽ����,��ô2^2=4,3^2=9,
//����֪����5��2��3֮��,�������2.5^2=6.25>5,
//����֪����5��2��2.5֮��,
//�����ظ�������̿��Լ������5����λС��.
void f(double a,double error){
	double low,high,mid,delta;		
	low = 0;
	high = a;
	mid = (low+high)/2;
	while(1){
		delta = mid*mid-a;				
		if(fabs(delta)<=error){//ȡ����ֵ: ����abs  ������fabs  ������labs
			break;
		}
		
		if(delta>0){
			high = mid;
		}
		else{
			low = mid;
		}
		mid = (low+high)/2;
	}
	
	printf("a=%0.2f, rootsquare=%0.2f\n",a,mid);
}
void homework(){
	//��ҵҪ������������� 
}
int main()  
{  
     f(5,0.01);
     
     f(2,0.01);
     
     //homework(); 
     //testSqrt();
}



