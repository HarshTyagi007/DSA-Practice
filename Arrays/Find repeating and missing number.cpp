//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#
/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/
int *findTwoElement(int *arr, int n) {
        int* ans=new int[2];
        int i=0;
        while(i<n){
            if(arr[i]!=arr[arr[i]-1])//checking if the elements is at is right place 
                swap(arr[i],arr[arr[i]-1]);
            else i++;//if it is then will move futher
        }
        //elements which are to be at their correct places are there 
        //now we will which element is at some other's place
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1)
            {
                ans[0]=(arr[i]);
                ans[1]=(i+1);
            }
        }
        return ans;
    }