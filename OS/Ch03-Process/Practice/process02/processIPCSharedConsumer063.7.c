#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    const int SIZE = 4096; // the size of shared memory
    const char *name = "OS";  // the name of shared memory

    int shm_fd; // the file descriptor of shared memory
    char *ptr; // pointer to shared memory

    /* create shared memory object */ 
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    /* map the shared memory object */
    ptr = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    /* read from shared memory object */
    printf("%s", (char *)ptr);

    /* remove shared memory */
    shm_unlink(name);

    return 0;

}