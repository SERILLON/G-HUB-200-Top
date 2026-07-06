/*
** EPITECH PROJECT, 2026
** top
** File description:
** top
*/

#include "top.h"

top_summary_t *set_summary(top_summary_t *summary)
{
    get_hostname(summary->hostname, HOSTNAME_MAX_LEN);
    get_uptime(summary->uptime, UPTIME_MAX_LEN);
    get_load(&summary->load);
    get_tasks(&summary->tasks);
    get_cpu(&summary->cpu);
    return summary;
}


void init_ncurses(void)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(0);
}

int main(int ac, char **av)
{
    if (ac > 2)
        return ERROR;
    init_ncurses();
    return SUCCESS;
}
