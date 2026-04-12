class Solution {
    public:
    int nCr (int n, int r)
      {
        long long res = 1;
         for (int i =0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
         }
         return res;
      }

      int GetPascalElement(int row,int col){
        long long ans = 1;
    
        for (int i =1;i<=row;i++){
            ans = ans* (row-i);
            ans = ans/i;
        }
        return ans;
      }

};