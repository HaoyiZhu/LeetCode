/*
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
形式上，如果可以找出索引 i+1 < j 且满足 A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1] 就可以将数组三等分。
*/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
       int i;
       int sum = 0;
       bool first = false;
       int part_sum = 0;
       int n=A.size();
       for(i=0; i<n; i++)
       {
           sum += A[i];
       } 

       if(sum % 3 != 0) return false;
       for(i=0; i<n; i++)
       {
           part_sum += A[i];
           if(part_sum == sum / 3)
           {
               if(!first) {first = true;part_sum=0;}
               else if(i<n-1) return true;
           }
       }

       return false;
    }
};