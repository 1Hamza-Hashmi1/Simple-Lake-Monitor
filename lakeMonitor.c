#include <stdio.h>
#include <string.h>

//calculates the average of a given lake, where 2,3,4,5,6,7 correspond to lakes Sup. Mich. Huron Erie Ont. St.Clr respectively
double lakeAvg(int lakeNum, double data[366][8])
{
    double total=0;
    double avg;

    for(int i=0; i<366; i++)				//goes through entire array
        total = total + data[i][lakeNum];	//calculates the sums of all the values in the array for specified column

    avg = total/366;						//calculates the average of all the values in the array for specified column
    return(avg);
}

//calculates the avrage of all the 6 lakes
double avgTotal(double data[366][8])
{
    double total=0;
    double average;

    for(int i=0; i<366; i++)				//goes through each row
        for(int j=2; j<8; j++)				//goes through each column
            total = total + data[i][j];		//calculates the average of all the values in the array 

    average = total/(366*6);
    return(average);
}

//finds the coldest lake in the array based on lowest average water tempreature
double findColdest(double avgTemp[], char coldestLake[])
{
	double coldest = 10;
	int coldestNum=0;
	
	for(int i=0; i<6; i++)
	{
		if(avgTemp[i] < coldest)
		{
			coldest = avgTemp[i];
			coldestNum = i+2;
		}
	}
	
	//compares each of the lakes to each other to find coldest lake
	if(coldestNum==2)
		strcpy(coldestLake, "Superior");
	if(coldestNum==3)
		strcpy(coldestLake, "Michigan");
	if(coldestNum==4)
		strcpy(coldestLake, "Huron");
	if(coldestNum==5)
		strcpy(coldestLake, "Erie");
	if(coldestNum==6)
		strcpy(coldestLake, "Ontario");
	if(coldestNum==7)
		strcpy(coldestLake, "St. Clair");
	
	return(coldest);
}

//finds the warmest lake in the array based on highest average water tempreature
double findWarmest(double avgTemp[], char warmestLake[])
{
	double warmest = 10;
	int warmestNum=0;
	
	for(int i=0; i<6; i++)
	{
		if(avgTemp[i] > warmest)
		{
			warmest = avgTemp[i];
			warmestNum = i+2;
		}
	}
	
	//compares each of the lakes to each other to find warmest lake
	if(warmestNum==2)
		strcpy(warmestLake, "Superior");
	if(warmestNum==3)
		strcpy(warmestLake, "Michigan");
	if(warmestNum==4)
		strcpy(warmestLake, "Huron");
	if(warmestNum==5)
		strcpy(warmestLake, "Erie");
	if(warmestNum==6)
		strcpy(warmestLake, "Ontario");
	if(warmestNum==7)
		strcpy(warmestLake, "St. Clair");
	
	return(warmest);
}

//takes day number and converts it to a month/day format
void convertDate(int day)
{
	int month = day / 30;
	int date;
	date = day - month*30;
	
	printf("\nMonth: %d, Day: %d.", month, date);
}

//calculate the summer average (day 172 to day 265) for all specified lake
double sumAvg(int lakeNum, double data[366][8])
{
	double total=0;
    double avg;

    for(int i=172; i<265; i++)				//calculates the sum of the temp from day 172 to day 265
        total = total + data[i][lakeNum];

    avg = total/(265-172);
    return(avg);
}

//calculate the winter average (days 1 to 79 and days 355 to 366) for specified lake
double winAvg(int lakeNum, double data[366][8])
{
	double total=0;
    double avg;

    for(int i=1; i<79; i++)					//calculates the sum of the temp from day 1 to day 79
        total = total + data[i][lakeNum];
    for(int i=355; i<366; i++)
        total = total + data[i][lakeNum];	//calculates the sum of the temp from day 355 to day 356

    avg = total/((79-1)+(366-355));
    return(avg);
}

//calculates the number of days in the year you can swim for each of the specified lake
double swimmingTemp(int lakeNum, double data[366][8])
{
    double totalDays=0;

    for(int i=0; i<366; i++)			//goes through entire array
    {
		if(data[i][lakeNum] >= 20)		//compares the temp in array to 20Â°
			totalDays = totalDays + 1;
	}

    return(totalDays);
}

