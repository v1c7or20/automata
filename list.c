#include "automata.c"


struct list
{
    struct automata * actual_automata;
    struct list * next_node;
};

struct list create_list(char nombre_nodo)
{
    //create node of automata
    struct automata * nodo_automata = (struct automata*)malloc(sizeof(struct automata));
    *nodo_automata = construct(nombre_nodo, true);
    //create start of list
    struct list list_of_nodes;
    list_of_nodes.next_node = NULL;
    list_of_nodes.actual_automata = nodo_automata;
    return list_of_nodes;
}

void add_node(struct list nodo_inicial ,char * nombre_nodo)
{
    struct list *nodo_to_insert = &nodo_inicial;
    //look for end
    while (nodo_to_insert->next_node != NULL)
    {
        nodo_to_insert = nodo_to_insert->next_node;
    }
    //create new node
    nodo_to_insert->actual_automata->is_end = false;
    nodo_to_insert->next_node = (struct list*)malloc(sizeof(struct list));
    //pass to the new node
    nodo_to_insert = nodo_to_insert->next_node;
    nodo_to_insert->next_node = NULL;
    *(nodo_to_insert->actual_automata) = construct(nombre_nodo, true);
}

void look_for_state(struct list * list_of_states, char * name_of_state)
{
    while (strcmp(list_of_states->actual_automata->name, name_of_state) != 0)
    {
        if (list_of_states->next_node != NULL)
        {
            list_of_states = list_of_states->next_node;
        }
        else
        {
            printf("The state: %s does not exist", name_of_state);
            return;
        }
    }
}