#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

 vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
 {
        vector<int> result;
        for(int idx = 0; idx < nums1.size(); idx++)
        {
            if(compar(nums2, nums1[idx]) && !compear(result, nums1[idx]))
            {
                result.push_back(nums1[idx]);
            }
        return true;



 }



 int compear(vector<int> newvec, int temp)
 {
    for(int idx = 0; idx < newvec.size(); idx++)
    {
        if(newvec[idx] == temp)
        {
            return true;
        }
    }
    return false;
 }