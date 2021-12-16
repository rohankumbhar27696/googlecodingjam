//https://codejam.googleapis.com/dashboard/get_file/AQj_6U2-09XEu6CohyhxhxlREfZpFUEbJoHD1aQr/Solution.c

#include "stdio.h"

long long int mypow(long long int num ,long long  int pow1);
long long int arrtoint(long long int *num ,long long  int len );
long long int find_closest_even_no(long long int num);

int main()
{
	int test_no = 0;
	long int num = 0;

	scanf("%d",&test_no);


	for(int i = 0 ; i < test_no ; i++ )
	{
		long long int ret = 0;

		scanf("%ld",&num);
		//printf("%ld\n",num );
		ret = find_closest_even_no(num);
		//printf("ret = %lld \n", ret );
		
		if(ret > num)
		{
			printf("Case #%d: %lld\n", i+1 , ret-num );
		}
		else if( ret < num )
		{
			printf("Case #%d: %lld\n", i+1 , num-ret );
		}
		else
		{
			printf("Case #%d: %lld\n", i+1 , ret-num );
		}

	}

}



long long int mypow(long long int num ,long long  int pow1)
{
	long long int sum = 1;
	//printf("pow === %d \n",pow1);
	if(pow1 == 0 )
	{
		return 1;
	}
	for(int i = 0 ; i < pow1 ; i++)
	{
		sum = sum * num;
	}
	//printf("sum = %d \n",sum );

	return sum;
}

long long int arrtoint(long long int *num ,long long  int len )
{
	long long int sum = 0 ; 
	//printf("arrint %d\n",len );
	for( long long  int  i = 0 ;  i < len ; i++ )
	{
		//printf("num[%d]  == %d \n", i,num[i] );
		if(num[i] == 0  && i == 0)
		{
			continue;
		}

		sum = sum +(long long) num[i]*mypow(10,len-i-1) ;

	}
   // printf("arrintsum %lld\n",sum );
	return sum;
}


