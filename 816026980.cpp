/*My name is Isis Gonsalves and my student ID number is 816026980. 

ASSIGNMENT 4 for COMP 1601

I believe my program is working efficiently however, this was a bit challenging. 

This program will open an input file (readings.txt) and analysis a person's blood sugar level.

Inputs from file: - blood sugar level for every day
		
		
To display in Output File (results): - Highest blood sugar levels
									 - Days with the highest tie
									 - 3 Consecutive days with blood sugar levels higher than user input
									 - Number of Days that weren't measured
									 - Percentage of days not measured
									 - Number of spikes in blood sugar level (increase or decrease)
									 - Highest Spike (increase or decrease)
									 - Day the spike occurred


To display to console: - Histogram of Levels based on the range of blood sugar

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>


using namespace std;

void printStars (int n) //This is a Print Stars function. 

{
	int i;
	
	for (i=1; i<=n; i=i+1) 
		cout << "*";

}


int main() {
	int glucose [500]={0}; //array for file read
	int ranges [7]; //array for ranges
	
	ifstream in_readings; //declare input file
	ofstream out_results; //declare output file
	
	int day =0; //counter
	int n =0; //counter
	int i; //counter
	int count=0;//counter
	
	int sugar_level; // variable for file read
	
	int highest= INT_MIN; //highest sugar level
	int highest_day; //day with highest sugar level
	
	int highest_tie; //the tie amount
	int high_tieday; //the day that tied
	
	int readings=0; //total amount of values in file 
	
	//variables for print stars function
	int seventy_stars=0;
	int eighty_stars=0;
	int ninety_stars=0;
	int hundreds_stars=0;
	int teens_stars=0;
	int twenty_stars=0;
	int highest_level_stars=0;
	
	//variables to calculate days not measured
	int zero;
	int zero_level=0;
	float zero_percent=0;
	int percent = 100;
	
	int input_level; //value entered by user
	
	int level; //used in for loop to count
	
	int max; //used in for loop to count
	
	int consecutive; //used in for loop to count
	
	int difference=0; //store the difference between levels
	
	int num_spikes; //store number of spikes
	
	//variables for biggest spike
	int biggest_spike = INT_MIN;
	int biggest_spikeday1;
	int biggest_spikeday2;
	
	int s;//used in loop to count
	
	
	in_readings.open("readings.txt");
	out_results.open("results.txt");
	
	
	cout<<"\t\tBlood Sugar Level Analysis\n";
	cout<<"\t\t--------------------------\n";
	
	
	out_results<<"\t\tBlood Sugar Level Analysis\n";
	out_results<<"\t\t--------------------------\n";
	
	
	if (!in_readings.is_open()) {
		cout << "\nERROR: File cannot be found...Try again\n";
		return 0;
	}
	else 
		
		cout<<"File was Read Successfully... "<<endl<<endl; 
	
	
	cout<<"Starting Part A..."<<endl<<endl;
	
	//Part A: Reading file into array, keeping track of how much values in array.

	in_readings >> sugar_level;
	
	while ((sugar_level != -1)&&(count <=500)){
		
		count++;
		
		readings=readings +1;
		
		glucose[n]=sugar_level;
		
		n=n+1;
		
		in_readings >> sugar_level;
	}
	
	cout<<"Part A Completed. "<<endl<<endl<<endl;
	
	
	cout<<"Starting Part B... "<<endl<<endl;
	
	//Part B: Calculating highest blood sugar level and checking for ties 
	
	for (max=0; max < readings; max=max+1){
	
	day=day+1;	
			
		if(glucose [max] > highest ){
				highest= glucose[max];
				highest_day= day; 
				
		}
		else
		if ((glucose[max]==highest)&&(max!=highest_day)){
			highest_tie= glucose[max];
			high_tieday= day;
			
		}
	
	}

	out_results<<"The highest blood sugar level was: "<<highest<< " on Day: " <<highest_day <<" and Day: "<< high_tieday <<endl<<endl<<endl;

	cout<<"Part B Completed. "<<endl<<endl<<endl;


	cout<<"Starting Part C... "<<endl<<endl;
	
	//Part C: Prompting for input value and displaying consecutive days where the blood sugar level was greater than the user input.

	cout<<"Hello, Please enter a Blood Sugar Level: ";
	cin>>input_level;
	
	out_results<<"Consecutive Days with levels over "<<input_level<<endl;
	out_results<<"------------------------------------\n";
	

	for(consecutive=0; consecutive < readings; consecutive=consecutive+1){
		
			if((glucose[consecutive]>input_level) && (glucose[consecutive - 1 ]>input_level)&&(glucose[consecutive - 2 ]>input_level)){
				out_results<<"\n\nDays: "<< consecutive-1 << " ("<<glucose[consecutive - 2 ]<<" mg/dl), "; 
				
				out_results<<consecutive << " ("<<glucose[consecutive - 1 ]<<" mg/dl), "; 
				
				out_results<<consecutive +1<< " ("<<glucose[consecutive ]<<" mg/dl) ";
			}
	
	}
	
	cout<<"Part C Completed. "<<endl<<endl<<endl;


	cout<<"Starting Part D... "<<endl<<endl;
	
	//Part D: Calculating amount of zeros in file and its percentage. Zeros indicate no measurement was taken on that day.

	for (zero=0; zero<readings; zero=zero+1){
		
		if(glucose[zero] == 0)
		zero_level= zero_level + 1; 
		
	}

	zero_percent= (zero_level*1.0/ day) * percent; 
	
	
	out_results<<"\n\nNumber of days measurements were not taken: " <<zero_level<<endl;
	out_results<< "\nPercentage of days measurements were not taken: "<< fixed << setprecision(1)<<zero_percent<< " % "<<endl;
	
	cout<<"Part D Completed. "<<endl<<endl<<endl;
	

	cout<<"Starting Part E... "<<endl<<endl;

	//Part E: Calculate number of spikes, Highest Spike and day it occurred. 
	
	for (i=0; i < readings; i = i +1){
		
		if((glucose[i] !=0)&&(glucose[i+1]!=0)){
		
			if(glucose[i] > glucose [i +1]){
				
				difference= glucose[i] - glucose [i+1];
				
				if(difference >= 40){
					num_spikes= num_spikes +1;
				}
				
			}
			else 
				if (glucose[i+1] > glucose [i]){
					
					difference= glucose[i+1] - glucose [i];
					
					if(difference >= 40){
						num_spikes= num_spikes +1;
					}
				}
		}
		
		if (difference > biggest_spike){
			biggest_spike= difference;
			biggest_spikeday1= i +1;
			biggest_spikeday2= i +2;
		}
	}
	
	out_results<<"\n\n\nNumber of Spikes Occurred: "<<num_spikes<<endl;
	out_results<<"\nBiggest Spike to Occur: "<<biggest_spike<<endl;
	out_results<<"\nOccurred between: Day "<<biggest_spikeday1<<" and Day "<<biggest_spikeday2<<endl;

	cout<<"Part E Completed. "<<endl<<endl<<endl;


	cout<<"Starting Part F... "<<endl<<endl;

	//Part F: Printing a histogram using the print stars function.
	
	for (s=0; s<7; s=s+1){
		ranges[s]=0;
	}
	
	for (level=0;level<readings;level=level+1){

		if (glucose[level] >=70 && glucose[level] <=79){
			ranges[0]=ranges [0] +1;
		}
		else
			if (glucose[level] >=80 && glucose[level] <=89){
			ranges[1]=ranges [1] +1;
			}
			else
				if(glucose[level] >=90 && glucose[level] <=99){
				ranges[2]=ranges [2] +1;
				}
				else
					if(glucose[level] >=100 && glucose[level] <=109){
					ranges[3]=ranges [3] +1;
					}
					else
						if(glucose[level] >=110 && glucose[level] <=119){
						ranges[4]=ranges [4] +1;
						}
						else
							if(glucose[level] >=120 && glucose[level] <=129){
							ranges[5]=ranges [5] +1;
							}
							else
								if(glucose[level] >=130 ){
								ranges[6]=ranges [6] +1;
								}
	}
	
	seventy_stars= ceil(ranges[0]*1.0/5);
	eighty_stars= ceil(ranges[1]*1.0/5);
	ninety_stars= ceil(ranges[2]*1.0/5);
	hundreds_stars= ceil(ranges[3]*1.0/5);
	teens_stars= ceil(ranges[4]*1.0/5);
	twenty_stars= ceil(ranges[5]*1.0/5);
	highest_level_stars= ceil(ranges[6]*1.0/5);
	

	cout<< "\n\tHISTOGRAM OF READINGS\n";
	cout<< "\t---------------------\n";
	cout<<"\t70-79  | ";
	printStars(seventy_stars);
	cout<<endl<<endl;
	
	cout<<"\t80-89  | ";
	printStars(eighty_stars);
	cout<<endl<<endl;
	
	cout<<"\t90-99  | ";
	printStars(ninety_stars);
	cout<<endl<<endl;
	
	cout<<"\t100-109| ";
	printStars(hundreds_stars);
	cout<<endl<<endl;
	
	cout<<"\t110-119| ";
	printStars(teens_stars);
	cout<<endl<<endl;
	
	cout<<"\t120-129| ";
	printStars(twenty_stars);
	cout<<endl<<endl;
	
	cout<<"\t130 +  | ";
	printStars(highest_level_stars);
	
	cout<<"\n\n\nPart F Completed. "<<endl<<endl<<endl;	
	
	cout<<"\n\n\tThank You & Stay Covid Safe :) -Isis "<<endl;
	cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;	
	
	//closing all files
	
	in_readings.close(); 
	out_results.close(); 
	
	return 0;
}
