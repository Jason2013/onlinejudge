# [题目1006：ZOJ问题](http://ac.jobdu.com/problem.php?pid=1006)

## 题目描述：

对给定的字符串(只包含'z','o','j'三种字符),判断他是否能AC。

是否AC的规则如下：

1. zoj能AC；
2. 若字符串形式为xzojx，则也能AC，其中x可以是N个'o' 或者为空；
3. 若azbjc 能AC，则azbojac也能AC，其中a,b,c为N个'o'或者为空；

## 输入：

输入包含多组测试用例，每行有一个只包含'z','o','j'三种字符的字符串，字符串长度小于等于1000。

## 输出：

对于给定的字符串，如果能AC则请输出字符串“Accepted”，否则请输出“Wrong Answer”。

## 样例输入：

```
zoj
ozojo
ozoojoo
oozoojoooo
zooj
ozojo
oooozojo
zojoooo
```

## 样例输出：

```
Accepted
Accepted
Accepted
Accepted
Accepted
Accepted
Wrong Answer
Wrong Answer
```

## 来源：

[2010年浙江大学计算机及软件工程研究生机试真题](http://ac.jobdu.com/problemset.php?search=2010年浙江大学计算机及软件工程研究生机试真题)

## 答疑：

解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7730-1-1.html
