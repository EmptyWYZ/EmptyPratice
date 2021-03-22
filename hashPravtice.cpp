#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
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
class HappyNum{
    public:
        int getSum(int n){
            int sum = 0;
            while(n){
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            return sum;
        }
        bool happNum(int n){
            unordered_set<int> arr;
            while(1){
                int sum = getSum(n);
                if(sum == 1){
                    return true;
                }
                if(arr.find(sum) != arr.end()){
                    return false;
                }else{
                    arr.insert(sum);
                }
                n = sum;
            }
        }
};
class TwoNumCounter {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*暴力解法，复杂度o(n*n)*/
        // vector<int> ret;
        // for(int i = 0;i < nums.size() - 1; i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         if(nums[i] + nums[j] == target){
        //             ret.push_back(i);
        //             ret.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return vector<int>(ret.begin(),ret.end());
        /*哈希*/
        unordered_map <int, int> ret;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = ret.find(target - nums[i]);//同一种元素不能同时出现
            if(iter != ret.end()) {
                return {iter->second, i};
            }
            ret.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};