/* Assignment 1
   TCSS-333
   Autumn 2017
   Maryia Shautsova


   This program converts IP addresses to/from their dot decimal notation.
   User can choose next options: 
   1 allows to find IP address in decimal and binary forms,
   find subnet mask in decimal, dot decimal and binary forms, 
   and network prefix in decimal, dot decimal and binary forms,
   and host partin decimal, dot decimal and binary forms.
   2 allows to find the message address taking host part and network prefix as input
   3 (extra credit) allows given 32-bit decimal number for IP address and for subnet mask 
   into dot-decimal and binary forms.
*/

   #include <stdio.h>
   #define CONST 4294967295;
   unsigned int asDecimal(unsigned char m1, unsigned char m2, unsigned char m3,unsigned char m4);
   unsigned int asBin(unsigned int num);
   int getResult();
   

   int main (void)
{

	char command = 'r'; 
	getResult();
	printf("\n");
	printf("Enter r to repeat, q to quit:"); //commands that allows user to repeat the program again or just quit
	scanf("%c", &command);
	getchar();
	if(command =='r'|| command =='R')
	{
	  		main();
	}
}
/*****************************************************************************************
A method to convert given number  into decimal form

******************************************************************************************/
unsigned int asDecimal(unsigned char m1, unsigned char m2,unsigned char m3,unsigned char m4){

 	unsigned int x1 =0;   

	unsigned int temp;


    x1 = x1|m1;
   	
    temp = x1<<8;

    temp = temp|m2;

    temp = temp<<8;

    temp = temp|m3;


    temp = temp<<8;

    temp = temp|m4;

    return temp;
	

}
/**********************************************************
A method to represent given number in the binary form
**********************************************************/
 unsigned int asBin(unsigned int num)
 {
 	int i;
 	for (i=31; i>0; i--)
 	{
 		printf("%u", (num&(1<<i))>>i);

 		if((i%8)==0)
 		{
 			printf("%c",' ');
 		}


    }

 	return 0;
}


