/*
** printf, strerror
*/
#include <stdio.h>


/*
** errno
*/
#include <sys/errno.h>


/*
** write, read, close, fork, getcwd, chdir, unlink, execve, dup, dup2, pipe, isatty, ttyname, ttyslot
*/
#include <unistd.h>


/*
** malloc, free, exit, getenv
*/
#include <stdlib.h>

/*
** open
*/
#include <fcntl.h>


/*
** signal, kill
*/
#include <signal.h>


/*
** opendir, readdir, closedir
*/
#include <dirent.h>


/*
** wait, wait3, wait4, waitpid
*/
#include <sys/wait.h>


/*
** stat, lstat, fstat
*/
#include <sys/stat.h>

/*
** ioctl
*/
#include <sys/ioctl.h>


/*
** tcsetattr, tcgetattr
*/
#include <termios.h>

/*
** tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
*/
#include <curses.h>
#include <term.h>

/*
** readline, add_history, rl_on_new_line, rl_replace_line, rl_redisplay
*/
#include <readline/readline.h>
#include <readline/history.h>

// https://web.mit.edu/gnu/doc/html/rlman_2.html