#include <string>
#include <iostream>

struct link_list
{
    struct link_list *prev_;
    struct link_list *next_;
    int n_;
};

typedef link_list link_list_t;

void init_list(link_list_t *ll)
{
}

void destroy_list(link_list_t *ll)
{
}

void clear_list(link_list_t *ll)
{
}

bool is_list_empty(link_list_t *ll)
{
}

int list_length(link_list_t *ll)
{
}

int get_elem(link_list_t *ll, int i)
{
}

/*
 * return the index which equals the number
 * otherwise return -1
 */
int locate_elem(link_list_t *ll, int n)
{
}

/**
 * @brief Insert an item into the list
 *
 * @param ll the list
 * @param i the index of which to insert
 * @param n the item to insert
 */
void list_insert(link_list_t *ll, int i, int n)
{
}

void list_delete(link_list_t *ll, int i)
{
}

void list_push_back(link_list_t *ll, int n)
{
}

int main()
{
    return 0;
}
