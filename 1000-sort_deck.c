#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

int compare_cards(const void *a, const void *b);

/**
 * compare_cards - Compare two cards for qsort
 * @a: Pointer to first card
 * @b: Pointer to second card
 *
 * Return: Integer indicating sort order
 */
int compare_cards(const void *a, const void *b)
{
  const deck_node_t *node_a = *(const deck_node_t **)a;
  const deck_node_t *node_b = *(const deck_node_t **)b;

  int value_diff = strcmp(node_a->card->value, node_b->card->value);

  if (value_diff != 0)
    return value_diff;

  return node_a->card->kind - node_b->card->kind;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to pointer to head node of deck
 */
void sort_deck(deck_node_t **deck)
{
  deck_node_t *nodes[52];
  deck_node_t *node;
  int i = 0;

  node = *deck;
  while (node) {
    nodes[i++] = node;
    node = node->next; 
  }

  qsort(nodes, 52, sizeof(deck_node_t*), compare_cards);

  for (i = 0; i < 51; i++) {
    nodes[i]->next = nodes[i + 1];
    nodes[i + 1]->prev = nodes[i];
  }

  nodes[51]->next = NULL;
  nodes[0]->prev = NULL;

  *deck = nodes[0];
}
