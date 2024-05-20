/**
 * arm/syscalls.h
 * 
 * This file is an implementation of the most important
 * syscalls for the ARM architecture which are used in the
 * RawC project.
 * 
 * Author: ruxixa
 * 
 * Date: 17.05.2024
*/

// include guard
#ifndef __ARM_SYSCALLS_H__
#define __ARM_SYSCALLS_H__

#include <sys/stat.h>

/**
 * Macros for file opening flags and file permissions.
 * 
 * Flags:
 * - O_RDONLY - read only
 * - O_WRONLY - write only
 * - O_RDWR   - read and write
 * - O_CREAT  - create file if it does not exist
 * - O_APPEND - append to the end of the file
 * - O_TRUNC  - truncate the file
 *  
 * Permissions:
 * - S_IRUSR  - read permission owner
 * - S_IWUSR  - write permission owner
 * - S_IRGRP  - read permission group
 * - S_IROTH  - read permission others
*/

#define _O_RDONLY  0x0000     // O_RDONLY - read only
#define _O_WRONLY  0x0001     // O_WRONLY - write only
#define _O_RDWR    0x0002     // O_RDWR   - read and write
#define _O_CREAT   0x0100     // O_CREAT  - create file if it does not exist
#define _O_APPEND  0x0200     // O_APPEND - append to the end of the file
#define _O_TRUNC   0x0400     // O_TRUNC  - truncate the file

#define _S_IRUSR  00400       // S_IRUSR  - read permission owner
#define _S_IWUSR  00200       // S_IWUSR  - write permission owner
#define _S_IRGRP  00040       // S_IRGRP  - read permission group
#define _S_IROTH  00004       // S_IROTH  - read permission others

/**
 * Syscall definitions
 * 
 * Every Linux syscall has its own number, which is used to call and identify it.
 * 
 * Syscalls we are going to use:
 * 
 * | Syscall    | Numer | Arguments |
 * | ---------  | ----- | --------- |
 * | SYS_READ   | 63    | 3         |
 * | SYS_WRITE  | 64    | 3         |
 * | SYS_OPEN   | 5     | 3         |
 * | SYS_CLOSE  | 6     | 1         |
 * | SYS_EXIT   | 93    | 1         |
 * | SYS_RENAME | 128   | 2         |
 * 
 * You can find the list of all syscalls here:
 *  https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md
*/

#define __SYS_READ__   63
#define __SYS_WRITE__  64
#define __SYS_OPEN__   5
#define __SYS_CLOSE__  6
#define __SYS_EXIT__   93
#define __SYS_RENAME__ 128

/**
 * Read from a file descriptor.
 * 
 * @param fd - file descriptor
 * @param buf - buffer to store read data
 * @param size - number of bytes to read
 * @return - number of bytes read, or an error code
 * 
 * @return - number of bytes read, or an error code
 */
long long sys_read(int fd, void *buf, unsigned long long size) {
    long long ret;

    /**
     * Call the syscall for reading with the following parameters:
     * 
     * @param r7  - syscall number
     * @param r0  - file descriptor
     * @param r1  - buffer address
     * @param r2  - size
    */
    asm volatile
    (
        "svc #0"
        : "=r" (ret)
        //         R7         R0       R1        R2
        : "r"(__SYS_READ__), "r"(fd), "r"(buf), "r"(size)
        : "memory"
    );

    // Return the number of bytes read or an error code
    return ret;
}

/**
 * Write to a file descriptor.
 * 
 * @param fd - file descriptor
 * @param buf - buffer containing data to write
 * @param size - number of bytes to write
 * 
 * @return - number of bytes written, or an error code
*/
long long sys_write(int fd, const void *buf, unsigned long long size) {
    long long ret;

    /**
     * Call the syscall for writing with the following parameters:
     * 
     * @param r7  - syscall number
     * @param r0  - file descriptor
     * @param r1  - buffer address
     * @param r2  - size
    */
    asm volatile
    (
        "svc #0"
        : "=r" (ret)
        //         R7          R0       R1        R2
        : "r"(__SYS_WRITE__), "r"(fd), "r"(buf), "r"(size)
        : "memory"
    );

    return ret;
}

/**
 * Exit the current process.
 * 
 * @param status - exit status code
 * 
 * @return - void
 */
void sys_exit(int status) {
    /**
     * Call the syscall for exiting with the following parameters:
     * 
     * @param r7  - syscall number
     * @param r0  - exit status code
    */
    asm volatile
    (
        "svc #0"
        :
        //         R7          R0
        : "r"(__SYS_EXIT__), "r"(status)
        : "memory"
    );
}

/**
 * Rename the given file.
 * 
 * @param old_name - old name of the file
 * @param new_name - new name of the file
 * @return - 0 on success, or an error code on failure
*/
int sys_rename(const char* old_name, const char* new_name) {
    long long ret;
    /**
     * Call the syscall for renaming a file with the following parameters:
     * 
     * @param r7  - syscall number
     * @param r0  - old name of the file
     * @param r1  - new name of the file
    */

    asm volatile
    (
        "svc #0"
        : "=r" (ret)
        //         R7             R0              R1
        : "r"(__SYS_RENAME__), "r"(old_name), "r"(new_name)
        : "memory"
    );

    return (int)ret;
}

/**
 * Open or create a file.
 * 
 * @param filename - name of the file to open or create
 * @param flags - flags determining the mode of opening/creating the file
 * @param mode - file permissions
*/
long long sys_open(const char *filename, int flags, int mode) {
    long long ret;
    /**
     * Call the syscall for opening a file with the following parameters:
     * 
     * @param r7  - syscall number
     * @param r0  - filename
     * @param r1  - flags
     * @param r2  - mode
    */

    asm volatile
    (
        "svc #0"
        : "=r" (ret)
        //         R7          R0           R1        R2
        : "r"(__SYS_OPEN__), "r"(filename), "r"(flags), "r"(mode)
        : "memory"
    );

    return ret;
}

/**
 * Close a file descriptor.
 * 
 * @param fd - file descriptor to close
 * @return - 0 on success, or an error code on failure
*/
int sys_close(int fd) {
    long long ret;
    /**
     * Call the syscall for closing a file descriptor with the following parameters:
     * 
     * @param r7  - syscall number
     * @param r0  - file descriptor
    */
    asm volatile
    (
        "svc #0"
        : "=r" (ret)
        //         R7             R0
        : "r"(__SYS_CLOSE__), "r"(fd)
        : "memory"
    );

    return (int)ret;
}

#endif // include guard
