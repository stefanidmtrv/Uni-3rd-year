#include "fibonacci.h"
#include <stdio.h>

int fibonacci(int n) {
    int result;
    if(n == 0) {
        return 0;
    }else if (n==1) {
        return 1;
    }else if(n < 0){
        return 0;
    }else  {
        return (fibonacci(n-1) + fibonacci(n-2));
    } 
    return 0;
}