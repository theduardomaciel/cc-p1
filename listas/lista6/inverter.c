#include <stdio.h>
#include <string.h>

void array_print(int index, int end, char string_array[])
{
    if (index < end)
    {
        printf("\n");
        return;
    }

    printf("%c", string_array[index]);

    return array_print(index - 1, end, string_array);
}

int main()
{
    char string_array[255];
    scanf("%s", string_array);

    array_print(strlen(string_array), 0, string_array);

    return 0;
}