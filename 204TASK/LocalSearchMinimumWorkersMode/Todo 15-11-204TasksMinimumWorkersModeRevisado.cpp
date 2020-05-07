#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define aux 4
#define Time 1500

/*DECLARACION DE VARIABLES*/
	int main() 													{	

		int NumberOfTasks=204, SolutionIterations=0, NumberOfAreas=0, DesiredSolutions=40000, NumberOfProfiles=0, Area1Capacity=0, Area2Capacity=0, Area3Capacity=0, k=0, j=0, i=0, m=0, l=0, Aux1=0, Aux2=0, Aux3=0, Aux4=0, Aux5=0, Aux6=0, Aux7=0, Aux8=0,
		Area1_1Results[Time], Area1_2Results[Time],Area1_3Results[Time],Area1_4Results[Time],Area1_5Results[Time],
		Area2_1Results[Time], Area2_2Results[Time],Area2_3Results[Time],
		Area1_1ResultsTask[Time], Area1_2ResultsTask[Time], Area1_3ResultsTask[Time], Area1_4ResultsTask[Time], Area1_5ResultsTask[Time],
		Area2_1ResultsTask[Time], Area2_2ResultsTask[Time], Area2_3ResultsTask[Time],
		AuxiliarArea1_1Results[Time], AuxiliarArea1_2Results[Time],AuxiliarArea1_3Results[Time],AuxiliarArea1_4Results[Time],AuxiliarArea1_5Results[Time],
		AuxiliarArea2_1Results[Time], AuxiliarArea2_2Results[Time],AuxiliarArea2_3Results[Time],
		AuxiliarArea1_1ResultsTask[Time], AuxiliarArea1_2ResultsTask[Time], AuxiliarArea1_3ResultsTask[Time], AuxiliarArea1_4ResultsTask[Time], AuxiliarArea1_5ResultsTask[Time],
		AuxiliarArea2_1ResultsTask[Time], AuxiliarArea2_2ResultsTask[Time], AuxiliarArea2_3ResultsTask[Time],
		AuxiliarArea1_1Occupancy=0, AuxiliarArea1_2Occupancy=0, AuxiliarArea1_3Occupancy=0, AuxiliarArea1_4Occupancy=0, AuxiliarArea1_5Occupancy=0, AuxiliarArea2_1Occupancy=0, AuxiliarArea2_2Occupancy=0, AuxiliarArea2_3Occupancy=0, 
		Area1_1Occupancy=0, Area1_2Occupancy=0, Area1_3Occupancy=0, Area1_4Occupancy=0, Area1_5Occupancy=0, Area2_1Occupancy=0, Area2_2Occupancy=0, Area2_3Occupancy=0, 
		Area1_1StartInThisArea[Time*2], Area1_1EndInThisArea[Time*2], Area1_2StartInThisArea[Time*2], Area1_2EndInThisArea[Time*2], Area1_3StartInThisArea[Time*2], Area1_3EndInThisArea[Time*2], Area1_4StartInThisArea[Time*2], Area1_4EndInThisArea[Time*2], Area1_5StartInThisArea[Time*2], Area1_5EndInThisArea[Time*2],Area2_1StartInThisArea[Time*2], Area2_1EndInThisArea[Time*2], Area2_2StartInThisArea[Time*2], Area2_2EndInThisArea[Time*2], Area2_3StartInThisArea[Time*2], Area2_3EndInThisArea[Time*2], 
		MakespamInIteration[DesiredSolutions],
		SolutionTask[NumberOfTasks], SolutionStart[NumberOfTasks], SolutionEnd[NumberOfTasks],
		AuxiliarSolutionTotalStart[NumberOfTasks], AuxiliarSolutionTotalEnd[NumberOfTasks], 
		SEED=0, StopCounter=0, Solution=0, Makespam=10000, ScheduleEarlyStart[NumberOfTasks], 
		ScheduleStart[NumberOfTasks], ScheduleEnd[NumberOfTasks], ScheduledTask[NumberOfTasks], 
		TotalOperatorsOfProfile1=5, TotalOperatorsOfProfile2=3, OperatorsInArea1[NumberOfTasks][aux], OperatorsInArea2[NumberOfTasks][aux], MinimumOperators[NumberOfTasks], MaximumOperators[NumberOfTasks],
		PrecedencePredeccessor[NumberOfTasks], NumberOfPrecedenceSuccessors[NumberOfTasks], PrecedenceSuccessors[NumberOfTasks][aux],
		IncPredeccessor[NumberOfTasks], NumberOfIncSuccessors[NumberOfTasks], IncSuccessor[NumberOfTasks][aux],
		ConsecutivePredeccessor[NumberOfTasks], NumberOfConsecutiveSuccessors[NumberOfTasks], ConsecutiveSuccessor[NumberOfTasks], 
		NumberOfPredeccessors[NumberOfTasks], NumberOfThePredeccessor[NumberOfTasks][3], 
		State[NumberOfTasks],  
		ModesPredeccessor[NumberOfTasks], ModesPerTask[NumberOfTasks], Mode[NumberOfTasks][aux], Duration[NumberOfTasks][aux], OperatorsInArea3[NumberOfTasks][aux], OperatorsOfProfile1[NumberOfTasks][aux], OperatorsOfProfile2[NumberOfTasks][aux],
		GRPWNewTask=0, GRPWAuxiliar=0, GRPW[NumberOfTasks], GRPWSuccessors[NumberOfTasks][NumberOfTasks], GRPWAddLater[NumberOfTasks][NumberOfTasks],
		Profile1Resources[Time], Profile2Resources[Time], AuxiliarProfile1Resources[Time], AuxiliarProfile2Resources[Time], NumberOfIteration[DesiredSolutions],
		RandomTotalSumOfGRPWToSchedule=0, RandomChoosenNumber=0, RandomCumulative=0,
		ScheduleIterations=0, ScheduleDurationFirstConsecutive=0, ScheduleDurationSecondConsecutive=0,   
		AuxiliarProfile1, AuxiliarProfile2,
		AuxiliarProfile1FirstConsecutive, AuxiliarProfile2FirstConsecutive,
		AuxiliarProfile1SecondConsecutive, AuxiliarProfile2SecondConsecutive,
		ScheduleMakespam=0, ScheduleInstant=0,
		AuxiliarCounter1=0, AuxiliarCounter2=0, AuxiliarCounter3=0;
		float ExecutionTime=0,	StartTime=clock(),	Area1_1TotalOccupancy=0, Area1_2TotalOccupancy=0, Area1_3TotalOccupancy=0, Area1_4TotalOccupancy=0, Area1_5TotalOccupancy=0, Area2_1TotalOccupancy=0, Area2_2TotalOccupancy=0, Area2_3TotalOccupancy=0;
	
	for(i=0; i<DesiredSolutions; i++)		{
	
		MakespamInIteration[i]=0;
		NumberOfIteration[i]=0;	
	
										}
		
	for(i=0; i<NumberOfTasks; i++)						{
		
		MinimumOperators[i]=0, MaximumOperators[i]=0,
		PrecedencePredeccessor[i]=0, NumberOfPrecedenceSuccessors[i]=0;
		IncPredeccessor[i]=0, NumberOfIncSuccessors[i]=0,
		ConsecutivePredeccessor[i]=0, NumberOfConsecutiveSuccessors[i]=0, ConsecutiveSuccessor[i]=0;
		NumberOfPredeccessors[i]=0;
		ModesPredeccessor[i]=0, ModesPerTask[i]=0;
		GRPW[i]=0, State[i]=1;
		SolutionTask[i]=0, SolutionStart[i]=0, SolutionEnd[i]=0;
							
		
			for(j=0; j<aux+1; j++)						{
				
				 IncSuccessor[i][j]=0, PrecedenceSuccessors[i][j]=0, NumberOfThePredeccessor[i][j]=0, Mode[i][j]=0, Duration[i][j]=0, OperatorsInArea1[i][j]=0, OperatorsInArea2[i][j]=0, OperatorsInArea3[i][j]=0, OperatorsOfProfile1[i][j]=0, OperatorsOfProfile2[i][j]=0;
				
														}
													
			for(k=0; k<NumberOfTasks; k++)			{
				
				GRPWSuccessors[i][k]=0, GRPWAddLater[i][k]=204;
				
													}
														}
/*APERTURA DEL FICHERO(INSTANCIA) DE LA QUE SE QUIERE HALLAR LA SOLUCION*/
FILE *f;	
	f = fopen("204Tasks.txt","r"); 
	
	if(f == NULL) 											{
		printf("Could not open the file.\n");
		exit(1);		
															}
					
/*ESCANEO DE DATOS Y DE PRECEDENCIAS*/
	fscanf(f,"%d %d %d", &NumberOfTasks, &NumberOfAreas, &NumberOfProfiles); 
	
		
	fscanf(f,"%d %d", &Area1Capacity, &Area2Capacity); 	
	
														
	for(i=0; i<NumberOfTasks; i++)						{
			
			fscanf(f, "%d", &MinimumOperators[i]);
														
														}
														
	for(i=0; i<NumberOfTasks; i++)						{
			
			fscanf(f, "%d", &MaximumOperators[i]);
														
														}
		
	for(i=0; i<NumberOfTasks; i++)						{
			
			fscanf(f, "%d %d", &PrecedencePredeccessor[i], &NumberOfPrecedenceSuccessors[i]);
				
				if(NumberOfPrecedenceSuccessors[i]==0) 	{
														}
				
				else if(NumberOfPrecedenceSuccessors[i]==1) 
														{
					
					fscanf(f, "%d", &PrecedenceSuccessors[i][0]);

														}				
								
				else if(NumberOfPrecedenceSuccessors[i]==2) 	
														{
					
					fscanf(f, "%d %d", &PrecedenceSuccessors[i][0], &PrecedenceSuccessors[i][1]);

														}					
								
				else if(NumberOfPrecedenceSuccessors[i]==3) 	
														{
					
					fscanf(f, "%d %d %d", &PrecedenceSuccessors[i][0], &PrecedenceSuccessors[i][1], &PrecedenceSuccessors[i][2]);
			
														}				
								
				else if(NumberOfPrecedenceSuccessors[i]==4) 	
														{
					
					fscanf(f, "%d %d %d %d", &PrecedenceSuccessors[i][0], &PrecedenceSuccessors[i][1], &PrecedenceSuccessors[i][2], &PrecedenceSuccessors[i][3]);
					
														}					
															}
															
/*ESCANEO DE RESTRICCIONES INC*/
	for(i=0; i<NumberOfTasks; i++)							{
			
			fscanf(f, "%d %d", &IncPredeccessor[i], &NumberOfIncSuccessors[i]);
				
				if(NumberOfIncSuccessors[i]==0) 		{
														}
				
				else if(NumberOfIncSuccessors[i]==1) 	
														{
					
					fscanf(f, "%d", &IncSuccessor[i][0]);
				
														}
				else if(NumberOfIncSuccessors[i]==2) 	
														{
					
					fscanf(f, "%d", &IncSuccessor[i][0]);
					fscanf(f, "%d", &IncSuccessor[i][1]);
					
														}
				else if(NumberOfIncSuccessors[i]==3) 	
														{
					
					fscanf(f, "%d", &IncSuccessor[i][0]);
					fscanf(f, "%d", &IncSuccessor[i][1]);
					fscanf(f, "%d", &IncSuccessor[i][2]);
					
														}
				else if(NumberOfIncSuccessors[i]==4) 	
														{
					
					fscanf(f, "%d", &IncSuccessor[i][0]);
					fscanf(f, "%d", &IncSuccessor[i][1]);
					fscanf(f, "%d", &IncSuccessor[i][2]);
					fscanf(f, "%d", &IncSuccessor[i][3]);
					
														}
														
															}
/*ESCANEO DE RESTRICCIONES CONSECUTIVE*/
	for(i=0; i<NumberOfTasks; i++)						{
			
			fscanf(f, "%d %d", &ConsecutivePredeccessor[i], &NumberOfConsecutiveSuccessors[i]);
				
				if(NumberOfConsecutiveSuccessors[i]==0) {		
														}
				
				else if(NumberOfConsecutiveSuccessors[i]==1&&NumberOfPrecedenceSuccessors[i]==0)	
														{
					
					fscanf(f, "%d", &ConsecutiveSuccessor[i]);
					NumberOfPrecedenceSuccessors[i]++;
					PrecedenceSuccessors[i][0]=ConsecutiveSuccessor[i];
														}
														
				else if(NumberOfConsecutiveSuccessors[i]==1&&NumberOfPrecedenceSuccessors[i]==1)	
														{
					
					fscanf(f, "%d", &ConsecutiveSuccessor[i]);
					NumberOfPrecedenceSuccessors[i]++;
					PrecedenceSuccessors[i][1]=ConsecutiveSuccessor[i];
				
														}	
															}											
	
/*ESCANEO LOS MODOS*/															
	for(i=0; i<NumberOfTasks; i++)				{
			
			fscanf(f, "%d %d", &ModesPredeccessor[i], &ModesPerTask[i]);			
		
												}	
																									
	for(i=0; i<NumberOfTasks; i++)				{
		
		if (ModesPerTask[i]==1)				{
					
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][0], &Duration[i][0], &OperatorsInArea1[i][0], &OperatorsInArea2[i][0], &OperatorsOfProfile1[i][0], &OperatorsOfProfile2[i][0]);
				
											}
				
	else if (ModesPerTask[i]==2)			{
					
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][0], &Duration[i][0], &OperatorsInArea1[i][0], &OperatorsInArea2[i][0], &OperatorsOfProfile1[i][0], &OperatorsOfProfile2[i][0]);
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][1], &Duration[i][1], &OperatorsInArea1[i][1], &OperatorsInArea2[i][1], &OperatorsOfProfile1[i][1], &OperatorsOfProfile2[i][1]);
				
											}
								
	else if (ModesPerTask[i]==3)			{
					
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][0], &Duration[i][0], &OperatorsInArea1[i][0], &OperatorsInArea2[i][0], &OperatorsOfProfile1[i][0], &OperatorsOfProfile2[i][0]);
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][1], &Duration[i][1], &OperatorsInArea1[i][1], &OperatorsInArea2[i][1], &OperatorsOfProfile1[i][1], &OperatorsOfProfile2[i][1]);
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][2], &Duration[i][2], &OperatorsInArea1[i][2], &OperatorsInArea2[i][2], &OperatorsOfProfile1[i][2], &OperatorsOfProfile2[i][2]);
				
											}				
				
								
	else if (ModesPerTask[i]==4)			{
					
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][0], &Duration[i][0], &OperatorsInArea1[i][0], &OperatorsInArea2[i][0], &OperatorsOfProfile1[i][0], &OperatorsOfProfile2[i][0]);
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][1], &Duration[i][1], &OperatorsInArea1[i][1], &OperatorsInArea2[i][1], &OperatorsOfProfile1[i][1], &OperatorsOfProfile2[i][1]);
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][2], &Duration[i][2], &OperatorsInArea1[i][2], &OperatorsInArea2[i][2], &OperatorsOfProfile1[i][2], &OperatorsOfProfile2[i][2]);
			fscanf(f, "%d %d %d %d %d %d %d", &ModesPredeccessor[i], &Mode[i][3], &Duration[i][3], &OperatorsInArea1[i][3], &OperatorsInArea2[i][3], &OperatorsOfProfile1[i][3], &OperatorsOfProfile2[i][3]);
				
											}					
												}		

