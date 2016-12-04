# include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
	char file_name[25],file_nam[25];
	printf("Enter the protein conformation file(pdb file).\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	string s; double x[100],y[100],z[100]; int i=0;
	while(!inputfile.eof()) 
	{
		inputfile>>s;
		if(s=="ATOM")
		{
			inputfile>>s;
			inputfile>>s;
			if(s=="CA")
			{inputfile>>s;inputfile>>s;inputfile>>s;
			inputfile>>x[i]>>y[i]>>z[i];
			i++;
	
			}
		}
		
	}
	inputfile.close();
	printf("Enter the native protein conformation file(pdb file).\n");
    cin>>file_nam;
    ifstream inputfile1(file_nam);
    double x1[100],y1[100],z1[100]; int j=0;
	while(!inputfile1.eof()) 
	{
		inputfile1>>s;
		if(s=="ATOM")
		{
			inputfile1>>s;
			inputfile1>>s;
			if(s=="CA")
			{inputfile1>>s;inputfile1>>s;inputfile1>>s;
			inputfile1>>x1[j]>>y1[j]>>z1[j];
			j++;	
			}
		}
		
	}
	inputfile1.close();
	int cn=i,nn=j,counter1[1000],counter2[1000],k=0; double count1=0,count2=0,com=0;
	for(i=0;i<cn-2;i++)
	for(j=i+2;j<cn;j++)
	{
		if(((x[i] - x[j])*(x[i] - x[j])+(y[i] - y[j])*(y[i] - y[j])+(z[i] - z[j])*(z[i] - z[j]))<36)
	 	{
			count1++;
			counter1[k]=1;
			k++;
	 	}
		else
			{
				counter1[k]=0;
				k++;
			}
	}
	k=0;
	for(i=0;i<nn-2;i++)
	for(j=i+2;j<nn;j++)
	{
		if(((x1[i] - x1[j])*(x1[i] - x1[j])+(y1[i] - y1[j])*(y1[i] - y1[j])+(z1[i] - z1[j])*(z1[i] - z1[j]))<36)
	 	{
			count2++;
			counter2[k]=1;
			k++;
	 	}
		else
			{
				counter2[k]=0;
				k++;
			}
	}
 	cout<<"No. of contacts in given protein conformation="<<count1<<endl;
 	cout<<"No. of contacts in native protein conformation="<<count2<<endl;
 	for(i=0;i<k;i++)
 		if(counter1[i] && counter2[i])
 			com++;
 	cout<<"Common contacts in conformation and native protein="<<com<<endl;
 	cout<<"Contact Density="<<(com/count2)*100<<endl;
	system("pause");	
	
return 0;
}
