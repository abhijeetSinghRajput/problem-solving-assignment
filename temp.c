int main()
{
    pid_t pid;
    for (int i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("Child PID: %d\n", getpid());
            exit(0);
        }
        else if (pid < 0)
        {
            printf("fork() failed.\n");
        }
    }
    printf("Parent Process PID: %d\n", getpid());
    return 0;
}
