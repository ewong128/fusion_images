#include<stdio.h>
#include<stdlib.h>

/*Allocate result image memory*/

typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned int LONG;
struct tagBITMAPFILEHEADER
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
};

struct tagBITMAPINFOHEADER{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};

int main(int argc, char *argv[]){
    struct tagBITMAPFILEHEADER fileh1;
    struct tagBITMAPINFOHEADER filehinfo1;
    struct tagBITMAPFILEHEADER fileh2;
    struct tagBITMAPINFOHEADER filehinfo2;
   
    FILE *f;
    float ratio;
    int s,z,i,j,row1,row2,r;
    unsigned char *blended;
    unsigned char *pixel1;
    unsigned char *pixel2;
    unsigned char amtpad = '\0';

    if (argv[1] == NULL){
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    if (argv[2] == NULL){
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    if (argv[3] == NULL){
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    if (argv[4] == NULL){
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    

/*   if (ratio == strtod(r,NULL)){
        printf("Invalid\n");
        exit(EXIT_FAILURE);
        }
} */

    /*Image 1*/
    f= fopen(argv[1],"rb");
    fread(&(fileh1.bfType), sizeof(WORD),1,f);
    /*change the asci value*/
    if(fileh1.bfType!= 0x4D42){
        printf("Invalid file");
        fclose(f);
        exit(EXIT_FAILURE);
    }
    fread(&(fileh1.bfSize), sizeof(DWORD),1,f);
    fread(&(fileh1.bfReserved1), sizeof(WORD),1,f);
    fread(&(fileh1.bfReserved2), sizeof(WORD),1,f);
    fread(&(fileh1.bfOffBits), sizeof(DWORD),1,f);

    fread(&(filehinfo1.biSize), sizeof(DWORD),1,f);
    fread(&(filehinfo1.biWidth), sizeof(LONG),1,f);
    fread(&(filehinfo1.biHeight), sizeof(LONG),1,f);
    fread(&(filehinfo1.biPlanes), sizeof(WORD),1,f);
    fread(&(filehinfo1.biBitCount), sizeof(WORD),1,f);
    fread(&(filehinfo1.biCompression), sizeof(DWORD),1,f); 
    fread(&(filehinfo1.biSizeImage), sizeof(DWORD),1,f);
    fread(&(filehinfo1.biXPelsPerMeter), sizeof(LONG),1,f);
    fread(&(filehinfo1.biYPelsPerMeter), sizeof(LONG),1,f);
    fread(&(filehinfo1.biClrUsed), sizeof(DWORD),1,f);
    fread(&(filehinfo1.biClrImportant), sizeof(DWORD),1,f);

    pixel1 = malloc(filehinfo1.biWidth * filehinfo1.biHeight *3);
    row1 = filehinfo1.biWidth * 3;
    if (pixel1 == NULL){
        printf("Invalid");
        fclose(f);
        exit(EXIT_FAILURE);
    }
    if (row1 % 4 != 0){
        row1 = 4 - (row1%4);}
    else{
        row1 = 0;
    }
    for(i=0; i< filehinfo1.biHeight; i++){
        for(j=0; j<filehinfo1.biWidth; j++){
            /*Changed what multiplies*/
            fread(pixel1+(i*filehinfo1.biWidth+j)*3,3,1,f);
        }
        /*fileinfo1*/
        fseek(f,row1,SEEK_CUR);
    }
    fclose(f);
   
 /*Image 2*/
    f = fopen(argv[2],"rb");
    fread(&(fileh2.bfType), sizeof(WORD),1,f);
    /*change the asci value*/
    if(fileh2.bfType!= 0x4D42){
        printf("Invalid file");
        fclose(f);
        free(pixel1);
        exit(EXIT_FAILURE);
    }
    fread(&(fileh2.bfSize), sizeof(DWORD),1,f);
    fread(&(fileh2.bfReserved1), sizeof(WORD),1,f);
    fread(&(fileh2.bfReserved2), sizeof(WORD),1,f);
    fread(&(fileh2.bfOffBits), sizeof(DWORD),1,f);

    fread(&(filehinfo2.biSize), sizeof(DWORD),1,f);
    fread(&(filehinfo2.biWidth), sizeof(LONG),1,f);
    fread(&(filehinfo2.biHeight), sizeof(LONG),1,f);
    fread(&(filehinfo2.biPlanes), sizeof(WORD),1,f);
    fread(&(filehinfo2.biBitCount), sizeof(WORD),1,f);
    fread(&(filehinfo2.biCompression), sizeof(DWORD),1,f); 
    fread(&(filehinfo2.biSizeImage), sizeof(DWORD),1,f);
    fread(&(filehinfo2.biXPelsPerMeter), sizeof(LONG),1,f);
    fread(&(filehinfo2.biYPelsPerMeter), sizeof(LONG),1,f);
    fread(&(filehinfo2.biClrUsed), sizeof(DWORD),1,f);
    fread(&(filehinfo2.biClrImportant), sizeof(DWORD),1,f);
    
    pixel2 = malloc(filehinfo2.biWidth * filehinfo2.biHeight *3);
    if (pixel2 == NULL){
        printf("Invalid");
        fclose(f);
        free(pixel1);
        exit(EXIT_FAILURE);
    }
    row2 = filehinfo2.biWidth * 3;
    if (row2 % 4 != 0){
        row2 = 4 - (row2%4);}
    else{
        row2 = 0;
    }

    for(i=0; i< filehinfo2.biHeight; i++){
        for(j=0; j<filehinfo2.biWidth; j++){
            fread(pixel2+(i * filehinfo2.biWidth+j)*3,3,1,f);
        }
        fseek(f,row2,SEEK_CUR);
    }
    fclose(f);

    /*Result output*/
    f = fopen(argv[4], "wb");
    ratio = atof(argv[3]);
    /*printf("%f",ratio);*/
    s = filehinfo2.biWidth * filehinfo2.biHeight *3;
    blended = malloc(s);
    if (blended == NULL){
        printf("Invalid");
        fclose(f);
        free(pixel1);
        free(pixel2);
        exit(EXIT_FAILURE);
    }
    z=0;
   while(z<s){
        blended[z] = pixel1[z] * ratio + pixel2[z] * (1-ratio);
      z++;
    }

    fwrite(&(fileh2.bfType), sizeof(WORD),1,f);
    fwrite(&(fileh2.bfSize), sizeof(DWORD),1,f);
    fwrite(&(fileh2.bfReserved1), sizeof(WORD),1,f);
    fwrite(&(fileh2.bfReserved2), sizeof(WORD),1,f);
    fwrite(&(fileh2.bfOffBits), sizeof(DWORD),1,f);

    fwrite(&(filehinfo2.biSize), sizeof(DWORD),1,f);
    fwrite(&(filehinfo2.biWidth), sizeof(LONG),1,f);
    fwrite(&(filehinfo2.biHeight), sizeof(LONG),1,f);
    fwrite(&(filehinfo2.biPlanes), sizeof(WORD),1,f);
    fwrite(&(filehinfo2.biBitCount), sizeof(WORD),1,f);
    fwrite(&(filehinfo2.biCompression), sizeof(DWORD),1,f); 
    fwrite(&(filehinfo2.biSizeImage), sizeof(DWORD),1,f);
    fwrite(&(filehinfo2.biXPelsPerMeter), sizeof(LONG),1,f);
    fwrite(&(filehinfo2.biYPelsPerMeter), sizeof(LONG),1,f);
    fwrite(&(filehinfo2.biClrUsed), sizeof(DWORD),1,f);
    fwrite(&(filehinfo2.biClrImportant), sizeof(DWORD),1,f);


     for(i=0; i< filehinfo2.biHeight; i++){
        for(j=0; j<filehinfo2.biWidth; j++){
            fwrite(blended+(i * filehinfo2.biWidth+j)*3,3,1,f);
        }
        fwrite(&amtpad,sizeof(char),row2,f);
    }

    fclose(f);
    free(pixel1);
    free(pixel2);
    free(blended);
    return 0;
}

    /*exit(EXIT_SUCCESS);*/

/*Bilinear Interpolation*/
/*red_left_upper = get_color(x1,y2);
red_right_upper = get_color(x2,y2);
red_left_lower = get_color(x1,y1);
red_right_lower = get_color(x2,y1);

red_left = red_left_upper *(1-dy)+red_left_lower *dy;
red_right = red_right_upper * (1-dy) +red_right_lower *dy;
red_result = red_left *(1-dx)+red_right*dx;
*/
    
 