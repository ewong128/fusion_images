/*  char *f1 = argv[argc];
    char *f2 = "result.bmp";
    int f = 0;
    float hold[11] = {0,0.1,0.2,0.3,0.4,0.5,0.6, 0.7,0.8,0.9,1}
    
    if (argc != hold){
        error("invalid input");
        break;
    }
    else{
        blendimages(f1, f2, f, hold);
    }
}
else if(argc>= 3 && argc < 9)
{
    if (s(argv[1], "-t") == 0){
        if(argc == 4 || (argc == 6 &&(strcmp(argv[3], "-o")==0))){
            f = 1;
            char *ptr;
            strtof(argv[2], &ptr);
            if(*argv[2] != *ptr) hold[0] = atof(argv[2]);
            else{
                error("wrong arguments");
            }
            if (argc ==6)f2 == argv[4];
            blendimages(f1,f2,f, hold);
        }
        else{
            error("invalid");
        }
    }
    else if(strcmp(argv[1], "-b")==0){
char *ptr;
strtof(argv[2], *ptr);
if(*argv[2]!= *ptr)
{hold[0] = atpf(argv[2]);}
    }
    f =2;
    f1 = argv[argc -2];
    f2 = argv[argc -1];
    blendimage(f1, f2, f, hold);
}*/


/*blended pizels*/
/*red_result = red_image1 * ratio + red_image2 * (1-ratio);
green_result = green_image1 * ratio + green_image2 *(1-ratio);
blue_result = blue_image1 * ration + blue_image2 *(1-ratio);
/*blend colors precisely*/
/*unsigned char get_red(unsigned char *imagedata, float x, float y, int imagewidth, int imageheight);
unsigned char get_green(unsigned char *imagedata, float x, float y, int imagewidth, int imageheight);
unsigned char get_blue(unsigned char *imagedata, float x, float y, int imagewidth, int imageheight);*/

/*Read file
FILE *f1;
FILE *f2;*/
/*BITMAPFILEHEADER bitmapFileHeader;
unsigned char *bitmapImage;
unsigned char temp;
f1 = fopen("flowers.bmp", "rb");*/

/*if (file1 == NULL){
    return NULL;
}*/
/*fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER),1,file1);*/
/*bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);
fclose(f1);*/