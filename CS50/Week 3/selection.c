#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int array[], int l, int m, int r){
        int new[10];
        //left side is bigger
        int n1 = m-l +1;
        int n2 = r-m;

        

        int L[n1];
        int R[n2];
        for (int i = 0; i< n1; i++){
            L[i] = array[l+i];
        }
        for (int i = 0; i< n2; i++){
            R[i] = array[m+i+1];
        }

        int i = 0; int j = 0;
        while(i< n1 && j < n2){;
            if(L[i] <= R[j]){
                array[l + i + j] = L[i];
                i++;
            }
            else {
                array[l + i + j] = R[j];
                j++;
            }
        }
        while(i < n1){array[l+ i +j] = L[i]; i++;}
        while(j < n2){array[l+ j+i] = R[j]; j++;}

        


    }
    void sort (int array[], int l, int r){
        if(l>= r){ return;}
        //rounds down
        int m = (r -l)/2 + l;

        sort(array, l,  m);
        sort( array, m + 1,  r);
        merge(array, l, m, r);
        
        return;
       
    };

int main (void){
    

    int arr[5] = {2,5,8,3,4};
    sort(arr, 0, 4);

    for(int i = 0; i <= 4; i++){
        
    printf("%d", arr[i]);
    }
}
    