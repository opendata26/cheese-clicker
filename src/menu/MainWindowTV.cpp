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
#include "MainWindowTV.h"
#include "utils/logger.h"

MainWindowTV::MainWindowTV(int w, int h)
    : GuiMainWindowScreen(w, h)
    , width(w)
    , height(h)
    ,bgImageColor(w, h, (GX2Color){ 0, 0, 0, 0 })
{
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 0);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 1);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 2);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 3);
    append(&bgImageColor);
   
    sliceMultiplier = 0;
    touchTrigger = new GuiTrigger(GuiTrigger::CHANNEL_1, GuiTrigger::VPAD_TOUCH);

    clickSound = new GuiSound(Resources::GetFile("click.mp3"), Resources::GetFileSize("click.mp3"));

    shopBtnImgData = Resources::GetImageData("shop_button.png");
    shopBtnImg = new GuiImage(shopBtnImgData);
    
    shopBtn = new GuiButton(shopBtnImg->getWidth(), shopBtnImg->getHeight());
    shopBtn->setImage(shopBtnImg);
    shopBtn->setAlignment(ALIGN_BOTTOM | ALIGN_LEFT);
    shopBtn->setTrigger(touchTrigger);
    shopBtn->clicked.connect(this, &MainWindowTV::onShopBtnClick);
    shopBtn->setSoundClick(clickSound);
    shopBtn->setEffectGrow();
    append(shopBtn);

    cheeseAnim[0] = Resources::GetImageData("cheese1.png");
    cheeseAnim[1] = Resources::GetImageData("cheese2.png");
    cheeseAnim[2] = Resources::GetImageData("cheese3.png");
    cheese = new GuiImage(cheeseAnim[0]);    
    cheese->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    cheese->setPosition(0, 0);
    append(cheese);
    
    // The below code wll draw "Hello World!" as a string
    // opionally underneath the pie, if it is available
    slicesText = new GuiText(slicesChar, 40, glm::vec4(0, 0, 0, 1));
    slicesText->setAlignment(ALIGN_CENTER | ALIGN_CENTER); // start from center
    slicesText->setPosition(0, 200); // move the text left 200 from the center
    append(slicesText);
}

MainWindowTV::~MainWindowTV()
{
    remove(&bgImageColor);
    delete(clickSound);
    delete(cheese);
}

void MainWindowTV::draw(CVideo *v){
	GuiMainWindowScreen::draw(v);
	//gets called on every frame for drawing
}


void MainWindowTV::update(GuiController * c){
    GuiMainWindowScreen::update(c);
    //CONTROLLER UPDATE!!!
    
    x=c->data.x;
    y=c->data.y;
    log_printf("x:%d y:%d", x, y);
    if(x > -217 && x < 222 && y > -133 && y < 138 && c->data.touched && valid) {
        log_printf("tapped");
        clickSound->Stop();
        clickSound->Play();
        clicked = 1;
    }
    if(!valid && !c->data.touched)
        valid = TRUE;
}

void MainWindowTV::process(){
    GuiMainWindowScreen::process();
    
    if(clicked == 1){
        if(currentAnimStage == 2) {
            currentAnimStage = 0;
            cheese->setImageData(cheeseAnim[currentAnimStage]);
        } else {
            currentAnimStage ++;
            cheese->setImageData(cheeseAnim[currentAnimStage]);
        }

        slices += 1 + sliceMultiplier;
        clicked = 0;
        sprintf(slicesChar, "%d slices", slices); 
        slicesText->setText(slicesChar);
        valid = FALSE;
    }

}

void MainWindowTV::onShopBtnClick(GuiButton* button, const GuiController* controller, GuiTrigger* trigger)
{
    shopBtn->setState(GuiElement::STATE_DISABLED);
    //! show equal screen on settings
    ShopWindow* settings = new ShopWindow(width, height);
    //settings->setEffect(EFFECT_FADE, 10, 255);
    //settings->setState(GuiElement::STATE_DISABLED);
    //settings->settingsQuitClicked.connect(this, &MainWindow::OnSettingsQuit);
    //settings->effectFinished.connect(this, &MainWindow::OnOpenEffectFinish);
    append(settings);
}

