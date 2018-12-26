//
//
// @..*
//
//  Created by Choonghun Lee on 9/11/18.
//  @..
//

#include "stdc++.h"


using namespace std;

struct cmp{

 bool operator()(pair<int,int> a, pair<int, int> b){

   return a.first + a.second < b.first + b.second;

}

};



vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {


 

    vector<pair<int,int>> res;

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    for(int i = 0; i< min(k, (int)nums1.size()); ++i){
        for(int j=0; j < min(k, (int)nums2.size()); ++j)
        {
           if(pq.size() < k ){

               pq.push(make_pair(nums1[i], nums2[j]));
           }else{

               if( nums1[i] + nums2[j] < pq.top().first + pq.top().second ){

                   pq.pop();
                   pq.push(make_pair(nums1[i], nums2[j]));

               }
           }
        }
    }

    while(!pq.empty()){

       res.push_back(pq.top()) ;
       pq.pop();

    }


    return res;


}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> num1 = {1,7,11};
    vector<int> num2 = {2,4,6};
    
  vector<pair<int, int>> res =   kSmallestPairs(num1, num2, 3);
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
