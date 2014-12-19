class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        if(n == 1 && target !=A[0])   //递归出口1,找不到目标值
            ret.assign(2, -1);
        else if(target == A[n/2]){      //递归出口2,找到目标值
            int tbeg = n/2, tend = n/2;
            while((--tbeg) >= 0 && target == A[tbeg]);
            while((++tend) < n && target == A[tend]);
            ret.push_back(tbeg + 1);
            ret.push_back(tend - 1);
        }
        else if(target < A[n/2])
            ret = searchRange(A, n/2, target);
        else{
	    ret = searchRange(A + n/2, n - n/2, target);
	    if(ret[0] == -1 && ret[1] == -1)  return ret;
	    ret[0] += n/2; ret[1] += n/2;       //***attention***
        }
        return ret;
    }
};
