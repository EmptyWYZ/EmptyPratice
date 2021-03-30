#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
class FourSumCount {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> addAB;//核心思想在于将四个数组压缩为两个数组进行处理
        int cnt = 0;
        for(auto &a : A) {
            for(auto &b : B) {
                addAB[a + b]++;//统计a和b相加和的统计次数
            }
        }
        for(auto &c : C) {
            for(auto &d : D) {
                if(addAB.find(0 - (c + d)) != addAB.end()) {
                    cnt += addAB[(0 - (c + d))];
                }
            }
        }
        return cnt;
    }
};
class CanConstruct {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // for (int i = 0; i < magazine.size(); i++) {//暴力解法,时间复杂度o(n^2)
        //     for(int j = 0; j < ransomNote.size(); j++) {
        //         if(magazine[i] == ransomNote[j]) {//找到相同的就删除那个元素
        //             ransomNote.erase(ransomNote.begin() + j);
        //             break;
        //         }
        //     }
        // }
        // if(ransomNote.size() == 0){
        //     return true;
        // }
        // return false;
        int comp[26] = {0};//复杂度o(n)
        for (int i = 0; i < magazine.size(); i++) {
            comp[magazine[i] - 'a']++;
        }
        for(int j = 0; j < ransomNote.size(); j++) {
            comp[ransomNote[j] - 'a']--;
            if(comp[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //学习
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {//排序之后如果第一个元素大于零，其他的就不用聊了
                continue;
            }
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;//去重a
            }
            unordered_set<int> set;//核心思路是先确认a,b不重复
            for(int j = i + 1; j < nums.size(); j++) {//去重b,b元素于前与后都不相同,为了防止越界，从最右侧向回找
                if(j > i + 2 && nums[j] == nums[j - 1]
                             && nums[j - 1] == nums[j - 2]) {
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    ret.push_back({nums[i], nums[j], c});
                    set.erase(c);//去重c，保证下一次不会有相同的C
                }else {
                    set.insert(nums[j]);
                } 
            }
        }
        return ret;
    }
};
class FourCount {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {//去重a
                continue;
            }
            for(int j = i + 1; j < nums.size(); j++) { 
                if(j > i + 1 && nums[j] == nums[j - 1]) {//去重b
                    continue;
                }
                int left = j + 1;//双指针
                int right = nums.size() - 1;
                while(right > left) {
                    if(nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    }else if(nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                    }else {//去重
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(right > left && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        while(right > left && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
        }
        return ret;
    }
};