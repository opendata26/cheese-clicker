/****************************************************************************
 * Loadiine resource files.
 * This file is generated automatically.
 * Includes 10 files.
 *
 * NOTE:
 * Any manual modification of this file will be overwriten by the generation.
 ****************************************************************************/
#ifndef _FILELIST_H_
#define _FILELIST_H_

#include <gctypes.h>

typedef struct _RecourceFile
{
	const char *filename;
	const u8   *DefaultFile;
	const u32  &DefaultFileSize;
	u8		   *CustomFile;
	u32		    CustomFileSize;
} RecourceFile;

extern const u8 backBtn_png[];
extern const u32 backBtn_png_size;

extern const u8 backgroundBtn_png[];
extern const u32 backgroundBtn_png_size;

extern const u8 backgroundBuyBtn_png[];
extern const u32 backgroundBuyBtn_png_size;

extern const u8 cheese1_png[];
extern const u32 cheese1_png_size;

extern const u8 cheese2_png[];
extern const u32 cheese2_png_size;

extern const u8 cheese3_png[];
extern const u32 cheese3_png_size;

extern const u8 click_mp3[];
extern const u32 click_mp3_size;

extern const u8 font_ttf[];
extern const u32 font_ttf_size;

extern const u8 shop_button_clicked_png[];
extern const u32 shop_button_clicked_png_size;

extern const u8 shop_button_png[];
extern const u32 shop_button_png_size;

static RecourceFile RecourceList[] =
{
	{"backBtn.png", backBtn_png, backBtn_png_size, NULL, 0},
	{"backgroundBtn.png", backgroundBtn_png, backgroundBtn_png_size, NULL, 0},
	{"backgroundBuyBtn.png", backgroundBuyBtn_png, backgroundBuyBtn_png_size, NULL, 0},
	{"cheese1.png", cheese1_png, cheese1_png_size, NULL, 0},
	{"cheese2.png", cheese2_png, cheese2_png_size, NULL, 0},
	{"cheese3.png", cheese3_png, cheese3_png_size, NULL, 0},
	{"click.mp3", click_mp3, click_mp3_size, NULL, 0},
	{"font.ttf", font_ttf, font_ttf_size, NULL, 0},
	{"shop_button_clicked.png", shop_button_clicked_png, shop_button_clicked_png_size, NULL, 0},
	{"shop_button.png", shop_button_png, shop_button_png_size, NULL, 0},
	{NULL, NULL, 0, NULL, 0}
};

#endif
