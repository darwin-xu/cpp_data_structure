#include <string>
#include <iostream>

struct link_list
{
    struct link_list* prev_;
    struct link_list* next_;
    int               n_;
};

typedef link_list link_list_t;

void init_list(link_list_t* ll)
{
    ll->n_    = 0;
    ll->prev_ = NULL;
    ll->next_ = NULL;
}

void destroy_list(link_list_t* ll)
{
}

void clear_list(link_list_t* ll)
{
}

bool is_list_empty(link_list_t* ll)
{
    if (ll->prev_ == NULL && ll->next_ == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int list_length(link_list_t* ll)
{
    int          length = 0;
    link_list_t* new_p  = ll->next_;

    while (new_p != NULL)
    {
        length += 1;
        new_p = new_p->next_;
    }

    return length;
}

link_list_t* get_elem(link_list_t* ll, int i)
{
    link_list_t* p;
    p = ll;
    for (int x = 0; x <= i; x++)
    {
        p = p->next_;
    }
    return p;
}

/*
 * return the index which equals the number
 * otherwise return -1
 */
int locate_elem(link_list_t* ll, int n)
{
    return 0;
}

void list_insert(link_list_t* ll, int n)
{
    link_list_t* new_p;
    new_p = (link_list_t*)malloc(sizeof(link_list));
    if (ll->next_ == NULL)
    {
        ll->next_    = new_p;
        new_p->prev_ = ll;
        new_p->next_ = NULL;
        new_p->n_    = n;
    }
    else
    {
        new_p->next_        = ll->next_;
        new_p->next_->prev_ = new_p;
        ll->next_           = new_p;
        new_p->prev_        = ll;
        new_p->n_           = n;
    }
}

void list_delete(link_list_t* ll)
{
    if (ll->next_ == NULL)
    {
        ll->prev_->next_ = NULL;
    }
    else
    {
        ll->next_->prev_ = ll->prev_;
        ll->prev_->next_ = ll->next_;
    }
    free(ll);
}

void list_push_back(link_list_t* ll, int n)
{
}

void print_list(link_list_t* ll)
{
    std::cout << "-----------------------------------" << std::endl;

    ll = ll->next_;
    while (ll != NULL)
    {
        std::cout << ll->n_ << std::endl;
        ll = ll->next_;
    }

    std::cout << "-----------------------------------" << std::endl;
}

int main()
{
    link_list_t l1;

    init_list(&l1);

    assert(is_list_empty(&l1));

    assert(list_length(&l1) == 0);

    list_insert(&l1, 1);
    list_insert(&l1, 2);
    list_insert(&l1, 3);
    list_insert(&l1, 4);
    list_insert(&l1, 5);

    assert(list_length(&l1) == 5);
    print_list(&l1);

    assert(get_elem(&l1, 0)->n_ == 5);
    assert(get_elem(&l1, 1)->n_ == 4);
    assert(get_elem(&l1, 2)->n_ == 3);
    assert(get_elem(&l1, 3)->n_ == 2);
    assert(get_elem(&l1, 4)->n_ == 1);

    list_insert(get_elem(&l1, 0), 77);
    list_insert(get_elem(&l1, 2), 777);
    list_insert(get_elem(&l1, 4), 7777);
    list_insert(get_elem(&l1, 6), 6);
    
    print_list(&l1);
    list_delete(get_elem(&l1,1));
    list_delete(get_elem(&l1,2));
    list_delete(get_elem(&l1,3));
    list_delete(get_elem(&l1,4));
    print_list(&l1);
    assert(get_elem(&l1, 0)->n_ == 5);
    assert(get_elem(&l1, 1)->n_ == 4);
    assert(get_elem(&l1, 2)->n_ == 3);
    assert(get_elem(&l1, 3)->n_ == 2);
    assert(get_elem(&l1, 4)->n_ == 1);

    return 0;
}
