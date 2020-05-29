class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        if(A.size() == 0) return 0;
        int sum = A[0];
        int maxSoFar = A[0];
        int maxTotal = A[0];
        int minSoFar = A[0];
        int minTotal = A[0];
        for(int i = 1; i< A.size();i++){
            maxSoFar = max(A[i], maxSoFar + A[i]);
            maxTotal = max(maxTotal, maxSoFar);
            
            minSoFar = min(A[i], minSoFar + A[i]);
            minTotal = min(minTotal, minSoFar);
            sum += A[i];

        }
        if(sum == minTotal) return maxTotal;
        return max(sum - minTotal, maxTotal);
      
    }
};
// One approach is to invert values and use kadane's algorithm, sum-res= will the answer required
//Other approach is Find Total sum, Minsofar and MaxSofar.
// incase of all -ve then return Maxtotal  i.e hight value among the -ve.
//or the max of sum-minvalue (considereing circular elements) or maxtotal (considering the elements within the range).