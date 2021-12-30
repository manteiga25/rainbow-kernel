/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __MT6627_FM_LIB_H__
#define __MT6627_FM_LIB_H__

#include "fm_typedef.h"

enum {
	DSPPATCH = 0xFFF9,
	USDELAY = 0xFFFA,
	MSDELAY = 0xFFFB,
	HW_VER = 0xFFFD,
	POLL_N = 0xFFFE,	/* poling check if bit(n) is '0' */
	POLL_P = 0xFFFF,	/* polling check if bit(n) is '1' */
};

enum {
	FM_PUS_DSPPATCH = DSPPATCH,
	FM_PUS_USDELAY = USDELAY,
	FM_PUS_MSDELAY = MSDELAY,
	FM_PUS_HW_VER = HW_VER,
	FM_PUS_POLL_N = POLL_N,	/* poling check if bit(n) is '0' */
	FM_PUS_POLL_P = POLL_P,	/* polling check if bit(n) is '1' */
	FM_PUS_MAX
};

enum SOFT_MUTE_GAIN_STATE {
	SOFT_MUTE_GAIN_DEFAULT = 0,
	SOFT_MUTE_GAIN_DISABLE,
	SOFT_MUTE_GAIN_ENABLE,
	SOFT_MUTE_GAIN_SET,
	SOFT_MUTE_GAIN_MAX
};

struct mt6627_smg_control {
	enum SOFT_MUTE_GAIN_STATE state;
	int value;
};

enum BLENDING_STATE {
	BLENDING_DEFAULT = 0,
	BLENDING_DISABLE,
	BLENDING_ENABLE,
	BLENDING_SET,
	BLENDING_MAX
};

struct mt6627_blend_control {
	enum BLENDING_STATE state;
	int rssi_value;
	int pamd_value;
	int blend_value;
};

enum {
	mt6627_E1 = 0,
	mt6627_E2
};

struct mt6627_fm_cqi {
	unsigned short ch;
	unsigned short rssi;
	unsigned short reserve;
};

struct adapt_fm_cqi {
	signed int ch;
	signed int rssi;
	signed int reserve;
};

struct mt6627_full_cqi {
	unsigned short ch;
	unsigned short rssi;
	unsigned short pamd;
	unsigned short pr;
	unsigned short fpamd;
	unsigned short mr;
	unsigned short atdc;
	unsigned short prx;
	unsigned short atdev;
	unsigned short smg;		/* soft-mute gain */
	unsigned short drssi;		/* delta rssi */
};

#endif
