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
    QImage player_death = QImage(13, 7, QImage::Format_RGB32);
    QImage ufo_graphic = QImage(16, 7, QImage::Format_RGB32);
    QImage ufo_death = QImage(13, 7, QImage::Format_RGB32);
    QImage bunker1 = QImage(6, 6, QImage::Format_RGB32);
    QImage bunker2 = QImage(6, 6, QImage::Format_RGB32);
    QImage bunker3 = QImage(6, 6, QImage::Format_RGB32);
    QImage bunker4 = QImage(6, 6, QImage::Format_RGB32);
    QRgb white = qRgb(255, 255, 255);
    QRgb black = qRgb(0, 0, 0);
    QRgb green = qRgb(0, 255, 0);
    QRgb red = qRgb(255, 0, 0);
    int matrix_alien_1[8][11] = {{0,0,1,0,0,0,0,0,1,0,0}, {0,0,0,1,0,0,0,1,0,0,0}, {0,0,1,1,1,1,1,1,1,0,0}, {0,1,1,0,1,1,1,0,1,1,0}, {1,1,1,1,1,1,1,1,1,1,1}, {1,0,1,1,1,1,1,1,1,0,1}, {1,0,1,0,0,0,0,0,1,0,1}, {0,0,0,1,1,0,1,1,0,0,0}};
    int matrix_alien_2[8][11] = {{0,0,1,0,0,0,0,0,1,0,0}, {1,0,0,1,0,0,0,1,0,0,1}, {1,0,1,1,1,1,1,1,1,0,1}, {1,1,1,0,1,1,1,0,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1}, {0,1,1,1,1,1,1,1,1,1,0}, {0,0,1,0,0,0,0,0,1,0,0}, {0,1,0,0,0,0,0,0,0,1,0}};
    int matrix_alien_3[8][8] = {{0,0,0,1,1,0,0,0}, {0,0,1,1,1,1,0,0}, {0,1,1,1,1,1,1,0}, {1,1,0,1,1,0,1,1}, {1,1,1,1,1,1,1,1}, {0,1,0,1,1,0,1,0}, {1,0,0,0,0,0,0,1}, {0,1,0,0,0,0,1,0}};
    int matrix_alien_4[8][8] = {{0,0,0,1,1,0,0,0}, {0,0,1,1,1,1,0,0}, {0,1,1,1,1,1,1,0}, {1,1,0,1,1,0,1,1}, {1,1,1,1,1,1,1,1}, {0,0,1,0,0,1,0,0}, {0,1,0,1,1,0,1,0}, {1,0,1,0,0,1,0,1}};
    int matrix_alien_5[8][12] = {{0,0,0,0,1,1,1,1,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,1,0}, {1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,0,0,1,1,0,0,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1}, {0,0,0,1,1,0,0,1,1,0,0,0}, {0,0,1,1,0,1,1,0,1,1,0,0}, {1,1,0,0,0,0,0,0,0,0,1,1}};
    int matrix_alien_6[8][12] = {{0,0,0,0,1,1,1,1,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,1,0}, {1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,0,0,1,1,0,0,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1}, {0,0,1,1,1,0,0,1,1,1,0,0}, {0,1,1,0,0,1,1,0,0,1,1,0}, {0,0,1,1,0,0,0,0,1,1,0,0}};
    int death_matrix[7][13] = {{0,1,0,0,1,0,0,0,1,0,0,1,0}, {0,0,1,0,0,1,0,1,0,0,1,0,0}, {0,0,0,1,0,0,0,0,0,1,0,0,0}, {1,1,0,0,0,0,0,0,0,0,0,1,1}, {0,0,0,1,0,0,0,0,0,1,0,0,0}, {0,0,1,0,0,1,0,1,0,0,1,0,0}, {0,1,0,0,1,0,0,0,1,0,0,1,0}};
    int player_matrix[7][11] = {{0,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,1,1,1,0,0,0,0}, {0,0,0,0,1,1,1,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,0}, {1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1}};
    int ufo_matrix[7][16] = {{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}};
    int bunker2_matrix[6][6] = {{0, 1, 1, 0, 1, 1 }, {1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 1}, {1, 1, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}};
    int bunker3_matrix[6][6] = {{0, 0, 1, 0, 1, 1}, {0, 0, 1, 1, 0, 0}, {0, 1, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 0}};
    int bunker4_matrix[6][6] = {{0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 1}, {0, 0, 0, 1, 0, 0}};
    for(int i=0; i<8; i++){
        for(int j = 0; j<13; j++){
            if(j<6 && i<6){
                bunker1.setPixel(j, i, green);
                if(bunker2_matrix[i][j]==0){
                    bunker2.setPixel(j, i, black);
                }
                else{
                    bunker2.setPixel(j, i, green);
                }
                if(bunker3_matrix[i][j]==0){
                    bunker3.setPixel(j, i, black);
                }
                else{
                    bunker3.setPixel(j, i, green);
                }
                if(bunker4_matrix[i][j]==0){
                    bunker4.setPixel(j, i, black);
                }
                else{
                    bunker4.setPixel(j, i, green);
                }
            }
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
                    ufo_death.setPixel(j, i, black);
                    player_death.setPixel(j, i, black);
               }
                else{
                    death_graphic.setPixel(j, i, white);
                    ufo_death.setPixel(j, i, red);
                    player_death.setPixel(j, i, green);
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
    for(int i=0; i<7; i++){
        for(int j=0; j<16; j++){
            if(ufo_matrix[i][j]==0){
                ufo_graphic.setPixel(j, i, black);
            }
            else{
                ufo_graphic.setPixel(j, i, red);
            }
        }
    }


    QPixmap temp_alien_pixmap1 = QPixmap::fromImage(alien_graphic1);
    QPixmap temp_alien_pixmap2 = QPixmap::fromImage(alien_graphic2);
    QPixmap temp_death = QPixmap::fromImage(death_graphic);
    QPixmap temp_player = QPixmap::fromImage(player_graphic);
    QPixmap temp_player_death = QPixmap::fromImage(player_death);
    QPixmap temp_alien_pixmap3 = QPixmap::fromImage(alien_graphic3);
    QPixmap temp_alien_pixmap4 = QPixmap::fromImage(alien_graphic4);
    QPixmap temp_alien_pixmap5 = QPixmap::fromImage(alien_graphic5);
    QPixmap temp_alien_pixmap6 = QPixmap::fromImage(alien_graphic6);
    QPixmap temp_ufo_pixmap = QPixmap::fromImage(ufo_graphic);
    QPixmap temp_ufo_death = QPixmap::fromImage(ufo_death);
    QPixmap temp_bunker1 = QPixmap::fromImage(bunker1);
    QPixmap temp_bunker2 = QPixmap::fromImage(bunker2);
    QPixmap temp_bunker3 = QPixmap::fromImage(bunker3);
    QPixmap temp_bunker4 = QPixmap::fromImage(bunker4);
    alien_pixmap1 = temp_alien_pixmap1.scaled(QSize(27, 20));
    alien_pixmap2 = temp_alien_pixmap2.scaled(QSize(27, 20));
    alien_pixmap3 = temp_alien_pixmap3.scaled(QSize(24, 24));
    alien_pixmap4 = temp_alien_pixmap4.scaled(QSize(24, 24));
    alien_pixmap5 = temp_alien_pixmap5.scaled(QSize(30, 20));
    alien_pixmap6 = temp_alien_pixmap6.scaled(QSize(30, 20));
    death_pixmap = temp_death.scaled(QSize(27, 20));
    player_pixmap = temp_player.scaled(QSize(38, 24));
    player_death_pixmap = temp_player_death.scaled(QSize(37, 22));
    ufo_pixmap = temp_ufo_pixmap.scaled(QSize(48, 21));
    ufo_death_pixmap = temp_ufo_death.scaled(QSize(34, 20));
    bunker1_pixmap = temp_bunker1.scaled(QSize(25, 25));
    bunker2_pixmap = temp_bunker2.scaled(QSize(25, 25));
    bunker3_pixmap = temp_bunker3.scaled(QSize(25, 25));
    bunker4_pixmap = temp_bunker4.scaled(QSize(25, 25));
    graphics_loaded = true;
}
