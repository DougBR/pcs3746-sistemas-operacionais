#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

void bypass_signal(int sig_no)
{
  printf("Division by zero\nSignal number:%d\n", sig_no);
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &bypass_signal;
    sigaction(SIGFPE, &sa, NULL);
    while (1) {
      sleep(1);
      printf("Doing nothing.\n");
    }
    return 0;
}
