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
    printf("[----- [ 김 윤 희 ]  [2018038014] -----]\n");

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
    if (row <= 0 || col <= 0)   // row 값과 col 값이 0보다 작게 입력되면 다시 입력하라는 경고 문구를 출력
    {
        printf("행과 열를 자연수 양수로 입력해주세요.\n");
        return NULL;
    }

    int** x, i;
    x = (int**)malloc(row * sizeof(*x)); // row의 크기 만큼 행을 동적할당

    for (i = 0; i < row; i++)
    {
        x[i] = (int*)malloc(col * sizeof(**x));  //col의 크기 만큼 열을 동적할당

    }

    return x;         // 동적할당된 배열을 반환한다.
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)          // 함수를 출력하기 위한 함수
{
    int i, n;
  if (row <= 0 || col <= 0)                                 // row 값과 col 값이 0보다 작게 입력되면 다시 입력하라는 경고 문구를 출력
    {
        printf("행과 열를 자연수 양수로 입력해주세요.\n");
        return ;
    }


    for (i = 0; i < row; i++)
    {
        for (n = 0; n < col; n++)
        {
            printf("%5d", matrix[i][n]);                     // i행n열을 5칸 띄어서 출력
        }
        printf("\n");                                        //다음 행을 출력하기 위해서 줄을 바꿔준다
    }
    
    
    if (matrix == NULL) {
      printf("매모리 할당 실패.\n");                            // matrix_a 와 matrix_b에 NULL 값이 있으면 오류문구를 출력하고 -1을 반환한다.
      return ;
   }
   return;
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)  
{
    if (row <= 0 || col <= 0)                                       // row 값과 col 값이 0보다 작게 입력되면 다시 입력하라는 경고 문구를 출력
    {
        printf("행과 열를 자연수 양수로 입력해주세요.\n");
        return NULL;
    }

    int i;
    for (i = 0; i < row; i++)       
    {
        free(matrix[i]);                                            // 2차원 배열의 가로 공간 메모리 해제
    }
    free(matrix);                                                   // 2차원 배열의 세로 공간 메모리 해제
    
    if (matrix == NULL) 
    {
      printf("매모리 할당 실패.\n");                                    // matrix_a 와 matrix_b에 NULL 값이 있으면 오류문구를 출력하고 -1을 반환한다.
      return -1;
    }

    return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
    int i, n;
    if (row <= 0 || col <= 0)                                       // row 값과 col 값이 0보다 작게 입력되면 다시 입력하라는 경고 문구를 출력
    {
        printf("행과 열를 자연수 양수로 입력해주세요.\n");
        return NULL;
    }

    for (i = 0; i < row; i++)                                       //행의 크기 만큼 반복 
    {
        for (n = 0; n < col; n++)                                   //열의 크기 만큼 반복
        {
            matrix[i][n] = rand() % 20;                             //[i]행[n]열의 배열에 0~19사이에 난수 값으로 초기화
        }
    }
    if (matrix == NULL)                                             // matrix_a 와 matrix_b에 NULL 값이 있으면 오류문구를 출력하고 -1을 반환한다.
    {
      printf("매모리 할당 실패.\n");
      return -1;
    }
    return **matrix;                                                //초기화 된 배열을 반환 
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_a_b_sum = create_matrix(row,col);                    //행렬 합의 값을 저장할 이중포인터 배열을 동적 할당 해준다.
    int i,n;
    if (row <= 0 || col <= 0)                                         // row 값과 col 값이 0보다 작게 입력되면 다시 입력하라는 경고 문구를 출력
    {
        printf("행과 열를 자연수 양수로 입력해주세요.\n");
        return NULL;
    }

    for(i=0;i<row;i++)                                               //행의 크기 만큼 반복 
    {
        for(n=0;n<col;n++)                                           //열의 크기 만큼 반복
        {
            matrix_a_b_sum[i][n]=matrix_a[i][n]+matrix_b[i][n];             //matrix_a행렬 + matrix_b를 더해서 행렬 sum에 저장 
        }
    }
    print_matrix(matrix_a_b_sum,row,col);                            // 행렬a 와 b의 합의 값을 출력한다.
    free_matrix(matrix_a_b_sum,row,col);                             // 동적 할당한 메모리 해제

    if (matrix_a == NULL || matrix_b == NULL)                       // matrix_a 와 matrix_b에 NULL 값이 있으면 오류문구를 출력하고 -1을 반환한다.
    {
      printf("매모리 할당 실패.\n");
      return -1;
    }
    return 1;

}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int i,n;
    int** matrix_a_b_sub = create_matrix(row,col);          // 행렬 뺄셈의 값을 저장할 이중 포인터 배열을 동적할당 해준다.
    if (row <= 0 || col <= 0)                               // row 값과 col 값이 0보다 작게 입력되면 다시 입력하라는 경고 문구를 출력
    {
        printf("행과 열를 자연수 양수로 입력해주세요.\n");
        return NULL;
    }

    for(i=0;i<row;i++)                                       // 행의 크기만큼 반복
    {
        for(n=0;n<col;n++)                                    //열의 크기 만큼 반복
        {
            matrix_a_b_sub[i][n]=matrix_a[i][n]-matrix_b[i][n];    //matrix_a행렬 + matrix_b행렬의 뺄샘 결과를 matrix_a_b_sub에 저장
        }
                                    
    }
    print_matrix(matrix_a_b_sub,row,col);                    //matrix_a_b_sub의 값을 출력
    free_matrix(matrix_a_b_sub,row,col);                     // 동적할당된 메모리 해제
    if (matrix_a == NULL || matrix_b == NULL)               // matrix_a 와 matrix_b에 NULL 값이 있으면 오류문구를 출력하고 -1을 반환한다.
    {
      printf("매모리 할당 실패.\n");
      return -1;
    }
    return 0;

}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)      // 행렬 a를 전치한다.
{
    int i,n;                    
    if (row <= 0 || col <= 0)                                            // row 값과 col 값이 0보다 작게 입력되면 다시 입력하라는 경고 문구를 출력
    {
        printf("행과 열를 자연수 양수로 입력해주세요.\n");
        return NULL;
    }
                                          
    for(i=0;i<row;i++)                                                    // 전치행렬 a의 행의 크기 만큼 반복한다                                    
    {
        for(n=0;n<col;n++)                                                // 전치행열 a의 열의 크기 만큼 반복한다.
        {
            matrix_t[i][n] = matrix[n][i];                                // 행렬 a를 전치행렬 a에 저장한다. 
        }
    }
    if (matrix == NULL || matrix_t == NULL)                                // matrix_a 와 matrix_b에 NULL 값이 있으면 오류문구를 출력하고 -1을 반환한다.
    {
      printf("매모리 할당 실패.\n");
      return -1;
    }

    return **matrix_t;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)   // 행렬 A와 전치행렬A의 곱을 출력한다.
{
    if (row <= 0 || col <= 0)                                           // row 값과 col 값이 0보다 작게 입력되면 다시 입력하라는 경고 문구를 출력
    {
        printf("행과 열를 자연수 양수로 입력해주세요.\n");
        return NULL;
    }

    int** matrix_axt = create_matrix(row,col);
    int i,n,k;
    int sum;                                                            // 행렬 곱의 값을 저장한다. 
    
    for(i=0;i<row;i++)                                                  // A행렬의 행의 크기만큼 반복
    {
        for(n=0;n<row;n++)                                              //B행렬의 열의 크기 만큼 반복
        {
            sum = 0;                                                    // 0으로 초기화 해서 다음 행렬의 곱의 값을 저장한다.
            for(k=0;k<col;k++)                                          // B행렬의 행의 크기 만큼 반복
            {   
                sum+=(matrix_a[i][k]*matrix_t[k][n]);                   // 행렬의 곱을 다 더한다.
            }
            matrix_axt[i][n] = sum;                                          // 더한 행렬의 값을 matrix_axt에 저장
        }
        
    }
    print_matrix(matrix_axt,row,row);                                   // 행렬 곱을 한 값을 출력한다.
    free_matrix(matrix_axt,row,row);                                    // 동적메모리 해제 
    if (matrix_a == NULL || matrix_t == NULL)                           // matrix_a 와 matrix_b에 NULL 값이 있으면 오류문구를 출력하고 -1을 반환한다.
    {
      printf("매모리 할당 실패.\n");
      return -1;
    }

    return 1;
}
