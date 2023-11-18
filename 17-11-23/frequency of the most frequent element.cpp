class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums) , end(nums)); // sort the array 
        int i =0;
        int j =0;
        long long  total = 0;
        int res =0;

        while(j < nums.size()){

            total += 1LL *nums[j];
            while(1LL * nums[j] * (j-i +1) > 1LL *total + k){ 
                total -= nums[i];
                i++;
            }
            res = max(res , j-i+1);
            j++;
        }
        return res;

    }
};
 // why nums[j] * (j-i +1) > total + k? 
 //ans:  here we need the maximum frequency now my pointer is on the  2 position (element 3) if we convert the whole element by 3 then  3 * 3
 //let suppose 1 2 3 5 6  k = 3
 // 2 position is = 3 
 // i =0 , j = 2  , 3 *(j -i +1)= 9-> (3 * 3 * 3) for that nums[j] * (j -i +1)  it means that 3 3 3 5 6
 //                      |3
 // total + k ,, now come to here total from 0 to 2 (1 + 2 + 3) + k let k = 3; 1 + 2 + 3 + 3 = 9
// 9 >  9 = false max length or window is 2 - 0 +1= 3
// if j come in 3rd index then the 5 * 4= 20
// total present value total + k(which given inthe question/ max operation ) = 11 + k(3) =14
// 20 > 14 increment i
// max = 3
