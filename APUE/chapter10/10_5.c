#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MAX_TIMER 10	

struct Timer {
	int inUse;
	unsigned int time;
} timerList[MAX_TIMER];

static int timerNext = -1;

int getUnUseIndex()
{
	unsigned int i;
	for (i = 0; i != MAX_TIMER; ++i) {
		if (0 == timerList[i].inUse) {
			break;
		}
	}

	return MAX_TIMER == i ? -1: i;
}

void checkNextTimer()
{
	int i = 0;
	for (i = 0; i != MAX_TIMER; ++i) {
		if (0 == timerList[i].inUse) {
			continue;
		}

		if (-1 == timerNext) {
			timerNext = i;
			continue;
		}

		if (timerList[timerNext].time > timerList[i].time)
			timerNext = i;
	}
}

void updateTime(int time)
{
	if (timerNext == -1) {
		printf("has no timer running\n");
		return;
	}

	unsigned int subtractor = (0 == time) ? timerList[timerNext].time : time;

	for (int i = 0; i != MAX_TIMER; ++i) {
		if (timerList[i].inUse != 0)
			timerList[i].time -= subtractor;
	}

	timerList[timerNext].inUse = 0;
	timerNext = -1;

	checkNextTimer();
}

void sig_alrm(int signo)
{
	printf("%s\n", __FUNCTION__);
	updateTime(0);
	alarm(timerList[timerNext].time);	
}

void setTimer(unsigned int seconds)
{
	int index;
	if (-1 == (index = getUnUseIndex())) {
		printf("%s timer is full\n", __FUNCTION__);
		return;
	}

	checkNextTimer();

	timerList[index].inUse = 1;
	timerList[index].time = seconds;

	if (-1 == timerNext) {
		timerNext = index;
		alarm(seconds);
		return;
	}

	unsigned int unSlept = alarm(0);

	if (seconds < unSlept) {
		updateTime(unSlept);
		alarm(seconds);
	}
	else {
		alarm(unSlept);
	}
}

void initTimerList()
{
	for (int i = 0; i != MAX_TIMER; ++i) {
		timerList[i].inUse = 0;
		timerList[i].time = 0;
	}
}

int
main(int argc, char const *argv[])
{
	initTimerList();

	signal(SIGALRM, sig_alrm);

	setTimer(2);
	setTimer(6);
	setTimer(3);
	setTimer(5);

	while (1);
}