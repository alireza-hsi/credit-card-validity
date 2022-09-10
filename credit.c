#include <cs50.h>
#include <stdio.h>

// declaring the functions
long get_cn(void);
int check_validity(long credit_number);
int digit(long n);
int id(long c_n);

// declaring the variables
int digits;
long cn;
int r;
int sum;
long test;
int first_digit;

int main(void) 
{

    // storing credit number in a variable
    //long credit_number = 
    get_cn();
    check_validity(cn);    
    // check by algorithm and printf the right statement according to the number of digits
    if (digits == 15)
    {
        //check_validity(cn);
        if (r == 1)
        {
            printf("AMEX\n");
        }
        else if (r == 0)
        {
            printf("INVALID\n");
        }
        
    }
    else if (digits == 16 && (first_digit == 5 || first_digit == 2))
    {
        // check_validity(cn);
        if (r == 1)
        {
            printf("MASTERCARD\n");
        }
        else if (r == 0)
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 13)
    {
        //check_validity(cn);
        if (r == 1)
        {
            printf("VISA\n");
        }
        else if (r == 0)
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 16 && first_digit == 4)
    {
        //check_validity(cn);
        if (r == 1)
        {
            printf("VISA\n");
        }
        else if (r == 0)
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    
}


// a function to prompt user to enter the credit card number and check if it is consisted of right number of digits and if not so, prompt the user again
long get_cn(void)
{
    
    do 
    {
        digits = 0;
        cn = get_long("enter your credit number ");
        digits = digit(cn);
        //printf("%i \n", digits);
    }
    while (digits < 10);
    return digits;
    return cn;
}

// a function to declare the number of digits in the credit card number
int digit(long n)
{
    int count = 0;
    do 
    {
        n /= 10;
        ++count;
    } 
    while (n != 0);
    return count;
}

// a function to check the credit card number by the Luhn's Algorithm. It should return r == 1 if its valid and r == 0 if its not valid.
int check_validity(long credit_number)
{
    id(cn);
    int chk = sum % 10;
    if (chk == 0)
    {
        r = 1;
    }
    else
    {
        r = 0;
    }
    return r;
}


// indexing digits. assigning them to an array
int id(long c_n)
{
    test = c_n;

    int index1 = (((((test % 100) / 10) * 2) % 100) / 10) + ((((test % 100) / 10) * 2) % 10) ;
    int index2 = (((((test % 10000) / 1000) * 2) % 100) / 10) + ((((test % 10000) / 1000) * 2) % 10) ;
    int index3 = (((((test % 1000000) / 100000) * 2) % 100) / 10) + ((((test % 1000000) / 100000) * 2) % 10) ;
    int index4 = (((((test % 100000000) / 10000000) * 2) % 100) / 10) + ((((test % 100000000) / 10000000) * 2) % 10) ;
    int index5 = (((((test % 10000000000) / 1000000000) * 2) % 100) / 10) + ((((test % 10000000000) / 1000000000) * 2) % 10) ;
    int index6 = (((((test % 1000000000000) / 100000000000) * 2) % 100) / 10) + ((((test % 1000000000000) / 100000000000) * 2) % 10) ;
    int index7 = (((((test % 100000000000000) / 10000000000000) * 2) % 100) / 10) + ((((test % 100000000000000) / 10000000000000) * 2) %
                 10) ;
    int index8 = (((((test % 10000000000000000) / 1000000000000000) * 2) % 100) / 10) + ((((test % 10000000000000000) / 
                 1000000000000000) * 2) % 10) ;
    int index9 = (test % 10) / 1;
    int index10 = (test % 1000) / 100;
    int index11 = (test % 100000) / 10000;
    int index12 = (test % 10000000) / 1000000;
    int index13 = (test % 1000000000) / 100000000;
    int index14 = (test % 100000000000) / 10000000000;
    int index15 = (test % 10000000000000) / 1000000000000;
    int index16 = (test % 1000000000000000) / 100000000000000;

    first_digit = (test % 10000000000000000) / 1000000000000000;

    
    sum = index1 + index2 + index3 + index4 + index5 + index6 + index7 + index8 + index9 + index10 + index11 + index12 + index13 +
          index14 + index15 + index16;
    //printf("%i" , sum);
    return sum;
    return test;
    

}