/*HALLAMOS LAS TAREAS CON MAS DE UN PREDECESOR*/
	for(i=0; i<NumberOfTasks; i++)							{
			
				if(NumberOfPrecedenceSuccessors[i]==0) 	{	
														}
				
				else if(NumberOfPrecedenceSuccessors[i]==1) 
														{
					
					NumberOfPredeccessors[PrecedenceSuccessors[i][0]]++;
					
														}				
								
				else if(NumberOfPrecedenceSuccessors[i]==2) 
														{
					
					NumberOfPredeccessors[PrecedenceSuccessors[i][0]]++;
					NumberOfPredeccessors[PrecedenceSuccessors[i][1]]++;		
					
														}					
								
				else if(NumberOfPrecedenceSuccessors[i]==3) 
														{
					
					NumberOfPredeccessors[PrecedenceSuccessors[i][0]]++;
					NumberOfPredeccessors[PrecedenceSuccessors[i][1]]++;
					NumberOfPredeccessors[PrecedenceSuccessors[i][2]]++;
			
														}				
								
				else if(NumberOfPrecedenceSuccessors[i]==4) 
														{
					
					NumberOfPredeccessors[PrecedenceSuccessors[i][0]]++;
					NumberOfPredeccessors[PrecedenceSuccessors[i][1]]++;
					NumberOfPredeccessors[PrecedenceSuccessors[i][2]]++;
					NumberOfPredeccessors[PrecedenceSuccessors[i][3]]++;
					
														}					
															}

/*ALMACENAMOS LOS PREDECESORES*/
	for(i=0; i<NumberOfTasks; i++)						{
		m=0;
		if(NumberOfPredeccessors[i]==2||NumberOfPredeccessors[i]==3)		{
			
			for(j=0; j<NumberOfTasks; j++)			{
					
				if((NumberOfPrecedenceSuccessors[j]==1&&PrecedenceSuccessors[j][0]==i)||(NumberOfPrecedenceSuccessors[j]==2&&(PrecedenceSuccessors[j][0]==i||PrecedenceSuccessors[j][1]==i))||(NumberOfPrecedenceSuccessors[j]==3&&(PrecedenceSuccessors[j][0]==i||PrecedenceSuccessors[j][1]==i||PrecedenceSuccessors[j][2]==i))||(NumberOfPrecedenceSuccessors[j]==4&&(PrecedenceSuccessors[j][0]==i||PrecedenceSuccessors[j][1]==i||PrecedenceSuccessors[j][2]==i||PrecedenceSuccessors[j][3]==i)))
				
												{
						
					NumberOfThePredeccessor[i][m]=j;
					m++;
					
												}
													}
														}
															}

		for(i=0; i<NumberOfTasks; i++)		{
	
				GRPW[i]=0;
			
				for(m=0; m<100; m++)	{
		
				GRPWSuccessors[i][m]=204;
				GRPWAddLater[i][m]=204;
										}
											}

	for(i=0; i<NumberOfTasks; i++)																							{
		k=0;

	 /*NO QUIERO QUE SALGA DE AQUI HASTA QUE SE SUMEN TODAS LAS TAREAS*/
 		
			GRPWNewTask=i;
 			m=0;
 			GRPWSuccessors[i][m]=GRPWNewTask;
 								
 								
 								if(NumberOfPrecedenceSuccessors[GRPWNewTask]==1) 		{
									j=GRPWNewTask;
													
/*ESTAS DOS LINEAS SON PARA QUE PILLE EL SIGUIENTE SUCESOR*/
								
									GRPWNewTask=PrecedenceSuccessors[j][0];
									m=0;		
																	}	
								
								else if	(NumberOfPrecedenceSuccessors[GRPWNewTask]==2)  {
									
									j=GRPWNewTask;		
											
/*ESTAS DOS LINEAS SON PARA QUE PILLE EL SIGUIENTE SUCESOR*/
									
									GRPWNewTask=PrecedenceSuccessors[j][0];
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][1];
									k++;
									GRPWAuxiliar=k;
									m=0;
																	}
						
																	
								else if	(NumberOfPrecedenceSuccessors[GRPWNewTask]==3)  {
									
									j=GRPWNewTask;	
												
/*ESTAS DOS LINEAS SON PARA QUE PILLE EL SIGUIENTE SUCESOR*/
										
									GRPWNewTask=PrecedenceSuccessors[j][0];
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][1];
									k++;
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][2];
									k++;
									GRPWAuxiliar=k;
									m=0;
																	}
																	
								else if	(NumberOfPrecedenceSuccessors[GRPWNewTask]==4)  {
									
									j=GRPWNewTask;	
												
/*ESTAS DOS LINEAS SON PARA QUE PILLE EL SIGUIENTE SUCESOR*/

									GRPWNewTask=PrecedenceSuccessors[j][0];
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][1];
									k++;
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][2];
									k++;
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][3];
									k++;
									GRPWAuxiliar=k;
									m=0;
																	}
			
			ADDLATER:
				while(GRPWAddLater[i][k]!=204) 	{
				k++;
												}
												
