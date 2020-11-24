/*Toma Andrei 311CB*/
#include<stdio.h>
#define MAX 500
#define DIM 4
#define MASCA 128
#define SIZE_OF_CHAR 8


int main()
{
	/*-----------DECLARAREA VARIABILELOR-----------*/

	int N, MSK_2, j, contor, q, K=0, c, i=0, OK=1, ct=-1, ck=-1, cj=0;
	unsigned char IP_1[DIM], IP_2[DIM], MSK_1[DIM], NET[MAX][5], MSK_2_10[DIM],
	AD_R_1[DIM], AD_R_2[DIM], AD_B_1[DIM];
	scanf ("%d", &contor);
	for (q=0;q<contor;q++)
	{	
		/*-----------CITIREA ADRESEI IP SI A MASTILOR-----------*/

		scanf ("%hhu.%hhu.%hhu.%hhu", &MSK_1[0],&MSK_1[1],&MSK_1[2],&MSK_1[3]);
		scanf ("%d", &MSK_2);
		scanf ("%hhu.%hhu.%hhu.%hhu", &IP_1[0],&IP_1[1],&IP_1[2],&IP_1[3]);
		scanf ("%hhu.%hhu.%hhu.%hhu", &IP_2[0],&IP_2[1],&IP_2[2],&IP_2[3]);
		scanf ("%d", &N);
		for (j=0;j<N;j++)
			scanf ("%hhu.%hhu.%hhu.%hhu/%hhu", &NET[j][0], &NET[j][1], 
				&NET[j][2], &NET[j][3], &NET[j][4]);
		printf ("1\n");

		/*------------TASK 0------------*/

		printf("-0 ");
		printf ("%hhu.%hhu.%hhu.%hhu/%d\n", IP_1[0], IP_1[1], IP_1[2], 
			IP_1[3], MSK_2);//afisare cu printf

		/*------------TASK 1------------*/

		printf("-1 ");
		//vector pentru scrierea in baza zece a mastii 2
		MSK_2_10[0]=0;MSK_2_10[1]=0;MSK_2_10[2]=0;MSK_2_10[3]=0; 
		K=0;c=MSK_2;i=0;
		while (c>0)
		{
			MSK_2_10[K]=((MSK_2_10[K]) | (MASCA>>i));
			if (i==7)
			{
				i=-1;
				K++;
			}
			c--;
			i++;

		}
		printf ("%hhu.%hhu.%hhu.%hhu\n", MSK_2_10[0], MSK_2_10[1], 
			MSK_2_10[2], MSK_2_10[3]);
		
		/*------------TASK 2------------*/

		printf ("-2 ");
		printf ("%o.%o.%o.%o ", MSK_1[0],MSK_1[1],MSK_1[2],MSK_1[3]);
		//%o afiseaza numarul in baza 8
		printf ("%X.%X.%X.%X\n", MSK_1[0], MSK_1[1], MSK_1[2],MSK_1[3]);
		//%X afiseaza numarul in baza 16 (cu majuscule)

		/*------------TASK 3------------*/

		printf ("-3 ");
		for (j=0;j<DIM;j++)
			/*& logic intre elementele adresi IP_1 si ale MSK_2 scrisa in baza 
			10 pentru a obtine adresa de retea*/
			AD_R_1[j]=((IP_1[j]) & (MSK_2_10[j]));
		printf("%hhu.%hhu.%hhu.%hhu\n", AD_R_1[0],AD_R_1[1],AD_R_1[2],AD_R_1[3]);

		/*-------------------------TASK 4-------------------------*/

		printf ("-4 ");
		for (j=0;j<DIM;j++)
			/*| logic intre elementele adresei ip_1 si ale MSK_2 scrisa in baza 
			10 pentru a obtine adresa de broadcast a ip_ului 1*/
			AD_B_1[j]=((IP_1[j]) | (~(MSK_2_10[j])));
		printf("%hhu.%hhu.%hhu.%hhu\n", AD_B_1[0],AD_B_1[1],AD_B_1[2],AD_B_1[3]);

		/*------------TASK 5------------*/

		printf ("-5 ");
		AD_R_2[0]=0;AD_R_2[1]=0;AD_R_2[2]=0;AD_R_2[3]=0;
		OK=1;
		for (j=0;j<DIM;j++)
			//calculare adresa de retea a ip_2
			AD_R_2[j]=((IP_2[j]) & (MSK_2_10[j]));
		for(j=0;j<DIM;j++)
			if (AD_R_1[j]!=AD_R_2[j])/*comparatie intre adresa de retea a 
			ip-ului 1 si a ip-ului 2 pentru*/
			{
				OK=0;
				break;
			}
		if (OK==1)
			printf ("DA\n");
		else
			printf ("NU\n");

		/*------------TASK 6------------*/

		printf ("-6 ");
	 	ct=0;ck=-1;cj=-1;/*variabile care vor determina pozitia primului 0 din
	 	MSK_1*/
		OK=1;
		/*in acest pas vom determina prezenta primului 0*/
		for (K=0;K<DIM;K++)
			{
				for (j=0;j<SIZE_OF_CHAR;j++)
					if (((MSK_1[K]) & (MASCA>>j))==0)
					{ 	
						ck=K;
						cj=j;
						ct=1;
						break;
					}
			if (ct==1)
				break;
			}
		/*daca din pozitia primului 0 gaseste o valoare care este diferita de
		de 0 inseamna ca masca nu este corect scrisa*/
		for (j=cj+1;j<SIZE_OF_CHAR;j++)
			if (((MSK_1[ck]) & (MASCA>>j))!=0)
				{
					OK=0;break;
				}

		if ((ck!=-1) & (cj!=-1))
				{
					for (i=ck+1;i<DIM;i++)
						for (j=0;j<SIZE_OF_CHAR;j++)
							if (((MSK_1[i]) & (MASCA>>j))!=0)
							{
								OK=0;break;
							}
				}

		if (OK==1)
			printf ("DA\n");
		else
			printf ("NU\n");

		/*------------TASK 7------------*/

		printf ("-7 ");
		if (OK==1)
			printf("%hhu.%hhu.%hhu.%hhu\n", MSK_1[0],MSK_1[1],MSK_1[2],MSK_1[3]);
		else /*se vor schimba in 0 toate elementele aflate dupa primul 0*/
		{
			for (j=cj+1;j<SIZE_OF_CHAR;j++)
				MSK_1[ck]=((MSK_1[ck]) & (~(MASCA>>j)));
			for (i=ck+1;i<DIM;i++)
				for (j=0;j<SIZE_OF_CHAR;j++)
					MSK_1[i]=((MSK_1[i]) & (~(MASCA>>j)));
			printf("%hhu.%hhu.%hhu.%hhu\n", MSK_1[0],MSK_1[1],MSK_1[2],MSK_1[3]);

		}

		/*------------TASK 8------------*/

		printf ("-8 ");
		for (i=0;i<DIM;i++)
			for (j=0;j<SIZE_OF_CHAR;j++)
			{
				if (((IP_1[i]) & (MASCA>>j))!=0)
					printf ("1");
				else
					printf ("0");
				if ((j==7) & (i!=3))
					printf (".");/*pentru despartirea comp ip-ului scris in baza
					binara*/
			}
		printf ("\n");

		/*------------TASK 9------------*/

		printf ("-9 ");
		for (j=0;j<N;j++)
		{
			MSK_2_10[0]=0;MSK_2_10[1]=0;MSK_2_10[2]=0;MSK_2_10[3]=0;
			AD_R_2[0]=0;AD_R_2[1]=0;AD_R_2[2]=0;AD_R_2[3]=0; 
			K=0; c=NET[j][4]; i=0; OK=1;
			while (c>0) /*algoritmul asemanator cu task 1 pentru transformarea
			mastii in baza 10*/
			{
				MSK_2_10[K]=((MSK_2_10[K]) | (MASCA>>i));
				if (i==7)
				{
					i=-1;
					K++;
				}
				c--;
				i++;
			}
			for (i=0;i<DIM;i++)
				/*calcularea adresei de retea pentru NET*/
				AD_R_2[i]=((IP_2[i]) & (MSK_2_10[i]));
			for (i=0;i<DIM;i++)
			{
				/*verificare daca adresa de retea a lui NET este corecta*/ 
				if ((AD_R_2[i]) != ((MSK_2_10[i]) & (NET[j][i])))
						OK=0;
			}
			if (OK==1)
			{
				printf ("%d", j);
				if (j<N-1)
					printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
	/*------------THE END------------*/
}