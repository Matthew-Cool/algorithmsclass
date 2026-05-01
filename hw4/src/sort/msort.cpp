#include <vector>
#include <msort.hpp>
#include <graph.hpp>

template <typename T>
void merge(std::vector<T> &array, int l, int m, int r) {
    // YOUR CODE HERE
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<T> left(n1);
    std::vector<T> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = array[l + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = array[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }
}

template <typename T>
void msort(std::vector<T> &array, int l, int r) {
    // YOUR CODE HERE
    if (l >= r) return;

    int m = l + (r - l) / 2;

    msort(array, l, m);
    msort(array, m + 1, r);
    merge(array, l, m, r);
}

// Explicit instantiation for Edge to satisfy the linker for Kruskal's algorithm
template void msort<Edge>(std::vector<Edge> &array, int l, int r);
// Explicit instantiation for int for unit testing
template void msort<int>(std::vector<int> &array, int l, int r);