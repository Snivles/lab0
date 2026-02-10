//Постановка задачи Дан массив чисел нужно найти количество уникальных значений(или количество первых
//вхождений каждого значения.
//szz = 10 {5,5,7,3,3,2,2,1,1,10} => countEL = 6
//szz = 6 {1,2,3,4,5,6} => countEL = 6
//szz = 4 {1,1,1,1} => countEL = 1
//szz = 5 {1,2,3,2,1} => countEL = 3
#include <stdio.h>
#include <stdbool.h>
#define szz 5
int main()
{
    int array[szz] = {1,2,3,2,1};
    int max = array[0];
    for(int i=1;i < szz;i++)
        if(array[i] > max) max = array[i];
    bool unique = true;
    int notExist = max+1;
    int countEl=0;
    for(int i=0;i < szz;i++)
    {
        int jx = i+1;
        if(array[i]!= notExist)
        {
            unique = true;
            while(jx < szz)
            {
                if(array[jx]!= notExist)
                {
                    if(array[i] == array[jx])
                    {
                        array[jx] = notExist;

                    }
                }
                jx++;
            }
        }
        else
            unique = false;
        if(unique)
            countEl++;
        else
            array[i] = notExist;
    }

    printf("countEl = %d", countEl);
}
