import java.util.Arrays;
public class leetcode_34 {
    public static void main(String[] args) {
        int[] arr = {5,9,9,9,9,10,12,14,15,16,17,17,17,20};
        int target = 17;
        int[] ans = searchIndex(arr,target);
        System.out.println(Arrays.toString(ans));
    }
    static int[] searchIndex(int[] nums, int target){
        int[] ans = {-1,-1};
        int start = searchrange(nums, target, true);
        int end = searchrange(nums, target, false);
        ans[0] = start;
        ans[1] = end;
        return ans;
    }
    static int searchrange(int[] nums, int target, boolean findIndex){
        int ans = -1;
        int start = 0;
        int end = nums.length-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(target<nums[mid]){
                end = mid-1;
            }
            else if(target>nums[mid]){
                start = mid+1;
            }
            else{
                ans = mid;
                if(findIndex){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
        }
        return ans;
    }
}
