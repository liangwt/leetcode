/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main(){
    int* returnSize;
    int digits[] = {1, 2, 3, 4}; 

    plusOne(digits, 4, returnSize);
    return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* ret = (int*) malloc((digitsSize+1) * sizeof(int));
    
    // int p, is_full=0;
    
    // for(int i = digitsSize-1; i>=0; i++){
    //     p = digits[i]+1;
    //     if(p>=10){
    //         is_full = 1;
    //         ret[i+1]  = p%10;
    //     }else{
    //         is_full = 0;
    //         ret[i+1]  = p;
    //     }
    //     if(is_full == 0){
    //         break;
    //     }
    // }
    
    // if(is_full == 1){
    //     ret[0] = 1;
    // }
    
    *returnSize = digitsSize+1;
    
    return ret;

}