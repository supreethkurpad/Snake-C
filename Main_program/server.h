#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
struct snake {
								int x;
								int y;
								//8-UP 4-LEFT 6-RIGHT 2-DOWN
								int dir;
								struct snake *next;
								struct snake *prev;

};
void intro(char a[]);
void gen_food(int a[],int n);
void update_body(struct snake *head);
int check_col(struct snake *head,int n);
void set_box(int n, char p[][n]);
void show(int n, char p[][n]);
void init_body(struct snake *head, struct snake *body);
void snake_init(struct snake *head);
void show_snake(struct snake *head);
void add_body(struct snake *head);
