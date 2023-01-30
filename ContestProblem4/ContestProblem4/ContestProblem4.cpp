#include <iostream>
using namespace std;
// к сожалению, оптимальный алгоритм не успел придумать :(
double Sum(int* arr, int start, int end) {
    double sum = 0;
    for (int i = start; i <= end; i++) {
        sum += arr[i];
    }
    return sum;
}
double MinAvg(int* arr, int N, int k) {
    double MinAvg = 99999999;
    double TempAvg = 0;
    for (int i = 0; i <= N - k; i++) {
        TempAvg = Sum(arr, i, i + k - 1) / k;
        if (TempAvg < MinAvg) {
            MinAvg = TempAvg;
        }
    }
    return MinAvg;
}
int main()
{
    int N;
    int k;
    std::cin >> N;
    std::cin >> k;
    if ((N <= 0)||(k<=0)||(k>N)) {
        std::cout << "Error!" << std::endl;
    }
    else {
        int* A = new int[N];
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        std::cout << "Min avg is: " << MinAvg(A, N, k) << std::endl;
        delete[] A;
    }
    return 0;
}

