#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

void bypass_signal(int sig_no)
{
  printf("[chil] Division by zero\nSignal number:%d\n", sig_no);
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &bypass_signal;
    sigaction(SIGFPE, &sa, NULL);
    int i = 0;
    while (1) {
      sleep(1);
      printf("[chil] Doing nothing %d.\n", ++i);
      10/(i % 5 != 0);
    }
    return 0;
}
