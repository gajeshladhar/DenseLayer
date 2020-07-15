#include <iostream>
#include <cmath>
#include<fstream>
#include <string>
#include<stdlib.h>
#include "matrix.h"
#include "dense.h"


using namespace std;
int batch_size=401;
int output_size=1;

float calculate_loss(float**,float**);
void read_csv(float**,float**);
int main()
{
	Dense *dense_1,*dense_2,*dense_3;
	
    float** X=new float*[401];
    float** Y=new float*[401];


    for(int i=0;i<401;i++)
    {
        X[i]=new float[3];
        Y[i]=new float[1];
    }

    //Generating Dataset X and Y
     read_csv(X,Y);
     X=normalization(X,401,3);
    

	dense_1=(new Dense(X,batch_size,3,10,"sigmoid"));
	dense_2=(new Dense(dense_1->get_result(),batch_size,10,5,"sigmoid"));
	dense_3=(new Dense(dense_2->get_result(),batch_size,5,output_size,"sigmoid"));

 

    float loss=calculate_loss(dense_3->get_result(),Y);
    cout<<endl<<"loss : "<<loss<<endl;
	// backprop
    
   
    for(int i=0;i<3000;i++)
    {
     

      dense_3->back_propagate(true,0,Y);
      dense_2->back_propagate(false,dense_3,0);
      dense_1->back_propagate(false,dense_2,0);

      
   
   cout<<endl;
      dense_2->set_input(dense_1->get_result());
      dense_3->set_input(dense_2->get_result());
      loss=calculate_loss(dense_3->get_result(),Y);
      cout<<"loss : "<<loss<<endl;
      cout<<"Y[0][0] : "<<dense_3->get_result()[1][0]<<endl;
  

    }
    
  ofstream fout;
  fout.open("result.txt");
  fout<<"Predicted  |  Original"<<endl;
  for(int i=0;i<batch_size;i++)
    fout<<dense_3->get_result()[i][0]<<"     "<<Y[i][0]<<"\n";
  fout.close();

	return 0;
}




float calculate_loss(float** pred,float** act)
{
float loss=0;

    for(int i=0;i<batch_size;i++)
    {
        for(int j=0;j<output_size;j++)
        loss+=0-( *(*(act+i)+j)*log(*(*(pred+i)+j))+(1-*(*(act+i)+j))*log(1-*(*(pred+i)+j)) );
    }
    loss/=(batch_size*1.0);

    return loss;
}


void read_csv(float** X,float** Y)
{
string line;
ifstream fin;
int i;



fin.open("Social_Network_Ads.csv");
string temp;

  while(fin && i<401)
  {  
    getline(fin,line);
    

    if(i==0)
    {
        i++;
        continue;
    }
   
    temp="";
    int flag=0;
    int count=0;
    for(int k=0;k<line.length();k++)
    {
        if(flag==1 && line[k]!=',')
        {
            
        temp=temp+line[k];
        continue;
        
        
        }

        
      if(line[k]==',')
      {
      if(flag==0)
      {
      flag=1;
      continue;
      }

      if(temp.compare("Male")==0)
      temp="0";
      else if( temp.compare("Female")==0)
      temp="1";
     
     //cout<<temp<<endl;
     
     if(count<3)
       X[i][count]=stoi(temp);
     else
       Y[i][0]=stoi(temp);
    //cout<<X[i][count]<<endl;  

        temp="";
        
        count++;
        continue;
      }


    }
    Y[i][0]=stoi(temp);
     
    i++;
 
    
  }
  fin.close();  
/* cout<<endl<<"Verify..."<<endl;
 for(int i=0;i<401;i++)
     cout<<X[i][0]<<" "<<X[i][1]<<" "<<X[i][2]<<" ---> "<<Y[i][0]<<endl;;
*/


    
}
