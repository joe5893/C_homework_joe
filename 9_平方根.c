#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//牛顿迭代法求平方根 
void newton(){
	float a;   
    float x;      //x为所求结果  
    int i=100;    //控制循环的次数a  
    printf("请输入要开方的数:");  
    scanf("%f",&a);  
    x=a/2;  
    while(i--)  
    {  
        x=(x+a/x)/2;
		printf("%.2f  ",x)  ;
    }  
    printf("开方的结果为:%f\n",x);  
	
	//return ans;
}
//牛顿迭代法求平方根
double Sqrt(double a,double p)//a是被开平方根数，p是所求精度
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

//用二分逼近法,比如计算5的平方根,那么2^2=4,3^2=9,
//可以知道√5在2和3之间,而后计算2.5^2=6.25>5,
//可以知道√5在2到2.5之间,
//不断重复这个过程可以计算出√5任意位小数.
void f(double a,double error){
	double low,high,mid,delta;		
	low = 0;
	high = a;
	mid = (low+high)/2;
	while(1){
		delta = mid*mid-a;				
		if(fabs(delta)<=error){//取绝对值: 整形abs  浮点型fabs  长整形labs
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
	//作业要求的输入和输出： 
}
int main()  
{  
     f(5,0.01);
     
     f(2,0.01);
     
     //homework(); 
     //testSqrt();
}



