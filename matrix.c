#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [ �� �� �� ]  [2018038014] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) { return -1; }

    do {
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch (command) {
        case 'z': case 'Z':
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A':
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S':
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T':
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    if (row <= 0 || col <= 0)   // row ���� col ���� 0���� �۰� �ԷµǸ� �ٽ� �Է��϶�� ��� ������ ���
    {
        printf("��� ���� �ڿ��� ����� �Է����ּ���.\n");
        return NULL;
    }

    int** x, i;
    x = (int**)malloc(row * sizeof(*x)); // row�� ũ�� ��ŭ ���� �����Ҵ�

    for (i = 0; i < row; i++)
    {
        x[i] = (int*)malloc(col * sizeof(**x));  //col�� ũ�� ��ŭ ���� �����Ҵ�

    }

    return x;         // �����Ҵ�� �迭�� ��ȯ�Ѵ�.
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)          // �Լ��� ����ϱ� ���� �Լ�
{
    int i, n;
  if (row <= 0 || col <= 0)                                 // row ���� col ���� 0���� �۰� �ԷµǸ� �ٽ� �Է��϶�� ��� ������ ���
    {
        printf("��� ���� �ڿ��� ����� �Է����ּ���.\n");
        return ;
    }


    for (i = 0; i < row; i++)
    {
        for (n = 0; n < col; n++)
        {
            printf("%5d", matrix[i][n]);                     // i��n���� 5ĭ �� ���
        }
        printf("\n");                                        //���� ���� ����ϱ� ���ؼ� ���� �ٲ��ش�
    }
    
    
    if (matrix == NULL) {
      printf("�Ÿ� �Ҵ� ����.\n");                            // matrix_a �� matrix_b�� NULL ���� ������ ���������� ����ϰ� -1�� ��ȯ�Ѵ�.
      return ;
   }
   return;
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)  
{
    if (row <= 0 || col <= 0)                                       // row ���� col ���� 0���� �۰� �ԷµǸ� �ٽ� �Է��϶�� ��� ������ ���
    {
        printf("��� ���� �ڿ��� ����� �Է����ּ���.\n");
        return NULL;
    }

    int i;
    for (i = 0; i < row; i++)       
    {
        free(matrix[i]);                                            // 2���� �迭�� ���� ���� �޸� ����
    }
    free(matrix);                                                   // 2���� �迭�� ���� ���� �޸� ����
    
    if (matrix == NULL) 
    {
      printf("�Ÿ� �Ҵ� ����.\n");                                    // matrix_a �� matrix_b�� NULL ���� ������ ���������� ����ϰ� -1�� ��ȯ�Ѵ�.
      return -1;
    }

    return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
    int i, n;
    if (row <= 0 || col <= 0)                                       // row ���� col ���� 0���� �۰� �ԷµǸ� �ٽ� �Է��϶�� ��� ������ ���
    {
        printf("��� ���� �ڿ��� ����� �Է����ּ���.\n");
        return NULL;
    }

    for (i = 0; i < row; i++)                                       //���� ũ�� ��ŭ �ݺ� 
    {
        for (n = 0; n < col; n++)                                   //���� ũ�� ��ŭ �ݺ�
        {
            matrix[i][n] = rand() % 20;                             //[i]��[n]���� �迭�� 0~19���̿� ���� ������ �ʱ�ȭ
        }
    }
    if (matrix == NULL)                                             // matrix_a �� matrix_b�� NULL ���� ������ ���������� ����ϰ� -1�� ��ȯ�Ѵ�.
    {
      printf("�Ÿ� �Ҵ� ����.\n");
      return -1;
    }
    return **matrix;                                                //�ʱ�ȭ �� �迭�� ��ȯ 
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_a_b_sum = create_matrix(row,col);                    //��� ���� ���� ������ ���������� �迭�� ���� �Ҵ� ���ش�.
    int i,n;
    if (row <= 0 || col <= 0)                                         // row ���� col ���� 0���� �۰� �ԷµǸ� �ٽ� �Է��϶�� ��� ������ ���
    {
        printf("��� ���� �ڿ��� ����� �Է����ּ���.\n");
        return NULL;
    }

    for(i=0;i<row;i++)                                               //���� ũ�� ��ŭ �ݺ� 
    {
        for(n=0;n<col;n++)                                           //���� ũ�� ��ŭ �ݺ�
        {
            matrix_a_b_sum[i][n]=matrix_a[i][n]+matrix_b[i][n];             //matrix_a��� + matrix_b�� ���ؼ� ��� sum�� ���� 
        }
    }
    print_matrix(matrix_a_b_sum,row,col);                            // ���a �� b�� ���� ���� ����Ѵ�.
    free_matrix(matrix_a_b_sum,row,col);                             // ���� �Ҵ��� �޸� ����

    if (matrix_a == NULL || matrix_b == NULL)                       // matrix_a �� matrix_b�� NULL ���� ������ ���������� ����ϰ� -1�� ��ȯ�Ѵ�.
    {
      printf("�Ÿ� �Ҵ� ����.\n");
      return -1;
    }
    return 1;

}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int i,n;
    int** matrix_a_b_sub = create_matrix(row,col);          // ��� ������ ���� ������ ���� ������ �迭�� �����Ҵ� ���ش�.
    if (row <= 0 || col <= 0)                               // row ���� col ���� 0���� �۰� �ԷµǸ� �ٽ� �Է��϶�� ��� ������ ���
    {
        printf("��� ���� �ڿ��� ����� �Է����ּ���.\n");
        return NULL;
    }

    for(i=0;i<row;i++)                                       // ���� ũ�⸸ŭ �ݺ�
    {
        for(n=0;n<col;n++)                                    //���� ũ�� ��ŭ �ݺ�
        {
            matrix_a_b_sub[i][n]=matrix_a[i][n]-matrix_b[i][n];    //matrix_a��� + matrix_b����� ���� ����� matrix_a_b_sub�� ����
        }
                                    
    }
    print_matrix(matrix_a_b_sub,row,col);                    //matrix_a_b_sub�� ���� ���
    free_matrix(matrix_a_b_sub,row,col);                     // �����Ҵ�� �޸� ����
    if (matrix_a == NULL || matrix_b == NULL)               // matrix_a �� matrix_b�� NULL ���� ������ ���������� ����ϰ� -1�� ��ȯ�Ѵ�.
    {
      printf("�Ÿ� �Ҵ� ����.\n");
      return -1;
    }
    return 0;

}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)      // ��� a�� ��ġ�Ѵ�.
{
    int i,n;                    
    if (row <= 0 || col <= 0)                                            // row ���� col ���� 0���� �۰� �ԷµǸ� �ٽ� �Է��϶�� ��� ������ ���
    {
        printf("��� ���� �ڿ��� ����� �Է����ּ���.\n");
        return NULL;
    }
                                          
    for(i=0;i<row;i++)                                                    // ��ġ��� a�� ���� ũ�� ��ŭ �ݺ��Ѵ�                                    
    {
        for(n=0;n<col;n++)                                                // ��ġ�࿭ a�� ���� ũ�� ��ŭ �ݺ��Ѵ�.
        {
            matrix_t[i][n] = matrix[n][i];                                // ��� a�� ��ġ��� a�� �����Ѵ�. 
        }
    }
    if (matrix == NULL || matrix_t == NULL)                                // matrix_a �� matrix_b�� NULL ���� ������ ���������� ����ϰ� -1�� ��ȯ�Ѵ�.
    {
      printf("�Ÿ� �Ҵ� ����.\n");
      return -1;
    }

    return **matrix_t;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)   // ��� A�� ��ġ���A�� ���� ����Ѵ�.
{
    if (row <= 0 || col <= 0)                                           // row ���� col ���� 0���� �۰� �ԷµǸ� �ٽ� �Է��϶�� ��� ������ ���
    {
        printf("��� ���� �ڿ��� ����� �Է����ּ���.\n");
        return NULL;
    }

    int** matrix_axt = create_matrix(row,col);
    int i,n,k;
    int sum;                                                            // ��� ���� ���� �����Ѵ�. 
    
    for(i=0;i<row;i++)                                                  // A����� ���� ũ�⸸ŭ �ݺ�
    {
        for(n=0;n<row;n++)                                              //B����� ���� ũ�� ��ŭ �ݺ�
        {
            sum = 0;                                                    // 0���� �ʱ�ȭ �ؼ� ���� ����� ���� ���� �����Ѵ�.
            for(k=0;k<col;k++)                                          // B����� ���� ũ�� ��ŭ �ݺ�
            {   
                sum+=(matrix_a[i][k]*matrix_t[k][n]);                   // ����� ���� �� ���Ѵ�.
            }
            matrix_axt[i][n] = sum;                                          // ���� ����� ���� matrix_axt�� ����
        }
        
    }
    print_matrix(matrix_axt,row,row);                                   // ��� ���� �� ���� ����Ѵ�.
    free_matrix(matrix_axt,row,row);                                    // �����޸� ���� 
    if (matrix_a == NULL || matrix_t == NULL)                           // matrix_a �� matrix_b�� NULL ���� ������ ���������� ����ϰ� -1�� ��ȯ�Ѵ�.
    {
      printf("�Ÿ� �Ҵ� ����.\n");
      return -1;
    }

    return 1;
}
