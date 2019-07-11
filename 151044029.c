/*ANIL AKBULUT CSE102 #HW1*/
/*I used the following libraries*/
#include <stdio.h>  
#include <math.h>
#include <time.h>
#include <stdlib.h>
/*SQUARE,RECTENGULAR and circle values defined*/
#define SQUARE 1
#define RECTENGULAR 2
#define CIRCULAR 3
/*Yellow,blue,black and white color values defined*/
#define red 0
#define yellow 1	
#define blue 2
#define black 3
#define white 4
/*Pi number defined*/
#define PI 3.0

/*I defined the functions used*/
double CreateBody (int shape);
int SetColor (int color);
double LoadMoves(int shape, double body_size);
int SetAttackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);

/*PART 1-This function takes input from the user according to the parameter sent to the function.
		 And returns the field of the desired shape. */
double CreateBody (int shape){ 
	double edge_SQUARE,edge_short_rect,edge_long_rect,radius_circ;
	if(shape==SQUARE){
		printf("Please enter the SQUARE's edge:"); 
		scanf("%lf",&edge_SQUARE);/*User enter the SQUARE's edge*/
		return edge_SQUARE*edge_SQUARE;
	}
	if(shape==RECTENGULAR){
		printf("Please enter the RECTENGULAR's edges:");
		scanf("%lf %lf",&edge_short_rect,&edge_long_rect);/*User enter the RECTENGULAR's edge*/
		return edge_short_rect*edge_long_rect;
	}
	if(shape==CIRCULAR){
		printf("Please enter the CIRCULAR's radius:");
		scanf("%lf",&radius_circ);/*User enter the CIRCULAR's radius*/
		return PI*radius_circ*radius_circ;
	}
}
/*PART 2-This function returns the number according to the parameter to the function.*/
int SetColor (int color){
	if( 0<=color && color<=1000){
		return color%5;
	}
	else return 1;
}
/*PART 3-This function takes two parameters and returns the circumference of the shape according to the shape parameter*/
double LoadMoves(int shape, double body_size){
	if(shape==SQUARE){
		return sqrt(body_size)*4;
	}
	if(shape==RECTENGULAR){
		return (body_size/5+5)*2;
	}
	if(shape==CIRCULAR){
		return 2 * PI * ( sqrt(body_size/PI));
	}
}
/*PART 4-This function generates random numbers between 2 parameters and returns that number*/
int SetAttackPower(int lower_bound, int upper_bound){
	srand(time(NULL));
	int number=lower_bound+rand()%(upper_bound-lower_bound+1);
	return number;
}
/*PART 5-This function draws the desired shapes.The display shows you the values of size,move_lenght, color and attack_power.*/
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power){ 
	double i,j,radius;
	int left_tab,mid_tab,temp_left_tab=1,temp_line;
	if(shape==SQUARE){/*Draws a SQUARE on the screen if the shape is SQUARE*/
		for(i=0;i<sqrt(body_size);i++){
			for(j=0;j<sqrt(body_size);j++){
				printf("X");
			}
			printf("\n");
		}
		printf("Name: Square Pokémon\n");
	}
	if(shape==RECTENGULAR){/*Draws a RECTENGULAR on the screen if the shape is RECTENGULAR*/
		for(i=0;i<5;i++){
			for(j=0;j<body_size/5;j++){
				printf("X");
			}
			printf("\n");
		}
		printf("Name: Rectangular Pokémon\n");
	}
	if(shape==CIRCULAR){/*Draws a CIRCULAR on the screen if the shape is CIRCULAR*/
		radius = sqrt(body_size/PI);
		left_tab=(radius-1)/2;
		mid_tab=1;
		temp_line=left_tab;
		if((int)radius%2==0 && (int)radius!=0){ /*This 'if' works if the radius is even number.*/
			for(j=0;j<temp_line;j++){ /*temp_line is a first line.*/
				printf("\t");
			}
			printf("    X\n");
			for(i=1;i<radius;i++){
				for(j=0;j<left_tab;j++){
					printf("\t");
				}
				printf("X");
				for(j=0;j<mid_tab;j++){
					printf("\t");				
				}
				printf("X\n");
				if(temp_left_tab==1){ /*The upper half of the circle is drawn using this code.*/
					left_tab--;
					mid_tab=mid_tab+2;
					if(left_tab==0) temp_left_tab=0;
				}
				else{	/*The lower half of the circle is drawn using this code.*/
					left_tab++;
					mid_tab=mid_tab-2;
					temp_left_tab=0;
				}	
			}
			for(j=0;j<temp_line;j++){ /*temp_line is a last line*/
				printf("\t");
			}
			printf("    X\n");
		}
		left_tab=(radius-1)/2;
		mid_tab=0;
		temp_left_tab=1;
		if((int)radius%2!=0) /*/*This 'if' works if the radius is odd number.*/
		{
			for(i=1;i<=radius;i++){
				for(j=0;j<left_tab;j++){
					printf("\t");
				}
				printf("X");
				if(mid_tab==0) printf("\n");
				else{
					for(j=0;j<mid_tab;j++){
						printf("\t");
					}
					printf("X\n");
				}
				if(temp_left_tab==1){/*The upper half of the circle is drawn using this code.*/
					left_tab--;
					mid_tab=mid_tab+2;
					if(left_tab==0) temp_left_tab=0;
				}
				else {	/*The lower half of the circle is drawn using this code.*/
						left_tab++;
						mid_tab=mid_tab-2;
						temp_left_tab=0;
				}
			}
		}
		printf("Name: Circular Pokémon\n");
	}
	/*Values printed on the screen*/
	printf("Size: %d\n",(int)body_size); 
	if(color==red) printf("Color: Red\n");
	if(color==yellow) printf("Color: Yellow\n");
	if(color==blue) printf("Color: Blue\n");
	if(color==black) printf("Color: Black\n");
	if(color==white) printf("Color: White\n");
    printf("Move: %d\n",(int)move_length);
	printf("Attack Power: %d\n",attack_power);
}
int main ()
{
	int shape,color,attack_power;
	double size_of_body,move_length;
	shape=CIRCULAR;
	size_of_body=CreateBody(shape);
	color=798;
	color=SetColor(color);
	move_length=LoadMoves(shape,size_of_body);
	attack_power=SetAttackPower(5,8);
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);
}