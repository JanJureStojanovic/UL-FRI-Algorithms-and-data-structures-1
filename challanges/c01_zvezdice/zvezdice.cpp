#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>

std::tuple<int, int []> recursion(int arr[][2], int n, int w, int time, int ) {
    int[2] arr = {1, 3};
    return std::make_tuple(10, arr);
}

int main() {

    int n, w;
    std::cin >> n >> w;

    int arr[n][2];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i][0] >> arr[i][1];
    }


           
}