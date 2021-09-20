#include <stdio.h>
#include <stdlib.h>

void permutations(int* options, int size, int original_size) {
    if (size == 1) {

        int check = options[0];
        for (int i = 1; i < original_size; i++) {
            check = check*10 + options[i];

            if (check % (i+1) != 0) {
                return;
            }
        }

        printf("Found! %d\n", check);
        exit(0);
    }

    for (int i = 0; i < size; i++) {
        permutations(options, size-1, original_size);

        int j = size % 2 ? i : 0;

        int tmp = options[size-1];
        options[size-1] = options[j];
        options[j] = tmp;
    }
}

int main() {
    int options[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int size = sizeof(options)/sizeof(options[0]);

    permutations(options, size, size);
}
