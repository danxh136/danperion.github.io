#include<stdio.h>
#include<math.h>

int mobius(int n)
{
	int i;
	int res=-1;//开始为奇数
    if(n==1)//1就是1
    {
        return 1;
    }
    else
    {
        for(i=2; i<=sqrt(n); i++)//简便数的运算，判断素数常用，取一半数就行
        {
            //能进去if里面的肯定不是素数，若该数就是一个素数直接输出-1就行了
            if(n%i==0 && n/i%i==0)//非素数，并且还有平方因子，既然/i%i为0，也就是i*i就是那个完全平方数
            {
                return 0;
            }
            else if(n%i==0)//非素数
            {
                res*=-1;//res负责判断素数为奇数还是偶数，来一次变一次，偶数为1，奇数为-1
                n/=i;
            }
        }
        return res;
    }
}
int main(void)
{
	int t, n;

	scanf("%d", &t);
	while(t>0)
	{
		scanf("%d", &n);
		printf("%d\n", mobius(n));
		t--;
	}
	
	return 0;
}