//calculates the number of days in the year that the lake is frozen for each of the 6 lakes
double frozenTemp(int lakeNum, double data[366][8])
{
    double totalDays=0;

    for(int i=0; i<366; i++)			//goes through entire array
    {
		if(data[i][lakeNum] <= 0)		//compares the temp in array to 0Â°
			totalDays = totalDays + 1;
	}

    return(totalDays);
}

//calculates the average of a given lake, where 2,3,4,5,6,7 correspond to lakes Sup. Mich. Huron Erie Ont. St.Clr respectively in 2019
double lakeAvg2(int lakeNum, double data[365][8])
{
    double total=0;
    double avg;

    for(int i=0; i<365; i++)					//goes through entire array
        total = total + data[i][lakeNum];		//calculates the sums of all the values in the array for specified column

    avg = total/365;							//calculates the average of all the values in the array for specified column
    return(avg);
}

//calculates the avrage of all the 6 lakes
double avgTotal2(double data[365][8])
{
    double total=0;
    double average;

    for(int i=0; i<365; i++)					//goes through each row
        for(int j=2; j<8; j++)					//goes through each column
            total = total + data[i][j];			//calculates the average of all the values in the array for specified column

    average = total/(365*6);
    return(average);
}

int
main(void)
{
    //opening the file
    FILE * input;
    input = fopen("cpsData.txt", "r");

    //array declaration
    double data[366][8];

    //getting data from the file and storing into a 2D array
    for(int i=0; i<366; i++)
        for(int j=0; j<8; j++)
            fscanf(input, "%lf", &data[i][j]);
    
    //q1---------------------------------------------------------------
    //calculates the average tempreture of each lake
    double avgSup = lakeAvg(2, data);
    double avgMich = lakeAvg(3, data);
    double avgHuron = lakeAvg(4, data);
    double avgErie = lakeAvg(5, data);
    double avgOnt = lakeAvg(6, data);
    double avgStC = lakeAvg(7, data);
    double allAvg = avgTotal(data);

	printf("------Question 1------\n");
	
	//displays the average tempreture of each lake
    printf("Average temp for lake Sup is: %lf\n", avgSup);
    printf("Average temp for lake Mich is: %lf\n", avgMich);
    printf("Average temp for lake Huron is: %lf\n", avgHuron);
    printf("Average temp for lake Erie is: %lf\n", avgErie);
    printf("Average temp for lake Ont is: %lf\n", avgOnt);
    printf("Average temp for lake StC is: %lf\n", avgStC);
    printf("Average temp for all lakes is: %lf\n", allAvg);
    
    //q2---------------------------------------------------------------
    printf("\n------Question 2------");
    //varaible decleration
    char coldestLake[10];
    double coldestAvg;
    char warmestLake[10];
    double warmestAvg;
    double avgTemp[] = {avgSup, avgMich, avgHuron, avgErie, avgOnt, avgStC};
    
    //find the lake with the coldest and warmest temp
	coldestAvg = findColdest(avgTemp, coldestLake);
	warmestAvg = findWarmest(avgTemp, warmestLake);
	
	//displays the lake with the coldest and warmest temp
	printf("\nThe coldest average temurature is %.2lf degrees C at Lake %s.", coldestAvg, coldestLake);
	printf("\nThe warmest average temurature is %.2lf degrees C at Lake %s.\n", warmestAvg, warmestLake);
	
	//displays which lakes have average temperatures above the average of all the lakes and which ones are below that same average
	if(avgSup > allAvg)
		printf("\nLake Superior has an average temperature above the average of all the lakes");
	else
		printf("\nLake Superior has an average temperature below the average of all the lakes");
	if(avgMich > allAvg)
		printf("\nLake Michigan has an average temperature above the average of all the lakes");
	else
		printf("\nLake Michigan has an average temperature below the average of all the lakes");
	if(avgHuron > allAvg)
		printf("\nLake Huron has an average temperature above the average of all the lakes");
	else
		printf("\nLake Huron has an average temperature below the average of all the lakes");
	if(avgErie > allAvg)
		printf("\nLake Erie has an average temperature above the average of all the lakes");
	else
		printf("\nLake Erie has an average temperature below the average of all the lakes");
	if(avgOnt > allAvg)
		printf("\nLake Ontario has an average temperature above the average of all the lakes");
	else
		printf("\nLake Ontario has an average temperature below the average of all the lakes");
	if(avgStC > allAvg)
		printf("\nLake St. Clair has an average temperature above the average of all the lakes\n");
	else
		printf("\nLake St. Clair has an average temperature below the average of all the lakes\n");
    
    //q3---------------------------------------------------------------
    printf("\n------Question 3------");
    //varaible decleration
    double coldestTemp;
	int coldestDay;
	double warmestTemp;
	int warmestDay;
    
    //Finding the coldest day for all the lakes
    coldestTemp = 20;
	for(int i=0; i<366; i++) //finding coldest for lake michigan
	{
		if(data[i][3] < coldestTemp)
		{
			coldestTemp = data[i][3];
			coldestDay = i;
		}
	}
	printf("\nThe coldest temperature for Lake Michigan is %lf degrees.", coldestTemp);
	convertDate(coldestDay);
	
	coldestTemp = 20;
	for(int i=0; i<366; i++) //finding coldest for lake Huron
	{
		if(data[i][4] < coldestTemp)
		{
			coldestTemp = data[i][4];
			coldestDay = i;
		}
	}
	printf("\nThe coldest temperature for Lake Huron is %lf degrees.", coldestTemp);
	convertDate(coldestDay);
	
	coldestTemp = 20;
	for(int i=0; i<366; i++) //finding coldest for lake Erie
	{
		if(data[i][5] < coldestTemp)
		{
			coldestTemp = data[i][5];
			coldestDay = i;
		}
	}
	printf("\nThe coldest temperature for Lake Erie is %lf degrees.", coldestTemp);
	convertDate(coldestDay);
	
	coldestTemp = 20;
	for(int i=0; i<366; i++) //finding coldest for lake Ontario
	{
		if(data[i][6] < coldestTemp)
		{
			coldestTemp = data[i][6];
			coldestDay = i;
		}
	}
	printf("\nThe coldest temperature for Lake Ontario is %lf degrees.", coldestTemp);
	convertDate(coldestDay);
	
	coldestTemp = 20;
	for(int i=0; i<366; i++) //finding coldest for lake St. Clair
	{
		if(data[i][7] < coldestTemp)
		{
			coldestTemp = data[i][7];
			coldestDay = i;
		}
	}
	printf("\nThe coldest temperature for Lake St. Clair is %lf degrees.", coldestTemp);
	convertDate(coldestDay);
	
	//Finding the warmest day for all the lakes
	warmestTemp = 15;
	for(int i=0; i<366; i++) //finding warmest for lake Superior
	{
		if(data[i][2] > warmestTemp)
		{
			warmestTemp = data[i][2];
			warmestDay = i;
		}
	}
	printf("\n\nThe warmest temperature for Lake Superior is %lf degrees.", warmestTemp);
	convertDate(warmestDay);
	
	warmestTemp = 15;
	for(int i=0; i<366; i++) //finding warmest for lake Michigan
	{
		if(data[i][3] > warmestTemp)
		{
			warmestTemp = data[i][3];
			warmestDay = i;
		}
	}
	printf("\nThe warmest temperature for Lake Michigan is %lf degrees.", warmestTemp);
	convertDate(warmestDay);
	
	warmestTemp = 15;
	for(int i=0; i<366; i++) //finding warmest for lake Huron
	{
		if(data[i][4] > warmestTemp)
		{
			warmestTemp = data[i][4];
			warmestDay = i;
		}
	}
	printf("\nThe warmest temperature for Lake Huron is %lf degrees.", warmestTemp);
	convertDate(warmestDay);
	
	warmestTemp = 15;
	for(int i=0; i<366; i++) //finding warmest for lake Erie
	{
		if(data[i][5] > warmestTemp)
		{
			warmestTemp = data[i][5];
			warmestDay = i;
		}
	}
	printf("\nThe warmest temperature for Lake Erie is %lf degrees.", warmestTemp);
	convertDate(warmestDay);
	
	warmestTemp = 15;
	for(int i=0; i<366; i++) //finding warmest for lake Ontario
	{
		if(data[i][6] > warmestTemp)
		{
			warmestTemp = data[i][6];
			warmestDay = i;
		}
	}
	printf("\nThe warmest temperature for Lake Ontario is %lf degrees.", warmestTemp);
	convertDate(warmestDay);
	
	warmestTemp = 15;
	for(int i=0; i<366; i++) //finding warmest for lake St. Clair
	{
		if(data[i][7] > warmestTemp)
		{
			warmestTemp = data[i][7];
			warmestDay = i;
		}
	}
	printf("\nThe warmest temperature for Lake St. Clair is %lf degrees.", warmestTemp);
	convertDate(warmestDay);
    
    //q4---------------------------------------------------------------
    printf("\n");
    printf("\n------Question 4------");
    //Finding the overall coldest day
	coldestTemp = 20;
	for(int i=0; i<366; i++)
	{
		for(int j=2; j<8; j++)
		{
			if(data[i][j] < coldestTemp)
			{
				coldestTemp = data[i][j];
				coldestDay = i;
			}
		}
	}
	printf("\nThe coldest temperature overall is %lf degrees.", coldestTemp);
	convertDate(coldestDay);
	
	//Finding the overall warmest day
	warmestTemp = 15;
	for(int i=0; i<366; i++)
	{
		for(int j=2; j<8; j++)
		{
			if(data[i][j] > warmestTemp)
			{
				warmestTemp = data[i][j];
				warmestDay = i;
			}
		}
	}
	printf("\nThe warmest temperature overall is %lf degrees.", warmestTemp);
	convertDate(warmestDay);
	
    //q5---------------------------------------------------------------
    printf("\n");
    printf("\n------Question 5------");
    //calculate the summer average (day 172 to day 265) for all 6 lakes
    double sumAvgSup = sumAvg(2, data);
    double sumAvgMich = sumAvg(3, data);
    double sumAvgHuron = sumAvg(4, data);
    double sumAvgErie = sumAvg(5, data);
    double sumAvgOnt = sumAvg(6, data);
    double sumAvgStC = sumAvg(7, data);
    
    //displays the summer average (day 172 to day 265) for all 6 lakes
    printf("\nAverage summer temp for lake Sup is: %lf\n", sumAvgSup);
    printf("Average summer temp for lake Mich is: %lf\n", sumAvgMich);
    printf("Average summer temp for lake Huron is: %lf\n", sumAvgHuron);
    printf("Average summer temp for lake Erie is: %lf\n", sumAvgErie);
    printf("Average summer temp for lake Ont is: %lf\n", sumAvgOnt);
    printf("Average summer temp for lake StC is: %lf\n", sumAvgStC);
    printf("\n");
    
    //displays the temp of the lakes in order from warmest to coldest 
    double lowestTemp = 0;
    if(sumAvgSup >= lowestTemp)
		lowestTemp = sumAvgSup;	
	if(sumAvgMich >= lowestTemp)
		lowestTemp = sumAvgMich;	
	if(sumAvgHuron >= lowestTemp)
		lowestTemp = sumAvgHuron;			
	if(sumAvgErie >= lowestTemp)
		lowestTemp = sumAvgErie;				
	if(sumAvgOnt >= lowestTemp)
		lowestTemp = sumAvgOnt;					
	if(sumAvgStC >= lowestTemp)
		lowestTemp = sumAvgStC;		
	printf ("The 1st warmest Summer Temp is: %lf \n", lowestTemp); 
	
	double lowestTemp2 = 0;
    if(sumAvgSup >= lowestTemp2 && sumAvgSup < lowestTemp)
		lowestTemp2 = sumAvgSup;	
	if(sumAvgMich >= lowestTemp2 && sumAvgMich < lowestTemp)
		lowestTemp2 = sumAvgMich;	
	if(sumAvgHuron >= lowestTemp2 && sumAvgHuron < lowestTemp)
		lowestTemp2 = sumAvgHuron;			
	if(sumAvgErie >= lowestTemp2 && sumAvgErie < lowestTemp)
		lowestTemp2 = sumAvgErie;				
	if(sumAvgOnt >= lowestTemp2 && sumAvgOnt < lowestTemp)
		lowestTemp2 = sumAvgOnt;					
	if(sumAvgStC >= lowestTemp2 && sumAvgStC < lowestTemp)
		lowestTemp2 = sumAvgStC;
	printf ("The 2nd warmest Summer Temp is: %lf \n", lowestTemp2);
	
	double lowestTemp3 = 0;
    if(sumAvgSup >= lowestTemp3 && sumAvgSup < lowestTemp2)
		lowestTemp3 = sumAvgSup;	
	if(sumAvgMich >= lowestTemp3 && sumAvgMich < lowestTemp2)
		lowestTemp3 = sumAvgMich;	
	if(sumAvgHuron >= lowestTemp3 && sumAvgHuron < lowestTemp2)
		lowestTemp3 = sumAvgHuron;			
	if(sumAvgErie >= lowestTemp3 && sumAvgErie < lowestTemp2)
		lowestTemp3 = sumAvgErie;				
	if(sumAvgOnt >= lowestTemp3 && sumAvgOnt < lowestTemp2)
		lowestTemp3 = sumAvgOnt;					
	if(sumAvgStC >= lowestTemp3 && sumAvgStC < lowestTemp2)
		lowestTemp3 = sumAvgStC;
	printf ("The 3rd warmest Summer Temp is: %lf \n", lowestTemp3);	
	
	double lowestTemp4 = 0;
    if(sumAvgSup >= lowestTemp4 && sumAvgSup < lowestTemp3)
		lowestTemp4 = sumAvgSup;	
	if(sumAvgMich >= lowestTemp4 && sumAvgMich < lowestTemp3)
		lowestTemp4 = sumAvgMich;	
	if(sumAvgHuron >= lowestTemp4 && sumAvgHuron < lowestTemp3)
		lowestTemp4 = sumAvgHuron;			
	if(sumAvgErie >= lowestTemp4 && sumAvgErie < lowestTemp3)
		lowestTemp4 = sumAvgErie;				
	if(sumAvgOnt >= lowestTemp4 && sumAvgOnt < lowestTemp3)
		lowestTemp4 = sumAvgOnt;					
	if(sumAvgStC >= lowestTemp4 && sumAvgStC < lowestTemp3)
		lowestTemp4 = sumAvgStC;
	printf ("The 4th warmest Summer Temp is: %lf \n", lowestTemp4);
	
	double lowestTemp5 = 0;
    if(sumAvgSup >= lowestTemp5 && sumAvgSup < lowestTemp4)
		lowestTemp5 = sumAvgSup;	
	if(sumAvgMich >= lowestTemp5 && sumAvgMich < lowestTemp4)
		lowestTemp5 = sumAvgMich;	
	if(sumAvgHuron >= lowestTemp5 && sumAvgHuron < lowestTemp4)
		lowestTemp5 = sumAvgHuron;			
	if(sumAvgErie >= lowestTemp5 && sumAvgErie < lowestTemp4)
		lowestTemp5 = sumAvgErie;				
	if(sumAvgOnt >= lowestTemp5 && sumAvgOnt < lowestTemp4)
		lowestTemp5 = sumAvgOnt;					
	if(sumAvgStC >= lowestTemp5 && sumAvgStC < lowestTemp4)
		lowestTemp5 = sumAvgStC;
	printf ("The 5th warmest Summer Temp is: %lf \n", lowestTemp5);				
   
   double lowestTemp6 = 0;
    if(sumAvgSup >= lowestTemp6 && sumAvgSup < lowestTemp5)
		lowestTemp6 = sumAvgSup;	
	if(sumAvgMich >= lowestTemp6 && sumAvgMich < lowestTemp5)
		lowestTemp6 = sumAvgMich;	
	if(sumAvgHuron >= lowestTemp6 && sumAvgHuron < lowestTemp5)
		lowestTemp6 = sumAvgHuron;			
	if(sumAvgErie >= lowestTemp6 && sumAvgErie < lowestTemp5)
		lowestTemp6 = sumAvgErie;				
	if(sumAvgOnt >= lowestTemp6 && sumAvgOnt < lowestTemp5)
		lowestTemp6 = sumAvgOnt;					
	if(sumAvgStC >= lowestTemp6 && sumAvgStC < lowestTemp5)
		lowestTemp6 = sumAvgStC;
	printf ("The 6th warmest Summer Temp is: %lf \n", lowestTemp6);
	
	//q6---------------------------------------------------------------
	printf("\n------Question 6------");
	//calculates the winter average (days 1 to 79 and days 355 to 366) for all 6 lakes
	double winAvgSup = winAvg(2, data);
    double winAvgMich = winAvg(3, data);
    double winAvgHuron = winAvg(4, data);
    double winAvgErie = winAvg(5, data);
    double winAvgOnt = winAvg(6, data);
    double winAvgStC = winAvg(7, data);
    
    //displays the winter average (days 1 to 79 and days 355 to 366) for all 6 lakes
    printf("\n");
    printf("Average winter temp for lake Sup is: %lf\n", winAvgSup);
    printf("Average winter temp for lake Mich is: %lf\n", winAvgMich);
    printf("Average winter temp for lake Huron is: %lf\n", winAvgHuron);
    printf("Average winter temp for lake Erie is: %lf\n", winAvgErie);
    printf("Average winter temp for lake Ont is: %lf\n", winAvgOnt);
    printf("Average winter temp for lake StC is: %lf\n", winAvgStC);
    printf("\n");
	
	//display the temp of the lakes in order from warmest to coldest 
	double lowestTemp7 = 0;
    if(winAvgSup >= lowestTemp7)
		lowestTemp7 = winAvgSup;	
	if(winAvgMich >= lowestTemp7)
		lowestTemp7 = winAvgMich;	
	if(winAvgHuron >= lowestTemp7)
		lowestTemp7 = winAvgHuron;			
	if(winAvgErie >= lowestTemp7)
		lowestTemp7 = winAvgErie;				
	if(winAvgOnt >= lowestTemp7)
		lowestTemp7 = winAvgOnt;					
	if(winAvgStC >= lowestTemp7)
		lowestTemp7 = winAvgStC;		
	printf ("The 1st warmest Winter Temp is: %lf \n", lowestTemp7); 
	
	double lowestTemp8 = 0;
    if(winAvgSup >= lowestTemp8 && winAvgSup < lowestTemp7)
		lowestTemp8 = winAvgSup;	
	if(winAvgMich >= lowestTemp8 && winAvgMich < lowestTemp7)
		lowestTemp8 = winAvgMich;	
	if(winAvgHuron >= lowestTemp8 && winAvgHuron < lowestTemp7)
		lowestTemp8 = winAvgHuron;			
	if(winAvgErie >= lowestTemp8 && winAvgErie < lowestTemp7)
		lowestTemp8 = winAvgErie;				
	if(winAvgOnt >= lowestTemp8 && winAvgOnt < lowestTemp7)
		lowestTemp8 = winAvgOnt;					
	if(winAvgStC >= lowestTemp8 && winAvgStC < lowestTemp7)
		lowestTemp8 = winAvgStC;
	printf ("The 2nd warmest Winter Temp is: %lf \n", lowestTemp8);
	
	double lowestTemp9 = 0;
    if(winAvgSup >= lowestTemp9 && winAvgSup < lowestTemp8)
		lowestTemp9 = winAvgSup;	
	if(winAvgMich >= lowestTemp9 && winAvgMich < lowestTemp8)
		lowestTemp9 = winAvgMich;	
	if(winAvgHuron >= lowestTemp9 && winAvgHuron < lowestTemp8)
		lowestTemp9 = winAvgHuron;			
	if(winAvgErie >= lowestTemp9 && winAvgErie < lowestTemp8)
		lowestTemp9 = winAvgErie;				
	if(winAvgOnt >= lowestTemp9 && winAvgOnt < lowestTemp8)
		lowestTemp9 = winAvgOnt;					
	if(winAvgStC >= lowestTemp9 && winAvgStC < lowestTemp8)
		lowestTemp9 = winAvgStC;
	printf ("The 3rd warmest Winter Temp is: %lf \n", lowestTemp9);	
	
	double lowestTemp10 = 0;
    if(winAvgSup >= lowestTemp10 && winAvgSup < lowestTemp9)
		lowestTemp10 = winAvgSup;	
	if(winAvgMich >= lowestTemp10 && winAvgMich < lowestTemp9)
		lowestTemp10 = winAvgMich;	
	if(winAvgHuron >= lowestTemp10 && winAvgHuron < lowestTemp9)
		lowestTemp10 = winAvgHuron;			
	if(winAvgErie >= lowestTemp10 && winAvgErie < lowestTemp9)
		lowestTemp10 = winAvgErie;				
	if(winAvgOnt >= lowestTemp10 && winAvgOnt < lowestTemp9)
		lowestTemp10 = winAvgOnt;					
	if(winAvgStC >= lowestTemp10 && winAvgStC < lowestTemp9)
		lowestTemp10 = winAvgStC;
	printf ("The 4th warmest Winter Temp is: %lf \n", lowestTemp10);
	
	double lowestTemp11 = 0;
    if(winAvgSup >= lowestTemp11 && winAvgSup < lowestTemp10)
		lowestTemp11 = winAvgSup;	
	if(winAvgMich >= lowestTemp11 && winAvgMich < lowestTemp10)
		lowestTemp11 = winAvgMich;	
	if(winAvgHuron >= lowestTemp11 && winAvgHuron < lowestTemp10)
		lowestTemp11 = winAvgHuron;			
	if(winAvgErie >= lowestTemp11 && winAvgErie < lowestTemp10)
		lowestTemp11 = winAvgErie;				
	if(winAvgOnt >= lowestTemp11 && winAvgOnt < lowestTemp10)
		lowestTemp11 = winAvgOnt;					
	if(winAvgStC >= lowestTemp11 && winAvgStC < lowestTemp10)
		lowestTemp11 = winAvgStC;
	printf ("The 5th warmest Winter Temp is: %lf \n", lowestTemp11);				
   
   double lowestTemp12 = 0;
    if(winAvgSup >= lowestTemp12 && winAvgSup < lowestTemp11)
		lowestTemp12 = winAvgSup;	
	if(winAvgMich >= lowestTemp12 && winAvgMich < lowestTemp11)
		lowestTemp12 = winAvgMich;	
	if(winAvgHuron >= lowestTemp12 && winAvgHuron < lowestTemp11)
		lowestTemp12 = winAvgHuron;			
	if(winAvgErie >= lowestTemp12 && winAvgErie < lowestTemp11)
		lowestTemp12 = winAvgErie;				
	if(winAvgOnt >= lowestTemp12 && winAvgOnt < lowestTemp11)
		lowestTemp12 = winAvgOnt;					
	if(winAvgStC >= lowestTemp12 && winAvgStC < lowestTemp11)
		lowestTemp12 = winAvgStC;
	printf ("The 6th warmest Winter Temp is: %lf \n", lowestTemp12);
	
    
    //q7---------------------------------------------------------------
    printf("\n------Question 7------\n");
    //calculates the number of days in the year you can swim for each of the 6 lakes.
    double swimTempSup = swimmingTemp(2, data);
    double swimTempMich = swimmingTemp(3, data);
    double swimTempHuron = swimmingTemp(4, data);
    double swimTempErie = swimmingTemp(5, data);
    double swimTempOnt = swimmingTemp(6, data);
    double swimTempStC = swimmingTemp(7, data);
    
    //displays the number of days in the year you can swim for each of the 6 lakes.
    printf("Number of days with swimmable water temp for lake Sup: %.1lf\n", swimTempSup);
    printf("Number of days with swimmable water temp for lake Mich: %.1lf\n", swimTempMich);
    printf("Number of days with swimmable water temp for lake Huron: %.1lf\n", swimTempHuron);
    printf("Number of days with swimmable water temp for lake Erie: %.1lf\n", swimTempErie);
    printf("Number of days with swimmable water temp for lake Ont: %.1lf\n", swimTempOnt);
    printf("Number of days with swimmable water temp for lake StC: %.1lf\n", swimTempStC);
    
    //q8---------------------------------------------------------------
    printf("\n------Question 8------");
    //calculates the number of days in the year that the lake is frozen for each of the 6 lakes.
    double frozenTempSup = frozenTemp(2, data);
    double frozenTempMich = frozenTemp(3, data);
    double frozenTempHuron = frozenTemp(4, data);
    double frozenTempErie = frozenTemp(5, data);
    double frozenTempOnt = frozenTemp(6, data);
    double frozenTempStC = frozenTemp(7, data);
    
    //displays the number of days in the year that the lake is frozen for each of the 6 lakes.
    printf("\n");
    printf("Number of days with the forzen water temp for lake Sup: %.1lf\n", frozenTempSup);
    printf("Number of days with the forzen water temp for lake Mich: %.1lf\n", frozenTempMich);
    printf("Number of days with the forzen water temp for lake Huron: %.1lf\n", frozenTempHuron);
    printf("Number of days with the forzen water temp for lake Erie: %.1lf\n", frozenTempErie);
    printf("Number of days with the forzen water temp for lake Ont: %.1lf\n", frozenTempOnt);
    printf("Number of days with the forzen water temp for lake StC: %.1lf\n", frozenTempStC);
    
    //q9---------------------------------------------------------------
	printf("\n------Question 9------");
	//opening the file
    FILE * input2;
    input2 = fopen("cpsData2.txt", "r");

    //array declaration
    double data2[365][8];

    //getting data from the file and storing into a 2D array
    for(int i=0; i<365; i++)
        for(int j=0; j<8; j++)
            fscanf(input2, "%lf", &data2[i][j]);

    //calculates the yearly average temperature for each of the lakes in 2019
    double avgSup2 = lakeAvg2(2, data2);
    double avgMich2 = lakeAvg2(3, data2);
    double avgHuron2 = lakeAvg2(4, data2);
    double avgErie2 = lakeAvg2(5, data2);
    double avgOnt2 = lakeAvg2(6, data2);
    double avgStC2 = lakeAvg2(7, data2);
    double allAvg2 = avgTotal2(data2);
    
    //displays the yearly average temperature for each of the lakes in 2019
    printf("\n");
    printf("Average temp for lake Sup (in 2019) is: %lf\n", avgSup2);
    printf("Average temp for lake Mich (in 2019) is: %lf\n", avgMich2);
    printf("Average temp for lake Huron (in 2019) is: %lf\n", avgHuron2);
    printf("Average temp for lake Erie (in 2019) is: %lf\n", avgErie2);
    printf("Average temp for lake Ont (in 2019) is: %lf\n", avgOnt2);
    printf("Average temp for lake StC (in 2019) is: %lf\n", avgStC2);
    printf("Average temp for all lakes (in 2019) is: %lf\n", allAvg2);
    
    //dusplays the yearly average temperature for each of the lakes in 2019 and 2020 in a table
    printf("\n");
    printf("Year	Lake Sup Temp		Lake Mich Temp		Lake Huron Temp		Lake Erie Temp		Lake Ont Temp		Lake StC Temp\n");
    printf("2019	%lf		%lf		%lf		%lf		%lf		%lf\n", avgSup2, avgMich2, avgHuron2, avgErie2, avgOnt2, avgStC2);
    printf("2020	%lf		%lf		%lf		%lf		%lf		%lf\n", avgSup, avgMich, avgHuron, avgErie, avgOnt, avgStC);
    
    return(0);
}
