#include <stdio.h>
#include <math.h>

#define PI 3.14159  /* Omit if PI defined in <math.h> */
    
/* function prototypes */
double find_area(double r);
double find_rim_area(double outer, double inner);
double find_unit_weight(double area, double thickness, double density);
void instruct(void);
    
int main(void)
{
	double hole_diameter;	/* input   diameter of hole         */
	double edge_diameter; 	/* input   diameter of outer edge   */
	double thickness;     	/* input   thickness of washer      */
	double density;       	/* input   density of material used */
	double quantity;      	/* input   number of washers made   */
	double weight;        	/* output   weight of washer batch  */
	double hole_radius;  	/* radius of hole                   */
	double edge_radius;   	/* radius of outer edge             */
	double rim_area;      	/* area of rim                      */
	double unit_weight;   	/* weight of 1 washer               */
	   
	/* Give the user instructions. */
	instruct();

	/* Get the inner diameter, outer diameter, and thickness. */
	printf("Inner diameter in centimeters> ");
	scanf("%lf", &hole_diameter);
	printf("Outer diameter in centimeters> ");
	scanf("%lf", &edge_diameter);
	printf("Thickness in centimeters> ");
	scanf("%lf", &thickness);
	   
	/* Get the material density and quantity manufactured. */
	printf("Material density in grams per cubic centimeter> ");
	scanf("%lf", &density);
	printf("Quantity in batch> ");
	scanf("%lf", &quantity);
	   
	/* Compute the rim area. */
	hole_radius = hole_diameter / 2.0;
	edge_radius = edge_diameter / 2.0;
	rim_area = find_rim_area(edge_radius, hole_radius);
    
	/* Compute the weight of a flat washer. */
	unit_weight = find_unit_weight(rim_area, thickness, density);
    
	/* Compute the weight of the batch of washers. */
	weight = unit_weight * quantity;
    
	/* Display the weight of the batch of washers. */
	printf("\nThe expected weight of the batch is %.2f ", weight);
	printf("grams.\n");
    
	return (0);
}

	/* 
	 * Displays instructions to a user of program to compute the
	 * weight of a batch of flat washers.
	 */
	void instruct(void)
	{                   
	   printf("This program computes the weight of a batch of flat \n");
	   printf("washers.\n\n"); 
	   printf("To use this program, please enter the inner diameter,\n");
	   printf("outer diameter, thickness, density, and quantity at each\n");
	   printf("respective prompt.\n\nThanks for using this program.\n\n");
	}  

	/* 
	 * Computes the area of a circle with radius r.
	 * Pre:  r is defined and is > 0.
	 *       PI is a constant macro representing an approximation of pi.
	 *       Library math.h is included.
	 */
	double find_area(double r)
	{
	   return (PI * pow(r, 2));
	}

	/* 
	 * Computes the area of an annular ring with inner radius of inner
	 * and outer radius of outer.
	 * Pre:  inner and outer are defined and are > 0.
	 *       Function find_area() is defined.
	 */
	double find_rim_area(double outer, double inner)
	{
	   return (find_area(outer)-find_area(inner));
	}

	/* Computes the unit weight of a flat object with an area of area, 
	* with a thickness of thickness, and with a density of density.
	* Pre:  area, thickness and density are defined and are > 0.
	*/
	double find_unit_weight(double area, double thickness, double density)
	{
	   return (area * thickness * density);
	}

