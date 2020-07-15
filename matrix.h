float** mat_mul(float** mat1,float** mat2,int r1,int c1,int r2,int c2)
{

    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c2];
    float sum=0;

    for (int row = 0; row < r1; row++)
    {
        for (int col = 0; col < c2; col++)
        {
            sum = 0;

           
            for (int i = 0; i < c1; i++)
            {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }


            *(*(result + row) + col) = sum;
        }
    }

 return result;

}

float** mat_add(float** mat1,float** mat2,int r1,int c1,int r2,int c2)
{
    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c1];

    if(r1==r2 && c1==c2)
    {
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            result[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    else if(r1==r2 && c2==1)
    {
        for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c1;j++)
                result[i][j]=mat1[i][j]+mat2[i][0];
            }

    }

    else if(c1==r2 && c2==1)
    {
        for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c1;j++)
                result[i][j]=mat1[i][j]+mat2[j][0];
            }

    }


    return result;

}

float** mat_add(float** mat1,float mat2,int r1,int c1)
{
    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c1];
    
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
         result[i][j]=mat1[i][j]+mat2;
    }

    return result;
}
float** mat_add(float mat1,float** mat2,int r2,int c2)
{
    float** result;
    result=new float*[r2];
    for(int i=0;i<r2;i++)
    result[i]=new float[c2];
    
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
         result[i][j]=mat2[i][j]+mat1;
    }

    return result;
}



float** mat_sub(float** mat1,float mat2,int r1,int c1)
{
    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c1];
    
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
         result[i][j]=mat1[i][j]-mat2;
    }

    return result;
}
float** mat_sub(float mat1,float** mat2,int r2,int c2)
{
    float** result;
    result=new float*[r2];
    for(int i=0;i<r2;i++)
    result[i]=new float[c2];
    
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
         result[i][j]=mat1-mat2[i][j];
    }

    return result;
}


float** mat_ele_mul(float** mat1,float mat2,int r1,int c1)
{
    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c1];
    
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
         result[i][j]=mat1[i][j]*mat2;
    }

    return result;
}
float** mat_ele_mul(float mat1,float** mat2,int r2,int c2)
{
    float** result;
    result=new float*[r2];
    for(int i=0;i<r2;i++)
    result[i]=new float[c2];
    
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
         result[i][j]=mat2[i][j]*mat1;
    }

    return result;
}


float** mat_divide(float** mat1,float mat2,int r1,int c1)
{
    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c1];
    
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
         result[i][j]=mat1[i][j]/(1.0*mat2+1e-5);
    }

    return result;
}
float** mat_divide(float mat1,float** mat2,int r2,int c2)
{
    float** result;
    result=new float*[r2];
    for(int i=0;i<r2;i++)
    result[i]=new float[c2];
    
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
         result[i][j]=mat2[i][j]/(1.0*mat1);
    }

    return result;
}



float** mat_sub(float** mat1,float** mat2,int r1,int c1,int r2,int c2)
{
    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c1];

    if(r1==r2 && c1==c2)
    {
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            result[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
    else if(r1==r2 && c2==1)
    {
        for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c1;j++)
                result[i][j]=mat1[i][j]-mat2[i][0];
            }

    }

    return result;

}

float** mat_ele_mul(float** mat1,float** mat2,int r1,int c1,int r2,int c2)
{
    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c1];

    if(r1==r2 && c1==c2)
    {
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            result[i][j]=mat1[i][j]*mat2[i][j];
        }
    }
    else if(r1==r2 && c2==1)
    {
        for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c1;j++)
                result[i][j]=mat1[i][j]*mat2[i][0];
            }

    }
    else if(c1==c2 && r2==1)
    {
        for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c1;j++)
                result[i][j]=mat1[i][j]*mat2[0][j];
            }

    }

    return result;

}

float** mat_divide(float** mat1,float** mat2,int r1,int c1,int r2,int c2)
{
    float** result;
    result=new float*[r1];
    for(int i=0;i<r1;i++)
    result[i]=new float[c1];

    if(r1==r2 && c1==c2)
    {
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            result[i][j]=mat1[i][j]/(1.0*mat2[i][j]);
        }
    }
    else if(r1==r2 && c2==1)
    {
        for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c1;j++)
                result[i][j]=mat1[i][j]/(1.0*mat2[i][0]);
            }

    }
    else if(c1==c2 && r2==1)
    {
        for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c1;j++)
                result[i][j]=mat1[i][j]/(1.0*mat2[0][j]);
            }

    }

    return result;

}

float** mat_transpose(float** mat,int r,int c)
{
    float** result=new float*[c];
    int i, j; 
    for(i=0;i<c;i++)
    result[i]=new float[r];

    
    for (i = 0; i < c; i++) 
        for (j = 0; j < r; j++) 
            result[i][j] = mat[j][i]; 

    return result;
}

float** mat_sum(float** mat,int r,int c,int axis)
{
    float** result;
    if(axis==0)
    {
    result=new float*[1];
    result[0]=new float[c];
    float sum=0;

    for(int j=0;j<c;j++)
    {
        for(int i=0;i<r;i++)
        {
            sum+=mat[i][j];
        }
        result[0][j]=sum;
    }
    }

    return result;
}

float** normalization(float** X,int r,int c)
{
  float* mean=new float[c];
  float* std=new float[c];
  for(int i=0;i<r;i++)
  {
      for(int j=0;j<c;j++)
      mean[j]+=(X[i][j]/(1.0*r));
      
  }

  for(int i=0;i<r;i++)
  {
      for(int j=0;j<c;j++)
      std[j]+=((X[i][j]-mean[j])*(X[i][j]-mean[j])/(1.0*r) );
      
      
  }

  for(int i=0;i<c;i++)
  std[i]=sqrt(std[i]);

  for(int i=0;i<r;i++)
  {
      for(int j=0;j<c;j++)
      X[i][j]=(X[i][j]-mean[j])/(1.0*std[j]+1e-5);
  }

return X;
}

float** clip_grad(float** dZ,int r,int c,float range)
{
  for(int i=0;i<r;i++)
  {
      for(int j=0;j<c;j++)
  {
      if(dZ[i][j]<0-range)
      dZ[i][j]=0-range;
      else if(dZ[i][j]>range)
      dZ[i][j]=range;
  }
  }

  return dZ;
}