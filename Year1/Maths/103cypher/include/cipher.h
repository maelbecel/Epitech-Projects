/*
** EPITECH PROJECT, 2021
** cipher.h
** File description:
** cipher
*/

#ifndef CIPHER
    #define CIPHER

    typedef struct cipher {
        float size_key;
        float size_msg;
        float y_msg;
    } cipher_t;

    float **create_key(char **av, cipher_t *cipher);
    float **put_key_to_matrix(char **av, cipher_t *cipher);
    float **create_matrix(int x, int y);
    float *msg_to_ascii(char **av, cipher_t *cipher);
    float *msg_to_float(char **av, cipher_t *cipher);
    float **msg_to_matrix(float *msg, cipher_t *cipher);
    float **product_matrice(float **key, float **mat, cipher_t *cipher);
    float det_2x2(float **key);
    float det_3x3(float **key);
    float **inverse_key_2x2(float **key);
    float **calcul_inverse_2x2(float **key, float det);
    float **calcul_inverse_3x3(float **key, float det);
    float **comatrice_key(float **key);
    float **transpose_key(float **key);
    char *matrice_to_str(float **matrice, cipher_t *cipher);
    void print_array(float **array, int x, int y);

#endif /* !CIPHER */
