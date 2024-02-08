// autor: Lena Fiedor
// tytul: poker

#include <iostream>
using namespace std;

int main () {
    int ile;
    char g1;
    char g2;
    int w11;
    int w12;
    int w13;
    int w14;
    int w21;
    int w22;
    int w23;
    int w24;
    float lost1 = 0;
    float lost2 = 0;
    float lost3 = 0;
    float lost4 = 0;
    float lost5 = 0;
    float won1 = 0;
    float won2 = 0;
    float won3 = 0;
    float won4 = 0;
    float won5 = 0;
    float rem1 = 0;
    float rem2 = 0;
    float rem3 = 0;
    float rem4 = 0;
    float rem5 = 0;
    int lost_1 = 0;
    int lost_2 = 0;
    int won_1 = 0;
    int won_2 = 0;
    int rem_1 = 0;
    int rem_2 = 0;
    float ilea;
    float ileb;
    float ilec;
    float iled;
    float ilee;
    float sum1;
    float sum2;
    float sum3;
    float sum4;

    cin >> ile;
    int i = ile;
    while ( i > 0 )
    {
        cin >> g1;
        cin >> w11;
        cin >> w12;
        cin >> w13;
        cin >> w14;
        cin >> g2;
        cin >> w21;
        cin >> w22;
        cin >> w23;
        cin >> w24;

        if ( ( w11 > 0 ) && ( w11 <= 4 ) && ( w12 > 0 ) && ( w12 <= 4 ) && ( w13 > 0 ) && ( w13 <= 4 ) && ( w14 > 0 ) && ( w14 <= 4 ) && ( w21 > 0 ) && ( w21 <= 4 ) && ( w22 > 0 ) && ( w22 <= 4 ) && ( w23 > 0 ) && ( w23 <= 4 ) && ( w24 > 0 ) && ( w24 <= 4 ) )
        {
            if ( w11 == w12 && w12 == w13 && w13 == w14 && w21 == w22 && w22 == w23 && w23 == w24 )
            { // cztery identyczne
                if ( w11 > w21 )
                {
                    won_1 += 1;
                    lost_2 += 1;
                }
                else if ( w21 > w11 )
                {
                    won_2 += 1;
                    lost_1 += 1;
                }
                else if ( w11 == w21 )
                {  
                    rem_1 += 1;
                    rem_2 += 1;
                }
            }
            else if ( w11 == w12 && w12 == w13 && w13 == w14 )
            {
                won_1 += 1;
                lost_2 += 1;
            }
            else if ( w21 == w22 && w22 == w23 && w23 == w24 )
            {
                won_2 += 1;
                lost_1 += 1;
            }

            else if ( w11 != w12 && w12 != w13 && w13 != w14 && w11 != w13 && w11 != w14 && w12 != w14 && w21 != w22 && w22 != w23 && w23 != w24 && w21 != w23 && w21 != w24 && w22 != w24 )
            { // cztery rozne
                sum1 = w11 + w12 + w13 + w14;
                sum2 = w21 + w22 + w23 + w24;
                if ( sum1 > sum2 )
                {
                    won_1 += 1;
                    lost_2 += 1;
                }
                else if ( sum1 < sum2 )
                {
                    won_2 += 1;
                    lost_1 += 1;
                }
                else if ( sum1 == sum2 )
                {
                    rem_1 += 1;
                    rem_2 += 1;
                }
            }
            else if ( w11 != w12 && w12 != w13 && w13 != w14 && w11 != w13 && w11 != w14 && w12 != w14 )
            {
                won_1 += 1;
                lost_2 += 1;
            }
            else if ( w21 != w22 && w22 != w23 && w23 != w24 && w21 != w23 && w21 != w24 && w22 != w24 )
            {
                won_2 += 1;
                lost_1 += 1;
            }

            else if ( ( ( w11 == w12 && w13 == w14 ) || ( w11 == w13 && w12 == w14 ) || ( w11 == w14 && w12 == w13 ) ) && ( ( w21 == w22 && w23 == w24 ) || ( w21 == w23 && w22 == w24 ) || ( w21 == w24 && w22 == w23 ) ) )
            { // 2 pary
                if ( ( w11 == w12 ) && ( w13 == w14 ) )
                {
                    sum1 = w11 + w12;
                    sum2 = w13 + w14;
                }
                else if ( ( w11 == w13 ) && ( w12 == w14 ) )
                {
                    sum1 = w11 + w13;
                    sum2 = w12 + w14;
                }
                else if ( ( w11 == w14 ) && ( w12 == w13 ) )
                {
                    sum1 = w11 + w14;
                    sum2 = w12 + w13;
                }
                if ( ( w21 == w22 ) && ( w23 == w24 ) )
                {
                    sum3 = w21 + w22;
                    sum4 = w23 + w24;
                }
                else if ( ( w21 == w23 ) && ( w22 == w24 ) )
                {
                    sum3 = w21 + w23;
                    sum4 = w22 + w24;
                }
                else if ( ( w21 == w24 ) && ( w22 == w23 ) )
                {
                    sum3 = w21 + w24;
                    sum4 = w22 + w23;
                }
                if ( ( sum1 > sum2 ) && ( sum3 > sum4 ) )
                {
                    if ( sum1 > sum3 )
                    {
                        won_1 += 1;
                        lost_2 += 1;  
                    }
                    else if ( sum3 > sum1 )
                    {
                        won_2 += 1;
                        lost_1 += 1;
                    }
                    else if ( sum1 == sum3 )
                    {
                        sum1 = w11 + w12 + w13 + w14;
                        sum2 = w21 + w22 + w23 + w24;
                        if ( sum1 > sum2 )
                        {
                            won_1 += 1;
                            lost_2 += 1; 
                        }
                        else if ( sum1 < sum2 )
                        {
                            won_2 += 1;
                            lost_1 += 1; 
                        }
                        else if ( sum1 == sum2 )
                        {
                            rem_1 += 1;
                            rem_2 +=1;
                        }
                    }
                }
                else if ( ( sum1 > sum2 ) && ( sum3 < sum4 ) )
                {
                    if ( sum1 > sum4 )
                    {
                        won_1 += 1;
                        lost_2 += 1;  
                    }
                    else if ( sum4 > sum1 )
                    {
                        won_2 += 1;
                        lost_1 += 1;
                    }
                    else if ( sum1 == sum4 )
                    {
                        sum1 = w11 + w12 + w13 + w14;
                        sum2 = w21 + w22 + w23 + w24;
                        if ( sum1 > sum2 )
                        {
                            won_1 += 1;
                            lost_2 += 1; 
                        }
                        else if ( sum1 < sum2 )
                        {
                            won_2 += 1;
                            lost_1 += 1; 
                        }
                        else if ( sum1 == sum2 )
                        {
                            rem_1 += 1;
                            rem_2 +=1;
                        }
                    }
                }
                else if ( ( sum1 < sum2 ) && ( sum3 < sum4 ) )
                {
                    if ( sum2 > sum4 )
                    {
                        won_1 += 1;
                        lost_2 += 1;  
                    }
                    else if ( sum2 < sum4 )
                    {
                        won_2 += 1;
                        lost_1 += 1;
                    }
                    else if ( sum2 == sum4 )
                    {
                        sum1 = w11 + w12 + w13 + w14;
                        sum2 = w21 + w22 + w23 + w24;
                        if ( sum1 > sum2 )
                        {
                            won_1 += 1;
                            lost_2 += 1; 
                        }
                        else if ( sum1 < sum2 )
                        {
                            won_2 += 1;
                            lost_1 += 1; 
                        }
                        else if ( sum1 == sum2 )
                        {
                            rem_1 += 1;
                            rem_2 +=1;
                        }
                    }
                }
                else if ( ( sum1 < sum2 ) && ( sum3 > sum4 ) )
                {
                    if ( sum2 > sum3 )
                    {
                        won_1 += 1;
                        lost_2 += 1;  
                    }
                    else if ( sum2 < sum3 )
                    {
                        won_2 += 1;
                        lost_1 += 1;
                    }
                    else if ( sum2 == sum3 )
                    {
                        sum1 = w11 + w12 + w13 + w14;
                        sum2 = w21 + w22 + w23 + w24;
                        if ( sum1 > sum2 )
                        {
                            won_1 += 1;
                            lost_2 += 1; 
                        }
                        else if ( sum1 < sum2 )
                        {
                            won_2 += 1;
                            lost_1 += 1; 
                        }
                        else if ( sum1 == sum2 )
                        {
                            rem_1 += 1;
                            rem_2 +=1;
                        }
                    }
                }
            }
            else if ( ( w11 == w12 && w13 == w14 ) || ( w11 == w13 && w12 == w14 ) || ( w11 == w14 && w12 == w13 ) )
            {
                won_1 += 1;
                lost_2 += 1;
            }
            else if ( ( w21 == w22 && w23 == w24 ) || ( w21 == w23 && w22 == w24 ) || ( w21 == w24 && w22 == w23 ) )
            {
                won_2 += 1;
                lost_1 += 1;
            }

            else if ( ( ( w11 == w12 && w12 == w13 ) || ( w11 == w12 && w12 == w14 ) || ( w11 == w13 && w13 == w14 ) || ( w12 == w13 && w13 == w14 ) ) && ( ( w21 == w22 && w22 == w23 ) || ( w21 == w22 && w22 == w24 ) || ( w21 == w23 && w23 == w24 ) || ( w22 == w23 && w23 == w24 ) ) )
            { // trojka identyczna
                if ( w11 == w12 && w12 == w13 )
                {
                    sum1 = w11 + w12 + w13;
                }
                else if ( w11 == w12 && w12 == w14 )
                {
                    sum1 = w11 + w12 + w14;
                }
                else if ( w11 == w13 && w13 == w14 )
                {
                    sum1 = w11 + w13 + w14;
                }
                else if ( w12 == w13 && w13 == w14 )
                {
                    sum1 = w12 + w13 + w14;
                }

                if ( w21 == w22 && w22 == w23 )
                {
                    sum2 = w21 + w22 + w23;
                }
                else if ( w21 == w22 && w22 == w24 )
                {
                    sum2 = w21 + w22 + w24;
                }
                else if ( w21 == w23 && w23 == w24 )
                {
                    sum2 = w21 + w23 + w24;
                }
                else if ( w22 == w23 && w23 == w24 )
                {
                    sum2 = w22 + w23 + w24;
                }

                if ( sum1 > sum2 )
                {
                    won_1 += 1;
                    lost_2 += 1;
                }
                else if ( sum1 < sum2 )
                {
                    won_2 += 1;
                    lost_1 += 1;
                }
                else if ( sum1 == sum2 )
                {
                    sum1 = w11 + w12 + w13 + w14;
                    sum2 = w21 + w22 + w23 + w24;
                    if ( sum1 > sum2 )
                    {
                        won_1 += 1;
                        lost_2 += 1;
                    }
                    else if ( sum1 < sum2 )
                    {
                        won_2 += 1;
                        lost_1 += 1;
                    }
                    else if ( sum1 == sum2 )
                    {
                        rem_1 += 1;
                        rem_2 += 1;
                    }
                }
            }
            else if ( ( w11 == w12 && w12 == w13 ) || ( w11 == w12 && w12 == w14 ) || ( w11 == w13 && w13 == w14 ) || ( w12 == w13 && w13 == w14 ) )
            {
                won_1 += 1;
                lost_2 += 1;
            }
            else if ( ( w21 == w22 && w22 == w23 ) || ( w21 == w22 && w22 == w24 ) || ( w21 == w23 && w23 == w24 ) || ( w22 == w23 && w23 == w24 ) )
            {
                won_2 += 1;
                lost_1 += 1;
            }

            else if ( ( ( w11 == w12 ) || ( w11 == w13 ) || ( w11 == w14 ) || ( w12 == w13 ) || ( w12 == w14 ) || ( w13 == w14 ) ) && ( ( w21 == w22 ) || ( w21 == w23 ) || ( w21 == w24 ) || ( w22 == w23 ) || ( w22 == w24 ) || ( w23 == w24 ) ) )
            { // jedna para
                if ( w11 == w12 )
                {
                    sum1 = w11 + w12;
                }
                else if ( w11 == w13 )
                {
                    sum1 = w11 + w13;
                }
                else if ( w11 == w14 )
                {
                    sum1 = w11 + w14;
                }
                else if ( w12 == w13 )
                {
                    sum1 = w12 + w13;
                }
                else if ( w12 == w14 )
                {
                    sum1 = w12 + w14;
                }
                else if ( w13 == w14 )
                {
                    sum1 = w13 + w14;
                }
            
                if ( w21 == w22 )
                {
                    sum2 = w21 + w22;
                }
                else if ( w21 == w23 )
                {
                    sum2 = w21 + w23;
                }
                else if ( w21 == w24 )
                {
                    sum2 = w21 + w24;
                }
                else if ( w22 == w23 )
                {
                    sum2 = w22 + w23;
                }
                else if ( w22 == w24 )
                {
                    sum2 = w22 + w24;
                }
                else if ( w23 == w24 )
                {
                    sum2 = w23 + w24;
                }

                if ( sum1 > sum2 )
                {
                    won_1 += 1;
                    lost_2 += 1;
                }
                else if ( sum1 < sum2 )
                {
                    won_2 += 1;
                    lost_1 += 1;
                }
                else if ( sum1 == sum2 )
                {
                    sum1 = w11 + w12 + w13 + w14;
                    sum2 = w21 + w22 + w23 + w24;
                    if ( sum1 > sum2 )
                    {
                        won_1 += 1;
                        lost_2 += 1;
                    }
                    else if ( sum1 < sum2 )
                    {
                        won_2 += 1;
                        lost_1 += 1;
                    }
                    else if ( sum1 == sum2 )
                    {
                        rem_1 += 1;
                        rem_2 += 1;
                    }  
                }
            }
            else if ( ( w11 == w12 ) || ( w11 == w13 ) || ( w11 == w14 ) || ( w12 == w13 ) || ( w12 == w14 ) || ( w13 == w14 ) )
            {
                won_1 += 1;
                lost_2 += 1;
            }
            else if ( ( w21 == w22 ) || ( w21 == w23 ) || ( w21 == w24 ) || ( w22 == w23 ) || ( w22 == w24 ) || ( w23 == w24 ) )
            {
                won_2 += 1;
                lost_1 += 1;
            }

            if ( g1 == 'a' )
            {
                won1 += won_1;
                lost1 += lost_1;
                rem1 += rem_1;
                ilea += 1;
            }
            else if ( g1 == 'b' )
            {
                won2 += won_1;
                lost2 += lost_1;
                rem2 += rem_1;
                ileb += 1;
            }
            else if ( g1 == 'c' )
            {
                won3 += won_1;
                lost3 += lost_1;
                rem3 += rem_1;
                ilec += 1;
            }
            else if ( g1 == 'd' )
            {
                won4 += won_1;
                lost4 += lost_1;
                rem4 += rem_1;
                iled += 1;
            }
            else if ( g1 == 'e' )
            {
                won5 += won_1;
                lost5 += lost_1;
                rem5 += rem_1;
                ilee += 1;
            }
            if ( g2 == 'a' )
            {
                won1 += won_2;
                lost1 += lost_2;
                rem1 += rem_2;
                ilea += 1;
            }
            else if ( g2 == 'b' )
            {
                won2 += won_2;
                lost2 += lost_2;
                rem2 += rem_2;
                ileb += 1;
            }
            else if ( g2 == 'c' )
            {
                won3 += won_2;
                lost3 += lost_2;
                rem3 += rem_2;
                ilec += 1;
            }
            else if ( g2 == 'd' )
            {
                won4 += won_2;
                lost4 += lost_2;
                rem4 += rem_2;
                iled += 1;
            }
            else if ( g2 == 'e' )
            {
                won5 += won_2;
                lost5 += lost_2;
                rem5 += rem_2;
                ilee += 1;
            }
            won_1 = 0;
            won_2 = 0;
            lost_1 = 0;
            lost_2 = 0;
            rem_1 = 0;
            rem_2 = 0;
            i--;
        }
    }

    if ( won1 !=0 || lost1 != 0 || rem1 != 0 )
    {
        cout << "gracz a" << endl;
        if ( won1 !=0 )
        cout << "    wygrane: " << ( won1 / ilea ) * 100 << "%" << endl;
        if ( rem1 != 0 )
        cout << "    remisy: " << ( rem1 / ilea ) * 100 << "%" << endl;
        if ( lost1 != 0 )
        cout << "    przegrane: " << ( lost1 / ilea ) * 100 << "%" << endl;
        cout << "" << endl;
    }
    if ( won2 !=0 || lost2 != 0 || rem2 != 0 )
    {
        cout << "gracz b" << endl;
        if ( won2 !=0 )
        cout << "    wygrane: " << ( won2 / ileb ) * 100 << "%" << endl;
        if ( rem2 != 0 )
        cout << "    remisy: " << ( rem2 / ileb ) * 100 << "%" << endl;
        if ( lost2 != 0 )
        cout << "    przegrane: " << ( lost2 / ileb ) * 100 << "%" << endl;
        cout << "" << endl;
    }
    if ( won3 !=0 || lost3 != 0 || rem3 != 0 )
    {
        cout << "gracz c" << endl;
        if ( won3 !=0 )
        cout << "    wygrane: " << ( won3 / ilec ) * 100 << "%" << endl;
        if ( rem3 != 0 )
        cout << "    remisy: " << ( rem3 / ilec ) * 100 << "%" << endl;
        if ( lost3 != 0 )
        cout << "    przegrane: " << ( lost3 / ilec ) * 100 << "%" << endl;
        cout << "" << endl;
    }
    if ( won4 !=0 || lost4 != 0 || rem4 != 0 )
    {
        cout << "gracz d" << endl;
        if ( won4 !=0 )
        cout << "    wygrane: " << ( won4 / iled ) * 100 << "%" << endl;
        if ( rem4 != 0 )
        cout << "    remisy: " << ( rem4 / iled ) * 100 << "%" << endl;
        if ( lost4 != 0 )
        cout << "    przegrane: " << ( lost4 / iled ) * 100 << "%" << endl;
        cout << "" << endl;
    }
    if ( won5 !=0 || lost5 != 0 || rem5 != 0 )
    {
        cout << "gracz e" << endl;
        if ( won5 !=0 )
        cout << "    wygrane: " << ( won5 / ilee ) * 100 << "%" << endl;
        if ( rem5 != 0 )
        cout << "    remisy: " << ( rem5 / ilee ) * 100 << "%" << endl;
        if ( lost5 != 0 )
        cout << "    przegrane: " << ( lost5 / ilee ) * 100 << "%" << endl;
        cout << "" << endl;
    }

    return 0;
}