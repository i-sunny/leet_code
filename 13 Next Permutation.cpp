class Solution {
public:
    void nextPermutation(vector<int> &num) {
        vector<int>::iterator beg = num.begin(), end = num.end();
        vector<int>::iterator t = end - 1, j, min;
        for(t = end - 1; t >= beg; t--){
            if(t < end - 1 && *t < *(t + 1))
                break;
            if(t == beg){
                reverse(beg, end);
                return;
            }
        }
        min = t + 1;
        for(j = t + 1; j < end; j++)
            if(*j > *t && *j < *min)
                min = j;
        int vm = *min;
        num.erase(min);
        t = num.insert(t,vm);
        sort(t + 1, num.end()); 
    }
};
