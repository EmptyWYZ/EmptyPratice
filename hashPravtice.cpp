#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Sloution{
    public:
        vector<int> intersection(vector<int> nums1, vector<int> nums2){
            unordered_set<int> ret_set;//存储result
            unordered_set<int> num_set(nums1.begin(), nums2.end());//设置原始比对文件
            for(auto &num : nums2){
                if(num_set.find(num) != num_set.end()){
                    ret_set.insert(num);
                }
            } 
            return vector<int>(ret_set.begin(), ret_set.end());
        }
};