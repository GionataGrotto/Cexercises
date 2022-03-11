#include <stdlib.h>
#include <stdio.h>


double * perceptron(double **x, int *y, int d, int m, int iterations);

double inner_product(double *w, double *x, int d);

int check_classification(double *w, double **x, int *y, int d, int m);


int main() {
    return 0;
}


double * perceptron(double **x, int *y, int d, int m, int iterations) {
    // Pointer to all the vectors w
    double **w;
    int i, j, h, misc;

    // Allocate the vector of pointers
    w = (double **)malloc(iterations * sizeof(double*));

    // Allocate the memory for all the vectors w
    for (i = 0; i < iterations; i++) {
        w[i] = (double *)malloc(d * sizeof(double));
    }

    // Repeat for the number of iterations
    for (i = 0; i < iterations - 1; i++) {
        // Variable to check if there is a misclassified element
        misc = check_classification(w[i],x,y,d,m);
        if (misc != -1) {
            // Update the next w
            for (h = 0; h < d; h++) {
                w[i+1][h] = w[i][h] + x[misc][h] * y[misc];
            }
        } else {
            // Otherwise stop the iterations
            break;
        }
    }
    // Allocate the vector to return
    double *result = (double *)malloc(d * sizeof(double));
    // For every vector considered in the iterations sum to the result
    for (j = 0; j < i; j++) {
        for (h = 0; h < d; h++) {
            result[h] += w[j][h];
        }
    }

    // Free the memory of each pointer in the vector
    for (i = 0; i < iterations; i++) {
        free(w[i]);
    }
    // Free the memory of the initial pointer
    free(w);

    return result;
}

double inner_product(double *w, double *x, int d) {
    int i;
    double result;
    for (i = 0; i < d; i++) {
        result += w[i] * x[i];
    }
    return result;
}

// Function to check if there is a misclassified element. d is the number of features and m is the number of element in the training set
int check_classification(double *w, double **x, int *y, int d, int m) {
    int i;
    for (i = 0; i < m; i++) {
        if (inner_product(w,x[i],d) * y[i]) {
            return i;
        }
    }
    return -1;
}