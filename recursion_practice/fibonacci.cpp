//
// Fibonacci Implementation
//

#include <iostream>

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciTailHelper (int n, int a, int b){
    if (n == 0) return a;
    return fibonacciTailHelper(n - 1, b, a + b);
}

int fibonacciTail(int n){
    return fibonacciTailHelper(n, 0, 1);
}


int main(){
    int n;
    std::cout << "enter how much numbers you want in the fibonacci sequence: " << std::endl;
    std::cin >> n;

    std::cout << "fibonacci (standard recursion): ";
    for(int i = 0; i < n; ++i){
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

     std::cout << "fibonacci (tail recursion):     ";
    for(int i = 0; i < n; ++i){
        std::cout << fibonacciTail(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}

