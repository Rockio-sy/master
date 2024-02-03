#include <stdio.h>
#include <stdlib.h>

#include "read_action_and_num.h"
#include "action_processor.h"

int main(void)
{
    int rc = EXIT_SUCCESS, action = 0;
    rc = read_action(&action);
    if (rc == EXIT_SUCCESS)
    {
        if (action == OUT)
            rc = action_out();
        else if (action == MUL)
            rc = action_mul();
        else if (action == SQR)
            rc = action_sqr();
        else if (action == DIV)
            rc = action_div();
    }

    return rc;
}