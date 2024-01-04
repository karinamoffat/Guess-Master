//Q2.c – Assignment 3 – Karina Moffat

#include<stdio.h>
#include<stdlib.h>

//initialize the cache structure
struct Cache{
    int key;
    int value;
    int used;
};

typedef struct Cache cache;

int max_size;

//a function to create a new cache, passes capacity value through
void createCache(int capacity){
    max_size = capacity;
    cache *new = (cache*)malloc(max_size * sizeof(cache));
    //iterate through each index until capacity is reached
    for(int i=0; i<max_size; i++){
        new[i].key = 0;
        new[i].value = 0;
        new[i].used = 0;
    }
}

cache *c;

//a function to identify the value of the key in a cache
int get(int key){
    //iterate through the cache
    //if the key is identified, update used value and return the value at the key
    for(int i=0; i<max_size; i++){
        if(c[i].key == key){
            for(int j=0; j<max_size; j++){
                if(i != j){
                    c[j].used++;
                }
            }
            c[i].used = 0;
            return c[i].value;
        }
    }
    //return -1 if key was not found
    return -1;
}

//a function to update the value of the key
void put(int key, int value){
    int key_exists = 0;
    //index of cache is the modulus of key divided by capacity
    int insert_index = key % max_size;

    if(c[insert_index].key == key){
        c[insert_index].value = value;
        key_exists = 1;
    }

    //if the key has not been found...
    if(!key_exists){
        int highest_used_index = 0;
        for(int i=0; i<max_size; i++){
            if(c[highest_used_index].used < c[i].used){
                highest_used_index = i;
            }
        }
        for(int i=0; i<max_size; i++){
            if(i != highest_used_index){
                c[i].used++;
            }
        }

        if(c[highest_used_index].used==max_size-1){
            c[highest_used_index].key = key;
            c[highest_used_index].value = value;
            c[highest_used_index].used = 0;
        }else{
            c[insert_index].key = key;
            c[insert_index].value = value;
            c[insert_index].used = 0;
        }

    }
}

//a function to print the results of the cache
void printCache(){
    printf("Cache Contents:\n");
    //iterate through each index and print the key and value until end of cache is reached
    for(int i=0; i<max_size; i++){
        printf("Key: %d, Value: %d\n", c[i].key, c[i].value);
    }
}

int main(){
    createCache(2);
    put(1, 10);
    put(2, 20);
    printf("%d\n", get(1));
    put(3, 30);
    printf("%d\n", get(2));
    put(4, 40);
    printf("%d\n", get(1));
    printf("%d\n", get(3));
    printf("%d\n", get(4));
    put(5, 50);
    printCache();
}