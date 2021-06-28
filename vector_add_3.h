#include <stdlib.h>

void vector_add_3(int *var5, int *var4, int *var3, int *var33)
{
    int *var35;
    var35 = malloc(sizeof(int) * 100);
    for (int var26 = 0; var26 < 100; var26++)
    {
        int *var57;
        int var59;
        int var60;
        int var58;
        var57 = &var35[var26];
        var59 = var3[var26];
        var60 = var4[var26];
        var58 = (var59 + var60);
        *(var57) = var58;
    }
    for (int var25 = 0; var25 < 100; var25++)
    {
        int *var49;
        int var51;
        int *var53;
        int var52;
        int var50;
        var49 = &var33[var25];
        var51 = var5[var25];
        var53 = var35;
        var52 = var53[var25];
        var50 = (var51 + var52);
        *(var49) = var50;
    }
}

void vector_add_3_opt(int *var10, int *var9, int *var8, int *var36)
{
    for (int var29 = 0; var29 < 100; var29++)
    {
        int *var30;
        int var54;
        int var55;
        int var53;
        int *var46;
        int var48;
        int var49;
        int var47;
        var30 = malloc(sizeof(int));
        var54 = var8[var29];
        var55 = var9[var29];
        var53 = (var54 + var55);
        *(var30) = var53;
        var46 = &var36[var29];
        var48 = var10[var29];
        var49 = *(var30);
        var47 = (var48 + var49);
        *(var46) = var47;
	free(var30)
    }
}

void cross(int *var1, int *var0, int *var10)
{
    int *var8;
    int var29;
    int var28;
    int var27;
    int *var2;
    int var21;
    int var20;
    int var19;
    int var17;
    int var16;
    int var15;
    int var8;
    int var2;
    var29 = var1[2];
    var28 = var0[1];
    var27 = (var28 * var29);
    *(var8) = var27;
    var21 = var1[1];
    var20 = var0[2];
    var19 = (var20 * var21);
    *(var2) = var19;
    var17 = *(var2);
    var16 = *(var8);
    var15 = (var16 - var17);
    *(var10) = var15;
}