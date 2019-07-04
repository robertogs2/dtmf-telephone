/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2010  Pablo Alvarado
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file   mainwindow.h
 *         Implements the equalizer H(w) computation
 * \author Pablo Alvarado/Jose Miguel Barboza
 * \date   2010.12.12/2017.05.26
 *
 * $Id: mainwindow.h $
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFileDialog>

#include "dspsystem.h"
#include "constants.h"
#include "utils.h"
#include "vectoroperations.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int volumeGain;
    /**
      *Tolerance value
      */
    static const float Epsilon;

     /**
      * Verbose flag
      */
     bool verbose_;

     /**
      * Timer used to recompute the filter once the user changes the
      * values
      */
     QTimer *timer_;

     /**
      * List of selected files so far
      */
     QStringList selectedFiles_;

     /**
      * Pointer to an inherited class of processor, which does
      * all the real work.
      */
     dspSystem* dsp_;

     /**
      *DSP change
      */
     bool dspChanged_;
     
   private slots:
     //void on_fileEdit_returnPressed();
     //void on_fileButton_clicked();
     void on_volumeSlider_valueChanged(int value);

     void on_button1_pressed();
     void on_button1_released();
     void on_button2_pressed();
     void on_button2_released();
     void on_button3_pressed();
     void on_button3_released();
     void on_buttonA_pressed();
     void on_buttonA_released();
     void on_button4_pressed();
     void on_button4_released();
     void on_button5_pressed();
     void on_button5_released();
     void on_button6_pressed();
     void on_button6_released();
     void on_buttonB_pressed();
     void on_buttonB_released();
     void on_button7_pressed();
     void on_button7_released();
     void on_button8_pressed();
     void on_button8_released();
     void on_button9_pressed();
     void on_buttonC_pressed();
     void on_buttonC_released();
     void on_button9_released();
     void on_buttonS_pressed();
     void on_buttonS_released();
     void on_button0_pressed();
     void on_button0_released();
     void on_buttonN_pressed();
     void on_buttonN_released();
     void on_buttonD_pressed();
     void on_buttonD_released();

     void update();
     void button_pressed(int i, int j);
     void button_released(int i, int j);
     void on_buttonAC_clicked();
     void on_buttonDel_clicked();
     void on_buttonDesc_clicked();
};


#endif // MAINWINDOW_H
