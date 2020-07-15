using namespace std;

class Dense
{
	int ins;
	int outs;
	float** input;
	float** weights;
	float** bias;
	int batch_size;
	float** output;
    float **dZ;
    string activation;
	
	public :

	Dense(float** input,int batch_size,int ins,int outs,string activation="none")
	{
      this->input=input;
	  this->batch_size=batch_size;
	  this->ins=ins;
	  this->outs=outs;
      this->activation=activation;
       
	 
	  weights=new float*[ins];
	  bias=new float*[outs];
	 
	  for(int i=0;i<ins;i++)
	  	weights[i]=new float[outs];

        for(int i=0;i<outs;i++)
	  	bias[i]=new float[1]();

	  output=new float*[batch_size];

	  for(int i=0;i<batch_size;i++)
	  output[i]=new float[outs];

      dZ=new float*[batch_size];
       
        for(int i=0;i<batch_size;i++)
        {
            dZ[i]=new float[outs];
            
        }

      he_init();

	  cout<<"Sucessfully Init...";

	}

    void set_input(float** input)
    {
        this->input=input;
    }
    

    float** get_result()
    {
     output=mat_add(mat_mul(input,weights,batch_size,ins,ins,outs),bias,batch_size,outs,outs,1);
     

    if(activation.compare("sigmoid")==0)
    {
        for(int i=0;i<batch_size;i++)
        {
            for(int j=0;j<outs;j++)
                *(*(output+i)+j)=1.0/(1+exp(0-(*(*(output+i)+j)))) ;
        }
    }
    
    
    return output;
    }


	void he_init()
    {
    for(int i=0;i<ins;i++)
    {
        for(int j=0;j<outs;j++)
        weights[i][j]=(rand()/(1.0+RAND_MAX))/sqrt(ins);
    }
    }

    float** get_weights()
    {
    return weights;
    }
    float** get_dZ(){return dZ;}
    int get_ins(){return ins;}
    int get_outs(){return outs;}

    void back_propagate(bool output_layer,Dense* dense,float** act=0)
    {
        float **dW,** W_prev,**dZ_prev,**db;
        if(dense!=0)
        {
        W_prev=dense->get_weights();
        dZ_prev=dense->get_dZ();
        }
        

        if(output_layer)
           dZ=mat_sub(output,act,batch_size,outs,batch_size,outs);
        else
           {
               auto temp1=mat_transpose(W_prev,dense->get_ins(),dense->get_outs());
               auto temp2=mat_mul(dZ_prev,temp1,batch_size,dense->get_outs(),dense->get_outs(),dense->get_ins());
               auto temp3=mat_ele_mul(output,mat_sub(1.0,output,batch_size,outs),batch_size,outs,batch_size,outs);

               dZ=mat_divide(mat_ele_mul(temp3,temp2,batch_size,outs,batch_size,outs),1e0,batch_size,outs);

           }

       //Clipping...
        dZ=clip_grad(dZ,batch_size,outs,10.0);
        dW=mat_divide(mat_mul(mat_transpose(input,batch_size,ins),dZ,ins,batch_size,batch_size,outs),batch_size,ins,outs);
        weights=mat_sub(weights,mat_ele_mul(2.0,dW,ins,outs),ins,outs,ins,outs);
        db=mat_divide(mat_transpose(mat_sum(dZ,batch_size,outs,0),1,outs),batch_size,outs,1);
        bias=mat_sub(bias,mat_ele_mul(2.0,db,outs,1),outs,1,outs,1);

       
      
       
     
    }
    

};