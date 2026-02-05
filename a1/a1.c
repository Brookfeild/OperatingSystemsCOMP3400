// Written by Tyler Ricketts on 1/15/2026 at Wentworth Institute of Technology, Boston MA 02115 USA
// Apache 2.0 License. Open Source, Free for all to use!

#include <stdio.h> // for printf 
#include <stdlib.h> // For NULL

/**
 * Gives the price of all items based on the item's cost and the quantity of that item.
 * Also checks to see if the count exceeds the item limit specified.
 * @param peritem The individual item's cost.
 * @param count The amount of items.
 * @param bulk_limit The limit specified for maximum amount of items that can be selected.
 */
int price(int peritem, int count, int bulk_limit) {
    if (peritem <= 0 || count <= 0 || bulk_limit <= 0) {
        return 0;
    }

    int total = 0;

    if(count > bulk_limit) {
        int halfprice = peritem / 2;
        for(int i = 0; i < count; i++) {
            if(i < bulk_limit) {
                total = total + peritem;
            } else if (i >= bulk_limit) {
                total = total + halfprice;
            }
        }
    } else if (count < bulk_limit) {
        total = peritem * count;
    }

    return total;
}


/**
 * Finds the value of x to the power of y, x^y. (Based on Kernighan and Ritchie)
 * @param x The base value.
 * @param y The power value.
 */
int power(int x, int y) {
    // Return 1 if x or y equal 0
    if(x == 0) {
        return 1;
    } else if(y == 0) {
        return 1;
    }

    // Return 0 if x or y are negative
    if(x < 0) {
        return 0;
    } else if(y < 0) {
        return 0;
    }

    int i, p;

    p = 1;

    for (i = 1; i <= y; ++i) {
        p = p * x;
    }

    return p;
}


/**
 * Searches an array for positive values then adds all positive values together and returns this value
 * @param array The array
 * @param alen The length of the array
 */
int add_all_pos(int* array, int alen) {
    // Return 0 if array is NULL
    if (alen == 0 || array == NULL) {
        return 0;
    }

    int total = 0;

    for(int i = 0; i < alen; ++i) {
        if(array[i] > 0) {
            total = total + array[i];
        } else {
            continue;
        }
    }

    return total;
}


/**
 * Finds the largest diference of values in the array.....
 * In other words, searches the array for the largest and smallest
 * values and finds the diference between them
 * @param array The array
 * @param alen The length of the array
 */
int max_diff(int* array, int alen) {
    // Return 0 if array is NULL or only includes one value
    if (array == NULL || alen <= 1) {
        return 0;
    }

    int max = array[0];
    int min = array[0];
    for(int i = 0; i < alen; i++) {
        if(array[i] > max) {
            max = array[i];
            continue;
        } else if(array[i] < min) {
            min = array[i];
            continue;
        } else {
            continue;
        }
    }

    int total = max - min;
    return total;
}

int main() {
    int x = price(2, 1, 10);
    printf("price(2, 1, 10) returned: %d\n", x);

    // PASSED
    x = price(2, 9, 10);
    x = price(2, 12, 10);
    x = price(2, 1, -1);
    x = price(-2, 1, 1);

    // PASSED
    x = power(2, 3);
    x = power(2, 6);
    x = power(3, 4);
    x = power(3, -1);
    x = power(-2, 1);
    x = power(-3, 1);

    // PASSED
    int a1[] = {11, 12, 13};
    int a2[] = {11, 21, 31, 41};
    int a3[] = {11, -12};
    x = add_all_pos(a1, 3);
    x = add_all_pos(a2, 4);
    x = add_all_pos(a3, 2);
    x = add_all_pos(NULL, 0);

    // PASSED
    int b1[] = {-11, -12, -13, -14, -15};
    int b2[] = {-11, -12, -13, -14};
    int b3[] = {11, -12, -13, -14};
    int b4[] = {11};
    int b5[] = {11, 21, 31};
    int b6[] = {11, 12, 13, 14};
    int b7[] = {11, 12};

    x = max_diff(b1, 5);
    x = max_diff(b2, 4);
    x = max_diff(b3, 4);
    x = max_diff(b4, 1);
    x = max_diff(b5, 3);
    x = max_diff(b6, 4);
    x = max_diff(b7, 2);
    x = max_diff(NULL, 0);

    return 0;

}
