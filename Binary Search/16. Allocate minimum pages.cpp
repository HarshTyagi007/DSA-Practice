//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1/
/*
You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.

You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.

Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}
*/
int isValid(int A[],int N,int M ,int maxPages){
        int count=1,books=0;
        for(int i=0;i<N;i++){
            if(A[i]>maxPages||count>M)
            return false;
            books+=A[i];
            if(books>maxPages){
                count++;//moving to next student
                books=A[i];//it will be having these no. of books
            }
        }
        return count<=M?true:false;//while exiting the count value could have increased so we have to check that
    }
    int findPages(int A[], int N, int M) 
    {
        if(N<M)
        return -1;
        int maxPages,mid,low=A[0],high=0;
        for(int i=0;i<=N-1;i++)
        high+=A[i];
        
        while(low<=high){
            mid=low+(high-low)/2;
            if(isValid(A,N,M,mid)){
                maxPages=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return maxPages;
        
    }