long long int find_closest_even_no(long long int num)
{
	long long int arr1[20] = {0}, arr1len=0;
	long long int arr2[20] = {0}, arr2len=0;

	long long int dirflag = 0;
	long long int temp = num;
	long long int evenlen = 0;

	long long int diff1 = 0 ,diff2 = 0 ,diff3 =0;

	while( temp != 0)
	{
		arr1[ arr1len++ ] = temp % (long long)10 ;
		temp = temp /(long long) 10 ; 
	}
	//printf("len %lld\n",arr1len );

	// printf("num \n");
	// for(int i = 0; i < arr1len ;i++)
	// {
	// 	printf("%lld ",arr1[i]);
	// }
	// printf("\n");


	for( long long int i = arr1len-1 ; i >= 0 ; i-- )
	{
		//printf("arr1[ %lld ] = %lld\n", i ,arr1[i] );
		if(	arr1[i] == 1 && i == arr1len-1  && 0)
		{
			dirflag = 0;
			arr2[ arr2len++ ] = 0;
			arr2[ arr2len++ ] = 8;
			break;

		}
		else if( arr1[ i ] % 2 == 0 )
		{
			arr2[ arr2len++ ] = arr1[i];
			evenlen++;
		}
		else if( arr1[ i ] % 2 != 0)
		{



			arr2[ arr2len ] = arr1[i] + 1 ;

			temp = arrtoint(arr2,arr1len);
			if(arr1[i] == 9 )
			{
				arr2[ arr2len + 0 ] = 8;
				//arr2[ arr2len + 1]  = 0;

				temp = arrtoint(arr2,arr1len);

 			}


			//temp = arrtoint(arr2,arr1len);

			// printf("NUM2 = ");
			// for( int h = 0 ; h < arr1len ; h++)
			// {	
			// 	printf("%lld ",arr2[h]);
			// }


			//printf("add = %lld  %lld \n", temp , arr1len );

			if( num >= temp )
			{
				diff1 = num - temp ;
			}
			else
			{
				diff1 = temp - num ;
			}



			// printf("temp = %lld  num = %lld \n",temp,num );
			// printf("diff1 = %lld \n",diff1 );


			if(arr1[i] != 1)
			{
				arr2[ arr2len ] = arr1[i] - 1 ;


				for(int l = arr2len+1 ; l < arr1len ; l++)
				{
					//printf("l = %d \n", );
					arr2[ l ] = 8;
				}



				temp = arrtoint(arr2,arr1len);

			}
			else
			{
				arr2[ arr2len+0 ] = 0 ;
				arr2[ arr2len +1] = 8 ;

				temp = arrtoint(arr2,arr1len);

			}
			//printf("sub = %d \n", temp );





			// printf("NUM2 = ");
			// for( int h = 0 ; h < arr1len ; h++)
			// {	
			// 	printf("%lld ",arr2[h]);
			// }
			// printf("\n");

			// printf("temp = %lld  num = %lld \n",temp,num );

			if( num >= temp )
			{
				diff2 = num - temp ;
			}
			else
			{
				diff2 = temp - num ;
			}

			// printf("diff2 = %lld \n",diff2 );


			if(diff2 >= diff1)
			{
				dirflag =1;
				
				if(arr1[i] == 9 )
				{
					arr2[ arr2len++ ] = 8;
					//arr2[ arr2len++ ]  = 0;

					temp = arrtoint(arr2,arr1len);
					//printf("temp = %lld\n",temp );
					//arr1len++;
	 			}
	 			else
	 			{
	 				arr2[ arr2len++ ] = arr1[i] + 1 ;
	 			}

			}
			else
			{
				dirflag =0;

				if( arr1[i] == 1 )
				{
					arr2[ arr2len++ ] = 0 ;
					arr2[ arr2len++] = 8 ;

					temp = arrtoint(arr2,arr1len);

					//printf("temp1 = %lld\n",temp );
				}
				else
				{
					arr2[ arr2len++ ] = arr1[i] - 1 ;
				}	


			}

			break;

		}
		else
		{
			printf("WRONG1\n");

		}


	}


	if( dirflag && arr1len != evenlen )
	{
		int prev_value = 0;
		for(int i = arr2len ; i < arr1len ; i++ )
		{
				for(int j =0 ; j < 9 ;  )
				{
					arr2[i] = j;

					temp = arrtoint(arr2,arr1len);	

					diff3 = temp -num;
					//printf("diff31 - %lld %lld \n",temp ,diff3 );

					if(diff1 >= diff3)
					{
						prev_value = j ;
						diff1 = diff3;
						arr2[i] = j;
					}
					else
					{
						arr2[i] = prev_value;
						break;
					}
							

					j =j+2;

				}

		}

		temp = arrtoint(arr2,arr1len);	
		return  temp;

	}
	else if( dirflag ==0  && arr1len != evenlen)
	{
		long long int prev_value = 0;
		for(long long int i = arr2len ; i < arr1len ; i++ )
		{
			///printf("arr2[%lld] = %lld \n",i,arr2[i] );
				for(long long int j =8 ; j >= 0 ;  )
				{
					arr2[i] = j;
					temp = arrtoint(arr2,arr1len);	

					diff3 = num -temp;
					//printf("diff3 - %lld %lld %lld \n",temp ,diff3 ,diff2);


					if(diff2 >= diff3)
					{
						prev_value = j ;
						diff2 = diff3;
						arr2[i] = j;
					}
					else
					{
						arr2[i] = prev_value;
						break;
					}	

					j = j-2;				

				}
		}

		temp = arrtoint(arr2,arr1len);	
		return  temp;



	}
	else if( arr1len == evenlen)
	{
		temp = arrtoint(arr2,arr1len);	
		return  temp;
	}
	else
	{
		printf("WRONG2\n");
		return 0;
	}



}
