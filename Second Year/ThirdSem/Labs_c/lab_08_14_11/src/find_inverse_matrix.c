#include "find_inverse_matrix.h"

double det_matrix(matrix_t *matrix)
{
    double det = 1.0;

    if (matrix->matrix[0][0] == 0)
    {
        int obm = 0;
        for (int i = 0; i < matrix->n && obm == 0; i++)
            if (matrix->matrix[i][0] != 0)
                obm = i;

        if (obm > 0)
            swap_column(matrix->matrix[0], matrix->matrix[obm], matrix->n);
        det = -det;
    }

    int out = 0;
    for (int i = 0; i < matrix->n && !out; i++)
    {
        int k = i;
        for (int j = i + 1; j < matrix->n; j++)
            if (fabs(matrix->matrix[j][i]) > fabs(matrix->matrix[k][i]))
                k = j;
        if (fabs(matrix->matrix[k][i]) < EPS)
        {
            det = 0;
            out = 1;
        }
        else
        {
            swap_column(matrix->matrix[i], matrix->matrix[k], matrix->m);
            det *= matrix->matrix[i][i];
            for (int j = i + 1; j < matrix->n; j++)
                if (fabs(matrix->matrix[i][i]) > EPS && fabs(matrix->matrix[i][j]) > EPS)
                    matrix->matrix[i][j] /= matrix->matrix[i][i];
            for (int j = 0; j < matrix->n; ++j)
                if (j != i && fabs(matrix->matrix[j][i]) > EPS)
                    for (int k = i + 1; k < matrix->n; k++)
                        matrix->matrix[j][k] -= matrix->matrix[i][k] * matrix->matrix[j][i];
        }
    }
    if (fabs(det) < EPS)
        det = 0;
    return det;
}

int check_degenerate_matrix(const matrix_t *matrix)
{
    int degenerate = 0;
    double det = 0.0;

    matrix_t copy;
    default_usual_matrix(&copy);

    copy.matrix = (double **) allocate_matrix_third(matrix->n, matrix->m);
    if (!copy.matrix)
        degenerate = MEMORY_ERROR;
    else
    {
        copy_matrix(&copy, matrix);
        det = det_matrix(&copy);
        if (fabs(det) < EPS)
            degenerate = 1;
    }

    free_matrix_third(&copy.matrix);
    return degenerate;
}

void fill_last_column_square_matrix(double **slau, int j_ind, int j_last)
{
    for (int i = 0; i < j_last; i++)
        if (i == j_ind)
            slau[i][j_last] = 1.0;
        else
            slau[i][j_last] = 0.0;
}

void zeroing_the_lower_right_corner(matrix_t *slau, matrix_t *origin)
{
    for (int k = 0; k < slau->n; k++)
    {
        for (int i = 0; i < slau->m; i++)
            if (fabs(slau->matrix[k][i]) >= EPS && fabs(origin->matrix[k][k]) >= EPS)
                slau->matrix[k][i] = slau->matrix[k][i] / origin->matrix[k][k];

        for (int i = k + 1; i < slau->n; i++)
        {
            double kd = 0.0;
            if (fabs(slau->matrix[i][k]) >= EPS && fabs(slau->matrix[k][k]) >= EPS)
                kd = slau->matrix[i][k] / slau->matrix[k][k];
            for (int j = 0; j < slau->m; j++)
                slau->matrix[i][j] = slau->matrix[i][j] - slau->matrix[k][j] * kd;
        }

        for (int i = 0; i < slau->n; i++)
            for (int j = 0; j < slau->n; j++)
                origin->matrix[i][j] = slau->matrix[i][j];
    }
}

void zeroing_the_upper_left_corner(matrix_t *slau, matrix_t *origin)
{
    for (int k = slau->n - 1; k >= 0; k--)
    {
        for (int i = slau->n; i >= 0; i--)
            if (fabs(slau->matrix[k][i]) >= EPS && fabs(origin->matrix[k][k]) >= EPS)
                slau->matrix[k][i] = slau->matrix[k][i] / origin->matrix[k][k];

        for (int i = k - 1; i >= 0; i--)
        {
            double kd = 0.0;
            if (fabs(slau->matrix[i][k]) >= EPS && fabs(slau->matrix[k][k]) >= EPS)
                kd = slau->matrix[i][k] / slau->matrix[k][k];
            for (int j = slau->m - 1; j >= 0; j--)
                slau->matrix[i][j] = slau->matrix[i][j] - slau->matrix[k][j] * kd;
        }

        for (int i = 0; i < slau->n; i++)
            for (int j = 0; j < slau->n; j++)
                origin->matrix[i][j] = slau->matrix[i][j];
    }
}

void add_inverse_column(matrix_t *inverse_column, const matrix_t *slau, int obm, int j_ind)
{
    for (int i = 0; i < inverse_column->n; i++)
        if (obm > 0)
        {
            if (obm == j_ind)
                inverse_column->matrix[i][0] = slau->matrix[i][slau->m - 1];
            else if (j_ind == 0)
                inverse_column->matrix[i][obm] = slau->matrix[i][slau->m - 1];
            else
                inverse_column->matrix[i][j_ind] = slau->matrix[i][slau->m - 1];
        }
        else
            inverse_column->matrix[i][j_ind] = slau->matrix[i][slau->m - 1];
}

int find_column_inverse_matrix(matrix_t *inverse_column, const matrix_t *origin, int j_ind)
{
    int rc = EXIT_SUCCESS;
    matrix_t slau, copy_origin;
    default_usual_matrix(&slau);
    default_usual_matrix(&copy_origin);

    slau.matrix = (double **) allocate_matrix_third(origin->n, origin->m + 1);
    copy_origin.matrix = (double **) allocate_matrix_third(origin->n, origin->m);
    if (!slau.matrix || !copy_origin.matrix)
        rc = MEMORY_ERROR;
    else
    {
        copy_matrix(&slau, origin);
        fill_last_column_square_matrix(slau.matrix, j_ind, slau.m);
        int obm = 0;
        if (slau.matrix[0][0] == 0)
        {
            for (int i = 0; i < slau.n && obm == 0; i++)
                if (slau.matrix[i][0] != 0)
                    obm = i;
            swap_column(slau.matrix[0], slau.matrix[obm], slau.n);
        }
        copy_matrix(&copy_origin, &slau);
        slau.m++;

        zeroing_the_lower_right_corner(&slau, &copy_origin);
        zeroing_the_upper_left_corner(&slau, &copy_origin);

        add_inverse_column(inverse_column, &slau, obm, j_ind);
    }

    free_matrix_third(&slau.matrix);
    free_matrix_third(&copy_origin.matrix);
    return rc;
}

int gaussian_inverse_matrix(matrix_t *inverse, matrix_t *origin)
{
    int rc = EXIT_SUCCESS;
    if (check_matrix_params(inverse) || !check_matrix_params(origin))
        rc = PARAMS_ERROR;
    else
    {
        if (origin->n != origin->m)
            rc = INVERSE_MATRIX_ERROR;
        else if (check_degenerate_matrix(origin))
            rc = NON_DEG_ERROR;
        else
        {
            inverse->n = origin->n;
            inverse->m = origin->m;
            inverse->matrix = (double **) allocate_matrix_third(origin->n, origin->m);
            if (!inverse->matrix)
                rc = MEMORY_ERROR;
            else
            {
                for (int j = 0; j < origin->m && rc == 0; j++)
                    rc = find_column_inverse_matrix(inverse, origin, j);
            }
        }
    }

    return rc;
}