#include <stdio.h>
#include <stdlib.h>

int rekurzija() {

    return 0;
}

int main() {

    int n, w;
    scanf("%d %d", &n, &w);

    int** arr = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(2*sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    //int x = rek(arr, )

    return 0;

}