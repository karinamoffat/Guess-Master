#include <stdlib.h>
#include <stdio.h>

float getSum(float value1, float value2){
    float sum = value1 + value2;
    return sum;
}

int main(){

float sum;

sum = getSum(5.4, 10.6);


printf("%f", sum);


}


