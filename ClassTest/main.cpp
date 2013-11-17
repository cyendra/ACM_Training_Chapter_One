#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

FILE* f1;
int a[100];
int n;
int q;

int main()
{
    while (true)
    {
        n=0;
        memset(a,0,sizeof(a));
        printf("0.exit 1.data save 2.data load 3.txt save 4.txt load\n");
        scanf("%d",&q);
        switch (q)
        {
            case 0:
                return 0;
            case 1:
                scanf("%d",&n);
                for (int i=0; i<n; i++)
                {
                    scanf("%d",&a[i]);
                }
                f1=fopen("file.data","wb");
                fwrite(&n,sizeof(int),1,f1);
                for (int i=0; i<n; i++)
                {
                    fwrite(&a[i],sizeof(int),1,f1);
                }
                printf("data save\n");
                fclose(f1);
                break;
            case 2:
                f1=fopen("file.data","rb");
                fread(&n,sizeof(int),1,f1);
                for (int i=0;i<n;i++)
                {
                    fread(&a[i],sizeof(int),1,f1);
                }
                for (int i=0;i<n;i++)
                {
                    printf("%4d",a[i]);
                }
                printf("\ndata load\n");
                fclose(f1);
                break;
            case 3:
                f1=fopen("file.txt","w");
                scanf("%d",&n);
                for (int i=0; i<n; i++)
                {
                    scanf("%d",&a[i]);
                }
                fprintf(f1,"%d\n",n);
                for (int i=0;i<n;i++)
                {
                    fprintf(f1,"%d ",a[i]);
                }
                fprintf(f1,"\n");
                printf("txt save\n");
                fclose(f1);
                break;
            case 4:
                f1=fopen("file.txt","r");
                fscanf(f1,"%d",&n);
                for (int i=0;i<n;i++)
                {
                    fscanf(f1,"%d",&a[i]);
                }
                for (int i=0;i<n;i++)
                {
                    printf("%-4d",a[i]);
                }
                printf("\ntxt load\n");
                fclose(f1);
                break;
        }
        printf("\n");
    }
    return 0;
}
