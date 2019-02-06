/*///////////////////////////////////////////////////////////////////////////
Triad library
Copyright (C)2018 Alfredo SG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*////////////////////////////////////////////////////////////////////////////

#ifndef TRIAD_H_INCLUDED
#define TRIAD_H_INCLUDED

#ifndef VECTOR_LENGTH
#define VECTOR_LENGTH 3
#endif // VECTOR_LENGTH

#ifndef CSV_LENGTH
#define CSV_LENGTH 40
#endif // CSV_LENGTH

typedef float VECTOR[VECTOR_LENGTH];
typedef float MATRIX[VECTOR_LENGTH][VECTOR_LENGTH];

void transponse_matrix(float *matrix);

void matrix_multiplication(float *first_matrix, float *second_matrix, float *dest);

void create_matrix_from_vectors(float *first_vector, float *second_vector, float *third_vector, float *dest);

void print_matrix(char *matrix_name, float *matrix);

void print_vector(char *vector_name, float *_vector);

void unitary_vector_of_cross_product(float *first_vector, float *second_vector, float *dest);

void cross_product(float *first_vector, float *second_vector, float *dest);

void copy_vector(float *src_vector, float *dest_vector);

void convert_csv_to_vector(char *string_vector, float *float_vector);

#endif // TRIAD_H_INCLUDED
