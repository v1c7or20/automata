#include <stdio.h>
#include <stdbool.h>

struct automata
{
    char * name;
    bool is_end;
    int number_state;
    struct automata * next_states;
};

struct automata construct(char * nombre, bool is_end)
{
    struct automata constructed;
    strncpy(constructed.name, nombre, strlen(nombre));
    constructed.is_end = is_end;
    constructed.next_states = NULL;
    return constructed;
}

void add_state(char * state_from, char * state_to, struct list list_of_states)
{
    struct list * node_from = & list_of_states;
    look_for_state(node_from, state_from);
    struct list * node_to = & list_of_states;
    look_for_state(node_to, state_to);
    if (node_from->actual_automata->next_states == NULL)
    {
        create_first_next_states(node_from->actual_automata, node_to->actual_automata);
    }
    else
    {
        struct automata * next_states_to_copy = node_from->actual_automata->next_states;
        node_from->actual_automata->next_states = NULL;
        node_from->actual_automata->number_state += 1;
        node_from->actual_automata->next_states = (struct automata*)malloc(node_from->actual_automata->number_state * sizeof(struct automata));
        for (int i = 0; i < node_from->actual_automata->number_state -1; i++)
        {
            
        }
        
    }
    
}

void create_first_next_states(struct automata * node_from, struct automata * node_to)
{
    node_from->next_states = (struct automata*)malloc(sizeof(struct automata));
    node_from->next_states = node_to;
    node_from->number_state += 1;
}



struct automata * next_state(char * state_nombre, struct automata * current_state)
{

}