/*NO QUIERO QUE SALGA DE AQUI HASTA QUE SE SUMEN TODAS LAS TAREAS*/
			
				while(GRPWSuccessors[i][m]!=GRPWNewTask&&GRPWSuccessors[i][m]!=204)			{    
				
/*HASTA QUE NO SE COMPRUEBE QUE ES DISTINTO DE TODOS LOS ALMACENADOS, NO SE METE*/
				
					m++;
							
						if(GRPWSuccessors[i][m]==204) 					{		
						
/*SI HA LLEGADO HASTA AQUI, ES QUE ES DISTINTO A CUALQUIERA DE LOS QUE YA HABIA*/
									
							GRPWSuccessors[i][m]=GRPWNewTask; 

/*AQUI SE ALMACENA EL NUEVO SUCESOR*/

							m=0;						
							
/*PARA REINICIAR EL WHILE PARA VER SI EL SIGUIENTE SUCESOR YA ESTA EN EL VECTOR SUCCESORS*/
									
								if(NumberOfPrecedenceSuccessors[GRPWNewTask]==1) 		{
							
									j=GRPWNewTask;				
									
/*ESTAS DOS LINEAS SON PARA QUE PILLE EL SIGUIENTE SUCESOR*/
								
									GRPWNewTask=PrecedenceSuccessors[j][0];
									m=0;							
																	}
								
								else if	(NumberOfPrecedenceSuccessors[GRPWNewTask]==2)  {
									
									j=GRPWNewTask;					
									
/*ESTAS DOS LINEAS SON PARA QUE PILLE EL SIGUIENTE SUCESOR*/
								
									GRPWNewTask=PrecedenceSuccessors[j][0];
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][1];
									k++;
									m=0;
																	}
																	
								else if	(NumberOfPrecedenceSuccessors[GRPWNewTask]==3)  {
									
									j=GRPWNewTask;					
									
/*ESTAS DOS LINEAS SON PARA QUE PILLE EL SIGUIENTE SUCESOR*/
								
									GRPWNewTask=PrecedenceSuccessors[j][0];
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][1];
									k++;
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][2];
									k++;
									m=0;
																	}
																	
								else if	(NumberOfPrecedenceSuccessors[GRPWNewTask]==4)  {
									
									j=GRPWNewTask;				
									
/*ESTAS DOS LINEAS SON PARA QUE PILLE EL SIGUIENTE SUCESOR*/
								
									GRPWNewTask=PrecedenceSuccessors[j][0];
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][1];
									k++;
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][2];
									k++;
									GRPWAddLater[i][k]=PrecedenceSuccessors[j][3];
									k++;
									m=0;
																	}
																		}    
																			}
																						
		for(k=0; k<150; k++)					{
			
			if(GRPWAddLater[i][k]!=204)  	{
							
				GRPWNewTask=GRPWAddLater[i][k];	
				GRPWAddLater[i][k]=204;
				m=0;	
				k++;	
				goto ADDLATER;					
											}
				
												}
			
/*YA TENEMOS TODOS LOS SUCESORES (SIN REPETIRSE), AHORA LOS SUMAMOS*/
	m=0;	
	
	while(GRPWSuccessors[i][m]!=204) 		{

	GRPW[i]+=Duration[GRPWSuccessors[i][m]][0];	
	m++;
	
											}
												}	

/*HASTA AQUI LA RECOGIDA DE DATOS PARA SU ALMACENAMIENTO, HEMOS OBTENIDO SET INICIAL Y PESOS/
/*UNA VEZ CALCULADOS LOS GPRW DEL SET 0, PROGRAMAMOS UNA TAREA DEL INSTANTE 0 A LA DURACION DE LA TAREA, SIN TENER EN CUENTA RESTRICCIONES*/
/* DETERMINAMOS AHORA EL SET PARA LA ITERACION O*/

	for(i=0; i<NumberOfTasks; i++)   						{	
			
			if(NumberOfPrecedenceSuccessors[i]==0) 		{
														}
				
			else if(NumberOfPrecedenceSuccessors[i]==1)	{
					
				State[PrecedenceSuccessors[i][0]]=0;
					
														}				
								
			else if(NumberOfPrecedenceSuccessors[i]==2) {
					
				State[PrecedenceSuccessors[i][0]]=0;
				State[PrecedenceSuccessors[i][1]]=0;
					
														}					
								
			else if(NumberOfPrecedenceSuccessors[i]==3)	{
					
				State[PrecedenceSuccessors[i][0]]=0;
				State[PrecedenceSuccessors[i][1]]=0;
				State[PrecedenceSuccessors[i][2]]=0;
					
														}				
								
			else if(NumberOfPrecedenceSuccessors[i]==4) {
					
				State[PrecedenceSuccessors[i][0]]=0;
				State[PrecedenceSuccessors[i][1]]=0;
				State[PrecedenceSuccessors[i][2]]=0;
				State[PrecedenceSuccessors[i][3]]=0;
				
														}					
															}	

