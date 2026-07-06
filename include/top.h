/*
** EPITECH PROJECT, 2026
** top structures header
*/

#ifndef TOP_H
#define TOP_H

#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include <ncurses.h>

#define USER_MAX_LEN 32
#define HOSTNAME_MAX_LEN 256
#define COMMAND_MAX_LEN 256
#define UPTIME_MAX_LEN 64
#define SUCCESS 0
#define ERROR 84

typedef struct top_load_s {
    double one;
    double five;
    double fifteen;
} top_load_t;

typedef struct top_tasks_s {
    int total;
    int running;
    int sleeping;
    int stopped;
    int zombie;
} top_tasks_t;

typedef struct top_cpu_s {
    double user;
    double nice;
    double system;
    double idle;
    double iowait;
    double irq;
    double softirq;
    double steal;
    double guest;
    double guest_nice;
} top_cpu_t;

typedef struct top_mem_s {
    unsigned long total_kb;
    unsigned long free_kb;
    unsigned long used_kb;
    unsigned long buffers_kb;
    unsigned long cached_kb;
    unsigned long available_kb;
} top_mem_t;

typedef struct top_swap_s {
    unsigned long total_kb;
    unsigned long used_kb;
    unsigned long free_kb;
    unsigned long cached_kb;
} top_swap_t;

typedef struct top_process_s {
    pid_t pid;
    uid_t uid;
    char user[USER_MAX_LEN];
    int pr;
    int ni;
    unsigned long virt_kb;
    unsigned long res_kb;
    unsigned long shr_kb;
    char state;
    double cpu_percent;
    double mem_percent;
    unsigned long long time_cs;
    char command[COMMAND_MAX_LEN];
} top_process_t;

typedef struct top_summary_s {
    char hostname[HOSTNAME_MAX_LEN];
    char uptime[UPTIME_MAX_LEN];
    top_load_t load;
    top_tasks_t tasks;
    top_cpu_t cpu;
    top_mem_t mem;
    top_swap_t swap;
    time_t timestamp;
} top_summary_t;

#endif /* TOP_H */
