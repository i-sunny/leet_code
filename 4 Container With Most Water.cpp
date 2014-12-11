#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

#define min(x,y) ((x)<(y)? (x) : (y))
#define max(x,y) ((x)>(y)? (x) : (y))

class Solution {
public:
 
    int maxArea(vector<int> &height) {
        int a, b, max_b;  
        int area,  area_max, g_area_max = 0;
        for(a = 0; a != height.size(); a++)
        {
            if(a >0 && height[a] <= height[a - 1])  continue;
            b = height.size() - 1; max_b = b;
            area_max = (max_b - a) * min(height[a], height[max_b]);
            while(a < b && height[b] < height[a])
            {
                if(height[--b] > height[max_b])
                {
                    area = (b - a) * min(height[a], height[b]);
                    if(area_max < area)
                    {
                        max_b = b;
                        area_max = area;
                     }
                }
            }
            if(b > a)
            {
                    area = (b - a) * height[a];
                    if(area_max < area)
                    {
                        max_b = b;
                        area_max = area;
                     }
            }
            if(g_area_max < area_max)
                g_area_max = area_max;
        }
        return g_area_max;
    }

/* Here is a solution by n00tc0d3r from old discuss */
    /*
int maxArea(vector<int> &height) {  
   int len = height.size(), low = 0, high = len -1 ;  
   int maxArea = 0;  
   while (low < high) {  
        maxArea = max(maxArea, (high - low) * min(height[low], height[high]));  
        if (height[low] < height[high]) {  
            low++;  
        } 
        else {  
            high--;  
        }  
    }  
   return maxArea;  
 }
 */
};



int main()
{
    int a[] = {5,2,12,1,5,3,4,11,9,4};
    int sizea = sizeof(a)/sizeof(int);
    vector<int> height(a, a + sizea);
    Solution test;
    int p = test.maxArea(height);
    cout << p << endl;
}
