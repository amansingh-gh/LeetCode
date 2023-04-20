
//   Wrong code 

public class leetcode_410 {
    public static void main(String[] args) {
        int[] nums = {10,20,30,40,50};
        int m = 4;
        System.out.println(m);
    }
    public int splitarray(int[] nums, int m){
        int start = 0;
        int end =0;
        for(int i=0; i<nums.length; i++){
            start = Math.max(start, nums[i]);
            end = end+nums[i];
        }
        while(start<end){
            int mid = start+(end-start)/2;
            int sum = 0;
            int pieces =1;
            for(int num: nums){
                if(sum+num>mid){
                    sum=num;
                    pieces++;
                }
                else{
                    sum+=num;
                }
            }
            if(pieces>m){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return end;
    }
}
