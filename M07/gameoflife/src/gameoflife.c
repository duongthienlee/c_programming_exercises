#include "gameoflife.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

CellStatus **create_dead_cells(unsigned int x_size, unsigned int y_size)
{
    CellStatus **cells_pointer = malloc(y_size * sizeof(CellStatus *));
    if (cells_pointer != NULL)
    {

        for (unsigned int i = 0; i < y_size; i++)
        {
            cells_pointer[i] = malloc(x_size * sizeof(CellStatus));

            if (cells_pointer[i] == NULL)
            {
                for (unsigned int j = 0; j < i; j++)
                    free(cells_pointer[j]);

                free(cells_pointer);
                return NULL;
            }
            for (unsigned int j = 0; j < x_size; j++)
                cells_pointer[i][j] = DEAD;
        }

        return cells_pointer;
    }

    return NULL;
}
/* Exercise a: Allocates needed memory for the GameArea structure and
 * the actual game area. 'x_size' and 'y_size' indicate the horizontal and
 * vertical dimensions of the GameArea.
 * 
 * Returns: pointer to the GameArea structure allocated by this function.
 */
GameArea *createGameArea(unsigned int x_size, unsigned int y_size)
{
    GameArea *result = malloc(sizeof(GameArea));
    result->cells = create_dead_cells(x_size, y_size);

    if (result != NULL && result->cells != NULL)
    {
        result->x_size = x_size;
        result->y_size = y_size;

        return result;
    }
    free(result);
    return NULL;
}

/* Free memory allocated for GameArea <a>.
 */
void releaseGameArea(GameArea *a)
{
    for (unsigned int i = 0; i < a->y_size; i++)
        free(a->cells[i]);

    free(a->cells);
    free(a);
}

/* Exercise b: Initialize game GameArea by setting exactly <n> cells into
 * ALIVE CellStatus in the game GameArea <a>.
 */
void initGameArea(GameArea *a, unsigned int n)
{
    int coord_x, coord_y;
    while (n > 0)
    {
        coord_y = rand() % a->y_size;
        coord_x = rand() % a->x_size;

        if (a->cells[coord_y][coord_x] == DEAD)
        {
            a->cells[coord_y][coord_x] = ALIVE;
            n--;
        }
    }
}

/* Exercise c: Output the current CellStatus of GameArea <a>.
 */
void printGameArea(const GameArea *a)
{
    char dead_cell = '.', alive_cell = '*';

    for (unsigned int i = 0; i < a->y_size; i++)
    {
        for (unsigned int j = 0; j < a->x_size; j++)
        {
            switch (a->cells[i][j])
            {
            case DEAD:
                printf("%c", dead_cell);
                break;
            case ALIVE:
                printf("%c", alive_cell);
                break;
            }
        }
        printf("\n");
    }
}

void copy_cell_status(CellStatus **source, CellStatus **destination, unsigned int x_size, unsigned int y_size)
{
    for (unsigned int i = 0; i < y_size; i++)
        for (unsigned int j = 0; j < x_size; j++)
            destination[i][j] = source[i][j];
}

GameArea *copy_area(GameArea *original)
{
    GameArea *result = createGameArea(original->x_size, original->y_size);

    if (result != NULL)
    {
        copy_cell_status(original->cells, result->cells, original->x_size, original->y_size);
        return result;
    }

    releaseGameArea(result);
    return NULL;
}

bool is_top_row(int i)
{
    if (i == 0)
        return true;
    return false;
}

bool is_bottom_row(unsigned int i, const GameArea *of_area)
{
    if (i == of_area->y_size - 1)
        return true;
    return false;
}

bool is_left_column(unsigned int j)
{
    if (j == 0)
        return true;
    return false;
}

bool is_right_column(unsigned int j, const GameArea *of_area)
{
    if (j == of_area->x_size - 1)
        return true;
    return false;
}

int get_increment_if_alive(CellStatus cell)
{
    if (cell == ALIVE)
        return 1;
    return 0;
}

/* Calculates number of live neighbours around position (x,y),
 * and returns the count.
 */
unsigned int live_neighbours(const GameArea *a, unsigned int x, unsigned int y)
{
    unsigned int cnt = 0;
    bool left = is_left_column(y), right = is_right_column(y, a), top = is_top_row(x), bottom = is_bottom_row(x, a);

    // horizontal
    if (!left)
        cnt += get_increment_if_alive(a->cells[x][y - 1]);
    if (!right)
        cnt += get_increment_if_alive(a->cells[x][y + 1]);
    // vertical
    if (!top)
        cnt += get_increment_if_alive(a->cells[x - 1][y]);
    if (!bottom)
        cnt += get_increment_if_alive(a->cells[x + 1][y]);

    //diagonal
    if (!left && !top)
        cnt += get_increment_if_alive(a->cells[x - 1][y - 1]);
    if (!left && !bottom)
        cnt += get_increment_if_alive(a->cells[x + 1][y - 1]);
    if (!right && !top)
        cnt += get_increment_if_alive(a->cells[x - 1][y + 1]);
    if (!right && !bottom)
        cnt += get_increment_if_alive(a->cells[x + 1][y + 1]);

    return cnt;
}