for(SolutionIterations=0; SolutionIterations<DesiredSolutions; SolutionIterations++)		{
	
NEXTITERATION:
/*INICIALIZO*/											
	for(i=0; i<NumberOfTasks; i++)						{
		
		ScheduleEarlyStart[i]=0, ScheduleStart[i]=0, ScheduleEnd[i]=0, ScheduledTask[i]=0, State[i]=0, ScheduleMakespam=0;
		
														}

	State[10]=1,  State[13]=1, State[14]=1, State[31]=1, State[39]=1, State[43]=1, State[72]=1, State[83]=1, State[111]=1, State[122]=1,
	State[123]=1, State[140]=1, State[153]=1, State[162]=1, State[164]=1, State[195]=1;
	AuxiliarArea1_1Occupancy=0, AuxiliarArea1_2Occupancy=0, AuxiliarArea1_3Occupancy=0, AuxiliarArea1_4Occupancy=0, AuxiliarArea1_5Occupancy=0, AuxiliarArea2_1Occupancy=0, AuxiliarArea2_2Occupancy=0, AuxiliarArea2_3Occupancy=0;
	Area1_1Occupancy=0, Area1_2Occupancy=0, Area1_3Occupancy=0, Area1_4Occupancy=0, Area1_5Occupancy=0, Area2_1Occupancy=0, Area2_2Occupancy=0, Area2_3Occupancy=0;
														
/*INICIALIZACION DE LOS VECTORES DE RECURSOS*/
	for(i=0; i<Time; i++)   							{
						
		Profile1Resources[i]=TotalOperatorsOfProfile1;
		Profile2Resources[i]=TotalOperatorsOfProfile2;						
		AuxiliarProfile1Resources[i]=TotalOperatorsOfProfile1;
		AuxiliarProfile2Resources[i]=TotalOperatorsOfProfile2;
		AuxiliarArea1_1Results[i]=NumberOfTasks+1;
		AuxiliarArea1_1ResultsTask[i]=NumberOfTasks+1;
		AuxiliarArea1_2Results[i]=NumberOfTasks+1;
		AuxiliarArea1_2ResultsTask[i]=NumberOfTasks+1;
		AuxiliarArea1_3Results[i]=NumberOfTasks+1;
		AuxiliarArea1_3ResultsTask[i]=NumberOfTasks+1;
		AuxiliarArea1_4Results[i]=NumberOfTasks+1;
		AuxiliarArea1_4ResultsTask[i]=NumberOfTasks+1;
		AuxiliarArea1_5Results[i]=NumberOfTasks+1;
		AuxiliarArea1_5ResultsTask[i]=NumberOfTasks+1;
		AuxiliarArea2_1Results[i]=NumberOfTasks+1;
		AuxiliarArea2_1ResultsTask[i]=NumberOfTasks+1;
		AuxiliarArea2_2Results[i]=NumberOfTasks+1;
		AuxiliarArea2_2ResultsTask[i]=NumberOfTasks+1;
		AuxiliarArea2_3Results[i]=NumberOfTasks+1;
		AuxiliarArea2_3ResultsTask[i]=NumberOfTasks+1;
														}	
												
	m=0; /*INDICE QUE DETERMINA ORDEN DE TAREAS*/
														
for(ScheduleIterations=0; ScheduleIterations<NumberOfTasks; ScheduleIterations++)		{
	
	AuxiliarProfile1=0, AuxiliarProfile2=0;
	AuxiliarProfile1FirstConsecutive=0, AuxiliarProfile2FirstConsecutive=0;
	AuxiliarProfile1SecondConsecutive=0, AuxiliarProfile2SecondConsecutive=0;
	AuxiliarCounter1=0, AuxiliarCounter2=0, AuxiliarCounter3=0;
	RandomTotalSumOfGRPWToSchedule=0;
	RandomCumulative=0;
	RandomChoosenNumber=0;
	
	for(i=0; i<NumberOfTasks; i++) 	{
		
			if(State[i]==1) 	{
			
				RandomTotalSumOfGRPWToSchedule+=GRPW[i];

								}
									}

srand(SEED); 
		
RandomChoosenNumber=rand()%(RandomTotalSumOfGRPWToSchedule+1); 

/*VEMOS A QUE TAREA CORRESPONDE EL NUMERO ALEATORIO QUE HA SALIDO*/
for(i=0; i<NumberOfTasks; i++) 							{
	
	if(State[i]==1) 									{
		RandomCumulative+=GRPW[i];
		
		if(RandomCumulative>=RandomChoosenNumber)	{
			State[i]=3; /*LA TAREA i ENTRA EN LA SOLUCION*/
			

			break;	
/*Si el programa llega a una instrucción de tipo break;, sale inmediatamente del bucle y continúa ejecutando el resto de instrucciones que se encuentran fuera del bucle for.*/
													}
														}
															}
								
	for(i=0; i<NumberOfTasks; i++) 		{
		
		if(State[i]==3) 			{
			
			ScheduledTask[m]=i;
			AuxiliarProfile1=OperatorsOfProfile1[ScheduledTask[m]][0];
			AuxiliarProfile2=OperatorsOfProfile2[ScheduledTask[m]][0];
			ScheduleInstant=0; 
/*EL PREDECESOR TIENE QUE HABER TERMINADO*/
	
			if(NumberOfConsecutiveSuccessors[ScheduledTask[m]]==1) 	{
				
				ScheduledTask[m+1]=ConsecutiveSuccessor[ScheduledTask[m]];
				ScheduleDurationFirstConsecutive=Duration[ConsecutiveSuccessor[ScheduledTask[m]]][0];
				AuxiliarProfile1FirstConsecutive=OperatorsOfProfile1[ConsecutiveSuccessor[ScheduledTask[m]]][0];
				AuxiliarProfile2FirstConsecutive=OperatorsOfProfile2[ConsecutiveSuccessor[ScheduledTask[m]]][0];
																
																	}
	
	
			if(NumberOfConsecutiveSuccessors[ConsecutiveSuccessor[ScheduledTask[m]]]==1) 	{
				
				ScheduledTask[m+2]=ConsecutiveSuccessor[ConsecutiveSuccessor[ScheduledTask[m]]];
				ScheduleDurationSecondConsecutive=Duration[ConsecutiveSuccessor[ConsecutiveSuccessor[ScheduledTask[m]]]][0];
				AuxiliarProfile1SecondConsecutive=OperatorsOfProfile1[ConsecutiveSuccessor[ConsecutiveSuccessor[ScheduledTask[m]]]][0];
				AuxiliarProfile2SecondConsecutive=OperatorsOfProfile2[ConsecutiveSuccessor[ConsecutiveSuccessor[ScheduledTask[m]]]][0];
																
																	}
			break;	
/*Si el programa llega a una instrucción de tipo break;, sale inmediatamente del bucle y continúa ejecutando el resto de instrucciones que se encuentran fuera del bucle for.*/
									}
										}
										
/*SE PROGRAMA LA PRIMERA TAREA (SIN RESTRICCIONES), AHORA, SE RESTAN LOS RECURSOS, QUIERO QUE INSTANT NOS DE EL COMIENZO DE LA TAREA AL FINAL, Y DURATION EL FINAL*/
	if(State[i]==3)																		{

SCHEDULEINSTANT: /*VUELVO PARA COMENZAR DESDE EL PRINCIPIO SI HAY UN SOLO RECURSO NEGATIVO*/

		for(j=ScheduleEarlyStart[i]+ScheduleInstant; j<150+ScheduleEarlyStart[i]+ScheduleInstant; j++)			{
				
				if(AuxiliarCounter1<Duration[i][0])															{
				
					AuxiliarProfile1Resources[j]-=AuxiliarProfile1;
					AuxiliarProfile2Resources[j]-=AuxiliarProfile2;
					AuxiliarCounter1++;																					
																											}
				
				if(NumberOfConsecutiveSuccessors[ScheduledTask[m]]==1&&AuxiliarCounter2<ScheduleDurationFirstConsecutive&&NumberOfConsecutiveSuccessors[ConsecutiveSuccessor[ScheduledTask[m]]]==0)	{
					
					AuxiliarProfile1Resources[j+Duration[i][0]]-=AuxiliarProfile1FirstConsecutive;
					AuxiliarProfile2Resources[j+Duration[i][0]]-=AuxiliarProfile2FirstConsecutive;
					AuxiliarCounter2++;
																															
																															}
				if(NumberOfConsecutiveSuccessors[ConsecutiveSuccessor[ScheduledTask[m]]]==1&&AuxiliarCounter2<ScheduleDurationSecondConsecutive)	{
																															
					AuxiliarProfile1Resources[j+Duration[i][0]]-=AuxiliarProfile1FirstConsecutive;
					AuxiliarProfile2Resources[j+Duration[i][0]]-=AuxiliarProfile2FirstConsecutive;
					AuxiliarCounter2++;																							
																																					}
																															
				if(NumberOfConsecutiveSuccessors[ConsecutiveSuccessor[ScheduledTask[m]]]==1&&AuxiliarCounter3<ScheduleDurationSecondConsecutive)	{
																															
					AuxiliarProfile1Resources[j+Duration[i][0]+ScheduleDurationFirstConsecutive]-=AuxiliarProfile1SecondConsecutive;
					AuxiliarProfile2Resources[j+Duration[i][0]+ScheduleDurationFirstConsecutive]-=AuxiliarProfile2SecondConsecutive;
					AuxiliarCounter3++;																							
							
																															}
				
																															
			if(AuxiliarProfile1Resources[j]>=0&&AuxiliarProfile2Resources[j]>=0&&AuxiliarProfile1Resources[j+Duration[i][0]]>=0&&AuxiliarProfile2Resources[j+Duration[i][0]]>=0&&AuxiliarProfile1Resources[j+Duration[i][0]+ScheduleDurationFirstConsecutive]>=0&&AuxiliarProfile2Resources[j+Duration[i][0]+ScheduleDurationFirstConsecutive]>=0)
			
																										{ 
				ScheduleEnd[m]=ScheduleEarlyStart[ScheduledTask[m]]+Duration[i][0]+ScheduleInstant;
				 
				 
				 	if(NumberOfConsecutiveSuccessors[ScheduledTask[m]]==1) 							{
				ScheduleEnd[m+1]=ScheduleEarlyStart[ScheduledTask[m]]+Duration[i][0]+ScheduleDurationFirstConsecutive+ScheduleInstant;
																									}		
					
					if(NumberOfConsecutiveSuccessors[ConsecutiveSuccessor[ScheduledTask[m]]]==1) 	{	
				ScheduleEnd[m+2]=ScheduleEarlyStart[ScheduledTask[m]]+Duration[i][0]+ScheduleDurationFirstConsecutive+ScheduleDurationSecondConsecutive+ScheduleInstant;	
																									}
																										}
																																																																								
			else if (AuxiliarProfile1Resources[j]<0||AuxiliarProfile2Resources[j]<0||AuxiliarProfile1Resources[j+Duration[i][0]]<0||AuxiliarProfile2Resources[j+Duration[i][0]]<0||AuxiliarProfile1Resources[j+Duration[i][0]+ScheduleDurationFirstConsecutive]<0||AuxiliarProfile2Resources[j+Duration[i][0]+ScheduleDurationFirstConsecutive]<0)
																										{
				/*NO HAY RECURSOS SUFICIENTES, POR LO QUE TENDREMOS QUE IRNOS AL INSTANTE SIGUIENTE*/
				ScheduleInstant++;
				AuxiliarCounter1=0, AuxiliarCounter2=0, AuxiliarCounter3=0;
				
					for(k=0; k<ScheduleEarlyStart[i]+ScheduleInstant+100+Duration[i][0]+ScheduleDurationFirstConsecutive+ScheduleDurationSecondConsecutive; k++)			{	
					/*NO HAY, RECUPERAMOS EL VALOR DE LOS RECURSOS DISPONIBLES TRAS LA ITERACION ANTERIOR*/							
		
						AuxiliarProfile1Resources[k]=Profile1Resources[k];
						AuxiliarProfile2Resources[k]=Profile2Resources[k];
								
													}								
						goto SCHEDULEINSTANT;
																											}
																															}	
	for(k=0; k<Time; k++)				{	
	/*SI SE SALE DEL FOR ES QUE EL INTERVALO EN EL QUE SE HA PROGRAMADO DISPONE DE RECURSOS, SE ASIGNAN AHORA LOS NUEVOS VALORES DE RECURSOS*/
		
		Profile1Resources[k]=AuxiliarProfile1Resources[k];
		Profile2Resources[k]=AuxiliarProfile2Resources[k];
		
										}				
	
		if(ScheduleMakespam<ScheduleEnd[m])		{	
		
		/*PARA VER LA DURACION TOTAL PARA RESOLVER LA INSTANCIA*/
			ScheduleMakespam=ScheduleEnd[m];

/*CRITERIO DE PARADA AQUI*/		
				if(ScheduleMakespam>Makespam)	
				
											{
												
					StopCounter++;
					SEED+=1;				
					SolutionIterations++;	
						
						if(StopCounter>=20000)	
						
										{
			
							goto OUTOFTHELOOP;
			
										}	
											
					goto NEXTITERATION;	
						

												
											}											
												}
			
			ScheduleStart[m]=ScheduleInstant+ScheduleEarlyStart[ScheduledTask[m]];
			State[ScheduledTask[m]]=4;	/*SI VALE 4 ES PORQUE YA ESTA EN EL CONJUNTO SOLUCION*/

/*SE ALMACENAN AHORA LOS RESULTADOS DE AREA Y TRABAJADORES*/
	for(k=ScheduleStart[m]; k<ScheduleEnd[m]; k++)						{ /*PARA MOVERNOS POR LAS COLUMNAS DE LA MATRIZ*/
	
		AuxiliarProfile1=OperatorsInArea1[ScheduledTask[m]][0];
		AuxiliarProfile2=OperatorsInArea2[ScheduledTask[m]][0];

		/*PARA REINICIAR EN CADA INSTANTE*/
		
			while(AuxiliarProfile1!=0) 								{/*CAPACIDAD DE AREA 1 NECESARIA CON TRABAJADORES DE PERFIL 1*/

					if((AuxiliarArea1_1Results[k]==NumberOfTasks+1)&&(((Area1_1Occupancy<=Area1_2Occupancy)&&(Area1_1Occupancy<=Area1_3Occupancy)&&(Area1_1Occupancy<=Area1_4Occupancy)&&(Area1_1Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_2Results[k]==1)&&(Area1_1Occupancy<=Area1_3Occupancy)&&(Area1_1Occupancy<=Area1_4Occupancy)&&(Area1_1Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(Area1_1Occupancy<=Area1_2Occupancy)&&(Area1_1Occupancy<=Area1_4Occupancy)&&(Area1_1Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(Area1_1Occupancy<=Area1_3Occupancy)&&(Area1_1Occupancy<=Area1_2Occupancy)&&(Area1_1Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(Area1_1Occupancy<=Area1_3Occupancy)&&(Area1_1Occupancy<=Area1_4Occupancy)&&(Area1_1Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_1Occupancy<=Area1_2Occupancy)&&(Area1_1Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(Area1_1Occupancy<=Area1_2Occupancy)&&(Area1_1Occupancy<=Area1_4Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_1Occupancy<=Area1_4Occupancy)&&(Area1_1Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_1Occupancy<=Area1_2Occupancy)&&(Area1_1Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_1Occupancy<=Area1_5Occupancy)&&(Area1_1Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_1Occupancy<=Area1_4Occupancy)&&(Area1_1Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_2Results[k]==1))&&((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_5Results[k]==1))||((AuxiliarArea1_5Results[k]==1))&&((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_3Results[k]==1))&&(Area1_1Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_1Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_5Results[k]==1)&&((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_1Occupancy<=Area1_4Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_1Occupancy<=Area1_5Occupancy))))			{
						
								AuxiliarArea1_1Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_1ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
								AuxiliarArea1_1Occupancy++;
																}

					else if((AuxiliarArea1_2Results[k]==NumberOfTasks+1)&&(((Area1_2Occupancy<=Area1_1Occupancy)&&(Area1_2Occupancy<=Area1_3Occupancy)&&(Area1_2Occupancy<=Area1_4Occupancy)&&(Area1_2Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(Area1_2Occupancy<=Area1_3Occupancy)&&(Area1_2Occupancy<=Area1_4Occupancy)&&(Area1_2Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(Area1_2Occupancy<=Area1_1Occupancy)&&(Area1_2Occupancy<=Area1_4Occupancy)&&(Area1_2Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(Area1_2Occupancy<=Area1_3Occupancy)&&(Area1_2Occupancy<=Area1_1Occupancy)&&(Area1_2Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(Area1_2Occupancy<=Area1_3Occupancy)&&(Area1_2Occupancy<=Area1_4Occupancy)&&(Area1_2Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_2Occupancy<=Area1_1Occupancy)&&(Area1_2Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(Area1_2Occupancy<=Area1_1Occupancy)&&(Area1_2Occupancy<=Area1_4Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_2Occupancy<=Area1_4Occupancy)&&(Area1_2Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_2Occupancy<=Area1_1Occupancy)&&(Area1_2Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_2Occupancy<=Area1_5Occupancy)&&(Area1_2Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_2Occupancy<=Area1_4Occupancy)&&(Area1_2Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_3Results[k]==1))&&((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_5Results[k]==1))||((AuxiliarArea1_5Results[k]==1))&&((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(Area1_2Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_2Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_2Occupancy<=Area1_4Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_2Occupancy<=Area1_5Occupancy))))		{
						
								AuxiliarArea1_2Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_2ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
								AuxiliarArea1_2Occupancy++;
																}

					else if((AuxiliarArea1_3Results[k]==NumberOfTasks+1)&&(((Area1_3Occupancy<=Area1_1Occupancy)&&(Area1_3Occupancy<=Area1_2Occupancy)&&(Area1_3Occupancy<=Area1_4Occupancy)&&(Area1_3Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_2Results[k]==1)&&(Area1_3Occupancy<=Area1_1Occupancy)&&(Area1_3Occupancy<=Area1_4Occupancy)&&(Area1_3Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(Area1_3Occupancy<=Area1_2Occupancy)&&(Area1_3Occupancy<=Area1_4Occupancy)&&(Area1_3Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(Area1_3Occupancy<=Area1_1Occupancy)&&(Area1_3Occupancy<=Area1_2Occupancy)&&(Area1_3Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(Area1_3Occupancy<=Area1_1Occupancy)&&(Area1_3Occupancy<=Area1_4Occupancy)&&(Area1_3Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_3Occupancy<=Area1_2Occupancy)&&(Area1_3Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_3Occupancy<=Area1_1Occupancy)&&(Area1_3Occupancy<=Area1_4Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_3Occupancy<=Area1_4Occupancy)&&(Area1_3Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_3Occupancy<=Area1_1Occupancy)&&(Area1_3Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(Area1_3Occupancy<=Area1_5Occupancy)&&(Area1_3Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_3Occupancy<=Area1_4Occupancy)&&(Area1_3Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_5Results[k]==1))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_3Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_3Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_3Occupancy<=Area1_4Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_3Occupancy<=Area1_5Occupancy))))		{
						
								AuxiliarArea1_3Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_3ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
								AuxiliarArea1_3Occupancy++;
																}

					else if((AuxiliarArea1_4Results[k]==NumberOfTasks+1)&&(((Area1_4Occupancy<=Area1_2Occupancy)&&(Area1_4Occupancy<=Area1_3Occupancy)&&(Area1_4Occupancy<=Area1_1Occupancy)&&(Area1_4Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_2Results[k]==1)&&(Area1_4Occupancy<=Area1_3Occupancy)&&(Area1_4Occupancy<=Area1_1Occupancy)&&(Area1_4Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(Area1_4Occupancy<=Area1_2Occupancy)&&(Area1_4Occupancy<=Area1_1Occupancy)&&(Area1_4Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(Area1_4Occupancy<=Area1_3Occupancy)&&(Area1_4Occupancy<=Area1_2Occupancy)&&(Area1_4Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(Area1_4Occupancy<=Area1_3Occupancy)&&(Area1_4Occupancy<=Area1_1Occupancy)&&(Area1_4Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(Area1_4Occupancy<=Area1_2Occupancy)&&(Area1_4Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_4Occupancy<=Area1_1Occupancy)&&(Area1_4Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_4Occupancy<=Area1_2Occupancy)&&(Area1_4Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_4Occupancy<=Area1_1Occupancy)&&(Area1_4Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(Area1_4Occupancy<=Area1_5Occupancy)&&(Area1_4Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_4Occupancy<=Area1_3Occupancy)&&(Area1_4Occupancy<=Area1_5Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_5Results[k]==1))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_4Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_4Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_5Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_4Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_4Occupancy<=Area1_5Occupancy))))			{
						
								AuxiliarArea1_4Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_4ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
								AuxiliarArea1_4Occupancy++;
																}

					else if((AuxiliarArea1_5Results[k]==NumberOfTasks+1)&&(((Area1_5Occupancy<=Area1_2Occupancy)&&(Area1_5Occupancy<=Area1_3Occupancy)&&(Area1_5Occupancy<=Area1_4Occupancy)&&(Area1_5Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_2Results[k]==1)&&(Area1_5Occupancy<=Area1_3Occupancy)&&(Area1_5Occupancy<=Area1_4Occupancy)&&(Area1_5Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(Area1_5Occupancy<=Area1_2Occupancy)&&(Area1_5Occupancy<=Area1_4Occupancy)&&(Area1_5Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(Area1_5Occupancy<=Area1_3Occupancy)&&(Area1_5Occupancy<=Area1_2Occupancy)&&(Area1_5Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(Area1_5Occupancy<=Area1_3Occupancy)&&(Area1_5Occupancy<=Area1_4Occupancy)&&(Area1_5Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_1Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_5Occupancy<=Area1_3Occupancy)&&(Area1_5Occupancy<=Area1_4Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(Area1_5Occupancy<=Area1_2Occupancy)&&(Area1_5Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_5Occupancy<=Area1_1Occupancy)&&(Area1_5Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_5Occupancy<=Area1_2Occupancy)&&(Area1_5Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(Area1_5Occupancy<=Area1_1Occupancy)&&(Area1_5Occupancy<=Area1_4Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_5Occupancy<=Area1_4Occupancy)&&(Area1_5Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_2Results[k]==1))&&((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_1Results[k]==1))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(Area1_5Occupancy<=Area1_1Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_5Occupancy<=Area1_3Occupancy))||((AuxiliarArea1_4Results[k]==1)&&(AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_5Occupancy<=Area1_2Occupancy))||((AuxiliarArea1_3Results[k]==1)&&(AuxiliarArea1_2Results[k]==1)&&(AuxiliarArea1_1Results[k]==1)&&(Area1_5Occupancy<=Area1_4Occupancy))))		{
						
								AuxiliarArea1_5Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_5ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
								AuxiliarArea1_5Occupancy++;
																}
					
																	}
		
			while(AuxiliarProfile2!=0) 								{/*CAPACIDAD DE AREA 2 NECESARIA Y CON TRABAJADORES DE PERFIL 2*/
				
					if((AuxiliarArea2_1Results[k]==NumberOfTasks+1)&&(((Area2_1Occupancy<=Area2_2Occupancy)&&(Area2_1Occupancy<=Area2_3Occupancy))||((AuxiliarArea2_2Results[k]==1)&&(Area2_1Occupancy<=Area2_3Occupancy))||((AuxiliarArea2_3Results[k]==1)&&(Area2_1Occupancy<=Area2_2Occupancy))||((AuxiliarArea2_3Results[k]==1)&&(AuxiliarArea2_2Results[k]==1))))		{
						
								AuxiliarArea2_1Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_1ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
								AuxiliarArea2_1Occupancy++;
																}

					else if((AuxiliarArea2_2Results[k]==NumberOfTasks+1)&&(((Area2_2Occupancy<=Area2_1Occupancy)&&(Area2_2Occupancy<=Area2_3Occupancy))||((AuxiliarArea2_1Results[k]==1)&&(Area2_2Occupancy<=Area2_3Occupancy))||((AuxiliarArea2_3Results[k]==1)&&(Area2_2Occupancy<=Area2_1Occupancy))||((AuxiliarArea2_3Results[k]==1)&&(AuxiliarArea2_1Results[k]==1))))			{
						
								AuxiliarArea2_2Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_2ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
								AuxiliarArea2_2Occupancy++;
																}

					else if((AuxiliarArea2_3Results[k]==NumberOfTasks+1)&&(((Area2_3Occupancy<=Area2_2Occupancy)&&(Area2_3Occupancy<=Area2_1Occupancy))||((AuxiliarArea2_2Results[k]==1)&&(Area2_3Occupancy<=Area2_1Occupancy))||((AuxiliarArea2_1Results[k]==1)&&(Area2_3Occupancy<=Area2_2Occupancy))||((AuxiliarArea2_1Results[k]==1)&&(AuxiliarArea2_2Results[k]==1))))		{
						
								AuxiliarArea2_3Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_3ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
								AuxiliarArea2_3Occupancy++;
																}	
																	}																			
																		}
																							
	Area1_1Occupancy+=AuxiliarArea1_1Occupancy;	
	Area1_2Occupancy+=AuxiliarArea1_2Occupancy;
	Area1_3Occupancy+=AuxiliarArea1_3Occupancy;
	Area1_4Occupancy+=AuxiliarArea1_4Occupancy;
	Area1_5Occupancy+=AuxiliarArea1_5Occupancy;
	Area2_1Occupancy+=AuxiliarArea2_1Occupancy;
	Area2_2Occupancy+=AuxiliarArea2_2Occupancy;
	Area2_3Occupancy+=AuxiliarArea2_3Occupancy;
	AuxiliarArea1_1Occupancy=0;	
	AuxiliarArea1_2Occupancy=0;
	AuxiliarArea1_3Occupancy=0;
	AuxiliarArea1_4Occupancy=0;
	AuxiliarArea1_5Occupancy=0;
	AuxiliarArea2_1Occupancy=0;
	AuxiliarArea2_2Occupancy=0;
	AuxiliarArea2_3Occupancy=0;		
	
/*SE DECIDE AHORA LAS SIGUIENTES TAREAS QUE SE PUEDEN PROGRAMAR*/
if(NumberOfConsecutiveSuccessors[ScheduledTask[m]]==0)						{
/*LA TAREA PROGRAMADA, HACE ENTRAR A SUS SUCESORES, SI TODOS SUS PREDECESORES ESTAN YA PROGRAMADOS*/
	if(NumberOfPrecedenceSuccessors[ScheduledTask[m]]==0) 				{
			
			/*NO SE HACE NADA YA QUE SE TRATA DE UNA TAREA FINAL*/	
																		}
	
	else if(NumberOfPrecedenceSuccessors[ScheduledTask[m]]==1)			{	
	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==1)		
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m]; 
																	}
																	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1]]==4)	
																	{	
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 
				
				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
							break;						}
															}
																}	
																	}
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}																
																		}		
	
	else if(NumberOfPrecedenceSuccessors[ScheduledTask[m]]==2)			{

		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m]; 
			
																	}	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m]; 
			
																	}	
																	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 
			
				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
							break;						}
															}
																}	
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 
			
				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
							break;						}
															}
																}				
																	}	
																	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}
																		}
		
	else if(NumberOfPrecedenceSuccessors[ScheduledTask[m]]==3)			{

		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m]; 
			
																	}	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m]; 
			
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][2]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][2]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[m]; 
			
																	}	
																	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 
			
				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
							break;						}
															}
																}	 
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 
			
				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
							break;						}
															}
																}				
																	}	
									
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][2]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][2]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[k]+1;
							break;						}
															}
																}	
																	}					
																	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][2]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][2]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}	
																		}
																	
	else if(NumberOfPrecedenceSuccessors[ScheduledTask[m]]==4)			{

			if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m]; 
			
																	}	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m]; 
			
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][2]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][2]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[m]; 
			
																	}	
		
			if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][3]]==1)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][3]]=1; 
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][3]]=ScheduleEnd[m]; 
			
																	}	
																	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 
		
				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
							break;						}
															}
																}																		}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
							break;						}
															}
																}	
																	}	
									
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][2]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][2]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[k]+1;
							break;						}
															}
																}	
																	}					
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][3]]==2&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][3]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][3]][1]]==4)	
																	{		
			State[PrecedenceSuccessors[ScheduledTask[m]][3]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][3]][1])			
															{
						if(ScheduleEnd[m]>=ScheduleEnd[k])
														{
						
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][3]]=ScheduleEnd[m];
							break;						}
						else 							{
					
							ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][3]]=ScheduleEnd[k]+1;
							break;						}
															}
																}	
																	}				
																	
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][0]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][0]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][1]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][1]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][1]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][1]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][2]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][2]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][2]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][2]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}	
		
		if(NumberOfPredeccessors[PrecedenceSuccessors[ScheduledTask[m]][3]]==3&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][3]][0]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][3]][1]]==4&&State[NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][3]][2]]==4)	
																	{			
			State[PrecedenceSuccessors[ScheduledTask[m]][3]]=1; 

				for(k=0; k<NumberOfTasks; k++)				{

					if(ScheduledTask[k]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][3]][1])			
															{
						
						for(i=0; i<NumberOfTasks; i++)
														{
							
							if(ScheduledTask[i]==NumberOfThePredeccessor[PrecedenceSuccessors[ScheduledTask[m]][3]][2])																											
															{
																
																
								if(ScheduleEnd[m]>=ScheduleEnd[k]&&ScheduleEnd[m]>=ScheduleEnd[i])
													{
						
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][3]]=ScheduleEnd[m];
									break;			}
								else if(ScheduleEnd[k]>=ScheduleEnd[m]&&ScheduleEnd[k]>=ScheduleEnd[i])						
													{
					
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][3]]=ScheduleEnd[k]+1;
									break;			}
								else				{
									ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][3]]=ScheduleEnd[k]+1;
									break;			}
															}
														}
															}
																}
																	}															
																		}	
																			}

