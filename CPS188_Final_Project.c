#include <stdio.h>
#define SIZE 366
#define SIZE1 365
#include <stdlib.h>
#include <string.h>
#define MaxLine 5000

typedef struct data
{
    int year;
    int day;
    float data[6];
}DATA;

void read_txt(char *file, DATA *data)
{
     char buf[MaxLine];
     int len, col, n=0;
     char *str;

     FILE *fp;
     fp=fopen(file, "r");

     if(fp==NULL)
     {
         perror("fail to read");
         exit(1);
     }

     while(fgets(buf, MaxLine, fp)!=NULL)
     {
         len = strlen(buf);
         buf[len-1] = '\0';
         str = strtok(buf, " ");
         col = 0;
         while(str!= NULL )
         {
             if(col==0)
             {
                 data[n].year = atoi(str);
                 str = strtok(NULL, " ");
             }
             else if(col==1)
             {
                 data[n].day = atoi(str);
                 str = strtok(NULL, " ");
             }
             else
             {
                 data[n].data[col-2] = atof(str);
                 str = strtok(NULL, " ");
             }
             col++;
         }
         n++;
     }
}

void datechange(int year, int day1)
{
    int sum=0;
    int month;
    int day2;

    int month1[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((year%4==0&&year%100!=0)||(year%400==0)){
        month1[1]=29;
    }
    else
    {
        month1[1]=28;
    }

    for(int i=0; i<12; i++)
    {
        if(day1>sum&&day1<=sum+month1[i])
        {
            month = i+1;
            day2 = day1-sum;
            break;
        }
        sum = sum+month1[i];
    }
    printf("%02d/%02d", day2, month);
}

void findmaximum(DATA *Data, int l)
{
    float maximum=0;

    for(int i=0; i<MaxLine; i++)
    {
        if(Data[i].year==2020&&Data[i].data[l]>maximum)
            maximum = Data[i].data[l];
    }
    for(int i=0; i<MaxLine; i++)
    {
        if(Data[i].year==2020&&Data[i].data[l]==maximum)
        {
            datechange(Data[i].year, Data[i].day);
            printf("\t");
            for(int j=0; j<6; j++)
            {
                if(j==l)
                    printf("%.2f\t", Data[i].data[j]);
            }
            printf("\n");
        }
    }
}

void findminimum(DATA *Data, int q)
{
    float minimum=100;

    for(int i=0;i<MaxLine;i++)
    {
        if(Data[i].year==2020&&Data[i].data[q]<minimum)
            minimum=Data[i].data[q];
    }
    for(int i=0;i<MaxLine;i++)
    {
        if(Data[i].year==2020&&Data[i].data[q]==minimum)
        {
            datechange(Data[i].year,Data[i].day);
            printf("\t");
            for(int j=0;j<6;j++)
            {
                if(j==q)
                    printf("%.2f\t",Data[i].data[j]);
            }
            printf("\n");
        }
    }
}

void findtotalmaxprint(DATA *Data, char header[][1000])
{
    int i, j;
    float max=0;

    for(i=0; i<MaxLine; i++)
    {
        for(j=0; j<6; j++)
        {
            if(Data[i].year==2020&&Data[i].data[j]>max)
            {
                max = Data[i].data[j];
            }
        }
    }

    for(i=0; i<MaxLine; i++)
    {
        for(j=0; j<6; j++)
        {
            if(Data[i].year==2020&&Data[i].data[j]==max)
            {
                printf("%s\t", header[j]);
                datechange(Data[i].year, Data[i].day);
                printf("\t");
                printf("%.2f\n", Data[i].data[j]);
            }
        }
    }
}

void findtotalminprint(DATA *Data, char header[][1000])
{
    int i, j;
    float min=100;

    for(i=0; i<MaxLine; i++)
    {
        for(j=0; j<6; j++)
        {
            if(Data[i].year==2020&&Data[i].data[j]<min)
            {
                min = Data[i].data[j];
            }
        }
    }

    for(i=0; i<MaxLine; i++)
    {
        for(j=0; j<6; j++)
        {
            if(Data[i].year==2020&&Data[i].data[j]==min)
            {
                printf("%s\t", header[j]);
                datechange(Data[i].year, Data[i].day);
                printf("\t");
                printf("%.2f\n", Data[i].data[j]);
            }
        }
    }
}



int main()
{
	int i,j,count0=0,count1=0,count2=0,count3=0,count4=0,count5=0;
	int fcount0=0,fcount1=0,fcount2=0,fcount3=0,fcount4=0,fcount5=0;
	double array[5000],temp,sumSup,sumMich,sumHuron,sumErie,sumOnt,sumClr,Avg;
	double summerSup,summerMich,summerHuron,summerErie,summerOnt,summerClr;
	double winterSup,winterMich,winterHuron,winterErie,winterOnt,winterClr;
	int x,z;
	double array1[5000],temp1,sumSup1,sumMich1,sumHuron1,sumErie1,sumOnt1,sumClr1;
	
	FILE *in;
	in =fopen("TermProject.txt","r");
	
	for(j=0;j<SIZE;j++)
	{
		for(i=0;i<8;i++)
		{
		
			fscanf(in," %lf",&temp);
			array[i]=temp;	
		}
		
	/*Question 1*/
	sumSup=sumSup+array[2];
	sumMich=sumMich+array[3];
	sumHuron=sumHuron+array[4];
	sumErie=sumErie+array[5];
	sumOnt=sumOnt+array[6];
	sumClr=sumClr+array[7];
		
		
	/*Question 5*/
	if(array[1]>=172 && array[1]<=265)
		{
			summerSup=summerSup + array[2];
			summerMich=summerMich + array[3];
			summerHuron=summerHuron + array[4];
			summerErie=summerErie + array[5];
			summerOnt=summerOnt + array[6];
			summerClr=summerClr + array[7];
		}
		
	/*Question 6*/
	if(array[1]>=1 && array[1]<=79)
		{
			winterSup=winterSup + array[2];
			winterMich=winterMich + array[3];
			winterHuron=winterHuron + array[4];
			winterErie=winterErie + array[5];
			winterOnt=winterOnt + array[6];
			winterClr=winterClr + array[7];
		}
	if(array[1]>=355 && array[1]<=366)
		{
			winterSup=winterSup + array[2];
			winterMich=winterMich + array[3];
			winterHuron=winterHuron + array[4];
			winterErie=winterErie + array[5];
			winterOnt=winterOnt + array[6];
			winterClr=winterClr + array[7];
		}
		
		
	/*Question 7*/
	if(array[2]>20)
		count0=count0 +1;
	if(array[3]>20)
		count1=count1 +1;
	if(array[4]>20)
		count2=count2 +1;
	if(array[5]>20)
		count3=count3 +1;
	if(array[6]>20)
		count4=count4 +1;
	if(array[7]>20)
		count5=count5 +1;
		
		/*Question 8*/
	if(array[2]<0)
		fcount0=fcount0 +1;
	if(array[3]<0)
		fcount1=fcount1 +1;
	if(array[4]<0)
		fcount2=fcount2 +1;
	if(array[5]<0)
		fcount3=fcount3 +1;
	if(array[6]<0)
		fcount4=fcount4 +1;
	if(array[7]<0)
		fcount5=fcount5 +1;		
	}
	
	FILE *file;
	file =fopen("TermProject2019_data.txt","r");

	for(z=0;z<SIZE1;z++)
	{
		for(x=0;x<8;x++)
		{
		
			fscanf(file," %lf",&temp1);
			array1[x]=temp1;
			
		}
		sumSup1=sumSup1+array1[2];
		sumMich1=sumMich1+array1[3];
		sumHuron1=sumHuron1+array1[4];
		sumErie1=sumErie1+array1[5];
		sumOnt1=sumOnt1+array1[6];
		sumClr1=sumClr1+array1[7];
	}
	
	
	double FsumSup=sumSup/366,FsumMich=sumMich/366,FsumHuron=sumHuron/366;
	double FsumErie=sumErie/366,FsumOnt=sumOnt/366,FsumClr=sumClr/366;
	printf("Question 1: \n");
	printf("The average temperature for Lake Superior is: %.2lf%cC \n",FsumSup, 248);
	printf("The average temperature for Lake Michigan is: %.2lf%cC \n",FsumMich, 248);
	printf("The average temperature for Lake Huron is: %.2lf%cC \n",FsumHuron, 248);
	printf("The average temperature for Lake Erie is: %.2lf%cC \n",FsumErie, 248);
	printf("The average temperature for Lake Ontario is: %.2lf%cC \n",FsumOnt, 248);
	printf("The average temperature for Lake St. Clair is: %.2lf%cC \n",FsumClr, 248);
	
	Avg = (FsumSup+FsumMich+FsumHuron+FsumErie+FsumOnt+FsumClr)/6;
	printf("The average temperature for all the lakes is: %.2lf%cC \n",Avg, 248);
	
	printf("\nQuestion 2: \n");
	if (FsumSup>FsumMich && FsumSup>FsumHuron && FsumSup>FsumErie && FsumSup>FsumOnt && FsumSup>FsumClr)
		printf("The warmest lake is Lake Superior.\n");
	if (FsumSup<FsumMich && FsumSup<FsumHuron && FsumSup<FsumErie && FsumSup<FsumOnt && FsumSup<FsumClr)
		printf("The coldest lake is Lake Superior.\n");
		
	if (FsumMich>FsumSup && FsumMich>FsumHuron && FsumMich>FsumErie && FsumMich>FsumOnt && FsumMich>FsumClr)
		printf("The warmest lake is Lake Michigan.\n");
	if (FsumMich<FsumSup && FsumMich<FsumHuron && FsumMich<FsumErie && FsumMich<FsumOnt && FsumMich<FsumClr)
		printf("The coldest lake is Lake Michigan.\n");
		
	if (FsumHuron>FsumSup && FsumHuron>FsumMich && FsumHuron>FsumErie && FsumHuron>FsumOnt && FsumHuron>FsumClr)
		printf("The warmest lake is Lake Huron.\n");
	if (FsumHuron<FsumMich && FsumHuron<FsumSup && FsumHuron<FsumErie && FsumHuron<FsumOnt && FsumHuron<FsumClr)
		printf("The coldest lake is Lake Huron.\n");
		
	if (FsumErie>FsumSup && FsumErie>FsumMich && FsumErie>FsumHuron && FsumErie>FsumOnt && FsumErie>FsumClr)
		printf("The warmest lake is Lake Erie.\n");
	if (FsumSup<FsumSup && FsumErie<FsumMich && FsumErie<FsumHuron && FsumErie<FsumOnt && FsumErie<FsumClr)
		printf("The coldest lake is Lake Erie.\n");
		
	if (FsumOnt>FsumSup && FsumOnt>FsumMich && FsumOnt>FsumHuron && FsumOnt>FsumErie && FsumOnt>FsumClr)
		printf("The warmest lake is Lake Ontario.\n");
	if (FsumOnt<FsumSup && FsumOnt<FsumMich && FsumOnt<FsumHuron && FsumOnt<FsumErie && FsumOnt<FsumClr)
		printf("The coldest lake is Lake Ontario.\n");	
	
	if (FsumClr>FsumSup && FsumClr>FsumMich && FsumClr>FsumHuron && FsumClr>FsumErie && FsumClr>FsumOnt)
		printf("The warmest lake is Lake St. Clair.\n");
	if (FsumClr<FsumSup && FsumClr<FsumMich && FsumClr<FsumHuron && FsumClr<FsumErie && FsumClr<FsumOnt)
		printf("The coldest lake is Lake St. Clair.\n");
		
	
	printf("\n");
	if (FsumSup<Avg)
    		printf("Lake Superior is below the average temperature.\n");
    if (FsumSup>Avg)
    		printf("Lake Superior is above the average temperature.\n");

    if (FsumMich<Avg)
   		printf("Lake Michigun is below the average temperature.\n");
    if (FsumMich>Avg)
   		printf("Lake Michigun is above the average temperature.\n");

    if (FsumHuron<Avg)
   		printf("Lake Huron is below the average temperature.\n");
    if (FsumHuron>Avg)
   		printf("Lake Huron is above the average temperature.\n");

    if (FsumErie<Avg)
   		printf("Lake Erie is below the average temperature.\n");
    if (FsumErie>Avg)
  		printf("Lake Erie is above the average temperature.\n");

    if (FsumOnt<Avg)
    		printf("Lake Ontario is below the average temperature.\n");
    if (FsumOnt>Avg)
    		printf("Lake Ontario is above the average temperature.\n");

    if (FsumClr<Avg)
    		printf("Lake St. Clair is below the average temperature.\n");
    if (FsumClr>Avg)
    		printf("Lake St. Clair is above the average temperature.\n");
    		
    printf("\n");
    		
    printf("Question 3: \n");
    DATA Data[MaxLine];
    
    char header[6][1000] = {"Lake Superior: ", "Lake Michigan: ", "Lake Huron: ", "Lake Erie: ", "Lake Ontario: ", "Lake St.Clair: "};
    
    read_txt("TermProject.txt", Data);

    printf("Warmest temperature\n\n");
    for(int i=0; i<6; i++)
    {
        printf(header[i]);
        findmaximum(Data, i);
    }
	printf("\n");
    printf("Coldest temperature\n\n");
    for(int i=0; i<6; i++)
    {
        printf(header[i]);
        printf("\n");
        findminimum(Data, i);
		printf("\n");
    }
    
    
    printf("\nQuestion 4:  \n");
    printf("All lakes Warmest temperature\n");
    findtotalmaxprint(Data, header);
    printf("\n");

    printf("All lakes Coldest temperature\n");
    findtotalminprint(Data, header);
    printf("\n");
	


	printf("\nQuestion 5: \n");
	printf("The average summer temperature for Lake Superior is: %.2lf%cC \n",summerSup/94, 248);
	printf("The average summer temperature for Lake Huron is: %.2lf%cC \n",summerHuron/94, 248);
	printf("The average summer temperature for Lake Michigan is: %.2lf%cC \n",summerMich/94, 248);
	printf("The average summer temperature for Lake Ontario is: %.2lf%cC \n",summerOnt/94, 248);
	printf("The average summer temperature for Lake St.Clair is: %.2lf%cC \n",summerClr/94, 248);
	printf("The average summer temperature for Lake Erie is: %.2lf%cC \n",summerErie/94, 248);

	printf("\nQuestion 6: \n");
	printf("The average winter temperature for Lake St.Clair is: %.2lf%cC \n",winterClr/91, 248);
	printf("The average winter temperature for Lake Superior is: %.2lf%cC \n",winterSup/91, 248);
	printf("The average winter temperature for Lake Huron is: %.2lf%cC \n",winterHuron/91, 248);
	printf("The average winter temperature for Lake Erie is: %.2lf%cC \n",winterErie/91, 248);
	printf("The average winter temperature for Lake Michigan is: %.2lf%cC \n",winterMich/91, 248);
	printf("The average winter temperature for Lake Ontario is: %.2lf%cC \n",winterOnt/91, 248);
	
	printf("\nQuestion 7: \n");
	printf("You can swim in Lake Superior for: %d days.\n",count0);
	printf("You can swim in Lake Michigan for: %d days.\n",count1);
	printf("You can swim in Lake Huron for: %d days.\n",count2);
	printf("You can swim in Lake Erie for: %d days.\n",count3);
	printf("You can swim in Lake Ontario for: %d days.\n",count4);
	printf("You can swim in Lake St.Clair for: %d days.\n",count5);

	printf("\nQuestion 8: \n");
	printf("Lake Superior is frozen for: %d days.\n",fcount0);
	printf("Lake Michigan is frozen for: %d days.\n",fcount1);
	printf("Lake Huron is frozen for: %d days.\n",fcount2);
	printf("Lake Erie is frozen for: %d days.\n",fcount3);
	printf("Lake Ontario is frozen for: %d days.\n",fcount4);
	printf("Lake St.Clair is frozen for: %d days.\n",fcount5);
	
	double FsumSup1=sumSup1/365,FsumMich1=sumMich1/365,FsumHuron1=sumHuron1/365;
	double FsumErie1=sumErie1/365,FsumOnt1=sumOnt1/365,FsumClr1=sumClr1/365;
	double Avg1;
	Avg1 = (FsumSup1+FsumMich1+FsumHuron1+FsumErie1+FsumOnt1+FsumClr1)/6;
	printf("\nQuestion 9: \n");
	printf("      		2019 Average Temperatures:	       2020 Average Temperatures: \n");
	printf("Lake Superior:            %.2lf%cC			  	  %.2lf%cC\n", FsumSup1, 248, FsumSup, 248);
	printf("Lake Michigun:            %.2lf%cC				  %.2lf%cC\n", FsumMich1, 248, FsumMich, 248);
	printf("Lake Huron:               %.2lf%cC				  %.2lf%cC\n", FsumHuron1, 248, FsumHuron, 248);
	printf("Lake Erie:                %.2lf%cC				  %.2lf%cC\n", FsumErie1, 248, FsumErie, 248);
	printf("Lake Ontario:             %.2lf%cC				  %.2lf%cC\n", FsumOnt1, 248, FsumOnt, 248);
	printf("Lake St. Clair:           %.2lf%cC				  %.2lf%cC\n", FsumClr1, 248, FsumClr, 248);
	printf("Average of lakes:          %.2lf%cC                                 %.2lf%cC\n", Avg1, 248, Avg, 248);



	printf("\n");
	
	printf("If we compare the average temperatures of each lake between the year of 2019 and 2020,\n"
	"we can observe that average temperatures for 2020 are higher. According to NASA, the average global\n"
	"temperature of the Earth has increased by at least 1.1%cC since 1880, with the majority of this increase\n"
	"occurring within the past 50 years. This is due to the increased production of greenhouse gasses around\n"
	"the world, trapping the heat produced by the Sun within the atmosphere which is slowly increasing the\n" 
	"temperature of the Earth. This is why we see the temperature increase in the lakes going from 2019 to 2020.\n", 248);

	printf("\n\n");

    return 0;
}
