
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"
#include "data.h"

int main(void)
{
    int volba = 2;
    scanf ("%d",&volba);

    switch (volba){
            case 1: {
                double image[IMAGE_SIZE];  // pole na uloženie pixelov

                load_image(image,IMAGE_SIZE);     // načítanie pixelov zo stdin
                print_image(image,IMAGE_WIDTH,IMAGE_HEIGHT);  // výpis obrázk
                break;
            }
            case 2: {
                int index = 0;
                int riadok = 0;
                int stlpec = 0;

                scanf("%d %d %d",&index,&riadok,&stlpec);

                int pixel_index = riadok * IMAGE_WIDTH + stlpec;
                int pozicia = index * 784 + pixel_index;
                printf("%.2lf", weights[pozicia]);
                break;
            }
            case 3: {
                double image[IMAGE_SIZE];
                load_image(image, IMAGE_SIZE);

                for(int i = 0; i < 10; i++) {
                    double vysledok = 0;
                    for (int j = 0; j < IMAGE_SIZE; j++) {
                        int w_index = (i * IMAGE_SIZE) + j;
                        vysledok += (image[j] * weights[w_index]);
                    }
                    vysledok += bias[i];
                    printf("%8d %7.2lf\n", i,vysledok);
                }
                break;
            }
            case 4: {
                double z[10];
                for(int i = 0; i < 10; i++) {
                    scanf("%lf",&z[i]);
                }
                double max = z[0];
                for(int i = 1; i < 10; i++) {
                    if(z[i] > max) {
                        max = z[i];
                    }
                }
                double sucet = 0;
                for(int i = 0; i < 10; i++) {
                    sucet += exp(z[i] - max);
                }
                for(int i = 0; i < 10; i++) {
                    z[i] = exp(z[i]- max)/sucet;
                    printf("%.2f ", z[i]);
                }
                break;
            }
            case 5: {
                double z[10];
                for(int i = 0; i < 10; i++) {
                    scanf("%lf",&z[i]);
                }
                double max = z[0];
                for(int i = 1; i < 10; i++) {
                    if(z[i] > max) {
                        max = z[i];
                    }
                }
                for(int i = 0; i < 10; i++) {
                    if(z[i] == max) {
                        printf("%d",i);
                        break;
                    }
                }
                break;
            }
            case 6: {
                double image[IMAGE_SIZE];
                load_image(image,IMAGE_SIZE);
                double vysledok[10];
                for(int i = 0; i < 10; i++) {

                    for (int j = 0; j < IMAGE_SIZE; j++) {
                        int w_index = (i * IMAGE_SIZE) + j;
                        vysledok[i] += (image[j] * weights[w_index]);
                    }
                    vysledok[i] += bias[i];

                }
                double max = vysledok[0];
                for(int i = 1; i < 10; i++) {
                    if(vysledok[i] > max) {
                        max = vysledok[i];
                    }
                }
                for(int i = 0; i < 10; i++) {
                    if(vysledok[i] == max) {
                        printf("%d",i);
                        break;
                    }
                }
                break;

            }
        case 7: {
                int K = 0;
                scanf("%d", &K);
                int pole_spravnych[K];


                for (int i = 0; i < K; i++) {
                    scanf("%d", &pole_spravnych[i]);
                }
                double obrazok[K][IMAGE_SIZE];

                for (int i = 0; i < K; i++) {
                    load_image(obrazok[i], IMAGE_SIZE);
                }

                int p[K];

                for (int i = 0; i < K; i++) {
                    double vysledok[10] = {0};


                    for (int k = 0; k < 10; k++) {
                        for (int j = 0; j < IMAGE_SIZE; j++) {
                            int w_index = (k * IMAGE_SIZE) + j;
                            vysledok[k] += obrazok[i][j] * weights[w_index];
                        }
                        vysledok[k] += bias[k];
                    }

                    // Hľadanie max hodnoty
                    double max = vysledok[0];
                    int max_index = 0;
                    for (int f = 1; f < 10; f++) {
                        if (vysledok[f] > max) {
                            max = vysledok[f];
                            max_index = f;
                        }
                    }

                    p[i] = max_index;
                }


                int pocet = 0;
                for (int i = 0; i < K; i++) {
                    if (p[i] == pole_spravnych[i]) {
                        pocet++;
                    }
                }

                double accuracy = (pocet / (double)K) * 100;
                printf("%.2lf", accuracy);


                for (int i = 0; i < K; i++) {
                    printf(" %d-%d-%d", i, pole_spravnych[i], p[i]);
                }


                break;
        }
    }


    return 0;
}



