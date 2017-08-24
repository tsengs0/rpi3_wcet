#include <cstdio>
#include <cstdlib>

#include <string>

#define MATSIZE 64 

using namespace std;

int main(void)
{
    FILE *fp = fopen("matdat.h", "w");

    fprintf(fp, "unsigned int g_mat_A[64][64] = {\n");
    for (int row = 0; row < MATSIZE - 1; ++row)
    {
        fprintf(fp, "\t{");
        for (int col = 0; col < MATSIZE - 1; ++col)
        {
            fprintf(fp, "%d,", rand() % 10);
        }
        fprintf(fp, "%d},\n", rand() % 10);
    }
    
    fprintf(fp, "\t{");
    for (int col = 0; col < MATSIZE - 1; ++col)
    {
        fprintf(fp, "%d,", rand() % 10);
    }
    fprintf(fp, "%d}\n};\n", rand() % 10);
    
    fprintf(fp, "unsigned int g_mat_B[64][64] = {\n");
    for (int row = 0; row < MATSIZE - 1; ++row)
    {
        fprintf(fp, "\t{");
        for (int col = 0; col < MATSIZE - 1; ++col)
        {
            fprintf(fp, "%d,", rand() % 10);
        }
        fprintf(fp, "%d},\n", rand() % 10);
    }
    
    fprintf(fp, "\t{");
    for (int col = 0; col < MATSIZE - 1; ++col)
    {
        fprintf(fp, "%d,", rand() % 10);
    }
    fprintf(fp, "%d}\n};\n", rand() % 10);

    fprintf(fp, "unsigned int g_mat_C[64][64] = { 0, };\n");

    fclose(fp);

    return 0;
}
