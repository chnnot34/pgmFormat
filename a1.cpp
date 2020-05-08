#include <stdio.h> 
#include<math.h> 
int main() 
{ 
    int temp,width =2048, height =2048,k_first,k_last;
    
	double cx,cy,x1,y1,z1; 
    
    FILE* julia; 
    julia = fopen("julia.pgm", "wb"); 
   
    fprintf(julia, "P2\n");  
  
    fprintf(julia, "%d %d\n", width, height);  
   
    fprintf(julia, "255\n");
    
    printf("Enter The Constant k..");
    scanf("%d",&k_last);
    
    printf("Enter the real part of the complex number C..");
    scanf("%lf",&cx);
    printf("Enter the imaginary part of the complex number C..");
    scanf("%lf",&cy);
    
    for(x1=-1.5;x1<1.5;x1=x1+(3.0/2048.0)){
    	for(y1=-1.5;y1<1.5;y1=y1+(3.0/2048.0)){
    		
    		double x=y1;
    		double yi=x1;
    		
    		double ax;
    		double ay;
    		
    		for (k_first=0;k_first<k_last;k_first++){
    			
    			ax=(pow(x,2)-pow(yi,2))+cx;
    			ay=2*x*yi+cy;
    		
    			x=ax;
    			yi=ay;
    		}
    		
    		z1=sqrt(pow(x,2)+pow(yi,2));
    		if (z1<=4){
    			temp=0;
			}
    		else {
    			temp=255;
			}
			fprintf(julia, "%d ", temp);	
		}
		fprintf(julia, "\n");
	}
    fclose(julia);
} 


