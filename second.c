#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

volatile int flag = 0;

void sigCatcher(int signum)
{
	printf("Time Lapsed\n");
	flag=1;
}

int main(int argc, char *argv[])
{
	float total,dt;
	double wait;
	double average = 0;
	printf("Enter total time: ");
	scanf("%f",&total);
	printf("Enter dt: ");
	scanf("%f",&dt);

	printf("Entered %.3f seconds and %.3f dt\n", total,dt);

	float numOfStamps = total/dt;
	struct timeval tv[(int)numOfStamps+1];
	double values[(int)numOfStamps+1];

	signal(SIGALRM,sigCatcher);
	alarm(total);
	
	gettimeofday(&tv[0],NULL);
	values[0] = (double)tv[0].tv_sec+((double)tv[0].tv_usec)/1000000;
	printf("%f\t\t\t%d\n",values[0],1);
	sleep((int)dt);
	usleep((dt-(int)dt)*1000000);
	int i=2;
	while(flag==0)
	{
		gettimeofday(&tv[i-1],NULL);
		values[i-1] = (double)tv[i-1].tv_sec+((double)tv[i-1].tv_usec)/1000000;
		printf("%f\t\t\t%d\n",values[i-1],i);
		average+=values[i-1]-values[i-2]-dt;
		wait = dt-average/(i-1);
		sleep((int)wait);
		usleep((wait-(int)wait)*1000000);
		i++;
	}
	
	gettimeofday(&tv[i-1],NULL);
	values[i-1] = (double)tv[i-1].tv_sec+((double)tv[i-1].tv_usec)/1000000;
	printf("\n*****************\nFinished sampling\n*****************\n\n");

//---------------File Handling---------------
	char c;
	printf("Would you like to store the data?(y/n) ");
	scanf(" %c",&c);
	if(c=='y')
	{
	FILE *fp;
	fp = fopen("data2.txt","w");
	
	for(int j=0;j<i-1;j++)
	{
		fprintf(fp, "%f\n",values[j]);
	}
	fclose(fp);
	}
//-------------------------------------------
	double offset = 0;
	for(int j=1;j<i-1;j++)
	{
		offset+=values[j]-values[j-1]-dt;
	}
//---------------Print Results---------------
	double timelapsed = values[i-1] - values[0];
	printf("Time lapsed: %f \n",timelapsed);
	printf("Number of points: %d\n",i-1);
	printf("Offset: %f \n",offset);
	return 0;
}