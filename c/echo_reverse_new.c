/*
	There shall be a comment, explaining what the program does.

	Author: Sahar
	Copyright: DTU, BSD License
*/

int main() {

	volatile int *uart_stat_ptr = (int *) 0xF0000000;
	volatile int *uart_val_ptr = (int *) 0xF0000004;	
	volatile int *led_ptr = (int *) 0xF0000200;
	int i, j, k;
	int flag = 0;
	int flag2 = 0;
	int cmp1 = 2;
	int cmp2 = 1;
	int status;
	char read_val;//[2];
	char read_string[11];
	int num = 0;
	for (k = 0; k <= 9; k++){
	//while(!flag2){
		while (!flag )
		{
			status = *uart_stat_ptr & cmp1;
			if (status == 2)
				{flag = 1; break;}
				
		}
		read_val =  *uart_val_ptr;
		*uart_val_ptr = read_val;
		//if ((int)read_val == 10) break;
		read_string[k] = read_val; 
		//k++;		
		flag = 0;
	}
		//if (read_val == '*'){
			for (num = k-1 ; num >= 0; num--){
				while (!flag )
				{
					status = *uart_stat_ptr & cmp2;
					if (status == 1)
						{flag = 1; break;}
				
				}
				*uart_val_ptr =  read_string[num];
	 			flag = 0;//}
			}
}
