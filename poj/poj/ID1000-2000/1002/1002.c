/*
 * poj 1002
 * guzhoudiaoke@126.com
 * 2011-08-28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone_list {
    char phone_no[10];
    int times;
    struct phone_list *next;
} phone_list;

char char_map[26] = {
    '2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6',
    '6', '6', '7', 'Q', '7', '7', '8', '8', '8', '9', '9', '9', 'Z'
};

void add_to_list(phone_list *list, char *phone)
{
    phone_list *p = list->next;
    phone_list *q = list;
    int cmp;

    while (p)
    {
        cmp = strcmp(p->phone_no, phone);
        if (cmp < 0)
        {
            q = p;
            p = p->next;
        }
        else if (cmp == 0)
        {
            p->times ++;
            break;
        }
        else
        {
            phone_list *node = (phone_list *)malloc(sizeof(phone_list));
            strcpy(p->phone_no, phone);
            node->times = 1;

            q->next = node;
            node->next = p;

            break;
        }
    }

    if (p == NULL)
    {
        phone_list *node = (phone_list *)malloc(sizeof(phone_list));
        strcpy(p->phone_no, phone);
        node->times = 1;

        q->next = node;
        node->next = p;
    }
}

int main()
{
    int num;
    int i, j, k;
    char temp[100];
    char phone[10];
    int no_dup = 1;

    scanf("%d", &num);

    phone_list *ph_list = NULL;
    ph_list = (phone_list *)malloc(sizeof(phone_list));
    ph_list->next = NULL;
    if (!ph_list)
    {
        return 0;
    }

    for (i = 0; i < num; i++)
    {
        memset(temp, 0, sizeof(char) * 100);
        memset(phone, 0, sizeof(char) * 10);
        scanf("%s", temp);

        int len = strlen(temp);
        k = 0;
        for (j = 0; j < len; j++)
        {
            if (k == 3)
                phone[k++] = '-';
            if (temp[j] >= '0' && temp[j] <= '9')
                phone[k++] = temp[j];
            else if (temp[j] >= 'A' && temp[j] <= 'Z')
                phone[k++] = char_map[temp[j]-'A'];
        }

        add_to_list(ph_list, phone);
    }

    phone_list *p = ph_list->next;
    while (p)
    {
        if (p->times != 1)
        {
            no_dup = 0;
            printf("%s %d\n", p->phone_no, p->times);
        }

        p = p->next;
    }

    if (no_dup == 1)
        printf("No duplicates.");

    p = ph_list;
    while (p)
    {
        ph_list = p;
        p = p->next;
        free(ph_list);
    }
    return 0;
}

