Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. Let these two numbers be 
numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2]
 of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.


class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n= numbers.length;
        int i=0, j=n-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target) return new int[]{i+1,j+1};
            else if(numbers[i]+numbers[j]<target) i++;
            else j--;
        }
        return new int[]{};
    }
}

 