/*PARA EL CASO DE HABER CONSECUTIVE*/
		if(NumberOfConsecutiveSuccessors[ScheduledTask[m]]==1) 									{
			
			State[ConsecutiveSuccessor[ScheduledTask[m]]]=4;
			State[PrecedenceSuccessors[ScheduledTask[m]][0]]=1;
			ScheduleEarlyStart[PrecedenceSuccessors[ScheduledTask[m]][0]]=ScheduleEnd[m];
			State[PrecedenceSuccessors[ConsecutiveSuccessor[ScheduledTask[m]]][0]]=1;
			ScheduleEarlyStart[PrecedenceSuccessors[ConsecutiveSuccessor[ScheduledTask[m]]][0]]=ScheduleEnd[m]+2+ScheduleDurationFirstConsecutive;
			m++;
			ScheduleStart[m]=ScheduleInstant+Duration[i][0]+ScheduleEarlyStart[ScheduledTask[m-1]];

/*SE ALMACENAN AHORA LOS RESULTADOS DE AREA Y TRABAJADORES*/
if(NumberOfConsecutiveSuccessors[ScheduledTask[m]]==0)										{

	for(k=ScheduleStart[m]; k<ScheduleEnd[m]; k++)						{ /*PARA MOVERNOS POR LAS COLUMNAS DE LA MATRIZ*/
	
		AuxiliarProfile1=OperatorsInArea1[ScheduledTask[m]][0];
		AuxiliarProfile2=OperatorsInArea2[ScheduledTask[m]][0];

		/*PARA REINICIAR EN CADA INSTANTE*/
		
			while(AuxiliarProfile1!=0) 								{/*CAPACIDAD DE AREA 1 NECESARIA CON TRABAJADORES DE PERFIL 1*/

					if(AuxiliarArea1_1Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea1_1Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_1ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}

					else if(AuxiliarArea1_2Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea1_2Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_2ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}

					else if(AuxiliarArea1_3Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea1_3Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_3ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}

					else if(AuxiliarArea1_4Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea1_4Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_4ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}

					else if(AuxiliarArea1_5Results[k]==NumberOfTasks+1)		{
						
								AuxiliarArea1_5Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_5ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}
					
																	}
		
			while(AuxiliarProfile2!=0) 								{/*CAPACIDAD DE AREA 2 NECESARIA Y CON TRABAJADORES DE PERFIL 2*/
					
					if(AuxiliarArea2_1Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea2_1Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_1ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
																}

					else if(AuxiliarArea2_2Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea2_2Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_2ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
																}

					else if(AuxiliarArea2_3Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea2_3Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_3ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
																}	
																	}																			
																		}
																			}
					
			if(NumberOfConsecutiveSuccessors[ConsecutiveSuccessor[ScheduledTask[m-1]]]==1) 	{
				
				State[ConsecutiveSuccessor[ConsecutiveSuccessor[ScheduledTask[m-1]]]]=4;
				State[PrecedenceSuccessors[ConsecutiveSuccessor[ConsecutiveSuccessor[ScheduledTask[m-1]]]][0]]=1;
				m++;
				ScheduleEarlyStart[PrecedenceSuccessors[ConsecutiveSuccessor[ConsecutiveSuccessor[ScheduledTask[m-2]]]][0]]=ScheduleEnd[m-2]+1+ScheduleDurationFirstConsecutive+ScheduleDurationSecondConsecutive;
				ScheduleStart[m]=ScheduleEnd[m-1];	
																						
/*SE ALMACENAN AHORA LOS RESULTADOS DE AREA Y TRABAJADORES*/
if(NumberOfConsecutiveSuccessors[ScheduledTask[m]]==0)										{

	for(k=ScheduleStart[m]; k<ScheduleEnd[m]; k++)						{ /*PARA MOVERNOS POR LAS COLUMNAS DE LA MATRIZ*/
	
		AuxiliarProfile1=OperatorsInArea1[ScheduledTask[m]][0];
		AuxiliarProfile2=OperatorsInArea2[ScheduledTask[m]][0];

		/*PARA REINICIAR EN CADA INSTANTE*/
		
			while(AuxiliarProfile1!=0) 								{/*CAPACIDAD DE AREA 1 NECESARIA CON TRABAJADORES DE PERFIL 1*/

					if(AuxiliarArea1_1Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea1_1Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_1ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}

					else if(AuxiliarArea1_2Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea1_2Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_2ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}

					else if(AuxiliarArea1_3Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea1_3Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_3ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}

					else if(AuxiliarArea1_4Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea1_4Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_4ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}

					else if(AuxiliarArea1_5Results[k]==NumberOfTasks+1)		{
						
								AuxiliarArea1_5Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea1_5ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile1--;
																}
					
																	}
		
			while(AuxiliarProfile2!=0) 								{/*CAPACIDAD DE AREA 2 NECESARIA Y CON TRABAJADORES DE PERFIL 2*/
					
					if(AuxiliarArea2_1Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea2_1Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_1ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
																}

					else if(AuxiliarArea2_2Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea2_2Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_2ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
																}

					else if(AuxiliarArea2_3Results[k]==NumberOfTasks+1)			{
						
								AuxiliarArea2_3Results[k]=1;	/*PASA A VALER UNO CON LO QUE ESA UNIDAD DE CAPACIDAD EN EL INSTANTE k PASA A ESTAR OCUPADA*/
								AuxiliarArea2_3ResultsTask[k]=ScheduledTask[m];
								AuxiliarProfile2--;
																}	
																	}																			
																		}
																			}
																							}	
																								}
	
				/*	FIN DE ESTA ITERACION, HAY 204 ITERACIONES, 1 POR TAREA A PROGRAMAR DE LA INSTANCIA*/	
						m++; /*HA DE SER AL FINAL!!!!*/			

																		} 
																			} 


