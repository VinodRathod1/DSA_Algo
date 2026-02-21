class Solution {
public:
   bool isprime(int n){
    if(n<2)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
   }
    int count(int m){
        int cnt=0;
        while(m>0){
            if((m&1)==1){
                cnt++;
            }
            m>>=1;
        }
        if(isprime(cnt))return 1;
        return 0;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++){
            cnt+=count(i);
        }
        return cnt;
    }
};