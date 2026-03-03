#include <stdio.h>
#include <string.h>
#include <math.h>

void mergesort(int array[], int l, int r);
void merge(int array[], int l, int m, int r){
    int n1 = m -l +1; 
    int n2 = r - m;

    int L[n1]; int R[n2];

    for (int i =0; i < n1; i++){
        L[i] = array[l + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = array[m + 1 + i];
    }

    int i = 0; int j = 0; 
     while (i < n1 && j < n2){
        if(L[i] <= R[j]){
            array[l + i + j] = L[i];
            i++;
        }
        else {
            array[l + i + j] = R[j];
            j++;
        }
     }
     while(i< n1){
        array[l +i + j] = L[i];
        i++;
     }
     while (j< n2){
        array[l + i + j] = R[j];
       j++;
     }




};

void mergesort(int array[], int l,int r){
    int m = l + (r - l)/2;

    if(l>=r){ return;}

    mergesort(array, l, m);
    mergesort(array, m+1, r);
    merge(array, l, m, r);
    return;

};


int main(void){
 int array[4] = {4,2,1,6};
 mergesort(array, 0, 3);
 for (int i =0; i < 4; i++){
    printf("%d", array[i]);
 }

 return 0;

}