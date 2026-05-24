#include "class_triangle.h"
#include "class_right_triangle.h"
#include "class_isosceles_triangle.h"
#include "class_equilateral_triangle.h"
#include "class_quadrilateral.h"
#include "class_rectangle.h"
#include "class_square.h"
#include "class_parallelogram.h"
#include "class_rhombus.h"

void print_info(figure* temp) {
	temp->print();
}
int main() {
	triangle TR(10, 20, 30, 50, 60, 70);				figure* triangle_ptr = &TR;			print_info(triangle_ptr);
	right_triangle RTR(10, 20, 30, 50, 60);				figure* right_triangle_ptr = &RTR;	print_info(right_triangle_ptr);
	isosceles_triangle ITR(10, 20, 50, 60);				figure* isos_triangle_ptr = &ITR;	print_info(isos_triangle_ptr);
	equilateral_triangle ETR(30, 60);					figure* equil_triangle_ptr = &ETR;	print_info(equil_triangle_ptr);

	quadrilateral QL(10, 20, 30, 40, 50, 60, 70, 80);	figure* QL_ptr = &QL;				print_info(QL_ptr);
	rectangle RQL(10, 20);								figure* RQL_ptr = &RQL;				print_info(RQL_ptr);
	square SQL(20);										figure* SQL_ptr = &SQL;				print_info(SQL_ptr);
	parallelogram PQL(20, 30, 30, 40);					figure* PQL_ptr = &PQL;				print_info(PQL_ptr);
	rhombus HQL(30, 30, 40);							figure* HQL_ptr = &HQL;				print_info(HQL_ptr);

	return EXIT_SUCCESS;
}