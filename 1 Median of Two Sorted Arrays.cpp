class Solution {
public:
        double findIndexNum(int index, int A[], int m, int B[], int n){
        int ai, bi;
        if(m > n)
            return findIndexNum(index, B, n, A, m);
        if(m == 0)
            return B[index - 1];
        if(index == 1)
            return min(A[0], B[0]);
        ai = min(index / 2, m);  bi = index - ai;
        if(A[ai - 1] < B[bi - 1])
            return findIndexNum(index - ai, A + ai, m - ai, B, n);
        else if(A[ai - 1] > B[bi - 1])
            return findIndexNum(index - bi, A, m, B + bi, n - bi);
        else
            return A[ai - 1];
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2 == 1)
            return findIndexNum((m+n)/2+1, A, m, B, n);
        double midLeft = findIndexNum((m+n)/2, A, m, B, n);
        double midRight = findIndexNum((m+n)/2+1, A, m, B, n);
        return (midLeft + midRight)/2;


    }
};