/* Exercise d: Advance GameArea <a> by one generation.
 */
void gameTick(GameArea *a)
{
    GameArea *temporary_area = copy_area(a);

    if (temporary_area != NULL)
    {
        unsigned int number_of_live_neighbours;

        for (unsigned int i = 0; i < a->y_size; i++)
        {
            for (unsigned int j = 0; j < a->x_size; j++)
            {
                number_of_live_neighbours = live_neighbours(temporary_area, i, j);

                switch (temporary_area->cells[i][j])
                {
                case ALIVE:
                    if (number_of_live_neighbours < 2)
                        a->cells[i][j] = DEAD;

                    else if (number_of_live_neighbours == 2 || number_of_live_neighbours == 3)
                        a->cells[i][j] = ALIVE;

                    else if (number_of_live_neighbours > 3)
                        a->cells[i][j] = DEAD;

                    break;
                case DEAD:
                    if (number_of_live_neighbours == 3)
                        a->cells[i][j] = ALIVE;
                    break;
                }
            }
        }

        releaseGameArea(temporary_area);
    }
}

/*
// Aalto's answer
// Exercise a: Allocates needed memory for the GameArea structure and
// the actual game area. 'x_size' and 'y_size' indicate the horizontal and
// vertical dimensions of the GameArea.
// Returns: pointer to the GameArea structure allocated by this function.

GameArea *createGameArea(unsigned int x_size, unsigned int y_size)
{
    GameArea *a = malloc(sizeof(GameArea));
    a->x_size = x_size;
    a->y_size = y_size;

    a->cells = malloc(y_size * sizeof(CellStatus *));
    for (unsigned int y = 0; y < y_size; y++)
    {
        a->cells[y] = malloc(x_size * sizeof(CellStatus));
        for (unsigned int x = 0; x < x_size; x++)
        {
            a->cells[y][x] = DEAD;
        }
    }

    return a;
}

// Free memory allocated for GameArea <a>.
void releaseGameArea(GameArea *a)
{
    for (unsigned int y = 0; y < a->y_size; y++)
    {
        free(a->cells[y]);
    }

    free(a->cells);
    free(a);
}

// Exercise b: Initialize game GameArea by setting exactly <n> cells into
// ALIVE CellStatus in the game GameArea <a>.
//
void initGameArea(GameArea *a, unsigned int n)
{
    for (; n > 0; n--)
    {
        int x = rand() % a->x_size;
        int y = rand() % a->y_size;

        while (a->cells[y][x] == ALIVE)
        {
            x = rand() % a->x_size;
            y = rand() % a->y_size;
        }

        a->cells[y][x] = ALIVE;
    }
}

//  Exercise c: Output the current CellStatus of GameArea <a>.
void printGameArea(const GameArea *a)
{
    for (unsigned int y = 0; y < a->y_size; y++)
    {
        for (unsigned int x = 0; x < a->x_size; x++)
        {
            printf("%c", a->cells[y][x] ? '*' : '.');

            // The above with the ternary operator ? : is the same as

            // if(a->cells[y][x] == ALIVE)
            //     printf("%c", '*');
        }
        printf("\n");
    }
}

// Calculates number of live neighbours around position (x,y) and returns the count.
unsigned int live_neighbours(const GameArea *a, unsigned int x, unsigned int y)
{
    unsigned int n = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if ((int)x + j < 0 || x + j >= a->x_size || (int)y + i < 0 || y + i >= a->y_size)
                continue;

            if (i == 0 && j == 0)
                continue;

            if (a->cells[y + i][x + j] == ALIVE)
            {
                n++;
            }
        }
    }

    return n;
}

//  Exercise d: Advance GameArea <a> by one generation.
void gameTick(GameArea *a)
{
    CellStatus **c = malloc(a->y_size * sizeof(CellStatus *));
    for (unsigned int y = 0; y < a->y_size; y++)
    {
        c[y] = malloc(a->x_size * sizeof(CellStatus));
    }

    for (unsigned int y = 0; y < a->y_size; y++)
    {
        for (unsigned int x = 0; x < a->x_size; x++)
        {
            int n = live_neighbours(a, x, y);

            c[y][x] = a->cells[y][x];

            if (a->cells[y][x] == ALIVE)
            {
                if (n == 2 || n == 3)
                    c[y][x] = ALIVE;
                else
                    c[y][x] = DEAD;
            }
            else
            {
                if (n == 3)
                {
                    c[y][x] = ALIVE;
                }
            }
        }
    }

    for (unsigned int y = 0; y < a->y_size; y++)
    {
        free(a->cells[y]);
    }
    free(a->cells);

    a->cells = c;
}
*/