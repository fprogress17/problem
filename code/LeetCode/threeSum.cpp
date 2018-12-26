//
//
// @..*
//
//  Created    on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    
    /* Sort the elements */
    sort(A, A + arr_size);
    
    /* Now fix the first element one by one and find the
     other two elements */
    for (int i = 0; i < arr_size - 2; i++) {
        
        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
        // remaining elements
        
        r = arr_size - 1; // index of the last element
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i],
                       A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    
    // If we reach here, then no triplet was found
    return false;
}



/// with repeated number 
vector <vector< int >> threeSum(vector< int >& nums) {
    
    vector <vector< int >> res;
    sort(nums.begin(), nums.end());
   
    if(nums.empty() || nums.back() < 0 || nums.front() > 0 )
        return {};
    
    for ( int k = 0 ; k < nums.size(); ++ k) {
        if(nums[k] > 0 )
            break ;
       
        if (k > 0 && nums[k] == nums[k - 1 ])
            continue ;
        
        int target = 0 - nums[k];
      
        int i = k + 1 , j = nums.size() - 1 ;
        
        while(i < j) {
           
            if (nums[i] + nums[j] == target) {
                res.push_back({nums[k], nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1 ]) ++ i;
                while (i < j && nums[j] == nums[j - 1 ]) -- j;
                ++i; -- j;
            } else  if (nums[i] + nums[j] < target) ++ i;
            else -- j;
        }
    }
    return res;
}



vector<vector<int>> threeSum(vector<int> a){
    
    vector<vector<int>> res;
    
    if(a.size()<3)
        return res;
    
     sort(a.begin(), a.end());
    
    for(int i=0;i<a.size() - 2 ;++i){
        
        if( i == 0 || a[i] != a[i-1]){
            
            int left = i+1;
            int right = a[a.size()-1];
            
            while(left < right){
                
                if( a[i] + a[left] + a[right] == 0){
                    
                    vector<int> ret;
                    ret.push_back(i);
                    ret.push_back(left);
                    ret.push_back(right);
                    res.push_back(ret);
                    
                    
                    ++left;
                    --right;
                    
                    while(left<right && a[left] == a[left])
                        ++left;
                    
                    while(left<right && a[right] == a[right -1])
                        --right;
                }else if( a[i] + a[left] + a[right] < 0){
                    ++left;
                }else{
                    ++right;
                }
            }
        }
        
    }
    return res;
}



vector<vector<int>> threeSum(vector<int>& nums) {
    
    sort(nums.begin(), nums.end()) ;
    
    int n = (int)nums.size();
    vector<vector<int>> res;
    
    for(int i =0; i<= n-3; ++i){
        
        if(i != 0 && nums[i] == nums[i-1])
            continue;
        
        int t = nums[i];
        
        int j = i+1;
        int k = n-1;
        
        while(j<k){
            
            if(nums[i] + nums[j] + nums[k] == 0){
                
                vector<int> r ;
                r.push_back(nums[i]);
                r.push_back(nums[j]);
                r.push_back(nums[k]);
                res.push_back(r);
            }
            
            if( nums[j] + nums[k]  < - nums[i]){
                
                ++j;
                
                while( nums[j] == nums[j-1])
                    ++j;
                
                
            }else{
                --k;
                while( nums[k] == nums[k+1])
                    --k;
            }
            
        }
    }
    
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
