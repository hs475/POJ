# POJ
record solving problems of PKU Online Judge

## 同余定理
1234%m=(1 * 1000 + 2 * 100 + 3 * 10 + 4) % m=(((1 * 10 + 2) % m * 10 + 3 % m ) * 10 + 4) % m

## 原根
&#966;(n):小于或等于n的正整数中与n互质的数的数目\
满足${(x<sup>i</sup>mod p) | 1 <= i <= p-1 } == { 1, …, p-1 }的x称为模p的原根。\
定理：如果一个正整数n有一个原根，那他有&#966;(&#966;(n))个不同余的原根

## 最大公约数
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

## map
num.clear();\
num.insert(pair<int, int>(a, rest));\
num.find(a)!=num.end()

## Miller-Rabin素数判断
![image](https://github.com/hs475/POJ/assets/106378766/33d58d0c-d4a7-4028-a1e8-3cae5db754b6)




