#include <iostream>

void allocate_matrix(double **a, int rows, int columns)
{
    // You need to do the dynamic allocation on the heap
    *a = new double[rows * columns];
}

void initialize_a(double *a, int rows, int columns)
{
    //You need to initialize a
    /* We want a to look like the following
    *      1  2  3
    * a =  1  1  1
    *      1  1  1
    */
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            if (i == 0) {
                a[i * columns + j] = j + 1;
            } else {
                a[i * columns + j] = 1;
            }
        }
    }
}

void initialize_b(double *a, int rows, int columns)
{
    //You need to initialize b
    /* We want b to look like the following
    * b =  1  1  1
    */
    for(int i = 0; i < columns; ++i) {
        a[i] = 1;
    }
}

void initialize_c(double *a, int rows, int columns)
{
    //You need to initialize c
    /* We want c to look like the following
    * c =  0 0 0
    */
    for(int i = 0; i < columns; ++i) {
        a[i] = 0;
    }
}


void product_sum(double (*a)[3], double *b, double *c)
{
    /* We want a vector s.t.
    * c = b * a + b
    */

    // Reset c to zero before computation
    memset(c, 0, sizeof(double) * 3);

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            c[j] += b[i] * a[i][j];
        }
    }
    for(int i = 0; i < 3; ++i) {
        c[i] += b[i];
    }

}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
