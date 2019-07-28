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
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "triad.h"

void transponse_matrix(float *matrix)
{
    float temp;

    temp = matrix[3];
    matrix[3] = matrix[1];
    matrix[1] = temp;

    temp = matrix[6];
    matrix[6] = matrix[2];
    matrix[2] = temp;

    temp = matrix[7];
    matrix[7] = matrix[5];
    matrix[5] = temp;
}

void matrix_multiplication(float *first_matrix, float *second_matrix, float *dest)
{
    dest[0] = ((first_matrix[0] * second_matrix[0]) + (first_matrix[1] * second_matrix[3]) + (first_matrix[2] * second_matrix[6]));
    dest[1] = ((first_matrix[0] * second_matrix[1]) + (first_matrix[1] * second_matrix[4]) + (first_matrix[2] * second_matrix[7]));
    dest[2] = ((first_matrix[0] * second_matrix[2]) + (first_matrix[1] * second_matrix[5]) + (first_matrix[2] * second_matrix[8]));

    dest[3] = ((first_matrix[3] * second_matrix[0]) + (first_matrix[4] * second_matrix[3]) + (first_matrix[5] * second_matrix[6]));
    dest[4] = ((first_matrix[3] * second_matrix[1]) + (first_matrix[4] * second_matrix[4]) + (first_matrix[5] * second_matrix[7]));
    dest[5] = ((first_matrix[3] * second_matrix[2]) + (first_matrix[4] * second_matrix[5]) + (first_matrix[5] * second_matrix[8]));

    dest[6] = ((first_matrix[6] * second_matrix[0]) + (first_matrix[7] * second_matrix[3]) + (first_matrix[8] * second_matrix[6]));
    dest[7] = ((first_matrix[6] * second_matrix[1]) + (first_matrix[7] * second_matrix[4]) + (first_matrix[8] * second_matrix[7]));
    dest[8] = ((first_matrix[6] * second_matrix[2]) + (first_matrix[7] * second_matrix[5]) + (first_matrix[8] * second_matrix[8]));
}

void create_matrix_from_vectors(float *first_vector, float *second_vector, float *third_vector, float *dest)
{
    for(int i = 0; i < VECTOR_LENGTH; i++)
    {
        for(int j = 0; j < VECTOR_LENGTH; j++)
        {
            if(j == 0)
                *dest = first_vector[i];

            else if(j == 1)
                *dest = second_vector[i];

            else if(j == 2)
                *dest = third_vector[i];

            dest++;
        }
    }
}

void print_matrix(char *matrix_name, float *matrix)
{
    printf("\n%s = [    %-11.4f%-11.4f%-11.4f]", matrix_name, matrix[0], matrix[1], matrix[2]);
    printf("\n      [    %-11.4f%-11.4f%-11.4f]", matrix[3], matrix[4], matrix[5]);
    printf("\n      [    %-11.4f%-11.4f%-11.4f]\n", matrix[6], matrix[7], matrix[8]);
}

void print_vector(char *vector_name, float *_vector)
{
    printf("\n%s = [    %-11.4f%-11.4f%-11.4f]\n", vector_name, _vector[0], _vector[1], _vector[2]);
}

void unitary_vector_of_cross_product(float *first_vector, float *second_vector, float *dest)
{
    float buffer[VECTOR_LENGTH];
    float module = 0;

    buffer[0] = (first_vector[1] * second_vector[2]) - (second_vector[1] * first_vector[2]);
    buffer[1] = ((first_vector[0] * second_vector[2]) - (second_vector[0] * first_vector[2])) * -1;
    buffer[2] = (first_vector[0] * second_vector[1]) - (second_vector[0] * first_vector[1]);

    module = sqrt(pow(buffer[0],2) + pow(buffer[1],2) + pow(buffer[2],2));

    for (int i = 0; i < VECTOR_LENGTH; i++)
        dest[i] = buffer[i] / module;
}

void cross_product(float *first_vector, float *second_vector, float *dest)
{
    dest[0] = (first_vector[1] * second_vector[2]) - (second_vector[1] * first_vector[2]);
    dest[1] = ((first_vector[0] * second_vector[2]) - (second_vector[0] * first_vector[2])) * -1;
    dest[2] = (first_vector[0] * second_vector[1]) - (second_vector[0] * first_vector[1]);
}

void copy_vector(float *src_vector, float *dest_vector)
{
    while(*src_vector)
    {
        *dest_vector = *src_vector;
        dest_vector++;
        src_vector++;
    }
}

void convert_csv_to_vector(char *string_vector, float *float_vector)
{
    char buffer[CSV_LENGTH];
    int index = 0;

    while(*string_vector)
    {
        if(*string_vector == ',')
        {
            *float_vector = atof(buffer);
            memset(buffer, NULL, CSV_LENGTH);
            float_vector++;
            index = 0;
        }
        else
        {
            buffer[index] = *string_vector;
            index++;
        }
        string_vector++;
    }
    *float_vector = atof(buffer);
}
