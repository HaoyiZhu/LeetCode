'''
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

注意：
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
'''

class Solution {
public:
    int reverse(int x) {
        int r=0;
        
        while(x!=0){
            if(r>INT_MAX/10||r<INT_MIN/10)
            {
                return 0;
            }
            r = r*10 + x%10;
            x /= 10;
        }
        return r;
    }
};