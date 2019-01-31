
#include <stdio.h>

#define CHAR_NUM 128

int firstUniqChar(char* s);

int main(){
    char s[] = "loveleetcode";
    printf("%d", firstUniqChar(s));
}

int firstUniqChar(char* s) {
    int i = 0;
    int j = 0;
    
    int charSet[CHAR_NUM];
    
    while(s[i] != '\0'){

        if(charSet[s[i]] >= 1){
            i ++;
            continue;
        }else{
            charSet[s[i]] ++;
        }
          
        j = i+1;

        while(s[j] != '\0'){
            if(s[j] == s[i]){
                break;
            }
            j ++;
        }
        
        // end
        if(s[j] == '\0'){
            return i;
        }
              
        i ++;
    }
    
    return -1;
}
