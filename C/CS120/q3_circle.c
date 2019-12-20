/* You are given a point say A in the 2D plane along with radius r and an array
of points B . You are asked to print out indices of points lying inside this circle
in the increasing order. Also include points lying along the circumference of the
circle */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float r, h, k, B[1000000][2], s;
    int n, pt[100000], l = 0, i = 0, t = 1;

    scanf("%f", &r);
    scanf("%d", &n);
    scanf("%f %f", &h, &k);

    for(i = 0; i < n; i++){
        scanf("%f %f", &B[i][0], &B[i][1]);
        s = pow((B[i][0] - h), 2) + pow((B[i][1] - k), 2);
        if(s <= pow(r, 2))
            pt[l++] = i;
    }

    for(i = 0; i < l; i++){
        t = 0;
        printf("%d ", pt[i]);
    }
    if(t)
        printf("%d", -1);

    return 0;
}