/*************************************************
A method to make all necessary calculations
************************************************/
int getResult()
{




	int rm;
	unsigned int  mask, n, npb, ipb;
	unsigned int ocm, hp;
	int h1, h2, h3, h4;
	int pre1, pre2, pre3, pre4;
	unsigned int ipad;
	int choice, host, pref;
	int binip;
	unsigned int ip1, ip2, ip3, ip4;
	unsigned int decip, decmas;
	


/********************************************************
Dialog with user asking to choose the type of conversion
*********************************************************/
	printf("What type of conversion do you want?\n");
	printf("Enter 1 for IP-address and subnet, 2 for the host and network prefix, or 3 for more IP-address and subnet ;\n");
	scanf("%d", &choice);
	getchar();

	switch (choice)
		{

		
		case (1): //if user chose the first type of conversion
		
			

			printf("Enter the message address:");
			scanf("%d.%d.%d.%d/%d", &ip1, &ip2, &ip3, &ip4, &rm); //getting the input

			
			while (ip1<0 || ip1>255 || ip2<0 || ip2>255 || ip3<0 || ip3>255 || ip4<0 || ip4>255 || rm<0 || rm>32) //checks if input values are in their ranges
			{
				printf("Wrong address, try again:\n");
				scanf("%d.%d.%d.%d/%d", &ip1, &ip2, &ip3, &ip4, &rm);
			}
			
			getchar();
			ipb = asDecimal(ip1, ip2, ip3, ip4); //represents Ip address in the decimal form


			printf("The IP-address is: %u in decimal and\n", ipb);

			binip = asBin(ipb);//represents Ip address in the binary form
			printf("%u in binary\n", binip);
			printf("\n");

			//Subnet mask calucalation according to the routed mask that was inputed by user
			int b = 32 -rm;			
			unsigned int temper = CONST;
			unsigned int result = temper<<b;

			//Represents the subnet mask in the dot-decimal form		
			unsigned char m1 = 0;
			unsigned char m2 = 0;
			unsigned char m3 = 0;
			unsigned char m4 = 0;
			m1 = result|m1;
			//printf("m1:%u\n", m1);
			unsigned int t1 = result>>8;
			//printf("res1:%u\n", t1);
			m2 = t1|m2;
			//printf("m2:%u\n", m2);
			t1 = t1>>8;
			//printf("res2:%u\n", t1);
			m3 = t1|m3;
			//printf("m3:%u\n", m3);
			t1 = t1>>8;
			//printf("res3:%u\n", t1);
		    m4 = t1|m4;
			//printf("m4:%u\n", m4);

			
			printf("The subnet mask is: %u in decimal and\n", result);
			printf("%u in binary\n", asBin(result)); //represents the subnet mask in the binary form

         	printf ("The subnet mask in dot-decimal is: %u.%u.%u.%u\n", m4, m3, m2, m1);
         	printf("\n");

		    npb = asDecimal(ip1&m4, ip2&m3, ip3&m2, ip4&m1);//represents network prefix in the decimal form
			
         	printf("The network prefix is: %u in decimal and\n", npb);
         	printf("%u  in binary\n", asBin(npb));//represents the network prefix in the binary form
         	printf ("The network prefix in dot-decimal is: %u.%u.%u.%u\n", ip1&m4, ip2&m3, ip3&m2, ip4&m1);
          	printf("\n");


          	ocm=~result; //calculating one's complement of the subnet mask
          	hp = ipb&ocm; //the host id in the dot-decimal form
         	
       	    //Represents the host part in the dot-decimal form	    
 		 	unsigned char x1=0;
 		 	unsigned char x2=0;
 		 	unsigned char x3=0;
 		 	unsigned char x4=0;
 		 	unsigned int temp =0;
 		 	x1 = hp|x1;
 		// 	//printf("x1:%u\n", x1);
 		 	temp = hp>>8; 	
 		// 	//printf("temp:%u\n", temp);		
 		 	x2 = x2|temp; 
 		// 	//printf("x2:%u\n", x2);			
 		 	temp = temp>>8;
 		// 	//printf("temp:%u\n", temp);	
 		 	x3 = x3|temp;
 		// 	//printf("x3:%u\n", x3);
 		 	temp = temp>>8;
 		// 	//printf("temp:%u\n", temp);	
 		 	x4 =x4|temp;
 		// 	//printf("x4:%u\n", x4);





          	printf("The host id is: %u in decimal and\n", hp);
          	printf("%u in binary\n", asBin(hp));//represents the host part in the binary form
          	printf ("The host id in dot-decimal is: %u.%u.%u.%u\n", x4, x3, x2, x1);
          	printf("\n");

         	break;

         





		//}


		case (2): //if user chose the second type of conversion


			printf("Enter the host:");
			scanf("%d.%d.%d.%d", &h1,&h2,&h3,&h4);//getting the input
			getchar();
			printf("Enter the network prefix:");
			scanf("%d.%d.%d.%d", &pre1, &pre2, &pre3, &pre4);//getting the input
			getchar();
			host = asDecimal(h1, h2, h3, h4);//represents the host part in the decimal form

			pref = asDecimal(pre1, pre2, pre3, pre4);//represents the network prefix in the binary form
			ipad = pref|host;//calculationg of the ip component for the message address


			//Represents the IP address in the dot-decimal form	
 			unsigned char y1=0;
 			unsigned char y2=0;
 			unsigned char y3=0;
 			unsigned char y4=0;
 			unsigned int temp1 =0;
 			y1 = ipad|y1;
 			//printf("x1:%u\n", x1);
 			temp1 = ipad>>8; 	
 			//printf("temp:%u\n", temp);		
 			y2 = y2|temp1; 
 			//printf("x2:%u\n", x2);			
 			temp1 = temp1>>8;
 			//printf("temp:%u\n", temp);	
 			y3 = y3|temp1;
 			//printf("x3:%u\n", x3);
 			temp1 = temp1>>8;
 			//printf("temp:%u\n", temp);	
 			y4 =y4|temp1;
 			//printf("x4:%u\n", x4);
 			
 			//calculating mask component for the message address
 			unsigned int mask =1;
 			unsigned int res=0; 
 			int count =0;
 			int i =0;	
 			int maska =0;

 			
 				while(i<32)
 				{
 					
 						i++;

 						//res = pref&mask;
 						//mask = mask<<i;
 						//printf("%u\n", pref);
 					
 						res = (pref&(1<<i))>>i;
 						//if (res =0){
 							count++;
 						//}
 						//count++;
 				
 					if (res ==1)
 					{
 							break;
 					}
 						//printf("count:%d\n", count);
 						//printf("res:%u\n", res);

 					
 						

 				}
 				

 			
 				
 			
 		
 			
 			maska =32 -count;
 			
 			printf("The message is: %u.%u.%u.%u/%d\n", y4, y3, y2, y1, maska);

 			
 			break;
		//}

 		case(3)://if user chose the third type of conversion

		printf("Enter the IP-address as a 32-bits decimal number:");
		scanf("%u", &decip);
		getchar();
		printf("Enter the subnet mask as a 32-bits decimal number:");
		scanf("%u", &decmas);
		getchar();
		
		//Represents the IP address in the dot-decimal form	
 		unsigned char a1=0;
 		unsigned char a2=0;
 		unsigned char a3=0;
 		unsigned char a4=0;
 		unsigned int  var =0;
 		a1 = decip|a1;
 		// 	//printf("x1:%u\n", x1);
 		var = decip>>8; 	
 		// 	//printf("temp:%u\n", temp);		
 		a2 = a2|var; 
 		// 	//printf("x2:%u\n", x2);			
 		var = var>>8;
 		// 	//printf("temp:%u\n", temp);	
 		a3 = a3|var;
 		// 	//printf("x3:%u\n", x3);
 		var = var>>8;
 		// 	//printf("temp:%u\n", temp);	
 		a4 =a4|var;


 		
 		printf("The Ip-address in dot decimal is: %u.%u.%u.%u and\n", a4,a3,a2,a1);
 		printf("%u in binary\n", asBin(decip));
 		printf("\n");


 		//Represents the subnet mask in the dot-decimal form	
 		unsigned char b1=0;
 		unsigned char b2=0;
 		unsigned char b3=0;
 		unsigned char b4=0;
 		unsigned int  var1 =0;
 		b1 = decmas|b1;
 		// 	//printf("x1:%u\n", x1);
 		var1 = decmas>>8; 	
 		// 	//printf("temp:%u\n", temp);		
 		b2 = b2|var1; 
 		// 	//printf("x2:%u\n", x2);			
 		var1 = var1>>8;
 		// 	//printf("temp:%u\n", temp);	
 		b3 = b3|var1;
 		// 	//printf("x3:%u\n", x3);
 		var1 = var1>>8;
 		// 	//printf("temp:%u\n", temp);	
 		b4 =b4|var1;
 		printf("The subnet mask in dot decimal is: %u.%u.%u.%u and\n", b4,b3,b2,b1);
 		printf("%u in binary\n", asBin(decmas));

			break;
		}





}

