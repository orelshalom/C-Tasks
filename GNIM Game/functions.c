//Ordering the packets
void Order(int *x, int *y, int *z){
  if (*x >= *y && *x >= *z)
    {
      int temp = *x;
      *x = *z;
      *z = temp;
      if (*x > *y)
	{
	  int temp = *x;
	  *x = *y;
	  *y = temp;
	}
    }
  else {
      if (*y >= *x && *y >= *z)
    {
      int temp = *y;
      *y = *z;
      *z = temp;
      if (*x > *y)
	{
	  int temp = *y;
	  *y = *x;
	  *x = temp;
	}
    }
  else {
      if (*z >= *x && *z >= *y)
    {
      if (*x > *y)
	{
	  int temp = *x;
	  *x = *y;
	  *y = temp;
	}
    }
  }
  }
}

//Get input from the user
void UserChoice(int * a, int * b, int * x, int * y, int * z){
	  if (*a == *x){
	    *x = *b;
	  }
	  else {
	      if (*a == *y && *a != *x){
	        *y = *b;
	      }
	      else {
	          if (*a == *z && *a != *y && *a != *x){
	            *z = *b;
	          }
	      }
	  }
}

//Checking if computer lost
int IsWinner(int * x, int * y, int * z, int * loser){
    if((*x == 0 && *y == 0 && *z == 1) || (*x == 1 && *y == 1 && *z == 1)){
        *loser = 1;
    }
    return *loser;
}    
    
//Checking if user lost
int IsLoser(int * x, int * y, int * z, int * loser){
    if((*x == 0 && *y == 0 && *z > 1) || (*x == 1 && *y == 1 && *z > 1)){
        printf ("I turned %d to 1\n", *z);
        *z = 1;
        printf ("Packets sizes are now:\n%d %d %d\n", *x, *y, *z);
        *loser = 1;
    }
    else {
        if((*x == 0 && *y == 1 && *z > 1) || (*x == 0 && *y == 1 && *z == 1)){
            printf ("I turned %d to 0\n", *z);
            *z = 0;
            printf ("Packets sizes are now:\n%d %d %d\n", *x, *y, *z);
            *loser = 1;
        }
    }
    return *loser;
}    

        
