#include "server.h"

void intro(char a[])
{
	printf("SNAKE GAME\nEnter your name: ");
	scanf("%s",a);
	printf("Press A to start, and any key to exit\n");
	char ch;
	scanf(" %c",&ch);
	if(ch!='a'){exit(0);}
}


void gen_food(int a[],int n)
{
								a[0] = (rand() % (n-2)) +1 ;
								a[1] = (rand() % (n-2)) +1 ;

}

void update_body(struct snake *head)
{
								struct snake *p;
								p = head->next;
								while(p!=NULL)
								{
																if(head->dir == p->dir)
																{
																								switch(head->dir)
																								{
																								case 8: p->y = (head->y)+1; break;
																								case 2: p->y= (head->y)-1; break;
																								case 4: p->x= (head->x)+1; break;
																								case 6: p->x= (head->x)-1; break;
																								}

																}
																else
																{

																								switch(p->dir)
																								{

																								case 8: p->y-=1; if(head->y==p->y) {p->dir = head->dir;} break;
																								case 2: p->y+=1; if(head->y==p->y) {p->dir = head->dir;} break;
																								case 4: p->x-=1; if(head->x==p->x) {p->dir = head->dir;} break;
																								case 6: p->x+=1; if(head->x==p->x) {p->dir = head->dir;} break;
																								}

																}
																head = head->next;
																p = p->next;
								}
}

int check_col(struct snake *head,int n)
{
								if((head->x>=0 && head->x<=n-1 && head->y==0) || (head->x>=0 && head->x<=n-1 && head->y==n-1)) return 1;
								if((head->y>=0 && head->y<=n-1 && head->x==0) || (head->y>=0 && head->y<=n-1 && head->x==n-1)) return 1;
								struct snake *p;
								p = head->next;
								while(p!=NULL)
								{
																if( (head->x == p->x) && (head->y == p->y))
																{
																								return 1;

																}
																p = p->next;
								}
								return 0;
}


void set_box(int n, char p[][n])
{
								for(int i =1; i<n-1; i++)
								{
																for(int j =1; j<n-1; j++)
																{
																								p[i][j]=' ';
																}

								}
								for(int i=0; i<n; i++)
								{
																p[0][i] = '|';
																p[i][0] = '-';
								}
								for(int i=0; i<n; i++)
								{
																p[n-1][i] ='|';
																p[i][n-1] = '-';
								}
}

void show(int n, char p[][n])
{
								for(int i =0; i<n; i++)
								{
																for(int j = 0; j<n; j++)
																{
																								mvprintw(j,i,"%c",p[i][j]);
																}
								}
}


void init_body(struct snake *head, struct snake *body)
{
								body->dir = head->dir;
								if(head->dir==8)
								{
																body->x = head->x;
																body->y = head->y+1;
								}
								else if(head->dir==4)
								{
																body->x = head->x-1;
																body->y = head->y;
								}
								if(head->dir==6)
								{
																body->x = head->x+1;
																body->y = head->y;
								}
								if(head->dir==2)
								{
																body->x = head->x;
																body->y = head->y-1;
								}
								body->next = NULL;
								body->prev = head;
}

void snake_init(struct snake *head)
{
								struct snake *body = NULL;

								body = (struct snake*)malloc(sizeof(struct snake));

								head->x =head->y=10;
								head->dir = 8;
								head->next = body;
								head->prev = NULL;
								init_body(head,body);
}

void show_snake(struct snake *head)
{

								while(head!=NULL)
								{
																mvprintw(head->y,head->x,"o");
																head = head->next;
								}
}

void add_body(struct snake *head)
{
								while(head->next != NULL)
								{
																head = head->next;
								}

								struct snake *n = NULL;
								n = (struct snake*)malloc(sizeof(struct snake));
								head->next = n;
								init_body(head,n);


}
