#include <stdbool.h>

bool isAnagram(char* s, char* t);
void reset(int* s);

int main()
{
    printf("an: %d\n", isAnagram("anagram", "nagaram"));
}

bool isAnagram(char* s, char* t) {
    int charSetOne[128];
    int charSetTwo[128];
    
    reset(charSetTwo);
    reset(charSetOne);
    
    while(*s){
        charSetOne[*s] ++;
        s++;
    };
    
    while(*t){
        charSetTwo[*t] ++;
        t++;
    };

    for(int i=0; i<128; i++){
        if(charSetOne[i] != charSetTwo[i]){
            return false;
        }
    }
    
    return true;
}

void reset(int s[]){
   for(int i = 0; i < 128; i++){
       s[i] = 0;
   }
}
