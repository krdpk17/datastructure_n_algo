
/*
 Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
  n = 3 out = 5
    2        1                      1                 3          3
  /   \            2                      3        2        1
 1     3             3                2          1             2
     (1).        (2).                 (3)           (4)        (5)
        
    L: 1.            0                  0              2          2 
    R: 1             2                  2              0          0 
        

    every node can be root node: 
*/

/*
N -> 1 will go to root
Left subtree -> binary tree with Ln in {0,1,2,.....N-1}
Left subtree -> binary tree with Rn in (N-1-Ln) nodes
*/

/*

                  Root
         -----              -----------------
        |  M   |             | n-1-M         |
         -----               ----------------
*/
           
#include<iostream>
int countBST(int n){
    if(n== 0 || n==1){
        return 1;   
    }
    int i = 0;
    int total = 0;
    for(i = 0; i<=n-1; ++i){ 
        total += countBST(i) * countBST(n-1-i);
    }
    return total;
}


int main(){
    int n = 6;
    int total;
    total = countBST(n);
    std::cout<<total;
    
}








