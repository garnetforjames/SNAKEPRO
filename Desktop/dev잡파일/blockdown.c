void DrawGameBoard()
{
	int x,y;
	for(y=0;y<=GBOARD_HEIGHT ;y++){
		
		SetCurrentCursorPos(GBOARD_ORIGIN_X,GBOARD_ORIGIN_Y+y);
		if(y==GBOARD_HEIGHT)
			printf("¦¦") ;
		else
			printf("¦¢");
			
	}
		 
	for(x=0;x<2*(GBOARD_WIDTH-1);x++){
	 	
		printf("¦¡");
	}	
	for(y=0;y<=GBOARD_HEIGHT;y++){
		SetCurrentCursorPos(2*GBOARD_WIDTH+GBOARD_ORIGIN_X,GBOARD_ORIGIN_Y+y);
			if(y==GBOARD_HEIGHT)
			printf("¦¥") ;
		else
			printf("¦¢");
		
	} 
	
}
