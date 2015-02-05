/* Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/mfd/pm8xxx/batterydata-lib.h>

static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {1911, 1905, 1911, 1902, 1893},
	.cols	= 5
};

static struct single_row_lut fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 31,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7,
					6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4165, 4162, 4158, 4152, 4146},
				{4090, 4098, 4098, 4094, 4090},
				{4038, 4052, 4054, 4051, 4048},
				{3991, 4010, 4015, 4013, 4010},
				{3949, 3970, 3980, 3978, 3975},
				{3911, 3933, 3948, 3947, 3944},
				{3876, 3899, 3918, 3918, 3916},
				{3846, 3869, 3887, 3890, 3889},
				{3819, 3843, 3853, 3856, 3855},
				{3796, 3821, 3827, 3828, 3825},
				{3778, 3802, 3809, 3809, 3807},
				{3762, 3786, 3795, 3795, 3793},
				{3748, 3772, 3783, 3784, 3781},
				{3735, 3762, 3773, 3773, 3770},
				{3721, 3752, 3760, 3757, 3749},
				{3704, 3739, 3743, 3737, 3724},
				{3683, 3719, 3724, 3718, 3706},
				{3661, 3700, 3703, 3698, 3686},
				{3641, 3687, 3684, 3679, 3668},
				{3626, 3677, 3675, 3671, 3660},
				{3616, 3670, 3672, 3668, 3657},
				{3604, 3663, 3668, 3665, 3654},
				{3589, 3655, 3662, 3659, 3649},
				{3572, 3643, 3650, 3648, 3636},
				{3551, 3623, 3622, 3623, 3608},
				{3524, 3591, 3579, 3582, 3568},
				{3489, 3545, 3525, 3532, 3519},
				{3436, 3483, 3456, 3468, 3456},
				{3347, 3399, 3360, 3382, 3375},
				{3211, 3264, 3213, 3255, 3253},
				{3000, 3000, 3000, 3000, 3000}
	}
};

static struct sf_lut rbatt_sf = {
	.rows		= 30,
	.cols		= 5,
	/* row_entries are temperature */
	.row_entries	= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7,
					6, 5, 4, 3, 2, 1},
	.sf		= {
				{811, 201, 100, 90, 88},
				{811, 202, 100, 90, 88},
				{834, 208, 103, 91, 90},
				{842, 214, 107, 94, 91},
				{853, 215, 111, 97, 92},
				{862, 214, 118, 100, 95},
				{872, 212, 122, 105, 98},
				{886, 211, 120, 108, 101},
				{905, 212, 107, 101, 98},
				{927, 213, 102, 92, 90},
				{951, 216, 103, 91, 90},
				{981, 219, 105, 93, 91},
				{1018, 222, 108, 95, 92},
				{1071, 226, 110, 98, 95},
				{1149, 232, 109, 96, 93},
				{1273, 235, 107, 94, 91},
				{1447, 236, 107, 94, 93},
				{1577, 248, 106, 94, 92},
				{1677, 268, 105, 93, 91},
				{1606, 268, 105, 94, 92},
				{1961, 282, 108, 95, 94},
				{2472, 303, 111, 97, 96},
				{3281, 335, 114, 99, 98},
				{4697, 383, 115, 100, 98},
				{7291, 454, 112, 98, 94},
				{11928, 575, 112, 96, 95},
				{20039, 831, 115, 98, 95},
				{33171, 1440, 121, 101, 98},
				{53942, 2684, 132, 108, 105},
				{90080, 5047, 692, 159, 125},
	}
};

struct bms_battery_data palladium_1500_data = {
	.fcc			= 1800,
	.fcc_temp_lut		= &fcc_temp,
	.fcc_sf_lut		= &fcc_sf,
	.pc_temp_ocv_lut	= &pc_temp_ocv,
	.rbatt_sf_lut		= &rbatt_sf,
	.default_rbatt_mohm	= 170,
	.rbatt_capacitive_mohm	= 50,
};