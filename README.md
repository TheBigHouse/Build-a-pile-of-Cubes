# Build-a-pile-of-Cubes

来源：codewars

关键点有两个
1：1^3 + 2^3 + ... n^3 = (1+2+...+n)^2  这是数学公式这里不论
2：根据1的公式，如果给的数能够有整数根，那么这个题是有结果的，否则返回-1。所以只需要对给的数进行开方即可，但是long long型不能用c++的开方方法，会丢失精度。所以手写了开方过程。
