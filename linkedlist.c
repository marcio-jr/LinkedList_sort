#include <stdio.h>
#include <stdlib.h>

typedef struct coords_t {
    int x;
    int y;
    double slope;
    struct coords_t *next;
} coords;
    
int MDC (int a, int b){
    if (b==0) return a;
    else return MDC(b, a%b);
}
    
void insert_sorted(coords **head, coords *ins_coord) {
    coords *tmp = NULL;
    if (*head == NULL || ins_coord->slope < (*head)->slope){
        ins_coord->next = *head;
        *head = ins_coord;
        return;
    }
    tmp = *head;
    
    while (tmp->next && (ins_coord->slope > tmp->next->slope) ){
        tmp = tmp->next;
    }
    ins_coord->next = tmp->next;
    tmp->next = ins_coord;
}
    
coords* newCoord(int new_x, int new_y)
{
  int new_MDC, yy, xx;
  new_MDC = MDC(new_x, new_y);
  coords* coord = (coords*) malloc(sizeof(coords));
  coord->x = new_x;
  coord->y = new_y;
  coord->slope = ( (double)(new_y/new_MDC)/(double)(new_x/new_MDC) );
  coord->next = NULL;
  return(coord);
}    

int main(){
        
    int x_read, y_read;
    coords *head, *lastCoord;
    int i;
    
    head = NULL;    
    while (scanf("%d%d", &x_read, &y_read) && (x_read|y_read)){
        insert_sorted (&head, newCoord (x_read, y_read));
    }
    
