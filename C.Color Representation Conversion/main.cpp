
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define min3v(v1, v2, v3) ((v1)>(v2)? ((v2)>(v3)?(v3):(v2)):((v1)>(v3)?(v3):(v2)))
#define max3v(v1, v2, v3) ((v1)<(v2)? ((v2)<(v3)?(v3):(v2)):((v1)<(v3)?(v3):(v1)))
struct COLOR_RGB{
    int red;//[0,255]
    int green;//[0,255]
    int blue;//[0,255]
    COLOR_RGB(){}
    void make(int a,int b,int c){
        red=a;
        green=b;
        blue=c;
    }
};
struct COLOR_HSL{
    double hue;//[0,360]
    double saturation;//[0,100]
    double luminance;//[0,100]
    COLOR_HSL(){}
    void make(double a,double b,double c){
        hue=a;
        saturation=b;
        luminance=c;
    }
};
struct COLOR_HSV{
    double h;//[0,360]
    double s;//[0,100]
    double v;//[0,100]
    COLOR_HSV(){}
    void make(double a,double b,double c){
        h=a;
        s=b;
        v=c;
    }
};

//void RGBtoHSV(const COLOR_RGB *rgb, COLOR_HSV *hsv){
//    double var_R=(rgb->red)/255.0;
//    double var_G
//
//}

// Converts RGB to HSL
void RGBtoHSL(/*[in]*/const COLOR_RGB *rgb, /*[out]*/COLOR_HSL *hsl)
{
    double h=0, s=0, l=0;
    // normalizes red-green-blue values
    double r = rgb->red/255.f;
    double g = rgb->green/255.f;
    double b = rgb->blue/255.f;
    double maxVal = max3v(r, g, b);
    double minVal = min3v(r, g, b);
    // hue
    if(maxVal == minVal)
    {
        h = 0; // undefined
    }
    else if(maxVal==r && g>=b)
    {
        h = 60.0f*(g-b)/(maxVal-minVal);
    }
    else if(maxVal==r && g<b)
    {
        h = 60.0f*(g-b)/(maxVal-minVal) + 360.0f;
    }
    else if(maxVal==g)
    {
        h = 60.0f*(b-r)/(maxVal-minVal) + 120.0f;
    }
    else if(maxVal==b)
    {
        h = 60.0f*(r-g)/(maxVal-minVal) + 240.0f;
    }
    // luminance
    l = (maxVal+minVal)/2.0f;
    // saturation
    if(l == 0 && maxVal == minVal)
    {
        s = 0;
    }
    else if(0<l && l<=0.5f){
        s = (maxVal-minVal)/(maxVal+minVal);
    }
    else if(l>0.5f){
        s = (maxVal-minVal)/(2 - (maxVal+minVal)); //(maxVal-minVal > 0)?
    }
    hsl->hue = (h>360)? 360 : ((h<0)?0:h);
    hsl->saturation = ((s>1)? 1 : ((s<0)?0:s))*100;
    hsl->luminance = ((l>1)? 1 : ((l<0)?0:l))*100;
}
// Converts HSL to RGB
void HSLtoRGB(const COLOR_HSL *hsl, COLOR_RGB *rgb)
{
    double h = hsl->hue;
    // h must be [0, 360]
    double s = hsl->saturation/100.f;
    // s must be [0, 1]
    double l = hsl->luminance/100.f;
    // l must be [0, 1]
    double R, G, B;
    if(hsl->saturation == 0){
        // achromatic color (gray scale)
        R = G = B = l*255.f;
    }
    else{
        double q = (l<0.5f)?(l * (1.0f+s)):(l+s - (l*s));
        double p = (2.0f * l) - q;
        double Hk = h/360.0f;
        double T[3];
        T[0] = Hk + 0.3333333f;
        // Tr 0.3333333f=1.0/3.0
        T[1] = Hk;
        // Tb
        T[2] = Hk - 0.3333333f;
        // Tg
        for(int i=0; i<3; i++){
            if(T[i] < 0) T[i] += 1.0f;
            if(T[i] > 1) T[i] -= 1.0f;
            if((T[i]*6) < 1){
                T[i] = p + ((q-p)*6.0f*T[i]);
            }
            else if((T[i]*2.0f) < 1){ //(1.0/6.0)<=T[i] && T[i]<0.5
                T[i] = q;
            }
            else if((T[i]*3.0f) < 2){ // 0.5<=T[i] && T[i]<(2.0/3.0)
                T[i] = p + (q-p) * ((2.0f/3.0f) - T[i]) * 6.0f;
            }
            else T[i] = p;
        }
        R = T[0]*255.0f;
        G = T[1]*255.0f;
        B = T[2]*255.0f;
    }
    rgb->red = (int)((R>255)? 255 : ((R<0)?0 : R));
    rgb->green = (int)((G>255)? 255 : ((G<0)?0 : G));
    rgb->blue = (int)((B>255)? 255 : ((B<0)?0 : B));
}
char nam[3][4]= {"RGB","HSL","HSV"};

COLOR_RGB rgb;
COLOR_HSL hsl;

int main()
{
    char ss[11];
    char tt[11];
    int R,G,B;
    double a,b,c;

    while (~scanf("%s",ss))
    {
        int s=0;
        int t=0;
        scanf("%s",tt);
        //È¡µÃs t
        for (int i=0; i<3; i++){
            if (strcmp(nam[i],ss)==0){
                s=i;
                break;
            }
        }
        for (int i=0; i<3; i++){
            if (strcmp(nam[i],tt)==0){
                t=i;
                break;
            }
        }
        if (t==0){
            scanf("%d%d%d",&R,&G,&B);
            rgb.make(R,G,B);
        }
        else if (t==1){
            char c1,c2;
            scanf("%lf %lf%c %lf%c",&a,&b,&c1,&c,&c2);
            hsl.make(a,b,c);
            HSLtoRGB(&hsl,&rgb);
        }
        else if (t==2){

        }
        //Êä³ö
        if (s==0){
            printf("RGB %d %d %d\n",rgb.red,rgb.green,rgb.blue);
        }
        else if (s==1){
            RGBtoHSL(&rgb,&hsl);
            printf("HSL %0.0f %0.0f%% %0.0f%%\n",hsl.hue,hsl.saturation,hsl.luminance);
        }
        else if (s==2){

        }
    }
    return 0;
}