/*FUNCION OBJETIVO*/
		if(ScheduleMakespam<Makespam)		{
			
	/*PARA HACER LA GRAFICA DE MEJORA DE LAS SOLUCIONES*/
	MakespamInIteration[l]=ScheduleMakespam;
	NumberOfIteration[l]=SolutionIterations;
	l++;
			
	Solution++, Makespam=ScheduleMakespam, StopCounter=0;		
	
			for(k=0; k<NumberOfTasks; k++)	
			
										{
				SolutionTask[k]=ScheduledTask[k];
				SolutionStart[k]=ScheduleStart[k];
				SolutionEnd[k]=ScheduleEnd[k];											
										}	
			printf("Solution number %d solution iteration %d with seed %d and makespam %d\n", Solution, SolutionIterations, SEED, Makespam);									
	
	
			for(i=0; i<Makespam+1; i++)			{
				
					Area1_1Results[i]=AuxiliarArea1_1Results[i];
					Area1_1ResultsTask[i]=AuxiliarArea1_1ResultsTask[i];
					Area1_2Results[i]=AuxiliarArea1_2Results[i];
					Area1_2ResultsTask[i]=AuxiliarArea1_2ResultsTask[i];
					Area1_3Results[i]=AuxiliarArea1_3Results[i];
					Area1_3ResultsTask[i]=AuxiliarArea1_3ResultsTask[i];
					Area1_4Results[i]=AuxiliarArea1_4Results[i];
					Area1_4ResultsTask[i]=AuxiliarArea1_4ResultsTask[i];
					Area1_5Results[i]=AuxiliarArea1_5Results[i];
					Area1_5ResultsTask[i]=AuxiliarArea1_5ResultsTask[i];
					Area2_1Results[i]=AuxiliarArea2_1Results[i];
					Area2_1ResultsTask[i]=AuxiliarArea2_1ResultsTask[i];
					Area2_2Results[i]=AuxiliarArea2_2Results[i];
					Area2_2ResultsTask[i]=AuxiliarArea2_2ResultsTask[i];
					Area2_3Results[i]=AuxiliarArea2_3Results[i];
					Area2_3ResultsTask[i]=AuxiliarArea2_3ResultsTask[i];
					
												}	
	
for(k=0; k<NumberOfTasks; k++)	
								
										{
		printf("Task %d, start %d end %d scheduled in the iteration %d with a GRPW of %d \n ", SolutionTask[k], SolutionStart[k], SolutionEnd[k], k, GRPW[SolutionTask[k]]);
										}

											}	
	SEED+=1;										
																
