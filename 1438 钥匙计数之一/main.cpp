#include<stdio.h>
#include<math.h>

int main ()
{
    int        i;
    __int64 temp, a[32], b[32];                    //b[i]��¼��1 4��β����

    a[2] = 0;
    a[3] = 8;
    b[2] = 0;
    b[3] = 4;
    printf ("N=2: 0\nN=3: 8\n");
    for (i = 4; i <= 31; i++)
    {
        a[i] = a[i - 1] * 4;
        a[i] += (__int64) pow (2,i) - 4;        //��2 3 ��β��
        temp = ((__int64) pow (4,i-2) - (__int64) pow (2, i - 2)) * 2 - b[i - 1];
        a[i] += temp;
        b[i] = a[i - 1] * 2 + temp;
        printf ("N=%d: %I64d\n", i, a[i]);
    }

    return 0;
}
