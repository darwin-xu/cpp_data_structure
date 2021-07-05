struct linear_list
{
    int* array_;
    int  length_;
};

typedef linear_list linear_list_t;

void init_list(linear_list_t* ll)
{
}

void destroy_list(linear_list_t* ll)
{
}

void clear_list(linear_list_t* ll)
{
}

bool is_list_empty(linear_list_t* ll)
{
    return false;
}

int list_length(linear_list_t* ll)
{
    return 0;
}

int get_elem(linear_list_t* ll, int i)
{
    return 0;
}

int locate_elem(linear_list_t* ll, int n)
{
    return 0;
}

void list_insert(linear_list_t* ll, int i, int n)
{
}

void list_delete(linear_list_t* ll, int i)
{
}

void list_push_back(linear_list_t* ll, int n)
{
}

typedef void (*visit)(int n);

void list_traverse(linear_list_t* ll, visit v)
{
}

int main()
{
    return 0;
}
