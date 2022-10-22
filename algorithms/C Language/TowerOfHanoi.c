#include <stdio.h>

int n = 1;

int toh(int disks, int t1, int t2, int t3)
{
    if (disks > 0)
    {
        toh(disks - 1, t1, t3, t2); // Move all disks except 1 from A to B using C

        // [NOTE: Moving all disk here means moving recursively i.e One by one]
        // only movement of one disk is allowed

        printf("%d. Move one disk from %d to %d \n", n, t1, t3); // Move one disk from A to C
        n++;

        toh(disks - 1, t2, t1, t3); // Move all disks from B to C using A which was moved earlier temporarily to B
    }
}

int main()
{
    int k;
    printf("\nEnter number of disks :\n");
    scanf("%d", &k);
    toh(k, 1, 2, 3);

    return 0;
}

/*
Output:
Enter number of disks :
3
1. Move one disk from 1 to 3
2. Move one disk from 1 to 2
3. Move one disk from 3 to 2
4. Move one disk from 1 to 3
5. Move one disk from 2 to 1
6. Move one disk from 2 to 3
7. Move one disk from 1 to 3
*/