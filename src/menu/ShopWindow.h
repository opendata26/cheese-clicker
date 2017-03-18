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
#ifndef _SHOP_WINDOW_H_
#define _SHOP_WINDOW_H_

#include "gui/Gui.h"
#include "gui/GuiMainWindowScreen.h"
#include "gui/VPadController.h"
#include "menu/MainWindowTV.h"

class CVideo;

class ShopWindow : public GuiFrame, public sigslot::has_slots<>{
public:
    ShopWindow(int w, int h);
    virtual ~ShopWindow();

    sigslot::signal1<GuiElement *> backButtonClicked;
private:
    
    char *cowDesc = "A cow that gives you 17 more slices \n per click";
    char *maidDesc = "A maid that gives 786 more slices \n per click";
    char *dairyDesc = "A dairy that gives 47689 more \n slices per click";
    char *cowText = "Buy 1 for 300";
    char *maidText = "Buy 1 for 10000"; 
    char *dairyText = "Buy 1 for 50000000";

    int width, height;
    int itemPrice[3];
    int itemAmount[3];

    GuiImage bgImageColor;

    GuiSound *clickSound;

    GuiImageData* bgImgData;
    GuiImageData* backgroundDescImgData;
    GuiImageData* backgroundBuyBtnImgData;
    GuiImageData* backBtnImgData;

    GuiButton* buyBtn[3]; 
    GuiButton* backBtn;

    GuiTrigger* touchTrigger;

    GuiImage* backgroundDescImg[3];
    GuiImage* backgroundBuyBtnImg[3];
    GuiImage* backBtnImg;

    GuiText* buyText[3];
    GuiText* itemDescText[3];
    
    void update(GuiController * c);
    void onBuyBtn1Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger);
    void onBuyBtn2Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger);
    void onBuyBtn3Clicked(GuiButton* button, const GuiController* controller, GuiTrigger* trigger);
    
    void onBackBtnClicked(GuiButton *button, const GuiController *controller, GuiTrigger *trigger){
        backButtonClicked(this);
    }
};

#endif //_SHOP_WINDOW_H_
