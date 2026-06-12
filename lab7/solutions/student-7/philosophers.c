#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_MEALS 3

typedef enum e_state
{
    THINKING,
    HUNGRY,
    EATING
} t_state;

typedef enum e_philo_flags
{
    PHILO_NONE      = 0,
    PHILO_HAS_LEFT  = 1 << 0,
    PHILO_HAS_RIGHT = 1 << 1
} t_philo_flags;

typedef struct s_philosopher
{
    int             id;
    t_state         state;
    t_philo_flags   flags;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} t_philosopher;

void print_state(t_philosopher *philo)
{
    const char *states[] = {"THINKING", "HUNGRY", "EATING"};
    printf("Philosopher %d is %s\n", philo->id + 1, states[philo->state]);
}

void think(t_philosopher *philo)
{
    philo->state = THINKING;
    print_state(philo);
    usleep(100000); // имитация размышления
}

void eat(t_philosopher *philo)
{
    philo->state = EATING;
    print_state(philo);
    usleep(100000); // имитация еды
}

void take_forks(t_philosopher *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        printf("Philosopher %d took left fork\n", philo->id + 1);

        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        printf("Philosopher %d took right fork\n", philo->id + 1);
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        printf("Philosopher %d took right fork\n", philo->id + 1);

        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        printf("Philosopher %d took left fork\n", philo->id + 1);
    }
    philo->state = EATING;
    print_state(philo);
}

void put_forks(t_philosopher *philo)
{
    if (philo->flags & PHILO_HAS_LEFT)
    {
        pthread_mutex_unlock(philo->left_fork);
        philo->flags &= ~PHILO_HAS_LEFT;
    }
    if (philo->flags & PHILO_HAS_RIGHT)
    {
        pthread_mutex_unlock(philo->right_fork);
        philo->flags &= ~PHILO_HAS_RIGHT;
    }
    printf("Philosopher %d put forks\n", philo->id + 1);
    philo->state = THINKING;
    print_state(philo);
}

void *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;

    for (int i = 0; i < NUM_MEALS; i++)
    {
        think(philo);
        philo->state = HUNGRY;
        print_state(philo);
        take_forks(philo);
        eat(philo);
        put_forks(philo);
    }
    return NULL;
}

int main(void)
{
    t_philosopher philosophers[NUM_PHILOSOPHERS];
    pthread_mutex_t forks[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_mutex_init(&forks[i], NULL);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        philosophers[i].id = i;
        philosophers[i].state = THINKING;
        philosophers[i].flags = PHILO_NONE;
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % NUM_PHILOSOPHERS];
        pthread_create(&philosophers[i].thread, NULL, philosopher_routine, &philosophers[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_join(philosophers[i].thread, NULL);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_mutex_destroy(&forks[i]);

    return 0;
}