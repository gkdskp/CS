/* PRACTICE QUESTION
HackerLand National Bank has a simple policy for warning clients about
 possible fraudulent account activity. If the amount spent by a client 
 on a particular day is greater than or equal to 2 * the client's median 
 spending for a trailing number of days, they send the client a notification
 about potential fraud. The bank doesn't send the client any notifications
until they have at least that trailing number of prior days' transaction data.

Given the number of trailing days  and a client's total daily expenditures 
for a period of  days, find and print the number of times the client will 
receive a notification over all  days.

For example, d = 3 and expenditures = [10, 20, 30, 40, 50]. On the first three days, 
they just collect spending data. At day 4, we have trailing expenditures of [10, 20, 30]. 
The median is 20 and the day's expenditure is 40. Because 40 >= 20*2, there will be a notice. 
The next day, our trailing expenditures are [20, 30, 40] and the expenditures are 50. 
This is less than 2*30 so no notice will be sent. Over the period, there was one notice sent.

Input Format
The first line contains two space-separated integers n and d, the number of days of 
transaction data, and the number of trailing days' data used to calculate median spending.
The second line contains n space-separated non-negative integers where each integer i denotes 
expenditues[i].

Output Format
Print an integer denoting the total number of times the client 
receives a notification over a period of  days.

OUTPUT in STDOUT
SOURCE: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 
int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int* expenditures = (int*) malloc(n * sizeof(int));
    int* sorted = (int*) calloc(201, sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &(expenditures[i]));

 

    int isEven = d % 2 == 0;
    int half = (isEven)? (d / 2): ceil((float)d / 2.0f);


 

    int notif = 0;
    for (int i = 0; i < n; i++) {
        if (i >= d) {
            int h = 0, j= 0;
            float median = 0;
            int flag = 0;

            while (!flag) {
                if (h + sorted[j] >= half && !isEven) {
                    median = j;
                    flag = 1;
                }

                if (h + sorted[j] >= half && median == 0 && isEven) {
                    median = j;
                }
                if (h + sorted[j] >= half + 1 && isEven) {
                    median += j;
                    median = median / 2;
                    flag = 1;
                }
                h += sorted[j];
                j++;
            }
            if (expenditures[i] >= median * 2.0f) {
                notif++;
            }
            sorted[expenditures[i - d]]--;
        }
        sorted[expenditures[i]]++;
    }
    printf("%d\n", notif);
    free(expenditures);
    free(sorted);

    return 0;

}


