#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums){
     int j = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[j] == nums[i]){
                
              auto it = nums.begin() + j;
              nums.erase(it);
            }
            else
                j++;
        }
        return nums.size();

}
int main(){
    vector<int> nums{1, 1, 2};
    for(int i = 0; i < removeDuplicates(nums); i++)
        cout <<  nums[i] << " ";
    return 0;
}