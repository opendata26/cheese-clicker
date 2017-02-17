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
    itemDescText[0] = new GuiText(cowDesc, 25, glm::vec4(0, 0, 0, 1));
    itemDescText[1] = new GuiText(maidDesc, 25, glm::vec4(0, 0, 0, 1));
    itemDescText[2] = new GuiText(dairyDesc, 25, glm::vec4(0, 0, 0, 1));

    backgroundDescImgData = Resources::GetImageData("backgroundBtn.png");
    backgroundDescImg[0] = new GuiImage(backgroundDescImgData);
    backgroundDescImg[0]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    backgroundDescImg[1] = new GuiImage(backgroundDescImgData);
    backgroundDescImg[1]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    backgroundDescImg[2] = new GuiImage(backgroundDescImgData);
    backgroundDescImg[2]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    backgroundDescImg[0]->setPosition(0, 200);
    backgroundDescImg[1]->setPosition(0, 0);
    backgroundDescImg[2]->setPosition(0, -200);
    itemDescText[0]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    itemDescText[1]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    itemDescText[2]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    itemDescText[0]->setPosition(-230, 195);
    itemDescText[1]->setPosition(-230, -5);
    itemDescText[2]->setPosition(-230, -205);
    append(backgroundDescImg[0]);
    append(backgroundDescImg[1]);
    append(backgroundDescImg[2]);
    append(itemDescText[0]);
    append(itemDescText[1]);
    append(itemDescText[2]);
 

    backgroundBuyBtnImgData = Resources::GetImageData("backgroundBuyBtn.png");
    backgroundBuyBtnImg[0] = new GuiImage(backgroundBuyBtnImgData);
    backgroundBuyBtnImg[1] = new GuiImage(backgroundBuyBtnImgData);
    backgroundBuyBtnImg[2] = new GuiImage(backgroundBuyBtnImgData);

    buyBtn[0] = new GuiButton(backgroundBuyBtnImg[0]->getWidth(), backgroundBuyBtnImg[0]->getHeight());
    buyBtn[0]->setImage(backgroundBuyBtnImg[0]);
    buyBtn[0]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    buyBtn[0]->setTrigger(touchTrigger);
    buyBtn[0]->setSoundClick(clickSound);
    buyBtn[0]->setEffectGrow();

    buyBtn[1] = new GuiButton(backgroundBuyBtnImg[1]->getWidth(), backgroundBuyBtnImg[1]->getHeight());
    buyBtn[1]->setImage(backgroundBuyBtnImg[1]);
    buyBtn[1]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    buyBtn[1]->setTrigger(touchTrigger);
    buyBtn[1]->setSoundClick(clickSound);
    buyBtn[1]->setEffectGrow();
    
    buyBtn[2] = new GuiButton(backgroundBuyBtnImg[2]->getWidth(), backgroundBuyBtnImg[2]->getHeight());
    buyBtn[2]->setImage(backgroundBuyBtnImg[2]);
    buyBtn[2]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    buyBtn[2]->setTrigger(touchTrigger);
    buyBtn[2]->setSoundClick(clickSound);
    buyBtn[2]->setEffectGrow();

    buyBtn[0]->setPosition(250, 200);
    buyBtn[1]->setPosition(250, 0);
    buyBtn[2]->setPosition(250, -200);
    buyBtn[0]->setLabel(buyText[0]);
    buyBtn[1]->setLabel(buyText[1]);
    buyBtn[2]->setLabel(buyText[2]);
    buyBtn[0]->clicked.connect(this, &ShopWindow::onBuyBtn1Clicked);//todo: Clean this up
    buyBtn[1]->clicked.connect(this, &ShopWindow::onBuyBtn2Clicked);//
    buyBtn[2]->clicked.connect(this, &ShopWindow::onBuyBtn3Clicked);//
    append(buyBtn[0]);
    append(buyBtn[1]);
    append(buyBtn[2]);

    backBtnImgData = Resources::GetImageData("backBtn.png");
    backBtnImg = new GuiImage(backBtnImgData);
 
    backBtn = new GuiButton(backBtnImg->getWidth(), backBtnImg->getHeight());

    backBtn->setImage(backBtnImg);
    backBtn->setAlignment(ALIGN_BOTTOM | ALIGN_LEFT);
    backBtn->setTrigger(touchTrigger);
    backBtn->clicked.connect(this, &ShopWindow::onBackBtnClick);
    backBtn->setSoundClick(clickSound);
    backBtn->setEffectGrow();
    append(backBtn);


}

ShopWindow::~ShopWindow()
{
    remove(&bgImageColor);
}

void ShopWindow::update(GuiController * c){
    GuiFrame::update(c);
}


void ShopWindow::onBuyBtn1Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger){
    sliceMultiplier += 17; 
    itemAmount[0]++;
    itemPrice[0] += 300 * itemAmount[0];
    sprintf(cowText, "Buy 1 for %d. Current amount: %d", itemPrice[0], itemAmount[0]); 
}

void ShopWindow::onBuyBtn2Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger){
    sliceMultiplier += 786;
    itemAmount[1]++;
    itemPrice[1] += 10000 * itemAmount[1];
    sprintf(maidText, "Buy 1 for %d. Current amount: %d", itemPrice[1], itemAmount[1]);
}

void ShopWindow::onBuyBtn3Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger){
    sliceMultiplier += 47689;
    itemAmount[2]++;
    itemPrice[2] += 50000000 * itemAmount[2];
    sprintf(dairyText, "Buy 1 for %d. Current amount: %d", itemPrice[2], itemAmount[2]);
}

