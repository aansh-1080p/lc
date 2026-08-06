class Solution {
    private:
    int pdt(int x){
       int pdt=1;
        while(x>0){
            pdt*=(x%10);
            x/=10;

        }
        return pdt;
    }
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<101;i++){
           if( pdt(i) % t==0) return i;
        }
        return -1;
    }
    
};