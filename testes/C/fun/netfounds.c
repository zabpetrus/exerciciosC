#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
struct stackNode {
    char data;
    struct stackNode *nextPtr;
};
 
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;
 
 
void convertToPostfix( char infix[], char postfix[] );
//isOperator completed
int isOperator( char c );
//precedence completed
int precedence( char operator1, char operator2 );
//push completed
void push( StackNodePtr *topPtr, char value );
//pop completed
char pop( StackNodePtr *topPtr );
char stackTop( StackNodePtr topPtr );
int isEmpty( StackNodePtr topPtr );
void printStack( StackNodePtr topPtr );
 
 
 
int main()
{
    char iFix[ 10 ] = "(6 + 2)";
    char pFix[ 10 ] = { 0 };
 
    convertToPostfix( iFix, pFix );
    printf( "%s\n", pFix );
 
    return 0;
}
 
 
 
void convertToPostfix( char infix[], char postfix[] )
{
    StackNode *stack = NULL;
    char temp[ 2 ] = ")";
    push( &stack, '(' );
 
/*   APPENDS ")\0" to the end of infix  */
    strcat( infix, temp );
 
 
    while( !isEmpty( stack ) ) {
 
 
        if ( isdigit( *infix ) ) {
            *postfix = *infix;
            postfix += 2;
        }
         
        if ( *infix == '(' )
            push( &stack, *infix );
 
        if ( isOperator( *infix ) ) {
            if ( precedence( stackTop( stack ), *infix ) == 0 || precedence( stackTop( stack ), *infix ) == 1 ) {
                *postfix = pop( &stack );
                postfix += 2;
                push( &stack, *infix );
            }
            else
                push( &stack, *infix );
        }
 
        if ( *infix == ')' ) {
            while ( stackTop( stack ) != '(' ) {
                *postfix = pop( &stack );
                postfix += 2;
            }
            pop( &stack );
        }
 
        ++infix;
    }
 
}
 
 
 
void printStack( StackNode *topPtr )
{
    while ( topPtr != NULL ) {
        printf( "%c", topPtr->data );
        topPtr = topPtr->nextPtr;
    }
 
    printf( "\n" );
}
 
 
 
int isEmpty( StackNode *topPtr )
{
    if ( topPtr == NULL )
        return 1;
    else
        return 0;
}
 
 
 
char pop( StackNode **topPtr )
{
    char output;
    StackNode *tempPtr = NULL;
 
    output = ( *topPtr )->data;
    tempPtr = *topPtr;
    *topPtr = ( *topPtr )->nextPtr;
    free( *topPtr );
 
    return output;  
 
}
 
 
char stackTop( StackNode *topPtr )
{
    if ( topPtr != NULL )
        return topPtr->data;
    else
        return ' ';
 
}
 
 
void push( StackNode **topPtr, char value )
{
    
    StackNode *newPtr;
    newPtr = (StackNode *) calloc( 1, sizeof( StackNode ) );
     
    if ( newPtr != NULL ) {
        newPtr->nextPtr = *topPtr;
        newPtr->data = value;
 
        *topPtr = newPtr;
    }
}
 
 
int isOperator( char c )
{
    if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' )
        return 1;
 
    else
        return 0;
 
 
}
 
 
//Determine if precedence of operator1 is greater(1), equal(0), or less then(-1) operator2
int precedence( char operator1, char operator2 )
{
    int opValue[ 2 ] = { 0 };
    char operator[ 2 ];
    operator[ 0 ] = operator1;
    operator[ 1 ] = operator2;
    int i = 0;
 
    for ( i = 0; i < 2; ++i ) {
        switch( operator[ i ] ) {
            case '+': case '-':
                opValue[ i ] = 1;
                break;
            case '*': case '/': case '%':
                opValue[ i ] = 2;
                break;
            case '^':
                opValue[ i ] = 3;
                break;
            case '(': case ')':
                opValue[ i ] = 4;
                break;
        }
 
    }
 
    if ( opValue[ 0 ] > opValue[ 1 ] )
        return 1;
    if ( opValue[ 0 ] == opValue[ 1 ] )
        return 0;
    else
        return -1;
}
