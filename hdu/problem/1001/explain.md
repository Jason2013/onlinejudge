# [杭电1001](https://blog.csdn.net/qq_41597596/article/details/81367498)


题目是这么描述的：

```
Problem Description
Hey, welcome to HDOJ(Hangzhou Dianzi University Online Judge).

In this problem, your task is to calculate SUM(n) = 1 + 2 + 3 + … + n.

Input
The input will consist of a series of integers n, one integer per line.

Output
For each case, output SUM(n) in one line, followed by a blank line. You may assume the result will be in the range of 32-bit signed integer.

Sample Input
1
100

Sample Output
1

5050

Author
DOOM III
```

刚开始就把这题给理解错了，以为是连续输入一组数n1，n2，n3……然后分别算出1+2+……+n1，1+2+……+n2，……的结果；第二个问题是，我一直认为可以用公式法即S=(1+n)*n/2.结果发现自己运行的答案自己看来都是对的，提交怎么都无法成功。

刚开始的代码如下：

```
#include <stdio.h>
int main()
{
    int a;
    int sum=0;
    while((scanf("%d",&a))!=EOF){
        sum = a*(a+1)*0.5;
        printf("%d\n\n",sum);
    }
    return 0;
}
```

最后参考了 [https://blog.csdn.net/odaynot/article/details/8020774](https://blog.csdn.net/odaynot/article/details/8020774) 的代码，结果accept.

```
#include <stdio.h>
int main()
{
    int a;
    int sum=0;
    while((scanf("%d",&a))!=EOF){
        for(int i=0;i<=a;i++)
            sum = sum+i;
        printf("%d\n\n",sum);
        sum = 0;
    }
    return 0;
}
```


我至此都不知道之前的写法错在哪里，直到看到一个百度知道的问答才明白了为什么。 https://zhidao.baidu.com/question/502897991.html。
公式法本身逻辑并没有错误，只是不符合这里的要求，这样的乘法容易造成溢出。循环累加的好处就在于溢出的可能比较小。题目中说了，假设结果是一个32位的有符号整数，也就是说最大值是4294967295，那么由 S>4294967295 可以得到n>=92682,意味当输入的数大于等于92682就会溢出。而累加法要n>2147483648才溢出。所以前者无法通过测试。若真的想用公式法，其实也可以，需要把除以2的运算拿到前面来，这样的话，就要判断一下输入是不是偶数了。如此：

```
#include <stdio.h>
int main()
{
    int a;
    int sum=0;
    while((scanf("%d",&a))!=EOF){
        if((a%2) == 0)
            sum = a/2*(a+1);
        else
            sum = (1+a)/2*a;
        printf("%d\n\n",sum);
    }
    return 0;
}
```
