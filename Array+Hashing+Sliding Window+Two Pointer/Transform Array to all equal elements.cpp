You are given an integer array nums of size n containing only 1 and -1, and an integer k.
You can perform the following operation at most k times:
Choose an index i (0 <= i < n - 1), and multiply both nums[i] and nums[i + 1] by -1.
Note that you can choose the same index i more than once in different operations.
Return true if it is possible to make all elements of the array equal after at most 
k operations, and false otherwise.


class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        //changing all element to 1 
        int count=0;
        int flag=1;
        int start=0,end=0;
        for(int i=0; i<nums.size(); i++){
           if(flag==0 && nums[i]==-1){
             flag=1;
             end=i;
           }
           else if(nums[i]==-1){
             flag=0;
             start=i;
           }
           if(end!=0){
              count+= end-start;
              end=0;
              start=0;
           }
        }
        //changing all element to -1
        int ncount=0;
        int nflag=1;
        int nstart=0,nend=0;
        for(int i=0; i<nums.size(); i++){
           if(nflag==0 && nums[i]==1){
             nflag=1;
             nend=i;
           }
           else if(nums[i]==1){
             nflag=0;
             nstart=i;
           }
           if(nend!=0){
              ncount+= nend-nstart;
              nend=0;
              nstart=0;
           }
        }
        if(flag && k>=count) return true;
        if(nflag && k>=ncount) return true;
        return false;
    }
};