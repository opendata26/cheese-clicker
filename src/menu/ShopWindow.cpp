/****************************************************************************
 * Copyright (C) 2015 Dimok
 * Modified by Maschell, 2016 for GX2_GUI_Template
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
 ****************************************************************************/
#include "ShopWindow.h"
#include "utils/logger.h"

ShopWindow::ShopWindow(int w, int h)
    : GuiFrame(w, h)
    , width(w)
    , height(h)
    ,bgImageColor(w, h, (GX2Color){ 0, 0, 0, 0 })
{
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 0);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 1);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 2);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 3);
    append(&bgImageColor);
    
    touchTrigger = new GuiTrigger(GuiTrigger::CHANNEL_1, GuiTrigger::VPAD_TOUCH);

    clickSound = new GuiSound(Resources::GetFile("click.mp3"), Resources::GetFileSize("click.mp3"));
    
    buyText[0] = new GuiText(cowText, 40, glm::vec4(0, 0, 0, 1));
    buyText[1] = new GuiText(maidText, 40, glm::vec4(0, 0, 0, 1));
    buyText[2] = new GuiText(dairyText, 40, glm::vec4(0, 0, 0, 1));
    itemDescText[0] = new GuiText(cowDesc, 40, glm::vec4(0, 0, 0, 1));
    itemDescText[1] = new GuiText(maidDesc, 40, glm::vec4(0, 0, 0, 1));
    itemDescText[2] = new GuiText(dairyDesc, 40, glm::vec4(0, 0, 0, 1));

    backgroundDescImgData = Resources::GetImageData("backgroundBtn.png");
    for(int i=0;i<2;i++) backgroundDescImg[i] = new GuiImage(backgroundDescImgData);
    for(int i=0;i<2;i++) backgroundDescImg[i]->setAlignment(ALIGN_CENTER | ALIGN_CENTER );
    backgroundDescImg[0]->setPosition(0, 40);
    backgroundDescImg[1]->setPosition(0, 0);
    backgroundDescImg[2]->setPosition(0, -40);
    for(int i=0;i<2;i++) append(backgroundDescImg[i]);

    backgroundBuyBtnImgData = Resources::GetImageData("backgroundBuyBtn.png");
    backgroundBuyBtnImg = new GuiImage(backgroundBuyBtnImgData);

    for(int i=0;i<2;i++){
        buyBtn[i] = new GuiButton(backgroundBuyBtnImg->getWidth(), backgroundBuyBtnImg->getHeight());
        buyBtn[i]->setImage(backgroundBuyBtnImg);
        buyBtn[i]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
        buyBtn[i]->setTrigger(touchTrigger);
        buyBtn[i]->setSoundClick(clickSound);
        buyBtn[i]->setEffectGrow();
    }
    buyBtn[0]->setPosition(20, 40);
    buyBtn[1]->setPosition(20, 0);
    buyBtn[2]->setPosition(20, -40);
    buyBtn[0]->setLabel(buyText[0]);
    buyBtn[1]->setLabel(buyText[1]);
    buyBtn[2]->setLabel(buyText[2]);
    buyBtn[0]->clicked.connect(this, &ShopWindow::onBuyBtn1Clicked);//todo: Clean this up
    buyBtn[1]->clicked.connect(this, &ShopWindow::onBuyBtn2Clicked);//
    buyBtn[2]->clicked.connect(this, &ShopWindow::onBuyBtn3Clicked);//
    for(int i=0;i<2;i++) append(buyBtn[i]);

}

ShopWindow::~ShopWindow()
{
    remove(&bgImageColor);
}

void ShopWindow::draw(CVideo *v){
}


void ShopWindow::update(GuiController * c){

}

void ShopWindow::process(){
}

void ShopWindow::onBuyBtn1Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger){
    MainWindowTV->sliceMultiplier += 17; 
    itemAmount[0]++;
    itemPrice[0] += 300 * itemAmount[0];
    sprintf(cowText, "Buy 1 for %d. Current amount: %d", itemPrice[0], itemAmount[0]); 
}

void ShopWindow::onBuyBtn2Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger){
    MainWindowTV->sliceMultiplier += 786;
    itemAmount[1]++;
    itemPrice[1] += 10000 * itemAmount[1];
    sprintf(maidText, "Buy 1 for %d. Current amount: %d", itemPrice[1], itemAmount[1]);
}

void ShopWindow::onBuyBtn3Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger){
    MainWindowTV->sliceMultiplier += 47689;
    itemAmount[2]++;
    itemPrice[2] += 50000000 * itemAmount[2];
    sprintf(dairyText, "Buy 1 for %d. Current amount: %d", itemPrice[2], itemAmount[2]);
}

