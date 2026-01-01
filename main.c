// Copyright © 2024-2026 Matei Pralea <matei@pralea.me>
// SPDX-License-Identifier: MIT OR Apache-2.0

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node node_t;

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

node_t *node_get_random(int amount)
{
    node_t *x = node_new(1);
    node_t *head = x;

    for (int i = 2; i <= amount; i++)
    {
        x->next = node_new(i);
        x = x->next;
    }
    return head;
}

void node_print_from_head(node_t *head)
{
    node_t *x = head;

    while (x != NULL)
    {
        printf("[%p; %d] ", x, x->value);
        x = x->next;
    }
}

int main(int argc, char **argv)
{
    printf("Simple Linked List - Example\n");
    printf("Please enter the amount of nodes to create on the heap: ");
    int amount;
    scanf("%d", &amount);
    node_t *head = node_get_random(amount);
    node_print_from_head(head);
    printf("\n");
    fflush(stdout);
    return 0;
}

