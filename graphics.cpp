#include "graphics.h"

Graphics::Graphics(){
    graphics_loaded = false;
    QImage alien_graphic1 = QImage(11, 8, QImage::Format_RGB32);
    QImage alien_graphic2 = QImage(11, 8, QImage::Format_RGB32);
    QImage alien_graphic3 = QImage(8, 8, QImage::Format_RGB32);
    QImage alien_graphic4 = QImage(8, 8, QImage::Format_RGB32);
    QImage alien_graphic5 = QImage(12, 8, QImage::Format_RGB32);
    QImage alien_graphic6 = QImage(12, 8, QImage::Format_RGB32);
    QImage death_graphic = QImage(13, 7, QImage::Format_RGB32);
    QImage player_graphic = QImage(11, 7, QImage::Format_RGB32);
    QRgb white = qRgb(255, 255, 255);
    QRgb black = qRgb(0, 0, 0);
    QRgb green = qRgb(0, 255, 0);
    int matrix_alien_1[8][11] = {{0,0,1,0,0,0,0,0,1,0,0}, {0,0,0,1,0,0,0,1,0,0,0}, {0,0,1,1,1,1,1,1,1,0,0}, {0,1,1,0,1,1,1,0,1,1,0}, {1,1,1,1,1,1,1,1,1,1,1}, {1,0,1,1,1,1,1,1,1,0,1}, {1,0,1,0,0,0,0,0,1,0,1}, {0,0,0,1,1,0,1,1,0,0,0}};
    int matrix_alien_2[8][11] = {{0,0,1,0,0,0,0,0,1,0,0}, {1,0,0,1,0,0,0,1,0,0,1}, {1,0,1,1,1,1,1,1,1,0,1}, {1,1,1,0,1,1,1,0,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1}, {0,1,1,1,1,1,1,1,1,1,0}, {0,0,1,0,0,0,0,0,1,0,0}, {0,1,0,0,0,0,0,0,0,1,0}};
    int matrix_alien_3[8][8] = {{0,0,0,1,1,0,0,0}, {0,0,1,1,1,1,0,0}, {0,1,1,1,1,1,1,0}, {1,1,0,1,1,0,1,1}, {1,1,1,1,1,1,1,1}, {0,1,0,1,1,0,1,0}, {1,0,0,0,0,0,0,1}, {0,1,0,0,0,0,1,0}};
    int matrix_alien_4[8][8] = {{0,0,0,1,1,0,0,0}, {0,0,1,1,1,1,0,0}, {0,1,1,1,1,1,1,0}, {1,1,0,1,1,0,1,1}, {1,1,1,1,1,1,1,1}, {0,0,1,0,0,1,0,0}, {0,1,0,1,1,0,1,0}, {1,0,1,0,0,1,0,1}};
    int matrix_alien_5[8][12] = {{0,0,0,0,1,1,1,1,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,1,0}, {1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,0,0,1,1,0,0,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1}, {0,0,0,1,1,0,0,1,1,0,0,0}, {0,0,1,1,0,1,1,0,1,1,0,0}, {1,1,0,0,0,0,0,0,0,0,1,1}};
    int matrix_alien_6[8][12] = {{0,0,0,0,1,1,1,1,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,1,0}, {1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,0,0,1,1,0,0,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1}, {0,0,1,1,1,0,0,1,1,1,0,0}, {0,1,1,0,0,1,1,0,0,1,1,0}, {0,0,1,1,0,0,0,0,1,1,0,0}};
    int death_matrix[7][13] = {{0,1,0,0,1,0,0,0,1,0,0,1,0}, {0,0,1,0,0,1,0,1,0,0,1,0,0}, {0,0,0,1,0,0,0,0,0,1,0,0,0}, {1,1,0,0,0,0,0,0,0,0,0,1,1}, {0,0,0,1,0,0,0,0,0,1,0,0,0}, {0,0,1,0,0,1,0,1,0,0,1,0,0}, {0,1,0,0,1,0,0,0,1,0,0,1,0}};
    int player_matrix[7][11] = {{0,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,1,1,1,0,0,0,0}, {0,0,0,0,1,1,1,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,0}, {1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1}};
    for(int i=0; i<8; i++){
        for(int j = 0; j<13; j++){
            if(j<12){
                if(matrix_alien_5[i][j]==0){
                    alien_graphic5.setPixel(j, i, black);
                }
                else{
                    alien_graphic5.setPixel(j, i, white);
                }
                if(matrix_alien_6[i][j]==0){
                    alien_graphic6.setPixel(j, i, black);
                }
                else{
                    alien_graphic6.setPixel(j, i, white);
                }
            }
            if(j<11 && i<7){
                if(player_matrix[i][j]==0){
                    player_graphic.setPixel(j, i, black);
                }
                else{
                    player_graphic.setPixel(j, i, green);
                }
            }
            if(j<11){
            if(matrix_alien_1[i][j]==0){
                alien_graphic1.setPixel(j, i, black);
            }
            else{
                alien_graphic1.setPixel(j, i, white);
            }
            if(matrix_alien_2[i][j]==0){
                alien_graphic2.setPixel(j, i, black);
            }
            else{
                alien_graphic2.setPixel(j, i, white);
            }
            }
            if(i<7){
                if(death_matrix[i][j]==0){
                    death_graphic.setPixel(j, i, black);
               }
                else{
                    death_graphic.setPixel(j, i, white);
                }
            }
        }
    }
    for(int x = 0; x<8; x++){
        for(int y=0; y<8; y++){
            if(matrix_alien_3[x][y] == 0){
                alien_graphic3.setPixel(y, x, black);
            }
            else{
                alien_graphic3.setPixel(y, x, white);
            }
            if(matrix_alien_4[x][y]==0){
                alien_graphic4.setPixel(y, x, black);
            }
            else{
                alien_graphic4.setPixel(y, x, white);
            }
        }
    }


    QPixmap temp_alien_pixmap1 = QPixmap::fromImage(alien_graphic1);
    QPixmap temp_alien_pixmap2 = QPixmap::fromImage(alien_graphic2);
    QPixmap temp_death = QPixmap::fromImage(death_graphic);
    QPixmap temp_player = QPixmap::fromImage(player_graphic);
    QPixmap temp_alien_pixmap3 = QPixmap::fromImage(alien_graphic3);
    QPixmap temp_alien_pixmap4 = QPixmap::fromImage(alien_graphic4);
    QPixmap temp_alien_pixmap5 = QPixmap::fromImage(alien_graphic5);
    QPixmap temp_alien_pixmap6 = QPixmap::fromImage(alien_graphic6);
    alien_pixmap1 = temp_alien_pixmap1.scaled(QSize(27, 20));
    alien_pixmap2 = temp_alien_pixmap2.scaled(QSize(27, 20));
    alien_pixmap3 = temp_alien_pixmap3.scaled(QSize(24, 24));
    alien_pixmap4 = temp_alien_pixmap4.scaled(QSize(24, 24));
    alien_pixmap5 = temp_alien_pixmap5.scaled(QSize(30, 20));
    alien_pixmap6 = temp_alien_pixmap6.scaled(QSize(30, 20));
    death_pixmap = temp_death.scaled(QSize(27, 20));
    player_pixmap = temp_player.scaled(QSize(38, 24));
    graphics_loaded = true;
}