/*for(k=0; k<NumberOfTasks; k++)			{
		
		
			
			printf("Tarea %d, estado %d\n ", k, State[k]);
												
		
											}*/

/*for(k=0; k<NumberOfTasks; k++)			{
		
		
			
			printf("Task %d, start %d end %d scheduled in the iteration %d \n ", ScheduledTask[k], ScheduleStart[k], ScheduleEnd[k], k);
												
		
											}*/

															} 	/*FIN DE TODAS LAS ITERACIONES*/
															
	OUTOFTHELOOP:
				printf("\nTHE SOLUTION WITH THE OPTIMAL MAKESPAM OF %d IS:\n", Makespam);

/*REASIGNO SCHEDULEDSTART Y SCHEDULEDEND PARA QUE EL INDICE SEA LA TAREA (Y NO M)*/
for(i=0; i<NumberOfTasks; i++)	{
	
	AuxiliarSolutionTotalStart[SolutionTask[i]]=SolutionStart[i];
	AuxiliarSolutionTotalEnd[SolutionTask[i]]=SolutionEnd[i];
		printf("Task %d, start %d end %d scheduled\n ", SolutionTask[i], AuxiliarSolutionTotalStart[SolutionTask[i]], AuxiliarSolutionTotalEnd[SolutionTask[i]]);
								}

for(i=0; i<Makespam*2; i++)	{
	
	Area1_1StartInThisArea[i]=Makespam*2;
	Area1_1EndInThisArea[i]=Makespam*2;
	Area1_2StartInThisArea[i]=Makespam*2;
	Area1_2EndInThisArea[i]=Makespam*2;
	Area1_3StartInThisArea[i]=Makespam*2;
	Area1_3EndInThisArea[i]=Makespam*2;
	Area1_4StartInThisArea[i]=Makespam*2;
	Area1_4EndInThisArea[i]=Makespam*2;
	Area1_5StartInThisArea[i]=Makespam*2;
	Area1_5EndInThisArea[i]=Makespam*2;
	Area2_1StartInThisArea[i]=Makespam*2;
	Area2_1EndInThisArea[i]=Makespam*2;
	Area2_2StartInThisArea[i]=Makespam*2;
	Area2_2EndInThisArea[i]=Makespam*2;
	Area2_3StartInThisArea[i]=Makespam*2;
	Area2_3EndInThisArea[i]=Makespam*2;
	
							}	


/*PARA FACILITARLE LAS COSAS A PLOTLY Y PONER EL TRABAJO EN CADA AREA*/
j=0;
		for(i=0; i<Makespam-1; i++)																				{

if(Area1_1Results[i]==1)																					{

while(Area1_1ResultsTask[i]==Area1_1ResultsTask[i+1]||(Area1_1ResultsTask[i-1]!=Area1_1ResultsTask[i])&&(Area1_1ResultsTask[i]!=Area1_1ResultsTask[i+1]))														{
								
	if(Area1_1Results[i]==1&&Area1_1ResultsTask[i-1]!=Area1_1ResultsTask[i]) 						{
		
		Area1_1StartInThisArea[j]=i;
		Area1_1ResultsTask[j]=Area1_1ResultsTask[i];
	
																									}
	
	
	if(Area1_1StartInThisArea[i+1]==Makespam*2)														{
		
		i++;
																									}
																											}		
		Area1_1EndInThisArea[j]=i+1;
									
		j++;
		Aux1=j;	
																											}
																												}

j=0;									
		for(i=0; i<Makespam-1; i++)																				{

if(Area1_2Results[i]==1)																					{

while(Area1_2ResultsTask[i]==Area1_2ResultsTask[i+1]||(Area1_2ResultsTask[i-1]!=Area1_2ResultsTask[i])&&(Area1_2ResultsTask[i]!=Area1_2ResultsTask[i+1]))															{
								
	if(Area1_2Results[i]==1&&Area1_2ResultsTask[i-1]!=Area1_2ResultsTask[i]) 						{
		
		Area1_2StartInThisArea[j]=i;
		Area1_2ResultsTask[j]=Area1_2ResultsTask[i];
	
																									}
	
	if(Area1_2StartInThisArea[i+1]==Makespam*2)														{
		
		i++;
																									}
																											}		
		Area1_2EndInThisArea[j]=i+1;
									
		j++;
		Aux2=j;
																											}
																												}

j=0;									
		for(i=0; i<Makespam-1; i++)																				{

if(Area1_3Results[i]==1)																					{
	
while(Area1_3ResultsTask[i]==Area1_3ResultsTask[i+1]||(Area1_3ResultsTask[i-1]!=Area1_3ResultsTask[i])&&(Area1_3ResultsTask[i]!=Area1_3ResultsTask[i+1]))																{
								
	if(Area1_3Results[i]==1&&Area1_3ResultsTask[i-1]!=Area1_3ResultsTask[i]) 						{
		
		Area1_3StartInThisArea[j]=i;
		Area1_3ResultsTask[j]=Area1_3ResultsTask[i];
	
																									}
	
	if(Area1_3StartInThisArea[i+1]==Makespam*2)														{
		
		i++;
																									}
																											}		
		Area1_3EndInThisArea[j]=i+1;
									
		j++;																								
		Aux3=j;
																											}
																												}

j=0;									
		for(i=0; i<Makespam-1; i++)																				{

if(Area1_4Results[i]==1)																				{
	

while(Area1_4ResultsTask[i]==Area1_4ResultsTask[i+1]||(Area1_4ResultsTask[i-1]!=Area1_4ResultsTask[i])&&(Area1_4ResultsTask[i]!=Area1_4ResultsTask[i+1]))														{
								
	if(Area1_4Results[i]==1&&Area1_4ResultsTask[i-1]!=Area1_4ResultsTask[i]) 						{
		
		Area1_4StartInThisArea[j]=i;
		Area1_4ResultsTask[j]=Area1_4ResultsTask[i];
	
																									}
	
	if(Area1_4StartInThisArea[i+1]==Makespam*2)														{
		
		i++;
																									}
																											}		
		Area1_4EndInThisArea[j]=i+1;
									
		j++;																								
		Aux4=j;
																											}
																												}
																												
j=0;									
		for(i=0; i<Makespam-1; i++)																				{

if(Area1_5Results[i]==1)														
																											{
																												
while(Area1_5ResultsTask[i]==Area1_5ResultsTask[i+1]||Area1_5Results[i]==NumberOfTasks+1||(Area1_5ResultsTask[i-1]!=Area1_5ResultsTask[i])&&(Area1_5ResultsTask[i]!=Area1_5ResultsTask[i+1]))														
																									
																										{
								
	if(Area1_5Results[i]==1&&Area1_5ResultsTask[i-1]!=Area1_5ResultsTask[i]) 						{
		
		Area1_5StartInThisArea[j]=i;
		Area1_5ResultsTask[j]=Area1_5ResultsTask[i];
	
																									}
	
	if(Area1_5StartInThisArea[i+1]==Makespam*2)														{
		
		i++;
																									}

																										}
		Area1_5EndInThisArea[j]=i+1;	
		j++;	
		Aux5=j;																								}
																		
																												}
																										
		
															
																												
