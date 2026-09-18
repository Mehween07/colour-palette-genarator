#include<bits/stdc++.h>
#include <cmath>
using namespace std;
int main() { 
    char again = 'y';
    do {
    int r , g , b ;
    cout<<"enter red (0-255): ";
    cin>> r ;
    cout<<"enter green (0-255): ";
    cin>> g ;
    cout<<"enter blue (0-255): ";
    cin>> b ;

    cout<< "you entered RGB(" << r << " , " << g << " , " << b << ")" << endl;

   float rf = r / 255.0 ;
   float gf = g / 255.0 ;
   float bf = b / 255.0 ;

   float cmax = max(rf, max(gf, bf));
   float cmin = min(rf, min(gf, bf));
   float delta = cmax - cmin;
   float L = (cmax + cmin) / 2.0;
   cout<< "Lightness: " << L << endl;

   float s;
       if (delta == 0) {
          s = 0 ;
       } else if ( L < 0.5){
          s = delta / (cmax + cmin) ;
       } else {
          s = delta / (2.0 - cmax - cmin) ;
       }
       float h;
       if (delta == 0) {
        h = 0 ;
       } else if (cmax == rf) {
        h = 60 * (((gf - bf) / delta)) ;
       } else if (cmax == gf) {
        h = 60 * (((bf - rf) / delta) + 2) ;
       } else {
        h = 60 * (((rf - gf) / delta) + 4) ;
       }
       if (h < 0) {
        h += 360 ;
       }
       cout << "hue: " << h << ", saturation: " << s << ", Lightness:" << L << endl;

     int choice;
        cout << "\nChoose an option:\n";
        cout << "1. Complementary colour\n";
        cout << "2. Analogous colours\n";
        cout << "3. Triadic colous\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;

       if (choice == 1){ 
       float h2 = h + 180;
         if (h2 >= 360) {
             h2 -= 360;
         }

        float c = (1 - fabs(2 * L - 1)) * s;
        float x = c * (1 - fabs(fmod(h2 / 60.0, 2) - 1));
        float m = L - c / 2.0;

        float r2, g2, b2;
        if (h2 < 60) {
            r2 = c; g2 = x; b2 = 0;
        } else if (h2 < 120) {
            r2 = x; g2 = c; b2 = 0;
        }else if (h2 < 180) {
            r2 = 0; g2 = c; b2 = x;
        }else if (h2 < 240) {
            r2 = 0; g2 = x; b2 = c;
        }else if (h2 < 300) {
            r2 = x; g2 = 0; b2 = c;
        }else {
            r2 = c; g2 = 0; b2 = x;
        }

        int R2 = (r2 + m) * 255;
        int G2 = (g2 + m) * 255;
        int B2 = (b2 + m) * 255;

        cout << "new hue: " << h2 << endl;
        cout << "c: " << c << ", x: " << x << ", m : " << endl;
        cout << " complementary colour RGB: (" << R2 << ", " << G2 << ", " << B2 << ")" << endl;
    }
    else if (choice == 2) {
        float h_left = h - 30;
        if (h_left < 0) { h_left += 360; }
        float h_right = h + 30;
        if (h_right >= 360) { h_right -= 360; }
        cout <<"left analogous hue: "<< h_left << endl;
        cout <<"right analogous hue: "<< h_right << endl; 

        // left analogous colour
        float c_1 = (1 - fabs(2 * L - 1)) * s;
        float x_1 = c_1 * (1 - fabs(fmod(h_left / 60.0, 2) - 1));
        float m_1 = L - c_1 / 2.0;
        float r_1, g_1, b_1;
        if (h_left < 60) {r_1 = c_1, g_1 = x_1, b_1 = 0; }
        else if (h_left < 120) { r_1 = x_1, g_1 = c_1, b_1 = 0; }
        else if (h_left < 180) { r_1 = 0, g_1 = c_1, b_1 = x_1; }
        else if (h_left < 240) { r_1 = 0, g_1 = x_1, b_1 = c_1; }
        else if (h_left < 300) { r_1 = x_1, g_1 = 0, b_1 = c_1; }
        else { r_1 = c_1; g_1 = 0; b_1 = x_1; }
        int R_l = (r_1 + m_1) * 255;
        int G_l = (g_1 + m_1) * 255;
        int B_l = (b_1 + m_1) * 255;
        cout <<" left analogous RGB: (" << R_l << ", " << G_l << ", " << B_l <<") " <<endl;  
        
        //Right analouges colour
         float c_r= (1 - fabs(2 * L - 1)) * s;
        float x_r = c_r * (1 - fabs(fmod(h_right / 60.0, 2) - 1));
        float m_r = L - c_r / 2.0;
        float r_r, g_r, b_r;
        if (h_right < 60) {r_r = c_r, g_r = x_r, b_r = 0; }
        else if (h_right < 120) { r_r = x_r, g_r = c_r, b_r = 0; }
        else if (h_right < 180) { r_r = 0, g_r = c_r, b_r = x_r; }
        else if (h_right < 240) { r_r = 0, g_r = x_r, b_r = c_r; }
        else if (h_right < 300) { r_r = x_r, g_r = 0, b_r = c_r; }
        else { r_r = c_r; g_r = 0; b_r = x_r; }
        int R_r = (r_r + m_r) * 255;
        int G_r = (g_r + m_r) * 255;
        int B_r = (b_r + m_r) * 255;
        cout <<"right analogous RGB: (" << R_r << ", " << G_r << ", " << B_r <<") " <<endl;
        }
        else if (choice == 3) {
            float h_t1 = h + 120;
            if (h_t1 > 360) { h_t1 -=360 ;}
            
            float h_t2 = h + 240;
            if (h_t1 >=360) { h_t2 -=360 ;}
            
            cout <<"Triadic hue 1: " << h_t1 <<endl;
            cout <<"Triadic hue 2: " << h_t2 <<endl;

            //Triadic colour 1
            float c_t1 = (1 - fabs(2 * L -  1)) * s;
            float x_t1 = c_t1 * (1 - fabs(fmod(h_t1 / 60.0, 2) - 1));
            float m_t1 = L - c_t1 / 2.0;
            float r_t1, g_t1, b_t1;
            if (h_t1 < 60) { r_t1 = c_t1; g_t1 = x_t1; b_t1 = 0; }
            else if (h_t1 < 120) { r_t1 = x_t1; g_t1 = c_t1; b_t1 = 0; }
            else if (h_t1 < 180) { r_t1 = 0; g_t1 = c_t1; b_t1 = x_t1; }
            else if (h_t1 < 240) { r_t1 = 0; g_t1 = x_t1; b_t1 = c_t1; }
            else if (h_t1 < 300) { r_t1 = x_t1; g_t1 = 0; b_t1 = c_t1; }
            else { r_t1 = c_t1; g_t1 = 0; b_t1 = x_t1; }
            int R_t1 = (r_t1 + m_t1) * 255;
            int G_t1 = (g_t1 + m_t1) * 255;
            int B_t1 = (b_t1 + m_t1) * 255;
            cout << "Triadic colour 1 RGB: (" <<R_t1 << ", "<< G_t1 << ", " << B_t1 << ")" <<endl;

            //Triadic colour 2
            float c_t2= (1 - fabs(2 * L -  1)) * s;
            float x_t2 = c_t2 * (1 - fabs(fmod(h_t2 / 60.0, 2) - 1));
            float m_t2 = L - c_t2 / 2.0;
            float r_t2, g_t2, b_t2;
            if (h_t2 < 60) { r_t2 = c_t2; g_t2 = x_t2; b_t2 = 0; }
            else if (h_t2 < 120) { r_t2 = x_t2; g_t2 = c_t2; b_t2 = 0; }
            else if (h_t2 < 180) { r_t2 = 0; g_t2 = c_t2; b_t2 = x_t2; }
            else if (h_t2 < 240) { r_t2 = 0; g_t2 = x_t2; b_t2 = c_t2; }
            else if (h_t2 < 300) { r_t2 = x_t2; g_t2 = 0; b_t2 = c_t2; }
            else { r_t2 = c_t2; g_t2 = 0; b_t2 = x_t2; }
            int R_t2 = (r_t2 + m_t2) * 255;
            int G_t2 = (g_t2 + m_t2) * 255;
            int B_t2 = (b_t2 + m_t2) * 255;
            cout << "Triadic colour 2 RGB: (" <<R_t2 << ", "<< G_t2 << ", " << B_t2 << ")" <<endl;
        }
        cout << "\nTry another colour? (y/n): ";
        cin >> again;

        } while (again == 'y' || again == 'Y') ;
        
    return 0;
    }