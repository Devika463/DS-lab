#include <stdio.h>
#include <ctype.h>
void bitVector(char set[], int bit_vector[], char U[])
{
    for (int i = 0; i < 26; i++)
    {
        bit_vector[i] = 0;
    }
    for (int i = 0; set[i] != '\0'; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (set[i] == U[j])
            {
                bit_vector[j] = 1;
                break;
            }
        }
    }
}

void printBitVector(int bit_vector[])
{
    for (int i = 0; i < 26; i++)
    {
        printf("%d", bit_vector[i]);
    }
    printf("\n");
}

void union_operation(int set1_bit[], int set2_bit[], int result[])
{
    for (int i = 0; i < 26; i++)
        result[i] = set1_bit[i] | set2_bit[i];
}

void intersection(int set1_bit[], int set2_bit[], int result[])
{
    for (int i = 0; i < 26; i++)
    {
        result[i] = set1_bit[i] & set2_bit[i];
    }
}

void complementOperation(int set_bit[], int result[])
{
    for (int i = 0; i < 26; i++)
    {
        result[i] = (set_bit[i] == 0) ? 1 : 0;
    }
}

void difference(int set1_bit[], int set2_bit[], int result[])
{
    int complement[26];
    complementOperation(set2_bit, complement);
    for (int i = 0; i < 26; i++)
        result[i] = set1_bit[i] & set2_bit[i];
}

int main()
{
    char Universal_set[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 					'x', 'y', 'z'};
    char set1[26], set2[26];
    int set1_bit[26], set2_bit[26], result[26];
    int set1_size, set2_size;

    // Set 1
    printf("Enter size of Set 1: ");
    scanf("%d", &set1_size);
    printf("\nEnter elements for Set 1: ");
    for (int i = 0; i < set1_size; i++)
    {
        scanf(" %c", &set1[i]);
        set1[i] = tolower(set1[i]);
    }
    set1[set1_size] = '\0';

    // Set 2
    printf("\nEnter size of Set 2: ");
    scanf("%d", &set2_size);
    printf("\nEnter elements for Set 2: ");
    for (int i = 0; i < set2_size; i++)
    {
        scanf(" %c", &set2[i]);
        set2[i] = tolower(set2[i]);
    }
    set2[set2_size] = '\0';

    // Function Calls
    bitVector(set1, set1_bit, Universal_set);
    printf("\nBit Vector Representation of Set 1: \n");
    printBitVector(set1_bit);

    bitVector(set2, set2_bit, Universal_set);
    printf("\nBit Vector Representation of Set 2: \n");
    printBitVector(set2_bit);

    // Menu Implementation Starts Here!
    int choice;
    while (choice != 5)
    {
        printf("\n 1.Set Union\n 2.Intersection\n 3.Complement\n 4.Set Difference\n 5.Exit\n");
        printf("Enter Your Choice Here: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            union_operation(set1_bit, set2_bit, result);
            printf("\nUnion of Set 1 and Set 2 is :\n");
            printBitVector(result);
            break;
        case 2:
            intersection(set1_bit, set2_bit, result);
            printf("\nIntersection of Set 1 and Set 2 is :\n");
            printBitVector(result);
            break;
        case 3:
            complementOperation(set1_bit, result);
            printf("\nComplement of Set 1 is :\n");
            printBitVector(result);
            complementOperation(set2_bit, result);
            printf("\nComplement of Set 2 is :\n");
            printBitVector(result);
            break;
        case 4:
            difference(set1_bit, set2_bit, result);
            printf("\nSet Difference of Set 1 and Set 2 is :\n");
            printBitVector(result);
            break;
        case 5:
	    break;
        default:
            printf("\nInvalid Choice, Try Again\n");
        }
    }

    return (0);
}
