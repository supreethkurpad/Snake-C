#include "server.h"
int lives = 3;
int score = 0;
char name[20];
int food_pos[2];

int main()
{
	if (lives == 3)
	{
		intro(name);
	}

	initscr();

	int n = 25;
	char map[n][n];
	set_box(n, map);
	//AMke snake
	struct snake *head = NULL;
	head = (struct snake *)malloc(sizeof(struct snake));
	snake_init(head);

	food_pos[1] = 15;
	food_pos[0] = 15;

	int ch, pch;
	nodelay(stdscr, TRUE);
	cbreak();
	for (;;)
	{

		if ((ch = getch()) == ERR)
		{
			sleep(1);
			switch (head->dir)
			{
			case 8:
				if (head->dir != 2)
				{
					if (head->dir == 8)
					{
						head->y -= 1;
					}
					else if (head->dir == 4)
					{
						head->dir = 8;
						head->y -= 1;
					}
					else if (head->dir == 6)
					{
						head->dir = 8;
						head->y -= 1;
					}
				}
				update_body(head);
				break;
			case 2:
				if (head->dir != 8)
				{
					if (head->dir == 2)
					{
						head->y += 1;
					}
					else if (head->dir == 4)
					{
						head->dir = 2;
						head->y += 1;
					}
					else if (head->dir == 6)
					{
						head->dir = 2;
						head->y += 1;
					}
				}

				update_body(head);
				break;
			case 4:
				if (head->dir != 6)
				{
					if (head->dir == 4)
					{
						head->x -= 1;
					}
					else if (head->dir == 8)
					{
						head->dir = 4;
						head->x -= 1;
					}
					else if (head->dir == 2)
					{
						head->dir = 4;
						head->x -= 1;
					}
				}
				update_body(head);
				break;
			case 6:
				if (head->dir != 4)
				{
					if (head->dir == 6)
					{
						head->x += 1;
					}
					else if (head->dir == 8)
					{
						head->dir = 6;
						head->x += 1;
					}
					else if (head->dir == 2)
					{
						head->dir = 6;
						head->x += 1;
					}
				}
				update_body(head);
				break;
			}

			if (head->x == food_pos[0] && head->y == food_pos[1])
			{
				add_body(head);
				gen_food(food_pos, n);
				score += 10;
			}
			show(n, map);
			show_snake(head);
			mvprintw(food_pos[1], food_pos[0], "o");
			mvprintw(1, n + 5, "Score: %d", score);
			mvprintw(2, n + 5, "Live: %d", lives);
			mvprintw(3, n + 5, "Player Name: %s              ", name);

			mvprintw(n - 1, n, "%s", "");
			if (check_col(head, n))
			{
				mvprintw(n - 1, n + 10, "%s", "H");
				lives--;
				if (lives <= 0)
				{
					endwin();
					printf("GAME OVER\nPress 'r' to retry and 'q' to quit\n");
					char q;
					scanf(" %c", &q);
					if (q == 'r')
					{
						lives = 3;
						score = 0;
						main();
					}
					else
					{
						exit(0);
					}
				}

				main();
			}
			else
			{
				mvprintw(n - 1, n + 10, "%s", "N");
			}
		}
		else
		{

			switch (ch)
			{
			case 'w':
				if (head->dir != 2)
				{
					if (head->dir == 8)
					{
						head->y -= 1;
					}
					else if (head->dir == 4)
					{
						head->dir = 8;
						head->y -= 1;
					}
					else if (head->dir == 6)
					{
						head->dir = 8;
						head->y -= 1;
					}
				}
				update_body(head);
				break;
			case 's':
				if (head->dir != 8)
				{
					if (head->dir == 2)
					{
						head->y += 1;
					}
					else if (head->dir == 4)
					{
						head->dir = 2;
						head->y += 1;
					}
					else if (head->dir == 6)
					{
						head->dir = 2;
						head->y += 1;
					}
				}

				update_body(head);
				break;
			case 'a':
				if (head->dir != 6)
				{
					if (head->dir == 4)
					{
						head->x -= 1;
					}
					else if (head->dir == 8)
					{
						head->dir = 4;
						head->x -= 1;
					}
					else if (head->dir == 2)
					{
						head->dir = 4;
						head->x -= 1;
					}
				}
				update_body(head);
				break;
			case 'd':
				if (head->dir != 4)
				{
					if (head->dir == 6)
					{
						head->x += 1;
					}
					else if (head->dir == 8)
					{
						head->dir = 6;
						head->x += 1;
					}
					else if (head->dir == 2)
					{
						head->dir = 6;
						head->x += 1;
					}
				}
				update_body(head);
				break;
			}

			if (check_col(head, n))
			{
				mvprintw(n - 1, n + 10, "%s", "H");
				lives--;
				if (lives <= 0)
				{
					endwin();
					printf("GAME OVER\nPress 'r' to retry and 'q' to quit\n");
					char q;
					scanf(" %c", &q);
					if (q == 'r')
					{
						lives = 3;
						score = 0;
						main();
					}
					else
					{
						exit(0);
					}
				}

				main();
			}
			else
			{
				mvprintw(n - 1, n + 10, "%s", "N");
			}
			if (head->x == food_pos[0] && head->y == food_pos[1])
			{
				add_body(head);
				gen_food(food_pos, n);
				score += 10;
			}
			show(n, map);
			void snake_init(struct snake * head);
			show_snake(head);
			mvprintw(food_pos[1], food_pos[0], "o");
			mvprintw(1, n + 5, "Score: %d", score);
			mvprintw(2, n + 5, "Live: %d", lives);
			mvprintw(3, n + 5, "Player Name: %s              ", name);

			sleep(0.5);
		}
		refresh();
	}

	getch();
	endwin();
	return 0;
}
