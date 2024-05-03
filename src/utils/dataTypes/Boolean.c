#include "../../../inc/utils/dataTypes/Boolean.h"

/**
 * Function to perform logical NOT operation on a boolean value.
 *
 * @param a The boolean value to be negated.
 * @return The negated boolean value.
 */
boolean not(boolean a)
{
    return (a.value == 0) ? true : false;
}

/**
 * Function to perform logical AND operation on two boolean values.
 *
 * @param a The first boolean value.
 * @param b The second boolean value.
 * @return The result of the logical AND operation.
 */
boolean and (boolean a, boolean b)
{
    return (a.value != 0 && b.value != 0) ? true : false;
}

/**
 * Function to perform logical OR operation on two boolean values.
 *
 * @param a The first boolean value.
 * @param b The second boolean value.
 * @return The result of the logical OR operation.
 */
boolean or (boolean a, boolean b)
{
    return (a.value != 0 || b.value != 0) ? true : false;
}