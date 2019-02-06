#include <stdio.h>
#include <stdlib.h>
#include "triad.h"

int main()
{
    char input_buffer[CSV_LENGTH];

    //In my case the measurement of the sun vector is the most accurate
    VECTOR sun_body;
    VECTOR sun_inertial;
    VECTOR magnetic_field_body;
    VECTOR magnetic_field_inertial;

    VECTOR t1b, t2b, t3b;
    VECTOR t1i, t2i, t3i;
    MATRIX Rbt, Rti, Rbi;

    printf("\n[+] Enter the sun vector respect to the body frame (comma separated): ");
    gets(input_buffer);
    convert_csv_to_vector(input_buffer, sun_body);

    printf("[+] Enter the magnetic field vector respect to the body frame (comma separated): ");
    gets(input_buffer);
    convert_csv_to_vector(input_buffer, magnetic_field_body);

    printf("[+] Enter the sun vector respect to the inertial frame (comma separated): ");
    gets(input_buffer);
    convert_csv_to_vector(input_buffer, sun_inertial);

    printf("[+] Enter the magnetic field vector respect to the inertial frame (comma separated): ");
    gets(input_buffer);
    convert_csv_to_vector(input_buffer, magnetic_field_inertial);

    copy_vector(sun_body, t1b);
    unitary_vector_of_cross_product(sun_body, magnetic_field_body, t2b);
    cross_product(t1b, t2b, t3b);

    copy_vector(sun_inertial, t1i);
    unitary_vector_of_cross_product(sun_inertial, magnetic_field_inertial, t2i);
    cross_product(t1i, t2i, t3i);

    print_vector("t1b T", t1b);
    print_vector("t2b T", t2b);
    print_vector("t3b T", t3b);
    print_vector("t1i T", t1i);
    print_vector("t2i T", t2i);
    print_vector("t3i T", t3i);

    create_matrix_from_vectors(t1b, t2b, t3b, Rbt);
    create_matrix_from_vectors(t1i, t2i, t3i, Rti);

    transponse_matrix(Rti);

    print_matrix("RbT", Rbt);
    print_matrix("RTi", Rti);

    matrix_multiplication(Rbt, Rti, Rbi);

    printf("\nThe rotation matrix is: \n \n");

    print_matrix("Rbi", Rbi);

    printf("\n");
    system("PAUSE");

    return EXIT_SUCCESS;
}
