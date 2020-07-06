#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    char * name;
    bool is_end;
    int number_state;
    struct automata ** next_states;
} automata;

typedef struct 
{
    automata * actual_automata;
    struct list * next_node;
} list;

void construct_node(automata * to_construct, char * nombre, bool is_end)
{
    to_construct = (automata *)malloc(sizeof( automata));
    strncpy(to_construct->name, nombre, strlen(nombre));
    to_construct->is_end = is_end;
    to_construct->next_states = NULL;
}

void look_for_state(list * list_of_states, char * name_of_state)
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

void create_first_next_states(automata * node_from, automata * node_to)
{
    *(node_from->next_states) = (automata*)malloc(sizeof(automata));
    node_from->next_states[0] = node_to;
    node_from->number_state += 1;
}

void add_state(char * state_from, char * state_to, list * list_of_states)
{
    list * node_from =  list_of_states;
    look_for_state(node_from, state_from);
    list * node_to = list_of_states;
    look_for_state(node_to, state_to);
    if (*(node_from->actual_automata->next_states) == NULL)
    {
        create_first_next_states(node_from->actual_automata, node_to->actual_automata);
    }
    else
    {
        automata ** next_states_to_copy = node_from->actual_automata->next_states;
        node_from->actual_automata->next_states = NULL;
        node_from->actual_automata->number_state += 1;
        *(node_from->actual_automata->next_states) = (automata*)malloc(node_from->actual_automata->number_state * sizeof(automata ));
        for (int i = 0; i < node_from->actual_automata->number_state -1; i++)
        {
            node_from->actual_automata->next_states[i] = next_states_to_copy[i];
        }
        node_from->actual_automata->next_states[node_from->actual_automata->number_state] = node_to->actual_automata;
    }
    
}

automata * next_state(char * state_nombre, automata * current_state)
{

}


list create_list(char * nombre_nodo)
{
    //create node of automata
    automata * nodo_automata = (automata*)malloc(sizeof(automata));
    construct_node(nodo_automata, nombre_nodo, true);
    //create start of list
    list list_of_nodes;
    list_of_nodes.next_node = NULL;
    list_of_nodes.actual_automata = nodo_automata;
    return list_of_nodes;
}

void add_node(list nodo_inicial ,char * nombre_nodo)
{
    list *nodo_to_insert = &nodo_inicial;
    //look for end
    while (nodo_to_insert->next_node != NULL)
    {
        nodo_to_insert = nodo_to_insert->next_node;
    }
    //create new node
    nodo_to_insert->actual_automata->is_end = false;
    nodo_to_insert->next_node = (list*)malloc(sizeof(list));
    //pass to the new node
    nodo_to_insert = nodo_to_insert->next_node;
    nodo_to_insert->next_node = NULL;
    construct_node(nodo_to_insert->actual_automata, nombre_nodo, true);
}

