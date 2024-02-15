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
write n − 1 as 2r·d with d odd by factoring powers of 2 from n − 1\
WitnessLoop: repeat k times:\
   pick a random integer a in the range [2, n − 2]\
   x ← ad mod n\
   if x = 1 or x = n − 1 then\
      continue WitnessLoop\
   repeat r − 1 times:\
      x ← x2 mod n\
      if x = n − 1 then\
         continue WitnessLoop\
   return composite\
return probably prime\
在int范围内，选取 {2, 7, 61}三个数作为底数可以保证100%正确。\
在long long范围内，选取{2,325,9375,28178,450775,9780504,1795265022}七个数作为底数可保证100%正确。\




