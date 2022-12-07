#include<stdio.h>
#include<omp.h>

void main()
{
int x=0;

omp_lock_t writelock; // omp_lock_t is data type used to declare lock variable.

omp_init_lock(&writelock); // Function omp_init_lock() is used to initialize lock.
                           // By default, lock is unset.

#pragma omp parallel num_threads(300) 
{
omp_set_lock(&writelock); //omp_set_lock() is used to set lock
x=x+1;
omp_unset_lock(&writelock);
}

printf("x=%d\n",x);

omp_destroy_lock(&writelock);

}