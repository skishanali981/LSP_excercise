#include "dll.h"
#include <memory.h>
#include <stdlib.h>


dll_t *
get_new_dll(){
    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    return dll;
}


int
add_data_to_dll (dll_t *dll, void *app_data){

    if(!dll || !app_data)
        return -1;
    
    dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
    dll_new_node->left = NULL;
    dll_new_node->right = NULL;
    dll_new_node->data = app_data;

    if(!dll->head){
        dll->head = dll_new_node;
        return 0;
    }

    dll_node_t *first_node = dll->head;
    dll_new_node->right = first_node;
    first_node->left = dll_new_node;
    dll->head = dll_new_node;
    return 0;
}

void 
traverse_dll(dll_t* dll_name){
    dll_node_t* temp = NULL;
    temp = dll_name->head;
    while(temp != NULL){
        temp = temp->right;
        printf("Printing the Data of the Nodes: %d \n",*(int*)temp->data);
    }
}

int main(){
    dll_t* new_dll = get_new_dll();
    printf("new dll has been initialized: \n");
    int* num = 10;
    int res = add_data_to_dll(new_dll,num);
    printf("Data has been added to doubly linked list: \n", res);
    int* num2 = 20;
    int res1 = add_data_to_dll(new_dll, num2);
    printf("Created second DLL: \n");
    printf("Traversing the doubly linkedlist: \n");
    //traverse_dll(new_dll);
    
    return 0;
}