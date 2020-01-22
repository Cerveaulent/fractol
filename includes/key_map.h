/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_map.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/15 21:11:26 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 21:09:28 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef KEY_MAP_H
# define KEY_MAP_H
# ifdef linux

#  define A				0x0061
#  define B				0x0062
#  define C				0x0063
#  define D				0x0064
#  define E				0x0065
#  define F				0x0066
#  define G				0x0067
#  define H				0x0068
#  define I				0x0069
#  define J				0x006A
#  define K				0x006B
#  define L				0x006C
#  define M				0x006D
#  define N				0x006E
#  define O				0x006F
#  define P				0x0070
#  define Q				0x0071
#  define R				0x0072
#  define S				0x0073
#  define T				0x0074
#  define U				0x0075
#  define V				0x0076
#  define W				0x0077
#  define X				0x0078
#  define Y				0x0079
#  define Z				0x007A
#  define UP 			0xFF52
#  define DOWN			0xFF54
#  define LEFT			0xFF51
#  define RIGHT			0xFF53
#  define PAD_PLUS		0xFFAB
#  define PAD_MINUS		0xFFAD
#  define PAD_1			0xFF9C
#  define PAD_2			0xFF99
#  define PAD_3			0xFF9B
#  define PAD_4			0xFF96
#  define ESC 			0xFF1B
# else
#  define A 				0
#  define B 				11
#  define C 				8
#  define D 				2
#  define E 				14
#  define F 				3
#  define G 				5
#  define H 				4
#  define I 				34
#  define J 				38
#  define K 				40
#  define L 				37
#  define M 				46
#  define N 				45
#  define O 				31
#  define P 				35
#  define Q 				12
#  define R 				15
#  define S 				1
#  define T 				17
#  define U 				32
#  define V 				9
#  define W 				13
#  define X 				7
#  define Y 				16
#  define Z 				6
#  define LEFT 			123
#  define RIGHT 			124
#  define DOWN 			125
#  define UP 			126
#  define LESS 			78
#  define MORE 			69
#  define ONE 			18
#  define TWO 			19
#  define THREE 			20
#  define FOUR 			21
#  define ESC 			53
# endif
#endif