j=0;									
		for(i=0; i<Makespam-1; i++)																				{

if(Area2_1Results[i]==1)																					{
	
while(Area2_1ResultsTask[i]==Area2_1ResultsTask[i+1]||(Area2_1ResultsTask[i-1]!=Area2_1ResultsTask[i])&&(Area2_1ResultsTask[i]!=Area2_1ResultsTask[i+1]))														{
								
	if(Area2_1Results[i]==1&&Area2_1ResultsTask[i-1]!=Area2_1ResultsTask[i]) 						{
		
		Area2_1StartInThisArea[j]=i;
		Area2_1ResultsTask[j]=Area2_1ResultsTask[i];
	
																									}
	
	if(Area2_1StartInThisArea[i+1]==Makespam*2)														{
		
		i++;
																									}
																											}		
		Area2_1EndInThisArea[j]=i+1;
									
		j++;
		Aux6=j;																								
																											}
																												}
																												
j=0;									
		for(i=0; i<Makespam-1; i++)																				{

if(Area2_2Results[i]==1)																					{
	
while(Area2_2ResultsTask[i]==Area2_2ResultsTask[i+1]||(Area2_2ResultsTask[i-1]!=Area2_2ResultsTask[i])&&(Area2_2ResultsTask[i]!=Area2_2ResultsTask[i+1]))											{
								
	if(Area2_2Results[i]==1&&Area2_2ResultsTask[i-1]!=Area2_2ResultsTask[i]) 						{
		
		Area2_2StartInThisArea[j]=i;
		Area2_2ResultsTask[j]=Area2_2ResultsTask[i];
	
																									}
	
	if(Area2_2StartInThisArea[i+1]==Makespam*2)														{
		
		i++;
																									}
																											}		
		Area2_2EndInThisArea[j]=i+1;
									
		j++;
		Aux7=j;																								
																										}
																												}
																												
j=0;									
		for(i=0; i<Makespam-1; i++)																				{

if(Area2_3Results[i]==1)																					{
	
	
while(Area2_3ResultsTask[i]==Area2_3ResultsTask[i+1]||(Area2_3ResultsTask[i-1]!=Area2_3ResultsTask[i])&&(Area2_3ResultsTask[i]!=Area2_3ResultsTask[i+1]))													{
						
	if(Area2_3Results[i]==1&&Area2_3ResultsTask[i-1]!=Area2_3ResultsTask[i]) 						{
		
		Area2_3StartInThisArea[j]=i;
		Area2_3ResultsTask[j]=Area2_3ResultsTask[i];
	
																									}
	
	if(Area2_3StartInThisArea[i+1]==Makespam*2)														{
		
		i++;
																									}
																											}		
		Area2_3EndInThisArea[j]=i+1;
									
		j++;
		Aux8=j;																								
																											}
																												}


		for(i=0; i<Makespam; i++)																				{
		
			if(Area1_1Results[i]==1)																		{

				Area1_1TotalOccupancy++;
																											
																											}
		
			if(Area1_2Results[i]==1)																		{

				Area1_2TotalOccupancy++;
																											
																											}

			if(Area1_3Results[i]==1)																		{

				Area1_3TotalOccupancy++;
																											
																											}

			if(Area1_4Results[i]==1)																		{

				Area1_4TotalOccupancy++;
																											
																											}

			if(Area1_5Results[i]==1)																		{

				Area1_5TotalOccupancy++;
																											
																											}

			if(Area2_1Results[i]==1)																		{

				Area2_1TotalOccupancy++;
																											
																											}

			if(Area2_2Results[i]==1)																		{

				Area2_2TotalOccupancy++;
																											
																											}

			if(Area2_3Results[i]==1)																		{

				Area2_3TotalOccupancy++;
																											
																											}
																												}
				
FILE *h;	
	h = fopen("204TasksLocalSearchResources.txt","w"); 
	
	if(h == NULL) 											{
		printf("Could not open the file.\n");
		exit(1);		
															}


for(j=0; j<70; j++)											{

	if(j<Aux1&&Area1_1StartInThisArea[j]!=Makespam*2)	{
				
fprintf(h,"%i %i %i		" ,Area1_1ResultsTask[j], Area1_1StartInThisArea[j], Area1_1EndInThisArea[j]);										
												
														}
	
	else if (j>=Aux1)									{
		
fprintf(h,"%i %i %i		" ,0, 0, 0);										
																
														}

	if(j<Aux2&&Area1_2StartInThisArea[j]!=Makespam*2)	{
				
fprintf(h,"%i %i %i		", Area1_2ResultsTask[j], Area1_2StartInThisArea[j], Area1_2EndInThisArea[j]);										
												
														}
	
	else if (j>=Aux2)									{
		
fprintf(h,"%i %i %i		" ,0, 0, 0);										
																
														}
												
	if(j<Aux3&&Area1_3StartInThisArea[j]!=Makespam*2)	{
				
fprintf(h,"%i %i %i		", Area1_3ResultsTask[j], Area1_3StartInThisArea[j], Area1_3EndInThisArea[j]);										
												
														}
	
	else if (j>=Aux3)									{
		
fprintf(h,"%i %i %i		", 0, 0, 0);										
																
														}
												
	if(j<Aux4&&Area1_4StartInThisArea[j]!=Makespam*2)	{
				
fprintf(h,"%i %i %i		", Area1_4ResultsTask[j], Area1_4StartInThisArea[j], Area1_4EndInThisArea[j]);										
												
														}
	
	else if (j>=Aux4)									{
		
fprintf(h,"%i %i %i		", 0, 0, 0);										
																
														}
												
	if(j<=Aux5&&Area1_5StartInThisArea[j]!=Makespam*2)	{
				
fprintf(h,"%i %i %i		", Area1_5ResultsTask[j], Area1_5StartInThisArea[j], Area1_5EndInThisArea[j]);										
												
														}
	
	else if (j>=Aux5)									{
		
fprintf(h,"%i %i %i		", 0, 0, 0);										
																
														}
												
	if(j<Aux6&&Area2_1StartInThisArea[j]!=Makespam*2)	{
				
fprintf(h,"%i %i %i		", Area2_1ResultsTask[j], Area2_1StartInThisArea[j], Area2_1EndInThisArea[j]);										
												
														}
	
	else if (j>=Aux6)									{
		
fprintf(h,"%i %i %i		", 0, 0, 0);										
																
														}
												
	if(j<Aux7&&Area2_2StartInThisArea[j]!=Makespam*2)	{
				
fprintf(h,"%i %i %i		", Area2_2ResultsTask[j], Area2_2StartInThisArea[j], Area2_2EndInThisArea[j]);										
												
														}
	
	else if (j>=Aux7)									{
		
fprintf(h,"%i %i %i		", 0, 0, 0);										
																
														}
												
	if(j<Aux8&&Area2_3StartInThisArea[j]!=Makespam*2)	{
				
fprintf(h,"%i %i %i		", Area2_3ResultsTask[j], Area2_3StartInThisArea[j], Area2_3EndInThisArea[j]);										
												
														}
	
	else if (j>=Aux8)									{
		
fprintf(h,"%i %i %i		", 0, 0, 0);										
																
														}
												
fprintf(h,"\n");									
												
															}

fclose(h);	


FILE *t;	
	t= fopen("204TasksMinimumWorkersModeMakespamEvolution.txt","w"); 
	
	if(t == NULL) 											{
		printf("Could not open the file.\n");
		exit(1);		
															}
															
fprintf(t,"NumberOfIteration, MakespamInIteration");	
fprintf(t,"\n");	

for(i=0; i<DesiredSolutions; i++)							{
	
		if(MakespamInIteration[i]!=0)		{
	
fprintf(t,"%i, %i			", NumberOfIteration[i], MakespamInIteration[i]);	

fprintf(t,"\n");		
											}	
														}
														
	fclose(t);

FILE *y;	
	y= fopen("204TasksMinimumWorkersModePercentageOccupancy.txt","w"); 
	
	if(y == NULL) 											{
		printf("Could not open the file.\n");
		exit(1);		
															}
															
fprintf(y,"NumberOfArea, PercentageOccupancy");	
fprintf(y,"\n");	
	
fprintf(y,"%i, %f			", 1, Area1_1TotalOccupancy*100/Makespam);	

fprintf(y,"\n");		

fprintf(y,"%i, %f			", 2, Area1_2TotalOccupancy*100/Makespam);	

fprintf(y,"\n");		

fprintf(y,"%i, %f			", 3, Area1_3TotalOccupancy*100/Makespam);	

fprintf(y,"\n");		

fprintf(y,"%i, %f			", 4, Area1_4TotalOccupancy*100/Makespam);	

fprintf(y,"\n");		

fprintf(y,"%i, %f			", 5, Area1_5TotalOccupancy*100/Makespam);	

fprintf(y,"\n");		

fprintf(y,"%i, %f			", 6, Area2_1TotalOccupancy*100/Makespam);	

fprintf(y,"\n");		

fprintf(y,"%i, %f			", 7, Area2_2TotalOccupancy*100/Makespam);	

fprintf(y,"\n");		

fprintf(y,"%i, %f			", 8, Area2_3TotalOccupancy*100/Makespam);	

fprintf(y,"\n");		

fprintf(y,"%i, %f			", 9, ((Area1_1TotalOccupancy+Area1_2TotalOccupancy+Area1_3TotalOccupancy+Area1_4TotalOccupancy+Area1_5TotalOccupancy+Area2_1TotalOccupancy+Area2_2TotalOccupancy+Area2_3TotalOccupancy)*100/(Makespam*8)));	

fprintf(y,"\n");		

fclose(y);


ExecutionTime= (clock()-StartTime)/1000;
printf("El tiempo de ejecucion ha sido de %f segundos", ExecutionTime);

system("pause");
return 0;												
																}
