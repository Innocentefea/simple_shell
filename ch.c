#include "shell.h"
/**
 * child - func for child process
 * @fulldir: fulldir of exec
 * @toks: tokenized user input
 * Return: 0 on success
 */
int child(char *fulldir, char **toks, char **environ)
{
        pid_t child_pid;
	int status;
	int execve_status;
	char **envp = environ;

        child_pid = fork();
        if (child_pid == -1)
        {
                errors(1);
                exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
                execve_status = execve(fulldir, toks, envp);
		if (execve_status == -1)
		{
			errors(2);
			exit(EXIT_FAILURE);
		}
        }
        else
                wait(&status);
	return(0);
}
