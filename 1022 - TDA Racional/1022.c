#include <stdio.h>

int calcularMDC(int m, int n)
{
    if (n == 0) return m;
    else return calcularMDC(n, m % n);
}

int main(int argc, char const *argv[])
{
    int testes;
    scanf("%d", &testes);

    while (testes > 0)
    {
        int n1, d1, n2, d2;
        char op1, op2, op3;

        // racional 1
        scanf("%d", &n1);
        scanf(" %c", &op1);
        scanf("%d", &d1);
        
        // op
        scanf(" %c", &op2);

        // racional 2
        scanf("%d", &n2);
        scanf(" %c", &op3);
        scanf("%d", &d2);

        //printf("%d %c %d %c %d %c %d\n", n1, op1, d1, op2, n2, op3, d2);



        int n3, d3;
        /*
        Soma: (N1*D2 + N2*D1) / (D1*D2)
        Subtração: (N1*D2 - N2*D1) / (D1*D2)
        Multiplicação: (N1*N2) / (D1*D2)
        Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)
        */
        switch (op2)
        {
        case '+':
            n3 = n1 * d2 + n2 * d1;
            d3 = d1 * d2;
            break;
        
        case '-':
            n3 = n1 * d2 - n2 * d1;
            d3 = d1 * d2;
            break;
        
        case '*':
            n3 = n1 * n2;
            d3 = d1 * d2;
            break;

        case '/':
            n3 = n1 * d2;
            d3 = n2 * d1;
            break;

        default:
            break;
        }

        int nFinal, dFinal, mdc;

        mdc = calcularMDC(n3, d3);
        nFinal = n3 / mdc;
        dFinal = d3 / mdc;

        if (dFinal < 0)
        {
            dFinal *= -1;
            nFinal *= -1;
        }

        printf("%d/%d = %d/%d\n", n3, d3, nFinal, dFinal);

        testes--;
    }
    return 0;
}
