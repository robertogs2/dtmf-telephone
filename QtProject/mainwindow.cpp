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
 * \file   mainwindow.cpp
 *         Implements the equalizer H(w) computation
 * \author Pablo Alvarado
 * \date   2010.12.12
 *
 * $Id: equalizer.cpp $
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jack.h"
#include "constants.h"
#include <string>
#include <iostream>

#undef _DSP_DEBUG
#define _DSP_DEBUG

#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif


/**
 * Precision used by trimming
 */
const float MainWindow::Epsilon = 0.001;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    verbose_(false),
    dspChanged_(true)
{
    ui->setupUi(this);
    /*
     * Set up a timer 4 times in a second to check if the user
     * changed the equalizer values, and if so, then create a new
     * filter response
     */
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_->start(250);

    dsp_ = new dspSystem;
    jack::init(dsp_);

    // parse some command line arguments
    QStringList argv(QCoreApplication::arguments());

    QStringList::const_iterator it(argv.begin());
    while(it!=argv.end()) {
      if ((*it)=="-v" || (*it)=="--verbose") {
        verbose_=true;
      } else if ((*it).indexOf(".wav",0,Qt::CaseInsensitive)>0) {
        //ui->fileEdit->setText(*it);
        std::string tmp(qPrintable(*it));
        jack::playAlso(tmp.c_str());
      }
      ++it;
    }

}


MainWindow::~MainWindow()
{
    jack::close();
    delete timer_;
    delete ui;
    delete dsp_;
}

void MainWindow::update() {
    if(dspChanged_){
        _debug("Updating" << std::endl);

        dspChanged_=false;
    }
}


void MainWindow::on_volumeSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolume(value);
}



void MainWindow::on_button1_pressed(){
  button_pressed(0,0);
}

void MainWindow::on_button1_released(){
  button_released(0,0);
}

void MainWindow::on_button2_pressed(){
  button_pressed(0,1);
}

void MainWindow::on_button2_released(){
  button_released(0,1);
}

void MainWindow::on_button3_pressed(){
  button_pressed(0,2);
}

void MainWindow::on_button3_released(){
  button_released(0,2);
}

void MainWindow::on_buttonA_pressed(){
  button_pressed(0,3);
}

void MainWindow::on_buttonA_released(){
  ui->labelDigits->setText("#911*");
  dsp_->setUChain("#911*");
  // Same as s
  bool start = dsp_->getUChain().size() > 0;
  if(start){ // There is a chain to play
    dsp_->setToneActive(true);
    dsp_->setChainActive(true);
    dsp_->setChainFlank(true);
    dsp_->setPChain(-1);
    ui->labelDigits->setText("");
  }
  //button_released(0,3);
}

void MainWindow::on_button4_pressed(){
  button_pressed(1,0);
}

void MainWindow::on_button4_released(){
  button_released(1,0);
}

void MainWindow::on_button5_pressed(){
  button_pressed(1,1);
}

void MainWindow::on_button5_released(){
  button_released(1,1);
}

void MainWindow::on_button6_pressed(){
  button_pressed(1,2);
}

void MainWindow::on_button6_released(){
  button_released(1,2);
}

void MainWindow::on_buttonB_pressed(){
  button_pressed(1,3);
}

void MainWindow::on_buttonB_released(){
   ui->labelDigits->setText(QString::fromStdString(dsp_->lastNumber));
   dsp_->setUChain(dsp_->lastNumber);
  button_released(1,3);
}

void MainWindow::on_button7_pressed(){
  button_pressed(2,0);
}

void MainWindow::on_button7_released(){
  button_released(2,0);
}

void MainWindow::on_button8_pressed(){
  button_pressed(2,1);
}

void MainWindow::on_button8_released(){
  button_released(2,1);
}

void MainWindow::on_button9_pressed(){
  button_pressed(2,2);
}

void MainWindow::on_button9_released(){
  button_released(2,2);
}

void MainWindow::on_buttonC_pressed(){
  dsp_->updateVolume(ui->volumeSlider->value()+1);
  //button_pressed(2,3);
}

void MainWindow::on_buttonC_released(){
  button_released(2,3);
}

void MainWindow::on_buttonS_pressed(){
  dsp_->lastNumber = dsp_->getUChain();
  button_pressed(3,0);
}

void MainWindow::on_buttonS_released(){
  //button_released(3,0);
  bool start = dsp_->getUChain().size() > 0;
  if(start){ // There is a chain to play
    dsp_->setToneActive(true);
    dsp_->setChainActive(true);
    dsp_->setChainFlank(true);
    dsp_->setPChain(-1);
    ui->labelDigits->setText("");
  }
  else{
    dsp_->setToneActive(false);
    dsp_->setChainActive(false);
    dsp_->setChainFlank(false);
    dsp_->setPChain(-1);
  }
}

void MainWindow::on_button0_pressed(){
  button_pressed(3,1);
}

void MainWindow::on_button0_released(){
  button_released(3,1);
}

void MainWindow::on_buttonN_pressed(){
  button_pressed(3,2);
}

void MainWindow::on_buttonN_released(){
  button_released(3,2);
}

void MainWindow::on_buttonD_pressed(){
  button_pressed(3,3);
}

void MainWindow::on_buttonD_released(){
  button_released(3,3);
}

void MainWindow::button_pressed(int i, int j){
  std::cout << "pressing" << std::endl;
  if(dsp_->getHanging()){
      // Activates the oscillation while it is runnings
    dsp_->setToneActive(true);
    float f1 = constants::sideFrequencies[i];
    float f2 = constants::upperFrequencies[j];
    dsp_->setFrequencies(f1, f2);

    // Adds to the chain as soon as it is pressed
    dsp_->addToChain(utils::getChar(i, j));
    ui->labelDigits->setText(QString::fromStdString(dsp_->getUChain()));
  }
}

void MainWindow::button_released(int i, int j){
  dsp_->setToneActive(false);
}

void MainWindow::on_buttonAC_clicked(){
    dsp_->setUChain("");
    ui->labelDigits->setText("");
}

void MainWindow::on_buttonDel_clicked(){
  std::string chain = dsp_->getUChain();
  chain = chain.substr(0, chain.size()-1);
  dsp_->setUChain(chain);
  ui->labelDigits->setText(QString::fromStdString(chain));
}

void MainWindow::on_buttonDesc_clicked(){
  bool h = dsp_->getHanging();
  if(h){
    ui->buttonDesc->setText(QString::fromStdString(constants::desc));
  }
  else{
    ui->buttonDesc->setText(QString::fromStdString(constants::col));
  }
  dsp_->setUChain("");
  ui->labelDigits->setText("");
  dsp_->setHanging(!h);
}
